#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int H,N,a[100001],aux;
    a[0] = 0;
    
    while(true){
        scanf("%d %d",&H,&N);
        if(H==0) break;
        
        for(int i=1;i<=N;++i) scanf("%d",&a[i]);
        sort(a+1,a+N+1);
        
        aux = 0;
        for(int i=N;i>0;i-=2) aux ^= (a[i]-a[i-1]-1);
        
        printf("%s\n",aux==0? "Lose":"Win"); 
    }
    
    return 0;
}
