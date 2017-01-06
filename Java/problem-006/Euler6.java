/**
 *
 * @author Sohan Nipunage
 */
import java.util.*;
import java.math.*;
public class Euler6 {
    public static void main(String[] args) {
        //start-timer
        Date date=new Date();
        long start_time=Calendar.getInstance().get(Calendar.MILLISECOND);
        int x=0,y=0,xref=0,result=0;
        for(int i=1;i<=100;i++)
        {
            x+=i;
            y+=Math.pow(i,2);
        }
        xref=x*x;
        result=xref-y;
        long current_time=Calendar.getInstance().get(Calendar.MILLISECOND);
        System.out.println(result+"\nCurrent time:"+(current_time-start_time)+"milliseconds");
    }
    
}
