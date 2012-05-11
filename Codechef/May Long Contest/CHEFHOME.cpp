#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &x){
    int n = x.size(),m = 0;
    vector<int> cont;
    
    sort(x.begin(),x.end());
    
    for(int i = 0;i < n;){
        int e = i;
        
        while(e < n && x[e] == x[i]) ++e;
        
        x[m++] = x[i];
        cont.push_back(e - i);
        i = e;
    }
    
    int nl = 0,nr = n;
    long long aux = 0,best = 0;
    int x1 = x[0],x2 = x[0];
    
    for(int i = 0;i < m;++i){
        if(aux < best){
            best = aux;
            x1 = x2 = x[i];
        }else if(aux == best) x2 = x[i];
        
        nl += cont[i];
        nr -= cont[i];
        if(i + 1 < m) aux += (long long)(x[i + 1] - x[i]) * (nl - nr);
    }
    
    return x2 - x1 + 1;
}

int main(){
    int T,N;
    vector<int> X,Y;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        X.clear(); Y.clear();
        
        for(int i = 0,x,y;i < N;++i){
            scanf("%d %d",&x,&y);
            X.push_back(x);
            Y.push_back(y);
        }
        
        printf("%lld\n",(long long)solve(X) * solve(Y));
    }
    
    return 0;
}
