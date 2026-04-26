#Je ne gère pas si les personnes amène leur propre dossier/CMakeLists et aussi si il y a des fichier avec les mêmes noms
file(GLOB Les_Headers "*.hh" "*.h")
# file(GLOB Les_Headers "${CMAKE_SOURCE_DIR}/*.hh" "${CMAKE_SOURCE_DIR}/*.h")
file(GLOB Les_Sources "*.cpp" "*.cc" "*.c")
# file(GLOB Les_Sources "${CMAKE_SOURCE_DIR}/*.cpp" "${CMAKE_SOURCE_DIR}/*.cc" "${CMAKE_SOURCE_DIR}/*.c")

set(INCLUDES_JEUX "")
foreach(header IN LISTS Les_Headers)
    get_filename_component(nom_header ${header} NAME)
    if(NOT nom_header STREQUAL "includeTousJeux.hh")
        # string(APPEND INCLUDES_JEUX "#include \"Jeu/${nom_header}\"\n")
        string(APPEND INCLUDES_JEUX "#include \"${nom_header}\"\n")
    endif()
endforeach()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJeux.hh.in
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJeux.hh
)

add_library(Jeu
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJeux.hh
    ${CMAKE_SOURCE_DIR}/include/Jeu/Jeu.hh
    ${CMAKE_SOURCE_DIR}/include/Jeu/Jeu.cc
    ${CMAKE_SOURCE_DIR}/include/macro/macro.hh
    ${CMAKE_SOURCE_DIR}/include/macro/Registre.hh
    ${Les_Headers}
    ${Les_Sources}
)

target_include_directories(Jeu
    PUBLIC "${CMAKE_SOURCE_DIR}/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/include/Jeu"
)

message(NOTICE "compilation de Jeu c'est bien passé !")