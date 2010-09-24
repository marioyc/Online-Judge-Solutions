#include<iostream>
#include<queue>

using namespace std;

struct nodo{
    int visited[6];
    int pos;
    int suma;
    int cont;
};

int num[6][3];
int mx;
vector< vector<int> > v;
vector<int> ax;
bool M[18][18];    

void bfs(){
    queue<nodo> Q;
    mx=-1;
    
    nodo aux;
    for(int i=0;i<6;i++)
        aux.visited[i]=-1;
    
    aux.cont=1;
    
    for(int i=0;i<3;i++){
        aux.visited[0]=i;
        aux.suma=v[i][1]; 
        aux.pos=i;
        Q.push(aux);
    }
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        
        if(aux.cont==6){
            if(aux.visited[0]==0 && M[aux.pos][0]) mx=max(mx,aux.suma);
            else if(aux.visited[0]==1 && M[aux.pos][1]) mx=max(mx,aux.suma);
            else if(aux.visited[0]==2 && M[aux.pos][2]) mx=max(mx,aux.suma);
            continue;
        }
        
        for(int i=0;i<18;i++){
            if(aux.visited[i/3]==-1 && M[aux.pos][i]){                
                nodo ax;
                for(int j=0;j<6;j++) ax.visited[j]=aux.visited[j];
                ax.visited[i/3]=i%3;
                ax.pos=i;
                ax.suma=aux.suma+v[i][1];
                ax.cont=aux.cont+1;
                
                Q.push(ax);
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    char signo;
    

    while(1){
        for(int i=0;i<6;i++)
            for(int j=0;j<3;j++)
                cin>>num[i][j];
        
        v.clear();
        
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                ax.clear();
                ax.push_back(num[i][j]);
                ax.push_back(num[i][(j+1)%3]);
                ax.push_back(num[i][(j+2)%3]);
                v.push_back(ax);
            }
        }
        
        memset(M,false,sizeof(M));
        
        for(int i=0;i<18;i++)
            for(int j=0;j<18;j++)
                if(v[i][2]==v[j][0] && i/3!=j/3) M[i][j]=true;
        
        
        bfs();
        
        if(mx==-1) cout<<"none"<<endl;
        else cout<<mx<<endl;
        
        cin>>signo;
        if(signo=='$') break;
    }

    return 0;
}
