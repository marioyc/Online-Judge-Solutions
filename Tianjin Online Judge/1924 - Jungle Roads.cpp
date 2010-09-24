#include<iostream>
#include<queue>

using namespace std;

int n;
int M[26][26];
int N[26][26];
int gr[26];

void prim(){
    vector<int> d(n,(1<<30));
    int v;
    vector<bool> intree(n,false);
    int dist=0;
    int tot=0;
    
    v=0;
    
    while(!intree[v]){
        tot+=dist;
        intree[v]=true;
        
        for(int i=0;i<gr[v];i++){
            if(!intree[M[v][i]]) d[M[v][i]]=min(d[M[v][i]],N[v][M[v][i]]);
        }
        
        v=0;
        dist=(1<<30);
        
        for(int i=0;i<n;i++){
            if(d[i]<dist && !intree[i]){
                v=i;
                dist=d[i];
            }
        }
    }
    cout<<tot<<endl;
}

int main(){
    
    char vill;
    int k,x;
    
    while(cin>>n){
        if(n==0) break;
        
        memset(gr,0,sizeof(gr));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) N[i][j]=(1<<30);
        
        for(int i=0;i<n-1;i++){
            cin>>vill;
            cin>>k;
            for(int j=0;j<k;j++){
                cin>>vill;
                M[i][gr[i]++]=vill-'A';
                M[vill-'A'][gr[vill-'A']++]=i;
                cin>>x;
                N[i][vill-'A']=x;
                N[vill-'A'][i]=x;
            } 
        }
        
        
        prim();
        
    }    
    
    return 0;
}
