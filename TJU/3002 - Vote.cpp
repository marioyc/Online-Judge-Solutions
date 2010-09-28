#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N,n,sum;
    int a[101];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        sort(a,a+N);
        
        n=(N+2)/2;
        sum=0;
        for(int i=0;i<n;i++) sum+=(a[i]+2)/2;
        
        printf("%d",sum);
    }
    
    return 0;
}
