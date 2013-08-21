#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int cont[10],sum = 0;
    memset(cont,0,sizeof cont);
    
    for(int i = 0,d;i < n;++i){
        scanf("%d",&d);
        ++cont[d];
        sum = (sum + d) % 3;
    }
    
    if(cont[0] == 0) printf("-1\n");
    else{
        --cont[0];
        bool ok = false;
        
        if(sum != 0){
            for(int i = 1;i < 10 && !ok;++i){
                if(cont[i] && i % 3 == sum){
                    ok = true;
                    --cont[i];
                }
            }
            
            for(int i = 1;i < 10 && !ok;++i){
                for(int j = 1;j < i && !ok;++j){
                    if(cont[i] && cont[j] && (i + j) % 3 == sum){
                        ok = true;
                        --cont[i];
                        --cont[j];
                    }
                }
                
                if(cont[i] >= 2 && 2 * i % 3 == sum){
                    ok = true;
                    cont[i] -= 2;
                }
            }
        }else ok = true;
        
        if(ok){
            bool zero = true;
            
            for(int i = 9;i > 0;--i)
                if(cont[i]) zero = false;
            
            if(!zero){
                for(int i = 9;i >= 0;--i)
                    for(int j = cont[i];j >= 1;--j)
                        printf("%d",i);
            }
            
            printf("0\n");
        }else printf("-1\n");
    }
    
    return 0;
}
