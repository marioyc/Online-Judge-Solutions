#include <cstdio>
#include <vector>

using namespace std;

bool is_lucky(int n){
    int cont = 0;
    
    for(int i = 2;i <= n / i;++i){
        if(n % i == 0){
            ++cont;
            
            while(n % i == 0)
                n /= i;
        }
    }
    
    if(n > 1) ++cont;
    
    return cont >= 3;
}

int main(){
    vector<int> L;
    
    for(int i = 1,j = 1;i <= 2664;++i)
        if(is_lucky(i))
            L.push_back(i);
    
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        --n;
        
        printf("%d\n",L[n]);
    }
    
    return 0;
}
