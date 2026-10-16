#include "PDA.h"

#include <iostream>
#include <fstream>
#include <ranges>
#include <sstream>
#include <vector>
#include <map>
#include <tuple>
#include <set>
#include <optional>

void PDA::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) { std::cerr << "Error: could not open file " << filename << std::endl; exit(1); }

    std::string line;

    getline(file, line); { std::stringstream ss(line); std::string w; while (ss >> w) { _states.insert(w); } }
    getline(file, line); { std::stringstream ss(line); std::string w; while (ss >> w) { _alphabet.push_back(w); } }
    getline(file, line); { std::stringstream ss(line); std::string w; while (ss >> w) { _stack_alphabet.push_back(w); } }
    getline(file, _start_state); if (!_start_state.empty() && _start_state.ends_with("\r")) { _start_state.pop_back(); }
    getline(file, _start_stack_symbol); if (!_start_stack_symbol.empty() && _start_stack_symbol.ends_with("\r")) { _start_stack_symbol.pop_back(); }
    getline(file, line); { std::stringstream ss(line); std::string w; while (ss >> w) { _final_states.insert(w); } }

    while (getline(file, line))
    {
        if (line.empty() || line[0] == '#') { continue; }
        std::stringstream ss(line);
        std::string st, sym, top, nst;
        ss >> st >> sym >> top >> nst;
        std::vector<std::string> pushes;
        std::string x;
        while (ss >> x)
        {
            for (std::vector<std::string> tokenized = tokenize(x, _stack_alphabet).value_or(std::vector<std::string>{}); const auto& token : tokenized)
            {
                if (token != "e") { pushes.push_back(token); }
            }
        }
        if (pushes.size() == 1 && pushes[0] == "e") { pushes.clear(); }
        _trans[{st, sym, top}] = { nst, pushes };
    }
}

std::optional<std::vector<std::string>> PDA::tokenize(const std::string& input, const std::vector<std::string>& alphabet)
{
    std::vector<std::string> tokens;
    size_t pos = 0;

    while (pos < input.length())
    {
        std::string current_token;
        for (const auto& token : alphabet)
        {
            if (input.substr(pos, token.size()) == token && token.size() > current_token.size())
            {
                current_token = token;
            }
        }
        if (current_token.empty())
        {
            std::cerr << "Error: unrecognized token in input: " << input << std::endl;
            return std::nullopt;
        }
        tokens.push_back(current_token);
        pos += current_token.size();
    }
    return tokens;
}

bool PDA::recognize(const std::vector<std::string>& input_tokens) const
{
    if (_verbosity > 0)
    {
        std::cout << "Input tokens: ";
        for (const auto& token : input_tokens) { std::cout << token << " "; }
        std::cout << std::endl;
    }

    std::set<Configuration> visited;
    std::vector<Configuration> queue;

    queue.push_back({_start_state, 0, {_start_stack_symbol}});

    while (!queue.empty())
    {
        Configuration current = queue.front();
        queue.erase(queue.begin());

        if (_verbosity > 0)
        {
            std::cout << "Visiting: " << current.state << ", position: " << current.position << ", stack: ";
            for (const auto& s : current.stack) { std::cout << s << " "; }
            std::cout << std::endl;
        }

        if (visited.contains(current)) { continue; }
        visited.insert(current);

        if (_final_states.contains(current.state) && current.position == input_tokens.size()) { return true; }
        if (processEpsilonTransitions(current, queue)) { continue; }
        if (current.position < input_tokens.size()) { processSymbolTransitions(current, input_tokens[current.position], queue); }
    }

    return false;
}

bool PDA::processEpsilonTransitions(const Configuration& current, std::vector<Configuration>& queue) const
{
    bool found = false;
    std::string top_stack = current.stack.empty() ? "e" : current.stack.back();

    if (const Key epsilon_key = {current.state, "e", top_stack}; _trans.contains(epsilon_key))
    {
        const auto&[next_state, push_symbols] = _trans.at(epsilon_key);

        Configuration next = current;
        next.state = next_state;

        if (top_stack != "e") { next.stack.pop_back(); }

        for (const auto & it : std::ranges::reverse_view(push_symbols)) { if (it != "e") { next.stack.push_back(it); } }

        queue.push_back(next);
        found = true;
    }
    return found;
}

void PDA::processSymbolTransitions(const Configuration& current, const std::string& input_symbol, std::vector<Configuration>& queue) const
{
    std::string top_stack = current.stack.empty() ? "e" : current.stack.back();

    if (const Key input_key = {current.state, input_symbol, top_stack}; _trans.contains(input_key))
    {
        const auto&[next_state, push_symbols] = _trans.at(input_key);

        Configuration next = current;
        next.state = next_state;
        next.position++;

        if (top_stack != "e") { next.stack.pop_back(); }
        for (const auto & it : std::ranges::reverse_view(push_symbols)) { if (it != "e") { next.stack.push_back(it); } }
        queue.push_back(next);
    }
}