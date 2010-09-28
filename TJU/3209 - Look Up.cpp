#include <cstdio>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int H[N];
    
    for(int i=0;i<N;i++) scanf("%d",&H[i]);
    
    int x[N];
    
    for(int i=N-1;i>=0;i--){
        x[i]=i+1;
        while(x[i]<N && H[x[i]]<=H[i]) x[i]=x[x[i]];
    }
    
    for(int i=0;i<N;i++) x[i]=(x[i]==N? 0: x[i]+1);
    
    for(int i=0;i<N;i++) printf("%d\n",x[i]);
    
    return 0;
}
