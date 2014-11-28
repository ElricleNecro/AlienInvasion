set(CMAKE_INCLUDE_CURRENT_DIR ON)

#############
# Répertoire à inclure :
########################
include_directories(../include/ )

####################
# Liste des fichiers sources :
##############################
file(
	GLOB
	verif_files
	main.cpp
)

add_subdirectory(galaxy)

############
# Exécutable à construire :
###########################
add_library(
	galaxy_gen_a
	STATIC
	galaxy/generator.cpp
	galaxy/uniformsphere.cpp
)
add_library(
	galaxy_gen
	SHARED
	galaxy/generator.cpp
	galaxy/uniformsphere.cpp
)

add_executable(
	${EXEC_NAME}
	${verif_files}
)

target_link_libraries(
	${EXEC_NAME}
	galaxy_gen
)

install(TARGETS ${EXEC_NAME} DESTINATION bin)
install(TARGETS galaxy_gen DESTINATION lib)
