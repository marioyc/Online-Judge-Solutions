#include<cstdio>

using namespace std;

int main(){    
    int n,k,t,cont=0;
    
    scanf("%d %d",&n,&k);
    
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t%k==0) cont++;
    }
    
    printf("%d\n",cont);
    
    return 0;
}
