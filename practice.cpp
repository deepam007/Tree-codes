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

node* build_tree(){
  int x;
  cin>>x;
  node* root;
  if(x==-1)return NULL;
  root=new node(x);
  root->left=build_tree();
  root->right=build_tree();
  return root;
}

int ans=-1;

bool lca(node* root,int a,int b){
  if(root==NULL)return false;
  if(root->data==a || root->data==b)return true;

  bool lt=lca(root->left,a,b);
  bool rt=lca(root->right,a,b);

  if(lt && rt){
    ans=root->data;
    return true;
  }
  if((lt||rt) && (root->data==a || root->data==b)){
    ans=root->data;
    return true;
  }
   if(rt || lt){
     return true;
   }
   return false;
}

int main(){
    node* root=build_tree();

    static deque<int> dq;
    vector<int> ans;
        
        int lt=0,rt=0;
        dq.push_front(root->data);
        // all_left(root,0);
        // all_right(root,0);
        queue<pair<node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.second>rt)dq.push_back(it.first->data);
            if(it.second<lt)dq.push_front(it.first->data);
            if(it.first->left)q.push({it.first->left,it.second-1});
            if(it.first->right)q.push({it.first->right,it.second+1});
        }
        
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        
       
    return 0;
}