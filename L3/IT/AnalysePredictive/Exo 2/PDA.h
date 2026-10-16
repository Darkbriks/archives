#pragma once
#include <set>
#include <string>
#include <vector>
#include <map>
#include <optional>

typedef std::tuple<std::string, std::string, std::string> Key;

struct Transition { std::string next_state; std::vector<std::string> push_symbols; };

struct Configuration
{
    std::string state;
    size_t position;
    std::vector<std::string> stack;

    bool operator<(const Configuration& other) const
    {
        if (state != other.state) return state < other.state;
        if (position != other.position) return position < other.position;
        return stack < other.stack;
    }
};

class PDA
{
public:
    explicit PDA(const u_int8_t verbosity = 0) : _verbosity(verbosity) {}

    void loadFromFile(const std::string& filename);
    [[nodiscard]] static std::optional<std::vector<std::string>> tokenize(const std::string& input, const std::vector<std::string>& alphabet) ;
    [[nodiscard]] bool recognize(const std::vector<std::string>& input_tokens) const;

    [[nodiscard]] std::vector<std::string> getAlphabet() const { return _alphabet; }

private:
    u_int8_t _verbosity = 0;

    std::set<std::string> _states;
    std::vector<std::string> _alphabet;
    std::vector<std::string> _stack_alphabet;
    std::string _start_state;
    std::string _start_stack_symbol;
    std::set<std::string> _final_states;
    std::map<Key, Transition> _trans;

    [[nodiscard]] bool processEpsilonTransitions(const Configuration& current, std::vector<Configuration>& queue) const;
    void processSymbolTransitions(const Configuration& current, const std::string& input_symbol, std::vector<Configuration>& queue) const;
};