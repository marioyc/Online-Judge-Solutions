#include <iostream>
#include <queue>

using namespace std;

int n,l,a,b,x,y;

int di[]={-2,-2,-1,-1,1,1,2,2};
int dj[]={1,-1,2,-2,2,-2,1,-1};

struct nodo{
    int i;
    int j;
    int cost;
    nodo(int x, int y, int z){
        i=x;
        j=y;
        cost=z;
    }
};

bool visited[300][300];

int bfs(){
    queue<nodo> Q;
    Q.push(nodo(a,b,0));
    visited[a][b]=true;
    
    int I,J;
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();
        
        if(aux.i==x && aux.j==y) return aux.cost;
        
        for(int i=0;i<8;i++){
            I=aux.i+di[i];
            J=aux.j+dj[i];
            if(I>=0 && I<l && J>=0 && J<l && !visited[I][J]){
                Q.push(nodo(I,J,aux.cost+1));
                visited[I][J]=true;
            }
        } 
    }
    
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d %d",&l,&a,&b,&x,&y);
        for(int j=0;j<l;j++){
            for(int k=0;k<l;k++) visited[j][k]=false;
        }
        cout<<bfs()<<endl;
    }
 
    return 0;
}
