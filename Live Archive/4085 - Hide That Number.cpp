#include<iostream>
#include<string>

using namespace std;

int mod11(string number){
    int aux=0;
    
    for(int i=number.size()-1;i>=0;i--)
        if((number.size()-1-i)%2==0) aux+=number[i]-'0';
        else aux-=number[i]-'0';
    
    return (aux%11+11)%11;
}

void resolver_caso(string &number, int &caso){
    cout<<caso<<". ";
    
    int n=number.size();
    int aux=mod11(number);
    int x;
    
    if(number.size()%2==1) x=aux;
    else x=11-aux;
    
    if(x==10) number.insert(0,"10");
    else if(x==11) number.insert(0,"11");
    else{
        char c='0'+x;
        string s="";
        s+=c;
        number.insert(0,s);
    }
    
    string ans="";
    
    aux=0;
    
    for(int i=0;i<number.size();i++){
        aux=aux*10+number[i]-'0';
        ans+=aux/11+'0';
        aux%=11;
    }
    
    while(ans[0]=='0') ans.erase(0,1);
    
    if(ans.size()!=n) cout<<"IMPOSSIBLE"<<endl;    
    else cout<<ans<<endl;
}

int main(){    
    string number;
    int cont=1;
    
    while(1){
        cin>>number;
        if(number=="0") break;
        
        resolver_caso(number,cont);
        cont++;
    }
    
    return 0;
}
