#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

struct planet{
    int id,x,y,z;
    
    planet(){
    }
    
    planet(int a, int b, int c, int d){
        id=a;
        x=b;
        y=c;
        z=d;
    }
};

double dist(planet A, planet B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}

vector<planet> v;

vector< vector<int> > L;

struct nodo{
    int n;
    int dist;
    
    nodo(int a, int b){
        n=a;
        dist=b;
    }
};

bool visited[1000];
int N;

int max_dist(int n){
    queue<nodo> Q;
    Q.push(nodo(n,0));
    int ans;
    
    fill(visited,visited+N,false);
    visited[n]=true;
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();
        
        ans=aux.dist;
        
        
        for(int i=0;i<L[aux.n].size();i++){
            if(!visited[L[aux.n][i]]){
                visited[L[aux.n][i]]=true;
                Q.push(nodo(L[aux.n][i],aux.dist+1));
            }
        }
    }
    
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int id,x,y,z,cont;
    double min;
    int nodo1,nodo2,min2,max;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        v.clear();
        
        for(int i=0;i<N;i++){
            scanf("%d %d %d %d",&id,&x,&y,&z);
            v.push_back(planet(id,x,y,z));
        }
        
        L.clear();
        L.resize(N);
        
        for(int i=1;i<N;i++){
            min=1e8;
            
            for(int j=0;j<i;j++){
                if(dist(v[i],v[j])<min){
                    id=j;
                    min=dist(v[i],v[j]);
                }
            }
            
            L[id].push_back(i);
            L[i].push_back(id);
        }
        
        min2=(1<<30);
        
        for(int i=0;i<N;i++){
            max=max_dist(i);
            
            if(max<min2){
                cont=1;
                min2=max;
                nodo1=i;
            }else if(max==min2){
                cont=2;
                nodo2=i;
            }
        }
        
        if(cont==1) printf("%d\n",v[nodo1].id);
        else{
            if(v[nodo1].id<v[nodo2].id) printf("%d %d\n",v[nodo1].id,v[nodo2].id);
            else printf("%d %d\n",v[nodo2].id,v[nodo1].id);
        }
    }
    
    return 0;
}
