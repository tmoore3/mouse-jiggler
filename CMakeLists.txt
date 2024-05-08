cmake_minimum_required(VERSION 3.0)
project (mouse-jiggler)
add_executable(mouse-jiggler mouse-jiggler.c)
install(TARGETS mouse-jiggler RUNTIME DESTINATION bin)
