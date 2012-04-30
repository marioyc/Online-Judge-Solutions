#include <cstdio>
#include <cstring>

using namespace std;

bool is_prime(int n){
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n / i;++i)
        if(n % i == 0) return false;
    
    return true;
}

int n,m,d,a[1000];
bool found,prime[10000],used[1001];

bool check(int pos){
    int sum = a[pos - 1];
    
    for(int i = 2;i <= d && pos >= i;++i){
        sum += a[pos - i];
        if(prime[sum]) return false;
    }
    
    return true;
}

void search(int pos){
    if(pos < 2 || check(pos)){
        if(pos == m - n + 1) found = true;
        else{
            for(int i = n;i <= m;++i){
                if(!used[i]){
                    a[pos] = i;
                    used[i] = true;
                    
                    search(pos + 1);
                    if(found) break;
                    
                    used[i] = false;
                }
            }
        }
    }
}

int main(){
    for(int i = 2;i < 10000;++i)
        prime[i] = is_prime(i);
    
    while(true){
        scanf("%d %d %d",&n,&m,&d);
        if(n == 0) break;
        
        found = false;
        memset(used,false,sizeof used);
        
        search(0);
        
        if(!found) puts("No anti-prime sequence exists.");
        else{
            for(int i = 0;i < m - n + 1;++i){
                if(i > 0) putchar(',');
                printf("%d",a[i]);
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
