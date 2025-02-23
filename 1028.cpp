/*

1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getval(string &traversal,const int &n,int &pos) {
        int val=0;
        while(pos<n && traversal[pos]>='0' && traversal[pos]<='9'){
            val=val*10+(traversal[pos]-'0');
            pos++;
        }
        return val;
    }

    int getdashes(string &traversal,const int &n,int &pos){
        int dash_count=0;
        while(pos<n && traversal[pos]=='-'){
            dash_count++;
            pos++;
        }
        return dash_count;
    }

    void build(TreeNode* root,int dl,string &s,int &pos,const int &n){
        if(pos==n) return ;
        int prev_pos=pos;
        int dashes=getdashes(s,n,pos);
        if(dashes<dl){
            pos=prev_pos;
            return ;
        }
        int nodeval=getval(s,n,pos);
        TreeNode* currNode=new TreeNode(nodeval);
        if(!root->left) root->left=currNode;
        else root->right=currNode;

        build(currNode,dl+1,s,pos,n);
        build(currNode,dl+1,s,pos,n);
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        int pos=0;
        TreeNode* root=new TreeNode(getval(traversal,n,pos));
        build(root,1,traversal,pos,n);
        build(root,1,traversal,pos,n);
        return root;
    }
};

class Solution_ {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*>m;
        TreeNode* root,*ptr;
        int i=0;
        string num="";
        while(i<traversal.size() && traversal[i]!='-'){
            num+=traversal[i];
            i++;
        }
        
        ptr =new TreeNode(stoi(num));
        m[0]=ptr;
        root=ptr;
        
        while(i<traversal.size()){
            int dash=0;
            string s="";
            while(traversal[i]=='-'){
                dash++;
                i++;
            }
            
            while(i<traversal.size() && traversal[i]!='-'){
                s+=traversal[i];
                i++;
            }
            
            auto ele=new TreeNode(stoi(s));
            if(!m[dash-1]->left)m[dash-1]->left=ele;
            else m[dash-1]->right=ele;
            
            m[dash]=ele;
        }
        
        return root;
    }
};

int main() {
    return 0;
}

