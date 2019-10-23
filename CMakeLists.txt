cmake_minimum_required(VERSION 3.15)
project(HW1_RPC C)

set(CMAKE_C_STANDARD 99)

add_executable(RPC_Client client.c common_clnt.c util.c)
add_executable(RPC_Server server.c)
