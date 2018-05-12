
set (FTT_ARCH_SRCS
  main.cpp
  fixed_three_tables.cpp
  )

set (FTT_ATCH_HDRS
  fixed_three_tables.h
  )

add_cpplint_files (${CMAKE_CURRENT_SOURCE_DIR} "${FTT_ARCH_SRCS};${FTT_ARCH_HDRS}")

build_unified(P4TEST_SRCS ALL)
add_executable(p4c-ftt ${FTT_ARCH_SRCS})
target_link_libraries (p4c-ftt ${P4C_LIBRARIES} ${P4C_LIB_DEPS})
add_dependencies(p4c-ftt genIR)

install (TARGETS p4c-ftt
  RUNTIME DESTINATION ${P4C_RUNTIME_OUTPUT_DIRECTORY})
install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/p4include
  DESTINATION ${P4C_ARTIFACTS_OUTPUT_DIRECTORY})
install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/driver/p4c.ftt.cfg
  DESTINATION ${P4C_ARTIFACTS_OUTPUT_DIRECTORY}/p4c_src)

add_custom_target(linkbinary
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_BINARY_DIR}/p4c-ftt ${P4C_BINARY_DIR}/p4c-ftt
)

add_dependencies(p4c_driver linkbinary)
