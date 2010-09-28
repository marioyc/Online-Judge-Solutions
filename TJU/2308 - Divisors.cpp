#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> p;

bool primo(int n){
    for(int i=0;i<p.size();i++)
        if(n%p[i]==0) return false;
        
    return true;
}

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    p.push_back(2);

    for(int i=3;i<432;i+=2)
        if(primo(i)) p.push_back(i);

    vector<int> ax(p.size(),0);
    
    vector< vector<int> > v(432,ax);

    int aux;

    for(int i=2;i<432;i++){
        for(int j=0;j<p.size() && p[j]<=i;j++){
            aux=i;
            while(aux!=0){
                v[i][j]+=aux/p[j];
                aux/=p[j];
            }
        }
    }

    vector<int> u(p.size());
    long long div;
    int n,k;

    while(cin>>n>>k){
        u=ax;
        div=1;
        for(int i=0;i<p.size();i++) u[i]=v[n][i]-v[k][i]-v[n-k][i];
                
        
        
        for(int i=0;i<p.size();i++) div*=(u[i]+1);
            
        cout<<div<<endl;
    }

    return 0;
}
