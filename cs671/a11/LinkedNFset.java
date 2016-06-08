//Victor Maloney CS 671
//November 27, 2001

import java.util.*;

public class LinkedNFset extends NFset {
	private LinkedList set; //the pointer to the linked list or "set"
	
	//insert an object into the set
	public void insert(Object elem) {
		if(!this.set.contains(elem))
		{
			if(elem != null)
			{
				this.set.addLast(elem);
			}
		}
	}

	//constructor
	public LinkedNFset(int num) {
		this.set = new LinkedList();
	}

	//an iterator for the set
	public java.util.Iterator iterator() {
		return new Iterator(this);
	}

	//clone the set
	public Object clone() {
		Object[] old;
		LinkedNFset copy = new LinkedNFset(0);
	 	old = this.set.toArray();
		for(int i = 0;i<old.length;i++)
			copy.set.addLast(old[i]);
		return copy;
	}

	//Begin the more efficent code
	//A more efficent size
	public int size() {
		return this.set.size();
	}
	
	//A more efficent remove
	public Object remove(Object elem) {
		int i = this.set.indexOf(elem);
		return this.set.remove(i);
	}

	//A more efficent clear
	public void clear() {
		this.set.clear();
	}	

	//A more efficent has member
	public boolean hasMember(Object elem) {
		return this.set.contains(elem);
	}

	//A more efficent toArray
	public Object[] toArray() {
		return this.set.toArray();
	}

	//A more efficent epsilon
	public Object epsilon() {
		return this.set.getFirst();
	}

	private class Iterator implements java.util.Iterator {
		private int i;
		private Object[] set;
		private LinkedList setptr;

		//constructor for the iterator
		private Iterator(LinkedNFset x) {
			this.set = (x.set).toArray();
			setptr = x.set;
			i = 0;
		}

		//remove for iterator
		public void remove() {
			if(i != 0)
			this.setptr.remove(this.set[i - 1]);
		}

		//move to the next element for Iterator 
		public Object next() {
			return this.set[i++];
		}

		//test if a iterator has next 
		public boolean hasNext() {
			if(this.i < this.set.length)
				return true;
			return false;
		}
	}
}
