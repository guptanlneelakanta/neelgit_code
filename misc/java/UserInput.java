
import java.util.Scanner; // 1. Import the Scanner class

public class UserInput{

	public static void main(String[] args )
	{
		System.out.println("hello world");
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("\n enter your name");
		String username = scanner.nextLine();
		
		System.out.println("\n username is  " + username + " welcome");	
		
		scanner.close();
	}

}
