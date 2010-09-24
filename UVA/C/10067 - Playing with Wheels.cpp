#include <set>
#include <iostream>
#include <queue>

using namespace std;

struct nodo{
    int x;
    int cost;
    nodo(int a, int b){
        x=a;
        cost=b;
    }
};

set <int>  S;
int a,b,ax;
int n[4];
bool visited[10000];
bool M[10000];

int bfs(){
    queue<nodo> Q;
    
    ax=a;
    for(int i=0;i<4;i++){
        n[i]=ax%10;
        ax/=10;
    }
    
    visited[a]=true;
    
    if(n[0]>0) Q.push(nodo(a-1,1));
    else Q.push(nodo(a+9,1));
    if(n[0]<9) Q.push(nodo(a+1,1));
    else Q.push(nodo(a-9,1));
    if(n[1]>0) Q.push(nodo(a-10,1));
    else Q.push(nodo(a+90,1));
    if(n[1]<9) Q.push(nodo(a+10,1));
    else Q.push(nodo(a-90,1));
    if(n[2]>0) Q.push(nodo(a-100,1));
    else Q.push(nodo(a+900,1));
    if(n[2]<9) Q.push(nodo(a+100,1));
    else Q.push(nodo(a-900,1));
    if(n[3]>0) Q.push(nodo(a-1000,1));
    else Q.push(nodo(a+9000,1));
    if(n[3]<9) Q.push(nodo(a+1000,1));
    else Q.push(nodo(a-9000,1));
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();        
        
        if(visited[aux.x]) continue;
        visited[aux.x]=true;
        
        if(aux.x==b) return aux.cost;
        
        ax=aux.x;
        for(int i=0;i<4;i++){
            n[i]=ax%10;
            ax/=10;
        }
        
        if(M[aux.x]) continue;
        
        if(n[0]>0) Q.push(nodo(aux.x-1,aux.cost+1));
        else Q.push(nodo(aux.x+9,aux.cost+1));
        if(n[0]<9) Q.push(nodo(aux.x+1,aux.cost+1));
        else Q.push(nodo(aux.x-9,aux.cost+1));
        if(n[1]>0) Q.push(nodo(aux.x-10,aux.cost+1));
        else Q.push(nodo(aux.x+90,aux.cost+1));
        if(n[1]<9) Q.push(nodo(aux.x+10,aux.cost+1));
        else Q.push(nodo(aux.x-90,aux.cost+1));
        if(n[2]>0) Q.push(nodo(aux.x-100,aux.cost+1));
        else Q.push(nodo(aux.x+900,aux.cost+1));
        if(n[2]<9) Q.push(nodo(aux.x+100,aux.cost+1));
        else Q.push(nodo(aux.x-900,aux.cost+1));
        if(n[3]>0) Q.push(nodo(aux.x-1000,aux.cost+1));
        else Q.push(nodo(aux.x+9000,aux.cost+1));
        if(n[3]<9) Q.push(nodo(aux.x+1000,aux.cost+1));
        else Q.push(nodo(aux.x-9000,aux.cost+1));
        
    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,n,proh;
    cin>>N;
    
    for(int i=0;i<N;i++){
        a=0;
        for(int j=0;j<4;j++){
            cin>>ax;
            a=a*10+ax;
        }        
        b=0;
        for(int j=0;j<4;j++){
            cin>>ax;
            b=b*10+ax;
        }
        cin>>n;
        memset(M,false,sizeof(M));
        for(int j=0;j<n;j++){
            proh=0;
            for(int k=0;k<4;k++){
                cin>>ax;
                proh=proh*10+ax;
            }
            M[proh]=true;
        }
        memset(visited,false,sizeof(visited));
        
        if(a==b) cout<<0<<endl;
        else cout<<bfs()<<endl;
    }

    return 0;
}
