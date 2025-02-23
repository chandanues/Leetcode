/*

1261. Find Elements in a Contaminated Binary Tree

Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

Example 1:


Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {

    public:
    int val;
    TreeNode* left, *right;

    public:
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class FindElements {

    TreeNode* root;
    public:

    void f(TreeNode* root) {
        if(!root) return ;
        root->val=-1;
        f(root->left);
        f(root->right);
    }

    FindElements(TreeNode* root) {
        this->root=root;
        f(root);
    }

    bool dfs(TreeNode* root,int target){
        if(!root) return false;
        if(root->val==target) return true;
        if(root->left) {
            root->left->val=2*root->val+1;
            if(dfs(root->left,target)) return true;
        }
        if(root->right) {
            root->right->val=2*root->val+2;
            if(dfs(root->right,target)) return true;
        }
        return false;
    }

    
    bool find(int target){
        root->val=0;
        if(!root) return false;
        return dfs(root,target);
    }
};

class FindElements2 {
    private:
    unordered_set<int>st;

    public:
    FindElements2(TreeNode* root) {
        root->val=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            st.insert(front->val);
            if(front->left) {
                front->left->val=2*front->val+1;
                q.push(front->left);
            }
            if(front->right) {
                front->right->val=2*front->val+2;
                q.push(front->right);
            }
        }
    }

    bool find(int target){
        return st.find(target)!=st.end();
    }
};

int main() {
    return 0;
}