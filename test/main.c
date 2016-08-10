#include "Mat2.h"
int main(void) {
	CGLM_TYPE *a = Mat2_alloc();
	CGLM_TYPE *b = Mat2_alloc();
	Mat2_identity(a);
	Mat2_set(b,2,0,0,2);
	Mat2_print(a);
	Mat2_mul(a,a,b);
	Mat2_print(a);
	Mat2_invert(b,b);
	Mat2_print(b);
	return 0;
}
