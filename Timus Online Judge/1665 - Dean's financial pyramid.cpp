#include <cstdio>

using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    
    for(int i = 3;i<=n/i;i += 2)
        if(n%i==0) return false;
    
    return true;
}

bool isPossible(int n){
    bool even = true;
    
    while((n & 1)==0){
        n>>=1;
        even ^= 1;
    }
    
    if(even && n==1) return false;
    if(!even && isPrime(n)) return false;
    
    return true;
}

int main(){
    int T,N;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        if(isPossible(N)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
