
# 头文件及源文件
file(
    GLOB PUBLIC_HEADERS 
    ../include/jlink-restful-cpp/*.h
)
file(
    GLOB SRC 
    *.h *.hpp *.cpp 
    .
)
list(APPEND SRC "${PUBLIC_HEADERS}")

# 编译目标
add_library(${PROJECT_NAME})

# 目标关联源文件
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    SOURCES "${SRC}"
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

# 目标宏定义
target_compile_definitions(
    ${PROJECT_NAME} PUBLIC  
    CURL_STATICLIB
)

# 目标头文件搜索路径
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    .
    ../include
    ../include/jlink-restful-cpp
    ../third/
    ../third/curl/include
    ../third/fmt/include
    ../third/openssl/include
)

# 目标依赖库搜索路径
target_link_directories(
    ${PROJECT_NAME} PUBLIC
    ../third/curl/lib
    ../third/fmt/lib
    ../third/openssl/lib
)

# 目标依赖库
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    $<$<PLATFORM_ID:Windows>:fmt_static>
    $<$<PLATFORM_ID:Windows>:libcurl_static>
    $<$<PLATFORM_ID:Windows>:ws2_32>
    $<$<PLATFORM_ID:Windows>:Crypt32>
    $<$<PLATFORM_ID:Windows>:wldap32>
    $<$<PLATFORM_ID:Windows>:libcrypto_static>
    $<$<PLATFORM_ID:Windows>:libssl_static>
)
