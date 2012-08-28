#include <cstdio>

using namespace std;

#define MAXN 1000002

long long bit0[MAXN],bit1[MAXN],bit2[MAXN];

void update(long long bit[], int idx, long long val){
    for(int x = idx;x < MAXN;x += x & -x)
        bit[x] += val;
}

long long query(long long bit[], int idx){
    long long ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

long long query(int x){
    return (query(bit0,x) + query(bit1,x) * x + query(bit2,x) * x * x) / 2;
}

void update(long long a, long long b, int v0, int r){
    update(bit0,a,-r * (a - 1) * (a - 1) - ((1 - 2 * a) * r + 2 * v0) * (a - 1));
    update(bit0,b + 1,(2 * v0 + (b + 1 - 2 * a) * r) * b);
    
    update(bit1,a,(1 - 2 * a) * r + 2 * v0);
    update(bit1,b + 1,-(1 - 2 * a) * r - 2 * v0);
    
    update(bit2,a,r);
    update(bit2,b + 1,-r);
}

int main(){
    int Q;
    
    scanf("%d",&Q);
    
    char op[6];
    int arg1,arg2;
    
    while(Q--){
        scanf("%s %d %d",op,&arg1,&arg2);
        
        if(op[0] == 'c') printf("%lld\n",query(arg2) - query(arg1 - 1));
        else{
            update(arg1 - arg2 / 2,arg1,1,1);
            if(arg2 > 1) update(arg1 + 1,arg1 + arg2 / 2,arg2 / 2,-1);
        }
    }
    
    return 0;
}
