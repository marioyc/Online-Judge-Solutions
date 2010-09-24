#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,L,x,ans;
    bool M[200][300];
    bool contains[200][200];
    bool valid[200];
    bool ok,found;
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        
        for(int i=0;i<m;i++){
            fill(M[i],M[i]+n,false);
            scanf("%d",&L);
            for(int j=0;j<L;j++){
                scanf("%d",&x);
                x--;
                M[i][x]=true;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    contains[i][i]=false;
                    continue;
                }
                
                ok=true;
                for(int k=0;k<n;k++)
                    if(M[j][k] && !M[i][k]) ok=false;
                contains[i][j]=ok;
            }
        }
        
        fill(valid,valid+m,true);
        ans=0;
        
        for(int i=0;i<m;i++){
            ok=true;
            for(int j=0;j<n;j++){
                if(!M[i][j]) continue;
                
                found=false;
                for(int k=0;k<m;k++)
                    if(valid[k] && contains[i][k] && M[k][j]){
                        found=true;
                        break;
                    }
                
                if(!found){
                    ok=false;
                    break;
                }
            }
            if(ok){
                valid[i]=false;
                ans++;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
