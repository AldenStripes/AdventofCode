package AdventofCode;
import java.util.*;
public class Day2part2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int total = 0;
		for (int i=0; i<2500; i++) {
			String opponent = sc.next();
			String you = sc.next();
			if (you.equals("X")) { //Calculate the sum of the transaction
				if (opponent.equals("A")) {
					total = total+3;
				}	else if (opponent.equals("B")) {
					total = total+1;
				}	else {
					total = total+2;
				}
			}	else if (you.equals("Y")) {
				total = total+3;
				if (opponent.equals("A")) {
					total = total+1;
				}	else if (opponent.equals("B")) {
					total = total+2;
				}	else {
					total = total+3;
				}
			}	else {
				total = total+6;
				if (opponent.equals("A")) {
					total = total+2;
				}	else if (opponent.equals("B")) {
					total = total+3;
				}	else {
					total = total+1;
				}
			}
		}
		System.out.println(total);
	}

}
