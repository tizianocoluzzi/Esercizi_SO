cmake_minimum_required (VERSION 2.8.11)
project (boh_cose)

add_library(veicolo_library SHARED
    Veicolo.c
    Automobile.c
    Camion.c
    ParcoAuto.c)
add_executable(main
  main.c)

target_link_libraries(main
  veicolo_library)




  


