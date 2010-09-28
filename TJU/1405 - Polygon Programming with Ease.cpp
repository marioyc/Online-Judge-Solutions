#include<cstdio>
#include<vector>

using namespace std;

int main(){
    vector<double> x;
    vector<double> y;
    int n;
    double a,b;
    
    while(scanf("%d",&n)==1){
        x.clear();
        y.clear();
        
        for(int i=0;i<n;i++){
            scanf(" %lf %lf",&a,&b);
            
            x.push_back(a);
            y.push_back(b);
        }
        
        a=b=0;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=x[i];
                b+=y[i];
            }else{
                a-=x[i];
                b-=y[i];
            }
        }
        
        printf("%d %.6lf %.6lf",n,a,b);
        
        for(int i=0;i<n-1;i++){
            printf(" %.6lf %.6lf",2*x[i]-a,2*y[i]-b);
            a=2*x[i]-a;
            b=2*y[i]-b;
        }
        
        printf("\n");
    }
    
    return 0;
}
