#pragma once
#include <atomic>
#include "retired.hpp"

namespace HazardPointer
{
    template <class T>
    class RetiredList
    {
        std::atomic<Retired<T>> head;    
    };
}