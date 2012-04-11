#include <cstdio>
#include <algorithm>

using namespace std;

#define LIM 2000000000LL

int main(){
    int a,fa,b,fb,n;
    
    scanf("%d %d %d %d %d",&a,&fa,&b,&fb,&n);
    
    if(b < a){
        swap(a,b);
        swap(fa,fb);
    }
    
    long long lo = -LIM,hi = LIM,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        bool neg = false,pos = false;
        int x = fa,y = mi,z;
        
        for(int i = a + 2;i <= b;++i){
            if(x > LIM - y){
                pos = true;
                break;
            }
            
            if(x < -LIM - y){
                neg = true;
                break;
            }
            
            z = x + y;
            x = y;
            y = z;
        }
        
        if(!neg && !pos){
            if(y < fb) lo = mi + 1;
            else hi = mi;
        }else if(neg) lo = mi + 1;
        else hi = mi;
    }
    
    int x = fa,y = lo,z;
    
    if(n >= a + 1){
        for(int i = a + 2;i <= n;++i){
            z = x + y;
            x = y;
            y = z;
        }
        
        printf("%d\n",y);
    }else{
        for(int i = a - 1;i >= n;--i){
            z = y - x;
            y = x;
            x = z;
        }
        
        printf("%d\n",x);
    }
    
    return 0;
}
