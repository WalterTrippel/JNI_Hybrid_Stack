package jnihybridstack;

import java.io.IOException;



public class Main {
	
	public static void main(String[] args) throws StackMemoryOutOfBoundsException, ClassNotFoundException, IOException{
		Stack<Double> myStack = new Stack<>();
		try {
			for(int k = 0; k < 100; ++k){
				myStack.push(new Double(k));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(myStack);
		myStack = myStack.reverse();
		System.out.println(myStack);
		while(!myStack.isEmpty()){
			myStack.pop();
		}
		/**
		 * Generating Exception
		 * */
		myStack.peek();
		
		
		/*java.util.Stack<Double> sunStack = new java.util.Stack<>();
		double startTime = System.currentTimeMillis();
		System.out.println(startTime);
		for(int k = 0; k < 100; ++k){
			sunStack.push(new Double(k));
		}
		double endTime = System.currentTimeMillis();
		System.out.println(endTime);
		double difference = endTime - startTime;
		System.out.println(difference);
		
		
		Stack<Double> stack = new Stack<>();
		try {
			startTime = System.currentTimeMillis();
			System.out.println(startTime);
			for(int k = 0; k < 100; ++k){
				stack.push(new Double(k));
			}
			endTime   = System.currentTimeMillis();
			System.out.println(endTime);
			difference = endTime - startTime;
			System.out.println(difference);
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(stack);
		stack = stack.reverse();
		System.out.println(stack);*/
		
		
		
		/*Stack<String> first = new Stack<>();
		try {
			first.push("ABC");
			first.push("gfsdhygfjkcjhgrujasxlkdjvhdcjsxlkcdsvhbnckalkcnsdvhbcjkxlkcsdvhbckslxkcdbhvncskcnb");
			first.push("dd");
			first.push("d");
			first.push("gfddjfsdchjnedancbhgyfehujadcndvgfehacsjnbfngesdchzjnfwmefschjnfm2sdhczjndmgrwnsdhzxjnm gsdvzhxjnvsmgdvjnx");
			first.push("gfddjfsdchjnedancbhgyfehujadcndvgfehacsjnbfngesdchzjnfwmefschjnfm2sdhczjndmgrwnsdhzxjnm gsdvzhxjnvsmgdvjnx");
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(first);
		
		
		
		Stack<StringBuilder> second = new Stack<>();
		try {
			second.push(new StringBuilder().append("I"));
			second.push(new StringBuilder().append("have"));
			second.push(new StringBuilder().append("finally"));
			second.push(new StringBuilder().append("done"));
			second.push(new StringBuilder().append("it"));
			second.push(new StringBuilder().append("Even"));
			second.push(new StringBuilder().append("with"));
			second.push(new StringBuilder().append("LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_LARGE_"));
			second.push(new StringBuilder().append("input"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(second.reverse());*/

	}
}
 