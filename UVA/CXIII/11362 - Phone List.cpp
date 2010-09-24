#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t,n;
    string s;
    vector<string> list;
    bool ok;
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>n;
        
        list.clear();
        
        for(int i=0;i<n;i++){
            cin>>s;
            list.push_back(s);
        }
        
        sort(list.begin(),list.end());
        
        ok=true;
        
        for(int i=0;i<n-1;i++){
            if(list[i+1].size()>=list[i].size()){
                s=list[i+1].substr(0,list[i].size());
                if(s==list[i]){
                    ok=false;
                    break;
                }
            }
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
