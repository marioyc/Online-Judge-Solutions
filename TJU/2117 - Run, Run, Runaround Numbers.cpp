#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vals;
int D,M,dig[7];
bool used[10];

void search(int n, int last){
    int next = (last+dig[last])%D;
    
    if(n==0 && next!=0) return;
    if(n!=0 && dig[next]!=0) return;
    
    if(n==0){
        int aux = 0;
        for(int i = 0;i<D;++i) aux = aux*10+dig[i];
        vals.push_back(aux);
        return;
    }
    
    for(int i = 1;i<=9;++i){
        if(used[i]) continue;
        
        used[i] = true;
        dig[next] = i;
        
        search(n-1,next);
        
        used[i] = false;
        dig[next] = 0;
    }
}

void init(){
    memset(used,false,sizeof(used));
    memset(dig,0,sizeof(dig));
    
    for(D = 2;D<=8;++D){
        for(int d = 1;d<=9;++d){
            used[d] = true;
            dig[0] = d;
            
            search(D-1,0);
            
            used[d] = false;
        }
    }
    
    M = vals.size();
    sort(vals.begin(),vals.end());
}

int solve(int n){
    int lo = 0,hi = M-1,mi;
    
    while(lo<hi){
        mi = (lo+hi)>>1;
        
        if(vals[mi]<n) lo = mi+1;
        else hi = mi;
    }
    
    return vals[lo];
}

int main(){
    init();
    
    for(int tc = 1,n;;++tc){
        scanf("%d",&n);
        if(n==0) break;
        printf("Case %d: %d\n",tc,solve(n));
    }
    
    return 0;
}
