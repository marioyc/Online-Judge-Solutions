#include <cstdio>
#include <algorithm>

using namespace std;

int main(){    
    int n,h[100000],left[100000],right[100000];
    long long ans,x;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&h[i]);
        
        left[0]=-1;
        for(int i=1;i<n;i++){
            left[i]=i-1;
            if(h[left[i]]>=h[i]){
                do{
                    left[i]=left[left[i]];
                }while(left[i]!=-1 && h[left[i]]>=h[i]);
            }
        }
        
        right[n-1]=n;
        for(int i=n-2;i>=0;i--){
            right[i]=i+1;
            if(h[i]<=h[right[i]]){
                do{
                    right[i]=right[right[i]];
                }while(right[i]!=n && h[i]<=h[right[i]]);
            }
        }
        
        ans=-1;
        
        for(int i=0;i<n;i++){
            x=(long long)(right[i]-left[i]-1)*h[i];
            
            if(x>ans) ans=x;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
