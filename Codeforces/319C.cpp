#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100005

int n,a[MAXN],b[MAXN];

struct line{
    long long m,b;
    
    line(){}
    
    line(long long _m, long long _b):
        m(_m),b(_b){}
};

line H[MAXN];
int pos,sz;

bool check(line &l1, line &l2, line &l3){
    return (double)(l3.b - l1.b) / (l1.m - l3.m) < (double)(l3.b - l2.b) / (l2.m - l3.m);
}

void insert(line l){
    while(sz >= 2 && !check(H[sz - 2],H[sz - 1],l)){
        if(pos == sz - 1) --pos;
        --sz;
    }
    
    H[sz++] = l;
}

#define INF 1000000000000000000LL

long long eval(int ind, int x){
    return min(INF,H[ind].m * x + H[ind].b);
}

long long query(int x){
    while(pos + 1 < sz && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0;i < n;++i)
        cin >> a[i];
    
    for(int i = 0;i < n;++i)
        cin >> b[i];
    
    long long ans = 0;
    sz = pos = 0;
    insert(line(b[0],0));
    
    for(int i = 1;i < n;++i){
        ans = min(INF,query(a[i]));
        insert(line(b[i],ans));
    }
    
    cout << ans << endl;
    
    return 0;
}
