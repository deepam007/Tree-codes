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
int max_=0;
int diameter(node* root){
    if(root==NULL)return 0;
    int depth_lt=diameter(root->left);
    int depth_rt=diameter(root->right);
    if(depth_lt+1+depth_rt>max_)max_=depth_lt+1+depth_rt;
    return max(depth_lt,depth_rt)+1;
}

int main(){
    node* root=BuildTree();
    diameter(root);
    cout<<max_;
    return 0;
   // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
}