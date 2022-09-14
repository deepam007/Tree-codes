#include<bits/stdc++.h>
using namespace std;


int findDuplicate(vector<int>& v) {
        int n=0;
        for(int i=0;i<v.size();i++){
            n=n|v[i];
        }
      //  cout<<n<<" ";
        int cnt=0;
        while(n>0){
            if(n&1){
                int x=1<<cnt;
               // cout<<x<<" ";
               int ans;
                for(int i=0;i<v.size();i++){
                    if(v[i]&x){
                       ans=v[i];
                        continue;
                    }
                    
                } 
                cout<<endl;
            }
            cnt++;
            n=n>>1;
        }
        return n;
    }


int main(){
   vector<int> v{1,3,4,2,2};
   findDuplicate(v);
    
    return 0;
}