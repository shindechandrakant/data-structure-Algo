import java.io.*;
import java.util.*;



abstract class Person {

	String name;
	String designation;
	int paymentPerHour;

	Person(String name, String designation, int paymentPerHour) {

		this.name = name;
		this.designation = designation;
		this.paymentPerHour = paymentPerHour;
	}

	public abstract int getSalary();
	public abstract String toString();
}

class Employee extends Person {

	int workingHours;

	public Employee(String name, String designation, int workingHours, int paymentPerHour) {

		super(name, designation, paymentPerHour);
		this.workingHours = workingHours;
	}

	public int getSalary() {

		return 30 * workingHours * paymentPerHour;
	}

	public String toString() {

		return "NAME: " + name + "\ndesignation: " + designation + "\nSalary: " + getSalary();
	}

	public void add(int x, int y) {

		System.out.println("In add x-y");
	}

	public void add(int x, String str) {

		System.out.println("In add x-str");

	}


}


public class JavaOops {

	public static void main(String[] args) {

		try {

			System.setIn(new FileInputStream("../io/input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("../io/output.txt")));
		
		} catch (Exception e) {

			System.err.println("Error : " + e.toString());
		}

		Scanner scanner = new Scanner(System.in);


		Employee employee = new Employee("Chandrakant", "Android Developer", 8, 20);

		employee.add(3,4);
		employee.add(4, "FF");
		System.out.println(employee.toString());


		scanner.close();
	}
}