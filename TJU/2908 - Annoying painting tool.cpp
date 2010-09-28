#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,m,r,c,cont;
    vector<string> v;
    string s;
    bool X[100][100],ok;
    
    while(1){
        cin>>n>>m>>r>>c;
        if(n==0 && m==0 && r==0 && c==0) break;
        
        getline(cin,s);
        v.clear();
        
        for(int i=0;i<n;i++){
            getline(cin,s);
            v.push_back(s);
        }
                
        cont=0;
        memset(X,0,sizeof(X));
        
        for(int i=0;i<=n-r;i++){
            for(int j=0;j<=m-c;j++){
                if((v[i][j]-'0')!=X[i][j]){
                    for(int a=i;a<i+r;a++)
                        for(int b=j;b<j+c;b++) X[a][b]=1-X[a][b];
                        
                    cont++;
                }
            }
        }
        
        ok=true;
        
        for(int i=n-r+1;i<n && ok;i++){
            for(int j=0;j<m && ok;j++){
                if(X[i][j]!=(v[i][j]-'0')) ok=false;
            }
        }
        
        for(int i=0;i<=n-r && ok;i++){
            for(int j=m-c;j<m && ok;j++){
                if(X[i][j]!=(v[i][j]-'0')) ok=false;
            }
        }
        
        if(ok) cout<<cont<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}
