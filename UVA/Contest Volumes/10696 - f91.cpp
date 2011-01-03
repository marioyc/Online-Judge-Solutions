#include<cstdio>

using namespace std;

int main(){
    int N;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        if(N<=101) printf("f91(%d) = 91\n",N);
        else printf("f91(%d) = %d\n",N,N-10);
    }
    
    return 0;
}
