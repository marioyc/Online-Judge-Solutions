#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N[2],v[2][10000],jump[2][10000],memo[2][10000];
bool done[2][10000];

int solve(int seq, int pos){
    if(pos == N[seq]) return 0;
    
    int &ret = memo[seq][pos];
    
    if(!done[seq][pos]){
        done[seq][pos] = true;
        ret = -100000000;
        
        if(pos + 1 < N[seq]) ret = max(ret,solve(seq,pos+1));
        else ret = 0;
        
        if(jump[seq][pos] != -1) ret = max(ret,solve(1-seq,jump[seq][pos]));
        
        ret += v[seq][pos];
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%d",&N[0]);
        if(N[0] == 0) break;
        for(int i = 0;i < N[0];++i) scanf("%d",&v[0][i]);
        
        scanf("%d",&N[1]);
        for(int i = 0;i < N[1];++i) scanf("%d",&v[1][i]);
        
        memset(jump,-1,sizeof(jump));
        
        for(int i = 0,pos = 0;i < N[0];++i){
            while(pos + 1 < N[1] && v[1][pos] < v[0][i]) ++pos;
            if(v[1][pos] == v[0][i]) jump[0][i] = pos + 1;
        }
        
        for(int i = 0,pos = 0;i < N[1];++i){
            while(pos + 1 < N[0] && v[0][pos] < v[1][i]) ++pos;
            if(v[0][pos] == v[1][i]) jump[1][i] = pos + 1;
        }
        
        memset(done,false,sizeof(done));
        printf("%d\n",max(solve(0,0),solve(1,0)));
    }
    
    return 0;
}
