cmake_minimum_required(VERSION 3.13)
project(FRWindowsSystem)

set(CMAKE_CXX_STANDARD 17)



find_path(FR_X11_WINDOWS_MANAGER_PATH "window.h" ${CMAKE_CURRENT_SOURCE_DIR}/realization/FRX11WindowsManager)

if((NOT FR_X11_WINDOWS_MANAGER_PATH) OR (NOT EXISTS ${FR_X11_WINDOWS_MANAGER_PATH}))
    execute_process(COMMAND git clone git@github.com:Fork3r/FRX11WindowsManager.git -b dev
            ${CMAKE_CURRENT_SOURCE_DIR}/realization/FRX11WindowsManager)
endif()
include(${CMAKE_CURRENT_SOURCE_DIR}/realization/FRX11WindowsManager/CMakeLists.txt)

set(header
        ${header}
        )

set(src
        ${src}
        main.cpp
        )


add_executable(FRWindowsSystem main.cpp ${header} ${src})

target_link_libraries(FRWindowsSystem ${libraries})
target_compile_definitions(FRWindowsSystem PUBLIC ${defines})
