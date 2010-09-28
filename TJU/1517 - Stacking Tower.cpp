#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,h;
    int a[100];
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        h=n;
        
        for(int i=0;i<n+1;i++)
            if(h==0){
                printf("%d\n",n-i);
                break;
            }else if(h>a[i]) h=a[i]-1;
            else h--;
        
    }
    
    return 0;
}
