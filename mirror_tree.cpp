#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
   public:
     int data;
     node* left;
     node* right;
   node(int x){
       data=x;
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

node* mirror_tree(node* root,node* root1){
       if(root==NULL)return NULL;
       root1=new node(root->data);
       root1->right=mirror_tree(root->left,root1->right);
       root1->left=mirror_tree(root->right,root1->left);
       return root1;
}

void bfs1(node* root){
 
 queue<node*> q;
 q.push(root);
   q.push(NULL);
   while(!q.empty()){
    node* x=q.front();
    if(x==NULL){
     cout<<endl;
     q.pop();
      if(!q.empty()){
       q.push(NULL);
      }
    }
    else{
    cout<<x->data<<" ";
     q.pop();
     if(x->left)q.push(x->left);
     if(x->right)q.push(x->right);
    }
   }
   return;
}

void inorder(node* root){
     if(root==NULL){
         return;
     }

     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
     
     return;
}



int main(){
    node* root=BuildTree();
    node* root1=NULL;
    root1=mirror_tree(root,root1);
    bfs1(root);
    cout<<endl;
    bfs1(root1);
   inorder(root);
   cout<<endl;
   inorder(root1);

    return 0;
}