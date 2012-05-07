#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M[100][100];
int memo1[100][100],memo2[100][100];

// r wins [l,r]
int solver(int l, int r);

int solvel(int l, int r){
    if(l == r) return 1;
    
    int &ret = memo1[l][r];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = l;i < r;++i)
            if(M[r][i])
                for(int j = i;j < r;++j)
                    if(solvel(l,i) && solver(i,j) && solvel(j + 1,r))
                        ret = 1;
    }
    
    return ret;
}

// l wins [l,r]
int solver(int l, int r){
    if(l == r) return 1;
    
    int &ret = memo2[l][r];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = l + 1;i <= r;++i)
            if(M[l][i])
                for(int j = l + 1;j <= i;++j)
                    if(solver(l,j - 1) && solvel(j,i) && solver(i,r))
                        ret = 1;
    }
    
    return ret;
}

int main(){
    int T,N,v[100];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&v[i]);
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                scanf("%d",&M[i][j]);
        
        memset(memo1,-1,sizeof memo1);
        memset(memo2,-1,sizeof memo2);
        int ans = 0;
        
        for(int i = 0;i < N;++i)
            if(solvel(0,i) && solver(i,N - 1))
                ans = max(ans,v[i]);
        
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}
