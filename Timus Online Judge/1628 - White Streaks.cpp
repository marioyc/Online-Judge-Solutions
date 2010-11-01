#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> PII;

bool comp1(PII a, PII b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}

bool comp2(PII a, PII b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}

PII cell[180000];

int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i = 0,x,y;i<K;++i){
        scanf("%d %d",&x,&y);
        cell[i] = make_pair(x,y);
    }
    
    for(int i = 1;i<=M;++i){
        cell[K] = make_pair(0,i);
        ++K;
        cell[K] = make_pair(N+1,i);
        ++K;
    }
    
    for(int i = 1;i<=N;++i){
        cell[K] = make_pair(i,0);
        ++K;
        cell[K] = make_pair(i,M+1);
        ++K;
    }
    
    int ans = 0;
    set<PII> S;
    
    sort(cell,cell+K,comp1);
    
    for(int i = 0;i+1<K;++i){
        int diff = cell[i+1].second-cell[i].second;
        if(cell[i].first==cell[i+1].first && diff>=2){
            if(diff==2) S.insert(make_pair(cell[i].first,cell[i].second+1));
            else ++ans;
        }
    }
    
    sort(cell,cell+K,comp2);
    
    for(int i = 0;i+1<K;++i){
        int diff = cell[i+1].first-cell[i].first;
        if(cell[i].second==cell[i+1].second && diff>=2){
            if(diff==2){
                if(S.find(make_pair(cell[i].first+1,cell[i].second))!=S.end())
                    ++ans;
            }else ++ans;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
