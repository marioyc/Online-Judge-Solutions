#include <cstdio>
#include <algorithm>

using namespace std;

int points(char c1, char c2){
    if(c1==c2) return 1;
    if(c1=='S') return (c2=='P'? 2 : 0);
    if(c1=='R') return (c2=='S'? 2 : 0);
    return (c2=='R'? 2 : 0);
}

int main(){
    int R;
    scanf("%d",&R);
    
    char a[R+1];
    scanf("%s",a);
    
    int N;
    scanf("%d",&N);
    
    char b[N][R+1];
    for(int i = 0;i<N;++i) scanf("%s",b[i]);
    
    int sc = 0;
    
    for(int i = 0;i<R;++i)
        for(int j = 0;j<N;++j)
            sc += points(a[i],b[j][i]);
    
    printf("%d\n",sc);
    
    sc = 0;
    
    for(int i = 0;i<R;++i){
        int best = 0,aux;
        
        for(int j = 0;j<N;++j)
            best += points('R',b[j][i]);
        
        aux = 0;
        
        for(int j = 0;j<N;++j)
            aux += points('P',b[j][i]);
        
        best = max(best,aux);
        aux = 0;
        
        for(int j = 0;j<N;++j)
            aux += points('S',b[j][i]);
        
        best = max(best,aux);
        sc += best;
    }
    
    printf("%d\n",sc);
    
    return 0;
}
