cmake_minimum_required(VERSION 3.23)
project(Billing_Management)

set(CMAKE_CXX_STANDARD 14)

add_executable(Billing_Management main.cpp Menu.cpp Menu.h CardVector.cpp CardVector.h global.h BillVector.cpp BillVector.h tool.h)
