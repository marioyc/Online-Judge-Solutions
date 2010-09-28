#include <string>
#include <iostream>

using namespace std;

bool sub(string a, string b){
    if(b.empty()) return true;
    if(b.size()>a.size()) return false;
    
    bool ax=0;
    
    if(a[0]==b[0]){
        string y;
        y=b;
        a.erase(0,1); y.erase(0,1);
        ax|=sub(a,y);
    }else{
        string x;
        x=a; x.erase(0,1);
        ax|=sub(x,b);
    }
    return ax;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //int T;
    //cin>>T;
    
    string s1,s2;
    cin>>s1;
    
    for(int i=0;i<T;i++){
        cin>>s1>>s2;
        
        if(sub(s1,s2)){
            cout<<"YES"<<endl;
            continue;
        }
        
        reverse(s2.begin(),s2.end());
        
        if(sub(s1,s2)){
            cout<<"YES"<<endl;
            continue;
        }
        
        cout<<"NO"<<endl;
    }

    return 0;
}
