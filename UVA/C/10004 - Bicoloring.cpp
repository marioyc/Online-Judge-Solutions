#include <iostream>

using namespace std;

int M[199][199];
int gr[199];
bool ok;
int x[199];

void f(int n){
    for(int i=0;i<gr[n]&&ok;i++){
        if(x[M[n][i]]==-1){
            x[M[n][i]]=1-x[n];
            f(M[n][i]);
        }else if(x[n]==x[M[n][i]]) ok=false;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,l,a,b;
    
    while(true){
        cin>>n;
        if(n==0) break;
        cin>>l;
        for(int i=0;i<n;i++) gr[i]=0;
        for(int i=0;i<l;i++){
            cin>>a>>b;
            M[a][gr[a]]=b;
            gr[a]++;
            M[b][gr[b]]=a;
            gr[b]++;
        }
        ok=true;
        for(int i=0;i<n;i++) x[i]=-1;        
        for(int i=0;i<n && ok;i++){
            if(x[i]==-1){
                x[i]=0;
                f(i);
            }
        }
        if(ok) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }

    return 0;
}
