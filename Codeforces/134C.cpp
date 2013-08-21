#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

priority_queue< pair<int, int> > Q;

int main(){
    int n,s;
    
    scanf("%d %d",&n,&s);
    
    int p = 0;
    
    for(int i = 0,a;i < n;++i){
        scanf("%d",&a);
        Q.push(make_pair(a,i + 1));
    }
    
    if(p == 1) puts("No");
    else{
        vector< pair<int, int> > sol;
        bool ok = true;
        
        while(!Q.empty()){
            pair<int, int> cur = Q.top();
            Q.pop();
            vector< pair<int, int> > out;
            
            while(cur.first > 0 && !Q.empty()){
                pair<int, int> to = Q.top();
                Q.pop();
                --cur.first; --to.first;
                out.push_back(to);
                sol.push_back(make_pair(cur.second,to.second));
            }
            
            if(cur.first){
                ok = false;
                break;
            }
            
            while(!out.empty()){
                Q.push(out.back());
                out.pop_back();
            }
        }
        
        if(!ok) puts("No");
        else{
            puts("Yes");
            
            int m = s / 2;
            printf("%d\n",m);
            
            for(int i = 0;i < m;++i)
                printf("%d %d\n",sol[i].first,sol[i].second);
        }
    }
    
    return 0;
}
