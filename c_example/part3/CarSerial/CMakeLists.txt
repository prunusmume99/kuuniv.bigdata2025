cmake_minimum_required(VERSION 3.10)
project(carSerial)

# 소스 파일 설정
set(SOURCES
    main.c
    serial.c
)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(carSerial ${SOURCES})