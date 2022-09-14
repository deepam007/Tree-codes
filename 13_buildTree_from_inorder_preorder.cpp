#include<bits/stdc++.h>
using namespace std;

class node{
   public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }
};

int pos=0;

node* BuildTree_inorder_pre_order(int* pre,int* in,int st,int end){
 //   if(pos>7)return NULL;
    if(st>end)return NULL;
    int idx=-1;
    node* root=new node(pre[pos]);
    for(int i=st;i<=end;i++){
      //  cout<<pre[pos]<<" ";
        if(pre[pos]==in[i]){
            idx=i;
            break;
        }
    }
    pos++;
  //  cout<<"a "<<pos;
    root->left=BuildTree_inorder_pre_order(pre,in,st,idx-1);
    root->right=BuildTree_inorder_pre_order(pre,in,idx+1,end);
    return root;

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
        cout<<root->data<<" ";
        return;
    }
    print_each_level(root->left,level,n+1);
    print_each_level(root->right,level,n+1);
    return;
}

void level_order(node* root){
    if(root==NULL)return;

    int ht=height(root);
  //  cout<<"ht "<<ht<<endl;
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
     int pre[]={1,2,3,4,8,5,6,7};
     int in[]= {3,2,8,4,1,6,7,5};
     int n=sizeof(in)/sizeof(int);
     node* root=BuildTree_inorder_pre_order(pre,in,0,n-1);
     level_order(root);


}