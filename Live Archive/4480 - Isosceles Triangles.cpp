#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,X[1000],Y[1000],cont,ans,pos1,pos2;
    long long dist2;
    long long a[1000];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d %d",&X[i],&Y[i]);
        
        ans=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) a[j]=(long long)(X[i]-X[j])*(X[i]-X[j])+(long long)(Y[i]-Y[j])*(Y[i]-Y[j]);
            
            sort(a,a+N);
            
            pos1=0;
            
            while(pos1<N){
                pos2=pos1;
                while(pos2<N && a[pos2]==a[pos1]) pos2++;
                cont=pos2-pos1;
                ans+=(cont*(cont-1))>>1;
                pos1=pos2;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
