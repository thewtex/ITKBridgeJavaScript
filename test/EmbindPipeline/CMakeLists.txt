cmake_minimum_required(VERSION 3.10)
project(Embind)

if(EMSCRIPTEN)
  include(ITKBridgeJavaScript)
  web_add_executable(Embind EMBIND Embind.cxx)
else()
  add_executable(Embind Embind.cxx)
endif()

enable_testing()
add_test(NAME EmbindTest
  COMMAND Embind
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/input.bin
    ${CMAKE_CURRENT_BINARY_DIR}/output.txt
    ${CMAKE_CURRENT_BINARY_DIR}/output.bin
  )
