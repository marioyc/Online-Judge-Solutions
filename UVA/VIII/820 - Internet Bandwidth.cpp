#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int cap[100][100];
int flow[100][100];
int prev[100];
vector< vector<int> > L;

bool augmenting(int &n, int &s, int &t, int &f){
    fill(prev,prev+n,-1);
    
    queue<int> Q;
    Q.push(s);
    prev[s]=-2;
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<L[aux].size();i++)
            if(flow[aux][L[aux][i]]<cap[aux][L[aux][i]] && prev[L[aux][i]]==-1){
                prev[L[aux][i]]=aux;
                if(L[aux][i]==t) goto found;
                Q.push(L[aux][i]);
            }
    }
    
    return false;
    
    found:
    
    aux=INT_MAX;
    
    int cur=t,next;
    
    while(cur!=s){
        next=prev[cur];
        aux=min(aux,cap[next][cur]-flow[next][cur]);
        cur=next;
    }
    
    cur=t;
    
    while(cur!=s){
        next=prev[cur];
        flow[next][cur]+=aux;
        flow[cur][next]-=aux;
        cur=next;
    }
    
    f+=aux;
    
    return true;
}

int main(){
    int caso=1,n,s,t,connections,a,b,c,f;
    
    while(1){
        scanf("%d",&n);
        if(!n) break;
        
        printf("Network %d\n",caso);
        caso++;
        
        scanf("%d %d %d",&s,&t,&connections);
        s--; t--;
        
        for(int i=0;i<n;i++){
            fill(cap[i],cap[i]+n,0);
            fill(flow[i],flow[i]+n,0);
        }
        
        L.clear();
        L.resize(n);
        
        for(int i=0;i<connections;i++){
            scanf("%d %d %d",&a,&b,&c);
            
            if(cap[a-1][b-1]==0){
                L[a-1].push_back(b-1);
                L[b-1].push_back(a-1);
            }
            
            cap[a-1][b-1]+=c;
            cap[b-1][a-1]+=c;
        }
        
        f=0;
        
        while(augmenting(n,s,t,f)) ;
        
        printf("The bandwidth is %d.\n\n",f);
    }
    
    return 0;
}
