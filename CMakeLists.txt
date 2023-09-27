# CMakeList.txt : CMake project for ParsingProject, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ParsingProject "ParsingProject.cpp" "ParsingProject.h" "UnitTests.cpp")
add_library (Lexer "Lexer/Lexer.h" "Lexer/Lexer.cpp" "UnitTests.h")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ParsingProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
