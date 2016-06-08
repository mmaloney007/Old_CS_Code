interface Counter extends Cloneable {
    public int get(); // returns current counter value and increase it by one
    public void reset(); // reset value to 0; next call to get() returns 0
    public Object clone();
}

class UnboundCounter implements Counter {
	private int count; //the integer that keeps count

	//Returns the current counter value and increases it by one
	public int get() { return count++;
	}

	//Resets the counter value to 0
	public void reset() {
		count = 0;
	}

	//clones the counter
	public Object clone() {
	try{
		UnboundCounter copy = (UnboundCounter)super.clone();
		return copy;
	 }
	 catch (CloneNotSupportedException e) {return null;}
	}

	//constructor for the counter
	public UnboundCounter() {
		count = 0;
	}

}

class CyclicCounter extends UnboundCounter {
	private int db; //interger to mod by

	//return the count
	public int get() {
		return (super.get()) % db;
	}

	//clones the counter
	public Object clone() {
		CyclicCounter copy = (CyclicCounter)super.clone();
		copy.db = this.db;
		return copy;
	}

	//resets the counter
	public void reset() {
		super.reset();
	}
	
	//constructor
	public CyclicCounter(int num) {
		super();
		db = num;
	}
}

class CyclicCounter2 implements Counter {
	private int count;
	private int db;

	//constructor
	public CyclicCounter2(int num) {
		count = 0;
		db = num;
	}

	//resets the counter
	public void reset() {
		count = 0;
	}

	//clones the counter
  	public Object clone () {
	 try {
		CyclicCounter2 copy = (CyclicCounter2)super.clone();
		copy.count = this.count;
		copy.db = this.db;
		return copy;
	 }
	 catch (CloneNotSupportedException e) {return null;}
	}

	//return the count
	public int get() {
		return (count++)%db;
	}
}

public class CounterMain {
    public static void main(String[] args) {
        Counter c = new UnboundCounter();
        for (int i=0; i<10; i++)
            System.out.print(c.get()+" ");
        System.out.println();
        Counter d = (Counter)c.clone();
        for (int i=0; i<10; i++)
            System.out.print(d.get()+" ");
        System.out.println();
        Counter e = new CyclicCounter2(4);
        for (int i=0; i<10; i++)
            System.out.print(e.get()+" ");
        System.out.println();
        Counter f = (Counter)e.clone();
        for (int i=0; i<10; i++)
            System.out.print(f.get()+" ");
        System.out.println();

       // additional output
        Counter x = new UnboundCounter();
        for (int i=0; i<5; i++)
            System.out.print(x.get()+" ");
        Counter y = (Counter)x.clone();
        for (int i=5; i<10; i++)
            System.out.print(x.get()+" ");
        System.out.println();
        for (int i=0; i<10; i++)
            System.out.print(y.get()+" ");
        System.out.println();
        for (int i=0; i<10; i++)
            System.out.print(x.get()+" ");
        System.out.println();
        x = new CyclicCounter(4);
        y = new CyclicCounter(7);
        for (int i=0; i<10; i++)
            System.out.print(x.get()+" ");
        System.out.println();
        for (int i=0; i<10; i++)
            System.out.print(y.get()+" ");
        System.out.println();
        x = (Counter)y.clone();
        for (int i=0; i<10; i++)
            System.out.print(y.get()+" ");
    }
}

/* Expected output:

   0 1 2 3 4 5 6 7 8 9 
   10 11 12 13 14 15 16 17 18 19 
   0 1 2 3 0 1 2 3 0 1 
   2 3 0 1 2 3 0 1 2 3 

*/
