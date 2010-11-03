import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BigInteger sum,a;

        sum = BigInteger.ZERO;

        while(true){
            a = new BigInteger(in.readLine());
            if(a.equals(BigInteger.ZERO)) break;

            sum = sum.add(a);
        }

        System.out.println(sum);
    }
}
