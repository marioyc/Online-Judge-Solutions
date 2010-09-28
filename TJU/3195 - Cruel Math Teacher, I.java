import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;

public class TJU3195{
    public static void main(String args[]){
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        
        try{
            StringTokenizer st=new StringTokenizer(stdin.readLine());

            BigInteger N=new BigInteger(st.nextToken());
            int P=Integer.parseInt(st.nextToken());

            N=N.pow(P);
            String s=N.toString();

            int n=(s.length()+69)/70;

            for(int i=0;i<n;i++) System.out.println(s.substring(70*i,Math.min(70*(i+1),s.length())));
        }catch(IOException e){}
    }
}
