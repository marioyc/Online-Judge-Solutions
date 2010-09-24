#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    int n,cont,ans,aux;
    double x[100],y[100],r[100];
    bool M[100][100],visited[100];
    queue<int> Q;
    
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        
        for(int i=0;i<n;i++) scanf("%lf %lf %lf",&x[i],&y[i],&r[i]);
        
        for(int i=0;i<n;i++){
            M[i][i]=false;
            for(int j=i+1;j<n;j++){
                if(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<(r[i]+r[j])){
                    if(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+fmin(r[i],r[j])<=fmax(r[i],r[j])) M[i][j]=M[j][i]=false;
                    else M[i][j]=M[j][i]=true;
                }else M[i][j]=M[j][i]=false;
            }
        }
        
        ans=0;
        fill(visited,visited+n,false);
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            visited[i]=true;
            cont=1;
            
            Q.push(i);
            
            while(!Q.empty()){
                aux=Q.front();
                Q.pop();
                
                for(int j=0;j<n;j++){
                    if(M[aux][j] && !visited[j]){
                        cont++;
                        visited[j]=true;
                        Q.push(j);
                    }
                }
            }
            
            ans>?=cont;
        }
        
        if(ans==1) printf("The largest component contains 1 ring.\n");
        else printf("The largest component contains %d rings.\n",ans);
    }
    
    return 0;
}
