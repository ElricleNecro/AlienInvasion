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

add_subdirectory(profile)

############
# Exécutable à construire :
###########################
add_library(
	profile_gen_a
	STATIC
	profile/generator.cpp
	profile/uniformsphere.cpp
)
add_library(
	profile_gen
	SHARED
	profile/generator.cpp
	profile/uniformsphere.cpp
)

add_executable(
	${EXEC_NAME}
	${verif_files}
)

target_link_libraries(
	${EXEC_NAME}
	profile_gen
)

install(TARGETS ${EXEC_NAME} DESTINATION bin)
install(TARGETS profile_gen DESTINATION lib)
