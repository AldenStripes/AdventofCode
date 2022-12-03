package AdventofCode;
import java.util.*;
public class Day1Part2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int sum = 0;
		int biggestSum = Integer.MIN_VALUE; //There are 254 spaces/empty lines
		int secBiggest = Integer.MIN_VALUE;
		int thrdBiggest = Integer.MIN_VALUE;
		for (int i=0; i<2005; i++) {
			String N = sc.next();
			if (Integer.valueOf(N)==0) { //check if theres an empty line
				sum = 0;
				i --;
			}	else{
				sum += Integer.valueOf(N);
				if (sum>biggestSum) {
					thrdBiggest = secBiggest;
					secBiggest = biggestSum;
					biggestSum = sum;
				}	else if (sum>secBiggest && sum<biggestSum){
					thrdBiggest = secBiggest;
					secBiggest=sum;
				}	else if (sum>thrdBiggest && sum<secBiggest) {
					thrdBiggest = sum;
				}
			}
		}

		System.out.println(biggestSum+secBiggest+thrdBiggest);
	}

}
