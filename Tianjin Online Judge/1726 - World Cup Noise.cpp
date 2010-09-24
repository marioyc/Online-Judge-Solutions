#include<cstdio>

using namespace std;

int main(){    
    int f[45];
    
    f[1]=2;
    f[2]=3;
    
    for(int i=3;i<45;i++) f[i]=f[i-1]+f[i-2];
    
    int T,n;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        printf("Scenario #%d:\n%d\n\n",i,f[n]);
    }
    
    return 0;
}
