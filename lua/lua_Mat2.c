#define LUA_LIB
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define CGLM_ALLOC(size) lua_newuserdata(L,(size))
#include "Mat2.h"

#define MAT2MT "__MAT2MT__"

#define GETMAT2(i) (CGLM_TYPE *)(luaL_checkudata(L,(i),MAT2MT))

#if (LUA_VERSION_NUM<=501)
#define lua_len(L,i) (lua_pushnumber( (L), lua_objlen( (L), (i) )))
#define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
//static void luaL_setfuncs (lua_State *L, const luaL_Reg *l, int nup) {
//	luaL_checkstack(L, nup, "too many upvalues");
//	for (; l->name != NULL; l++) {  /* fill the table with given functions */
//		int i;
//		for (i = 0; i < nup; i++)  /* copy upvalues to the top */
//			lua_pushvalue(L, -nup);
//		lua_pushcclosure(L, l->func, nup);  /* closure with those upvalues */
//		lua_setfield(L, -(nup + 2), l->name);
//	}
//	lua_pop(L, nup);  /* remove upvalues */
//}*/
#endif

#ifdef _WIN32
__declspec (dllexport)
#endif
int luaopen_cglm( lua_State *L );

static int lua_Mat2_newindex( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(1);
	int index = luaL_checkint(L,2) - 1;
	luaL_argcheck( L, 1 <= index && index <= 4, 2, "index out of range" );
	self[index] = luaL_checknumber( L, 3 );
	return 0;
}

static int lua_Mat2_index( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(1);
	int index = luaL_checkint( L, 2 ) - 1;
	luaL_argcheck( L, 1 <= index && index <= 4, 2, "index out of range" );
	lua_pushnumber( L, self[index] );
	return 1;
}

static int lua_Mat2_len( lua_State *L ) {
	lua_pushnumber( L, 4 );
	return 1;
}

static int lua_Mat2_eq( lua_State *L ) {
	lua_pushboolean( L, Mat2_eq( GETMAT2(1), GETMAT2(2)));
	return 1;
}

static int lua_Mat2_tostring( lua_State *L ) {
	CGLM_TYPE *self = GETMAT2(1);
	luaL_Buffer b;
	luaL_buffinit( L, &b );
	luaL_addstring( &b, "Mat2(" );
	lua_pushnumber( L, self[0] );
	luaL_addvalue( &b );
	lua_pushnumber( L, self[1] );
	luaL_addvalue( &b );
	lua_pushnumber( L, self[2] );
	luaL_addvalue( &b );
	lua_pushnumber( L, self[3] );
	luaL_addvalue( &b );
	luaL_addstring( &b, ")" );
	luaL_pushresult( &b );
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

static int lua_Mat2_create( lua_State *L ) {
	CGLM_TYPE *dest = Mat2_alloc();
	Mat2_identity( dest );
	luaL_getmetatable(L,MAT2MT);
	lua_setmetatable(L,-2);
	return 1;
}

static int lua_Mat2_identity( lua_State *L ) {
	Mat2_identity( GETMAT2(1));
	return 0;
}

static int lua_Mat2_set( lua_State *L ) {
	Mat2_set( GETMAT2(1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
	return 0;
}

static int lua_Mat2_copy( lua_State *L ) {
	Mat2_copy( GETMAT2(1), GETMAT2(2));
	return 0;
}

static int lua_Mat2_setrot( lua_State *L ) {
	Mat2_setrot( GETMAT2(1), luaL_checknumber(L,2));
	return 0;
}

static int lua_Mat2_setscl( lua_State *L ) {
	Mat2_setscl( GETMAT2(1), luaL_checknumber(L,2), luaL_checknumber(L,3));
	return 0;
}

static int lua_Mat2_det( lua_State *L ) {
	lua_pushnumber( L, Mat2_det( GETMAT2(1)));
	return 1;	
}

static int lua_Mat2_frob( lua_State *L ) {
	lua_pushnumber( L, Mat2_frob( GETMAT2(1)));
	return 1;	
}

static int lua_Mat2_add( lua_State *L ) {
	Mat2_add( GETMAT2(1), GETMAT2(2), GETMAT2(3));
	return 0;	
}

static int lua_Mat2_sub( lua_State *L ) {
	Mat2_sub( GETMAT2(1), GETMAT2(2), GETMAT2(3));
	return 0;	
}

static int lua_Mat2_mul( lua_State *L ) {
	Mat2_mul( GETMAT2(1), GETMAT2(2), GETMAT2(3));
	return 0;	
}

static int lua_Mat2_mulk( lua_State *L ) {
	Mat2_mulk( GETMAT2(1), GETMAT2(2), luaL_checknumber(L,3));
	return 0;	
}

static int lua_Mat2_addmulk( lua_State *L ) {
	Mat2_addmulk( GETMAT2(1), GETMAT2(2), GETMAT2(3), luaL_checknumber(L,4));
	return 0;	
}

static int lua_Mat2_transpose( lua_State *L ) {
	Mat2_transpose( GETMAT2(1), GETMAT2(2));
	return 0;	
}

static int lua_Mat2_adjoint( lua_State *L ) {
	Mat2_adjoint( GETMAT2(1), GETMAT2(2));
	return 0;	
}

static int lua_Mat2_invert( lua_State *L ) {
	Mat2_invert( GETMAT2(1), GETMAT2(2));
	return 0;	
}

static const luaL_Reg lMat2lib[] = {
	{"create", lua_Mat2_create},
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
	{"transpose", lua_Mat2_transpose},
	{"adjoint", lua_Mat2_adjoint},
	{"invert", lua_Mat2_invert},
};

#ifdef _WIN32
__declspec (dllexport)
#endif
int luaopen_cglm( lua_State *L ) {
	printf(">>>>1");
	luaL_newmetatable( L, MAT2MT );
	//luaL_setfuncs( L, lMat2mt, 0 );
	printf(">>>>2");
	luaL_newlib( L, lMat2lib );
	printf(">>>>3");
	return 1;
}
