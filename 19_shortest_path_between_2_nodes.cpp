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

int shortest_dist_btwn_two_nodes(node* root,int a,int b){
    if(root==NULL)return 0;
    int l=shortest_dist_btwn_two_nodes(root->left,a,b);
    int r=shortest_dist_btwn_two_nodes(root->right,a,b);
    cout<<root->d<<" "<<l<<" "<<r<<endl;
    if(root->d==a||root->d==b&&(l>0||r>0)){
        ans=max(l,r);
        return l+1;
    }
    if(root->d==a||root->d==b){
        return 1;
    }
    if(l>0&&r>0){
        ans=l+r;
        return l+1;
    }
    if(l>0)return l+1;
    else if(r>0)return r+1;
    return 0;
}

int main(){
  
     node* root=BuildTree();
     shortest_dist_btwn_two_nodes(root,9,10);
     cout<<ans;
   //  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
   //  1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
 
     return 0;
}