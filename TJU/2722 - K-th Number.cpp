#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 100000

int a[maxn],b[18][maxn];

void merge(int depth, int l, int r){
    if(l == r) b[depth][l] = a[l];
    else{
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

struct node{
    int depth,l,r;
    
    node(){}
    node(int _depth, int _l, int _r):
        depth(_depth), l(_l), r(_r){}
};

vector<node> vq;

void query(int depth, int l, int r, int x, int y){
    if(y < l || x > r) return;
    if(x <= l && r <= y) vq.push_back(node(depth,l,r));
    else{
        int mi = (l + r) >> 1;
        query(depth + 1,l,mi,x,y);
        query(depth + 1,mi + 1,r,x,y);
    }
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    merge(0,0,n - 1);
    sort(a,a + n);
    
    int l,r,k;
    
    while(m--){
        scanf("%d %d %d",&l,&r,&k);
        --l; --r;
        
        vq.clear();
        query(0,0,n - 1,l,r);
        
        int lo = 0,hi = n - 1,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            int x = a[mi],cont = 0;
            
            for(int i = vq.size() - 1;i >= 0;--i){
                int lo2 = vq[i].l,hi2 = vq[i].r,mi2;
                
                while(lo2 < hi2){
                    mi2 = (lo2 + hi2 + 1) >> 1;
                    
                    if(b[ vq[i].depth ][mi2] > x) hi2 = mi2 - 1;
                    else lo2 = mi2;
                }
                
                if(b[ vq[i].depth ][lo2] <= x)
                    cont += lo2 - vq[i].l + 1;
            }
            
            if(cont < k) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",a[lo]);
    }
    
    return 0;
}
