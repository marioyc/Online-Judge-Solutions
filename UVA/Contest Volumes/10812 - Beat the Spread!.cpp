#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,s,d;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&s,&d);
        
        if(s<d || s%2!=d%2) puts("impossible");
        else{
            int a = (s+d)>>1;
            int b = (s-d)>>1;
            
            printf("%d %d\n",a,b);
        }
    }
    
    return 0;
}
