#include<cstdio>

using namespace std;

int main(){    
    int N;
    
    scanf("%d",&N);
    
    int x[N],y[N];
    int dist[N][N];
    
    for(int i=0;i<N;i++) scanf("%d %d",&x[i],&y[i]);
    
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            dist[i][j]=dist[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    
    int pos1=0,pos2,min;
    bool ok[N];
    for(int i=0;i<N;i++) ok[i]=true;
    
    for(int i=0;i<N-1;i++){
        min=(1<<30);        
        
        for(int j=0;j<N;j++){
            if(!ok[j] || j==pos1) continue;
            if(dist[pos1][j]<min){
                min=dist[pos1][j];
                pos2=j;
            }
        }
        
        ok[pos2]=false;
        
        pos1=(pos1+1)%N;
        while(!ok[pos1]) pos1=(pos1+1)%N;
    }
    
    printf("%d\n",pos1+1);
    
    return 0;
}
