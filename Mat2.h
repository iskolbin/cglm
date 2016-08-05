#ifndef CGLM_MAT2D_H_
#define CGLM_MAT2D_H_

#include "cglm_types.h"

#define Mat2d_create() ((Mat2d *) malloc( 6 * sizeof float ))
#define Mat2d_destroy(src) free((src))
#define Mat2d_copy(dest,src) ((Mat2d *) memcpy((dest),(src),6*sizeof float))
#define Mat2d_clone(src) (Mat2d_copy(Mat2d_create(),(src)))
Mat2d *Mat2d_set( Mat2d *dest, float a, float b, float c, float d, float tx, float ty ); 
Mat2d *Mat2d_transform( Mat2d *dest, Mat2d *src, float a, float b, float c, float d );
Mat2d *Mat2d_translate( Mat2d *dest, Mat2d *src, float dx, float dy );
	//do{dest[0]=a; dest[1]=b; dest[2]=c; dest[3]=d; dest[4]=tx; dest[5]=ty;}while(0)
#define Mat2d_identity(dest) (Mat2d_set((dest),1.0f,0.0f,0.0f,1.0f,0.0f,0.0f))
#define Mat2d_fromvalues(a,b,c,d,tx,ty) (Mat2d_set((Mat2d_create()),(a),(b),(c),(d),(tx),(ty)))
Mat2d *Mat2d_fromvalues( float a, float b, float c, float d, float tx, float ty );
Mat2d *Mat2d_inv( Mat2d *dest, Mat2d *src );
#define Mat2d_det(src) ((src)[0]*(src)[3]-(src)[1]*(src)[2])
#define Mat2d_rotsc(dest,src,s,c) (Mat2d_transform((dest),(src),(c),(s),(-s),(c)))
#define Mat2d_rot(dest,src,rad) (Mat2d_rotsc((dest),(src),sin((rad)),cos((rad))))
#define Mat2d_scl(dest,src,sclx,scly) (Mat2d_transform((dest),(src),1.0f,0.0f,0.0f,1.0f))
Mat2d *Mat2d_scl( Mat2d *dest, Mat2d *src, float sclx, float scly );
Mat2d *Mat2d_sclv( Mat2d *dest, Mat2d *src, Vec2 scl );
Mat2d *Mat2d_translv( Mat2d *dest, Mat2d *src, Vec2 dxy );
Mat2d *Mat2d_fromrot( Mat2d *dest, float rad );
Mat2d *Mat2d_fromscl( Mat2d *dest, float sclx, float scly );
Mat2d *Mat2d_fromsclv( Mat2d *dest, Vec2 scl );
Mat2d *Mat2d_fromtransl( Mat2d *dest, float dx, float dy );
Mat2d *Mat2d_fromtranslv( Mat2d *dest, Vec2 dxy );
float *Mat2d_frob( Mat2d *src );
Mat2d *Mat2d_add( Mat2d *dest, Mat2 *m1, Mat2 *m2 );
Mat2d *Mat2d_sub( Mat2d *dest, Mat2 *m1, Mat2 *m2 );
Mat2d *Mat2d_mul( Mat2d *dest, Mat2d *m1, Mat2d *m2 );
Mat2d *Mat2d_mulk( Mat2d *dest, Mat2d *src, float k );
Mat2d *Mat2d_mulk_add( Mat2d *dest, Mat2d *m1, Mat2d *m2, float k );
int    Mat2d_eq( Mat2d *m1, Mat2d *m2 );
int    Mat2d_equal( Mat2d *m1, Mat2d *m2 );

#endif
