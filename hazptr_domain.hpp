#pragma once
#include "hazptr.hpp"
#include "retired.hpp"

namespace HazardPointer
{
    template <class T>
    // Holds the linked list of HazPtrs
    class HazPtrDomain
    {
        public:
            HazPtr<T>* acquire() const;
            HazPtr<T> hazptrs;
            Retired retired;
    };
}