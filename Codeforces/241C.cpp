#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXLEN 100000
#define MAXN 100

int id[2][MAXLEN];
int v[MAXN];
bool hit[MAXN];

int main(){
    int hl,hr,n;
    char c[2];
    
    scanf("%d %d %d",&hl,&hr,&n);
    
    memset(id,-1,sizeof id);
    
    for(int i = 0,l,r;i < n;++i){
        scanf("%d %s %d %d",&v[i],c,&l,&r);
        
        int ind = (c[0] == 'T'? 0 : 1);
        
        for(int j = l;j < r;++j)
            id[ind][j] = i;
    }
    
    int y1 = hl,y2;
    int ans = 0;
    
    for(int i = 1;i <= 100;++i){
        if(i & 1) y2 = -100 * (i - 1) - hr;
        else y2 = -100 * i + hr;
        
        bool ok = true;
        memset(hit,false,sizeof hit);
        int aux = 0;
        
        for(int j = 0,ind = 1;j < i;++j,ind ^= 1){
            int y = -100 * j;
            
            int x = (int)floor((y - hl) * 100000.0 / (y2 - y1));
            
            if(id[ind][x] == -1) ok = false;
            else if(hit[ id[ind][x] ]) ok = false;
            else{
                hit[ id[ind][x] ] = true;
                aux += v[ id[ind][x] ];
            }
        }
        
        if(ok) ans = max(ans,aux);
    }
    
    for(int i = 1;i <= 100;++i){
        if(i & 1) y2 = 100 * (i + 1) - hr;
        else y2 = 100 * i + hr;
        
        bool ok = true;
        memset(hit,false,sizeof hit);
        int aux = 0;
        
        for(int j = 0,ind = 0;j < i;++j,ind ^= 1){
            int y = 100 * (j + 1);
            
            int x = (int)floor((y - hl) * 100000.0 / (y2 - y1));
            
            if(id[ind][x] == -1) ok = false;
            else if(hit[ id[ind][x] ]) ok = false;
            else{
                hit[ id[ind][x] ] = true;
                aux += v[ id[ind][x] ];
            }
        }
        
        if(ok) ans = max(ans,aux);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
