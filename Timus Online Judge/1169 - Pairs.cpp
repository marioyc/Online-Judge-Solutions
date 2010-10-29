#include <cstdio>
#include <cstring>

using namespace std;

int Q1[495000],Q2[495000],head,tail;
int take[101][4951];

void solve(int N, int K){
    memset(take,-1,sizeof(take));
    
    Q1[0] = 0; Q2[0] = 0;
    take[0][0] = -2;
    head = 0; tail = 1;
    
    while(head<tail){
        int n = Q1[head], k = Q2[head];
        ++head;
        
        for(int i = 1;n+i<=N && k+i*n<=K;++i){
            if(i==2) continue;
            int n2 = n+i, k2 = k+i*n;
            
            if(take[n2][k2]==-1){
                take[n2][k2] = i;
                if(n2==N && k2==K) return;
                
                Q1[tail] = n2; Q2[tail] = k2;
                ++tail;
            }
        }
    }
    
    return;
} 

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    
    solve(N,K);
    
    if(take[N][K]==-1) printf("-1\n");
    else{
        int nV[100],sz = 0;
        
        while(N!=0 || K!=0){
            nV[sz] = take[N][K];
            N -= nV[sz];
            K -= nV[sz]*N;
            ++sz;
        }
        
        for(int i = sz-1,s = 1;i>=0;--i){
            for(int j = 0;j<nV[i];++j)
                for(int k = j+1;k<nV[i];++k)
                    printf("%d %d\n",s+j,s+k);
            
            if(i>0) printf("%d %d\n",s+nV[i]-1,s+nV[i]);
            s += nV[i];
        }
    }
    
    return 0;
}
