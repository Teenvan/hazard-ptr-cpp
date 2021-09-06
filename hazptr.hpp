#pragma once
#include <atomic>

namespace HazardPointer
{
    template <class T>
    class HazPtr
    {
        public:
            // T* refers to the entity the hazard pointer
            // is guarding.
            void protect(T* ptr);

            std::atomic<T*> d_ptr;
            std::atomic<HazPtr<T>> next;
            // Bool active that tells us whether to reuse them or not
            std::atomic<bool> active;
    };
}