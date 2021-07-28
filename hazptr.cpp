#include "hazptr.hpp"

namespace HazardPointer
{
    template <class T>
    void HazPtr<T>::protect(T* ptr) 
    {
        d_ptr = ptr;
    }
}