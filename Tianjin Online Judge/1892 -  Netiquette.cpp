#include<string>
#include<iostream>

using namespace std;

bool cond1(string s){
    for(int i=0;i+1<s.size();i++){
        if(isupper(s[i]) && isupper(s[i+1])) return true;
    }
    return false;
}

bool letra(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool cond2(string s){    
    for(int i=0;i+1<s.size();i++){
        if(isdigit(s[i]) && letra(s[i+1])) return true;
        if(isdigit(s[i+1]) && letra(s[i])) return true;
    }
    return false;
}

bool cond3(string s){
    s=" "+s;
    s+=" ";
    for(int i=0;i+1<s.size();i++){
        if(s[i]!=' ' && s[i-1]==' ' && s[i+1]==' ' && s[i]!='a' && s[i]!='A' && s[i]!='I') return true;
    }
    return false;
}

bool puntuacion(char c){
    return (!letra(c) && !isdigit(c) && c!='"' && c!=' ');
}

bool cond4(string s){
    for(int i=0;i+1<s.size();i++){
        if(puntuacion(s[i]) && puntuacion(s[i+1])) return true;
    }
    return false;
}

int main(){
    string s;
    
    while(1){
        getline(cin,s);
        if(s=="#") break;
        
        if(cond1(s)||cond2(s)||cond3(s)||cond4(s)) cout<<"suspicious"<<endl;
        else cout<<"OK"<<endl;
    }
}
