#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int coef,exp;
    bool ok;
    
    while(getline(cin,s)){
        istringstream is(s);
        exp=8;
        ok=true;
        while(is>>coef){
            if(coef!=0){
                if(coef!=1){
                    if(coef==-1){
                        if(exp==0 && ok) cout<<-1;
                        else if(exp==0) cout<<" - "<<1;
                        else if(!ok) cout<<" - ";
                        else cout<<"-";
                    }
                    else if(coef<0 && ok) cout<<coef;
                    else if(coef<0) cout<<" - "<<-coef;
                    else if(!ok) cout<<" + "<<coef;
                    else cout<<coef;
                }
                else if(exp==0 && ok) cout<<1;
                else if(exp==0) cout<<" + "<<1;
                else if(!ok) cout<<" + ";
                
                if(exp>0) cout<<"x";
                if(exp>1) cout<<"^"<<exp;
                
                ok=false;
            }else if(exp==0 && ok) cout<<0;
            exp--;
        }
        cout<<endl;
    }

    return 0;
}
