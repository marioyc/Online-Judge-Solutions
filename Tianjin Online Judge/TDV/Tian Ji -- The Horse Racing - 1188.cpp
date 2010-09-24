#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,sum,cont,j;
    vector<int> v;
    vector<int> u;
    bool enc;
    
    while(1){
        cin>>n;
        cout<<n<<endl;
        if(n==0) break;
        
        v.clear();v.resize(n);
        
        for(int i=0;i<n;i++) cin>>v[i];
        
        u.clear();u.resize(n);
        
        for(int i=0;i<n;i++) cin>>u[i];
    
        sort(v.rbegin(),v.rend());
        sort(u.begin(),u.end());
        
        cont=0;
        
        for(int i=0;i<v.size();i++){
            enc=false;
            
            j=0;
            while(j<u.size() && u[j]<=v[i]){// && u[i+1]<=v[i]){
                if(j+1>u.size()) break;
                j++;
                enc=true;
            }
            
            if(!enc) break;
            
            u.erase(u.begin()+j);
            
            cont++;
        }
        
        sum=200*cont-200*(n-cont);
        
        cout<<sum<<endl;
    }

    return 0;
}
