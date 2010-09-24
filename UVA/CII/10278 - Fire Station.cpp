#include<iostream>
#include<queue>
#include<string>
#include<sstream>

using namespace std;

int F,I;
int M[101];
pair<int,int> L[500][500];
int g[500];
int mn[500];
bool visited[500][500];
int d[500][500];

struct nodo{
    int b,cost;
    nodo(int y, int z){
        b=y;
        cost=z;
    }
    bool operator <(nodo N)const{
        if(cost>N.cost) return true;
        return false;
    }
};

bool y;

void f(int n){
    priority_queue<nodo> Q;
    Q.push(nodo(n,0));
    int cont=0;
    
    while(!Q.empty()){
        nodo aux=Q.top();
        Q.pop();
        
        if(d[n][aux.b]==-1){
            d[n][aux.b]=aux.cost;
            cont++;
        }
        
        if(cont==I) return;
        
        for(int i=0;i<g[aux.b];i++){
            if(!visited[aux.b][L[aux.b][i].first]){
                Q.push(nodo(L[aux.b][i].first,aux.cost+L[aux.b][i].second));
                visited[aux.b][L[aux.b][i].first]=1;
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);    
    
    int T,a,b,cost;
    int est;
    string s;
    
    cin>>T;
    
    for(int caso=0;caso<T;caso++){
        cin>>F>>I;
    
        memset(M,false,sizeof(M));
    
        for(int i=0;i<F;i++){
            cin>>est;
            M[i]=est-1;
        }
    
        memset(g,0,sizeof(g));
    
        pair<int,int> P;    
            
        //while(scanf("%d %d %d",&a,&b,&cost)==3){
            getline(cin,s);
        while(1){
            getline(cin,s);
            istringstream is(s);
            if(s.empty()) break;
            
            is>>a>>b>>cost;
            
            a--;b--;
            P.first=b;
            P.second=cost;
            L[a][g[a]++]=P;
            P.first=a;
            P.second=cost;
            L[b][g[b]++]=P;
        }
    
        for(int i=0;i<I;i++)
            for(int j=0;j<I;j++) d[i][j]=-1;
        
        for(int i=0;i<I;i++){
            for(int j=0;j<I;j++){
                for(int k=0;k<I;k++) visited[j][k]=false;
            }
            f(i);
        }
        
        int mx;
        int S=(1<<30),x;
    
        for(int i=0;i<I;i++){
            M[F]=i;
            for(int j=0;j<I;j++){
                mn[j]=(1<<30);
            }
            for(int j=0;j<I;j++){
                for(int k=0;k<F+1;k++){
                    mn[j]=min(mn[j],d[j][M[k]]);
                }
            }
        
            mx=0;
            for(int j=0;j<I;j++) mx=max(mx,mn[j]);
            if(mx<S){
                S=mx;
                x=i;
            }
        }
    
        cout<<x+1<<endl;
        if(caso!=T-1) cout<<endl;
    }
    
    return 0;
}
