#include <iostream>
#include <fstream>

#include "utils.h"
#include "Backpack.h"

int main(const int argc, char *argv[])
{
    if (argc != 2)
    {std::cerr << "usage: program <fileName>" << std::endl; return 1;}

    std::ifstream file(argv[1]);

    if (!file.is_open())
    {std::cerr << "can't open file: " << argv[1] << std::endl; return 1;}

    std::string line;

    std::getline(file, line);
    auto [k, n] = utils::parseTwoInts(line);

    std::getline(file, line);
    const std::vector<int> item_weights = utils::split(line, ',');

    std::getline(file, line);
    const std::vector<int> item_values = utils::split(line, ',');

    if (item_weights.size() != n || item_values.size() != n)
    {std::cerr << "item_weights and item_values must be of n size" << std::endl; return 1;}

    file.close();

    Backpack backpack = Backpack(n, k, item_weights, item_values);
    backpack.compute();
}
