#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct punto{
    char letra;
    int x;
    int y;
    
    punto(char a, int b, int c){
        letra=a;
        x=b;
        y=c;
    }
};

vector<punto> v;

int area(int a, int b, int c){
    return abs(v[a].x*v[b].y+v[b].x*v[c].y+v[c].x*v[a].y-v[a].y*v[b].x-v[b].y*v[c].x-v[c].y*v[a].x);
}

int S,S1,S2,S3;

bool comprobar(int a, int b, int c){
    
    for(int i=0;i<v.size();i++){
        if(i!=a && i!=b && i!=c){
            S1=area(a,b,i);
            S2=area(b,c,i);
            S3=area(c,a,i);
            if(S1+S2+S3==S || ((S1==0 || S2==0 || S3==0) && S1+S2+S3==S)  ) return false;
        }
    }
    
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,x,y;
    char letra;
    int A_max,A;
    string s;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        v.clear();
        
        for(int i=0;i<n;i++){
            cin>>letra>>x>>y;
            v.push_back(punto(letra,x,y));
        }
        
        A_max=-1;
        s="   ";
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    S=area(i,j,k);
                    if(S>A_max && comprobar(i,j,k)){
                        A_max=S;
                        s[0]=v[i].letra;
                        s[1]=v[j].letra;
                        s[2]=v[k].letra;
                    }
                }
            }
        }
        
        cout<<s<<endl;
    }

    return 0;
}
