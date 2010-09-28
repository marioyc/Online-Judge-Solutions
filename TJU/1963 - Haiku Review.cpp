#include <string>
#include <iostream>

using namespace std;

bool vocal(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    short cont;
    int ax;
    
    while(getline(cin,s))
    {
        if(s=="e/o/i") break;
        cont=0;
        
        ax=0;
        while(s[ax]!='/'){
            if(vocal(s[ax])){
                cont++;
                while(vocal(s[ax])) ax++;
                continue;
            }
            ax++;
        }
        ax++;
        if(cont!=5){
            cout<<1<<endl;
            continue;
        }
        
        cont=0;
        while(s[ax]!='/'){
            if(vocal(s[ax])){
                cont++;
                while(vocal(s[ax])) ax++;
                continue;
            }
            ax++;
        }
        ax++;
        if(cont!=7){
            cout<<2<<endl;
            continue;
        }
        
        cont=0;
        while(ax<s.size()){
            if(vocal(s[ax])){
                cont++;
                while(vocal(s[ax]) && ax<s.size()) ax++;
                continue;
            }
            ax++;
        }
        if(cont!=5){
            cout<<3<<endl;
            continue;
        }
        
        cout<<"Y"<<endl;
    }

    return 0;
}
