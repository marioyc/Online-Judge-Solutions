#include <cstdio>

using namespace std;

int main(){
    int s,d,aux,ans;
    bool valid;
    
    while(scanf("%d %d",&s,&d)==2){
        ans = -1;
        
        for(int mask=0;mask<(1<<12);++mask){
            valid = true;
            
            for(int i=0;i<8;++i){
                aux = 0;
                
                for(int j=0;j<5;++j){
                    if(mask & (1<<(i+j))) aux += s;
                    else aux -= d;
                }
                
                if(aux>=0) valid = false;
            }
            
            if(!valid) continue;
            
            aux = 0;
            
            for(int i=0;i<12;++i){
                if(mask & (1<<i)) aux += s;
                else aux -= d;
            }
            
            if(aux>ans) ans = aux;
        }
        
        if(ans<0) printf("Deficit\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
