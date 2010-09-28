#include<iostream>
#include<string>

using namespace std;

void roman(string &s){
    int cont=0,pos=0;
    string x="";
    
    while(s[pos]=='M'){
        pos++;
        cont++;
    }
    
    x+='0'+cont;
    
    if(pos+1<s.size() && s[pos]=='C' && s[pos+1]=='M'){
        pos+=2;
        x+='9';
    }else if(pos<s.size() && s[pos]=='D'){
        pos++;
        cont=5;
        while(pos<s.size() && s[pos]=='C'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }else if(pos+1<s.size() && s[pos]=='C' && s[pos+1]=='D'){
        pos+=2;
        x+='4';
    }else{
        cont=0;
        while(pos<s.size() && s[pos]=='C'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }
    
    if(pos+1<s.size() && s[pos]=='X' && s[pos+1]=='C'){
        pos+=2;
        x+='9';
    }else if(pos<s.size() && s[pos]=='L'){
        pos++;
        cont=5;
        while(pos<s.size() && s[pos]=='X'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }else if(pos+1<s.size() && s[pos]=='X' && s[pos+1]=='L'){
        pos+=2;
        x+='4';
    }else{
        cont=0;
        while(pos<s.size() && s[pos]=='X'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }
    
    if(pos+1<s.size() && s[pos]=='I' && s[pos+1]=='X'){
        pos+=2;
        x+='9';
    }else if(pos<s.size() && s[pos]=='V'){
        pos++;
        cont=5;
        while(pos<s.size() && s[pos]=='I'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }else if(pos+1<s.size() && s[pos]=='I' && s[pos+1]=='V'){
        pos+=2;
        x+='4';
    }else{
        cont=0;
        while(pos<s.size() && s[pos]=='I'){
            pos++;
            cont++;
        }
        x+='0'+cont;
    }
    
    while(x.size()>=1 && x[0]=='0') x.erase(0,1);
    
    cout<<x<<endl;
}

int main(){
    string s;
    int N;
    
    cin>>N;
    
    for(int caso=1;caso<=N;caso++){
        cin>>s;
        roman(s);
    }
    
    return 0;
}
