#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,L,C;
    int len[1000];
    char s[71];
    
    while(scanf("%d %d %d",&N,&L,&C) == 3){
        for(int i = 0;i < N;++i){
            scanf("%s",s);
            len[i] = strlen(s);
        }
        
        int ans = 1;
        
        for(int i = 0,cont = 0;i < N;++i){
            if(cont + len[i] + 1 <= C + 1) cont += len[i] + 1;
            else{
                cont = len[i] + 1;
                ++ans;
            }
        }
        
        printf("%d\n",(ans + L - 1) / L);
    }
    
    return 0;
}
