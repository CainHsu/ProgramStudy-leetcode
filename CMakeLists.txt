cmake_minimum_required(VERSION 3.15)
project(ProgramStudy_leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProgramStudy_leetcode main.cpp
        "leetCode/150.Evaluate Reverse Polish Notation.hpp"
        SourceCode/DataStructure/TreeNode.hpp
        "leetCode/739.Daily Temperatures.hpp"
        "leetCode/102.Binary Tree Level Order Traversal.hpp"
        "leetCode/107.Binary Tree Level Order Traversal II.hpp"
        "leetCode/111.Minimum Depth of Binary Tree.hpp"
        "leetCode/101.Symmetric Tree.hpp"
        main2.cpp SourceCode/person.hpp
        "SourceCode/mathProblems.hpp"
        SourceCode/Algorithm/BFS.hpp
        "leetCode/200.Number of Islands.hpp"
        SourceCode/_person.cpp
        "leetCode/103.Binary Tree Zigzag Level Order Traversal.hpp"
        "leetCode/199.Binary Tree Right Side View.hpp"
        "SourceCode/else.hpp" "leetCode/144.Binary Tree Preorder Traversal.hpp" SourceCode/Algorithm/UnionFind.hpp SourceCode/male.hpp SourceCode/_male.cpp "leetCode/147.Insertion Sort List.hpp" "leetCode/112.Path Sum.hpp" "leetCode/404.Sum of Left Leaves.hpp" SourceCode/structs.hpp)