set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(
	GLOB
	galaxy_gen_files
	generator.cpp
	uniformsphere.cpp
)

add_library(
	galaxy_gen_obj
	OBJECT
	${galaxy_gen_files}
)
