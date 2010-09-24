#include <cstdio>

using namespace std;

int main(){    
    int t,n,i;
    int S;
    
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        
        S=0;
        
        for(i=1;i*i<n;i++)
            if(n%i==0)
                S+=i+n/i;
        
        if(i*i==n) S+=i;
        S-=n;
        
        printf("%d\n",S);
    }   
    
    return 0;
}
