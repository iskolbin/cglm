CGLM
====

C-macros GL vector-matrix library. Greatly inspired by [gl-matrix](https://github.com/toji/gl-matrix).

Vec2
----


Vec3
----


Vec4
----


Vec6
----


Mat2
----
`Mat2_alloc()`

`Mat2_unpack( Mat2 a )`

`Mat2_print( Mat2 a )`

`Mat2_unsafeset( Mat2 a, float a00, float a01, float a10, float a11 )`

`Mat2_set( Mat2 a, float a00, float a01, float a10, float a11 )`

`Mat2_copy( Mat2 dest, Mat2 a )`

`Mat2_setrot( Mat2 dest, float s, float c )`

`Mat2_setrotv2( Mat2 dest, float rot )`

`Mat2_setrotrad( Mat2 dest, float rad )`

`Mat2_setscl( Mat2 dest, float sclx, float scly )`

`Mat2_setsclv2( Mat2 dest, Vec2 scl )`

`Mat2_identity( Mat2 dest )`

`Mat2_det( Mat2 a )`

`Mat2_frob( Mat2 a )`

`Mat2_add( Mat2 dest, Mat2 a, Mat2 b )`

`Mat2_sub( Mat2 dest, Mat2 a, Mat2 b)`

`Mat2_mul( Mat2 dest, Mat2 a, Mat2 b)`

`Mat2_mulk( Mat2 dest, Mat2 a, float k )`

`Mat2_addmulk( Mat2 dest,a, Mat2 b, float k )`

`Mat2_rot( Mat2 dest, float s, float c )`

`Mat2_rotv2( Mat2 dest, Vec2 rot )`

`Mat2_rotrad( Mat2 dest, float rad )`

`Mat2_scl( Mat2 dest, Mat2 a, float sclx, float scly )`

`Mat2_sclv2( Mat2 dest, Mat2 a, Vec2 scl )`

`Mat2_sclx( Mat2 dest, Mat2 a, float scl )`

`Mat2_scly( Mat2 dest, Mat2 a, float scl )`

`Mat2_transpose( Mat2 dest, Mat2 a )`

`Mat2_invert( Mat2 dest, Mat2 a )`

`Mat2_adjoint( Mat2 dest, Mat2 a )`

`Mat2_eqeps( Mat2 a, Mat2 b, float eps)`

`Mat2_eq( Mat2 a, Mat2 b )`

`Mat2_eqexact( Mat2 a, Mat2 b )`

Mat3
----

Mat4
----

Quat
----

Mat2d
-----

