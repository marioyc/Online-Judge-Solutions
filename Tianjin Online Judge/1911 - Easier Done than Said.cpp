#include<iostream>
#include<string>

using namespace std;

bool vocal(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s,aux;
    int cont;
    bool ok,b1,b2,b3;
    
    while(1){
        cin>>s;
        if(s=="end") break;
        
        ok=false;
        
        for(int i=0;i<s.size();i++){
            if(vocal(s[i])){
                ok=true;
                break;
            }
        }
        
        if(ok && s.size()>1){
            
            for(int i=0;i<s.size()-1;i++){
                if((s[i]==s[i+1]) && s[i]!='e' && s[i]!='o'){
                    ok=false;
                    break;
                }
            }
            
            if(ok && s.size()>2){
                for(int i=0;i<s.size()-2;i++){
                    b1=vocal(s[i]);
                    b2=vocal(s[i+1]);
                    b3=vocal(s[i+2]);
                    if((b1 && b2 && b3) || (!b1 && !b2 && !b3)){
                        ok=false;
                        break;
                    } 
                }
            }
        }
        
        if(ok) cout<<"<"<<s<<"> is acceptable."<<endl;
        else cout<<"<"<<s<<"> is not acceptable."<<endl;
    }

    return 0;
}
