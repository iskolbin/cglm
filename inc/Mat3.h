#ifndef CGLM_MAT3_H_
#define CGLM_MAT3_H_

#include "global.h"

#define Mat3_alloc() CGLM_ALLOC(9*sizeof(CGLM_TYPE))
#define Mat3_unpack(a) (a)[0],(a)[1],(a)[2],(a)[3],(a)[4],(a)[5],(a)[6],(a)[7],(a)[8]
#define Mat3_print(a) printf("Mat3(%g %g %g;%g %g %g;%g %g %g)",Mat3_unpack(a))

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

#define Mat3_copy(dest,a) Mat3_unsafeset((dest),Mat3_unpack((a)))
#define Mat2_setrot(dest,s,c) Mat3_unsafeset((dest), (c),(s),0, -(s),(c),0, 0,0,1)
#define Mat2_setrotv2(dest,rot) Mat3_setrot((dest),(rot[0]),(rot[1]))
#define Mat2_setrotrad(dest,rad) Mat3_setrot((dest),sin(rad),cos(rad))
#define Mat3_setscl(dest,sclx,scly) Mat2_unsafeset((dest),(sclx),0,0, 0(scly),0, 0,0,1)
#define Mat3_setsclv2(dest,scl) Mat2_setscl((dest),(scl)[0],(scl)[1])
#define Mat3_identity(dest) Mat2_unsafeset((dest),1,0,0, 0,1,0, 0,0,1)

#define Mat3_det(src) ( \
		(src)[0] * ((src)[8] * (src)[4] - (src)[5] * (src)[7]) + \ 
		(src)[1] *(-(src)[8] * (src)[3] + (src)[5] * (src)[6]) + \
		(src)[2] * ((src)[7] * (src)[3] - (src)[4] * (src)[6])) \

#define Mat3_frob(src) sqrt( \
		(src)[0]*(src)[0] + (src)[1]*(src)[1] + (src)[2]*(src)[2] + \
		(src)[3]*(src)[3] + (src)[4]*(src)[4] + (src)[5]*(src)[5] + \
		(src)[6]*(src)[6] + (src)[7]*(src)[7] + (src)[8]*(src)[8])

#define Mat3_binary_op(dest,a,b,op) Mat3_unsafeset((dest),  \
		(a)[0] op (b)[0],(a)[1] op (b)[1],(a)[2] op (b)[2], \
		(a)[3] op (b)[3],(a)[4] op (b)[4],(a)[5] op (b)[5], \
		(a)[6] op (b)[6],(a)[7] op (b)[7],(a)[8] op (b)[8])

#define Mat3_add(dest,a,b) Mat3_binary_op((dest),(a),(b),+)
#define Mat3_sub(dest,a,b) Mat3_binary_op((dest),(a),(b),-)
#define Mat3_mul(dest,a,b) Mat3_set((dest), \
		b[0] * a[0] + b[1] * a[3] + b[2] * a[6], b[0] * a[1] + b[1] * a[4] + b[2] * a[7], b[0] * a[2] + b[1] * a[5] + b[2] * a[8], \
		b[3] * a[0] + b[4] * a[3] + b[5] * a[6], b[3] * a[1] + b[4] * a[4] + b[5] * a[7], b[3] * a[2] + b[4] * a[5] + b[5] * a[8], \
		b[6] * a[0] + b[7] * a[3] + b[8] * a[6], b[6] * a[1] + b[7] * a[4] + b[8] * a[7], b[6] * a[2] + b[7] * a[5] + b[8] * a[8] )
#define Mat3_mulk(dest,a,k) Mat3_unsafeset((dest), \
		(a)[0]*(k),(a)[1]*(k),(a)[2]*(k), \
		(a)[3]*(k),(a)[4]*(k),(a)[5]*(k), \
		(a)[6]*(k),(a)[7]*(k),(a)[8]*(k))
#define Mat3_addmulk(dest,a,b,k) Mat3_unsafeset((dest), \
		(a)[0]+((b)[0]*(k)),(a)[1]+((b)[1]*(k)),(a)[2]+((b)[2]*(k)), \
		(a)[3]+((b)[3]*(k)),(a)[4]+((b)[4]*(k)),(a)[5]+((b)[5]*(k)), \
		(a)[6]+((b)[6]*(k)),(a)[7]+((b)[7]*(k)),(a)[8]+((b)[8]*(k)))

#define Mat3_rotxyz(dest,a,sx,cx,sy,cy,sz,cz) //TODO
#define Mat3_rotxy(dest,a,sx,cx,sy,cy) Mat3_rotxyz((dest),(a),(sx),(cx),(sy),(cy),0,1)
#define Mat3_rotxz(dest,a,sx,cx,sz,cz) Mat3_rotxyz((dest),(a),(sx),(cx),0,1,(sz),(cz))
#define Mat3_rotyz(dest,a,sy,cy,sz,yz) Mat3_rotxyz((dest),(a),0,1,(sy),(cy),(sz),(cz))
#define Mat3_rotx(dest,a,s,c) Mat3_rotxyz((dest),(a),(s),(c),0,1,0,1)
#define Mat3_roty(dest,a,s,c) Mat3_rotxyz((dest),(a),0,1,(s),(c),0,1)
#define Mat3_rotz(dest,a,s,c) Mat3_rotxyz((dest),(a),0,1,0,1,(s),(c))
#define Mat3_rotxyzv6(dest,a,rot) Mat3_rotxyz((dest),(a),(rot)[0],(rot)[1],(rot)[2],(rot)[3],(rot)[4],(rot)[5])
#define Mat3_rotxyzv2(dest,a,rotxy,rotxz,rotyz) Mat3_rotxyz((dest),(a),(rotxy)[0],(rotxy)[1],(rotxz)[0],(rotxz)[1],(rotyz)[0],(rotyz)[1])
#define Mat3_rotxyzrad(dest,radx,rady,radz) Mat3_rotxyz((dest),(a),sin(radx),cos(radx),sin(rady),cos(rady),sin(radz),cos(radz))
#define Mat3_rotxyrad(dest,a,radx,rady) Mat3_rotxy((dest),(a),sin(radx),cos(radx),sin(rady),cos(rady))
#define Mat3_rotxzrad(dest,a,radx,radz) Mat3_rotxz((dest),(a),sin(radx),cos(radx),sin(radz),cos(radz))
#define Mat3_rotyzrad(dest,a,rady,radz) Mat3_rotyz((dest),(a),sin(rady),cos(rady),sin(radz),cos(radz))
#define Mat3_rotxyv4(dest,a,rot) Mat3_rotxy((dest),(a),(rot)[0],(rot)[1],(rot)[2],(rot)[3])
#define Mat3_rotxzv4(dest,a,rot) Mat3_rotxz((dest),(a),(rot)[0],(rot)[1],(rot)[2],(rot)[3])
#define Mat3_rotyzv4(dest,a,rot) Mat3_rotyz((dest),(a),(rot)[0],(rot)[1],(rot)[2],(rot)[3])
#define Mat3_rotxrad(dest,a,rad) Mat3_rotx((dest),(a),sin(rad),cos(rad))
#define Mat3_rotyrad(dest,a,rad) Mat3_roty((dest),(a),sin(rad),cos(rad))
#define Mat3_rotzrad(dest,a,rad) Mat3_rotz((dest),(a),sin(rad),cos(rad))
#define Mat3_rotxv2(dest,a,rot) Mat3_rotx((dest),(a),(rot)[0],(rot)[1])
#define Mat3_rotyv2(dest,a,rot) Mat3_roty((dest),(a),(rot)[0],(rot)[1])
#define Mat3_rotzv2(dest,a,rot) Mat3_rotz((dest),(a),(rot)[0],(rot)[1])

#define Mat3_sclxyz(dest,a,sclx,scly,sclz) //TODO
#define Mat3_sclxyzv3(dest,a,scl) (Mat3_sclxyz((dest),(a),(scl)[0],(scl)[1],(scl)[2]))
#define Mat3_sclxyv2(dest,a,scl) Mat3_sclxy((dest),(a),(scl)[0],(scl)[1])
#define Mat3_sclxzv2(dest,a,scl) Mat3_sclxz((dest),(a),(scl)[0],(scl)[1])
#define Mat3_sclyzv2(dest,a,scl) Mat3_sclyz((dest),(a),(scl)[0],(scl)[1])
#define Mat3_sclxy(dest,a,sclx,scly) Mat3_sclxyz((dest),(a),(sclx),(scly),1)
#define Mat3_sclxz(dest,a,sclx,sclz) Mat3_sclxyz((dest),(a),(sclx),1,(sclz))
#define Mat3_sclyz(dest,a,scly,sclz) Mat3_sclxyz((dest),(a),1,(scly),(sclz))
#define Mat3_sclx(dest,a,sclx) Mat3_sclxyz((dest),(a),(sclx),1,1)
#define Mat3_scly(dest,a,scly) Mat3_sclxyz((dest),(a),1,(scly),1)
#define Mat3_sclz(dest,a,sclz) Mat3_sclxyz((dest),(a),1,1,(sclz))

#define Mat3_transpose(dest,a) do{ \
	CGLM_TYPE a01 = a[1], a02 = a[2], a12 = a[5]; \
	(dest)[0]=(a)[0];(dest)[1]=(a)[3];(dest)[2]=(a)[6]; \
	(dest)[3]=a01;   (dest)[4]=(a)[4];(dest)[5]=(a)[7]; \
	(dest)[6]=(a)[2];(dest)[7]=a02;     (dest)[8]=a12;      \
}while(0)

// TODO
//#define Mat2_adjoint(dest,src) Mat2_set((dest),(src)[3],-(src)[1],-(src)[2],(src)[0])
//#define Mat2_invert(dest,src) do{CGLM_TYPE idet = 1/Mat2_det((src)); Mat2_set((dest),idet*(src)[3],-idet*(src)[1],-idet*(src)[2],idet*(src)[0]);}while(0)

#define Mat3_eqeps(a,b,eps) ( \
		(CGLM_EQ(0,(a),(b),(eps)) && CGLM_EQ(1,(a),(b),(eps)) && CGLM_EQ(2,(a),(b),(eps))) && \
		(CGLM_EQ(3,(a),(b),(eps)) && CGLM_EQ(4,(a),(b),(eps)) && CGLM_EQ(2,(a),(b),(eps))) && \
		(CGLM_EQ(0,(a),(b),(eps)) && CGLM_EQ(1,(a),(b),(eps)) && CGLM_EQ(2,(a),(b),(eps))) )
#define Mat2_eq(a,b) Mat2_eqeps((a),(b),CGLM_DEFAULT_EPSILON)
#define Mat2_eqexact(a,b) ( \
		(a)[0]==(b)[0] && (a)[1]==(b)[1] && (a)[2]==(b)[2] && \
		(a)[3]==(b)[3] && (a)[4]==(b)[4] && (a)[5]==(b)[5] && \
		(a)[6]==(b)[6] && (a)[7]==(b)[7] && (a)[8]==(b)[8] )

#endif
