#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_N 1000

bool is_prime[MAX_N+1];

int main(){
    memset(is_prime,true,sizeof(is_prime));    
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2;i<=MAX_N;++i)
        if(is_prime[i])
            for(int j = 2*i;j<=MAX_N;j += i)
                is_prime[j] = false;
    
    int T,p;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&p);
        
        bool valid = true;
        
        if((p&3)==1 && p!=1){
            int r = (int)round(sqrt(p-4));
            
            if(r*r!=p-4 || !is_prime[r]) valid = false;
        }else valid = false;
        
        if(valid) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}
