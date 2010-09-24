#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    int scatter=0;
    int aux;
    
    for(int i=0;i<4;i++){
        cin>>s;
        for(int j=0;j<4;j++){
            if(s[j]!='.'){
                aux=s[j]-'A';
                scatter+=abs(i-aux/4)+abs(j-aux%4);
            }
        }
    }
    
    cout<<scatter<<endl;
    
    return 0;
}
