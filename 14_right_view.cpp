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


void right_view(node* root){
   vector<int> v;
 queue<node*> q;
 q.push(root);
   q.push(NULL);
   while(!q.empty()){
    node* x=q.front();
    if(x==NULL){
    // cout<<endl;
     q.pop();
      if(!q.empty()){
       q.push(NULL);
      }
    }
    else{
   // cout<<x->d<<" ";
     q.pop();
     if(q.front()==NULL)v.push_back(x->d);
     if(x->left)q.push(x->left);
     if(x->right)q.push(x->right);
    }
   }
   cout<<v.size()<<endl;
   for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
   return;
}


int main(){
     
     node* root=BuildTree();
     right_view(root);
   //  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
     return 0;
}