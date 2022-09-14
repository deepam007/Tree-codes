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

int max_path_sum(node* root){
    if(root==NULL)return 0;
    int l=max_path_sum(root->left);
    int r=max_path_sum(root->right);
    if(l+root->d>ans)ans=l+root->d;
    if(r+root->d>ans)ans=r+root->d;
    if(root->d>ans)ans=root->d;
    if(l+r+root->d>ans)ans=l+r+root->d;
    if(max(l,r)+root->d>0)return max(l,r)+root->d;
    return 0;
}

int main(){
  
     node* root=BuildTree();
     max_path_sum(root);
     cout<<ans;
   //  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 
     return 0;
}