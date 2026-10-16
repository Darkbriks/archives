#pragma once

#include <algorithm>
#include <concepts>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <valarray>
#include <vector>

template <typename T>
concept IntegralType = std::is_same_v<T, int8_t> || std::is_same_v<T, int16_t> || std::is_same_v<T, int32_t> || std::is_same_v<T, int64_t>;

template <IntegralType T>
class NeedlemanWunsch
{
protected:
    std::string _seq1; std::string _seq2;
    std::unordered_map<std::string, T> _matrice;
    std::valarray<std::valarray<T>> _mat_score;
    std::valarray<std::valarray<u_int8_t>> _mat_direction; // bit 0: up, bit 1: left, bit 2: diag
    // 1: left, 2: up, 3: up and left, 4: diag, 5: diag and left, 6: diag and up, 7: diag, up and left
    std::vector<std::pair<std::string, std::string>> _alignment;

public:
    NeedlemanWunsch(const std::string& file1, const std::string& file2, const std::string& file3)
    {
        _seq1 = ReadSeq(file1); _seq2 = ReadSeq(file2); ReadMat(file3);
        _mat_score.resize(_seq1.size() + 1); _mat_direction.resize(_seq1.size() + 1);
        for (size_t i = 0; i < _mat_score.size(); ++i) { _mat_score[i].resize(_seq2.size() + 1); _mat_direction[i].resize(_seq2.size() + 1); }
    }

    virtual ~NeedlemanWunsch() = default;

    void PrintMat() { for (const auto& [key, value] : _matrice) { std::cout << key << " : " << static_cast<int32_t>(value) << " ; "; } std::cout << std::endl; }

    void PrintScore()
    {
        constexpr int width = 4;
        std::cout << std::setw(width) << " " << std::setw(width) << "-"; for (const char i : _seq1) { std::cout << std::setw(width) << i; } std::cout << std::endl;

        for (size_t i = 0; i < _mat_score[0].size(); ++i)
        {
            if (i == 0) { std::cout << std::setw(width) << "-"; } else { std::cout << std::setw(width) << _seq2[i - 1]; }
            for (size_t j = 0; j < _mat_score.size(); ++j) { std::cout << std::setw(width) << static_cast<int32_t>(_mat_score[j][i]); }
            std::cout << std::endl;
        }
    }

    void PrintDirection() const
    {
        constexpr int width = 4;
        std::cout << std::setw(width) << " " << std::setw(width) << "-"; for (const char i : _seq1) { std::cout << std::setw(width) << i; } std::cout << std::endl;

        for (size_t i = 0; i < _mat_direction[0].size(); ++i)
        {
            if (i == 0) { std::cout << std::setw(width) << "-"; } else { std::cout << std::setw(width) << _seq2[i - 1]; }
            for (size_t j = 0; j < _mat_direction.size(); ++j) { std::cout << std::setw(width) << static_cast<int32_t>(_mat_direction[j][i]); }
            std::cout << std::endl;
        }
    }

    void PrintAlignment() const { for (const auto& [seq1, seq2] : _alignment) { std::cout << seq1 << std::endl << seq2 << std::endl << std::endl; } }

    virtual void ComputeScore()
    {
        _mat_score[0][0] = 0;
        for (size_t i = 1; i < _mat_score.size(); ++i) { _mat_score[i][0] = static_cast<T>(_mat_score[i - 1][0] + _matrice.at(_seq1.substr(i - 1, 1) + "-")); }
        for (size_t i = 1; i < _mat_score[0].size(); ++i) { _mat_score[0][i] = static_cast<T>(_mat_score[0][i - 1] + _matrice.at("-" + _seq2.substr(i - 1, 1))); }

        for (size_t i = 1; i < _mat_score.size(); ++i)
        {
            for (size_t j = 1; j < _mat_score[i].size(); ++j)
            {
                T diag = _mat_score[i - 1][j - 1] + _matrice.at(_seq1.substr(i - 1, 1) + _seq2.substr(j - 1, 1));
                T up = _mat_score[i - 1][j] + _matrice.at(_seq1.substr(i - 1, 1) + "-");
                T left = _mat_score[i][j - 1] + _matrice.at("-" + _seq2.substr(j - 1, 1));
                _mat_score[i][j] = std::max({ diag, up, left });
            }
        }
    }

    virtual void ComputeDirection()
    {
        for (size_t i = 1; i < _mat_direction.size(); ++i) { _mat_direction[i][0] = 1; }
        for (size_t i = 1; i < _mat_direction[0].size(); ++i) { _mat_direction[0][i] = 2; }

        for (size_t i = 1; i < _mat_direction.size(); ++i)
        {
            for (size_t j = 1; j < _mat_direction[i].size(); ++j)
            {
                T diag = _mat_score[i - 1][j - 1] + _matrice.at(_seq1.substr(i - 1, 1) + _seq2.substr(j - 1, 1));
                T up = _mat_score[i - 1][j] + _matrice.at(_seq1.substr(i - 1, 1) + "-");
                T left = _mat_score[i][j - 1] + _matrice.at("-" + _seq2.substr(j - 1, 1));
                T max = std::max({ diag, up, left });
                _mat_direction[i][j] = (diag == max ? 4 : 0) | (up == max ? 2 : 0) | (left == max ? 1 : 0);
            }
        }
    }

    virtual void ComputeAlignment(const size_t i, const size_t j, const std::string& seq1, const std::string& seq2)
    {
        this->_alignment.clear();
        if (i == 0 && j == 0) { _alignment.emplace_back( seq1, seq2 ); return; }
        if (i > 0 && (_mat_direction[i][j] & 2) == 2) { ComputeAlignment(i - 1, j, _seq1.substr(i - 1, 1) + seq1, "-" + seq2); }
        if (j > 0 && (_mat_direction[i][j] & 1) == 1) { ComputeAlignment(i, j - 1, "-" + seq1, _seq2.substr(j - 1, 1) + seq2); }
        if (i > 0 && j > 0 && (_mat_direction[i][j] & 4) == 4) { ComputeAlignment(i - 1, j - 1, _seq1.substr(i - 1, 1) + seq1, _seq2.substr(j - 1, 1) + seq2); }
    }

    virtual void ComputeAlignment() { ComputeAlignment(_seq1.size(), _seq2.size(), "", ""); }

protected:
    static std::string ReadSeq(const std::string& filename)
    {
        if (std::ifstream file(filename); file.is_open()) { std::string line; std::getline(file, line); return line; }
        std::cerr << "Error: Could not open file " << filename << std::endl; return "";
    }

    void ReadMat(const std::string& filename)
    {
        if (std::ifstream file(filename); file.is_open())
        {
            std::string keys; std::getline(file, keys);
            keys.erase(std::ranges::remove(keys, ' ').begin(), keys.end());

            size_t line = 0; std::string row;
            while (std::getline(file, row))
            {
                size_t column = 0;
                while (!row.empty())
                {
                    if (row[0] == ' ') { row.erase(0, 1); continue; } if (row == "\r") { break; }
                    std::string value = row.substr(0, row.find(' ')); row.erase(0, row.find(' '));
                    auto val = static_cast<T>(std::stoi(value));
                    _matrice.emplace(keys.substr(line, 1) + keys.substr(column, 1), val);
                    ++column;
                }
                ++line;
            }
            return;
        }
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
};