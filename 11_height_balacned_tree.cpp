#include<bits/stdc++.h>
using namespace std;

class node{
   public:
    int d;
    node* left;
    node* right;

    node(int data){
        d=data;
        right=NULL;
        left=NULL;
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

pair<bool,int> height_balacne_tree(node* root){
    if(root==NULL)return {true,0};
    pair<bool,int> l,r;
    l=height_balacne_tree(root->left);
    r=height_balacne_tree(root->right);
    if(abs(l.second-r.second)<=1&&l.first&&r.first)
       return {true,max(l.second,r.second)+1};

       return {false,max(l.second,r.second)+1};

}

int main(){
    

    node* root=BuildTree();
    pair<bool,int> p=height_balacne_tree(root);
    cout<<p.first;
  // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    return 0;
}
