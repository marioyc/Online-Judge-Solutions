#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,a[100000],ans,pos;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        
        sort(a,a+N);
        
        ans=a[N-1]-a[0]+1;
        
        for(int i=N-5;i>=0;i--)
            if(a[i+4]-a[i]+1<=ans){
                pos=i;
                ans=a[i+4]-a[i]+1;
            }
        
        printf("Scenario #%d:\n",tc);
        printf("%d:",a[pos+4]-a[pos]+1);
        for(int i=0;i<5;i++) printf(" %d",a[pos+i]);
        printf("\n\n");
    }
    
    return 0;
}
