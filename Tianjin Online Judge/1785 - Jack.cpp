#include<cstdio>
#include<algorithm>

using namespace std;

char map[1000][1001];
int R,C;
int memo[1000][1000];

long long ways(int r, int c){
    if(r==R-1 && c==C-1) return 1;
    
    if(memo[r][c]==-1){
        int aux=0;
        
        if(r!=R-1 && map[r+1][c]!='#') aux+=ways(r+1,c);
        if(c!=C-1 && map[r][c+1]!='#') aux+=ways(r,c+1);
        
        memo[r][c]=aux;
    }
    
    return memo[r][c];
}

int main(){    
    int T;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&R,&C);
        for(int j=0;j<R;j++) scanf("%s",map[j]);
        
        for(int j=0;j<R;j++) fill(memo[j],memo[j]+C,-1);
        printf("Existuje %d ruznych cest.\n",ways(0,0));
    }
    
    return 0;
}
