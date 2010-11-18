/*
    N = a + (a+1) + ... + (a+b)
    N = (b+1)*a + b*(b+1)/2
*/

#include <cstdio>

using namespace std;

int main(){
    int T,P,N;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&P,&N);
        
        int ans = 0;
        
        for(int b = 1;b*(b+1)/2<N;++b){
            int aux = N-b*(b+1)/2;
            if(aux%(b+1)==0) ++ans;
        }
        
        printf("%d %d\n",P,ans);
    }
    
    return 0;
}
