#include<cstdio>

using namespace std;

int main(){    
    int T,f,a,b,c;
    long long sum;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&f);
        
        sum=0;
        
        for(int j=0;j<f;j++){
            scanf("%d %d %d",&a,&b,&c);
            sum+=(long long)a*c;
        }
        
        printf("%lld\n",sum);
    }
    
    return 0;
}
