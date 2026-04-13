cmake_minimum_required(VERSION 3.16)

project(App LANGUAGES CXX)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wpedantic -O3)

add_subdirectory(Joueur)
add_subdirectory(Jeu)

set(Headers
    Jeu.hh
    Joueur.hh
    Arbitre.hh
    Competition.hh
    Registre.hh
    macro.hh
)

set(Sources
    Jeu.cc
    Joueur.cc
    Arbitre.cc
    Competition.cc
)

add_executable(App
    main.cpp
    ${Headers}
    ${Sources}
)

include(GNUInstallDirs)


install(TARGETS App
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(App PRIVATE Joueur)
target_link_libraries(App PRIVATE Jeu)

