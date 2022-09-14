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

vector<int> v;

void sibling_nodes_at_dist_k(node* root,int dist){
     if(dist<0||root==NULL)return;
     if(dist==0){
       v.push_back(root->d);
       return;
     }
     sibling_nodes_at_dist_k(root->left,dist-1);
     sibling_nodes_at_dist_k(root->right,dist-1);
     return;
}

void children_at_dist_k(node* root,int dist){
     if(dist<0||root==NULL)return;
     if(dist==0){
       v.push_back(root->d);
       return;
     }
     children_at_dist_k(root->left,dist-1);
     children_at_dist_k(root->right,dist-1);
     return;
}

int all_nodes_at_dist_k(node* root,int key,int dist){
    if(root==NULL)return -1;
    if(root->d==key){
        children_at_dist_k(root,dist);
        return 1;
    }
    int l,r;
    l=all_nodes_at_dist_k(root->left,key,dist);
    r=all_nodes_at_dist_k(root->right,key,dist);
    if(l!=-1&&l<=dist){
        if(dist==l){
          v.push_back(root->d);
          return l+1;
        } 
         sibling_nodes_at_dist_k(root->right,dist-l-1);
         return l+1;
    }
    else if(r!=-1&&r<=dist){
          if(dist==r){
          v.push_back(root->d);
          return r+1;
        } 
         sibling_nodes_at_dist_k(root->left,dist-r-1);
         return r+1;
    }
    else{
      return -1;
    }
    
}





int main(){
  
     node* root=BuildTree();
     int x=7,k=5;
     all_nodes_at_dist_k(root,x,k);
   //  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
   for(auto x:v)cout<<x<<" ";
     return 0;
}