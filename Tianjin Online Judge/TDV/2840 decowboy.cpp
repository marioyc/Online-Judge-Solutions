#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int inf = 1 << 29;
 
const int MAXN = 10005, MAXM = 100005, MAXE = MAXM * 2;
int n, m, ne;
int last[MAXN], to[MAXE], next[MAXE], val[MAXN];
int last2[MAXN], to2[MAXE], next2[MAXE], val2[MAXN];
 
int t, vis[MAXN], low[MAXN];
 
int parent[MAXN];
inline int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }
 
void go1(int x, int p) {
  if (vis[x] != -1) return;
  vis[x] = low[x] = t++;
 
  for (int e = last[x]; e != -1; e = next[e]) if (to[e] != p) {
    go1(to[e], x);
    low[x] = min(low[x], low[to[e]]);
  }
 
  if (low[x] < vis[x] && p != -1) parent[x] = find(p);
}
 
int ret;
 
int go2(int x, int p) {
  int sum = val[x];
  for (int e = last2[x]; e != -1; e = next2[e]) if (to2[e] != p) {
    int v = go2(to2[e], x);
    ret = max(v, ret);
    sum += v;
  }
  return sum;
}
 
void solve() {
  memset(last, 255, sizeof(last));
  ne = 0;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a, --b;
    to[ne] = b, next[ne] = last[a], last[a] = ne++;
    to[ne] = a, next[ne] = last[b], last[b] = ne++;
  }
 
    for(int i=0;i<ne;i++) printf("%d %d\n",to[i],next[i]);
    for(int i=0;i<n;i++) printf("%d\n",last[i]);
    
  for (int i = 0; i < n; ++i) scanf("%d", &val[i]);
  for (int i = 0; i < n; ++i) parent[i] = i;
 
  memset(vis, 255, sizeof(vis));
  t = 0;
  go1(0, -1);
 
  memset(last2, 255, sizeof(last2));
  memset(val2, 0, sizeof(val2));
  ne = 0;
 
  ret = -1;
 
  for (int i = 0; i < n; ++i) {
    int p = find(i);
    val2[p] += val[i];
    for (int e = last[i]; e != -1; e = next[e]) if (find(to[e]) != p) {
      to2[ne] = find(to[e]), next2[ne] = last2[p], last2[p] = ne++;
    }
  }
 
  ret = -inf;
  go2(0, -1);
 
  if (ret == -inf) printf("No apple\n");
  else printf("%d\n", ret);
}
 
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
  while (true) {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    solve();
  }
  return 0;
}
