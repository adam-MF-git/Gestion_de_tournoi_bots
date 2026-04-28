cmake_minimum_required(VERSION 3.16)

project(Projet-Tournois LANGUAGES CXX)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wpedantic -O3)

add_subdirectory(Joueur)
add_subdirectory(Jeu)

add_executable(Tournois
    main.cpp
    Arbitre.hh
    Arbitre.cc
    Competition.hh
    Competition.cc
)

target_link_libraries(Tournois PRIVATE Joueur Jeu)

include(GNUInstallDirs)

install(TARGETS Tournois
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


message(NOTICE "compilation de Projet-Tournois c'est bien passé !")