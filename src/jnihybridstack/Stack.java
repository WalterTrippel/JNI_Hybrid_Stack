package jnihybridstack;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.Serializable;


public class Stack<T> implements Serializable, Cloneable {

	static {
		System.loadLibrary("HybridStackLibrary");
	}
	
	private byte[] stack;
	
	private final native byte[] init();
	private native void push(byte[] data, byte[] handle);
	private native byte[] peek(byte[] handle);
	private native boolean isEmpty(byte[] handle);
	private native void pop(byte[] handle);
	private native byte[] cloneBuffer(byte[] handle);
	
    public Stack(){
    	this.stack = init();
    }
    
    public Stack<T> reverse(){
    	Stack<T> buffer = (Stack<T>) clone();
    	Stack<T> buf = new Stack<>();
    	try {
    		while(!buffer.isEmpty()){
    			buf.push(buffer.peek());
    			buffer.pop();
    		}
			
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
    	
    	return buf;
    }
	
	public boolean isEmpty(){
		return isEmpty(this.stack);
	}
	
	public void push(T data) throws IOException {
		push(serialize(data), this.stack);
	}

	public T peek() throws ClassNotFoundException, IOException {
		return (T) deserialize(peek(this.stack));
	}
	
	public void pop(){
		pop(this.stack); 
	}
	
	public byte[] serialize(T data) throws IOException{
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		ObjectOutput out = null;
		byte[] myBytes = null;
		try {
			out = new ObjectOutputStream(bos);
			out.writeObject(data);
			myBytes = bos.toByteArray();
		} finally {
			try {
				if(out != null){
					out.close();
				}
			} catch(IOException e) {
				throw new IOException();
			}
			try {
				bos.close();
			} catch(IOException e){
				throw new IOException();
			}
		}
		return myBytes;
	}
	
	@SuppressWarnings("unchecked")
	public Object deserialize(byte[] bytes) throws IOException, ClassNotFoundException{ // Find out true way of deserialization
		ByteArrayInputStream bis = null;
		ObjectInputStream o = null;
		try{
			bis = new ByteArrayInputStream(bytes);
			o = new ObjectInputStream(bis);
			try{
				return o.readObject();
			} catch(EOFException e){
				e.printStackTrace();
			} catch(IOException e1){
				e1.printStackTrace();
			}
		} finally{
			if(bis != null){
				bis.close();
			}
			if(o != null){
				o.close();
			}
		}
		return null;
	}
    
	public byte[] getStack() {
		return stack;
	}

	public void setStack(byte[] stack) {
		this.stack = stack;
	}
	
	@Override
	protected Object clone()  {
		Stack<T> obj;
		try {
			obj = (Stack<T>) super.clone();
			obj.setStack(cloneBuffer(this.stack)); 
			return obj;
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public String toString(){
		int counter = 0;
		StringBuilder sb = new StringBuilder("\n\tTHE STACK IS : \n");
		Stack<T> buffer = (Stack<T>) clone();
		sb.append("[");
		while(!buffer.isEmpty()){
			try {
				sb.append(buffer.peek()).append(", ");
			} catch (ClassNotFoundException | IOException e1) {
				e1.printStackTrace();
			}
			buffer.pop(buffer.getStack());
			++counter;
		}
		if(counter >= 1){ 
			sb.setLength(sb.length() - 2); 
		}
		sb.append("]");
		sb.append("\n");
		return sb.toString();
	}

}
