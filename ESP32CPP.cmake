set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE MinSizeRel)

# set(CMAKE_BUILD_PARALLEL_LEVEL 8)


include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

# example usage
enable_cxx_compiler_flag_if_supported("-fno-exceptions")
enable_cxx_compiler_flag_if_supported("-fno-unwind-tables")
enable_cxx_compiler_flag_if_supported("-fno-asynchronous-unwind-tables")
enable_cxx_compiler_flag_if_supported("-fno-rtti")

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
