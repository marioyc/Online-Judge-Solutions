#include <cstdio>

using namespace std;

#define N 30000

int parent[N],cont[N],top[N];

int Find(int x){
    if(parent[x] != x){
        int p = Find(parent[x]);
        top[x] += top[ parent[x] ];
        parent[x] = p;
    }
    
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        parent[y] = x;
        top[y] = cont[x];
        cont[x] += cont[y];
    }
}

int main(){
    int P,x,y;
    char s[2];
    
    for(int i = 0;i < N;++i){
        parent[i] = i;
        cont[i] = 1;
        top[i] = 0;
    }
    
    scanf("%d",&P);
    
    for(int p = 0;p < P;++p){
        scanf("%s",s);
        
        if(s[0] == 'M'){
            scanf("%d %d",&x,&y);
            Union(x,y);
        }else{
            scanf("%d",&x);
            
            int p = Find(x);
            
            printf("%d\n",cont[p] - 1 - top[x]);
        }
    }
    
    return 0;
}
