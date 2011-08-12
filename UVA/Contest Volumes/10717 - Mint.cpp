#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

int main(){
    int n,t,coin[50],leg[10];    
    
    while(true){
        scanf("%d %d",&n,&t);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i) scanf("%d",&coin[i]);
        for(int i = 0;i < t;++i) scanf("%d",&leg[i]);
        
        int L[t],U[t];
        memset(L,-1,sizeof(L));
        memset(U,-1,sizeof(U));
        
        for(int i1 = 0;i1 < n;++i1){
            for(int i2 = i1 + 1;i2 < n;++i2){
                for(int i3 = i2 + 1;i3 < n;++i3){
                    for(int i4 = i3 + 1;i4 < n;++i4){
                        int x = lcm(coin[i1],lcm(coin[i2],lcm(coin[i3],coin[i4])));
                        
                        for(int j = 0;j < t;++j){
                            int L2 = leg[j] / x * x;
                            int U2 = (leg[j] + x - 1) / x * x;
                            
                            if(L[j] == -1 || L2 > L[j])
                                L[j] = L2;
                            
                            if(U[j] == -1 || U2 < U[j])
                                U[j] = U2;
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i < t;++i)
            printf("%d %d\n",L[i],U[i]);
    }
    
    return 0;
}
