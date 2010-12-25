#include <cstdio>
#include <cstring>
 
using namespace std;
 
int P[100],C[500],memo[100][50001];
 
int solve(int n, int h){
    if(n<0) return -2;
    if(h<=0) return 0;
    
    int &ret = memo[n][h];
    
    if(ret==-1){
        ret = solve(n-1,h);
        int aux = solve(n,h-P[n]);
        
        if(aux>=0 && (ret<0 || C[n]+aux<ret))
            ret = C[n]+aux;
    }
    
    return ret;
}
 
int main(){
    int N,H;
    scanf("%d %d",&N,&H);
    
    for(int i = 0;i<N;++i)
        scanf("%d %d",&P[i],&C[i]);
    
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(N-1,H));
    
    return 0;
}
