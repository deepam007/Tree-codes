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

int ans=0;

bool lca(node* root,int a,int b){
      if(root==NULL)return false;
      bool l,r;
      l=lca(root->left,a,b);
      r=lca(root->right,a,b);
      if(root->d==a||root->d==b&&(l||r)){
           ans=root->d;
           return true;
      }
      if(root->d==a||root->d==b){
           return true;
      }
      
      if(l&&r)ans=root->d;
      if(l||r)return true;
      return false;
}

int main(){
  
     node* root=BuildTree();
     lca(root,1,7);
     cout<<ans;
  
   //  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 
     return 0;
}