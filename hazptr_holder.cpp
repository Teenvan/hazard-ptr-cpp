#include "hazptr_holder.hpp"

namespace HazardPointer
{
    /*
    Safety

    Caller must guarantee that the address in the 
    atomic ptr is valid.

    Caller must also guarantee that the value behind
    the AtomicPtr will only be deallocated through calls
    to [HazPtrObject::retire()]
    */
    template<class T>
    T* HazPtrHolder<T>::load(const std::atomic<T*>& src)
    {

        if (d_hazptr == nullptr)
        {
            // If we don't already have a hazard pointer
            // then we need to acquire one from the 
            // domain. 
            d_hazptr = d_domain.acquire();
        }

        T* ptr = src.load(std::memory_order_seq_cst);
        while (true)
        {
            d_hazptr->protect(ptr);
            auto ptr2 = src.load(std::memory_order_seq_cst);
            if (ptr2 == ptr)
            {
                // All good -- protected
                return ptr;
            } else {
                ptr = ptr2;
            } 
        }

        return ptr;
    }

    template <class T>
    void HazPtrHolder<T>::reset()
    {
        if (d_hazptr != nullptr)
        {
            // Make my hazard ptr point to nothing again
            d_hazptr->d_ptr.store(nullptr, std::memory_order_seq_cst);
        }
    }

    template <class T>
    void HazPtrHolder<T>::drop() 
    {
        reset();
        if (d_hazptr != nullptr)
        {
            d_hazptr->active.store(false, std::memory_order_seq_cst);
        }
    }
}