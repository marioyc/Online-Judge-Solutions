#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N;
    cin>>N;
    
    vector< vector<int> > carta;
    vector< vector<int> > z;
    int ax;
    char c,x;
    
    map<char,int> M;
    M['H']=0;
    M['C']=1;
    M['D']=2;
    M['S']=3;
    M['T']=10;
    M['J']=11;
    M['Q']=12;
    M['K']=13;
    
    for(int i=0;i<N;i++){
        carta.clear();
        carta.resize(4);
        
        for(int j=0;j<4;j++){
            cin>>c;
            if(c>='1' && c<='9') carta[j].push_back(c-'0');
            else carta[j].push_back(M[c]);
            cin>>c;
            if(j==0) x=c;
            carta[j].push_back(M[c]);
        }
        
        z.clear();
        z.resize(3);
        
        for(int j=0;j<3;j++){
            z[j].push_back(carta[j+1][0]);
            z[j].push_back(carta[j+1][1]);
        }
        
        for(int j=0;j<2;j++){
            for(int k=j+1;k<3;k++){
                if(z[j][1]>z[k][1] ) swap(z[j],z[k]);
                else if(z[j][1]==z[k][1] && z[j][0]>z[k][0]) swap(z[j],z[k]);
            }
        }
        
        if(carta[1]==z[0]){
            if(carta[2]==z[1]) ax=1;
            else ax=2;
        }else if(carta[1]==z[1]){
            if(carta[2]==z[0]) ax=3;
            else ax=4;
        }else{
            if(carta[2]==z[0]) ax=5;
            else ax=6;
        }
                
        ax+=carta[0][0]-1; ax%=13; ax++;
        
        if(ax>=1 && ax<=9) cout<<ax;
        else if(ax==10) cout<<"T";
        else if(ax==11) cout<<"J";
        else if(ax==12) cout<<"Q";
        else cout<<"K";
        cout<<x<<endl;
    }

    return 0;
}
