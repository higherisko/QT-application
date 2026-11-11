function(add_git_submodule dir)
    find_package(Git REQUIRED)
        if(NOT EXISTS ${dir}/CmakeLists.txt)
             execute_process (COMMAND ${GIT_EXECUTABLE}
                submodule update --init --recursive -- ${dir}
                )
    endif()

    add_subdirectory(${dir})
endfunction(add_git_submodule)
    
