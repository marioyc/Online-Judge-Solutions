#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int f[13];
    
    f[0]=0;
    f[1]=1;
    
    for(int i=2;i<=12;i++){
        f[i]=INT_MAX;
        
        for(int j=1;j<=i;j++) f[i]=min(f[i],2*f[i-j]+(1<<j)-1);
    }
    
    for(int i=1;i<=12;i++) printf("%d\n",f[i]);
    
    return 0;
}
