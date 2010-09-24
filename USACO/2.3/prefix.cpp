/*
ID:zion_ba1
LANG:C++
TASK:prefix
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    
    int m=0;
    string s,x;
    string L[200];
    
    while(1){
        getline(cin,x);
        if(x==".") break;
        istringstream is(x);
        while(is>>x) L[m++]=x;
    }
    
    while(getline(cin,x)) s+=x;
    int n=s.size(),ans=0;
    
    bool possible[n+1];
    fill(possible,possible+n+1,false);
    possible[0]=true;
    
    for(int i=1;i<=n;i++){
        bool found=false;
        
        for(int j=0;j<m;j++){
            if(L[j].size()>i || !possible[i-L[j].size()]) continue;
            
            bool check=true;
            
            for(int k=0;k<L[j].size();k++) 
                if(s[i-1-k]!=L[j][L[j].size()-1-k]) check=false;
            
            if(check){
                found=true;
                break;
            }
        }
        
        if(found){
            possible[i]=true;
            ans=i;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
