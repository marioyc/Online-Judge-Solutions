#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    
    int ans = -1,aux = -1,T[10001];
    
    for(int i = 0;i<K;++i){
        int aux2 = 0;
        memset(T,0,sizeof(T));
        
        for(int j = 0,x;j<N;++j){
            scanf("%d",&x);
            x = N+1-x;
            
            for(int idx = x-1;idx>0;idx -= (idx & -idx)) aux2 += T[idx];
            for(int idx = x;idx<=N;idx += (idx & -idx)) ++T[idx];
        }
        
        if(aux2>aux){
            aux = aux2;
            ans = i+1;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
