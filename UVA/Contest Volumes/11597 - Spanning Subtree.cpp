#include <cstdio>

using namespace std;

int main(){
    int T=1,N;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        N=N>>1;
        printf("Case %d: %d\n",T++,N);
    }
    
    return 0;
}
