//
// Created by xuche on 2020/6/4.
//

#ifndef PROGRAMSTUDY_LEETCODE_UNIONFIND_HPP
#define PROGRAMSTUDY_LEETCODE_UNIONFIND_HPP

#include "vector"

using namespace std;

class UnionFind {
private:
    vector<int> id;
    vector<int> size;
    static int count;
public:
    explicit UnionFind(int N);
    void unionNodes(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    static int getCount();
};


#endif //PROGRAMSTUDY_LEETCODE_UNIONFIND_HPP
