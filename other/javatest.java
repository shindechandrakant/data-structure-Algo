import java.io.*;
import java.util.*;


public class javatest {

	public static void main(String[] args) {

		try {
				System.setIn(new FileInputStream("../io/input.txt"));
				System.setOut(new PrintStream(new FileOutputStream("../io/output.txt")));
		} catch (Exception e) {

			System.err.println("Error : " + e.toString());
		}

		Scanner scanner = new Scanner(System.in);




		scanner.close();
	}
}