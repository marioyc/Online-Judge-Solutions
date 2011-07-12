#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,x,y,L,M[101][101];
    char com[6];
    
    scanf("%d",&T);
    memset(M,0,sizeof(M));
    
    while(T--){
        scanf("%s %d %d %d",com,&x,&y,&L);
        
        if(com[0] == 'W'){
            for(int i = 0;i < L;++i)
                for(int j = 0;j < L;++j)
                    M[x+i][y+j] = 0;
        }
        
        if(com[0] == 'B'){
            for(int i = 0;i < L;++i)
                for(int j = 0;j < L;++j)
                    M[x+i][y+j] = 1;
        }
        
        if(com[0] == 'T'){
            int ans = 0;
            
            for(int i = 0;i < L;++i)
                for(int j = 0;j < L;++j)
                    ans += M[x+i][y+j];
            
            printf("%d\n",ans);
        }
    }
}
