//
// Created by 徐琛 on 2019/10/11.
//

#ifndef TEST_TREENODE_HPP
#define TEST_TREENODE_HPP


#include <iostream>
#include "vector"
#include "queue"
#include "stack"
#include "stack"

using std::string;
using std::vector;
using std::queue;
using std::stack;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// DNF
// creat exact tree as data of queue
TreeNode* creatTree(std::queue<int> &tree){
    TreeNode* res;
    *res = TreeNode(tree.front());
    tree.pop();
    while(!tree.empty()){

    }
    return res;
}




//2019/10/8/9:35
std::vector<std::vector<int>> res;
void goDeeper(TreeNode* root, int depth){
    if(root){
        if(res.size() <= depth){
            res.push_back(std::vector<int>());
        }
        res[depth].push_back(root->val);
    }
    else
        return;
    goDeeper(root->left, depth + 1);
    goDeeper(root->right, depth + 1);
}
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    goDeeper(root, 0);
    reverse(res.begin(), res.end());
    return res;
}


std::vector<std::vector<int>> levelOrderOrdinary(TreeNode* root){
    std::vector<std::vector<int>> res;
    if(!root)
        return res;
    std::queue<TreeNode*> Q;
    TreeNode* p;
    Q.push(root);

    while(!Q.empty()){
        std::vector<int> temp;
        int width = Q.size();
        for(int i = 0; i < width; i++){
            p = Q.front();
            temp.push_back(p->val);
            Q.pop();
            if(p->left)
                Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }
        res.push_back(temp);
    }
    return res;
}


int maxDepth(TreeNode* root) {
    int res = 0;
    if(!root) return res;

    std::queue<TreeNode*> Q;
    TreeNode* p;
    Q.push(root);
    while(!Q.empty()){
        ++res;
        int wedith = Q.size();
        for(int i = 0; i < wedith; ++i){
            p = Q.front();
            Q.pop();
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
    }
    return res;
}


bool isValidBST(TreeNode* root) {
    std::queue<TreeNode*> Q;
    if(!root) return true;
    if(!root->right && !root->left) return true;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* p;
        int length = Q.size();
        for(int i = 0; i < length; ++i){
            p = Q.front();
            if((p->right && !p->left) || (p->left && !p->right))
                return false;
            Q.pop();
            if(p->left){
                if(p->val <= p->left->val){
                    return false;
                }
                Q.push(p->left);
            }
            if(p->right){
                if(p->val >= p->right->val){
                    return false;
                }
                Q.push(p->right);
            }
        }
    }
    return true;
}

// 2019/10/12 18:35
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p == NULL && q == NULL) return true;
    if(p->val != q->val) return false;
    std::queue<TreeNode*> P;
    std::queue<TreeNode*> Q;
    TreeNode* pp;
    TreeNode* qq;
    P.push(p);
    Q.push(q);
    while(!Q.empty()){
        int width = Q.size();
        for(int i = 0; i < width; i++) {
            pp = P.front();
            std::cout << "pp: " <<pp->val << std::endl;
            qq = Q.front();
            std::cout << "qq: " << qq->val << std::endl;
            Q.pop();
            P.pop();

            if(pp->left && qq->left) {
                if (pp->left->val == qq->left->val){
                    P.push(pp->left);
                    Q.push(qq->left);
                } else
                    return false;
            }else if( !( !(pp->left) && !(qq->left) ) )
                return false;

            if(pp->right && qq->right) {
                if (pp->right->val == qq->right->val){
                    P.push(pp->right);
                    Q.push(qq->right);
                } else
                    return false;
            }
            else if( !( !(pp->right) && !(qq->right) ) )
                return false;
        }
    }
    return true;
}



bool ifSym(TreeNode* r1, TreeNode* r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    return (r1->val == r2->val) && ifSym(r1->left, r2->right) && ifSym(r1->right, r2->left);
}
bool isSymmetric(TreeNode* root) {
    return ifSym(root, root);
}

int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    int depth = 1;
    std::queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* p = root;
    while(!Q.empty()){
        int size = Q.size();
        for(int i = 0; i < size; ++i){
            p = Q.front();
            Q.pop();
            if(!p->left && !p->right) return depth;
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        ++depth;
    }
    return depth;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if(!root) return ans;
    std::queue<TreeNode*> Q;
    Q.push(root);
    int row = 0;
    while(!Q.empty()){
        std::vector<int> temp;
        int depth = Q.size();
        for(int i = 0; i < depth; ++i){
            TreeNode* p = Q.front();
            temp.emplace_back(p->val);
            Q.pop();
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        if(row & 1) reverse(temp.begin(), temp.end());
        ++row;
        ans.emplace_back(temp);
    }
    return ans;
}


bool isNext(string word, string curWord){
    int notMatch = 0;
    for(int i = 0; i < word.size(); ++i){
        if(word[i] != curWord[i]) ++notMatch;
    }
    return (notMatch == 1);
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> Q;
    Q.push(beginWord);
    int ans = 2;
    while(!Q.empty()){
        int depth = Q.size();
        for(int i = 0; i < depth; ++i) {
            for (auto word:wordList) {
                string curWord = Q.front();
                Q.pop();
                if(word == endWord) return ans;
                if (isNext(word, curWord)) Q.push(word);
            }
        }
        ++ans;
    }
}

vector<int> rightSideView(TreeNode* root) {
    std::vector<int> res;
    if(!root)
        return res;
    std::queue<TreeNode*> Q;
    TreeNode* p;
    Q.push(root);

    while(!Q.empty()){
        std::vector<int> temp;
        int width = Q.size();
        for(int i = 0; i < width; i++){
            p = Q.front();
            temp.push_back(p->val);
            Q.pop();
            if(p->left)
                Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }
        res.push_back(temp.back());
    }
    return res;
}

static vector<int> pTAns;
void toGoDeeper(TreeNode* root){
    pTAns.emplace_back(root->val);
    if(root->left) toGoDeeper(root->left);
    if(root->right) toGoDeeper(root->right);
}
vector<int> preorderTraversalRecur(TreeNode* root) {
    if(!root) return pTAns;
    toGoDeeper(root);
    return pTAns;
}

vector<int> preorderTraversalIter(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode* p = nodes.top();
        if(p->right){
            nodes.pop();
            nodes.push(p->right);
        }
        else nodes.pop();
        ans.emplace_back(p->val);
        if(p->left) nodes.push(p->left);
    }
    return ans;
}


#endif //TEST_TREENODE_HPP
