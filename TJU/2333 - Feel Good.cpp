#include <cstdio>
#include <algorithm>

using namespace std;

int main(){    
    int n;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    long long S[n+1];
    S[0]=0;
    for(int i=0;i<n;i++) S[i+1]=S[i]+a[i];
    
    int left[n];
    left[0]=-1;
    for(int i=1;i<n;i++){
        left[i]=i-1;
        if(a[left[i]]>=a[i]){
            do{
                left[i]=left[left[i]];
            }while(left[i]!=-1 && a[left[i]]>=a[i]);
        }
    }
    
    int right[n];
    right[n-1]=n;
    for(int i=n-2;i>=0;i--){
        right[i]=i+1;
        if(a[i]<=a[right[i]]){
            do{
                right[i]=right[right[i]];
            }while(right[i]!=n && a[i]<=a[right[i]]);
        }
    }
    
    long long ans=-1,x;
    int L,R;
    
    for(int i=0;i<n;i++){
        x=(S[right[i]]-S[left[i]+1])*a[i];
        
        if(x>ans){
            ans=x;
            L=left[i]+2;
            R=right[i];
        }
    }
    
    printf("%lld\n",ans);
    printf("%d %d\n",L,R);
    
    return 0;
}
