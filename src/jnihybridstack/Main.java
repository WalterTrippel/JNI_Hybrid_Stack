package jnihybridstack;

public class Main {
	
	public static void fill(int[] array, JNIStackImplementation stack){
		for(int i = 0; i < array.length; ++i){
			stack.push(array[i]);
		}
	}

	public static void main(String[] args) {
		JNIStackImplementation stack = new JNIStackImplementation();
		int[] input = {-7, 6, 4, 3, 1, 89, 45, 3, 5, 9, 10, 11, 1, 7, 8};
		fill(input, stack);
		System.out.println(stack);
	}

}
