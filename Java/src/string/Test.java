package string;

public class Test {
	public static void main(String[] args) {
		char[] chars = "Hello there".toCharArray();
		String1 str = new String1(chars);
		System.out.println(str);
		System.out.println(str.toLowerCase());
		System.out.println(str.substring(1, 5));
		System.out.println(str.substring(5));
	}
}
