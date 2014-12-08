#ifndef DEFINE_H
#define DEFINE_H

#ifndef NULL
#	if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
#		define NULL nullptr
#	else
#		define NULL 0x0
#	endif
#endif

#define PLUGIN_API_VERSION_MAJOR @PLUGIN_API_VERSION_MAJOR@
#define PLUGIN_API_VERSION_MINOR @PLUGIN_API_VERSION_MINOR@

#define AI_VERSION_MAJOR @AI_VERSION_MAJOR@
#define AI_VERSION_MINOR @AI_VERSION_MINOR@

#define INSTALL_DIR "@CMAKE_INSTALL_PREFIX@"

#define F_TYPE @F_TYPE@
#define I_TYPE @I_TYPE@

#endif /* end of include guard */
//vim:ft=cpp
