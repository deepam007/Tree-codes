#include<bits/stdc++.h>
using namespace std;

class node{
    public:
      int data;
      node* left;
      node* right;

    node(int d){
        data=d;
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

    queue<pair<node*,int>> q;
    q.push(make_pair(root,1));
    int i=1;
    while(!q.empty()){
        node* temp=q.front().first;
        int x=q.front().second;
        if(x>i){
            cout<<endl;
            i++;
        }
        cout<<temp->data<<" ";
     
        
        q.pop();
        if(temp->left!=NULL)q.push(make_pair(temp->left,x+1));
        
        if(temp->right!=NULL)q.push(make_pair(temp->right,x+1));
        
    }
    return;
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


int main(){

    node* root=BuildTree();
    bfs1(root);
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
    return 0;
}