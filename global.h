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

typedef CGLM_TYPE[2]  Vec2;
typedef CGLM_TYPE[3]  Vec3;
typedef CGLM_TYPE[4]  Vec4;
typedef CGLM_TYPE[4]  Mat2;
typedef CGLM_TYPE[6]  Mat2d;
typedef CGLM_TYPE[9]  Mat3;
typedef CGLM_TYPE[16] Mat4;

#endif
