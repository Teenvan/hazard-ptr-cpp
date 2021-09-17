#include "hazptr.hpp"

namespace HazardPointer
{
    template <class T>
    HazPtr<T>::HazPtr(T* p, HazPtr<T> n, bool a)
    {
        d_ptr.store(ptr, std::memory_order_seq_cst);
        next.store(n, std::memory_order_seq_cst);
        active.store(a, std::memory_order_seq_cst);
    }


    template <class T>
    void HazPtr<T>::protect(T* ptr) 
    {
        d_ptr.store(ptr, std::memory_order_seq_cst);
    }
}