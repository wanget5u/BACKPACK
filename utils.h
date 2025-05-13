#pragma once

#include <vector>
#include <iostream>

namespace utils
{
    inline auto printVector(std::vector<int> const& vector) -> void
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
}