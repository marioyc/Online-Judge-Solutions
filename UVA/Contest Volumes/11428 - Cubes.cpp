#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,x[10001],y[10001];
    bool done[10001];
    
    memset(done,false,sizeof(done));
    
    for(int i = 1;i <= 57;++i){
        int j = 1;
        
        while((n = 3*i*i*j + 3*i*j*j + j*j*j) <= 10000){
            if(!done[n]){
                y[n] = i;
                x[n] = i + j;
                done[n] = true;
            }
            
            ++j;
        }
    }
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        if(!done[n]) puts("No solution");
        else printf("%d %d\n",x[n],y[n]);
    }
    
    return 0;
}
