#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector< vector<int> > S;

int memo[200];
bool U[200];

int solve(int v){
    if(memo[v] != -1) return memo[v];
    
    int aux1=0,aux2=1;
    bool b1=true,b2=true;
    
    for(int i=S[v].size()-1;i>=0;i--){
        aux1+=solve(S[v][i]);
        b1=b1 && U[S[v][i]];
    }
    
    for(int i=S[v].size()-1;i>=0;i--)
        for(int j=S[S[v][i]].size()-1;j>=0;j--){
            aux2+=solve(S[S[v][i]][j]);
            b2=b2 && U[S[S[v][i]][j]];
        }
    
    if(aux1==aux2){
        memo[v]=aux1;
        U[v]=false;
    }else{
        if(aux1>aux2){
            memo[v]=aux1;
            U[v]=b1;
        }else{
            memo[v]=aux2;
            U[v]=b2;
        }
    }
    return memo[v];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    
    map<string, int> M;    
    string s1,s2;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        S.clear();
        S.resize(n);
        M.clear();
        
        cin>>s1; M[s1]=0;
        
        int next=1;
        
        for(int i=1;i<n;i++){
            cin>>s1>>s2;
            
            if(M.find(s1)==M.end()) M[s1]=next++;
            if(M.find(s2)==M.end()) M[s2]=next++;
            
            S[M[s2]].push_back(M[s1]);
        }
        
        memset(memo,-1,sizeof(memo));
        memset(U,true,sizeof(U));
        
        cout<<solve(0)<<" ";
        
        if(U[0]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
