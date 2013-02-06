#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 100005

bool used[MAXN];

int main(){
    int n;
    
    scanf("%d",&n);
    
    priority_queue< pair<int, int> > Q[2];
    int r[2];
    
    for(int i = 0,c,val;i < n;++i){
        scanf("%d %d",&c,&val);
        Q[c].push(make_pair(-val,i));
        r[c] = i;
    }
    
    for(int i = 0;i < n - 1 && !Q[0].empty() && !Q[1].empty();++i){
        pair<int, int> cur0 = Q[0].top(),cur1 = Q[1].top();
        Q[0].pop(); Q[1].pop();
        printf("%d %d ",1 + cur0.second,1 + cur1.second);
        used[cur0.second] = used[cur1.second] = true;
        
        if(cur0.first >= cur1.first){
            Q[1].push(make_pair(cur1.first - cur0.first,cur1.second));
            printf("%d\n",-cur0.first);
        }else{
            Q[0].push(make_pair(cur0.first - cur1.first,cur0.second));
            printf("%d\n",-cur1.first);
        }
    }
    
    for(int c = 0;c <= 1;++c){
        while(!Q[c].empty()){
            pair<int, int> cur = Q[c].top();
            Q[c].pop();
            if(!used[cur.second])
                printf("%d %d %d\n",1 + cur.second,1 + r[c ^ 1],0);
        }
    }
    
    return 0;
}
