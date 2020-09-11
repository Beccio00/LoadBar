cmake_minimum_required(VERSION 3.17)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
set(SOURCE_FILES runAllTest.cpp TestFile.cpp TestLoadFiles.cpp TestWindow.cpp)
add_executable(runAllTest ${SOURCE_FILES} )
target_link_libraries(runAllTest ${GTEST_BOTH_LIBRARIES} core pthread)

