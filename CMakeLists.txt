cmake_minimum_required(VERSION 3.21)
project(Probability_Theory_Calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Probability_Theory_Calculator main.cpp pdf.cpp pdf.h cdf.cpp cdf.h expected_val.cpp expected_val.h variance.cpp variance.h char_func.cpp char_func.h)
