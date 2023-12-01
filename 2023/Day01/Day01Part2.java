package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day01Part2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String cur = "";
	static void findFirst(String S) {
		for (int i=0; i<S.length(); ++i) {
			char c = S.charAt(i);
			if (Character.isDigit(c)) {
				cur += c;
				break;
			}
			boolean go = true;
			String threeDigits = S.substring(i, Math.min(i+3, S.length()));
			String fourDigits = S.substring(i, Math.min(i+4, S.length()));
			String fiveDigits = S.substring(i, Math.min(i+5, S.length()));
			switch (threeDigits) {
			case "one": cur += '1'; go = false; break;
			case "two": cur += '2'; go = false; break;
			case "six": cur += '6'; go = false; break;
			}
			switch (fourDigits) {
			case "four": cur += '4'; go = false; break;
			case "five": cur += '5'; go = false; break;
			case "nine": cur += '9'; go = false; break;
			}
			switch (fiveDigits) {
			case "three": cur += '3'; go = false; break;
			case "seven": cur += '7'; go = false; break;
			case "eight": cur += '8'; go = false; break;
			}
			if (!go) {
				break;
			}
		}
	}
	static void findLast(String S) {
		for (int i=S.length()-1; i>=0; --i) {
			char c = S.charAt(i);
			if (Character.isDigit(c)) {
				cur += c;
				break;
			}
			boolean go = true;
			String threeDigits = S.substring(Math.max(0, i-2), i+1);
			String fourDigits = S.substring(Math.max(0, i-3), i+1);
			String fiveDigits = S.substring(Math.max(0, i-4), i+1);
			switch (threeDigits) {
			case "one": cur += '1'; go = false; break;
			case "two": cur += '2'; go = false; break;
			case "six": cur += '6'; go = false; break;
			}
			switch (fourDigits) {
			case "four": cur += '4'; go = false; break;
			case "five": cur += '5'; go = false; break;
			case "nine": cur += '9'; go = false; break;
			}
			switch (fiveDigits) {
			case "three": cur += '3'; go = false; break;
			case "seven": cur += '7'; go = false; break;
			case "eight": cur += '8'; go = false; break;
			}
			if (!go) {
				break;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day1Input.txt"));
		long sum = 0;
		int lineNum = 1;
		while (sc.hasNextLine()) {
			String S = sc.nextLine();
			findFirst(S);
			findLast(S);
			sum += Long.parseLong(cur);
			cur = "";
			lineNum ++;
		}
		sc.close();
		System.out.println("sum: "+sum);
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}
}
