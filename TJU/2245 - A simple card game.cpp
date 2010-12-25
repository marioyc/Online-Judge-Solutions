#include <cstdio>
#include <cstring>
 
using namespace std;
 
bool found[1000001];
 
int main(){
    int N,M;
    
    while(scanf("%d %d",&N,&M)==2){
        
        memset(found,false,sizeof(found));
        
        found[0] = true;
        
        for(int i = 0,a;i<N;++i){
            scanf("%d",&a);
            
            for(int j = 0;j+a<=M;++j)
                found[j+a] |= found[j];
        }
        
        if(!found[M]) puts("impossible");
        else{
            int pos = 0;
            for(int i = 1;i<=M;++i) pos += found[i];
            printf("%d\n",pos);
        }
    }
    
    return 0;
}


