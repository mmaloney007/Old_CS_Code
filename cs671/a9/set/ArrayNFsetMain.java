
// Time-stamp: <06 Nov 2001 at 18:31:40 by charpov on berlioz.cs.unh.edu>

public class ArrayNFsetMain {

    public static void main(String[] args) {

        NFset s1 = new ArrayNFset(10);
        NFset s2 = new ArrayNFset(100);
        NFset s3;

        s1.insert("Foo");
        s1.insert(new Integer(42));
        System.out.println(s1.size() + " " + 
                           s1.isEmpty() + " " + 
                           s1.epsilon());

        s1.remove("Foo");
        System.out.println(s1.size() + " " + 
                           s1.isEmpty() + " " + 
                           s1.epsilon());

        for (int i=0; i<9; i++)
            s1.insert(new Integer(i));
        System.out.println(s1.size() + " " + s1.epsilon());

        s1.insert(new Integer(5));
        try {
            s1.insert("Bar");
        }
        catch (SetException e) {
            System.out.println(e);
            System.out.println("Nothing done");
        }
        System.out.println(s1.size() + " " + s1.epsilon());

        s1.remove(new Integer(0));
        s1.insert("Bar");
        System.out.println(s1.size() + " " + s1.epsilon());

        s1.copyIn(s2);
        s2.addArray(new String[] {"foo", "bar"});
        System.out.println(s2.size() + " " + s2.epsilon());

        s1.clear();
        try {
            s2.copyIn(s1);
        }
        catch (SetException e) {
            System.out.println(e);
            if (s1.isEmpty())
                System.out.println("Nothing done");
            else
                System.out.println("Something's been done, though");
        }

        s3 = (NFset)s2.clone();
        s1.insert(new Integer(3));
        s1.insert(new Integer(4));
        s2.reduce(s1);
        System.out.println(s1.hasMember(new Integer(3)) + " and " +
                           !s2.hasMember(new Integer(3)));
        System.out.println(s2.subset(s3) + " " + !s3.subset(s2) + " " + 
                           s2.size());

        s2.extend(s1);        
        System.out.println(s2.equals(s3) + " and " + s3.equals(s2));

        s2.restrict(s1);
        System.out.println(!s2.equals(s3) + " and " + s1.equals(s2));

        System.out.println(s3.toArray().length + " " + s3.size());
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
    }
}

/* Output:

   2 false Foo
   1 false 42
   10 0
   SetException: Set is full!
   Nothing done
   10 0
   10 Bar
   12 Bar
   SetException: Destination not big enough for copy!
   Nothing done
   true and true
   true true 10
   true and true
   true and true
   12 12
   ArrayNFset@4672d0: {3,4}
   ArrayNFset@1bd03e: {3,4}
   ArrayNFset@4abc9: {Bar,42,1,2,3,4,5,6,7,8,...}
*/
