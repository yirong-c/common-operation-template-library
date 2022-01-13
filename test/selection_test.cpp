#include <iostream>
#include <vector>

#include "selection.hpp"

#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <catch/catch.hpp>

TEST_CASE("Select 1")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 2, 8, 7, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        cotl::Select(arr.begin(), arr.end(), 8, [](int a, int b) { return a - b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 1, 2, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 9, 10, 8, 16, 14, 8 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 8, arr.begin() + 9 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("Select 2")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 2, 4, 7, 1, 3, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        cotl::Select(arr.begin(), arr.end(), 8, [](int a, int b) { return a - b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 1, 2, 1, 2, 3, 3, 4, 4, 4, 6, 7, 7, 9, 10, 14, 16, 8 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 6, arr.begin() + 9 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("Select 3")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 2, 8, 7, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        cotl::Select(arr.begin(), arr.end(), 3, [](int a, int b) { return a - b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 1, 1, 2, 2, 3, 3, 8, 9, 10, 14, 4, 16, 7, 7, 8, 4, 5, 6 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 2, arr.begin() + 4 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("Select 4")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 2, 8, 7, 1, 3, 5, 6, 4 };
    clock_t start = clock();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval = 
        cotl::Select(arr.begin(), arr.end(), 15, [](int a, int b) { return a - b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 1, 2, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 10, 14, 16 };
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> interval_solution = 
        { arr.begin() + 15, arr.begin() + 16 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}

TEST_CASE("WeighedSelect 1")
{
    using Container = std::vector< std::pair<int, size_t> >;
    int i, j, h;
    std::cout << "-------------------\n";
    Container arr = { 
        { 4, 10 }, { 3, 3 }, { 7, 20 }, { 5, 15 }, { 2, 35 }, { 3, 5 }, { 6, 2 }, { 1, 10 }
    };
    clock_t start = clock();
    std::pair<Container::iterator, Container::iterator> interval = 
        cotl::WeighedSelect(arr.begin(), arr.end(), 49, 
        [](const std::pair<int, size_t>& a) { return a.second; }, 
        [](const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) 
        { return a.first - b.first; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    Container solution = { 
        { 2, 35 }, { 1, 10 }, { 3, 3 }, { 3, 5 }, { 7, 20 }, { 4, 10 }, { 5, 15 }, { 6, 2 } 
    };
    std::pair<Container::iterator, Container::iterator> interval_solution = 
        { arr.begin() + 2, arr.begin() + 4 };
    REQUIRE(arr == solution);
    REQUIRE(interval == interval_solution);
}
