#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        printf("%d\n",N*(N+1)/2*(2*N+1)/3);
    }
    
    return 0;
}
