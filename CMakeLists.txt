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
        Algorithms/2Sorting/tools.hpp
        Algorithms/2Sorting/3QuickSort/quickSort.cpp
        Algorithms/2Sorting/3QuickSort/quickSort.hpp
        leetCode/15.3Sum.hpp
        "leetCode/16.3Sum Closest.hpp"
        leetCode/18.4Sum.hpp
        "leetCode/31.Next Permutation.hpp"
        "leetCode/34.Find First and Last Position of Element in Sorted Array.hpp"
        "leetCode/39.Combination Sum.hpp"
        "leetCode/40.Combination Sum II.hpp"
        "leetCode/48.Rotate Image.hpp"
        "leetCode/21.Merge Two Sorted Lists.hpp"
        "leetCode/38.Count and Say.hpp"
        "leetCode/268.Missing Number.hpp"
        "leetCode/287.Find the Duplicate Number.hpp"
        "leetCode/448.Find All Numbers Disappeared in an Array.hpp"
        "leetCode/41.First Missing Positive.hpp"
        leetCode/120.Triangle.hpp
        "leetCode/53.Maximum Subarray.hpp"
        "leetCode/70.Climbing Stairs.hpp"
        "leetCode/121.Best Time to Buy and Sell Stock.hpp"
        "leetCode/198.House Robber.hpp"
        "leetCode/62.Unique Paths.hpp"
        "leetCode/64.Minimum Path Sum.hpp"
        "leetCode/213.House Robber II.hpp"
        "leetCode/96.Unique Binary Search Trees.hpp"
        "leetCode/95.Unique Binary Search Trees II.hpp"
        "leetCode/122.Best Time to Buy and Sell Stock II.hpp"
        "leetCode/63.Unique Paths II.hpp"
        "leetCode/328.Odd Even Linked List.hpp"
        "leetCode/92.Reverse Linked List II.hpp"
        "leetCode/24.Swap Nodes in Pairs.hpp"
        "leetCode/876.Middle of the Linked List.hpp"
        "leetCode/1290.Convert Binary Number in a Linked List to Integer.hpp"
        "leetCode/160.Intersection of Two Linked Lists.hpp" "leetCode/917.Reverse Only Letters.hpp" "leetCode/1487.Making File Names Unique.hpp" "leetCode/468.Validate IP Address.hpp" "leetCode/58.Length of Last Word.hpp" "leetCode/557.Reverse Words in a String III.hpp" "leetCode/541.Reverse String II.hpp" "leetCode/767.Reorganize String.hpp" "leetCode/1451.Rearrange Words in a Sentence.hpp" "leetCode/559.Maximum Depth of N-ary Tree.hpp" SourceCode/DataStructure/n-ary-tree.hpp "leetCode/451.Sort Characters By Frequency.hpp" leetCode/78.Subsets.hpp "leetCode/93.Restore IP Addresses.hpp" "leetCode/338.Counting Bits.hpp" leetCode/322.零钱兑换.hpp "leetCode/518.零钱兑换 II.hpp")