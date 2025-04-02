cmake_minimum_required(VERSION 3.10)
project(bowlingGame)

# C 표준 설정 (원하는 C 표준으로 변경 가능)
set(CMAKE_C_STANDARD 99)

# MySQL 클라이언트 라이브러리를 pkg-config를 통해 찾기
find_package(PkgConfig REQUIRED)
pkg_check_modules(MYSQL REQUIRED mysqlclient)

# MySQL 헤더와 라이브러리 경로 추가
include_directories(${MYSQL_INCLUDE_DIRS})
link_directories(${MYSQL_LIBRARY_DIRS})

# 소스 파일 지정 (main.c와 bowling.c)
set(SOURCES
    main.c
    bowling.c
)

# 실행 파일 생성
add_executable(bowlingGame ${SOURCES})

# MySQL 라이브러리 링크
target_link_libraries(bowlingGame ${MYSQL_LIBRARIES})
