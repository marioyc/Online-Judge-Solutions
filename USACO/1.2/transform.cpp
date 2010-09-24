/*
ID: zion_ba1
LANG: C++
TASK: transform
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    
    int N;
    scanf("%d",&N);
    
    char M1[N][N+1],M2[N][N+1],M3[N][N+1];
    
    for(int i=0;i<N;i++) scanf("%s",M1[i]);
    for(int i=0;i<N;i++) scanf("%s",M2[i]);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M3[i][j]=M1[i][j];
    
    bool equal;
    int ans=7;
    
    for(int mask=0;mask<(1<<4);mask++){
        if(__builtin_popcount(mask & 7)>1) continue;
        
        if(mask & 1){
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    M1[j][N-i-1]=M3[i][j];
        }
        
        if(mask & 2){
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    M1[N-i-1][N-j-1]=M3[i][j];
        }
        
        if(mask & 4){
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    M1[N-j-1][i]=M3[i][j];
        }
        
        if(mask & 8){
            for(int i=0;i<N;i++)
                for(int j=0;j<N/2;j++)
                    swap(M1[i][j],M1[i][N-j-1]);
        }
        
        equal=true;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(M1[i][j]!=M2[i][j])
                    equal=false;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                M1[i][j]=M3[i][j];
        
        if(!equal) continue;
        
        if(mask==1) ans=min(ans,1);
        else if(mask==2) ans=min(ans,2);
        else if(mask==4) ans=min(ans,3);
        else if(mask==8) ans=min(ans,4);
        else if(mask==0) ans=min(ans,6);
        else ans=min(ans,5);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
