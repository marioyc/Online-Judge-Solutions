#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,c,pos,ans,sum,caso=1;
    int a[20];
    bool off[20];
    
    while(1){
        scanf("%d %d %d",&n,&m,&c);
        if(n==0 && m==0 && c==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        fill(off,off+n,true);        
        ans=sum=0;
        
        for(int i=0;i<m;i++){
            scanf("%d",&pos);
            pos--;
            
            if(off[pos]) sum+=a[pos];
            else sum-=a[pos];
            
            off[pos]=!off[pos];
            
            ans=max(ans,sum);
        }
        
        printf("Sequence %d\n",caso);
        caso++;
        
        if(ans>c) printf("Fuse was blown.\n\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",ans);
    }
    
    return 0;
}
