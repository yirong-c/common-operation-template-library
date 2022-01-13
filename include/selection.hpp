#ifndef _SELECTION_HPP
#define _SELECTION_HPP

#include <iterator>
#include <vector>

#include "partition.hpp"

namespace cotl
{
    /**
     * Select the rank-th small element from the range of the container. 
     * This function will cause a partition on the range of the container 
     * around the rank-th small element.
     * @param first range
     * @param last range
     * @param rank order statistic (start by 0)
     * @param compare comparsion function object which 
     *                  returns 0 if the first argument is equal to the second argument and 
     *                  returns negative value if the first argument is less than the second argument.
     *          signature: int Cmp(const Type &a, const Type &b); 
     * @return range of elements that are eqaul to the rank-th small element
     */
    template <typename RandomAccessIterator, typename Compare>    
    std::pair<RandomAccessIterator, RandomAccessIterator> 
        Select(RandomAccessIterator first, RandomAccessIterator last, size_t rank, Compare compare)
    {
        if (std::distance(first, last) <= 1)
            return std::make_pair(first, last);
        typename std::iterator_traits<RandomAccessIterator>::difference_type i, n_div_five_floor;
        n_div_five_floor = std::distance(first, last) / 5;
        std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> medians;
        medians.reserve(n_div_five_floor + 1);
        RandomAccessIterator group_first, group_last = first;
        for (i = 0; i < n_div_five_floor; ++i)
        {
            group_first = group_last;
            group_last = group_first + 5;
            cotl::InsertionSort(group_first, group_last);
            medians.push_back(*(group_first + 2));
        }
        if (group_last != last)
        {
            cotl::InsertionSort(group_last, last);
            medians.push_back(*(group_last + ((std::distance(group_last, last) - 1) >> 1)));
        }
        typename std::iterator_traits<RandomAccessIterator>::value_type &median_of_medians = 
            *(Select(medians.begin(), medians.end(), 
            (std::distance(medians.begin(), medians.end()) - 1) >> 1, compare).first);
        std::pair<RandomAccessIterator, RandomAccessIterator> pivot_interval = 
            cotl::Partition(first, last, 
            [&median_of_medians, &compare]
            (const typename std::iterator_traits<RandomAccessIterator>::value_type &a) { 
                return compare(a, median_of_medians); 
            });
        if (rank < std::distance(first, pivot_interval.first))
            return Select(first, pivot_interval.first, rank, compare);
        else if (rank >= std::distance(first, pivot_interval.second))
            return Select(pivot_interval.second, last, 
                rank - std::distance(first, pivot_interval.second), compare);
        else
            return pivot_interval;
    }

    /**
     * Select the rank-th small element from the range of the container. 
     * This function will cause a partition on the range of the container 
     * around the rank-th small element.
     * @param first range
     * @param last range
     * @param weighted_rank weighted order statistic (start by 0)
     * @param weight weight function object which returns the weight of the argument.
     *          signature: size_t Weight(const Type &a); 
     * @param compare comparsion function object which 
     *                  returns 0 if the first argument is equal to the second argument and 
     *                  returns negative value if the first argument is less than the second argument.
     *          signature: int Cmp(const Type &a, const Type &b); 
     * @return range of elements that are eqaul to the rank-th small element
     */
    template <typename RandomAccessIterator, typename Compare, typename Weight>    
    std::pair<RandomAccessIterator, RandomAccessIterator> 
        WeighedSelect(RandomAccessIterator first, RandomAccessIterator last, 
        size_t weighted_rank, Weight weight, Compare compare)
    {
        if (std::distance(first, last) <= 1)
            return std::make_pair(first, last);
        typename std::iterator_traits<RandomAccessIterator>::difference_type i, n_div_five_floor;
        n_div_five_floor = std::distance(first, last) / 5;
        std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> medians;
        medians.reserve(n_div_five_floor + 1);
        RandomAccessIterator group_first, group_last = first;
        for (i = 0; i < n_div_five_floor; ++i)
        {
            group_first = group_last;
            group_last = group_first + 5;
            cotl::InsertionSort(group_first, group_last);
            medians.push_back(*(group_first + 2));
        }
        if (group_last != last)
        {
            cotl::InsertionSort(group_last, last);
            medians.push_back(*(group_last + ((std::distance(group_last, last) - 1) >> 1)));
        }
        typename std::iterator_traits<RandomAccessIterator>::value_type &median_of_medians = 
            *(Select(medians.begin(), medians.end(), 
            (std::distance(medians.begin(), medians.end()) - 1) >> 1, compare).first);
        std::pair<RandomAccessIterator, RandomAccessIterator> pivot_interval = 
            cotl::Partition(first, last, 
            [&median_of_medians, &compare]
            (const typename std::iterator_traits<RandomAccessIterator>::value_type &a) { 
                return compare(a, median_of_medians); 
            });
        size_t weight_sum = 0;
        for (RandomAccessIterator it = first; it != pivot_interval.first; ++it)
        {
            weight_sum += weight(*it);
        }
        if (weighted_rank < weight_sum)
            return WeighedSelect(first, pivot_interval.first, weighted_rank, weight, compare);
        for (RandomAccessIterator it = pivot_interval.first; it != pivot_interval.second; ++it)
        {
            weight_sum += weight(*it);
        }
        if (weighted_rank >= weight_sum)
            return WeighedSelect(pivot_interval.second, last, 
                weighted_rank - weight_sum, weight, compare);
        return pivot_interval;
    }
}

#endif