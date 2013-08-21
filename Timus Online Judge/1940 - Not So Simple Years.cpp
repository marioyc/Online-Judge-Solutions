#include <cstdio>

using namespace std;

bool is_prime(int n){
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n / i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int np = 0,p[70];

int solve(int pos, int l, int r){
    if(pos == np || p[pos] > r) return r - l;
    else if(l == r) return 0;
    else return solve(pos + 1,l,r) - solve(pos + 1,l / p[pos],r / p[pos]);
}

int main(){
    int A,B,k;
    
    scanf("%d %d %d",&A,&B,&k);
    
    for(int i = 2;i <= k + 1;++i)
        if(is_prime(i))
         p[np++] = i;
    
    int ans = solve(0,A,A + B);
    
    for(int i = 0;i < np;++i)
        if(p[i] > A && p[i] <= A + B)
            ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
