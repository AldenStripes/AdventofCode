package AdventofCode;
import java.util.*;
public class Day1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int sum = 0;
		int biggestSum = Integer.MIN_VALUE; 
		for (int i=0; i<2005; i++) {
			String N = sc.next();
			if (Integer.valueOf(N)==0) { //check if theres an empty line
				sum = 0;
				i --;
			}	else{
				sum += Integer.valueOf(N);
				if (sum>biggestSum) {
					biggestSum = sum;
				}
			}
		}

		System.out.println(biggestSum);
	}

}
