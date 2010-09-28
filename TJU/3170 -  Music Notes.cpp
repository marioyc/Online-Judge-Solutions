#include <cstdio>

using namespace std;

int main(){
    int N,Q;    
    scanf("%d %d",&N,&Q);
    
    int T[N],t;
    for(int i=0;i<N;i++) scanf("%d",&T[i]);
    
    int S[N+1];
    S[0]=0;
    for(int i=0;i<N;i++) S[i+1]=S[i]+T[i];
    
    int lo,hi,mi;
    
    for(int i=0;i<Q;i++){
        scanf("%d",&t);
        
        lo=0;hi=N-1;
        
        while(lo!=hi){
            mi=(lo+hi+1)/2;
            
            if(t>=S[mi+1]) lo=mi+1;
            else if(t<S[mi])  hi=mi-1;
            else lo=hi=mi;
        }
        
        printf("%d\n",lo+1);
    }
    
    return 0;
}
