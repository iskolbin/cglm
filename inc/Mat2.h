#ifndef CGLM_MAT2_H_
#define CGLM_MAT2_H_

#include "global.h"

#define Mat2_alloc() CGLM_ALLOC(4*sizeof(CGLM_TYPE))
#define Mat2_unpack(src) (src)[0],(src)[1],(src)[2],(src)[3]
#define Mat2_print(src) printf("Mat2(%g %g;%g %g)",Mat2_unpack(src))

#define Mat2_unsafeset(dest,a,b,c,d) do{(dest)[0]=(a);(dest)[1]=(b);(dest)[2]=(c);(dest)[3]=(d);}while(0) 
#define Mat2_set(dest,a,b,c,d) do{CGLM_TYPE a0=(a),a1=(b),a2=(c),a3=(d);(dest)[0]=a0;(dest)[1]=a1;(dest)[2]=a2;(dest)[3]=a3;}while(0)
#define Mat2_copy(dest,src) Mat2_set((dest),(src)[0],(src)[1],(src)[2],(src)[3])
#define Mat2_setrot(dest,s,c) Mat2_unsafeset((dest),(c),(s),-(s),(c))
#define Mat2_setrotv2(dest,rot) Mat2_setrot((dest),(rot)[0],(rot)[1])
#define Mat2_setrotrad(dest,rad) Mat2_setrot((dest),sin(rad),cos(rad))
#define Mat2_setscl(dest,sclx,scly) Mat2_unsafeset((dest),(sclx),0,0,(scly))
#define Mat2_setsclv2(dest,scl) Mat2_setscl((dest),(scl)[0],(scl)[1])
#define Mat2_identity(dest) Mat2_unsafeset((dest),1,0,0,1)

#define Mat2_det(src) ((src)[0]*(src)[3] - (src)[2]*(src)[1])
#define Mat2_frob(src) sqrt((src)[0]*(src)[0]+(src)[1]*(src)[1]+(src)[2]*(src)[2]+(src)[3]*(src)[3])
#define Mat2_add(dest,m1,m2) Mat2_unsafeset((dest),(m1)[0]+(m2)[0],(m1)[1]+(m2)[1],(m1)[2]+(m2)[2],(m1)[3]+(m2)[3])
#define Mat2_sub(dest,m1,m2) Mat2_unsafeset((dest),(m1)[0]-(m2)[0],(m1)[1]-(m2)[1],(m1)[2]-(m2)[2],(m1)[3]-(m2)[3])
#define Mat2_mul(dest,m1,m2) Mat2_set((dest),(m1)[0]*(m2)[0]+(m1)[2]*(m2)[1],(m1)[1]*(m2)[0]+(m1)[3]*(m2)[1],(m1)[0]*(m2)[2]+(m1)[2]*(m2)[3],(m1)[1]*(m2)[2]+(m1)[3]*(m2)[3])
#define Mat2_mulk(dest,src,k) Mat2_unsafeset((dest),(src)[0]*(k),(src)[1]*(k),(src)[2]*(k),(src)[3]*(k))
#define Mat2_addmulk(dest,m1,m2,k) Mat2_unsafeset((dest),(m1)[0]+((m2)[0]*(k)),(m1)[1]+((m2)[1]*(k)),(m1)[2]+((m2)[2]*(k)),(m1)[3]+((m2)[3]*(k)))

#define Mat2_rot(dest,src,s,c) Mat2_set((dest), (src)[0]*(c)+(src)[2]*(s), (src)[1]*(c)+(src)[3]*(s), (src)[0]*(-(s))+(src)[2]*(c), (src)[1]*(-(s))+(src)[3]*(c))
#define Mat2_rotv2(dest,src,rot) Mat2_rot((dest),(src),(rot)[0],(rot)[1])
#define Mat2_rotrad(dest,src,rad) Mat2_rot((dest),(src),sin(rad),cos(rad))
#define Mat2_scl(dest,src,sclx,scly) Mat2_set((dest), (src)[0]*(sclx), (src)[1]*(sclx), (src)[2]*(scly), (src)[3]*(scly))
#define Mat2_sclv2(dest,src,scl) Mat2_scl((dest),(src),(scl)[0],(scl)[1])
#define Mat2_sclx(dest,src,scl) Mat2_scl((dest),(src),(scl),1)
#define Mat2_scly(dest,src,scl) Mat2_scl((dest),(src),1,(scl))

#define Mat2_transpose(dest,src) Mat2_set((dest),(src)[0],(src)[2],(src)[1],(src)[3])
#define Mat2_adjoint(dest,src) Mat2_set((dest),(src)[3],-(src)[1],-(src)[2],(src)[0])
#define Mat2_invert(dest,src) do{CGLM_TYPE idet = 1/Mat2_det((src)); Mat2_set((dest),idet*(src)[3],-idet*(src)[1],-idet*(src)[2],idet*(src)[0]);}while(0)

#define Mat2_eqeps(m1,m2,eps) (CGLM_EQ(0,(m1),(m2),(eps)) && CGLM_EQ(1,(m1),(m2),(eps)) && CGLM_EQ(2,(m1),(m2),(eps)) && CGLM_EQ(3,(m1),(m2),(eps)))
#define Mat2_eq(m1,m2) Mat2_eqeps((m1),(m2),CGLM_DEFAULT_EPSILON)
#define Mat2_eqexact(m1,m2) ((m1)[0]==(m2)[0] && (m1)[1]==(m2)[1] && (m1)[2]==(m2)[2] && (m1)[3]==(m2)[3])

#endif
