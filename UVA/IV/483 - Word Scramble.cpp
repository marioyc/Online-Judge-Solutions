#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    bool espacio;

    while(getline(cin,s)){
        istringstream is(s);
        espacio=0;
        
        while(is>>s){
            if(espacio) cout<<" ";
            espacio=1;
            
            for(int i=s.size()-1;i>=0;i--) cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}
