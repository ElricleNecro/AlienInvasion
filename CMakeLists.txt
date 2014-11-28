# Version minimum de CMake qui est nécessaire pour compiler :
cmake_minimum_required(VERSION 2.6)

#########
# Nom du projet :
#################
project(AlienInvasion)

set(PLUGIN_API_VERSION_MAJOR 0)
set(PLUGIN_API_VERSION_MINOR 0)

set(AI_VERSION_MAJOR 0)
set(AI_VERSION_MINOR 1)

set(F_TYPE double)

set(EXEC_NAME alien)

########################
# On a besoin de quelques fichiers non-standards :
##################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/.cmake/Modules/")

message(STATUS "Installation PREFIX: " ${CMAKE_INSTALL_PREFIX})

#################
# Quelques flags de compilation :
#################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wextra -Wall -Wc++11-compat -Wpedantic -Woverflow -Wmissing-declarations -Wuninitialized -Winline -Wfloat-equal -Wdiv-by-zero -Wdeprecated -Wdeprecated-declarations -Wcast-align -Wcast-qual -Wbuiltin-macro-redefined -ftrapv -ffinite-math-only")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O3")

IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
	# SET(CMAKE_BUILD_TYPE Release)
	SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

# The macro below forces the build directory to be different from source directory:
include(MacroOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")

add_subdirectory(src)

#########
# Configuration :
#################
configure_file(config.h.cmake ${CMAKE_SOURCE_DIR}/include/config.hpp)
# install(FILES share/verif/config.yaml DESTINATION share/verif/)

# vim: spelllang=
