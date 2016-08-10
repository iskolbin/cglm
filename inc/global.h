#ifndef CGLM_TYPES_H_
#define CGLM_TYPES_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef CGLM_TYPE
#define CGLM_TYPE float
#endif

#ifndef CGLM_ALLOC
#define CGLM_ALLOC(n) malloc((n)*sizeof(CGLM_TYPE))
#endif

#ifndef CGLM_DEFAULT_EPSILON
#define CGLM_DEFAULT_EPSILON 0.00001
#endif

typedef CGLM_TYPE Vec2[2];
typedef CGLM_TYPE Vec3[3];
typedef CGLM_TYPE Vec4[4];
typedef CGLM_TYPE Mat2[4];
typedef CGLM_TYPE Mat2d[6];
typedef CGLM_TYPE Mat3[9];
typedef CGLM_TYPE Mat4[16];

#endif
