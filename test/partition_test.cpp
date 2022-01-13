#include <iostream>

#include "partition.hpp"

#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <catch/catch.hpp>

TEST_CASE("Partition 1")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 2, 8, 7, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        col::Partition(arr.begin(), arr.end(), [](int a) { return a - 4; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 2, 1, 3, 4, 7, 5, 6, 8 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 3, arr.begin() + 4 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("Partition 2")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 2, 8, 7, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        col::Partition(arr.begin() + 2, arr.begin() + 6, [](int a) { return a - 4; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 2, 8, 1, 3, 7, 5, 6, 4 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 4, arr.begin() + 4 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("Partition 3")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 2, 8, 5, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        col::Partition(arr.begin() + 1, arr.begin() + 7, [](int a) { return a - 5; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 2, 1, 3, 5, 5, 8, 6, 4 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 3, arr.begin() + 5 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}
