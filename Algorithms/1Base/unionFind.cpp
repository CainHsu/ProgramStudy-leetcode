//
// Created by xuche on 2020/6/4.
//

#include "unionFind.hpp"

int UnionFind::count = 0;

UnionFind::UnionFind(int N) {
    count = N;
    for(int i = 0; i < N; ++i) {
        id[i] = i;

        // 加权quick-union
        size[i] = 1;
    }


}

bool UnionFind::connected(int p, int q) {
    return find(p) == find(q);
}

int UnionFind::getCount() {
    return count;
}

// First method: union-find
// 通过id[i]的值是否相等判断连通性
// 遍历id[]将所有p改为q
//void UnionFind::unionNodes(int p, int q) {
//    int pID = id[p];
//    int qID = id[q];
//    if(pID == qID) return;
//    for(int & i : id)
//        if(i == pID) i = qID;
//    count--;
//}
//
//int UnionFind::find(int p) {
//    return id[p];
//}


// Second method: quick-union
// 每个触点对应的id[]元素都是同一个分量中的另一个触点的名称，这种联系为链接
//void UnionFind::unionNodes(int p, int q) {
//    int pRoot = find(p);
//    int qRoot = find(q);
//    if(pRoot == qRoot) return;
//    id[pRoot] = qRoot;
//    count--;
//}

// 返回根触点，也就是链接指向自己的触点
// find()函数的时间复杂度为树的高度
int UnionFind::find(int p) {
    while(p != id[p]) p = id[p];
    return p;
}


// Third method: 加权quick-union
// 根据树的大小，将小树链接到大树上
// 优点：减少find()函数的时间复杂度
void UnionFind::unionNodes(int p, int q) {
    int i = find(p);
    int j = find(q);
    if(i == j) return;
    if(size[i] > size[j]){
        id[j] = i;
        size[j] += size[i];
    }
    else{
        id[i] = j;
        size[i] += size[j];
    }
    count--;
}



