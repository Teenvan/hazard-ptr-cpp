#pragma once
#include "hazptr.hpp"
#include "hazptrs.hpp"
#include "retired.hpp"
#include <memory>

namespace HazardPointer
{
    template <class T, class D = std::default_delete<T> >
    // Holds the linked list of HazPtrs
    class HazPtrDomain
    {
        public:
            HazPtr<T>* acquire() const;
            void retire(D d, T* ptr) const;
            HazPtrs<T> hazptrs;
            HazPtr<T> retired_hazptrs;
            Retired retired;
        private:
            D deleter;
    };
}