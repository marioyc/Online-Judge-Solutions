#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;    
    vector<string> v;
    string s;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        v.clear();
        
        for(int i=0;i<N;i++){
            cin>>s;
            sort(s.begin(),s.end());
            
            while(s.size()>1 && s[0]=='0') s.erase(0,1);
            
            v.push_back(s);
        }
        
        sort(v.begin(),v.end());
        
        cout<<v[N-1]<<endl;
    }
    
    return 0;
}
