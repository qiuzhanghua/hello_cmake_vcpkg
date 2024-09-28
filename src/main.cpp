#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <array>
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "include/main.h"

using namespace std;

int main()
{
    fmt::print("Hello World!\n");
    spdlog::info("I Love C++!");
    // arrayUsage();
    // arrayRandom();
    arraySort();
    return 0;
}

/* Array Usage */
void arrayUsage()
{
    constexpr size_t arraySize{5};
    std::array<int, arraySize> arr{1, 2, 3, 4, 5};
    cout << fmt::format("{:>7}{:>10}", "Element", "Value") << endl;
    for (size_t i{0}; i < arr.size(); ++i)
    {
        cout << fmt::format("{:>7}{:>10}", i, arr[i]) << endl;
    }

    for (auto &element : arr)
    {
        element *= 2;
    }
    int sum{0};
    for (const auto &element : arr)
    {
        sum += element;
    }
    cout << fmt::format("{:>7}{:>10}", "Sum", sum) << endl;
}

/* Array Random */
void arrayRandom()
{
    constexpr size_t arraySize{7};
    std::array<int, arraySize> freq{};
    std::random_device rd;
    std::default_random_engine gen{rd()};
    std::uniform_int_distribution<int> uniform{1, 6};
    for (int i{0}; i < 60'000'000; ++i)
    {
        freq[uniform(gen)]++;
    }
    cout << fmt::format("{:>4}{:>13}", "Face", "Frequency") << endl;
    for (size_t i{1}; i < freq.size(); ++i)
    {
        cout << fmt::format("{:>4}{:>13}", i, freq[i]) << endl;
    }
}

void arraySort()
{
    using namespace std::string_literals;
    std::array colors{"red"s, "orange"s, "yellow"s, "green"s, "blue"s, "indigo"s, "violet"s};
    std::sort(colors.begin(), colors.end());
    for (const std::string &color : colors)
    {
        cout << color << " ";
    }
    cout << endl;
    bool found{std::binary_search(colors.begin(), colors.end(), "azure")};
    cout << fmt::format("Found: {}", found) << endl;
}