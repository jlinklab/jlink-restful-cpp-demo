project(jlink-cpp-demo)

# 编译目标
add_executable(${PROJECT_NAME} main.cpp tools.cpp tools.h mqttmessage.h)

# 目标头文件搜索路径
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    .
    ../include
    ../include/jlink-restful-cpp
)

# 目标依赖库
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    jlink-restful-cpp
)
