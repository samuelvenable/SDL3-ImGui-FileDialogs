cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(filedialogs)
if(IFD_USE_BASIC_ICONS)
	add_compile_definitions(IFD_USE_BASIC_ICONS)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else()
	if(APPLE)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -ObjC++")
	else() 
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
	endif()
endif()
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(CMAKE_TOOLCHAIN_FILE)
	include(${CMAKE_TOOLCHAIN_FILE})
endif(CMAKE_TOOLCHAIN_FILE)
if (UNIX)
	find_package(PkgConfig REQUIRED)
endif()
include(${CMAKE_CURRENT_SOURCE_DIR}/cl-bootstrap.cmake)
cl_repo()
if(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
	set(CATALOG_REQ_TYPE PREFER_SHARED)
else()
	set(CATALOG_REQ_TYPE PREFER_STATIC)
endif()
if(IFD_USE_LIBRARY_BUILD)
	set(SOURCES
		source/apifiledialogs/filedialogs.cpp
		source/apifilesystem/filesystem.cpp
		source/ImFileDialog/ImFileDialog.cpp
		source/imgui/imgui.cpp
		source/imgui/imgui_demo.cpp
		source/imgui/imgui_draw.cpp
		source/imgui/imgui_impl_sdl3.cpp
		source/imgui/imgui_impl_sdlrenderer3.cpp
		source/imgui/imgui_tables.cpp
		source/imgui/imgui_widgets.cpp
		source/msgbox/imguial_msgbox.cpp
	)
	add_library(filedialogs ${SOURCES})
else()
	if(WIN32)
		set(SOURCES
			source/main.cpp
			source/resource.rc
			source/apifiledialogs/filedialogs.cpp
			source/apifilesystem/filesystem.cpp
			source/ImFileDialog/ImFileDialog.cpp
			source/imgui/imgui.cpp
			source/imgui/imgui_demo.cpp
			source/imgui/imgui_draw.cpp
			source/imgui/imgui_impl_sdl3.cpp
			source/imgui/imgui_impl_sdlrenderer3.cpp
			source/imgui/imgui_tables.cpp
			source/imgui/imgui_widgets.cpp
			source/msgbox/imguial_msgbox.cpp
		)
	else()
		set(SOURCES
			source/main.cpp
			source/apifiledialogs/filedialogs.cpp
			source/apifilesystem/filesystem.cpp
			source/ImFileDialog/ImFileDialog.cpp
			source/imgui/imgui.cpp
			source/imgui/imgui_demo.cpp
			source/imgui/imgui_draw.cpp
			source/imgui/imgui_impl_sdl3.cpp
			source/imgui/imgui_impl_sdlrenderer3.cpp
			source/imgui/imgui_tables.cpp
			source/imgui/imgui_widgets.cpp
			source/msgbox/imguial_msgbox.cpp
		)
	endif()
	add_executable(filedialogs ${SOURCES})
endif()
cl_add_dep(filedialogs SDL3)
set_target_properties(filedialogs PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)
target_include_directories(filedialogs PRIVATE source source/imgui)
if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" OR CMAKE_SYSTEM_NAME STREQUAL "DragonFly")
	target_include_directories(filedialogs PUBLIC "/usr/local/include")
	target_link_directories(filedialogs PUBLIC "/usr/local/lib")
elseif(CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
	target_include_directories(filedialogs PUBLIC "/usr/X11R7/include")
	target_link_directories(filedialogs PUBLIC "/usr/X11R7/lib")
elseif(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
	target_include_directories(filedialogs PUBLIC "/usr/X11R6/include")
	target_link_directories(filedialogs PUBLIC ${LIBUSB_LIBRARIES} "/usr/X11R6/lib")
endif()
if(WIN32)
	target_link_libraries(filedialogs PRIVATE shell32)
elseif(UNIX AND NOT APPLE)
	if(IFD_USE_BASIC_ICONS)
		if(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
			target_link_libraries(filedialogs PRIVATE ${CMAKE_DL_LIBS} X11 kvm pthread)
		else()
			target_link_libraries(filedialogs PRIVATE ${CMAKE_DL_LIBS} X11 pthread)
		endif()
	else()
		add_subdirectory(source/lunasvg)
		include_directories(source/lunasvg/include)
		find_package(PkgConfig REQUIRED)
		pkg_search_module(PKG_GTK3 REQUIRED IMPORTED_TARGET gtk+-3.0)
		pkg_search_module(PKG_GIO2 REQUIRED IMPORTED_TARGET gio-2.0)
		pkg_search_module(PKG_GLIB2 REQUIRED IMPORTED_TARGET glib-2.0)
		if(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
			target_link_libraries(filedialogs PRIVATE lunasvg PkgConfig::PKG_GTK3 PkgConfig::PKG_GIO2 PkgConfig::PKG_GLIB2 ${CMAKE_DL_LIBS} X11 kvm pthread)
		else()
			target_link_libraries(filedialogs PRIVATE lunasvg PkgConfig::PKG_GTK3 PkgConfig::PKG_GIO2 PkgConfig::PKG_GLIB2 ${CMAKE_DL_LIBS} X11 pthread)
		endif()
	endif()
elseif(APPLE)
	target_link_libraries(filedialogs PRIVATE "-framework CoreFoundation -framework AppKit" ${CMAKE_DL_LIBS})
endif()
