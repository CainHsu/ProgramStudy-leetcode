cmake_minimum_required(VERSION 3.15)
project(ProgramStudy_leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProgramStudy_leetcode main.cpp
        "leetCode/150.Evaluate Reverse Polish Notation.hpp" TreeNode.hpp "leetCode/739.Daily Temperatures.hpp" "leetCode/102.Binary Tree Level Order Traversal.hpp" "leetCode/107.Binary Tree Level Order Traversal II.hpp" "leetCode/111.Minimum Depth of Binary Tree.hpp" "leetCode/101.Symmetric Tree.hpp" main2.cpp)