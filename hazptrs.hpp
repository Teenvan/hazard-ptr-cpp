#pragma once
#include <atomic>
#include "hazptr.hpp"

namespace HazardPointer
{
    template<class T>
    class HazPtrs
    {
        public:
            std::atomic<HazPtr<T>> head;
            
    };
}