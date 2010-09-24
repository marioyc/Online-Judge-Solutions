#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double x1,x2,x3,y1,y2,y3;
    double a,b,c,dif1,dif2,dif3;
    double x,y,z;
    
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
        c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
        
        if(a>b+c || b>c+a || c>a+b) cout<<"Not a Triangle";
        else{
            dif1=fabs(a-b);
            dif2=fabs(b-c);
            dif3=fabs(c-a);
            
            if(dif1<0.01 && dif2<0.01 && dif3<0.01) cout<<"Equilateral ";
            else if(dif1<0.01 || dif2<0.01 || dif3<0.01) cout<<"Isosceles ";
            else cout<<"Scalene ";
            
            /*if(fabs(a*a-b*b-c*c)<1e-7 || fabs(b*b-c*a-a*a)<1e-7 || fabs(c*c-a*a-b*b)<1e-7) cout<<"Right";
            else if(a*a>b*b+c*c || b*b>c*c+a*a || c*c>a*a+b*b) cout<<"Obtuse";
            else cout<<"Acute";*/
            
            
        }
        
        cout<<endl;
    }
    cout<<"End of Output"<<endl;
    
    return 0;
}
