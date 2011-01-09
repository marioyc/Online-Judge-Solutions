#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> P1, pair<int, int> P2){
    return P1.first<P2.first;
}

int main(){
    int N,C,K,freq[101];
    pair<int, int> P[100];
    
    while(true){
        scanf("%d %d %d",&N,&C,&K);
        if(N==0) break;
        
        for(int i = 0;i<K;++i){
            P[i].second = i+1;
            P[i].first = 0;
        }
        
        for(int i = 0,x;i<N;++i){
            for(int j = 0;j<C;++j){
                scanf("%d",&x);
                ++P[--x].first;
            }
        }
        
        stable_sort(P,P+K);
        
        for(int i = 0;i<K && P[i].first==P[0].first;++i){
            if(i>0) putchar(' ');
            printf("%d",P[i].second);
        }
        
        putchar('\n');
    }
    
    return 0;
}
