#include <iostream>

#include "NeedlemanWunsch.h"
#include "NeedlemanWunschLocal.h"

int main(const int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <dna_file1> <dna_file2> <mat_file>" << std::endl;
        return 1;
    }

    std::cout << "Alignement global:" << std::endl;
    NeedlemanWunsch<int8_t> needleman_wunsch(argv[1], argv[2], argv[3]);
    std::cout << "Matrice de score:" << std::endl;
    needleman_wunsch.ComputeScore();
    needleman_wunsch.PrintScore();
    std::cout << "Matrice de direction:" << std::endl;
    needleman_wunsch.ComputeDirection();
    needleman_wunsch.PrintDirection();
    std::cout << "Alignement(s):" << std::endl;
    needleman_wunsch.ComputeAlignment();
    needleman_wunsch.PrintAlignment();

    std::cout << std::endl << "Alignement local:" << std::endl;
    NeedlemanWunschLocal<int8_t> needleman_wunsch_local(argv[1], argv[2], argv[3]);
    std::cout << "Matrice de score:" << std::endl;
    needleman_wunsch_local.ComputeScore();
    needleman_wunsch_local.PrintScore();
    std::cout << "Matrice de direction:" << std::endl;
    needleman_wunsch_local.ComputeDirection();
    needleman_wunsch_local.PrintDirection();
    std::cout << "Alignement(s):" << std::endl;
    needleman_wunsch_local.ComputeAlignment();
    needleman_wunsch_local.PrintAlignment();

    return 0;
}