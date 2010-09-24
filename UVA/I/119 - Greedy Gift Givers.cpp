#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,cant,amigos;
    
    string s1,s2;
    
    vector<string> v;
    
    cin>>n;
    
    while(1){
        map<string, int> M;
        
        v.clear();
        
        for(int i=0;i<n;i++){
            cin>>s1;
            v.push_back(s1);
        }
        
        
        for(int i=0;i<n;i++){
            cin>>s1>>cant>>amigos;
            
            
            if(amigos!=0) M[s1]-=amigos*(cant/amigos);
            
            for(int j=0;j<amigos;j++){
                cin>>s2;
                M[s2]+=cant/amigos;
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<v[i]<<" "<<M[v[i]]<<endl;
        
        if(cin>>n) cout<<endl;
        else break;
    }
}
