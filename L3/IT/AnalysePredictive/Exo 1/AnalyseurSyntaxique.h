#pragma once

#include <iostream>
#include <map>
#include <optional>
#include <tuple>
#include <set>
#include <vector>

typedef std::pair<std::string, std::string> Key;
typedef std::vector<std::string> Rule;

std::tuple<std::map<Key, Rule>, std::string, std::set<std::string>, std::set<std::string>> load_file(const std::string& file_name);

std::optional<std::vector<std::string>> tokenize(const std::string& input, const std::set<std::string>& terminaux);

bool analyseur(const std::vector<std::string>& tokens,
    const std::string& axiom,
    const std::map<Key, Rule>& table,
    const std::set<std::string>& non_terminals,
    const std::set<std::string>& terminals);