#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,C;
    
    bool p[1001];
    vector<int> primos;
    vector<int> v;
    
    memset(p,true,sizeof(p));
    
    p[0]=0;
    primos.push_back(1);
    
    for(int i=2;i<1001;i++){
        if(p[i]){
            primos.push_back(i);
            
            for(int j=2;j*i<1001;j++) p[j*i]=0;
        }
    }
    
    while(cin>>N>>C){
        v.clear();
        
        for(int i=0;primos[i]<=N && i<primos.size();i++) v.push_back(primos[i]);
        
        cout<<N<<" "<<C<<":";
        
        if(v.size()%2==0){
            if(2*C>v.size()) for(int i=0;i<v.size();i++) cout<<" "<<v[i];
            else for(int i=(v.size()-2*C)/2;i<(v.size()-2*C)/2+2*C;i++) cout<<" "<<v[i];
        }else{
            if(2*C-1>v.size()) for(int i=0;i<v.size();i++) cout<<" "<<v[i];
            else for(int i=(v.size()-2*C+1)/2;i<(v.size()-2*C+1)/2+2*C-1;i++) cout<<" "<<v[i];
        }
        
        cout<<endl<<endl;
    }
    
    return 0;
}
