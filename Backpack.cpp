#include "Backpack.h"
#include <chrono>

#include "utils.h"

Backpack::Backpack(int const& n, int const& k, std::vector<int> const& item_weights, std::vector<int> const& item_values)
{
    this -> n = n;
    this -> k = k;
    this -> item_weights = item_weights;
    this -> item_values = item_values;

    std::cout
    << "Running Backpack with: " << std::endl
    << "k = " << k << " n = " << n << std::endl
    << "Item weights = ";

    utils::printVector(item_weights);

    std::cout << "Item values = ";
    utils::printVector(item_values);
}

void Backpack::compute() const
{
    int biggestValue = 0;
    int biggestSubset = 0;

    const int totalSubsets = 1 << this -> n;
    std::cout << "Subsets = " << totalSubsets << std::endl;

    const auto startTime = std::chrono::high_resolution_clock::now();

    for (int subset = 0; subset < totalSubsets; subset++)
    {
        int currentWeight = 0;
        int currentValue = 0;

        for (int x = 0; x < this -> n; x++)
        {
            if (subset & (1 << x))
            {
                currentWeight += item_weights[x];
                currentValue += item_values[x];
            }
        }

        if (currentWeight <= this -> k && currentValue > biggestValue)
        {
            biggestValue = currentValue;
            biggestSubset = subset;
        }
    }
    std::cout << "Biggest achievable value = " << biggestValue << std::endl;
    std::cout << "Biggest achievable subset = " << utils::decToBinary(biggestSubset) << std::endl;

    const auto endTime = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
}