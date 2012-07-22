#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    long long n;
    
    scanf("%lld",&n);
    
    n *= 6;
    
    vector<int> va,vb;
    int m = 0;
    
    for(int l = min(n,66943LL);l >= 1;--l){
        if(n % l == 0){
            int a = 6;
            long long b = 6 * l + 6;
            long long c = 2LL * l * l + 3 * l + 1 - n / l;
            long long D = b * b - 4 * a * c;
            
            if(D >= 0){
                long long D2 = (long long)round(sqrt(D));
                
                if(D2 * D2 == D && D2 >= b && (D2 - b) % (2 * a) == 0){
                    int y = (-b + D2) / 2 / a;
                    
                    va.push_back(y + 1);
                    vb.push_back(y + l);
                    ++m;
                }
            }
        }
    }
    
    printf("%d\n",m);
    
    for(int i = 0;i < m;++i){
        int a = va[i],b = vb[i];
        
        printf("%d",b - a + 1);
        
        for(int j = a;j <= b;++j)
            printf(" %d",j);
        
        printf("\n");
    }
    
    return 0;
}
