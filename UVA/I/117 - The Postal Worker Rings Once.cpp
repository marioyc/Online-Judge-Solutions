#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct nodo{
    int v,dist;
    
    nodo(){
    }
    
    nodo(int _v, int _dist){
        v=_v;
        dist=_dist;
    }
    
    bool operator < (nodo X) const{
        return dist>X.dist;
    }
};

int M[26][26];
int gr[26];

int dijkstra(int s, int t){
    nodo aux;
    priority_queue<nodo> Q;
    Q.push(nodo(s,0));
    
    bool visited[26];
    memset(visited,false,sizeof(visited));
    
    while(!Q.empty()){
        aux=Q.top();
        Q.pop();
        
        if(aux.v==t) return aux.dist;
        
        if(visited[aux.v]) continue;
        visited[aux.v]=true;
        
        for(int i=0;i<26;i++)
            if(!visited[i] && M[aux.v][i]!=-1) Q.push(nodo(i,aux.dist+M[aux.v][i]));
    }
}

int solve(){
    int cont=0,sum=0;
    
    for(int i=0;i<26;i++) if(gr[i]%2==1) cont++;
    
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++) if(M[i][j]!=-1) sum+=M[i][j];
    
    if(cont==0) return sum;
    else{    
        int a[2],m=0;
        for(int i=0;i<26;i++) if(gr[i]%2==1) a[m++]=i;
        return sum+dijkstra(a[0],a[1]);
    }
}

int main(){    
    string s;
    int n;
    
    while(cin>>s){
        memset(M,-1,sizeof(M));
        memset(gr,0,sizeof(gr));
        
        if(s!="deadend"){        
            n=s.size();
            M[s[0]-'a'][s[n-1]-'a']=n;
            M[s[n-1]-'a'][s[0]-'a']=n;
            gr[s[0]-'a']++;
            gr[s[n-1]-'a']++;
            
            while(1){
                cin>>s;
                if(s=="deadend") break;
                
                n=s.size();
                M[s[0]-'a'][s[n-1]-'a']=n;
                M[s[n-1]-'a'][s[0]-'a']=n;
                gr[s[0]-'a']++;
                gr[s[n-1]-'a']++;
            }
        }
        
        cout<<solve()<<endl;
    }
    
    return 0;    
}
