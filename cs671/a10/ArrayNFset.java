public class ArrayNFset extends NFset {
	private Object[] set; //holds the size of the set

        public void insert(Object elem) {
		if(elem != null)
		{
			int a = this.set.length;
			int i;
			for(i=0;i<a && (this.set[i] != null) && !(this.set[i].equals(elem));i++);
			if(i < a)
			{
		 	 if(this.set[i] != elem)
		 	 {
				this.set[i] = elem;
			 }
			}
			else
			{
				throw new SetException("Set is full!");
		 	}
		}
	}

	public Object clone() {
	ArrayNFset res = new ArrayNFset(this.set.length);
	int i = this.set.length; 
	for(int a=0;a<i;a++)
	 res.set[a] = this.set[a];
	return res;
	}

	public java.util.Iterator iterator() {
		return new Iterator(this);
	}

	public ArrayNFset(int num) {
		int i;
		set = new Object[num];
		for(i = 0;i < num; i++)
		{
		 set[i] = null;
		}
	}

	private class Iterator implements java.util.Iterator { 
		private int i; //what index is the iterator on
		private int len; //number of objects
		private Object[] set; //a pointer to the objects

		private Iterator(ArrayNFset x){
                	i = 0;
			len = x.set.length;
			//len = x.size();
			this.set = x.set;	
		}
			
		//removes the element just returned 
	   	public void remove() {
			this.set[(i - 1)] = null;
		}	
	
		//returns the next element of the set
		public Object next() {
			return this.set[i++];
		}

		//tells if the set has a next element
		public boolean hasNext() {
			if(this.i < this.len) {
				return true;
			}
			return false;
		}	
	}
}
