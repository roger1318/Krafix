#ifndef KX_VEC_H
#define KX_VEC_H

#include <KxKernel/KxDeclSpec.h>
//
#if 1
namespace Kx {
    KX_EXPORT int KxAdd(int i1, int i2);

    class KX_EXPORT KCLASS {
        int _iNum;
    public:
        void setNum(int num);
        KX_EXPORT_STATIC static float fMine;
    };
}
#endif

#endif // KX_VEC_H