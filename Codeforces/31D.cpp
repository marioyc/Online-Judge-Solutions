#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int W,H,n;

int id(int r, int c){
    return r * W + c;
}

int parent[10000],cont[10000];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x),y = Find(y);
    
    if(x != y){
        parent[x] = y;
        cont[y] += cont[x];
    }
}

int main(){
    scanf("%d %d %d",&W,&H,&n);
    
    bool cut[W][H][2];
    
    memset(cut,false,sizeof cut);
    
    for(int i = 0,x1,y1,x2,y2;i < n;++i){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        if(x1 == x2){
            if(y2 < y1) swap(y1,y2);
            
            for(int j = y1;j < y2;++j)
                cut[x1][j][0] = true;
        }else{
            if(x2 < x1) swap(x1,x2);
            
            for(int j = x1;j < x2;++j)
                cut[j][y1][1] = true;
        }
    }
    
    for(int i = 0;i < H * W;++i){
        parent[i] = i;
        cont[i] = 1;
    }
    
    for(int x = 1;x < W;++x)
        for(int y = 0;y < H;++y)
            if(!cut[x][y][0])
                Union(id(y,x),id(y,x - 1));
    
    for(int y = 1;y < H;++y)
        for(int x = 0;x < W;++x)
            if(!cut[x][y][1])
                Union(id(y,x),id(y - 1,x));
    
    vector<int> sol;
    
    for(int i = 0;i < H * W;++i)
        if(Find(i) == i)
            sol.push_back(cont[i]);
    
    sort(sol.begin(),sol.end());
    
    for(int i = 0;i < sol.size();++i)
        printf("%d ",sol[i]);
    printf("\n");
    
    return 0;
}
