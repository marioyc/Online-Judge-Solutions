#include <cstdio>
#include <cstring>

using namespace std;

int memo[10][82];

int solve(int D, int S){
    if(S<0) return 0;
    if(D==0) return (S==0? 1 : 0);
    
    int &ret = memo[D][S];
    
    if(ret==-1){
        ret = 0;
        
        for(int i = 0;i<=9;++i)
            ret += solve(D-1,S-i);
    }
    
    return ret;
}

int main(){
    int S;
    scanf("%d",&S);
    
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(9,S)+(S==1? 1 : 0));
    
    return 0;
}
