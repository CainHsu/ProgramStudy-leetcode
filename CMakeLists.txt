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
        "SourceCode/else.hpp"
        "leetCode/144.Binary Tree Preorder Traversal.hpp"
        SourceCode/Algorithm/UnionFind.hpp
        SourceCode/male.hpp SourceCode/_male.cpp
        "leetCode/147.Insertion Sort List.hpp"
        "leetCode/112.Path Sum.hpp"
        "leetCode/404.Sum of Left Leaves.hpp"
        SourceCode/structs.hpp
        "leetCode/872.Leaf-Similiar Trees.hpp"
        "leetCode/513.Find Bottom Left Tree Value.hpp"
        "leetCode/129.Sum Root to Leaf Numbers.hpp"
        "leetCode/226.Invert Binary Tree.hpp"
        "leetCode/235.Lowest Common Ancestor of a Binary Search Tree.hpp"
        "leetCode/108.Convert Sorted Array to Binary Tree.hpp"
        "leetCode/110.Balanced Binary Tree.hpp"
        Algorithms/1Base/unionFind.cpp
        Algorithms/1Base/unionFind.hpp
        Algorithms/2Sorting/1ElementarySorts/elementarySorts.cpp
        Algorithms/2Sorting/1ElementarySorts/elementarySorts.hpp
        Algorithms/2Sorting/data.cpp Algorithms/2Sorting/data.hpp
        "leetCode/242.Valid Anagram.hpp"
        Algorithms/2Sorting/2MergeSort/mergeSort.cpp
        Algorithms/2Sorting/2MergeSort/mergeSort.hpp
        Algorithms/2Sorting/tools.cpp
        Algorithms/2Sorting/tools.hpp Algorithms/2Sorting/3QuickSort/quickSort.cpp Algorithms/2Sorting/3QuickSort/quickSort.hpp leetCode/15.3Sum.hpp "leetCode/16.3Sum Closest.hpp" leetCode/18.4Sum.hpp)