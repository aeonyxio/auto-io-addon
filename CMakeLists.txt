cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

# Name of the project (will be the name of the plugin)
project(addon)

# Build a shared library named after the project from the files in `src/`
file(GLOB_RECURSE SOURCE_FILES
"src/common.h"
"src/key/key.cc"
"src/key/key.h"
"src/events/events-object.cc"
"src/events/events-object.h"

"src/get-keyboard-layout-list/get-keyboard-layout-list.cc"
"src/get-keyboard-layout-list/get-keyboard-layout-list.h"
"src/get-keyboard-layout-list/sync.cc"
"src/get-keyboard-layout-list/sync.h"

"src/get-keyboard-layout/get-keyboard-layout.cc"
"src/get-keyboard-layout/get-keyboard-layout.h"
"src/get-keyboard-layout/sync.cc"
"src/get-keyboard-layout/sync.h"

"src/get-mouse-position/get-mouse-position.cc"
"src/get-mouse-position/get-mouse-position.h"
"src/get-mouse-position/sync.cc"
"src/get-mouse-position/sync.h"

"src/highlight-screen/highlight-screen.cc"
"src/highlight-screen/highlight-screen.h"
"src/highlight-screen/sync.cc"
"src/highlight-screen/sync.h"
"src/highlight-screen/async.cc"
"src/highlight-screen/async.h"

"src/key-down/key-down.cc"
"src/key-down/key-down.h"
"src/key-down/sync.cc"
"src/key-down/sync.h"
"src/key-down/async.cc"
"src/key-down/async.h"

"src/key-up/key-up.cc"
"src/key-up/key-up.h"
"src/key-up/sync.cc"
"src/key-up/sync.h"
"src/key-up/async.cc"
"src/key-up/async.h"

"src/unicode/unicode.cc"
"src/unicode/unicode.h"
"src/unicode/sync.cc"
"src/unicode/sync.h"
"src/unicode/async.cc"
"src/unicode/async.h"

"src/mouse-down/mouse-down.cc"
"src/mouse-down/mouse-down.h"
"src/mouse-down/sync.cc"
"src/mouse-down/sync.h"
"src/mouse-down/async.cc"
"src/mouse-down/async.h"

"src/mouse-move/mouse-move.cc"
"src/mouse-move/mouse-move.h"
"src/mouse-move/sync.cc"
"src/mouse-move/sync.h"
"src/mouse-move/async.cc"
"src/mouse-move/async.h"

"src/mouse-up/mouse-up.cc"
"src/mouse-up/mouse-up.h"
"src/mouse-up/sync.cc"
"src/mouse-up/sync.h"
"src/mouse-up/async.cc"
"src/mouse-up/async.h"

"src/sleep/async.cc"
"src/sleep/async.h"
"src/sleep/sync.cc"
"src/sleep/sync.h"

"src/set-keyboard-layout/set-keyboard-layout.cc"
"src/set-keyboard-layout/set-keyboard-layout.h"
"src/set-keyboard-layout/sync.cc"
"src/set-keyboard-layout/sync.h"
"src/set-keyboard-layout/async.cc"
"src/set-keyboard-layout/async.h"

"src/shutdown/shutdown.cc"
"src/shutdown/shutdown.h"
"src/shutdown/shutdown-api.cc"
"src/shutdown/shutdown-api.h"

"src/window/window.cc"
"src/window/window.h"
"src/window/window-api.cc"
"src/window/window-api.h"

"src/screen-capture/screen-capture.c"
"src/screen-capture/screen-capture.h"
"src/screen-capture/screen-capture-api.cc"
"src/screen-capture/screen-capture-api.h"

"src/dpi-aware/dpi-aware-api.cc"
"src/dpi-aware/dpi-aware-api.h"

"src/auto_addon.cc"
"src/auto_addon.h"
)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

if(napi_build_version)
    message(STATUS "NAPI BUILD VERSION: ${napi_build_version}")
    add_compile_definitions(NAPI_VERSION=${napi_build_version})
    # add_compile_definitions(NAPI_VERSION=6)
else()
    message(STATUS "Without prebuild")
endif()

# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api 
    ${CMAKE_JS_INC})

# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})