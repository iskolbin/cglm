#ifndef CGLM_MAT2D_H_
#define CGLM_MAT2D_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"

#ifndef CGLM_MAT2D_EPS
#define CGLM_MAT2D_EPS (0.0001f)
#endif

#ifndef CGLM_MAT2D_FORMAT
#define CGLM_MAT2D_FORMAT "%f %f %f\n%f %f %f"
#endif

Mat2d *Mat2d_set( Mat2d *dest, float a, float b, float c, float d, float tx, float ty ); 
Mat2d *Mat2d_transform( Mat2d *dest, Mat2d *src, float a, float b, float c, float d );
Mat2d *Mat2d_translate( Mat2d *dest, Mat2d *src, float dx, float dy );
Mat2d *Mat2d_inv( Mat2d *dest, Mat2d *src );
Mat2d *Mat2d_fromrot( Mat2d *dest, float rad );
Mat2d *Mat2d_fromscl( Mat2d *dest, float sclx, float scly );
Mat2d *Mat2d_fromtransl( Mat2d *dest, float dx, float dy );
float *Mat2d_frob( Mat2d *src );
Mat2d *Mat2d_add( Mat2d *dest, Mat2 *m1, Mat2 *m2 );
Mat2d *Mat2d_sub( Mat2d *dest, Mat2 *m1, Mat2 *m2 );
Mat2d *Mat2d_mul( Mat2d *dest, Mat2d *m1, Mat2d *m2 );
Mat2d *Mat2d_mulk( Mat2d *dest, Mat2d *src, float k );
Mat2d *Mat2d_mulk_add( Mat2d *dest, Mat2d *m1, Mat2d *m2, float k );
void   Mat2d_fprintf( FILE *fout, Mat2d *src, const char *format );

#define Mat2d_create() ((Mat2d *) malloc(6*sizeof float))
#define Mat2d_destroy(src) free((src))
#define Mat2d_copy(dest,src) ((Mat2d *) memcpy((dest),(src),6*sizeof float))
#define Mat2d_clone(src) (Mat2d_copy(Mat2d_create(),(src)))
#define Mat2d_transformm(dest,src,mat2) (Mat2d_transform((dest),(src),(mat2)[0],(mat2)[1],(mat2)[2],(mat2)[3]))
#define Mat2d_translatev(dest,src,vec2) (Mat2d_translate((dest),(src),(vec2)[0],(vec2)[1]))
#define Mat2d_identity(dest) (Mat2d_set((dest),1.0f,0.0f,0.0f,1.0f,0.0f,0.0f))
#define Mat2d_fromvalues(a,b,c,d,tx,ty) (Mat2d_set((Mat2d_create()),(a),(b),(c),(d),(tx),(ty)))
#define Mat2d_det(src) ((src)[0]*(src)[3]-(src)[1]*(src)[2])
#define Mat2d_rotsc(dest,src,s,c) (Mat2d_transform((dest),(src),(c),(s),(-s),(c)))
#define Mat2d_rot(dest,src,rad) (Mat2d_rotsc((dest),(src),sin((rad)),cos((rad))))
#define Mat2d_scl(dest,src,sclx,scly) (Mat2d_transform((dest),(src),(sclx),0.0f,0.0f,(scly)))
#define Mat2d_sclv(dest,src,vec2) (Mat2d_scl((dest),(src),(vec2)[0],(vec2)[1]))
#define Mat2d_skw(dest,src,skwx,skwy) (Mat2d_transform((dest),(src),1.0f,(skwx),(skwy),1.0f))
#define Mat2d_skwv(dest,src,vec2) (Mat2d_skw((dest),(src),(vec2)[0],(vec2)[1]))
#define Mat2d_fromsclv(dest,vec2) (Mat2d_fromscl((dest),(vec2)[0],(vec2)[1]))
#define Mat2d_fromtranslv(dest,vec2) (Mat2d_fromtransl((dest),(vec2)[0],(vec2)[1]))
#define Mat2d_eqeps(m1,m2,eps) (\
		fabsf((m1)[0]-(m2)[0])<=eps && fabsf((m1)[1]-(m2)[1])<=eps && fabsf((m1)[2]-(m2)[2])<=eps && \
		fabsf((m1)[3]-(m2)[3])<=eps && fabsf((m1)[4]-(m2)[4])<=eps && fabsf((m1)[5]-(m2)[5])<=eps)
#define Mat2d_eq(m1,m2) (Mat2d_eqeps((m1),(m2),CGLM_MAT2D_EPS)
#define Mat2d_exacteq(m1,m2) (\
	(m1)[0]==(m2)[0] && (m1)[1]==(m2)[1] && (m1)[2]==(m2)[2] && \
	(m1)[3]==(m2)[3] && (m1)[4]==(m2)[4] && (m1)[5]==(m2)[5])

#endif
