#include<cstdio>

using namespace std;

int main(){    
    int N;
    
    scanf("%d",&N);
    
    int h[N];
    
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    
    int stop[N];
    long long S=0;
    
    for(int i=N-1;i>=0;i--){
        stop[i]=i+1;
        
        while(stop[i]<N && h[stop[i]]<h[i]){
            S+=stop[stop[i]]-stop[i];
            stop[i]=stop[stop[i]];
        }
    }
    
    printf("%lld\n",S);
    
    return 0;
}
