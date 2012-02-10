#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int N,M,cont[(1 << 15)],p[(1 << 16)],val[(1 << 16)],lvl[(1 << 16)];
    
    while(true){
        scanf("%d %d",&N,&M);
        
        if(N == 0 && M == 0) break;
        
        memset(cont,0,sizeof cont);
        
        for(int i = 0,x;i < M;++i){
            scanf("%d",&x);
            ++cont[x];
        }
        
        priority_queue< pair<int, int> > Q;
        
        for(int i = (1 << N) - 1;i >= 0;--i)
            Q.push(make_pair(-cont[i],i));
        
        for(int i = (1 << N) - 2,id = (1 << N);i >= 0;--i,id++){
            pair<int, int> P1 = Q.top();
            Q.pop();
            pair<int, int> P2 = Q.top();
            Q.pop();
            
            p[P1.second] = id;
            p[P2.second] = id;
            val[P1.second] = 0;
            val[P2.second] = 1;
            
            Q.push(make_pair(P1.first + P2.first,id));
        }
        
        lvl[(1 << (N + 1)) - 2] = 0;
        
        for(int i = (1 << (N + 1)) - 3;i >= 0;--i)
            lvl[i] = 1 + lvl[ p[i] ];
        
        int ans = 0;
        
        for(int i = (1 << N) - 1;i >= 0;--i)
            ans += cont[i] * lvl[i];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
