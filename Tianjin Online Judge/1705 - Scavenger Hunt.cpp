#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int parent[333];
int son[333];
vector<string> v;
map<string, int> M;

int main(){
    int T,S,n,start;
    string s1,s2;
    
    cin>>T;
    
    for(int caso=1;caso<=T;caso++){
        cout<<"Scenario #"<<caso<<":"<<endl;
        
        cin>>S;
        
        v.clear();
        M.clear();
        n=0;
        
        memset(parent,-1,sizeof(parent));
        
        for(int i=0;i<S-1;i++){
            cin>>s1>>s2;
            
            if(M.find(s1)==M.end()){
                M[s1]=n;
                v.push_back(s1);
                n++;
            }
            
            if(M.find(s2)==M.end()){
                M[s2]=n;
                v.push_back(s2);
                n++;
            }
            
            parent[M[s2]]=M[s1];
            son[M[s1]]=M[s2];
        }
        
        
        
        for(int i=0;i<S;i++){
            if(parent[i]==-1){
                start=i;
                break;
            }
        }
        
        for(int i=0;i<S;i++){
            cout<<v[start]<<endl;;
            start=son[start];
        }
        
        cout<<endl;
    }
    
    return 0;
}
