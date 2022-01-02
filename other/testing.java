import java.io.*;
import java.util.*;


public class testing {

	public static void main(String[] args) {

		try {

			System.setIn(new FileInputStream("../io/input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("../io/output.txt")));
		} catch (Exception e) {

			System.err.println("Error : " + e.toString());
		}

		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		int x = sc.nextInt();
		System.out.println(x+ str);
		
		sc.close();
	}
}