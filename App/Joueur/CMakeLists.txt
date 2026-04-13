# cmake_minimum_required(VERSION 3.16)

# project(Joueur LANGUAGES CXX)

# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# add_compile_options(-Wall -Wpedantic -O3)

#Je ne gère pas si les personnes amène leur propre dossier/CMakeLists et aussi si il y a des fichier avec les mêmes noms
file(GLOB Les_Headers "*.hh" "*.h")
# file(GLOB Les_Headers "${CMAKE_SOURCE_DIR}/*.hh" "${CMAKE_SOURCE_DIR}/*.h")
file(GLOB Les_Sources "*.cpp" "*.cc" "*.c")
# file(GLOB Les_Sources "${CMAKE_SOURCE_DIR}/*.cpp" "${CMAKE_SOURCE_DIR}/*.cc" "${CMAKE_SOURCE_DIR}/*.c")

# add_executable(Joueur
#     ${Les_Headers}
#     ${Les_Sources}
# )

add_library(Joueur
    ../Joueur.hh
    ../Joueur.cc
    ../macro.hh
    # ./includeTousJoueurs.hh
    ${Les_Headers}
    ${Les_Sources}
)

target_include_directories(Joueur INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})