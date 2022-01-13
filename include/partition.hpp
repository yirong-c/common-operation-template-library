#ifndef _PARTITION_HPP
#define _PARTITION_HPP

#include "sort.hpp"

namespace cotl
{
    /**
     * Partition the array arround pivot 
     * and group all elements with the value of partition_arround_val together.
     * @param first range
     * @param last range
     * @param compare comparsion function object which 
     *                  returns 0 if the argument is equal to the pivot value and 
     *                  returns negative value if the argument is less than the pivot value.
     *          signature: int Cmp(const Type &a); 
     * @return range of elements that are eqaul to the pivot value
     */
    template <typename BidirectionalIterator, typename Compare>    
    std::pair<BidirectionalIterator, BidirectionalIterator> 
        Partition(BidirectionalIterator first, BidirectionalIterator last, Compare compare)
    {
        BidirectionalIterator i = first;
        BidirectionalIterator m = first;
        for (BidirectionalIterator j = first; j != last; ++j)
        {
            if (compare(*j) < 0)
            {
                std::swap(*m, *j);
                std::swap(*i, *m);
                ++m;
                ++i;
            }
            else if (compare(*j) == 0)
            {
                std::swap(*m, *j);
                ++m;
            }
        }
        return std::make_pair(i, m);
    }
}

#endif