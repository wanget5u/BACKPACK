#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

namespace utils
{
    inline void printVector(std::vector<int> const& vector)
    {
        std::cout << '{';
        for (int x = 0; x < vector.size(); x++)
        {
            if (x != vector.size() - 1)
            {std::cout << vector.at(x) << ", ";}
            else
            {std::cout << vector.at(x) << '}' << std::endl;}
        }
    }

    inline std::vector<int> split(std::string const& text, char const& separator)
    {
        std::vector<int> data;
        std::istringstream iss(text);
        std::string fragment;

        while (std::getline(iss, fragment, separator))
        {
            try
            {
                data.push_back(std::stoi(fragment));
            }
            catch ([[maybe_unused]] std::exception const& exception)
            {
                std::cerr << "main.cpp split() string to int parse exception" << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        return data;
    }

    inline std::pair<int, int> parseTwoInts(std::string const& line)
    {
        std::istringstream iss(line);
        int a, b;
        iss >> a >> b;
        return {a, b};
    }

    inline std::string decToBinary(int & number)
    {
        std::string binary;

        while (number > 0)
        {
            int binaryNumber = number % 2;
            binary.push_back('0' + binaryNumber);
            number /= 2;
        }

        std::ranges::reverse(binary);
        return binary;
    }
}