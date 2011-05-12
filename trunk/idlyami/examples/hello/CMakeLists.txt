
add_executable(hello_server server.cpp helloC.cpp)
target_link_libraries(hello_server idlyami)

add_executable(hello_client client.cpp helloC.cpp)
target_link_libraries(hello_client idlyami)
