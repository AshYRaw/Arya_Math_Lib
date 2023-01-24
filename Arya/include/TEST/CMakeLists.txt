set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/MatrixX.h")
set(SUBDIRECTORIES "")
set(RELATIVE_PATH "include/TEST")

#Add all subdirectories
foreach(VAR ${SUBDIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	#Add source files to target
	target_sources("${PROJECT_NAME}" PUBLIC ${FILES})

	#Install our source files
	install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif()
