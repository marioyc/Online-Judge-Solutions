#include <iostream>
#include <set>

using namespace std;

int main(){
    int W;
    cin>>W;
    
    set<string> D;
    string s;
    
    for(int i=0;i<W;++i){
        cin>>s;
        D.insert(s);
    }
    
    int N;
    cin>>N;
    
    bool ok;
    
    for(int i=1;i<=N;++i){
        ok = true;
        
        while(true){
            cin>>s;
            if(s=="-1") break;
            if(D.find(s)==D.end()){
                if(ok) cout<<"Email "<<i<<" is not spelled correctly."<<endl;
                ok = false;
                cout<<s<<endl;
            }
        }
        
        if(ok) cout<<"Email "<<i<<" is spelled correctly."<<endl;
    }
    
    cout<<"End of Output"<<endl;
    
    return 0;
}
