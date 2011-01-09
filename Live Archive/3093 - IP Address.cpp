#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    char ip[33];
    
    while(N--){
        scanf("%s",ip);
        
        for(int i = 0;i<4;++i){
            int x = 0;
            
            for(int j = 0;j<8;++j)
                if(ip[8*i+j]=='1')
                    x |= (1<<(7-j));
            
            printf("%d",x);
            if(i<3) putchar('.');
        }
        
        putchar('\n');
    }
    
    return 0;
}
