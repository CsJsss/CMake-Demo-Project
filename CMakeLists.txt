cmake_minimum_required(VERSION 3.10)

project(CMakeDemoProject LANGUAGES CXX)


##### 01-Basic ######

# cpp 版本
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# default build type : Debug
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 使得 include 和 src 之间能够平级 include
include_directories(${CMAKE_SOURCE_DIR})

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# 跨平台使用 Threads 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
######################


##### 02-第三方库 ######

# spdlog
add_subdirectory(thirdparty/spdlog)
include_directories(thirdparty/spdlog/include)

# gtest

add_subdirectory(thirdparty/googletest-release-1.12.1)
include_directories(thirdparty/googletest-release-1.12.1/googletest/include)
######################


##### 03-静态库 ######

# 查询所有在src中的 .h 和 .cpp文件
file(GLOB sources CMAKE_CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(PROJECT_LIB STATIC ${sources})
# 静态库链接所需的库
target_link_libraries(PROJECT_LIB PUBLIC Threads::Threads)
######################


##### 04-target ######

# 所有的 target 文件
file(GLOB targets CMAKE_CONFIGURE_DEPENDS targets/*.cpp)
foreach(file ${targets})
    # split string in CMake
    # Link: https://stackoverflow.com/questions/5272781/what-is-common-way-to-split-string-into-list-with-cmake
    string(REPLACE "." ";" name_list ${file})
    list(GET name_list 0 prefix)
    string(REPLACE "/" ";" path_list ${prefix})
    list(GET path_list -1 current_file)

    add_executable(${current_file} ${file})
    target_link_libraries(${current_file} PROJECT_LIB)
endforeach()
######################


##### 05-ctest Related #######

enable_testing()
## 添加 test 三部曲:
# 1. add_executable(name source_file)
# 2. target_link_libraries(name gtest gtest_main 被测试模块(libaray))
# 3. add_test()

# 所有的测试文件
file(GLOB test_files CMAKE_CONFIGURE_DEPENDS tests/*.cpp)
foreach(test_file ${test_files})
    string(REPLACE "." ";" name_list ${test_file})
    list(GET name_list 0 test_prefix)
    string(REPLACE "/" ";" path_list ${test_prefix})
    list(GET path_list -1 current_test)

    add_executable(${current_test} ${test_file} ${source})
    target_link_libraries(${current_test} gtest gtest_main PROJECT_LIB)
    add_test(NAME ${current_test} COMMAND ${current_test})    
endforeach()
######################