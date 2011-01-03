#include <string>
#include <iostream>

using namespace std;

string s1,s2;

int main(){

    string a,b;
    int cont,i;    
    bool lleva;
    
    while(1){
        cin>>a>>b;
        if(a=="0" && b=="0") break;
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        lleva=0;
        cont=0;
        
        if(a.size()<b.size()){
            while(a.size()!=b.size()) a+='0';
        }else{
            while(a.size()!=b.size()) b+='0';
        }
        
        for(i=0;i<a.size();i++){
            if(a[i]-'0'+b[i]-'0'+lleva>9){
                cont++;
                lleva=1;
            }else lleva=0;
        }
        
        if(cont==0) cout<<"No carry operation."<<endl;
        else if(cont==1) cout<<1<<" carry operation."<<endl;
        else cout<<cont<<" carry operations."<<endl;
    }

    return 0;
}
