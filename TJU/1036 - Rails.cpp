#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,a[1000],Q[1000],m,end;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        while(1){
            scanf("%d",&a[0]);
            if(a[0]==0) break;
            
            for(int i=1;i<N;i++) scanf("%d",&a[i]);
            
            m=1;
            end=0;
            
            for(int i=0;i<N;i++){
                while(m<=N && (end==0 || Q[end-1]!=a[i])) Q[end++]=m++;
                
                if(Q[end-1]==a[i]) end--;
                else break;
            }
            
            if(end!=0) printf("No\n");
            else printf("Yes\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
