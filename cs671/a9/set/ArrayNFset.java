public class ArrayNFset implements NFset {
       private Object[] set; //holds the elements of the set
       private int trs; //true size of the set

      //tests to see if a set is empty
      public boolean isEmpty()
      {
        int a = this.set.length; 
        int i;
        for(i = 0;i < a;i++)
        {
         if(this.set[i] != null)
         {
          return false;
         }
        }
        return true;
      }

      //returns the number of elements in the set
      public int size()
      {
       int a = this.set.length;
       int s = 0;
       int i;
       for(i = 0;i < a;i++)
       {
        if(this.set[i] != null)
        {
         s++;
        }
       }
       return s; 
      } 

      //epsilon
      public Object epsilon()
      {
       int a = this.set.length; 
       int i;
       for(i = 0;i< a;i++)
       {
        if(this.set[i] != null)
        {
         return (Object)this.set[i];
        }
       }
       return null;
      }
   
      //insert an element into the set
      public void insert(Object elem)
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
 
      //extend a set with another set
      public void extend(NFset set)
      {
       Object[] s = set.toArray();
       int a = s.length;
       int i = 0;
       for(i=0;i<a;i++)
       {
        if(s[i] != null)
        {
         this.insert(s[i]);
        }
       }
      }
         
      //tests if an element is in the set
      public boolean hasMember(Object elem)
      {
       int a = this.set.length;
       int i;
       for(i=0;i<a;i++)
       {
        if(this.set[i] != null)
        {
         if(this.set[i].equals(elem))
          return true;
        }
       }
       return false;
      }

      //reduce a set by a set
      public void reduce(NFset set)
      {
       Object[] s = set.toArray();
       int a = s.length;
       int i = 0;
       for(i=0;i<a;i++)
       {
        if(s[i] != null)
        {
         this.remove(s[i]);
        }
       }
      }

      //remove an object from the set
      public Object remove(Object elem)
      {
       int a = this.set.length;
       int i;
       for(i=0;i<a;i++)
       {
        if(this.set[i] != null)
        {
         if(this.set[i].equals(elem))
          this.set[i] = null;
        }
       }
       return elem;
      }

      //restrict
      public void restrict(NFset set)
      {
       Object[] s = set.toArray();
       int a = s.length;
       int i;
       for(i=0;i<a;i++)
       {
        if(s[i] != null)
        {
         if(this.hasMember(s[i]))
         {
          this.remove(s[i]);
         }
        } 
       }
      }
 
      //subset
      public boolean subset(NFset set)
      {
       int a = this.set.length;
       int i;
       for(i=0;i<a;i++)
       {
        if(this.set[i] != null)
        {
         if(!(set.hasMember(this.set[i])))
         {
          return false;
         }
        }
       }
       return true;
      }
         
     //equals
     public boolean equals(Object set)
     {
      if (set instanceof ArrayNFset) {
          ArrayNFset t = (ArrayNFset)set;
          return (this.subset(t) && t.subset(this));
      }
      else
        return false;
     }

     //move all the elements to the left
     public void study()
     {
      int a = this.set.length;
      int i, j;
      Object tmp;
      for(i=0;i<a;i++)
      {
       for(j=i+1; j<a;j++)
       {
        if(this.set[i] == null)
        {
         this.set[i] = this.set[j];
         this.set[j] = null;
        }
       }
      } 
     }
      
     //add an array of elements
     public void addArray(Object[] array)
     {
      int i;
      int a = array.length;
      for(i = 0;i < a;i++)
      {
       this.insert(array[i]);
      }
     }

     //get an array from a set
     public Object[] toArray()
     {
      int numobj = 0;
      int i;
      for(i=0;i<this.set.length;i++)
      {
       if(this.set[i] != null)
       {
        numobj++;
       }
      }
      Object[] s = new Object[numobj];
      numobj = 0;
      for(i=0;i<this.set.length;i++)
      {
       if(this.set[i] != null)
       {
        s[numobj] = this.set[i];
        numobj++;
       }
      }
      return s; 
     } 

     //copyIn 
     public void copyIn(NFset set)
     {
      try{
      set.clear();
      set.extend(this);
      }
      catch (SetException e) { set.clear();
      throw new SetException("Destination too small!");
      }
     }

     //Clone was dup in sml
     public Object clone()
     {
      ArrayNFset res = new ArrayNFset(this.set.length);
      int i = this.set.length;
      for(int a=0;a<i;a++)
       res.set[a] = this.set[a];
      return res;
     }
 
     //clear the set of all elements
     public void clear()
     {
      int a = this.set.length;
      for(int i=0;i<a;i++)
       this.set[i] = null;
     }

     //not yet implemented
     public java.util.Iterator iterator()
     { return (java.util.Iterator)this;}
 
     public ArrayNFset(int num)
     {
      int i;
      set = new Object[num];
      trs = num;
      for(i=0;i<num;i++)
      {
       set[i] = null;
      }
     }  
}
