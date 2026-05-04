#Je ne gère pas si les personnes amène leur propre dossier/CMakeLists et aussi si il y a des fichier avec les mêmes noms
file(GLOB Les_Headers "*.hh" "*.h")
# file(GLOB Les_Headers "${CMAKE_SOURCE_DIR}/*.hh" "${CMAKE_SOURCE_DIR}/*.h")
file(GLOB Les_Sources "*.cpp" "*.cc" "*.c")
# file(GLOB Les_Sources "${CMAKE_SOURCE_DIR}/*.cpp" "${CMAKE_SOURCE_DIR}/*.cc" "${CMAKE_SOURCE_DIR}/*.c")

set(INCLUDES_JOUEURS "")
foreach(header IN LISTS Les_Headers)
    get_filename_component(nom_header ${header} NAME)
    if(NOT nom_header STREQUAL "includeTousJoueurs.hh")
        # string(APPEND INCLUDES_JOUEURS "#include \"Joueur/${nom_header}\"\n")
        string(APPEND INCLUDES_JOUEURS "#include \"${nom_header}\"\n")
    endif()
endforeach()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJoueurs.hh.in
    # ${CMAKE_BINARY_DIR}/includeTousJoueurs.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJoueurs.hh
)


add_library(Joueur
    ${CMAKE_CURRENT_SOURCE_DIR}/includeTousJoueurs.hh
    ${CMAKE_SOURCE_DIR}/include/Joueur/Joueur.hh
    ${CMAKE_SOURCE_DIR}/include/Joueur/Joueur.cc
    ${CMAKE_SOURCE_DIR}/include/macro/macro.hh
    ${CMAKE_SOURCE_DIR}/include/macro/Registre.hh
    ${CMAKE_SOURCE_DIR}/include/macro/Registre.cc
    ${Les_Headers}
    ${Les_Sources}
)

target_include_directories(Joueur
    PUBLIC "${CMAKE_SOURCE_DIR}/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/include/Joueur"
)

message(NOTICE "compilation de Joueur c'est bien passé !")