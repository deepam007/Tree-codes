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

int sum_of_nodes(node* root){

    if(root==NULL)return 0;

    int l=sum_of_nodes(root->left);
    int r=sum_of_nodes(root->right);
    return (l+r+root->d);
}

int main(){
    node* root=BuildTree();
    cout<<sum_of_nodes(root);
    return 0;
   // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
}