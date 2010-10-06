#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string s1,s2;
int memo[51][51];

int solve(int a, int b){
    if(a==-1 || b==-1) return a+b+2;
    
    int &ret = memo[a][b];
    if(ret!=-1) return ret;
    
    if(s1[a]==s2[b]) ret = solve(a-1,b-1);
    else ret = 1+min(solve(a,b-1),solve(a-1,b));
    
    return ret;
}

int main(){
    int T,N1,N2;
    
    cin>>T;
    getline(cin,s1);
    
    for(int tc = 1;tc<=T;++tc){
        getline(cin,s1);
        getline(cin,s2);
        
        N1 = s1.size(); N2 = s2.size();
        
        cout<<"Case #"<<tc<<":  ";
        
        if(s1.empty() || s2.empty()) cout<<N1+N2<<endl;
        else{
            memset(memo,-1,sizeof(memo));
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            cout<<solve(N1-1,N2-1)<<endl;
        }
    }
    
    return 0;
}
