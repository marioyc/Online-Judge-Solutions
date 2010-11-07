#include <cstdio>

using namespace std;

int main(){
    int T,M,K;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&K,&M);
        
        if(M>K) printf("0\n");
        else printf("%.6f\n",1-(double)M/(K+1));
    }
    
    return 0;
}
