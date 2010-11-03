#include <cstdio>

using namespace std;

int survivor(int n, int k){
    int s,i;
    for (s=0,i=1;i<=n;++i) s = (s + k) % i;
    return s;
}

int main(){
    int n,k,m;
    
    while(true){
        scanf("%d %d %d",&n,&k,&m);
        if(n==0 && k==0 && m==0) break;
        printf("%d\n",1+((m-k+survivor(n,k))%n+n)%n);
    }
    
    return 0;
}
