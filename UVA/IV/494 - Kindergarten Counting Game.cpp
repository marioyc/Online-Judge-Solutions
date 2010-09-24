#include<iostream>
#include<string>

using namespace std;

bool f(char &c){
    if((c>='a' && c<='z')||(c>='A' && c<='Z')) return 1;
    return 0;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int palabras;
    bool inicio;
    
    while(getline(cin,s)){
        palabras=0;
        
        inicio=0;
        
        for(int i=0;i<s.size();i++){
            if(!inicio && f(s[i])){
                palabras++;
                inicio=1;
            }else if(inicio && !f(s[i])) inicio=0;
        }
        
        cout<<palabras<<endl;
    }

    return 0;
}
