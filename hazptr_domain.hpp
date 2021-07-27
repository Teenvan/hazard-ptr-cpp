#pragma once
#include "hazptr.hpp"
#include "retired.hpp"

namespace HazardPointer
{
    // Holds the linked list of HazPtrs
    class HazPtrDomain
    {
        public:
            HazPtr* acquire() const;
            HazPtr hazptrs;
            Retired retired;
    };
}