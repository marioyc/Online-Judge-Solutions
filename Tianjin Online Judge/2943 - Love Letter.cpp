#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    short n;
    cin>>n;
    string s;
    
    vector<int> cont(26);
    
    map< vector<int> , string> M;
    
    getline(cin,s);
    
    int i,j;
    
    for(i=0;i<n;i++){
        getline(cin,s);
        
        if(s.size()<3) continue;
        
        for(j=0;j<26;j++) cont[j]=0;
                
        for(j=1;j<s.size()-1;j++) cont[s[j]-'a']++;
        
        s.erase(s.size()-1,1);
        s.erase(0,1);
        
        M[cont]=s;
    }

    while(getline(cin,s)){
        istringstream is(s);
        ostringstream os;
        
        while(is>>s){
            if(s.size()<3){
                os<<s<<" ";
                continue;
            }
            
            for(j=0;j<26;j++) cont[j]=0;
            
            for(j=1;j<s.size()-1;j++) cont[s[j]-'a']++;
            
            os<<s[0]<<M[cont]<<s[s.size()-1]<<" ";
        }
        
        s=os.str();
        s.erase(s.size()-1,1);
        cout<<s<<endl;
    }

    return 0;
}
