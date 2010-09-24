#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    bool c,java,error;    
    int n;
    
    while(cin>>s){
        c=java=false;
        n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='_') c=true;
            if(isupper(s[i])) java=true;
        }
        
        error=false;
        
        for(int i=0;i<n-1;i++) if(s[i]=='_' && s[i+1]=='_') error=true;
        
        if(!c && !java) cout<<s<<endl;
        else if(error || (c && java) || (java && isupper(s[0])) ||  (c && (s[0]=='_' || s[n-1]=='_'))) cout<<"Error!"<<endl;
        else if(c){
            for(int i=0;i<n;i++){
                if(s[i]=='_'){
                    i++;
                    if(islower(s[i])) cout<<(char)(s[i]-'a'+'A');
                    else cout<<s[i];
                }else cout<<s[i];
            }
            cout<<endl;
        }else{
            for(int i=0;i<n;i++){
                if(isupper(s[i])) cout<<'_'<<(char)(s[i]-'A'+'a');
                else cout<<s[i];
            }
            cout<<endl;
        }
    }
    
    return 0;
}
