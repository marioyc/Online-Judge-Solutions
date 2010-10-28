#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    bool have[65536];
    memset(have,false,sizeof(have));
    
    int N;
    scanf("%d",&N);
    
    for(int i = 0,x;i<N;++i){
        scanf("%d",&x);
        have[x+32768] = true;
    }
    
    scanf("%d",&N);
    
    bool found = false;
    
    for(int i = 0,x;i<N;++i){
        scanf("%d",&x);
        x = 42768-x;
        
        if(x>=0 && x<65536 && have[x])
            found = true;
    }
    
    if(found) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
