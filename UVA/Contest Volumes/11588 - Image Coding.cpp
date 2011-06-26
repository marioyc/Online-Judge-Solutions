#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,R,C,M,N,cont[26];
    char I[21];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d %d",&R,&C,&M,&N);
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i < R;++i){
            scanf("%s",I);
            for(int j = 0;j < C;++j) ++cont[I[j]-'A'];
        }
        
        int max = 0,imp = 0;
        
        for(int i = 0;i < 26;++i){
            if(cont[i] > max){
                max = cont[i];
                imp = 1;
            }else if(cont[i] == max){
                ++imp;
            }
        }
        
        printf("Case %d: %d\n",tc,M * max * imp + N * (R * C - max * imp));
    }
    
    return 0;
}
