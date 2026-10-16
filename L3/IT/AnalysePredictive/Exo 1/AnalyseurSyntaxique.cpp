#include "AnalyseurSyntaxique.h"

#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <stack>

std::tuple<std::map<Key, Rule>, std::string, std::set<std::string>, std::set<std::string>> load_file(const std::string& file_name)
{
    std::map<Key, Rule> table;
    std::string axiome;
    std::set<std::string> non_terminaux;
    std::set<std::string> terminaux;

    if (std::ifstream file(file_name); file.is_open())
    {
        std::string row;
        while(std::getline(file, row))
        {
            std::istringstream iss(row);
            std::string key1, key2;
            iss >> key1 >> key2;

            if (std::isupper(key1[0])) { non_terminaux.insert(key1); } else { terminaux.insert(key1); }
            if (std::isupper(key2[0])) { non_terminaux.insert(key2); } else { terminaux.insert(key2); }
            if (axiome.empty()) { axiome = key1; }
            if (key1 == "Axiome") { axiome = key2; continue; }

            std::stringstream right (row.substr(row.find(':') + 2));
            Rule rule;
            std::string token;
            while (right >> token)
            {
                if (std::isupper(token[0])) { non_terminaux.insert(token); }
                else { terminaux.insert(token); }
                rule.emplace_back(token);
            }

            table.emplace(std::make_pair(key1, key2), rule);
        }
    }
    else
    {
        std::cerr << "Error opening file: " << file_name << std::endl;
    }

    return std::make_tuple(table, axiome, non_terminaux, terminaux);
}

std::optional<std::vector<std::string>> tokenize(const std::string& input, const std::set<std::string>& terminaux)
{
    std::string input_no_spaces;
    for (const char i : input) { if (i != ' ') { input_no_spaces += i; } }

    std::vector<std::string> tokens;
    size_t pos = 0;

    while (pos < input_no_spaces.length())
    {
        std::string current_token;
        for (const auto& terminal : terminaux)
        {
            if (input_no_spaces.substr(pos, terminal.size()) == terminal && terminal.size() > current_token.size())
            {
                current_token = terminal;
            }
        }
        if (current_token.empty())
        {
            std::cerr << "Error: unrecognized token in input: " << input_no_spaces << std::endl;
            return std::nullopt;
        }
        tokens.push_back(current_token);
        pos += current_token.size();
    }
    tokens.emplace_back("$");
    return tokens;
}

bool analyseur(const std::vector<std::string>& tokens,
    const std::string& axiom,
    const std::map<Key, Rule>& table,
    const std::set<std::string>& non_terminals,
    const std::set<std::string>& terminals)
{
    std::stack<std::string> stk;
    stk.emplace("$");
    stk.push(axiom);

    size_t index = 0;
    while (!stk.empty())
    {
        std::string top = stk.top();

        if (std::string current_token = tokens[index]; top == current_token) { stk.pop(); index++; }
        else
        {
            for (const auto& non_terminal : non_terminals)
            {
                if (top == non_terminal)
                {
                    const auto it = table.find({top, current_token});
                    if (it == table.end()) return false;

                    stk.pop();
                    if (const Rule& rule = it->second; !(rule.size() == 1 && rule[0] == "\\epsilon"))
                    {
                        for (const auto & it2 : std::ranges::reverse_view(rule)) { stk.push(it2); }
                    }
                    break;
                }
            }
        }
    }
    return index == tokens.size();
}