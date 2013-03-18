#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define MAXN 200005

int sz = 0;
long long bit[MAXN + 1],sum[MAXN + 1];
int a[MAXN + 1],b[MAXN + 1];

void update(int idx, long long add){
    for(int x = idx;x <= MAXN;x += x & -x)
        bit[x] += add;
}

long long query(int idx){
    long long ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    sz = 1;
    a[0] = 0;
    
    for(int i = 0;i < n;++i){
        int t;
        
        scanf("%d",&t);
        
        if(t == 1){
            int pos,x;
            scanf("%d %d",&pos,&x);
            b[pos] += x;
            update(pos,x * pos);
        }else if(t == 2){
            scanf("%d",&a[sz]);
            ++sz;
            sum[sz] = sum[sz - 1] + a[sz - 1];
        }else{
            long long cur = b[sz];
            update(sz,-cur * sz);
            b[sz] = 0;
            --sz;
            if(sz){
                update(sz,cur * sz);
                b[sz] += cur;
            }
        }
        
        printf("%.8f\n",(double)(query(sz) + sum[sz]) / sz);
    }
    
    return 0;
}
