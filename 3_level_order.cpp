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

void inorder(node* root){
     if(root==NULL){
         return;
     }

     inorder(root->left);
     cout<<root->d<<" ";
     inorder(root->right);
     
     return;
}

int height(node* root){
   if(root==NULL) return 0;
   int l=height(root->left);
   int r=height(root->right);
   return max(l,r)+1;

}

void print_each_level(node* root,int level,int n){
    if(root==NULL)return;
    if(n==level){
        cout<<root->d<<" ";
        return;
    }
    print_each_level(root->left,level,n+1);
    print_each_level(root->right,level,n+1);
    return;
}

void level_order(node* root){
    if(root==NULL)return;

    int ht=height(root);
    cout<<"ht "<<ht<<endl;
    if(ht==0){
        cout<<"empty tree";
        return;
    }

    for(int i=1;i<=ht;i++){
        print_each_level(root,i,1);
        cout<<endl;
    }

    return;
}



int main(){

    node* root=BuildTree();
   // inorder(root);
    level_order(root);
    
    return 0;
}