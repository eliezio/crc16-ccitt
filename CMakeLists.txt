cmake_minimum_required(VERSION 2.8)
project(crc16)
enable_language(C)

add_executable(test-crc16 src/test-crc16.c src/crc16.c)

add_executable(print-table src/print-table.c)
