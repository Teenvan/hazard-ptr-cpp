#include "hazptr_domain.hpp"

namespace HazardPointer
{
    template <class T, class D>
    HazPtr<T>* HazPtrDomain<T, D>::acquire() const 
    {
        auto& head_ptr = hazptrs.head;
        
    }
    
    template <class T, class D>
    void HazPtrDomain<T, D>::retire(D d, T* ptr) const
    {
        // TODO
    }
}