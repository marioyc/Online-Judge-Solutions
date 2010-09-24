import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class TJU1208{
    public static void main(String args[]){
        int n;

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        try{
            String s=in.readLine();
            StringTokenizer st=new StringTokenizer(s);
            n=Integer.parseInt(st.nextToken());

            if(n==1 || n==2) System.out.println("1");
            else{
                BigInteger f[] = new BigInteger[n];

                f[0]=new BigInteger("1");
                f[1]=new BigInteger("1");

                for(int i=2;i<n;i++) f[i]=f[i-1].add(f[i-2]);

                System.out.println(f[n-1]);
            }
        }catch(IOException e){}
    }
}