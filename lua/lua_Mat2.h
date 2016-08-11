#include "Mat2.h"

#define MAT2MT "__MAT2MT__"
#define GETMAT2(i) (CGLM_TYPE *)(luaL_checkudata(L,(i),MAT2MT))

static int lua_Mat2_newindex( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(-3);
	int index = luaL_checkint( L, -2 ) - 1;
	luaL_argcheck( L, 0 <= index && index <= 3, -2, "index out of range" );
	self[index] = luaL_checknumber( L, -1 );
	return 0;
}

static int lua_Mat2_index( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(-2);
	int index = luaL_checkint( L, -1 ) - 1;
	luaL_argcheck( L, 0 <= index && index <= 3, -1, "index out of range" );
	lua_pushnumber( L, self[index] );
	return 1;
}

static int lua_Mat2_len( lua_State *L ) {
	lua_pushnumber( L, 4 );
	return 1;
}

static int lua_Mat2_eq( lua_State *L ) {
	lua_pushboolean( L, Mat2_eq( GETMAT2(-2), GETMAT2(-1)));
	return 1;
}

static int lua_Mat2_tostring( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(-1);
	CGLM_LUA_TOSTRING(L,self,"Mat2",4);
	return 1; 
}

static const struct luaL_Reg lMat2mt[] = {
	{"__newindex",lua_Mat2_newindex},
	{"__index",lua_Mat2_index},
	{"__len",lua_Mat2_len},
	{"__eq",lua_Mat2_eq},
	{"__tostring",lua_Mat2_tostring},
	{NULL,NULL},
};

static int lua_Mat2_new( lua_State *L ) {
	CGLM_TYPE *dest = Mat2_alloc();
	Mat2_identity( dest );
	luaL_getmetatable(L,MAT2MT);
	lua_setmetatable(L,-2);
	return 1;
}

static int lua_Mat2_identity( lua_State *L ) {
	Mat2_identity( GETMAT2(-1));
	return 0;
}

static int lua_Mat2_set( lua_State *L ) {
	Mat2_set( GETMAT2(-5), luaL_checknumber(L,-4), luaL_checknumber(L,-3), luaL_checknumber(L,-2), luaL_checknumber(L,-1));
	return 0;
}

static int lua_Mat2_copy( lua_State *L ) {
	Mat2_copy( GETMAT2(-2), GETMAT2(-1));
	return 0;
}

static int lua_Mat2_setrot( lua_State *L ) {
	Mat2_setrot( GETMAT2(-2), luaL_checknumber(L,-1));
	return 0;
}

static int lua_Mat2_setscl( lua_State *L ) {
	Mat2_setscl( GETMAT2(-3), luaL_checknumber(L,-2), luaL_checknumber(L,-1));
	return 0;
}

static int lua_Mat2_det( lua_State *L ) {
	lua_pushnumber( L, Mat2_det( GETMAT2(-1)));
	return 1;	
}

static int lua_Mat2_frob( lua_State *L ) {
	lua_pushnumber( L, Mat2_frob( GETMAT2(-1)));
	return 1;	
}

static int lua_Mat2_add( lua_State *L ) {
	Mat2_add( GETMAT2(-3), GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_sub( lua_State *L ) {
	Mat2_sub( GETMAT2(-3), GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_mul( lua_State *L ) {
	Mat2_mul( GETMAT2(-3), GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_mulk( lua_State *L ) {
	Mat2_mulk( GETMAT2(-3), GETMAT2(-2), luaL_checknumber(L,-1));
	return 0;	
}

static int lua_Mat2_addmulk( lua_State *L ) {
	Mat2_addmulk( GETMAT2(-4), GETMAT2(-3), GETMAT2(-2), luaL_checknumber(L,-1));
	return 0;	
}

static int lua_Mat2_transpose( lua_State *L ) {
	Mat2_transpose( GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_adjoint( lua_State *L ) {
	Mat2_adjoint( GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_invert( lua_State *L ) {
	Mat2_invert( GETMAT2(-2), GETMAT2(-1));
	return 0;	
}

static int lua_Mat2_rot( lua_State *L ) { 
	Mat2_rot( GETMAT2(-3), GETMAT2(-2), luaL_checknumber(L,-1)); 
	return 0; 
}

static int lua_Mat2_scl( lua_State *L ) {
	Mat2_scl( GETMAT2(-4), GETMAT2(-3), luaL_checknumber(L,-2), luaL_checknumber(L,-1)); 
	return 0;
}

static const luaL_Reg lMat2lib[] = {
	{"new", lua_Mat2_new},
	{"set", lua_Mat2_set},
	{"copy", lua_Mat2_copy},
	{"setrot", lua_Mat2_setrot},
	{"setscl", lua_Mat2_setscl},
	{"identity", lua_Mat2_identity},
	{"det", lua_Mat2_det},
	{"frob", lua_Mat2_frob},
	{"add", lua_Mat2_add},
	{"sub", lua_Mat2_sub},
	{"mul", lua_Mat2_mul},
	{"mulk", lua_Mat2_mulk},
	{"addmulk", lua_Mat2_addmulk},
	{"rot", lua_Mat2_rot},
	{"scl", lua_Mat2_scl},
	{"transpose", lua_Mat2_transpose},
	{"adjoint", lua_Mat2_adjoint},
	{"invert", lua_Mat2_invert},
	{NULL,NULL},
};

static void register_Mat2( lua_State *L ) {
	lua_newtable( L );
	luaL_newmetatable( L, MAT2MT );
	luaL_setfuncs( L, lMat2mt, 0 );
	lua_newtable( L );
	luaL_setfuncs( L, lMat2lib, 0 );
	lua_setfield( L, -2, "Mat2" );	
}
