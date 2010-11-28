#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct segment{
    int L,R;
    
    segment(){}
    
    segment(int _L, int _R){
        L = _L; R = _R;
    }
    
    bool operator < (segment X)const{
        return R<X.R;
    }
}S[100000],ans[100000];

bool comp(segment A, segment B){
    return A.L<B.L;
}

int main(){
    int M,I = 0;
    scanf("%d",&M);
    
    while(scanf("%d %d",&S[I].L,&S[I].R)==2){
        if(S[I].L==0 && S[I].R==0) break;
        ++I;
    }
    
    sort(S,S+I,comp);
    
    int last = 0,pos = 0,sz = 0;
    bool possible = true;
    
    while(last<M && possible){
        priority_queue<segment> Q;
        
        while(pos<I && S[pos].L<=last){
            if(S[pos].R>last)
                Q.push(S[pos]);
            ++pos;
        }
        
        if(Q.empty()) possible = false;
        else{
            segment aux = Q.top();
            
            ans[sz++] = aux;
            last = aux.R;
        }
    }
    
    if(!possible) printf("No solution\n");
    else{
        printf("%d\n",sz);
        for(int i = 0;i<sz;++i)
            printf("%d %d\n",ans[i].L,ans[i].R);
    }
    
    return 0;
}
