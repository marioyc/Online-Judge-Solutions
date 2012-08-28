#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[101];

int solve(int n, int have){
    if(n == -1) return 2 * max(0,have);
    
    if(a[n] == -1) return solve(n - 1,have);
    
    if(have == n){
        int aux = a[n];
        if(n > 0) aux += 2;
        
        return aux + solve(n - 1,n - 1);
    }
    
    return 2 + solve(n,have - 1);
}

int main(){
    int tc = 1,n,x;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = n;i >= 0;--i)
            scanf("%d",&a[i]);
        
        scanf("%d",&x);
        
        int ans1 = 0;
        
        if(x == 1){
            for(int i = 0;i <= n;++i)
                ans1 += a[i];
        }else{
            for(int i = 0;i <= n;++i){
                if(i & 1) ans1 -= a[i];
                else ans1 += a[i];
            }
        }
        
        int ans2 = 1;
        if(a[n] == 1) ans2 = -1;
        
        for(int i = 0;i <= n;++i){
            if(i < n && a[i] > 0) ++ans2;
            
            if(a[i] == 0) a[i] = -1;
            else{
                int aux = a[i];
                a[i] = 0;
                
                while(aux){
                    aux /= 10;
                    ++a[i];
                }
            }
        }
        
        ans2 += solve(n,n);
        
        printf("Polynomial %d: %d %d\n",tc++,ans1,ans2);
    }
    
    return 0;
}
