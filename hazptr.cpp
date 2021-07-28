#include "hazptr.hpp"

namespace HazardPointer
{
    template <class T>
    void HazPtr<T>::protect(T* ptr) 
    {
        d_ptr.store(ptr, std::memory_order_seq_cst);
    }
}