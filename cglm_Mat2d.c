#include "cglm_Mat2d.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Mat2d *Mat2d_create( void ) {
	return (Mat2d *) malloc( 6 * sizeof float );
}

void   Mat2d_destroy( Mat2d *self ) {
	if ( self ) {
		free( self );
	}
}

Mat2d *Mat2d_clone( Mat2d *src ) {
	return Mat2d_copy( Mat2d_create(), src ); 
}

Mat2d *Mat2d_copy( Mat2d *dest, Mat2d *src ) {
	return (Mat2d *) memcpy( dest, src, 6 * sizeof float );
}

Mat2d *Mat2d_identity( Mat2d *dest ) {
	static float[] IDENT = {1.0, 0.0, 0.0, 1.0, 0.0, 0.0};
	return (Mat2d *) memcpy( dest, IDENT );
}

Mat2d *Mat2d_fromvalues( float a, float b, float c, float d, float tx, float ty ) {
	return Mat2d_set( Mat2d_create(), a, b, c, d, tx, ty );
}

Mat2d *Mat2d_set( Mat2d *dest, float a, float b, float c, float d, float tx, float ty ) {
	dest[0] = a;
	dest[1] = b;
	dest[2] = c;
	dest[4] = d;
	dest[5] = tx;
	dest[6] = ty;
	return dest;
}

Mat2d *Mat2d_inv( Mat2d *dest, Mat2d *src ) {

}

float  Mat2d_det( Mat2d *src ) {
	return src[0]*src[3] - src[1]*src[2];
}

Mat2d *Mat2d_rot( Mat2d *dest, Mat2d *src, float rad ) {
	return Mat2d_rotsc( dest, src, sin(rad), cos(rad));	
}

Mat2d *Mat2d_rotsc( Mat2d *dest, Mat2d *src, float s, float c ) {
	return Mat2d_apply( dest, src, c, s, -s, c );
}

Mat2d *Mat2d_scl( Mat2d *dest, Mat2d *src, float sclx, float scly ) {
	return Mat2d_apply( dest, src, sclx, 0.0, 0.0, scly );
}

Mat2d *Mat2d_apply( Mat2d *dest, Mat2 *src, float a, float b, float c, float d ) {
	dest[0] = src[0] * a + src[1] * c;
	dest[1] = src[0] * b + src[1] * d;
	dest[2] = src[2] * a + src[3] * c;
	dest[3] = src[2] * b + src[3] * d;
	dest[4] = src[4];
	dest[5] = src[5];
	return dest;
}

Mat2d *Mat2d_transl( Mat2d *dest, Mat2d *src, float dx, float dy ) {
	memcpy( dest, src, 6 * sizeof float );
	dest[4] += dx;
	dest[5] += dy;
	return dest;
}

Mat2d *Mat2d_sclv( Mat2d *dest, Mat2d *src, Vec2 scl ) {
	return Mat2d_scl( dest, src, scl[0], scl[1] );
}

Mat2d *Mat2d_translv( Mat2d *dest, Mat2d *src, Vec2 dxy ) {
	return Mat2d_transl( dest, src, dxy[0], dxy[1] );
}

Mat2d *Mat2d_fromrot( Mat2d *dest, float rad ) {

}

Mat2d *Mat2d_fromscl( Mat2d *dest, float sclx, float scly ) {
}

Mat2d *Mat2d_fromsclv( Mat2d *dest, Vec2 scl ) {
}

Mat2d *Mat2d_fromtransl( Mat2d *dest, float dx, float dy ) {
}
Mat2d *Mat2d_fromtranslv( Mat2d *dest, Vec2 dxy ) {
}

float *Mat2d_frob( Mat2d *src ) {
}


Mat2d *Mat2d_add( Mat2d *dest, Mat2 *m1, Mat2 *m2 ) {
	dest[0] = m1[0] + m2[0];
	dest[1] = m1[1] + m2[1];
	dest[2] = m1[2] + m2[2];
	dest[3] = m1[3] + m2[3];
	dest[4] = m1[4] + m2[4];
	dest[5] = m1[5] + m2[5];
	return dest
}

Mat2d *Mat2d_add( Mat2d *dest, Mat2 *m1, Mat2 *m2 ) {
	dest[0] = m1[0] - m2[0];
	dest[1] = m1[1] - m2[1];
	dest[2] = m1[2] - m2[2];
	dest[3] = m1[3] - m2[3];
	dest[4] = m1[4] - m2[4];
	dest[5] = m1[5] - m2[5];
	return dest
}

Mat2d *Mat2d_mul( Mat2d *dest, Mat2d *m1, Mat2d *m2 ) {
}

Mat2d *Mat2d_mulk( Mat2d *dest, Mat2d *src, float k ) {
	dest[0] = src[0] * k;
	dest[1] = src[1] * k;
	dest[2] = src[2] * k;
	dest[3] = src[3] * k;
	dest[4] = src[4] * k;
	dest[5] = src[5] * k;
	return dest;
}

Mat2d *Mat2d_mulk_add( Mat2d *dest, Mat2d *m1, Mat2d *m2, float k ) {
	dest[0] = m1[0] + (m2[0] * k);
	dest[1] = m1[1] + (m2[1] * k);
	dest[2] = m1[2] + (m2[2] * k);
	dest[3] = m1[3] + (m2[3] * k);
	dest[4] = m1[4] + (m2[4] * k);
	dest[5] = m1[5] + (m2[5] * k);
	return dest;
}

int    Mat2d_eq( Mat2d *m1, Mat2d *m2 ) {
	return m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2] && m1[3] == m2[3] && m1[4] == m2[4] && m1[5] == m2[5];
}

int    Mat2d_eqexact( Mat2d *m1, Mat2d *m2 ) {
	
}
