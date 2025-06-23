cmake_minimum_required(VERSION 3.10)

project(base)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} base_SRCS)

file(GLOB_RECURSE base_HEADERS "${PROJECT_SOURCE_DIR}/include/base/*.h")

# 创建库并设置属性
add_library(mymuduo_base STATIC ${base_SRCS})
target_link_libraries(mymuduo_base pthread rt)
target_include_directories(mymuduo_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

# 安装
install(TARGETS mymuduo_base DESTINATION lib)
install(FILES ${base_HEADERS} DESTINATION include/mymuduo/base)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    # 这里将在后续课程中添加示例程序
endif() 