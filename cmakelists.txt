cmake_minimum_required(VERSION 3.10)
project(MultiSort)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

file(GLOB SOURCES "src/*.cpp")

add_executable(MultiSort ${SOURCES})

target_link_libraries(MultiSort PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)

# 包含头文件
include_directories(${CMAKE_SOURCE_DIR}/include)
