cmake_minimum_required(VERSION 3.10)
project(part2)

# set(EXECUTABLES
#     /home/yj/kuuniv.bigdata2025/c_example/part1/infinit.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/limit.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/celsius2fahr.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/fahr2celsius.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/charNumber.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/triangle.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/triangle2.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/arithmetics.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/increment.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/literal.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/genderRatio.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/compare.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/compare2.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/sizeof.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/oddeven.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/fourBit.c
#     /home/yj/kuuniv.bigdata2025/c_example/part1/fourBit2.c
# )

file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()