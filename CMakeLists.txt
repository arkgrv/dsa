cmake_minimum_required(VERSION 3.3)
project(dsa CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Z7")
    set(CMAKE_CXX_FLAGS_RELEASE "/Os")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-Os -fpic")
endif()

# Include directories
include_directories(dsa/include)

set(LIBRARY dsa)
set(RUNNABLE dsa-example)

# Sources for library
set(LIBRARY_SRC
    "dsa/src/sorting/bubble_sort.cpp"
    "dsa/src/sorting/insertion_sort.cpp"
    "dsa/src/sorting/selection_sort.cpp"
    "dsa/src/sorting/quick_sort.cpp"
    "dsa/src/sorting/merge_sort.cpp"
    "dsa/src/sorting/shell_sort.cpp"
    "dsa/src/sorting/heap_sort.cpp"
    "dsa/src/sorting/comb_sort.cpp"
    "dsa/src/sorting/counting_sort.cpp"
    "dsa/src/sorting/bucket_sort.cpp"
    "dsa/src/sorting/radix_sort.cpp"
)

# Sources for executable
set(RUNNABLE_SRC "dsa/src/main.cpp")

# Adding library and executable
add_library(${LIBRARY} STATIC ${LIBRARY_SRC})
add_executable(${RUNNABLE} ${RUNNABLE_SRC})

# Linking
target_link_libraries(${RUNNABLE} PUBLIC ${LIBRARY})