#include "Mat2d.h"

Mat2d *Mat2d_set( Mat2d *dest, float a, float b, float c, float d, float tx, float ty ) {
	dest[0] = a; dest[1] = b; dest[2] = c; dest[3] = d; dest[4] = tx; dest[5] = ty;
	return dest;
}

Mat2d *Mat2d_transform( Mat2d *dest, Mat2d *src, float a, float b, float c, float d ) {
	return dest;		
}

Mat2d *Mat2d_translate( Mat2d *dest, Mat2d *src, float x, float y ) {
	dest[0] = src[0]; dest[1] = src[1]; dest[2] = src[2]; dest[3] = src[3];
	
	return dest;
}

Mat2d *Mat2d_inv( Mat2d *dest, Mat2d *src ) {
	return dest;
}

Mat2d *Mat2d_fromrot( Mat2d *dest, float rad ) {
	
	return dest;
}

Mat2d *Mat2d_fromscl( Mat2d *dest, float sclx, float scly ) {
	return dest;
}

Mat2d *Mat2d_fromtransl( Mat2d *dest, float x, float y ) {
	return dest;
}

float *Mat2d_frob( Mat2d *src ) {
	return 0.0f;
}

Mat2d *Mat2d_add( Mat2d *dest, Mat2 *m1, Mat2 *m2 ) {
	return dest;
}

Mat2d *Mat2d_sub( Mat2d *dest, Mat2 *m1, Mat2 *m2 ) {
	return dest;
}

Mat2d *Mat2d_mul( Mat2d *dest, Mat2d *m1, Mat2d *m2 ) {
	return dest;
}

Mat2d *Mat2d_mulk( Mat2d *dest, Mat2d *src, float k ) {
	return dest;
}

Mat2d *Mat2d_mulk_add( Mat2d *dest, Mat2d *m1, Mat2d *m2, float k ) {
	return dest;
}

void Mat2d_fprintf( FILE *fout, Mat2d *src, const char *format ) {
	
}
