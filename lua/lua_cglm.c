#define LUA_LIB

#include "lua_global.h"
#include "lua_Mat2.h"

CGLMEXPORT int luaopen_cglm( lua_State *L );

static const luaL_Reg lcglmlib[] = {
	{NULL,NULL},
};

CGLMEXPORT int luaopen_cglm( lua_State *L ) {
	luaL_newlib( L, lcglmlib );
	register_Mat2( L );
	lua_pushnumber( L, sizeof( CGLM_TYPE )); 
	lua_setfield( L, -2, "value_size" );
	lua_pushstring( L, CGLM_VERSION );
	lua_setfield( L, -2, "version" );
	lua_pushnumber( L, CGLM_VERSION_NUM );
	lua_setfield( L, -2, "version_num" );
	return 1;
}
