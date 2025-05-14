#pragma once

#include <vector>

struct Backpack
{
    int n;
    int k;
    std::vector<int> item_weights;
    std::vector<int> item_values;

    Backpack(int const& n, int const& k, std::vector<int> const& item_weights, std::vector<int> const& item_values);

    void compute() const;
};
