#include <iostream>
#include <vector>

#include "sort.hpp"

#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <catch/catch.hpp>

TEST_CASE("InsertionSort 1 cmp")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 6, 5, 4, 3, 2, 1 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 2 cmp")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin() + 1, arr.begin() + 5, [](int a, int b) { return a > b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 5, 6, 4, 2, 1, 3 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 3 cmp")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin() + 4, arr.end(), [](int a, int b) { return a > b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 5, 2, 4, 6, 3, 1 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 4 cmp")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin() + 5, arr.end(), [](int a, int b) { return a > b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 5, 2, 4, 6, 1, 3 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 5 cmp")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin() + 5, arr.end(), [](int a, int b) { return a > b; });
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 5, 2, 4, 6, 1, 3 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 1 std::less")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin(), arr.end());
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 1, 2, 3, 4, 5, 6 };
    REQUIRE(arr == solution);
}

TEST_CASE("InsertionSort 2 std::less")
{
    int i, j, h;
    std::cout << "-------------------\n";
    std::vector<int> arr = { 5, 2, 4, 6, 1, 3 };
    clock_t start = clock();
    cotl::InsertionSort(arr.begin() + 1, arr.begin() + 5);
    clock_t end = clock();
    std::cout << "running time: " << 
        (double)(end - start) << " clocks\n";
    std::cout << "running time: " << 
        (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "\n";
    std::vector<int> solution = { 5, 1, 2, 4, 6, 3 };
    REQUIRE(arr == solution);
}
