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

node* BuildTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    
    node* root=new node(x);
    root->left=BuildTree();
    root->right=BuildTree();

    return root;

}

void preorder(node* root){
     if(root==NULL){
         return;
     }

     cout<<root->d<<" ";
     preorder(root->left);
     preorder(root->right);
     return;
}
void postorder(node* root){
     if(root==NULL){
         return;
     }

     postorder(root->left);
     postorder(root->right);
     cout<<root->d<<" ";
     return;
}

void inorder(node* root){
     if(root==NULL){
         return;
     }

     inorder(root->left);
     cout<<root->d<<" ";
     inorder(root->right);
     
     return;
}


int main(){

    return 0;
}