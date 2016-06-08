
// Time-stamp: <14 Nov 2001 at 09:47:15 by charpov on berlioz.cs.unh.edu>

import java.util.*;

public class NFsetMain {

    public static void main(String[] args) {

        NFset s1 = new HashNFset(10);
        NFset s2 = new HashNFset(100);
        NFset s3;

        s1.insert("Foo");
        Integer x = new Integer(42);
        s1.insert(x);
        System.out.println(s1.size() + " " + 
                           s1.isEmpty() + " " + 
                           s1.epsilon());

        Integer y = (Integer)s1.remove(new Integer(42));
        System.out.println(s1.size() + " " + 
                           s1.isEmpty() + " " + 
                           s1.epsilon());
        System.out.println("No copy in remove: " + (x==y));

        for (int i=0; i<9; i++)
            s1.insert(new Integer(i));
        System.out.println(s1.size() + " " + s1.epsilon());

        s1.insert(new Integer(5));
        try {
            s1.insert("Bar");
            System.out.println("Insertion succeeded.");
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
            System.out.println("Copy succeeded.");
        }
        catch (SetException e) {
            System.out.println(e);
            if (s1.isEmpty())
                System.out.println("Nothing done");
            else
                System.out.println("Something's been done, though");
        }

        s1.clear();
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
        // Tests on iterators
        for (Iterator iter = s3.iterator(); iter.hasNext();) {
            Object o = iter.next();
            System.out.print(o + " ");
            if (o.equals("Bar"))
                iter.remove();
        }
        System.out.println();
        System.out.println(s3);
        System.out.println(s3.size() + " " + s3.hasMember("Bar"));
    }
}

/* Output with:  NFset s1 = new ArrayNFset(10);
                 NFset s2 = new ArrayNFset(100);

   2 false Foo
   1 false Foo
   No copy in remove: true
   10 Foo
   SetException: Set is full!
   Nothing done
   10 Foo
   10 Foo
   12 Foo
   SetException: Destination not big enough for copy!
   Nothing done
   true and true
   true true 10
   true and true
   true and true
   12 12
   ArrayNFset@3fbdb0: {3,4}
   ArrayNFset@3e86d0: {3,4}
   ArrayNFset@50169: {Foo,Bar,1,2,3,4,5,6,7,8,...}
   Foo Bar 1 2 3 4 5 6 7 8 foo bar 
   ArrayNFset@50169: {Foo,1,2,3,4,5,6,7,8,foo,...}
   11 false
   

   Output with: NFset s1 = new HashNFset(10);
                NFset s2 = new HashNFset(100);

   2 false 42
   1 false Foo
   No copy in remove: true
   10 Foo
   Insertion succeeded.
   11 Bar
   10 Bar
   12 bar
   Copy succeeded.
   true and true
   true true 10
   true and true
   true and true
   12 12
   HashNFset@253498: {4,3}
   HashNFset@1fef6f: {4,3}
   HashNFset@209f4e: {bar,foo,Bar,Foo,8,7,6,5,4,3,...}
   bar foo Bar Foo 8 7 6 5 4 3 2 1 
   HashNFset@209f4e: {bar,foo,Foo,8,7,6,5,4,3,2,...}
   11 false


Output with: NFset s1 = new ArrayNFset(10);
             NFset s2 = new HashNFset(100);

   2 false Foo
   1 false Foo
   No copy in remove: true
   10 Foo
   SetException: Set is full!
   Nothing done
   10 Foo
   10 Foo
   12 bar
   SetException: Set is full!
   Something's been done, though
   true and true
   true true 10
   true and true
   true and true
   12 12
   ArrayNFset@7172ea: {3,4}
   HashNFset@2f6684: {4,3}
   HashNFset@738798: {bar,foo,Bar,Foo,8,7,6,5,4,3,...}
   bar foo Bar Foo 8 7 6 5 4 3 2 1 
   HashNFset@738798: {bar,foo,Foo,8,7,6,5,4,3,2,...}
   11 false

*/
