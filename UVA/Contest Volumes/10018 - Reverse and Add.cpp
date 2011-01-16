#include <cstdio>
#include <cstring>

using namespace std;

long long reversed(long long n){
    long long ret = 0;
    
    while(n){
        ret = ret*10+n%10;
        n /= 10;
    }
    
    return ret;
}

int d[10];

bool isPalindrome(long long n){
    int sz = 0;
    
    while(n){
        d[sz++] = n%10;
        n /= 10;
    }
    
    for(int i = 0;i<sz-1-i;++i)
        if(d[i]!=d[sz-1-i])
            return false;
    
    return true;
}

int main(){
    int T,it;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&N);
        
        it = 0;
        
        while(!isPalindrome(N)){
            N += reversed(N);
            ++it;
        }
        
        printf("%d %lld\n",it,N);
    }
    
    return 0;
}
