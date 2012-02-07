#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MOD1 1000000007

const int B = 31;
const int MAXLEN = 30000;
char s[200][MAXLEN + 1];
long long H1[MAXLEN + 1];
long long H3[MAXLEN + 1];

int val(char c){
    if(c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A';
}

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }
  
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
    
        q[tail] = t; ++tail;
        dist[t] = 0;
    
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
  
    int dfs(int v, int f){
        if(v==t) return f;
    
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
        
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
    
        return 0;
    }
  
    long long max_flow(int source, int sink){
        if(sink == source) return 0;
        s = source; t = sink;
        long long f = 0,df;
    
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
      
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
    
        return f;
    }
}G(200,200 * 200);

int a[40000],b[40000],c[40000];
long long pp[200];
long long pow1[MAXLEN + 1],pow2[MAXLEN + 1];

int main(){
    pow1[0] = 1;
    
    for(int j = 1;j <= MAXLEN;++j)
        pow1[j] = pow1[j - 1] * B % MOD1;
    
    int N,M,K;
    
    while(true){
        scanf("%d %d %d",&N,&M,&K);
        
        if(N == 0 && M == 0 && K == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%s",s[i]);
        
        vector< pair<long long, int> > v;
        
        for(int i = 0;i < N;++i){
            int L = strlen(s[i]);
            
            H1[L] = 0;
            
            for(int j = L - 1;j >= 0;--j)
                H1[j] = (H1[j + 1] * B + val(s[i][j])) % MOD1;
            
            H3[0] = 0;
            
            for(int j = 0;j < L;++j)
                H3[j + 1] = (H3[j] * B + val(s[i][j])) % MOD1;
            
            pp[i] = 0;
            
            for(int j = 0;j + 1 < L;++j){
                if(val(s[i][j]) == val(s[i][j + 1])){
                    int lo = 0,hi = min(j,L - 2 - j),mi;
                    
                    while(lo < hi){
                        mi = (lo + hi + 1) >> 1;
                        
                        int h1 = (H1[j - mi] - H1[j + 1] * pow1[mi + 1]) % MOD1;
                        if(h1 < 0) h1 += MOD1;
                        
                        int h3 = (H3[j + 2 + mi] - H3[j + 1] * pow1[mi + 1]) % MOD1;
                        if(h3 < 0) h3 += MOD1;
                        
                        if(h1 != h3) hi = mi - 1;
                        else lo = mi;
                    }
                    
                    pp[i] += (lo + 1) * (lo + 2);
                }
            }
            
            v.push_back(make_pair(pp[i],i));
        }
        
        sort(v.rbegin(),v.rend());
        
        vector<int> cities;
        
        for(int i = 0,j = 0;i < N && j < K;++j){
            int e = i;
            while(e < N && v[e].first == v[i].first) ++e;
            
            for(int k = i;k < e;++k)
                cities.push_back(v[k].second);
            
            i = e;
        }
        
        for(int i = 0;i < M;++i)
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        
        int n = cities.size();
        sort(cities.begin(),cities.end());
        
        printf("%d\n",n);
        
        for(int i = 0;i < n;++i){
            G.clear();
            
            for(int j = 0;j < M;++j)
                G.add_edge(a[j],b[j],c[j]);
            
            printf("%s (%lld) %lld\n",s[cities[i]],pp[cities[i]],G.max_flow(0,cities[i]));
        }
    }
    
    return 0;
}
