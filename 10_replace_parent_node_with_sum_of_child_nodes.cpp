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

int replace_parent_with_children(node* root){
      if(root==NULL)return 0;
      int l=replace_parent_with_children(root->left);
      int r=replace_parent_with_children(root->right);
      int x=root->d;
      if(l+r!=0)root->d=l+r;
      return l+r+x;  // here l+r= current root->d

}

int level(node* root){
    if(root==NULL)return 0;
    int l=level(root->left);
    int r=level(root->right);
    return max(l,r)+1;
}

void print_level(node* root,int level,int crnt){
   if(root==NULL)return ;
   if(crnt==level)cout<<root->d<<" ";
   print_level(root->left,level,crnt+1);
   print_level(root->right,level,crnt+1);
   return;
}

void print_all_level(node* root){
    if(root==NULL)return;
    int ht=level(root);
    for(int i=1;i<=ht;i++){
        print_level(root,i,1);
        cout<<endl;
    }
}

int main(){
    node* root=BuildTree();
    print_all_level(root);
    replace_parent_with_children(root);
    print_all_level(root);
    return 0;
   // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
}