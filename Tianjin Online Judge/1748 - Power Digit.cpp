#include <string>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int M[10][4];
    int n[10];
    
    n[0]=1; M[0][0]=0;
    n[1]=1; M[1][0]=1;
    n[2]=4; M[2][1]=2; M[2][2]=4; M[2][3]=8; M[2][0]=6;
    n[3]=4; M[3][1]=3; M[3][2]=9; M[3][3]=7; M[3][0]=1;
    n[4]=2; M[4][1]=4; M[4][0]=6;
    n[5]=1; M[5][0]=5;
    n[6]=1; M[6][0]=6;
    n[7]=4; M[7][1]=7; M[7][2]=9; M[7][3]=3; M[7][0]=1;
    n[8]=4; M[8][1]=8; M[8][2]=4; M[8][3]=2; M[8][0]=6;
    n[9]=2; M[9][1]=9; M[9][0]=1;
    
    string a,b;
    int ax;
    while(1){
        cin>>a>>b;
        if(a=="0" && b=="0") break;
        
        if(b=="0"){
            cout<<1<<endl;
            continue;
        }
        
        b.insert(0,"0");
        ax=(b[b.size()-2]-'0')*10+b[b.size()-1]-'0';
        //cout<<a<<" "<<b<<" "<<ax<<endl;
        cout<<M[a[a.size()-1]-'0'][ax%n[a[a.size()-1]-'0']]<<endl;
    }

    return 0;
}
