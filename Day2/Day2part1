package AdventofCode;
import java.util.*;
public class Day2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int total = 0;
		for (int i=0; i<2500; i++) {
			String opponent = sc.next();
			String you = sc.next();
			if (you.equals("X")) { //Calculate the sum of the transaction
				total ++;
				if (opponent.equals("A")) {
					total = total+3;
				}	else if (opponent.equals("B")) {
					total = total+0;
				}	else {
					total = total+6;
				}
			}	else if (you.equals("Y")) {
				total = total+2;
				if (opponent.equals("A")) {
					total = total+6;
				}	else if (opponent.equals("B")) {
					total = total+3;
				}	else {
					total = total+0;
				}
			}	else {
				total = total+3;
				if (opponent.equals("A")) {
					total = total+0;
				}	else if (opponent.equals("B")) {
					total = total+6;
				}	else {
					total = total+3;
				}
			}
		}
		System.out.println(total);
	}

}
