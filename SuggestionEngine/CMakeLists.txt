cmake_minimum_required(VERSION 3.14)
project(SuggestionEngine)

set(CMAKE_CXX_STANDARD 14)

set (SOURCE_FILES main.cpp statelessInput.txt wordAndPhrasesInput.txt queryInput.txt input.txt)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(SuggestionEngine ${SOURCE_FILES})

include(FindPkgConfig)
find_package(suggestLib REQUIRED)
include_directories(${SUGGESTLIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SUGGESTLIB_LIBRARY})
