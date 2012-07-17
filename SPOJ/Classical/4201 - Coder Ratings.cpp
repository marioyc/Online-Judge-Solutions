#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

struct coder{
    int x,y,id;
    
    coder(){}
    coder(int _x, int _y, int _id) :
        x(_x), y(_y), id(_id){}
    
    bool operator < (coder X)const{
        if(x != X.x) return x < X.x;
        return y < X.y;
    }
}a[300000];

int ans[300000],bit[100001];

void update(int idx){
    for(int x = idx;x <= 100000;x += x & -x)
        ++bit[x];
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].id = i;
    }
    
    sort(a,a + N);
    
    for(int i = 0;i < N;){
        int e = i;
        
        while(e < N && a[e].x == a[i].x && a[e].y == a[i].y) ++e;
        
        for(int j = i;j < e;++j)
            ans[ a[j].id ] = query(a[j].y);
        
        for(int j = i;j < e;++j)
            update(a[j].y);
        
        i = e;
    }
    
    for(int i = 0;i < N;++i)
        printf("%d\n",ans[i]);
    
    return 0;
}
