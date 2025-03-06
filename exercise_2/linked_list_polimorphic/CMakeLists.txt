cmake_minimum_required (VERSION 2.8.11)
project (boh_cose)

add_library(linked_list_library SHARED
  linked_list.c
  int_list.c
  float_list.c
  list_list.c)

add_executable(linked_list_test
  linked_list_test.c)

target_link_libraries(linked_list_test
  linked_list_library)


add_executable(linked_list_exercise_1a
  linked_list_exercise_1a.c)

target_link_libraries(linked_list_exercise_1a
  linked_list_library)

add_executable(linked_list_exercise_2a
  linked_list_exercise_2a.c)

target_link_libraries(linked_list_exercise_2a
  linked_list_library)

  
include_directories(${PROJECT_SOURCE_DIR})


