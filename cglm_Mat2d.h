#ifndef CGLM_MAT2D_H_
#define CGLM_MAT2D_H_

#include "cglm_types.h"

Mat2d *Mat2d_create( void );
void   Mat2d_destroy( Mat2d *self );
Mat2d *Mat2d_clone( Mat2d *dest );
Mat2d *Mat2d_copy( Mat2d *dest, Mat2d *src );
Mat2d *Mat2d_identity( Mat2d *dest );
Mat2d *Mat2d_fromvalues( float a, float b, float c, float d, float tx, float ty; );
Mat2d *Mat2d_set( Mat2d *dest, float a, float b, float c, float d, float tx, float ty; );
Mat2d *Mat2d_inv( Mat2d *dest, Mat2d *src );
float  Mat2d_det( Mat2d *src );
Mat2d *Mat2d_rot( Mat2d *dest, Mat2d *src, float rad );
Mat2d *Mat2d_rotsc( Mat2d *dest, Mat2d *src, float vsin, float vcos );
Mat2d *Mat2d_scl( Mat2d *dest, Mat2d *src, float sclx, float scly );
Mat2d *Mat2d_transl( Mat2d *dest, Mat2d *src, float dx, float dy );
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
