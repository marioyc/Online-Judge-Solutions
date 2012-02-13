#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int parent[400],rank[400],comp;

void Init(int N){
    comp = N;
    
    for(int i = 0;i < N;++i){
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int PX = Find(x),PY = Find(y);
    
    if(PX != PY){
        --comp;
        
        if(rank[PX] < rank[PY]) parent[PX] = PY;
        else{
            parent[PY] = PX;
            if(rank[PX] == rank[PY]) ++rank[PX];
        }
    }
}

int main(){
    int R,C,n;
    bool cutL[21][21];
    bool cutD[21][21];
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R == 0 && C == 0) break;
        
        scanf("%d",&n);
        
        memset(cutL,false,sizeof cutL);
        memset(cutD,false,sizeof cutD);
        
        for(int i = 0,x1,y1,x2,y2;i < n;++i){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            
            if(x1 > x2) swap(x1,x2);
            if(y1 > y2) swap(y1,y2);
            
            for(int j = y1;j < y2;++j) cutL[x1][j] = cutL[x2][j] = true;
            for(int j = x1;j < x2;++j) cutD[j][y1] = cutD[j][y2] = true;
        }
        
        Init(R * C);
        
        for(int x = 1;x < C;++x)
            for(int y = 0;y < R;++y)
                if(!cutL[x][y]) Union(x * R + y,(x-1) * R + y);
        
        
        for(int x = 0;x < C;++x)
            for(int y = 1;y < R;++y)
                if(!cutD[x][y]) Union(x * R + y,x*R + (y-1));
        
        printf("%d\n",comp);
    }
    
    return 0;
}
