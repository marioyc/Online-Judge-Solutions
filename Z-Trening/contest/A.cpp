#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct nodo{
    int v,dist,h;
    
    nodo(int _v, int _dist, int _h){
        v=_v;
        dist=_dist;
        h=_h;
    }
    
    bool operator < (nodo X)const{
        if(dist==X.dist) return h<X.h;
        return dist>X.dist;
    } 
};

int n;
int d[10000][10000];
int H[10000][10000];
bool visited[10000];

int ans_d,ans_h;

void shortest(){
    priority_queue<nodo> Q;
    Q.push(nodo(0,0,0));
    
    fill(visited,visited+n,false);
    
    ans_d=-1;
    ans_h=-1;
    
    while(!Q.empty()){
        nodo aux=Q.top();
        Q.pop();
        
        if(visited[aux.v]) continue;
        visited[aux.v]=true;
        
        if(aux.v==n-1){
            ans_d=aux.dist;
            ans_h=aux.h;
            break;
        }
        
        for(int i=0;i<n;i++){
            if(visited[i] || d[aux.v][i]==-1) continue;
            Q.push(nodo(i,aux.dist+d[aux.v][i],max(aux.h,H[aux.v][i])));
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int m,a,b,dist,h;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) d[i][j]=-1;
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>dist>>h;
        a--; b--;
        if(d[a][b]==-1){
            d[a][b]=d[b][a]=dist;
            H[a][b]=H[b][a]=h;
        }else{
            if(d[a][b]<dist){
                d[a][b]=dist;
                H[a][b]=h;
            }else if(d[a][b]==dist) H[a][b]=max(H[a][b],h);
        }
    }
    
    shortest();
    
    cout<<ans_d<<" "<<ans_h<<endl;
    
    return 0;
}
