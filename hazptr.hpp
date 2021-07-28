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
    };
}