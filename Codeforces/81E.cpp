#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 100005

int s[MAXN],h[MAXN];
vector<int> L[MAXN],path;
bool visited[MAXN],done[MAXN],in_cycle[MAXN];
vector< vector<int> > C;

void dfs(int cur, int curh, int p){
    visited[cur] = true;
    h[cur] = curh;
    path.push_back(cur);
    
    bool back = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(!visited[to]) dfs(to,curh + 1,cur);
        else if((to != p || (to == p && !back)) && !done[to]){
            vector<int> c;
            
            for(int i = h[to];i <= curh;++i){
                in_cycle[ path[i] ] = true;
                c.push_back(path[i]);
            }
            
            C.push_back(c);
        }
        
        if(to == p) back = false;
    }
    
    done[cur] = true;
    path.pop_back();
}

pair<int, int> operator + (pair<int, int> a, pair<int, int> b){
    return make_pair(a.first + b.first,a.second + b.second);
}

pair<int, int> operator - (pair<int, int> a, pair<int, int> b){
    return make_pair(a.first - b.first,a.second - b.second);
}

pair<int, int> memo[MAXN][2];
bool solved[MAXN][2];
int choice[MAXN][2];

pair<int, int> solve(int cur, int take, int p){
    pair<int, int> &ret = memo[cur][take];
    
    if(!solved[cur][take]){
        solved[cur][take] = true;
        ret = make_pair(0,0);
        pair<int, int> aux(0,0);
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(to != p && !in_cycle[to])
                aux = aux + solve(to,1,cur);
        }
        
        ret = aux;
        choice[cur][take] = -1;
        
        if(take == 1){
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                
                if(to != p && !in_cycle[to]){
                    pair<int, int> tmp = aux - solve(to,1,cur) + solve(to,0,cur) + make_pair(1,(s[cur] != s[to]? 1 : 0));
                    
                    if(tmp > ret){
                        ret = tmp;
                        choice[cur][take] = to;
                    }
                }
            }
        }
    }
    
    return ret;
}

int a[MAXN],b[MAXN];
pair<int, int> dp[MAXN],dp2[MAXN];
bool choose[MAXN],choose2[MAXN];
vector< pair<int, int> > sol;

void search(int cur, int take, int p){
    if(choice[cur][take] == -1){
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(to != p && !in_cycle[to])
                search(to,1,cur);
        }
    }else{
        sol.push_back(make_pair(cur, choice[cur][take]));
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(to != p && !in_cycle[to])
                search(to,to == choice[cur][take]? 0 : 1,cur);
        }
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1,bf;i <= n;++i){
        scanf("%d %d",&bf,&s[i]);
        
        L[i].push_back(bf);
        L[bf].push_back(i);
    }
    
    for(int i = 1;i <= n;++i)
        if(!visited[i]) dfs(i,0,0);
    
    memset(solved,false,sizeof solved);
    
    pair<int, int> ans = make_pair(0,0);
    
    for(int i = C.size() - 1;i >= 0;--i){
        int ncycle = C[i].size();
        
        if(ncycle == 2){
            pair<int, int> aux1 = make_pair(1,s[ C[i][0] ] != s[ C[i][1] ]? 1 : 0) + solve(C[i][0],0,0) + solve(C[i][1],0,0);
            pair<int, int> aux2 = solve(C[i][0],1,0) + solve(C[i][1],1,0);
            
            if(aux1 > aux2){
                sol.push_back(make_pair(C[i][0],C[i][1]));
                search(C[i][0],0,0);
                search(C[i][1],0,0);
                ans = ans + aux1;
            }else{
                search(C[i][0],1,0);
                search(C[i][1],1,0);
                ans = ans + aux2;
            }
        }else{
            int m = ncycle;
            
            for(int j = ncycle - 1;j >= 0;--j)
                a[j] = C[i][j];
            
            dp[0] = solve(a[0],1,0);
            choose[0] = false;
            
            for(int j = 1;j < m;++j){
                pair<int, int> aux1 = dp[j - 1] + solve(a[j],1,0);
                pair<int, int> aux2 = make_pair(1,s[ a[j] ] != s[ a[j - 1] ]? 1 : 0) + solve(a[j],0,0) + solve(a[j - 1],0,0) + (j >= 2? dp[j - 2] : make_pair(0,0));
                
                if(aux1 > aux2){
                    choose[j] = false;
                    dp[j] = aux1;
                }else{
                    choose[j] = true;
                    dp[j] = aux2;
                }
            }
            
            int m2 = ncycle - 2;
            
            for(int j = ncycle - 2;j >= 1;--j)
                b[j - 1] = C[i][j];
            
            pair<int, int> aux = make_pair(1,s[ a[0] ] != s[ a[m - 1] ]? 1 : 0) + solve(a[0],0,0) + solve(a[m - 1],0,0);
            dp2[0] = solve(b[0],1,0);
            choose2[0] = false;
            
            for(int j = 1;j < m2;++j){
                pair<int, int> aux1 = dp2[j - 1] + solve(b[j],1,0);
                pair<int, int> aux2 = make_pair(1,s[ b[j] ] != s[ b[j - 1] ]? 1 : 0) + solve(b[j],0,0) + solve(b[j - 1],0,0) + (j >= 2? dp2[j - 2] : make_pair(0,0));
                
                if(aux1 > aux2){
                    choose2[j] = false;
                    dp2[j] = aux1;
                }else{
                    choose2[j] = true;
                    dp2[j] = aux2;
                }
            }
            
            if(dp[m - 1] > aux + dp2[m2 - 1]){
                int pos = m - 1;
                
                while(pos >= 0){
                    if(choose[pos]){
                        sol.push_back(make_pair(a[pos],a[pos - 1]));
                        search(a[pos],0,0);
                        search(a[pos - 1],0,0);
                        pos -= 2;
                    }else{
                        search(a[pos],1,0);
                        --pos;
                    }
                }
                
                ans = ans + dp[m - 1];
            }else{
                int pos = m2 - 1;
                
                sol.push_back(make_pair(a[0],a[m - 1]));
                search(a[0],0,0);
                search(a[m - 1],0,0);
                
                while(pos >= 0){
                    if(choose2[pos]){
                        sol.push_back(make_pair(b[pos],b[pos - 1]));
                        search(b[pos],0,0);
                        search(b[pos - 1],0,0);
                        pos -= 2;
                    }else{
                        search(b[pos],1,0);
                        --pos;
                    }
                }
                
                ans = ans + aux + dp2[m2 - 1];
            }
        }
    }
    
    printf("%d %d\n",ans.first,ans.second);
    
    for(int i = 0;i < ans.first;++i)
        printf("%d %d\n",sol[i].first,sol[i].second);
    
    return 0;
}
