#include <cstdio>
#include <cstring>

using namespace std;

int check(int n, int *a){
    int mn = a[0],mx = a[0];
    
    for(int i = 1;i<n;++i){
        if(a[i]<mn) mn = a[i];
        if(a[i]>mx) mx = a[i];
    }
    
    if(mn!=mx) return -1;
    return mn;
}

int main(){
    int n,a[1000],b[1000];
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i = 0;i<n;++i) scanf("%d",&a[i]);
        
        int cont = 0;
        
        while(true){
            int ret = check(n,a);
            
            if(ret!=-1){
                printf("%d %d\n",cont,ret);
                break;
            }
            
            ++cont;
            memset(b,0,sizeof(b));
            
            for(int i = 0;i<n;++i){
                b[i+1==n? 0 : i+1] = a[i]/2+a[i+1==n? 0 : i+1]/2;
                if(b[i+1==n? 0 : i+1] & 1) ++b[i+1==n? 0 : i+1];
            }
            
            for(int i = 0;i<n;++i) a[i] = b[i];
        }
    }
    
    return 0;
}
