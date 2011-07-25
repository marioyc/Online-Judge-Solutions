#include <cstdio>

using namespace std;

int main(){
    int N,s[10001];
    
    scanf("%d",&N);
    
    s[0] = 0;
    
    for(int i = 0,k;i < N;++i){
        scanf("%d",&k);
        s[i+1] = s[i] + k;
    }
    
    int Q,l,r;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",s[r] - s[l-1]);
    }
    
    return 0;
}
