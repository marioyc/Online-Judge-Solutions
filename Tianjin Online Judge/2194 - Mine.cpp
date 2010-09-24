#include <iostream>

using namespace std;

int N,M;
bool X[100][100];
char Y[100][100];
bool visited[100][100];

int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,-1,0,1,-1,1,-1,0};

int cont(int n, int m){
    int ax=0,I,J;
    
    for(int i=0;i<8;i++){
        I=n+di[i];
        J=m+dj[i];
        if(I>=0 && I<N && J>=0 && J<N && !visited[I][J] && X[I][J]) ax++;
    }
    return ax;
}

void dfs(int n, int m){
    if(visited[n][m]) return;
    
    visited[n][m]=1;
    
    int ax, I, J;
    
    Y[n][m]='0';
    
    for(int i=0;i<8;i++){
        I=n+di[i];
        J=m+dj[i];
        if(I>=0 && I<N && J>=0 && J<N){
            ax=cont(I,J);
            if(ax==0) dfs(I,J);
            else Y[I][J]='0'+ax;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int a,b;

    while(1){
        cin>>N>>M;
        if(N==0 && M==0) break;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                X[i][j]=0;
                visited[i][j]=0;
            }
        }
            
        for(int i=0;i<M;i++){
            cin>>a>>b;
            a--; b--;
            X[a][b]=1;
        }
        
        cin>>a>>b;
        a--; b--;
        
        if(X[a][b]){
            cout<<"oops!"<<endl<<endl;
            continue;
        }
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) Y[i][j]='.';
        
        
        if(cont(a,b)==0) dfs(a,b);
        else Y[a][b]='0'+cont(a,b);
        
        for(int i=0;i<N;i++){                        
            for(int j=0;j<N;j++) cout<<Y[i][j];
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
