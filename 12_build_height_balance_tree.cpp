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

node* build_ht_balance_tree(int* a,int st,int end){
   if(st>end)return NULL;

   int mid=(st+end)/2;
   node* root=new node(a[mid]);
   root->left=build_ht_balance_tree(a,st,mid-1);
   root->right=build_ht_balance_tree(a,mid+1,end);
   return root;

}

int level(node* root){
    if(root==NULL)return 0;
    int l=level(root->left);
    int r=level(root->right);
    return max(l,r)+1;
}

void print_level(node* root,int level,int crnt){
   if(root==NULL)return ;
   if(crnt==level)cout<<root->d<<" ";
   print_level(root->left,level,crnt+1);
   print_level(root->right,level,crnt+1);
   return;
}

void print_all_level(node* root){
    if(root==NULL)return;
    int ht=level(root);
    for(int i=1;i<=ht;i++){
        print_level(root,i,1);
        cout<<endl;
    }
}

int main(){
     int a[]={1,2,3,4,5,6,7};
     node* root=build_ht_balance_tree(a,0,6);
     print_all_level(root);


}