#ifndef CGLM_VEC2_H_
#define CGLM_VEC2_H_

#include "global.h"
#include "Vec3.h"

#ifndef CGLM_DEFAULT_VEC2_FORMAT
#define CGLM_DEFAULT_VEC2_FORMAT "Vec2(%g,%g)\n"
#endif

#define Vec2_alloc() CGLM_ALLOC(2*sizeof(CGLM_TYPE))

#define Vec2_copy(dest,src) Vec2_set((dest),(src)[0],(src)[1])
#define Vec2_set(dest,a,b) do{CGLM_TYPE a0=(a),a1=(b);(dest)[0]=a0;(dest)[1]=a1;}while(0)
#define Vec2_unsafeset(dest,a,b) do{(dest)[0]=(a);(dest)[1]=(b);}while(0) 
#define Vec2_random(dest,len) do{CGLM_TYPE r = CGLM_UNIFORM((len)); Vec2_unsafeset((dest),cos(r),sin(r));}while(0)

#define Vec2_add(dest,v1,v2) Vec2_unsafeset((dest),(v1)[0]+(v2)[0],(v1)[1]+(v2)[1])
#define Vec2_sub(dest,v1,v2) Vec2_unsafeset((dest),(v1)[0]-(v2)[0],(v1)[1]-(v2)[1])
#define Vec2_mul(dest,v1,v2) Vec2_unsafeset((dest),(v1)[0]*(v2)[0],(v1)[1]*(v2)[1])
#define Vec2_mulk(dest,src,k) Vec2_unsafeset((dest),(v1)[0]*(k),(v2)[1]*(k))
#define Vec2_addmulk(dest,v1,v2,k) Vec2_unsafeset((dest),(v1)[0]+((v2)[0]*(k)),(v1)[1]+((v2)[1]*(k)))
#define Vec2_div(dest,v1,v2) Vec2_unsafeset((dest),(v1)[0]/(v2)[0],(v1)[1]/(v2)[1])
#define Vec2_neg(dest,src) Vec2_unsafeset((dest),-(src)[0],-(src)[1])

#define Vec2_min(dest,v1,v2) Vec2_unsafeset((dest),CGLM_MIN(0,(v1),(v2)),CGLM_MIN(1,(v1),(v2)))
#define Vec2_max(dest,v1,v2) Vec2_unsafeset((dest),CGLM_MAX(0,(v1),(v2)),CGLM_MAX(1,(v1),(v2)))

#define Vec2_sqrdist(v1,v2) (((v1)[0]-(v2)[0])*((v1)[0]-v2[0]) + ((v1)[1]-(v2)[1])*((v1)[1]-(v2)[1]))
#define Vec2_dist(v1,v2) sqrt(Vec2_sqrdist((v1),(v2)))
#define Vec2_sqrlen(src) ((src)[0]*(src)[0] + (src)[1]*(src)[1])
#define Vec2_len(src) sqrt(Vec2_sqrlen((src)))

#define Vec2_floor(dest,src) Vec2_unsafeset((dest),floor((src)[0]),floor((src)[1]))
#define Vec2_ceil(dest,src) Vec2_unsafeset((dest),ceil((src)[0]),ceil((src)[1]))
#define Vec2_round(dest,src) Vec2_unsafeset((dest),CGLM_ROUND((src)[0]),CGLM_ROUND((src)[1]))

#define Vec2_dot(v1,v2) ((v1)[0]*v2[0] + (v1)[1]*(v2)[1])
#define Vec2_cross(dest,v1,v2) Vec3_unsafeset((dest),0,0,(v1)[0]*(v2)[1]-(v1)[1]*(v2)[0])

#define Vec2_lerp(dest,v1,v2,t) Vec2_unsafeset((dest),(v1)[0]+(t)*((v2)[0]-(v1)[0]),(v1)[1]+(t)*((v2)[1]-(v1)[1]))
#define Vec2_inv(dest,src) Vec2_unsafeset((dest),1/(src)[0],1/(src)[1])
#define Vec2_norm(dest,src) do{CGLM_TYPE len = Vec2_len((src)); if (len>0) { len = 1/len; Vec2_unsafeset((dest),(src)[0]*len,(src)[1]*len); }}while(0)

#define Vec2_eqeps(v1,v2,eps) (CGLM_EQ(0,(v1),(v2),(eps)) && CGLM_EQ(1,(v1),(v2),(eps)))
#define Vec2_eq(v1,v2) Vec2_eqeps((v1),(v2),CGLM_DEFAULT_EPSILON)
#define Vec2_eqexact(v1,v2) ((v1)[0]==(v2)[0]&&(v1)[1]==(v2)[1])

#define Vec2_unpack(src) (src)[0],(src)[1]
#define Vec2_print(src) printf(CGLM_DEFAULT_VEC2_FORMAT,(src)[0],(src)[1])

#endif
