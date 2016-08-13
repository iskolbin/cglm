#ifndef CGLM_TYPES_H_
#define CGLM_TYPES_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CGLM_VERSION "CGLM 1.0.0"
#define CGLM_VERSION_NUM 100000

#ifndef CGLM_TYPE
#define CGLM_TYPE float
#endif

#ifndef CGLM_ALLOC
#define CGLM_ALLOC(n) malloc((n))
#endif

#ifndef CGLM_DEFAULT_EPSILON
#define CGLM_DEFAULT_EPSILON 0.00001
#endif

#ifndef CGLM_EQUAL
#define CGLM_EQUAL(a,b,eps) fabs((a)-(b))<=(eps) 
#endif

#define CGLM_EQ(i,name1,name2,eps) CGLM_EQUAL((name1)[(i)],(name2)[(i)],(eps))

#ifndef CGLM_ROUND
#define CGLM_ROUND(a) floor((a)+0.5)
#endif

#ifndef CGLM_UNIFORM
#define CGLM_UNIFORM(a) ((a)*((CGLM_TYPE)rand()/(CGLM_TYPE)(RAND_MAX)))
#endif 

#ifndef CGLM_MIN
#define CGLM_MIN(a,b) ((a)>(b)?(b):(a))
#endif

#ifndef CGLM_MAX
#define CGLM_MAX(a,b) ((a)<(b)?(b):(a))
#endif

typedef CGLM_TYPE Vec2[2];
typedef CGLM_TYPE Vec3[3];
typedef CGLM_TYPE Vec4[4];
typedef CGLM_TYPE Vec6[6];
typedef CGLM_TYPE Mat2[4];
typedef CGLM_TYPE Mat2d[6];
typedef CGLM_TYPE Mat3[9];
typedef CGLM_TYPE Mat4[16];

#endif
