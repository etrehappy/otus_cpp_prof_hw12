cmake_minimum_required(VERSION 3.26)

project(MapReduce_prj)

set(BINARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
file(MAKE_DIRECTORY ${BINARY_OUTPUT_PATH})


add_executable(mapper 
    mapper.cpp
)
add_executable(reducer_mean 
    reducer_mean.cpp
)

add_executable(reducer_variance 
    reducer_variance.cpp
)

set_target_properties(mapper reducer_mean reducer_variance 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH}
)

function(set_compile_options target)
    target_compile_options(${target} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
    )

    set_target_properties(${target} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    ) 
endfunction()


set_compile_options(mapper)
set_compile_options(reducer_mean)
set_compile_options(reducer_variance)
