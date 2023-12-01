package AdventOfCode2022;
import java.util.*;
public class Day6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String text = sc.next();
		
		for (int i=3; i<4095; i++) {
			if (text.charAt(i)!=text.charAt(i-1) && text.charAt(i)!=text.charAt(i-2) && text.charAt(i)!=text.charAt(i-3)&&text.charAt(i-1)!=text.charAt(i-2)&&text.charAt(i-1)!=text.charAt(i-3)&&text.charAt(i-2)!=text.charAt(i-3)) {
				System.out.println(i+1);
			}
		}
	}

}
