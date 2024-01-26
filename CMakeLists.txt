cmake_minimum_required(VERSION 3.10)
project(Zeta)

# C++ standard to C++17 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(include)

# Source Files 
file(GLOB ZETA_SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${ZETA_SOURCES})

# If you are using a specific library for REST API (e.g., CppRestSDK)
# find_package(cpprestsdk REQUIRED)
# target_link_libraries(ZetaMac PRIVATE cpprestsdk::cpprest)

# Additional libraries and configurations can be added here
