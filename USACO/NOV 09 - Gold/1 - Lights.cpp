/*
ID:zion_ba1
LANG:C++
TASK:lights
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_R 35
#define MAX_C 36

int R,C;
int MOD;

struct M{
    int X[MAX_R][MAX_C];
    
    M(){
    }
};

void GaussianElimination(M &M0){
    int aux;
    bool found;
    
    for(int i=0,r=0;r<R && i<C;i++){
        found=false;
        
        for(int j=r;j<R;j++){
            if(M0.X[j][i]==1){
                found=true;
                
                if(j==r) break;
                
                for(int k=i;k<C;k++) swap(M0.X[r][k],M0.X[j][k]);
                break;
            }
        }
        
        if(found){
            for(int j=r+1;j<R;j++){
                if(M0.X[j][i]==0) continue;
                for(int k=i;k<C;k++)
                    M0.X[j][k]=(M0.X[j][k]+M0.X[r][k])&1;
            }
            
            r++;
        }
    }
    
    for(int i=R-1;i>0;i--)
        for(int j=0;j<i;j++)
            M0.X[j][R]=(M0.X[j][R]+(2-M0.X[j][i])*M0.X[i][R])&1;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    freopen("lights.in","r",stdin);
    freopen("lights.out","w",stdout);
    
    int E;
    scanf("%d %d",&R,&E);
    
    C=R+1;
    M M0;
    
    for(int i=0;i<R;i++)
        for(int j=0;j<R;j++)
            M0.X[i][j]=0;
    
    for(int i=0;i<R;i++) M0.X[i][R]=1;
    
    for(int i=0,a,b;i<E;i++){
        scanf("%d %d",&a,&b);
        a--; b--;
        
        M0.X[a][b]=1;
        M0.X[b][a]=1;
    }
    
    for(int i=0;i<R;i++) M0.X[i][i]=1;
    
    GaussianElimination(M0);
    
    int ans=0;
    for(int i=0;i<R;i++) ans+=M0.X[i][R];
    
    printf("%d\n",ans);
    
    return 0;
}
