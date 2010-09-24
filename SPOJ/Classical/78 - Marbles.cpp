#include <cstdio>

using namespace std;

long long C(int n, int m){
    if(m>n-m) m=n-m;
    
    long long ans=1;
    
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    
    return ans;
}

int main(){
    int T,n,k;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&k);
        printf("%lld\n",C(n-1,k-1));
    }
    
    return 0;
}
