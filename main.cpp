#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "Backpack.h"

auto split(std::string const& text, char const& separator) -> std::vector<int>
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

auto parseTwoInts(std::string const& line) -> std::pair<int, int>
{
    std::istringstream iss(line);
    int a, b;
    iss >> a >> b;
    return {a, b};
}

auto main(const int argc, char* argv[]) -> int
{
    if (argc != 2)
    {std::cerr << "usage: program <fileName>" << std::endl; return 1;}

    std::ifstream file(argv[1]);

    if (!file.is_open())
    {std::cerr << "can't open file: " << argv[1] << std::endl; return 1;}

    std::string line;

    std::getline(file, line);
    auto [k, n] = parseTwoInts(line);

    std::getline(file, line);
    const std::vector<int> item_weights = split(line, ',');

    std::getline(file, line);
    const std::vector<int> item_values = split(line, ',');

    if (item_weights.size() != n || item_values.size() != n)
    {std::cerr << "item_weights and item_values must be of n size" << std::endl; return 1;}

    file.close();

    Backpack backpack = Backpack(n, k, item_weights, item_values);
    backpack.compute();
}
