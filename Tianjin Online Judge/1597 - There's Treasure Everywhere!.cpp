#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int n,cont=1,cont1,cont2;
    double x,y;

    while(true){        
        getline(cin,s);
        if(s=="END") break;
        
        cout<<"Map #"<<cont<<endl;
        cont++;
        
        for(int i=0;i<s.size()-1;i++)
            if(s[i]==',') s[i]=' ';
        s.erase(s.size()-1,1);
        
        istringstream is(s);
        x=0;y=0;cont1=0;cont2=0;
        while(is>>n>>s){
            if(s=="N") y+=n*1.0;
            else if(s=="S") y-=n*1.0;
            else if(s=="E") x+=n*1.0;
            else if(s=="W") x-=n*1.0;
            else if(s=="NE"){
                cont1+=n;
                cont2+=n;
            }else if(s=="NW"){
                cont1-=n;
                cont2+=n;
            }else if(s=="SE"){
                cont1+=n;
                cont2-=n;
            }else{
                cont1-=n;
                cont2-=n;
            }
        }
        x+=cont1*sqrt(2)/2;
        y+=cont2*sqrt(2)/2;
        cout<<fixed<<setprecision(3)<<"The treasure is located at ("<<x<<","<<y<<")."<<endl;
        cout<<"The distance to the treasure is "<<sqrt(x*x+y*y)<<"."<<endl<<endl;
    }

    return 0;
}
