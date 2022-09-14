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

    if(x==-1)return NULL;

    node* root=new node(x);
    root->left=BuildTree();
    root->right=BuildTree();
    
    return root;
}

void bfs(node* root){
    if(root==NULL)return;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->d<<" ";
        q.pop();
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
    return;
}

int main(){

    node* root=BuildTree();
    bfs(root);
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
    return 0;
}