#pragma once

#include "NeedlemanWunsch.h"
#include <cstdint>

template<typename T>
class NeedlemanWunschLocal : public NeedlemanWunsch<T>
{
public:
    NeedlemanWunschLocal(const std::string &file1, const std::string &file2, const std::string &file3): NeedlemanWunsch<T>(file1, file2, file3) {}

    void ComputeScore() override
    {
        for (size_t i = 0; i < this->_mat_score.size(); ++i) { this->_mat_score[i][0] = 0; }
        for (size_t j = 0; j < this->_mat_score[0].size(); ++j) {this->_mat_score[0][j] = 0;}

        for (size_t i = 1; i < this->_mat_score.size(); ++i)
        {
            for (size_t j = 1; j < this->_mat_score[i].size(); ++j)
            {
                T diag = this->_mat_score[i - 1][j - 1] + this->_matrice.at(this->_seq1.substr(i - 1, 1) + this->_seq2.substr(j - 1, 1));
                T up = this->_mat_score[i - 1][j] + this->_matrice.at(this->_seq1.substr(i - 1, 1) + "-");
                T left = this->_mat_score[i][j - 1] + this->_matrice.at("-" + this->_seq2.substr(j - 1, 1));
                this->_mat_score[i][j] = std::max({diag, up, left, static_cast<T>(0)});
            }
        }
    }

    void ComputeDirection() override
    {
        for (size_t i = 1; i < this->_mat_direction.size(); ++i)
        {
            for (size_t j = 1; j < this->_mat_direction[i].size(); ++j)
            {
                if (this->_mat_score[i][j] == 0) { this->_mat_direction[i][j] = 0; }
                else
                {
                    T diag = this->_mat_score[i - 1][j - 1] + this->_matrice.at(this->_seq1.substr(i - 1, 1) + this->_seq2.substr(j - 1, 1));
                    T up = this->_mat_score[i - 1][j] + this->_matrice.at(this->_seq1.substr(i - 1, 1) + "-");
                    T left = this->_mat_score[i][j - 1] + this->_matrice.at("-" + this->_seq2.substr(j - 1, 1));
                    T maxVal = std::max({diag, up, left});
                    this->_mat_direction[i][j] = (diag == maxVal ? 4 : 0) | (up == maxVal ? 2 : 0) | (left == maxVal ? 1 : 0);
                }
            }
        }
    }

    void ComputeAlignment() override
    {
        this->_alignment.clear(); T maxScore = 0;
        for (size_t i = 0; i < this->_mat_score.size(); ++i) { for (size_t j = 0; j < this->_mat_score[i].size(); ++j) { if (this->_mat_score[i][j] > maxScore) { maxScore = this->_mat_score[i][j]; } } }
        if (maxScore == 0) { std::clog << "No alignment found." << std::endl; return; }
        for (size_t i = 0; i < this->_mat_score.size(); ++i) { for (size_t j = 0; j < this->_mat_score[i].size(); ++j) { if (this->_mat_score[i][j] == maxScore) { BacktrackLocal(i, j, "", ""); } } }
    }
private:
    void BacktrackLocal(size_t i, size_t j, std::string align1, std::string align2)
    {
        if (i == 0 || j == 0 || this->_mat_score[i][j] == 0) { this->_alignment.emplace_back(align1, align2); return; }
        const uint8_t direction = this->_mat_direction[i][j];

        if (direction & 4) { BacktrackLocal(i - 1, j - 1, this->_seq1.substr(i - 1, 1) + align1, this->_seq2.substr(j - 1, 1) + align2); }
        if (direction & 2) { BacktrackLocal(i - 1, j, this->_seq1.substr(i - 1, 1) + align1, "-" + align2); }
        if (direction & 1) { BacktrackLocal(i, j - 1, "-" + align1, this->_seq2.substr(j - 1, 1) + align2); }
    }
};