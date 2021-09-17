#include "hazptr_domain.hpp"

namespace HazardPointer
{
    template <class T, class D>
    HazPtr<T>* HazPtrDomain<T, D>::acquire() const 
    {
        // Walk the list of hazard pointers and 
        auto& head_ptr = hazptrs.head;
        auto node = head_ptr.load(std::memory_order_seq_cst);

        while (true)
        {
            // If the active flag is set, we cannot use that node
            while (node && node.active.load(std::memory_order_seq_cst))
            {
                node = node.next.load(std::memory_order_seq_cst);   
            }
 
            // If we get a nullptr, we don't have any hazard pointers to reuse
            // and we need to allocate.
            if (!node)
            {
                // No free HazPtrs --  need to allocate a new one
                // HazPtr(ptr, next, active)
                HazPtr hazptr(nullptr, nullptr, true);

                auto head = head_ptr.load(std::memory_order_seq_cst);
                // And stick it at the head of the linked list
                while (true)
                {
                    hazptr.next = head; 
                    // Compare and swap the head ptr
                    if (std::atomic_compare_exchange_weak(head_ptr, head, hazptr))
                    {
                        // Safety: will never be de-allocated
                        // Return the mem address of the new hazptr
                        return &hazptr;
                    } else {
                        // Head has changed, try again with that as our 
                        // next ptr.
                        continue;
                    }
                }
            } 
            else 
            {
                if (std::atomic_compare_exchange_weak(&node.active, false, true))
                {
                    // It's ours
                    return &node;
                }
                else
                {
                    // Someone else grabbed this node right before us
                    // Keep walking
                }

            }
        }
        
    }
    
    template <class T, class D>
    void HazPtrDomain<T, D>::retire(D d, T* ptr) const
    {
        // TODO
    }
}