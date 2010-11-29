#include <cstdio>
#include <algorithm>

using namespace std;

long long solve(long long n){
    long long ans = 0;
    
    for(int i = 30;i>=0 && n!=0;--i){
        if(n & (1<<i)){
            if(n==(1<<i)) ans += (1<<i)-i-1;
            else ans += (1<<i)-2;
            n -= (1<<i);
        }
    }
    
    return ans;
}

int main(){
    long long A,B;
    scanf("%lld %lld",&A,&B);
    
    if(A>B) swap(A,B);
    
    printf("%lld\n",solve(B)-solve(A));
    
    return 0;
}
