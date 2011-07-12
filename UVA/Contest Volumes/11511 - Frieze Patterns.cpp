#include <cstdio>

using namespace std;

int M[1000][1001];

int main(){
    int N,Qr,Qc;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        scanf("%d %d",&Qr,&Qc);
        --Qr; --Qc;
        Qc %= (N + 1);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&M[i][0]);
        
        for(int i = 0;i <= N;++i)
            M[0][i] = M[N-1][i] = 1;
        
        for(int j = 1;j <= N;++j)
            for(int i = 1;i+1 < N;++i)
                M[i][j] = (1 + M[i-1][j] * M[i+1][j-1]) / M[i][j-1];
        
        printf("%d\n",M[Qr][Qc]);
    }
    
    return 0;
}
