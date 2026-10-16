#include <iostream>

#include "AnalyseurSyntaxique.h"

int main(const int argc, char** argv)
{
    if (argc != 2) { std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl; return 1; }

    auto [parsed, axiome, non_terminaux, terminaux] = load_file(argv[1]);

    for (const auto& [key, value] : parsed)
    {
        std::cout << key.first << " " << key.second << " : "; for (const auto& token : value) { std::cout << token << " "; } std::cout << std::endl;
    }

    std::cout << "Axiome: " << axiome << std::endl << "Non-terminaux: ";
    for (const auto& nt : non_terminaux) { std::cout << nt << " "; }
    std::cout << std::endl << "Terminaux: ";
    for (const auto& t : terminaux) { std::cout << t << " "; }
    std::cout << std::endl;

    std::string input;
    std::cout << "Enter input string: ";
    std::getline(std::cin, input);

    if (const auto tokens = tokenize(input, terminaux); tokens)
    {
        std::cout << "Tokens: "; for (const auto& token : *tokens) { std::cout << token << ", "; } std::cout << std::endl;
        const bool result = analyseur(*tokens, axiome, parsed, non_terminaux, terminaux);
        std::cout << "Result: " << (result ? "Accepted" : "Rejected") << std::endl;
    }
    else { std::cerr << "Error tokenizing input." << std::endl; }

    return 0;
}