cmake_minimum_required(VERSION 3.5)

project(recipe_cli)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)  # Automatically run moc when needed
set(CMAKE_AUTOUIC ON)  # Automatically run uic if you're using .ui files
set(CMAKE_AUTORCC ON)  # Automatically run rcc if you're using Qt resource files
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fsanitize=address")

set(DB_PATH "${CMAKE_SOURCE_DIR}/src/database/db.sqlite3")
add_compile_definitions(DB_PATH="${DB_PATH}")

# Include directories for headers
include_directories(
    ${CMAKE_SOURCE_DIR}/src/addrecipewindow
    ${CMAKE_SOURCE_DIR}/src/generatelistwindow
    ${CMAKE_SOURCE_DIR}/src/mainwindow
    ${CMAKE_SOURCE_DIR}/src/viewrecipewindow
		${CMAKE_SOURCE_DIR}/src/database
		#	${CMAKE_SOURCE_DIR}/src/database/modelStructs
)

add_executable(recipe_cli
    src/main.cpp
    src/mainwindow/mainwindow.cpp
    src/mainwindow/mainwindow.h  # Ensure the header file is included
		src/addrecipewindow/addrecipewindow.cpp
		src/addrecipewindow/addrecipewindow.h
		src/viewrecipewindow/viewrecipewindow.cpp
		src/viewrecipewindow/viewrecipewindow.h
		src/database/SQLiteHelper.cpp
		src/database/SQLiteHelper.h
)

target_link_libraries(recipe_cli Qt5::Widgets Qt5::Core sqlite3)

