#ifndef CGLM_VEC3_H_
#define CGLM_VEC3_H_

#include "global.h"

#define Vec3_alloc() CGLM_ALLOC(3*sizeof(CGLM_TYPE))
#define Vec3_unpack(src) (src)[0],(src)[1],(src)[2]
#define Vec3_print(src) printf("Vec3(%g %g %g)",(src)[0],(src)[1],(src)[2])

#define Vec3_copy(dest,src) Vec3_set((dest),(src)[0],(src)[1],(src)[2])
#define Vec3_set(dest,a,b,c) do{CGLM_TYPE a0=(a),a1=(b),a2=(c);(dest)[0]=a0;(dest)[1]=a1;(dest)[2]=a2;}while(0)
#define Vec3_unsafeset(dest,a,b,c) do{(dest)[0]=(a);(dest)[1]=(b);(dest)[2]=(c);}while(0) 

#define Vec3_add(dest,v1,v2) Vec3_unsafeset((dest),(v1)[0]+(v2)[0],(v1)[1]+(v2)[1],(v1)[2]+(v2)[2])
#define Vec3_sub(dest,v1,v2) Vec3_unsafeset((dest),(v1)[0]-(v2)[0],(v1)[1]-(v2)[1],(v1)[2]-(v2)[2])
#define Vec3_mul(dest,v1,v2) Vec3_unsafeset((dest),(v1)[0]*(v2)[0],(v1)[1]*(v2)[1],(v1)[2]*(v2)[2])
#define Vec3_div(dest,v1,v2) Vec3_unsafeset((dest),(v1)[0]/(v2)[0],(v1)[1]/(v2)[1],(v1)[2]/(v2)[2])
#define Vec3_mulk(dest,src,k) Vec3_unsafeset((dest),(v1)[0]*(k),(v2)[1]*(k),(v1)[2]*(k))
#define Vec3_addmulk(dest,v1,v2,k) Vec3_unsafeset((dest),(v1)[0]+((v2)[0]*(k)),(v1)[1]+((v2)[1]*(k)),(v1)[2]+((v2)[2]*(k)))
#define Vec3_neg(dest,src) Vec3_unsafeset((dest),-(src)[0],-(src)[1],-(src)[2])

#define Vec3_min(dest,v1,v2) Vec2_unsafeset((dest),CGLM_MIN(0,(v1),(v2)),CGLM_MIN(1,(v1),(v2)),CGLM_MIN(2,(v1),(v2)))
#define Vec3_max(dest,v1,v2) Vec2_unsafeset((dest),CGLM_MAX(0,(v1),(v2)),CGLM_MAX(1,(v1),(v2)),CGLM_MAX(2,(v1),(v2)))

#define Vec3_sqrdist(v1,v2) (((v1)[0]-(v2)[0])*((v1)[0]-v2[0]) + ((v1)[1]-(v2)[1])*((v1)[1]-(v2)[1]) + ((v1)[2]-(v2)[2])*((v1)[2]-(v2)[2]))
#define Vec3_dist(v1,v2) sqrt(Vec3_sqrdist((v1),(v2)))
#define Vec3_sqrlen(src) ((src)[0]*(src)[0] + (src)[1]*(src)[1] + (src)[2]*(src)[2])
#define Vec3_len(src) sqrt(Vec3_sqrlen((src)))

#define Vec3_floor(dest,src) Vec3_unsafeset((dest),floor((src)[0]),floor((src)[1]),floor((src)[2]))
#define Vec3_ceil(dest,src) Vec3_unsafeset((dest),ceil((src)[0]),ceil((src)[1]),ceil((src)[2]))
#define Vec3_round(dest,src) Vec3_unsafeset((dest),CGLM_ROUND((src)[0]),CGLM_ROUND((src)[1]),CGLM_ROUND((src)[2]))

#define Vec3_dot(v1,v2) ((v1)[0]*v2[0] + (v1)[1]*(v2)[1] + (v1)[2]*(v2)[2])
#define Vec3_cross(dest,v1,v2) Vec3_set((dest),(v1)[1]*(v2)[2] - (v1)[2]*(v2)[1], (v1)[2]*(v2)[0] - (v1)[0]*(v2)[2], (v1)[0]*(v2)[1] - (v1)[1]*(v2)[0])

#define Vec3_lerp(dest,v1,v2,t) Vec3_unsafeset((dest),(v1)[0]+(t)*((v2)[0]-(v1)[0]),(v1)[1]+(t)*((v2)[1]-(v1)[1]),(v1)[2]+(t)*((v2)[2]-(v1)[2]))
#define Vec3_inv(dest,src) Vec3_unsafeset((dest),1/(src)[0],1/(src)[1],1/(src)[2])
#define Vec3_norm(dest,src) do{CGLM_TYPE len = Vec3_len((src)); if (len>0) { len = 1/len; Vec3_unsafeset((dest),(src)[0]*len,(src)[1]*len,(src)[2]*len); }}while(0)

#define Vec3_eqeps(v1,v2,eps) (CGLM_EQ(0,(v1),(v2),(eps)) && CGLM_EQ(1,(v1),(v2),(eps)) && CGLM_EQ(2,(v1),(v2),(eps)))
#define Vec3_eq(v1,v2) Vec3_eqeps((v1),(v2),CGLM_DEFAULT_EPSILON)
#define Vec3_eqexact(v1,v2) ((v1)[0]==(v2)[0]&&(v1)[1]==(v2)[1]&&(v1)[2]==(v2)[2])


#endif
