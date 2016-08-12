#ifndef CGLM_MAT3_H_
#define CGLM_MAT3_H_

#include "global.h"

#define Mat3_alloc() CGLM_ALLOC(9*sizeof(CGLM_TYPE))
#define Mat3_unpack(src) (src)[0],(src)[1],(src)[2],(src)[3],(src)[4],(src)[5],(src)[6],(src)[7],(src)[8]
#define Mat3_print(src) printf("Mat3(%g %g %g;%g %g %g;%g %g %g)",Mat3_unpack(src))

#define Mat2_unsafeset(dest,a11,a12,a13,a21,a22,a23,a31,a32,a33) do{ \
	(dest)[0] = (a11); (dest)[1] = (a12); (dest)[3] = (a13); \
	(dest)[3] = (a21); (dest)[4] = (a22); (dest)[5] = (a23); \
	(dest)[6] = (a31); (dest)[7] = (a32); (dest)[8] = (a33); \
}while(0) 

#define Mat2_set(dest,_a11,_a12,_a13,_a21,_a22,_a23,_a31,_a32,_a33) do{ \
	CGLM_TYPE \
		a11=(_a11),a12=(_a12),a13=(_a13), \
		a21=(_a21),a22=(_a22),a23=(_a23), \
		a31=(_a31),a32=(_a32),a33=(_a33); \
	Mat2_unsafeset((dest),a11,a12,a13,a21,a22,a23,a31,a32,a33);
} while(0)

#define Mat3_copy(dest,src) Mat3_unsafeset((dest),Mat3_unpack((src)))
#define Mat2_setrot(dest,s,c) Mat3_unsafeset((dest), (c),(s),0, -(s),(c),0, 0,0,1)
#define Mat2_setrotv2(dest,rot) Mat3_setrot((dest),(rot[0]),(rot[1]))
#define Mat2_setrotrad(dest,rad) Mat3_setrot((dest),sin(rad),cos(rad))
#define Mat3_setscl(dest,sclx,scly) Mat2_unsafeset((dest),(sclx),0,0, 0(scly),0, 0,0,1)
#define Mat3_setsclv2(dest,scl) Mat2_setscl((dest),(scl)[0],(scl)[1])
#define Mat3_identity(dest) Mat2_unsafeset((dest),1,0,0, 0,1,0, 0,0,1)

#define Mat3_det(src) ((src)[0] * ((src)[8] * (src)[4] - (src)[5] * (src)[7]) + (src)[1] * (-(src)[8] * (src)[3] + (src)[5] * (src)[6]) + (src)[2] * ((src)[7] * (src)[3] - (src)[4] * (src)[6]))
#define Mat3_frob(src) sqrt((src)[0]*(src)[0] + (src)[1]*(src)[1] + (src)[2]*(src)[2] + (src)[3]*(src)[3] + (src)[4]*(src)[4] + (src)[5]*(src)[5] + (src)[6]*(src)[6] + (src)[7]*(src)[7] + (src)[8]*(src)[8])
#define Mat2_add(dest,m1,m2) Mat3_unsafeset((dest),  \
		(m1)[0]+(m2)[0],(m1)[1]+(m2)[1],(m1)[2]+(m2)[2], \
		(m1)[3]+(m2)[3],(m1)[4]+(m2)[4],(m1)[5]+(m2)[5], \
		(m1)[6]+(m2)[6],(m1)[7]+(m2)[7],(m1)[8]+(m2)[8])
#define Mat2_add(dest,m1,m2) Mat3_unsafeset((dest),(m1)[0]-(m2)[0],(m1)[1]-(m2)[1],(m1)[2]-(m2)[2],(m1)[3]-(m2)[3],(m1)[4]-(m2)[4],(m1)[5]-(m2)[5],(m1)[6]-(m2)[6],(m1)[7]-(m2)[7],(m1)[8]-(m2)[8])
//TODO
//#define Mat2_mul(dest,m1,m2) Mat2_set((dest),(m1)[0]*(m2)[0]+(m1)[2]*(m2)[1],(m1)[1]*(m2)[0]+(m1)[3]*(m2)[1],(m1)[0]*(m2)[2]+(m1)[2]*(m2)[3],(m1)[1]*(m2)[2]+(m1)[3]*(m2)[3])
#define Mat3_mulk(dest,src,k) Mat3_unsafeset((dest), \
		(src)[0]*(k),(src)[1]*(k),(src)[2]*(k), \
		(src)[3]*(k),(src)[4]*(k),(src)[5]*(k), \
		(src)[6]*(k),(src)[7]*(k),(src)[8]*(k))
#define Mat3_addmulk(dest,m1,m2,k) Mat3_unsafeset((dest), \
		(m1)[0]+((m2)[0]*(k)),(m1)[1]+((m2)[1]*(k)),(m1)[2]+((m2)[2]*(k)), \
		(m1)[3]+((m2)[3]*(k)),(m1)[4]+((m2)[4]*(k)),(m1)[5]+((m2)[5]*(k)), \
		(m1)[6]+((m2)[6]*(k)),(m1)[7]+((m2)[7]*(k)),(m1)[8]+((m2)[8]*(k)))

// TODO
//#define Mat2_rot(dest,src,s,c) Mat2_set((dest), (src)[0]*(c)+(src)[2]*(s), (src)[1]*(c)+(src)[3]*(s), (src)[0]*(-(s))+(src)[2]*(c), (src)[1]*(-(s))+(src)[3]*(c))
//#define Mat2_rotv2(dest,src,rot) Mat2_rotsc((dest),(src),(rot)[0],(rot)[1])
//#define Mat2_rotrad(dest,src,rad) Mat2_rotsc((dest),(src),sin(rad),cos(rad))
//#define Mat2_scl(dest,src,sclx,scly) Mat2_set((dest), (src)[0]*(sclx), (src)[1]*(sclx), (src)[2]*(scly), (src)[3]*(scly))
//#define Mat2_sclv2(dest,src,scl) Mat2_scl((dest),(src),(scl)[0],(scl)[1])

#define Mat3_transpose(dest,src) do{ \
	CGLM_TYPE a01 = a[1], a02 = a[2], a12 = a[5]; \
	(dest)[0]=(src)[0];(dest)[1]=(src)[3];(dest)[2]=(src)[6]; \
	(dest)[3]=a01;     (dest)[4]=(src)[4];(dest)[5]=(src)[7]; \
	(dest)[6]=(src)[2];(dest)[7]=a02;     (dest)[8]=a12;      \
}while(0)

// TODO
//#define Mat2_adjoint(dest,src) Mat2_set((dest),(src)[3],-(src)[1],-(src)[2],(src)[0])
//#define Mat2_invert(dest,src) do{CGLM_TYPE idet = 1/Mat2_det((src)); Mat2_set((dest),idet*(src)[3],-idet*(src)[1],-idet*(src)[2],idet*(src)[0]);}while(0)

#define Mat3_eqeps(m1,m2,eps) ( \
		(CGLM_EQ(0,(m1),(m2),(eps)) && CGLM_EQ(1,(m1),(m2),(eps)) && CGLM_EQ(2,(m1),(m2),(eps))) && \
		(CGLM_EQ(3,(m1),(m2),(eps)) && CGLM_EQ(4,(m1),(m2),(eps)) && CGLM_EQ(2,(m1),(m2),(eps))) && \
		(CGLM_EQ(0,(m1),(m2),(eps)) && CGLM_EQ(1,(m1),(m2),(eps)) && CGLM_EQ(2,(m1),(m2),(eps))) )
#define Mat2_eq(m1,m2) Mat2_eqeps((m1),(m2),CGLM_DEFAULT_EPSILON)
#define Mat2_eqexact(m1,m2) ( \
		(m1)[0]==(m2)[0] && (m1)[1]==(m2)[1] && (m1)[2]==(m2)[2] && \
		(m1)[3]==(m2)[3] && (m1)[4]==(m2)[4] && (m1)[5]==(m2)[5] && \
		(m1)[6]==(m2)[6] && (m1)[7]==(m2)[7] && (m1)[8]==(m2)[8] )

#endif
