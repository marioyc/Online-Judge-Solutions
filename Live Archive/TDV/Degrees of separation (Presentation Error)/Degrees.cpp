#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int P,R;
vector<string> V;
int adj[100][100];
bool visited[100];

int indice(string s)
{
    for(int i=0;i<V.size();i++)
        if(V[i]==s) return i;
        
    return -1;
}

int dfs(int n)
{
       
    visited[n]=1;
    int x=1;
   
    for(int i=0;i<P;i++)
        if(adj[n][i]==1 && !visited[i]) x+=dfs(i);
    
    return x;
   
}

struct nodo
{
    int ind;
    int costo;
    nodo(int a,int b)
    {
        ind=a;
        costo=b;
    }
    
};

int bfs(int a,int b)
{
    
    queue<nodo> Q;
    
    memset(visited,false,sizeof(visited));
    
    Q.push(nodo(a,0));
    visited[a]=true;
        
    while(!Q.empty())
    {
        nodo aux=Q.front();
        Q.pop();
        
        int ind=aux.ind;
        int costo=aux.costo;
        
        if(ind==b) return costo;
        
        for(int i=0;i<P;i++)
        {
            if(adj[ind][i] && !visited[i])
            {
                Q.push(nodo(i,costo+1));
                visited[i]=1;
            }
        }
        
    }
    
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s1,s2;
    int a,b;
    int cont=1;
    int aux;

    while(cin>>P>>R)
    {
        if(P==0 && R==0) break;
        if(cont!=1) cout<<endl;
        
        V.clear();
        memset(adj,0,sizeof(adj));
        
        for(int i=0;i<R;i++)
        {
            cin>>s1>>s2;
            
            if(indice(s1)==-1) V.push_back(s1);
            if(indice(s2)==-1) V.push_back(s2);
            
            a=indice(s1);
            b=indice(s2);
            
            adj[a][b]=1;
            adj[b][a]=1;
            
        }
        
        if(V.size() != P) cout<<"Network "<<cont<<": DISCONNECTED"<<endl;
        else
        {
            memset(visited,false,sizeof(visited));
            if(dfs(0) != P) cout<<"Network "<<cont<<": DISCONNECTED"<<endl;
            else
            {
                int maxD=0;
                
                for(int i=0;i<P-1;i++)
                    for(int j=i+1;j<P;j++)
                        maxD=max(maxD,bfs(i,j));
                
                cout<<"Network "<<cont<<": "<<maxD<<endl;
            }
        }
        cont++;
    }

    return 0;
}
