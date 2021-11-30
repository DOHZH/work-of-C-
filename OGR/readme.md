# Intro

1. This program is only a class library, which imitate the famous gis library **OGR**

2. You can use the [./test/main.cpp](OGR/test/main.cpp) to test the class library
3. You can define input txt document in [./test](https://github.com/DOHZH/work-of-C-/tree/master/OGR/test)
4. You can read [this manual](OGR/Implementation Specification for Geographic Information Simple feature access Part 1 CommonArchitecture v1.2.1(1).pdf\) to get more specific information

# Structure of program

1. the global define some basic element of geometry. Others all the geometric elements in OGR

   ![](https://github.com/DOHZH/work-of-C-/blob/master/pic/OGRGeometry.png?raw=true)

2. divide_method: divide input information to string

3. string_to_float: change string to float. The class will be used after read input info
