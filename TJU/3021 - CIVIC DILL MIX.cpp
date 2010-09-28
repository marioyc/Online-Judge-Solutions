#include<iostream>
#include<string>

using namespace std;

string conv(int a){
    string romanos="";
    
    while(a>=1000){
        romanos+="M";
        a-=1000;
    }
    if(a>=900){
        romanos+="CM";
        a-=900;
    }
    if(a>=500){
        romanos+="D";
        a-=500;
    }
    if(a>=400){
        romanos+="CD";
        a-=400;
    }
    while(a>=100){
        romanos+="C";
        a-=100;
    }    
    if(a>=90){
        romanos+="XC";
        a-=90;
    }
    if(a>=50){
        romanos+="L";
        a-=50;
    }
    if(a>=40){
        romanos+="XL";
        a-=40;
    }
    while(a>=10){
        romanos+="X";
        a-=10;
    }
    if(a==9){
        romanos+="IX";
        a-=9;
    }
    if(a>=5){
        romanos+="V";
        a-=5;
    }
    if(a==4){
        romanos+="IV";
        a-=4;
    }
    while(a>=1){
        romanos+="I";
        a--;
    }
    return romanos;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int n,sum;
    int caso=1;
    
    int aux,valor;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        sum=0;
        
        for(int i=0;i<n;i++){
            cin>>s;            
            aux=0;
            
            for(int j=s.size()-1;j>=0;j--){
                if(s[j]=='I') valor=1;
                else if(s[j]=='V') valor=5;
                else if(s[j]=='X') valor=10;
                else if(s[j]=='L') valor=50;
                else if(s[j]=='C') valor=100;
                else if(s[j]=='D') valor=500;
                else valor=1000;
                
                if(valor<aux) sum-=valor;
                else sum+=valor;
                aux=valor;
            }
        }
        cout<<"Case "<<conv(caso)<<": "<<conv(sum)<<endl;
        caso++;
    }

    return 0;
}
