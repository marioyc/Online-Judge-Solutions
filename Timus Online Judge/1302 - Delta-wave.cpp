#include <cstdio>
#include <algorithm>

using namespace std;

int get_row(int n){
    for(int i = 1;i <= 31623;++i)
        if(n <= i*i) return i; 
    
    return -1;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    if(n > m) swap(n,m);
    
    int r1 = get_row(n),r2 = get_row(m);
    
    n -= (r1-1) * (r1-1) + r1;
    m -= (r2-1) * (r2-1) + r2;
    
    int ans = 0;
    
    while(r1 < r2){
        if((r1-n) % 2 != 0){
            ++r1;
            ++ans;
        }else{
            if(n > m){
                --n;
                ++ans;
            }else if(n < m){
                ++n;
                ++ans;
            }else{
                while(r1 < r2){
                    ++r1;
                    ans += 3;
                    
                    if(r1 < r2){
                        ++r1;
                        ++ans;
                    }
                }
            }
        }
    }
    
    if(n < m) ans += m-n;
    else ans += n-m;
    
    printf("%d\n",ans);
    
    return 0;
}
