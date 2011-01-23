#include <cstdio>

using namespace std;

int main(){
    int T,x[10];
    
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0;i<10;++i) scanf("%d",&x[i]);
        
        int odd = 0;
        
        for(int i = 0;i<10;++i) for(int j = i+1;j<10;++j){
            if(x[i]==1 || x[j]==1)
                odd ^= 1;
            
            for(int k = j+1;k<10;++k)
                if(x[i]==1 || x[j]==1 || x[k]==1)
                    odd ^= 1;
        }
        
        printf("%d\n",odd);
    }
    
    return 0;
}
