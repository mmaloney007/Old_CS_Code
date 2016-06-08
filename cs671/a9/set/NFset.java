public interface NFset extends Cloneable {

    public boolean isEmpty(); // true of a newly created object
  
    public int size();
  
    public Object epsilon(); // returns null iff set is empty
  
    public void insert(Object elem);
  
    public void extend(NFset set);
  
    public boolean hasMember(Object elem); // was "member" in SML
  
    public void reduce(NFset set);
  
    public Object remove(Object elem); // was returning () in SML
  
    public void restrict(NFset set);
  
    public boolean subset(NFset set);
  
    public boolean equals(Object set); // was "equal" in SML
  
    public void study();
  
    public void addArray(Object[] array); // was "addList" in SML
  
    public Object[] toArray(); // was "toList" in SML
  
    public void copyIn(NFset set); // was "copy" in SML
  
    public Object clone(); // was "dup" in SML
  
    public void clear(); // was not present in SML
  
    public java.util.Iterator iterator(); // was not present in SML
}
