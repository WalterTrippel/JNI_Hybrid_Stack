package jnihybridstack;


public class JNIStackImplementation implements Cloneable {

	static {
		System.loadLibrary("HybridStackLibrary");
	}
	
	private byte[] stack;
	
	private final native byte[] init();
	
	
    native public void push(int x, byte[] handle);
    native public int peek(byte[] handle);
    native public boolean isEmpty(byte[] handle);
    native public void pop(byte[] handle) throws StackMemoryOutOfBoundsException;
    native public byte[] cloneBuffer(byte[] handle);
    
    public JNIStackImplementation(){
    	this.stack = init();
    }
    
	public byte[] getStack() {
		return stack;
	}

	public void setStack(byte[] stack) {
		this.stack = stack;
	}
	
	@Override
	protected Object clone()  {
		JNIStackImplementation obj;
		try {
			obj = (JNIStackImplementation) super.clone();
			obj.setStack(cloneBuffer(stack)); 
			return obj;
		} catch (CloneNotSupportedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public String toString(){
		int counter = 0;
		StringBuilder sb = new StringBuilder("\n\n\tTHE STACK IS : \n\n");
		JNIStackImplementation buffer = (JNIStackImplementation) clone();
		sb.append("[");
		while(!buffer.isEmpty(buffer.getStack())){
			sb.append(buffer.peek(buffer.getStack())).append(", ");
			try {
				buffer.pop(buffer.getStack());
			} catch (StackMemoryOutOfBoundsException e) {
				e.printStackTrace();
			}
			++counter;
		}
		if(counter >= 1){ 
			sb.setLength(sb.length() - 2); 
		}
		sb.append("]");
		sb.append("\n\n");
		return sb.toString();
	}

}
