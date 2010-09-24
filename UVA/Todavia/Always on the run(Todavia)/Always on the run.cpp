#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector< vector<int> > pdias;
int n,k;
int v1[10][10][1000];
int v2[10];

struct nodo
{
    int a;//inicio    
    int b;//dia
    int cost;//costo
    nodo(int x, int y, int z)
    {
        a=x;
        b=y;
        cost=z;
    }
};

int f()
{    
    queue<nodo> Q;
    Q.push(nodo(0,0,0));
    while(true)
    {
        nodo aux=Q.front();
        
        if(aux.b==k) break; 
               
        Q.pop();
        
        for(int i=0;i<n;i++)
            if(v1[aux.a][i%v2[aux.a]][aux.b]!=0) Q.push(nodo(i,aux.b+1,aux.cost+v1[aux.a][i%v2[aux.a]][aux.b]));        
        
    }
    while(!Q.empty())
    {
        nodo aux=Q.front();
        Q.pop();
        
        if(aux.a==n-1) return aux.cost;
    }
    return -1;
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<int> v;
    int m;
    int cont;
    
    while(true)
    {
        scanf("%d %d", &n, &k);
        if(n==0 && k==0) break;
        
        cout<<n<<" "<<k<<endl;
        
        for(int i=0;i<n*(n-1);i++)
        {
            cout<<"i"<<" "<<i<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<"j "<<j<<" ";
                cin>>v2[i];
                cont=0;                
                for(int x=0;cont!=m;x++)
                {
                    if(x==j) v1[i][j][x]=0;
                    else
                    {
                        cin>>v1[i][j][x];
                        cont++;
                    }
                    cout<<v1[i][j][x]<<endl;
                }
            }            
        }
        
        cout<<f()<<endl;
    }
    return 0;
}
