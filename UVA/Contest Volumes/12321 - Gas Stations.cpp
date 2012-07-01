#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int L,N;
    pair<int, int> P[10000];
    
    while(true){
        scanf("%d %d",&L,&N);
        
        if(L == 0) break;
        
        for(int i = 0,x,r;i < N;++i){
            scanf("%d %d",&x,&r);
            P[i] = make_pair(x - r,x + r);
        }
        
        sort(P,P + N);
        
        int pos = 0,aux,i = 0,ans = N;
        
        while(pos < L){
            aux = pos;
            
            while(i < N && P[i].first <= pos)
                aux = max(aux,P[i++].second);
            
            if(aux == pos) break;
            
            pos = aux;
            --ans;
        }
        
        printf("%d\n",pos < L? -1 : ans);
    }
    
    return 0;
}
