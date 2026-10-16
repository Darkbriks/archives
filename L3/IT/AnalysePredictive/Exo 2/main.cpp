#include <iostream>

#include "PDA.h"

bool testString(const PDA& pda, const std::string& input)
{
    const auto tokens = PDA::tokenize(input, pda.getAlphabet());
    if (!tokens) { std::cout << "Error tokenizing input: " << input << std::endl; return false; }
    return pda.recognize(*tokens);
}

int main(const int argc, char** argv)
{
    if (argc < 2) { std::cerr << "Usage: " << argv[0] << " <pda_config_file> <verbosity_level=0> <custom_input_string=\"\">" << std::endl; return 1; }

    auto pda = PDA(argc > 2 ? static_cast<u_int8_t>(std::stoi(argv[2])) : 0);
    pda.loadFromFile(argv[1]);

    const std::vector<std::string> testCases = {
        "",
        "a",
        "b",
        "ab",
        "aabb",
        "aaabbb",
        "aabbb",
        "aaabb",
        "aba",
        "ba",
        "aab",
        "aaaabbbb"
    };

    std::cout << "Résultats des tests avec l'automate à pile:" << std::endl;
    std::cout << "===========================================" << std::endl;
    if (argc > 3)
    {
        const std::string customInput = argv[3];
        std::cout << "Test de la chaîne personnalisée: \"" << customInput << "\" : " << (testString(pda, customInput) ? "ACCEPTÉE" : "REFUSÉE") << std::endl;
    }
    else
    {
        for (const auto& testCase : testCases)
        {
            const bool result = testString(pda, testCase);
            std::cout << "\"" << testCase << "\" : " << (result ? "ACCEPTÉE" : "REFUSÉE") << std::endl;
        }
    }

    return 0;
}