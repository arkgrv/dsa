cmake_minimum_required(VERSION 3.3)
project(c-dsa C)

if(MSVC)
    set(CMAKE_C_FLAGS_DEBUG "/TC /Od /Z7")
    set(CMAKE_C_FLAGS_RELEASE "/TC /Os")
else()
    set(CMAKE_C_FLAGS_DEBUG "-Wall -O0 -g")
    set(CMAKE_C_FLAGS_RELEASE "-fpic -Os")
endif()

include_directories(dsa/include)

set(LIBRARY dsa)
set(RUNNABLE dsa-example)

# Library sources
set(LIBRARY_SRC
    "dsa/src/sorting/bubble_sort.c"
    "dsa/src/sorting/insertion_sort.c"
    "dsa/src/sorting/selection_sort.c"
    "dsa/src/sorting/quick_sort.c"
    "dsa/src/sorting/merge_sort.c"
    "dsa/src/sorting/shell_sort.c"
    "dsa/src/sorting/heap_sort.c"
    "dsa/src/sorting/comb_sort.c"
)

add_library(${LIBRARY} STATIC ${LIBRARY_SRC})
add_executable(${RUNNABLE} dsa/src/main.c)

# Linking
target_link_libraries(${RUNNABLE} PUBLIC ${LIBRARY})