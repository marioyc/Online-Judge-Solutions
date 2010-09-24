#include <vector>
#include <iostream>

using namespace std;

int t,n,s=0;
vector< vector<int> > u;
vector<int> v;
vector<int> aux;

void b(int a){
    if(a>n) return;
    
    if(s==t){
        u.push_back(aux);
        return;
    }    
    if(s>t) return;
    
    aux.push_back(v[a]);
    s+=v[a];
    b(a+1);
    aux.erase(aux.begin()+aux.size()-1);
    s-=v[a];
    
    b(a+1);
    
    return;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int ax;    
    
    while(true){
        cin>>t>>n;
        if(n==0) break;
        
        v.clear();
        for(int i=0;i<n;i++){
            cin>>ax;
            v.push_back(ax);
        }
        
        u.clear();
        b(0);
        
        if(u.size()==0){
            cout<<"Sums of "<<t<<":"<<endl<<"NONE"<<endl;
            continue;
        }
        
        for(int i=0;i<u.size()-1;i++)
        {            
            for(int j=i+1;j<u.size();j++){
                if(u[i]==u[j]){
                    u.erase(u.begin()+j);
                    j--;
                }
            }
        }
        
        cout<<"Sums of "<<t<<":"<<endl;
        for(int i=0;i<u.size();i++){
            for(int j=0;j<u[i].size();j++){
                cout<<u[i][j];
                if(j!=u[i].size()-1) cout<<"+";
                else cout<<endl;
            }
        }
    }

    return 0;
}
