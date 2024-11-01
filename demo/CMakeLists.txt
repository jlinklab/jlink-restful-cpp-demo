project(jlink-cpp-demo)

if (MSVC)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:utf-8>")
endif()

aux_source_directory(./Public SRC_Public)
aux_source_directory(./Source SRC_Source)

# 编译目标
add_executable(${PROJECT_NAME} 
	main.cpp
	demo.h
	mqttmessage.h
	tools.cpp
	tools.h
	${SRC_Public}
	${SRC_Source}
)

# 目标头文件搜索路径
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    .
    ../include
    ../include/jlink-restful-cpp
	./Public
)

# 目标依赖库
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    jlink-restful-cpp
)
