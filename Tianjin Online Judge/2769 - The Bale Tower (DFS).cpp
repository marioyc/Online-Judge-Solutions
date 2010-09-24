#include<iostream>
#include<queue>

using namespace std;

struct nodo{
    int pos;
    int height;
    
    nodo(int a, int b){
        pos=a;
        height=b;
    }
};

int N;
int a[20];
int b[20];
bool M[20][20];
int in[20];
int visited[20];

int bfs(){
    queue<nodo> Q;
    
    for(int i=0;i<N;i++) if(in[i]==0) Q.push(nodo(i,1));
    
    int ans=-1;
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();
        
        if(visited[aux.pos]>= aux.height) continue;
        visited[aux.pos]=aux.height;
        
        ans=max(ans,aux.height);
        
        for(int i=0;i<N;i++)
            if(M[aux.pos][i])
                Q.push(nodo(i,aux.height+1));
    }
    
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>N;
    
    for(int i=0;i<N;i++) cin>>a[i]>>b[i];
    
    memset(M,false,sizeof(M));
    memset(in,0,sizeof(in));
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(a[i]<a[j] && b[i]<b[j]){
                M[i][j]=1;
                in[j]++;
            }
    
    memset(visited,-1,sizeof(visited));
    
    cout<<bfs()<<endl;
    
    return 0;
}
