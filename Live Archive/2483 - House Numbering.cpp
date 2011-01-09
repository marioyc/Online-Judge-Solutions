#include <cstdio>

using namespace std;

int main(){
    char s[5];
    int tc = 1,A,B,N;
    
    while(true){
        scanf("%s",s);
        if(s[0]=='#') break;
        
        scanf("%d %d",&A,&B);
        
        printf("Set %d\n",tc++);
        
        while(scanf("%d",&N)==1){
            int ans = 0;
            
            while(N){
                if(N & 1) ans += B;
                else ans += A;
                
                N >>= 1;
            }
            
            printf("%d\n",ans);
        }
    }    
    
    return 0;
}
