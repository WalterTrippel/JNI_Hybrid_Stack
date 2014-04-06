package jnihybridstack;

public class JNIStackImplementation {
	
	static {
		System.loadLibrary("HybridStackLibrary");
	}
	
    native public void push(int x);
    native public int peek();
    native public boolean isEmpty();
    native public void show();
    native private void remove();
    
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("\n\n\tTHE STACK IS : \n\n");
		sb.append("[");
		while(!isEmpty()){
			sb.append(peek()).append(", ");
			remove();
		}
		sb.setLength(sb.length() - 2); 
		sb.append("]");
		sb.append("\n\n");
		return sb.toString();
	}

}
