#ifndef _SORT_HPP
#define _SORT_HPP

#include <iterator>

namespace col
{
    /**
     * Insertion sort.
     * @param first range
     * @param last range
     * @param compare comparsion function object which 
     *                  returns true if the first argument is less than the second argument.
     *          signature: bool Cmp(const Type &a, const Type &b); 
     */
    template <typename BidirectionalIterator, typename Compare>    
    void InsertionSort(BidirectionalIterator first, BidirectionalIterator last, Compare compare)
    {
        if (first == last) return;
        BidirectionalIterator j = first;
        ++j;
        while (j != last)
        {
            typename std::iterator_traits<BidirectionalIterator>::value_type
                key = std::move(*j);
            BidirectionalIterator i = j;
            BidirectionalIterator k = j;
            --k;
            while (first != i && compare(key, *k))
            {
                *i = std::move(*k);
                --i;
                --k;
            }
            *i = std::move(key);
            ++j;
        }
    }

    template <typename BidirectionalIterator>    
    void InsertionSort(BidirectionalIterator first, BidirectionalIterator last)
    {
        InsertionSort(first, last, 
            std::less<typename std::iterator_traits<BidirectionalIterator>::value_type>());
    }
}

#endif