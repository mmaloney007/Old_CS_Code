
// Time-stamp: <14 Nov 2001 at 09:29:25 by charpov on berlioz.cs.unh.edu>

import java.util.Iterator;

/* Provides a default implementation of most set functions.  Assumes that 
   elements, as returned by an iterator, are unique
*/

public abstract class NFset implements Cloneable {

	//extend the set by another set
    public void extend(NFset set) {
        for (Iterator iter=set.iterator(); iter.hasNext();) 
            insert(iter.next());
    }

	//make a clone of the set
    public Object clone() {
        try {
            return super.clone(); // access to magic clone from object
        }
        catch (CloneNotSupportedException e) {
            return null;
        }
    }

	//an iterator of the set
    public abstract Iterator iterator();

	//an insert operation for the set
    public abstract void insert(Object elem);

    /* Code for methods size, remove, clear, isEmpty, epsilon, hasMember, 
       addArray, toArray, reduce, restrict, subset, copyIn, study and equals
       should be added here */

	//reduce a set by another set
    public void reduce(NFset set) {
	Object b;
	for (Iterator iter=set.iterator(); iter.hasNext();)
	{
		b = iter.next();
		if(b != null){
			this.remove(b);
		}	
	}
    }

	//returns the size of the set
    public int size() {
	int size = 0;
 	for (Iterator iter=this.iterator(); iter.hasNext();)
		if(iter.next() != null)
		size++;
	return size;
    }	

	//tests to see if a set is truly empty (all spots equal null)
    public boolean isEmpty() {
	for(Iterator iter=this.iterator(); iter.hasNext();)
		if(iter.next() != null)
			return false;
        return true;
    }
   
	//returns a element from the set (returns null if set is empty)
    public Object epsilon() {
        Object b;
	for(Iterator iter=this.iterator(); iter.hasNext();)
        {
		b = iter.next();
		if(b != null)
			return b;
        }
	return null;
    }

	//tests to see if a set has the object elem in it
    public boolean hasMember(Object elem) {
	Object b;
	if(elem != null)
	{
		for(Iterator iter=this.iterator(); iter.hasNext();)
		{
 			b = iter.next();
			if(b != null)	
			{
				if(elem.equals(b))
					return true;
			}
		}
	}
	return false;
    }

	//tests to see if the set this is a subset of set
    public boolean subset(NFset set) {
	Object b;
	for(Iterator iter=this.iterator(); iter.hasNext();)
	{
		b = iter.next();
		if(b != null)
		{
			if(!set.hasMember(b))
				return false;
		}
	}
	return true;
    }

	//tests to see if two sets are equal (they would be subsets of each other)
    public boolean equals(Object set) {
	return this.subset((NFset)set) && ((NFset)set).subset(this);
    }

	//adds an array to the set 
    public void addArray(Object[] array) {
 	int a = array.length;
        int i;
 	for(i = 0;i < a;i++)
	{
	 this.insert(array[i]);
	}
    }

	//moves all the elements to the left of the array
    public void study() {
	Object[] A = this.toArray();
	this.clear();
	int i = 0;
	int a = A.length;
	for(i = 0;i<a;i++)
	{
	 this.insert(A[i]);
	}
    }

	//makes a set into an array
    public Object[] toArray() {
 	int a = this.size();
        Object[] A = new Object[a];
        Object b;
        int i = 0;
	for(Iterator iter=this.iterator(); iter.hasNext();)
	{
         b = iter.next();
	 if(b != null)
	 {
	  A[i++] = b;
         }
        }
	return A;
     }

	//copy this into set
     public void copyIn(NFset set)
     {
	Object[] s  = set.toArray();
	try{
	 set.clear();
	 set.extend(this);
	}
	catch (SetException e) { set.clear(); set.addArray(s);
	throw new SetException("Destination too small!");
	}
     }

	//clear the set
     public void clear()
     {
	for(Iterator iter=this.iterator(); iter.hasNext();)
        {
         iter.next();
  	 iter.remove();
        }
     }

	//remove an object from the array
     public Object remove(Object elem)
     {
        Object b;
	Object c = null;
	for(Iterator iter=this.iterator(); iter.hasNext();)
	{
		b = iter.next();
 		if(b != null)
		{
			if(b.equals(elem))
			{
			 c = b;
			 iter.remove();
			}
		}
	}
	this.study();
   	return c; 
     } 

	//keep on the interstection of the two sets in this
     public void restrict(NFset set) {
       Object[] s = set.toArray();
       int a = s.length;
       int i;
       for(i=0;i<a;i++)
       {
        if(s[i] != null)
        {
         if(!this.hasMember(s[i]))
         {
          this.remove(s[i]);
         }
        }
       }
       Object[] t = this.toArray();
       a = t.length;
       for(i=0;i<a;i++)
       {
        if(t[i] != null)
        {
	 if(!set.hasMember(t[i]))
	 {
	  this.remove(t[i]);
	 }
	}
       }
      }

	//make a string of the set
      public String toString() {
	String str = "ArrayNFset" + ": {";
	Object [] s = this.toArray();
	int a = s.length;
	int i;

	for(i=0;i<a;i++)
	{
		str = str + s[i] + ",";
	}

	str = str + "} ";
	
	return str;
       }
}
