#pragma once
#include "hazptr_domain.hpp"

namespace HazardPointer
{
    template <typename T, typename D = std::default_delete<T> >
    class HazPtrObject
    {
        public:
            void retire(D d);
            HazPtrDomain<T> d_domain;
        protected:
            HazPtrObject() = default;
        private:
            D deleter;
    };
}