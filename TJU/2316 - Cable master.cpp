#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    double L[N];
    
    for(int i=0;i<N;i++) scanf("%lf",&L[i]);
    for(int i=0;i<N;i++) L[i]=L[i]*100;
    
    long long cont=0;
    for(int i=0;i<N;i++) cont+=floor(L[i]);
    
    if(cont<K) printf("0.00\n");
    else{
        int lo=1,hi=1,mi;
        
        for(int i=0;i<N;i++) if(hi<L[i]) hi=(int)L[i];
        
        while(lo!=hi){
            mi=(lo+hi+1)/2;
            
            cont=0;
            for(int j=0;j<N;j++) cont+=floor(L[j]/mi);
            
            if(cont>=K) lo=mi;
            else hi=mi-1;
        }
        
        double ans=lo/100.0;
        printf("%.2f\n",ans);
    }
    
    return 0;
}
