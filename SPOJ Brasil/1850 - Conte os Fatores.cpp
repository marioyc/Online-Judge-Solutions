#include <cstdio>

using namespace std;

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        int ans = 0,aux = N;
        
        for(int i = 2;i<=N/i;++i){
            if(N%i==0){
                while(N%i==0) N /= i;
                ++ans;
            }
        }
        
        if(N!=1) ++ans;
        
        printf("%d : %d\n",aux,ans);
    }
    
    return 0;
}
