#include<string>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    set<string> S;
    bool ok;    
    
    while(1){
        cin>>s;
        if(s=="XXXXXX") break;
        S.insert(s);
    }
    
    while(1){
        cin>>s;
        if(s=="XXXXXX") break;
        
        sort(s.begin(),s.end());
        ok=0;;
        
        do{
            if(S.find(s)!=S.end()){
                cout<<s<<endl;
                ok=1;
            }
        }while(next_permutation(s.begin(),s.end()));
        if(!ok) cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }
    return 0;
}
