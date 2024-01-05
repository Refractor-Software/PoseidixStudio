CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

###############################################################################
# Macros
###############################################################################

MACRO(RPF_MODULE_LIST IN_MODULE_DIRECTORY)
	SET(LOC_DIRECTORY ${IN_MODULE_DIRECTORY})
	FILE(GLOB LOC_CHILDREN RELATIVE ${LOC_DIRECTORY} ${LOC_DIRECTORY}/*)
	SET(RPF_MODULE_ARRAY)
	FOREACH(LOOP_CHILD ${LOC_CHILDREN})
		IF(IS_DIRECTORY ${LOC_DIRECTORY}/${LOOP_CHILD})
			SET(RPF_MODULE_ARRAY ${RPF_MODULE_ARRAY};${LOOP_CHILD})
		ENDIF()
	ENDFOREACH()
ENDMACRO()

MACRO(RPF_ADD_MODULE IN_TARGET_LIB IN_TARGET IN_MODULE_NAME)
	# Because I suck at CMake and can't seem to get the individual modules
	# to "talk" to each other as separate libaries, we're just going to treat
	# them as plain include directories instead. This is probably more like what
	# other engines do anyway and is much easier to deal with.
	SET(LOC_PATH	Source/${IN_TARGET}/${IN_MODULE_NAME})

	# this janky chunk of commands is required to get modules to "talk" to each other
	# and to get the exported includes to work as well
	TARGET_INCLUDE_DIRECTORIES(
		${PROJECT_NAME}
		PUBLIC
		${LOC_PATH}/Include
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/${LOC_PATH}>
		$<INSTALL_INTERFACE:${IN_MODULE_NAME}>
	)
	# these are only visible to the engine itself so we don't need the interface stuff
	TARGET_INCLUDE_DIRECTORIES(
		${PROJECT_NAME}
		PRIVATE
		${LOC_PATH}/Private
	)
ENDMACRO()

MACRO(RPF_CREATE_TARGET IN_LIB_NAME IN_DIR_NAME IN_MANIFEST IN_SOURCE_DIR)
	RPF_MODULE_LIST(${IN_SOURCE_DIR})
	FOREACH(LOOP_MODULE ${RPF_MODULE_ARRAY})
		RPF_ADD_MODULE(${IN_LIB_NAME} ${IN_DIR_NAME} ${LOOP_MODULE})
	ENDFOREACH()
ENDMACRO()

###############################################################################
# Engine Project
###############################################################################

# Create the engine project
PROJECT(rpfEngine)

# Set the C++ standard to use
SET(CMAKE_CXX_STANDARD 20)

###############################################################################
# Variable Setup
###############################################################################

SET(RPF_ENGINE_SOURCE_DIR		${PROJECT_SOURCE_DIR}/Source)

SET(RPF_INCLUDE_DIR_NAME		Include)
SET(RPF_PRIVATE_DIR_NAME		Private)

###############################################################################
# Engine Library
###############################################################################

# This is super very not good practice but I'm not adding/removing
# files every single time we add a file during development. It's easier
# to use a keyboard shortcut to regenerate this instead.
FILE(GLOB_RECURSE HEADERS Source/*.hxx)
FILE(GLOB_RECURSE INLINES Source/*.inl)
FILE(GLOB_RECURSE SOURCES Source/*.cxx)

# Add the engine library which all targets link into
ADD_LIBRARY(${PROJECT_NAME} STATIC ${HEADERS} ${INLINES} ${SOURCES})

###############################################################################
# Runtime Target
###############################################################################

RPF_CREATE_TARGET(
	rpfEngineRuntime
	Runtime
	${RPF_ENGINE_SOURCE_DIR}/Runtime/RuntimeManifest.cxx
	${RPF_ENGINE_SOURCE_DIR}/Runtime
)

###############################################################################
# Editor Target
###############################################################################

RPF_CREATE_TARGET(
	rpfEngineEd
	Editor
	${RPF_ENGINE_SOURCE_DIR}/Editor/EditorManifest.cxx
	${RPF_ENGINE_SOURCE_DIR}/Editor
)