package jnihybridstack;


public class Main {
	
	public static void fill(int[] array, JNIStackImplementation stack){
		for(int i = 0; i < array.length; ++i){
			stack.push(array[i], stack.getStack());
		}
	}

	public static void main(String[] args) throws CloneNotSupportedException, StackMemoryOutOfBoundsException{
		JNIStackImplementation stack = new JNIStackImplementation();
		int[] input = {-7, 6, 4, 3, 1, 89, 45, 3, 5, 9, 11, 1, 7, 8};
		fill(input, stack);
		JNIStackImplementation second = (JNIStackImplementation) stack.clone();
		second.pop(second.getStack());  
		System.out.println(second);
		System.out.println(stack);
		
		JNIStackImplementation second1 = (JNIStackImplementation) stack.clone();
		System.out.println(second1);
	}
}
 