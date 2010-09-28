#include <cstdio>
#include <numeric>

using namespace std;

bool check(int *p, int &n){
    for(int i=1;i<n;i++) if((*(p+i)) != (*p)) return false;
    return true;
}

int main(){    
    int T,S,C,n,a[100],start[101],sum;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&S,&C);
        
        for(int i=0;i<S;i++) scanf("%d",&a[i]);
        n=S;
        
        while(!check(a,n)){
            start[n]=a[0];
            for(int i=0;i<n-1;i++) a[i]=a[i+1]-a[i];
            n--;
        }
        
        for(int i=n;i<n+C;i++) a[i]=a[0];
        
        for(int i=n;i<S;i++){
            sum=accumulate(a,a+i+C,0)+start[i+1];
            
            for(int j=i+C;j>=0;j--){
                a[j]=sum;
                if(j>0) sum-=a[j-1];
            }
        }
        
        for(int i=S;i<S+C;i++){
            if(i>S) printf(" ");
            printf("%d",a[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}
