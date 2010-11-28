#include <cstdio>
#include <cstring>

using namespace std;

int N,A[500],B[500],memo[500],choice[500];

int solve(int last){
    int &ret = memo[last];
    
    if(ret==-1){
        ret = 0;
        
        for(int i = 0;i<N;++i){
            if(A[i]<A[last] && B[i]>B[last] && solve(i)>ret){
                ret = solve(i);
                choice[last] = i;
            }
        }
        
        ++ret;
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;++i) scanf("%d %d",&A[i],&B[i]);
    
    int ans = -1,pos = -1;
    memset(memo,-1,sizeof(memo));
    memset(choice,-1,sizeof(choice));
    
    for(int i = 0;i<N;++i){
        int aux = solve(i);
        
        if(aux>ans){
            ans = aux;
            pos = i;
        }
    }
    
    printf("%d\n",ans);
    
    while(pos!=-1){
        printf("%d ",pos+1);
        pos = choice[pos];
    }
    
    putchar('\n');
    
    return 0;
}
