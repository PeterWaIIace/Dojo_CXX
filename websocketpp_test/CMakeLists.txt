cmake_minimum_required(VERSION 3.2)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 20)  # or 14, 17, etc., depending on your needs
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Organise CMake scripts into a folder
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/")

project(Echo_client)

set(CMAKE_BUILD_TYPE DEBUG)

# Embed versioning from Git-Tag
find_package(Version.cmake)
find_package(asio REQUIRED)
find_package(websocketpp REQUIRED)
find_package(Threads REQUIRED)  # Add this line
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}>)

add_definitions(-D_WIN32_WINNT=0x0601)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-D_WINSOCKAPI_)

# Force include winsock2.h before any other includes
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FIwinsock2.h")

# Include OpenCV directories to ensure the compiler can find headers
add_executable(
    Echo_client
    echo_client.cpp
)

target_link_libraries(Echo_client PRIVATE ${websocketpp_LIBRARIES} asio Threads::Threads)
target_compile_definitions(Echo_client PRIVATE GENERATED_UUID=${GENERATED_UUID})