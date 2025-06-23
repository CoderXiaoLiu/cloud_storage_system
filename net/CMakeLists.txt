cmake_minimum_required(VERSION 3.10)

project(net)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} net_SRCS)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/poller poller_SRCS)

list(APPEND net_SRCS ${poller_SRCS})

file(GLOB_RECURSE net_HEADERS "${PROJECT_SOURCE_DIR}/include/net/*.h")

add_library(mymuduo_net ${net_SRCS})
target_link_libraries(mymuduo_net mymuduo_base pthread rt)

# 设置包含目录
target_include_directories(mymuduo_net PUBLIC ${PROJECT_SOURCE_DIR})

# 安装
install(TARGETS mymuduo_net DESTINATION lib)
install(FILES ${net_HEADERS} DESTINATION include/mymuduo/net)

# add_subdirectory(http)
# add_subdirectory(inspect)
# add_subdirectory(poller)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    # 这里将在后续课程中添加示例程序
endif() 