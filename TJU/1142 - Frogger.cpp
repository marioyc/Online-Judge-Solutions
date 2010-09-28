#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

struct nodo{
    int n;
    double dist;
    
    nodo(){
    }
    
    nodo(int a, double b){
        n=a;
        dist=b;
    }
    
    bool operator < (nodo X) const{
        return dist>X.dist;
    }
};

double dist[200][200];
bool visited[200];

double shortest(int &n){
    priority_queue<nodo> Q;
    Q.push(nodo(0,0.0));
    
    fill(visited,visited+n,false);
    
    nodo aux;
    
    while(!Q.empty()){
        aux=Q.top();
        Q.pop();
        
        visited[aux.n]=true;
        if(aux.n==1) return aux.dist;
        
        for(int i=0;i<n;i++)
            if(!visited[i]) Q.push(nodo(i,fmax(aux.dist,dist[aux.n][i])));
    }
}

int main(){    
    int n,scenario=1;
    int x[200];
    int y[200];
    int ans;
    
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) dist[i][j]=sqrt(pow(x[i]-x[j],2.0)+pow(y[i]-y[j],2.0));

        printf("Scenario #%d\nFrog Distance = %.3f\n\n",scenario,shortest(n));
        scenario++;
    }
    
    return 0;
}
