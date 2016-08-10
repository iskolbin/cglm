#ifndef CGLM_MAT2_H_
#define CGLM_MAT2_H_

#include "global.h"

#ifndef CGLM_DEFAULT_MAT2_FORMAT
#define CGLM_DEFAULT_MAT2_FORMAT "Mat2(%g,%g,%g,%g)"
#endif

#define Mat2_alloc() calloc(4,sizeof float)

#define Mat2_copy(dest,src) Mat2_set((dest),(src)[0],(src)[1],(src)[2],(src)[3])
#define Mat2_clone(src) Mat2_copy(Mat2_alloc(),(src))

#define Mat2_set(dest,a,b,c,d) do{(dest)[0]=(a);(dest)[1]=(b);(dest)[2]=(c);(dest)[3]=(d);}while(0)
#define Mat2_setrotsc(dest,s,c) Mat2_set((dest),(c),(s),-(s),(c))
#define Mat2_setrot(dest,rad) Mat2_set((dest),sin((rad)),cos((rad)))
#define Mat2_setscl(dest,sclx,scly) Mat2_set((dest),(sclx),0,0,(scly))
#define Mat2_setsclv2(dest,v2) Mat2_setscl((dest),(v2)[0],(v2)[1])
#define Mat2_identity(dest) Mat2_set((dest),1,0,0,1)

#define Mat2_create() Mat2_identity(Mat2_alloc())
#define Mat2_fromvalues(a,b,c,d) Mat2_set(Mat2_alloc(),(a),(b),(c),(d))
#define Mat2_fromrotsc(s,c) Mat2_setrotsc(Mat2_alloc(),(s),(c))
#define Mat2_fromrot(rad) Mat2_setrot(Mat2_alloc(),(rad))
#define Mat2_fromscl(sclx,scly) Mat2_setscl(Mat2_alloc(),(sclx),(scly))
#define Mat2_fromsclv2(v2) Mat2_setsclv2(Mat2_alloc(),(v2))

#define Mat2_det(src) ((src)[0]*(src)[3] - (src)[2]*(src)[1])
#define Mat2_frob(src) sqrt((src)[0]*(src)[0]+(src)[1]*(src)[1]+(src)[2]*(src)[2]+(src)[3]*(src)[3])
#define Mat2_add(dest,m1,m2) Mat2_set((dest),(m1)[0]+(m2)[0],(m1)[1]+(m2)[1],(m1)[2]+(m2)[2],(m1)[3]+(m2)[3])
#define Mat2_sub(dest,m1,m2) Mat2_set((dest),(m1)[0]-(m2)[0],(m1)[1]-(m2)[1],(m1)[2]-(m2)[2],(m1)[3]-(m2)[3])
#define Mat2_mul(dest,m1,m2) Mat2_set((dest),(m1)[0]*(m2)[0]+(m1)[2]*(m2)[1],(m1)[1]*(m2)[0]+(m1)[3]*(m2)[1],(m1)[0]*(m2)[2]+(m1)[2]*(m2)[3],(m1)[1]*(m2)[2]+(m1)[3]*(m2)[3])
#define Mat2_mulk(dest,src,k) Mat2_set((dest),(src)[0]*(k),(src)[1]*(k),(src)[2]*(k),(src)[3]*(k))
#define Mat2_addmulk(dest,m1,m2,k) Mat2_set((dest),(m1)[0]+((m2)[0]*(k)),(m1)[1]+((m2)[1]*(k)),(m1)[2]+((m2)[2]*(k)),(m1)[3]+((m2)[3]*(k)))

#define Mat2_transpose(dest,src) Mat2_set((dest),(src)[0],(src)[2],(src)[1],(src)[3])
#define Mat2_adjoint(dest,src) Mat2_set((dest),(src)[3],-(src)[1],-(src)[2],(src)[0])
#define Mat2_invert(dest,src) do{CGLM_TYPE idet = 1/Mat2_det((src)); Mat2_set((dest),idet*(src)[3],-idet*(src)[1],-idet*(src)[2],idet*(src)[0];}while(0)

#define Mat2d_eqeps(m1,m2,eps) (fabsf((m1)[0]-(m2)[0])<=eps && fabsf((m1)[1]-(m2)[1])<=eps && fabsf((m1)[2]-(m2)[2])<=eps && fabsf((m1)[3]-(m2)[3])<=eps)
#define Mat2d_eq(m1,m2) Mat2d_eqeps((m1),(m2),CGLM_DEFAULT_EPSILON)
#define Mat2d_exacteq(m1,m2) ((m1)[0]==(m2)[0] && (m1)[1]==(m2)[1] && (m1)[2]==(m2)[2] && (m1)[3]==(m2)[3])

#define Mat2_unpack(src) (src)[0],(src)[1],(src)[2],(src)[3]
#define Mat2_print(src) printf(CGLM_DEFAULT_MAT2_FORMAT,Mat2_unpack((src)))

#endif
