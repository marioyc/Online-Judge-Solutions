#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    unsigned long long a,b;
    
    while(scanf("%llu %llu",&a,&b) == 2){
        unsigned long long l = ceil(sqrt(a) / 2);
        unsigned long long r = floor((sqrt(b + 1) - 1) / 2);
        unsigned long long ans = 0;
        
        if((2*l + 1) * (2*l + 1) - 1 <= b)
            ans += (r - l) * (2*r + 2*l + 1) + 2*r + 2*l + 1;
        
        if(l > 0 && (2*l - 1) * (2*l - 1) - 1 >= b) ans = b - a + 1;
        else{
            if(l > 0 && (2*l - 1) * (2*l - 1) - 1 >= a)
                ans += (2*l - 1) * (2*l - 1) - max(a,4 * (l - 1) * (l - 1));
            
            ++r;
            
            if(4*r*r <= b)
                ans += min(b,(2*r + 1) * (2*r + 1)) - 4*r*r + 1;
        }
        
        printf("%llu\n",ans);
    }
    
    return 0;
}


