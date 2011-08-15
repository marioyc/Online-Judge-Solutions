#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    long long M,N;
    char s[21];
    
    while(true){
        scanf("%lld %lld",&M,&N);
        if(M == -1) break;
        
        int K1 = (20 * M) / N,K2 = (20 * M + N - 1) / N;
        int P1 = (100 * M) / N,P2 = (100 * M + N - 1) / N;
        
        int K = (N * (K1 + K2) <= 40 * M? K2 : K1);
        int P = (N * (P1 + P2) <= 200 * M? P2 : P1);
        
        memset(s,0,sizeof(s));
        for(int i = 0;i < K;++i) s[i] = '*';
        for(int i = K;i < 20;++i) s[i] = '-';
        
        int d1 = P / 10,d2 = P % 10;
        
        if(P < 10){
            s[9] = '0' + d2;
            s[10] = '%';
        }else if(P < 100){
            s[9] = '0' + d1;
            s[10] = '0' + d2;
            s[11] = '%';
        }else{
            s[8] = '1';
            s[9] = '0';
            s[10] = '0';
            s[11] = '%';
        }
        
        puts(s);
    }
    
    return 0;
}
