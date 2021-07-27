#pragma once
#include <atomic>
#include "hazptr.hpp"
#include "hazptr_domain.hpp"

namespace HazardPointer
{
    template<class T>
    class HazPtrHolder
    {
        public:
            // Protects an object pointed to by an atomic source
            T* load(const std::atomic<T*>& src) noexcept;

        private:
            HazPtr* d_hazptr = nullptr;
            HazPtrDomain d_domain;
    };
}