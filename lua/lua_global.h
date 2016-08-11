#ifndef CGLM_LUA_GLOBAL_H_
#define CGLM_LUA_GLOBAL_H_

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
#include "global.h"

#if (LUA_VERSION_NUM<=501)
#define lua_len(L,i) (lua_pushnumber( (L), lua_objlen( (L), (i) )))
#define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
static void luaL_setfuncs (lua_State *L, const luaL_Reg *l, int nup) {
	luaL_checkstack(L, nup, "too many upvalues");
	for (; l->name != NULL; l++) {  /* fill the table with given functions */
		int i;
		for (i = 0; i < nup; i++)  /* copy upvalues to the top */
			lua_pushvalue(L, -nup);
		lua_pushcclosure(L, l->func, nup);  /* closure with those upvalues */
		lua_setfield(L, -(nup + 2), l->name);
	}
	lua_pop(L, nup);  /* remove upvalues */
}
#endif

#ifdef _WIN32
#define CGLMEXPORT __declspec (dllexport)
#else
#define CGLMEXPORT
#endif

#define CGLM_LUA_TOSTRING(L,self,namestr,nitems) \
	do { \
		int i; \
		luaL_Buffer b; \
		luaL_buffinit( (L), &b ); \
		luaL_addstring( &b, (namestr)); \
		luaL_addstring( &b, "(" ); \
		for ( i = 0; i < (nitems)-1; i++ ) { \
			lua_pushnumber( L, (self)[i] ); \
			luaL_addvalue( &b ); \
			luaL_addstring( &b, ","); \
		} \
		lua_pushnumber( (L), (self)[(nitems)-1] ); \
		luaL_addvalue( &b ); \
		luaL_addstring( &b, ")"); \
		luaL_pushresult( &b ); \
	}while(0); 

#endif
