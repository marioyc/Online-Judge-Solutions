#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
    int T,N,M,server[100000];
    pair<int,int> P[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 0,t;i < N;++i){
            scanf("%d",&t);
            P[i] = make_pair(t,i);
        }
        
        sort(P,P + N);
        
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;
        
        for(int i = 0;i < M;++i)
            Q.push(make_pair(0,i));
        
        for(int i = N - 1;i >= 0;--i){
            pair<int, int> cur = Q.top();
            Q.pop();
            
            cur.first += P[i].first;
            server[ P[i].second ] = cur.second;
            
            Q.push(cur);
        }
        
        printf("%d\n",N);
        
        for(int i = 0;i < N;++i)
            printf("%d%c",server[i],i == N - 1? '\n' : ' ');
    }
    
    return 0;
}
