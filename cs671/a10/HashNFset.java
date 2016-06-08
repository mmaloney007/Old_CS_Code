//Victor Maloney CS 671
//November 26, 2001

import java.util.*;

public class HashNFset extends NFset {
	private HashMap set; //the hash map of the set
	private int size; //initial size of the container for the set

	//insert an object into the set
	public void insert(Object elem) {
		if(elem != null)
		{
			this.set.put(elem, elem);
		}
	}

	//Make a clone of the objects
	public Object clone() {
		HashNFset copy = (HashNFset)super.clone();
		copy.set = (HashMap)set.clone();
		copy.size = size;
		return copy;
	}

	//get an iterator
	public java.util.Iterator iterator() {
		return new Iterator(this); 
	}

	//constructor
  	public HashNFset(int num) {
		this.set = new HashMap(num);
		size = num;
	}

	//Secondary Implementations of selected functions
	//a more efficent hasMember
	public boolean hasMember(Object elem) {
		return this.set.containsKey(elem);
	}

	//a more efficent clear
	public void clear() {
		this.set.clear();
	}

	//a more efficent size
	public int size() {
		return this.set.size();
	}

	//a more efficent remove
	public Object remove(Object elem) {
		Object c;
		c = this.set.remove(elem);
		return c;
	}

	//a more efficent isEmpty
	public boolean isEmpty() {
		return this.set.isEmpty();
	}
	
	//an iterator class
	private class Iterator implements java.util.Iterator {
		private int i;
		private Object[] set;
		private HashMap setptr;
		
	private Iterator(HashNFset x) {
		this.set = (x.set.keySet()).toArray();
		setptr = x.set;
		i = 0;
	}

	public void remove() {
		this.setptr.remove(this.set[i - 1]);
	}
		
	public Object next() {
		return this.set[i++];
	}

	public boolean hasNext() {
		if(this.i < this.set.length)
			return true;
		return false;
	}
	}
}
