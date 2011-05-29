#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int grundy[10001];
    grundy[0] = grundy[1] = 0;
    
    bool found[10001];
    
    for(int i = 2;i <= 10000;++i){
        memset(found,false,sizeof(found));
        
        for(int j = 0;j <= i-2;++j)
            found[grundy[j] ^ grundy[i-2-j]] = true;
        
        for(int j = 0;j <= 10001;++j){
            if(!found[j]){
                grundy[i] = j;
                break;
            }
        }
    }
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        if(grundy[N] == 0) puts("Bhima");
        else puts("Arjuna");
    }
    
    return 0;
}
