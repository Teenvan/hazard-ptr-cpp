#pragma once

namespace HazardPointer
{
    template <class T>
    class HazPtr
    {
        public:
            // T* refers to the entity the hazard pointer
            // is guarding.
            void protect(T* ptr);
            
            T* d_ptr;
    };
}