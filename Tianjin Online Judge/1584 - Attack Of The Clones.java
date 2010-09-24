import java.io.BufferedReader;
import java.math.BigInteger;

public class Main{
    public static void main(String args[]){
        BufferedReader cin = new BufferedReader(new java.io.InputStreamReader(System.in));

        String s;
        BigInteger N;
        int n,m;

        while(true){
            try{
                s=cin.readLine();
                if(s.equals("0")) break;

                N=new BigInteger(s);

                n=N.bitLength();
                m=0;

                for(int i=0;i<n;i++)
                    if(!N.testBit(i)){
                        for(int j=i+1;j<n;j++) if(N.testBit(j)) m++;
                        break;
                    }

                System.out.println(m);
            }
            catch(java.io.IOException e){}
        }
    }
}