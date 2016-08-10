package = 'CGLM'
version = '1.0-0'
source = {
	url = 'git://github.com/iskolbin/cglm',
	tag = 'v1.0',
}
description = {
	summary = 'C GL Math',
	detailed = [[]],
	homepage = 'https://github.com/iskolbin/cglm',
	license = 'MIT/X11',
}
dependencies = {
	'lua >= 5.1'
}
build = {
	type = 'builtin',
	modules = {
		cglm = {
			sources = {
				'./lua/lua_Mat2.c',
			},
			incdirs = {
				'./inc',
			}
		}
	}
}
