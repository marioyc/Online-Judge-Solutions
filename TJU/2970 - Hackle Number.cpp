#include <string>
#include <iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int ax;

    while(getline(cin,s)){
        if(s=="6") cout<<"\"Possible.\""<<endl;
        else if (s.size()==1) cout<<"\"Not possible.\""<<endl;
        else{
            ax=s[s.size()-2]*10+s[s.size()-1]-2*'0';
            if(ax%4==2) cout<<"\"Possible.\""<<endl;
            else cout<<"\"Not possible.\""<<endl;
        }
    }
    return 0;
}
