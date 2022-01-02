import java.io.*;
import java.util.*;


public class JavaGenerics {


	public <dataType> void printArray(dataType[] array) {

		for(int i = 0; i < array.length; i++) {

			System.out.println(array[i]);
		}
	}



	public static void main(String[] args) {

		try {
				System.setIn(new FileInputStream("../io/input.txt"));
				System.setOut(new PrintStream(new FileOutputStream("../io/output.txt")));
		} catch (Exception e) {

			System.err.println("Error : " + e.toString());
		}

		Scanner scanner = new Scanner(System.in);

		JavaGenerics jav = new JavaGenerics();

		Integer[] arr = {1,2,4,5,6};
		String[] str = new String[] {"one", "Two"};

		jav.printArray(arr);
		jav.printArray(str);
		System.out.println(arr.toString());

		


		scanner.close();
	}
}
