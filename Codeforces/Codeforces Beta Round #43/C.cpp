#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    char s[1001];
    scanf("%s",s);
    
    int T = 0,H = 0;
    
    for(int i = 0;i<N;++i){
        if(s[i]=='H') ++H;
        else ++T;
    }
    
    int ans = -1;
    
    for(int i = 0;i<N;++i){
        int aux1 = 0,aux2 = 0,cont1 = 0,cont2 = 0;
        
        for(int j = 0;j<T;++j)
            if(s[(i+j)%N]=='H')
                ++aux1;
        
        
        for(int j = 0;j<H;++j)
            if(s[(i+j)%N]=='T')
                ++aux2;
        
        int aux = min(aux1,aux2);
        if(ans==-1 || aux<ans) ans = aux;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
