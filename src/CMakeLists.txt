
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
    ../third/mqtt/include

)

# 目标依赖库搜索路径
if (MSVC)
    target_link_directories(
        ${PROJECT_NAME} PUBLIC
        ../third/curl/lib/windows
        ../third/fmt/lib/windows
        ../third/openssl/lib/windows
        ../third/mqtt/lib/windows
    )
else()
    target_link_directories(
        ${PROJECT_NAME} PUBLIC
        ../third/curl/lib/linux
        ../third/fmt/lib/linux
        ../third/openssl/lib/linux
        ../third/mqtt/lib/linux
    )
endif()

# 目标依赖库
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    $<$<PLATFORM_ID:Linux>:curl>
    $<$<PLATFORM_ID:Linux>:fmt>
    $<$<PLATFORM_ID:Linux>:paho-mqtt3cs>
    $<$<PLATFORM_ID:Linux>:crypto>
    $<$<PLATFORM_ID:Linux>:ssl>
    $<$<PLATFORM_ID:Linux>:crypto>
    $<$<PLATFORM_ID:Linux>:dl>
    $<$<PLATFORM_ID:Linux>:pthread>
    $<$<PLATFORM_ID:Linux>:z>
    $<$<PLATFORM_ID:Windows>:paho-mqtt3cs-static>
    $<$<PLATFORM_ID:Windows>:fmt_static>
    $<$<PLATFORM_ID:Windows>:libcurl_static>
    $<$<PLATFORM_ID:Windows>:ws2_32>
    $<$<PLATFORM_ID:Windows>:Crypt32>
    $<$<PLATFORM_ID:Windows>:wldap32>
    $<$<PLATFORM_ID:Windows>:libcrypto_static>
    $<$<PLATFORM_ID:Windows>:libssl_static>
)
