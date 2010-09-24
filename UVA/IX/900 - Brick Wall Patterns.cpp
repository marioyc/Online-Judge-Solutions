#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int F[51];
    
    F[0]=F[1]=1;
    
    for(int i=2;i<=50;i++) F[i]=F[i-1]+F[i-2];
    
    int n;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("%d\n",F[n]);
    }
    
    return 0;
}
