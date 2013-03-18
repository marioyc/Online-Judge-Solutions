#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXQ 200000

int N,a[MAXN];
int b[18][MAXN],bit[18][MAXN];

void update(int T[], int idx){
    for(int x = idx;x <= MAXN;x += x & -x)
        ++T[x];
}

int query(int T[], int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += T[x];
    
    return ret;
}

void merge(int depth, int l, int r){
    if(l == r){
        b[depth][l] = a[l];
    }else{
        int mi = (l + r) >> 1;
        
        merge(depth + 1,l,mi);
        merge(depth + 1,mi + 1,r);
        
        int pos1 = l,pos2 = mi + 1,pos = l;
        
        while(pos1 <= mi && pos2 <= r){
            if(b[depth + 1][pos1] < b[depth + 1][pos2])
                b[depth][pos++] = b[depth + 1][pos1++];
            else
                b[depth][pos++] = b[depth + 1][pos2++];
        }
        
        while(pos1 <= mi)
            b[depth][pos++] = b[depth + 1][pos1++];
        
        while(pos2 <= r)
            b[depth][pos++] = b[depth + 1][pos2++];
    }
}

void update(int depth, int l, int r, int x, int val){
    int lo = l,hi = r,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(b[depth][mi] < val) lo = mi + 1;
        else hi = mi;
    }
    
    update(bit[depth],lo + 1);
    
    if(l != r){
        mi = (l + r) >> 1;
        
        if(x <= mi) update(depth + 1,l,mi,x,val);
        else update(depth + 1,mi + 1,r,x,val);
    }
}

char s[10];
int tipo[MAXQ],op[MAXQ][3],ans[MAXQ];

struct node{
    int depth,l,r;
    
    node(){}
    node(int _depth, int _l, int _r):
        depth(_depth), l(_l), r(_r){}
};

vector<node> vq;

void query(int depth, int l, int r, int x, int y){
    if(r < x || l > y) return;
    
    if(x <= l && r <= y) vq.push_back(node(depth,l,r));
    else{
        int mi = (l + r) >> 1;
        
        query(depth + 1,l,mi,x,y);
        query(depth + 1,mi + 1,r,x,y);
    }
}

int main(){
    int tc = 1,Q;
    long long ans1,ans2,ans3;
    
    while(scanf("%d",&Q) == 1){
        N = 0;
        
        for(int i = 0;i < Q;++i){
            scanf("%s",s);
            
            if(s[0] == 'I'){
                scanf("%d",&op[i][0]);
                tipo[i] = 0;
                a[N++] = op[i][0];
            }else if(s[6] == '1'){
                tipo[i] = 1;
                scanf("%d %d %d",&op[i][0],&op[i][1],&op[i][2]);
            }else if(s[6] == '2'){
                tipo[i] = 2;
                scanf("%d",&op[i][0]);
            }else{
                tipo[i] = 3;
                scanf("%d",&op[i][0]);
            }
        }
        
        merge(0,0,N - 1);
        sort(a,a + N);
        ans1 = ans2 = ans3 = 0;
        memset(bit,0,sizeof bit);
        
        for(int i = 0,posa = 0,pos;i < Q;++i){
            if(tipo[i] == 0){
                int pos = lower_bound(a,a + N,op[i][0]) - a;
                update(0,0,N - 1,posa++,op[i][0]);
            }else if(tipo[i] == 1){
                vq.clear();
                query(0,0,N - 1,op[i][0] - 1,op[i][1] - 1);
                
                int lo = 0,hi = N - 1,mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    int cur = a[mi],cont = 0;
                    
                    for(int j = vq.size() - 1;j >= 0;--j){
                        int lo2 = vq[j].l,hi2 = vq[j].r,mi2;
                        
                        while(lo2 < hi2){
                            mi2 = (lo2 + hi2 + 1) >> 1;
                            
                            if(b[ vq[j].depth ][mi2] > cur) hi2 = mi2 - 1;
                            else lo2 = mi2;
                        }
                        
                        if(b[ vq[j].depth ][lo2] <= cur)
                            cont += query(bit[ vq[j].depth ],lo2 + 1) - query(bit[ vq[j].depth ],vq[j].l);
                    }
                    
                    if(cont < op[i][2]) lo = mi + 1;
                    else hi = mi;
                }
                
                ans1 += a[lo];
            }else if(tipo[i] == 2){
                int cur = lower_bound(a,a + N,op[i][0]) - a;
                
                ans2 += query(bit[0], cur + 1);
            }else{
                int K = op[i][0],lo = 0,hi = N - 1,mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    if(query(bit[0], mi + 1) < K) lo = mi + 1;
                    else hi = mi;
                }
                
                ans3 += a[lo];
            }
        }
        
        printf("Case %d:\n%lld\n%lld\n%lld\n",tc++,ans1,ans2,ans3);
    }
    
    return 0;
}
