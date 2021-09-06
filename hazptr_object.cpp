#include "hazptr_object.hpp"
#include <memory>

namespace HazardPointer
{
    template <typename T, typename D>
    void HazPtrObject<T, D>::retire(D d = D())
    {
        // Retire from the domain
        d_domain.retire();
    }
}