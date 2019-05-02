package string;

public class String1 {
	private char[] chars;
	private int length;
	
	public String1() {
		chars = new char[0];
		length = 0;
	}
	
	public String1(char[] chars) {
		this.chars = chars;
		this.length = chars.length;
	}
	
	public String1(String str) {
		chars = new char[str.length()];
		length = chars.length;
		for (int i = 0; i < length; i++) {
			chars[i] = str.charAt(i);
		}
	}
	
	public int length() {
		return length;
	}
	
	public char charAt(int i) {
		return chars[i];
	}
	
	public String1 substring(int start, int end) {
		if (start < 0 || end < 0 || end < start || start > length || end > length) {
			return null;
		}
		char[] chars2 = new char[end - start];
		for (int i = start, j = 0; i < end; i++, j++) {
			chars2[j] = chars[i];
		}
		return new String1(chars2);
	}
	
	public String1 substring(int start) {
		if (start < 0 || start > length) {
			return null;
		}
		int end = length - 1;
		char[] chars2 = new char[end - start];
		for (int i = start, j = 0; i < end; i++, j++) {
			chars2[j] = chars[i];
		}
		return new String1(chars2);
	}
	
	public String1 toLowerCase() {
		char[] chars2 = new char[length];
		for (int i = 0; i < length; i++) {
			chars2[i] = Character.toLowerCase(chars[i]);
		}
		return new String1(chars2);
	}
	
	public boolean equals(String1 s) {
		if (s.length() != chars.length)
			return false;
		for (int i = 0; i < chars.length; i++) {
			if (this.chars[i] != s.chars[i])
				return false;
		}
		return true;
	}
	
	public String1 valueOf(int i) {
		char[] chars2 = new char[(int)(Math.log10(i))];
		int count = chars2.length;
		while (i > 0) {
			chars2[count] = (char)(i % 10 + '0');
			i /= 10;
			count--;
		}
		return new String1(chars2);
	}
	
	public String1[] split(String1 s) {
		var list = new java.util.ArrayList<String1>();
		int previous = 0;
		boolean found = false;
		for (int i = 0; i < chars.length; i++) {
			if (this.chars[i] == s.chars[i] && this.chars.length - i >= s.chars.length) {
				for (int j = 0; j < s.chars.length; j++) {
					if (s.chars[j] != this.chars[i + j]) {
						found = false;
						break;
					}
				}
				if (found) {
					list.add(this.substring(previous, i + 1));
					i += s.length();
				}
			}
		}
		if (list.isEmpty())
			list.add(this);
		return (String1[])list.toArray();
	}
	
	@Override
	public String toString() {
		return new String(chars);
	}
}
