cmake_minimum_required(VERSION 3.16)

project(App LANGUAGES CXX)

# add_subdirectory(Joueur)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wpedantic -O3)


add_executable(App main.cpp
    Jeu.hh
    Joueur.hh
    Joueur.cc
    Arbitre.hh
    Arbitre.cc
    Competition.hh
    Competition.cc)

include(GNUInstallDirs)
install(TARGETS App
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
