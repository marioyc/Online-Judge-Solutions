#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100005

struct edge{
    int to,w;
    edge(){}
    edge(int _to, int _w):
        to(_to), w(_w){}
};

vector<edge> L[MAXN];

int p[17][MAXN];
int pw[17][MAXN];
long long d[MAXN];
int h[MAXN];

void dfs(int cur, int parent){
    p[0][cur] = parent;

    for(auto e : L[cur]){
        if(e.to != parent){
            pw[0][e.to] = e.w;
            d[e.to] = d[cur] + e.w;
            h[e.to] = h[cur] + 1;
            dfs(e.to,cur);
        }
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    int diff = h[u] - h[v];
    for(int i = 0;i <= 16;++i){
        if(diff >> i & 1){
            u = p[i][u];
        }
    }

    if(u == v) return u;

    for(int i = 16;i >= 0;--i){
        if(p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    }

    return p[0][u];
}

int maxw(int u, int v){
    int x = lca(u,v),ret = 0;

    int du = h[u] - h[x],dv = h[v] - h[x];

    for(int i = 0;i <= 16;++i){
        if(du >> i & 1){
            ret = max(ret,pw[i][u]);
            u = p[i][u];
        }
    }

    for(int i = 0;i <= 16;++i){
        if(dv >> i & 1){
            ret = max(ret,pw[i][v]);
            v = p[i][v];
        }
    }

    return ret;
}

bool in_path(int u, int v, int x){
    int w = lca(u,v);
    return ((lca(u,x) == x && lca(x,w) == w) || (lca(v,x) == x && lca(x,w) == w));
}

long long dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u,v)];
}

int main(){
    int n,q;

    scanf("%d %d",&n,&q);

    for(int i = 1,u,v,w;i < n;++i){
        scanf("%d %d %d",&u,&v,&w);
        L[u].push_back(edge(v,w));
        L[v].push_back(edge(u,w));
    }

    dfs(1,0);

    for(int i = 1;i <= 16;++i){
        for(int j = 1;j <= n;++j){
            p[i][j] = p[i - 1][ p[i - 1][j] ];
            pw[i][j] = max(pw[i - 1][j],pw[i - 1][ p[i - 1][j] ]);
        }
    }

    int path1[2],path2[2];
    long long t1,t2;

    while(q--){
        scanf("%d %d %lld %d %d %lld",&path1[0],&path1[1],&t1,&path2[0],&path2[1],&t2);
        int s1 = -1,e1 = -1,s2 = -1,e2 = -1;
        long long mind1,maxd1,mind2,maxd2;

        for(int i = 0;i < 2;++i){
            for(int j = 0;j < 2;++j){
                int x = lca(path1[i],path2[j]);

                if(in_path(path1[0],path1[1],x) && in_path(path2[0],path2[1],x)){
                    long long d1 = dist(path1[0],x),d2 = dist(path2[0],x);
                    if(s1 == -1 || d1 < mind1) s1 = x, mind1 = d1;
                    if(e1 == -1 || d1 > maxd1) e1 = x, maxd1 = d1;
                    if(s2 == -1 || d2 < mind2) s2 = x, mind2 = d2;
                    if(e2 == -1 || d2 > maxd2) e2 = x, maxd2 = d2;
                }
            }
        }


        if(s1 == -1 || s1 == e1){
            printf("NO\n");
        }else{
            t1 += mind1;
            t2 += mind2;

            if(s1 == s2){
                if(abs(t1 - t2) < maxw(s1,e1)) printf("YES\n");
                else printf("NO\n");
            }else{
                long long L = dist(s1,e1);

                if(abs(t1 - t2) > L) printf("NO\n");
                else{
                    long long t = L + t1 + t2;

                    if(t & 1) printf("YES\n");
                    else{
                        t /= 2;
                        bool cross = true;
                        int w = lca(s1,e1),cur = s1;

                        for(int i = 16;i >= 0;--i){
                            int to = p[i][cur];
                            if(dist(s1,to) <= t - t1 && h[to] >= h[w]) cur = to;
                        }

                        if(dist(s1,cur) == t - t1) cross = false;

                        cur = e1;

                        for(int i = 16;i >= 0;--i){
                            int to = p[i][cur];
                            if(dist(s1,to) >= t - t1 && h[to] >= h[w]) cur = to;
                        }

                        if(dist(s1,cur) == t - t1) cross = false;

                        if(cross) printf("YES\n");
                        else printf("NO\n");
                    }
                }
            }
        }
    }

    return 0;
}
