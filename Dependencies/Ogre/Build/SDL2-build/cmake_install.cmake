# Install script for directory: C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/Dependencies")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Release/SDL2.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Release/SDL2.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2maind.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Release/SDL2main.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2main.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2_test.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/Release/SDL2_test.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2_test.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2_test.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake"
         "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake"
         "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2testTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/SDL2Config.cmake"
    "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/SDL2ConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_atomic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_audio.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_bits.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_blendmode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_clipboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_copying.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_cpuinfo.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_egl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_endian.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_error.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_events.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_filesystem.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gamecontroller.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gesture.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_guid.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_haptic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hidapi.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hints.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_joystick.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keyboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keycode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_loadso.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_locale.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_main.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_messagebox.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_metal.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_misc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mouse.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mutex.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_name.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl_glext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2ext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_khrplatform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_pixels.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_power.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_quit.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rect.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_render.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rwops.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_scancode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_sensor.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_shape.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_stdinc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_surface.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_system.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_syswm.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_common.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_compare.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_crc32.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_font.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_fuzzer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_harness.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_images.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_md5.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_memory.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_random.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_thread.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_timer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_touch.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_types.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_version.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_video.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_vulkan.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/begin_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/close_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include/SDL_revision.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include-config-debug/SDL_config.h"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_atomic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_audio.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_bits.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_blendmode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_clipboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_copying.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_cpuinfo.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_egl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_endian.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_error.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_events.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_filesystem.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gamecontroller.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gesture.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_guid.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_haptic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hidapi.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hints.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_joystick.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keyboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keycode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_loadso.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_locale.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_main.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_messagebox.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_metal.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_misc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mouse.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mutex.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_name.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl_glext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2ext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_khrplatform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_pixels.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_power.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_quit.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rect.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_render.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rwops.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_scancode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_sensor.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_shape.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_stdinc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_surface.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_system.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_syswm.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_common.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_compare.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_crc32.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_font.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_fuzzer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_harness.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_images.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_md5.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_memory.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_random.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_thread.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_timer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_touch.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_types.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_version.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_video.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_vulkan.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/begin_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/close_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include/SDL_revision.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include-config-release/SDL_config.h"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_atomic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_audio.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_bits.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_blendmode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_clipboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_copying.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_cpuinfo.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_egl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_endian.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_error.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_events.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_filesystem.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gamecontroller.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gesture.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_guid.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_haptic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hidapi.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hints.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_joystick.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keyboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keycode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_loadso.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_locale.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_main.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_messagebox.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_metal.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_misc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mouse.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mutex.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_name.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl_glext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2ext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_khrplatform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_pixels.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_power.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_quit.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rect.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_render.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rwops.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_scancode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_sensor.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_shape.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_stdinc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_surface.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_system.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_syswm.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_common.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_compare.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_crc32.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_font.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_fuzzer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_harness.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_images.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_md5.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_memory.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_random.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_thread.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_timer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_touch.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_types.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_version.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_video.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_vulkan.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/begin_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/close_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include/SDL_revision.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include-config-minsizerel/SDL_config.h"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_atomic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_audio.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_bits.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_blendmode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_clipboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_copying.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_cpuinfo.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_egl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_endian.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_error.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_events.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_filesystem.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gamecontroller.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_gesture.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_guid.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_haptic.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hidapi.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_hints.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_joystick.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keyboard.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_keycode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_loadso.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_locale.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_main.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_messagebox.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_metal.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_misc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mouse.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_mutex.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_name.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengl_glext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2ext.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_gl2platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_opengles2_khrplatform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_pixels.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_platform.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_power.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_quit.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rect.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_render.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_rwops.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_scancode.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_sensor.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_shape.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_stdinc.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_surface.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_system.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_syswm.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_assert.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_common.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_compare.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_crc32.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_font.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_fuzzer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_harness.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_images.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_log.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_md5.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_memory.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_test_random.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_thread.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_timer.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_touch.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_types.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_version.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_video.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/SDL_vulkan.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/begin_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-2.24.1/include/close_code.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include/SDL_revision.h"
      "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/include-config-relwithdebinfo/SDL_config.h"
      )
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Usuario/Documents/ELDERSBANE-Grupo03/Eldersbane/Motor-Grupo3/Dependencies/Ogre/Build/SDL2-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
