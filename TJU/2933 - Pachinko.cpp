#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int h,w;
vector<string> machine;
double expected[100][100];

double calcular(int a, int b){
    if(b==h) return 0.0;
    
    if(expected[b][a]!=-1.0) return expected[b][a];
    
    if(machine[b][a]=='*'){
        expected[b][a]=calcular(a-1,b)*0.5+calcular(a+1,b)*0.5;
        return expected[b][a];
    }else if(machine[b][a]>='1' && machine[b][a]<='9'){
        expected[b][a]=(machine[b][a]-'0');
        return expected[b][a];
    }else return calcular(a,b+1);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t;
    string s;
    
    double max_expected;
    double result;
    
    cin>>t;
        
    for(int caso=0;caso<t;caso++){
        cin>>h>>w;
        
        machine.clear();
        
        for(int i=0;i<h;i++){
            cin>>s;
            machine.push_back(s);
        }
        
        max_expected=0.0;
        
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++) expected[i][j]=-1.0;
        
        for(int i=0;i<w;i++)
            max_expected=fmax(max_expected,calcular(i,0));
        
        printf("%.6f\n",max_expected);
    }
}
