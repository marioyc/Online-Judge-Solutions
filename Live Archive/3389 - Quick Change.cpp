#include <cstdio>

using namespace std;

int main(){
    int Q[501],D[501],N[501],P[501];
    
    for(int i = 1;i<=500;++i){
        P[i] = i%5;
        int x = i/5;
        
        Q[i] = 0; D[i] = 0; N[i] = x;
        
        for(int j = x/5;j>=0;--j){
            for(int k = (x-5*j)/2;k>=0;--k){
                if(j+k+(x-5*j-2*k)<Q[i]+D[i]+N[i]){
                    Q[i] = j;
                    D[i] = k;
                    N[i] = x-5*j-2*k;
                }
            }
        }
    }
    
    int T,C;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d",&C);
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",tc,Q[C],D[C],N[C],P[C]);
    }
    
    return 0;
}
