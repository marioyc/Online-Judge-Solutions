#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

#define all(v) (v).begin(), (v).end()

using namespace std;

vector<string> v;
vector<string> ax;
string s;
int t,r,c,n,I,J;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

char f(int a, int b){
    if(v[a][b]=='R'){
        for(int i=0;i<4;i++){
            I=a+di[i];
            J=b+dj[i];
            if(I>=0 && I<r && J>=0 && J<c && v[I][J]=='P') return 'P';
        }
        return 'R';
    }else if(v[a][b]=='P'){
        for(int i=0;i<4;i++){
            I=a+di[i];
            J=b+dj[i];
            if(I>=0 && I<r && J>=0 && J<c && v[I][J]=='S') return 'S';
        }
        return 'P';
    }else{
        for(int i=0;i<4;i++){
            I=a+di[i];
            J=b+dj[i];
            if(I>=0 && I<r && J>=0 && J<c && v[I][J]=='R') return 'R';
        }
        return 'S';
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>r>>c>>n;
        
        v.clear();
        
        for(int j=0;j<r;j++){
            cin>>s;
            v.push_back(s);
        }
        
        for(int m=0;m<n;m++){
            ax.clear();
            for(int j=0;j<r;j++){
                s="";
                for(int k=0;k<c;k++){
                    s+=f(j,k);
                }
                ax.push_back(s);
            }
            v=ax;
        }
        
        for(int j=0;j<r;j++) cout<<v[j]<<endl;
        if(i!=t-1) cout<<endl;
    }

    return 0;
}
