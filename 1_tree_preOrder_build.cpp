#include<bits/stdc++.h>
using namespace std;

class node{
 public:
    int d;
    node* left;
    node* right;
    node(int data){
        d=data;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
     int x;
     cin>>x;
     if(x==-1)return NULL;
     node* root= new node(x);
     root->left=buildTree();
     root->right =buildTree();
     return root;

     
}

void printTree(node* root){
    if(root==NULL)return;
    cout<<root->d<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}

int main(){
    node * root=buildTree();
    printTree(root);
    return 0;
}