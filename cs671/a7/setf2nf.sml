functor SetF2NF(S : BASICFSET) : BASICNFSET = struct

exception SetIsFull of int (* never raised *)

type elem = S.elem
type set = S.set ref

(* Equality on elements *)

val eq = S.eq

(* Tests to see if the set is empty *)

fun isEmpty (ref l) = S.isEmpty l

(* Returns an emptySet *)

fun emptySet n = ref (S.emptySet (SOME n))

(* Gives the size of the set or in other words the number of elements*)

fun size (ref l) = S.size l

(* Returns the first elements of the set if there is one *)

fun epsilon (ref l) = S.epsilon l

(* Puts x into the set *)

fun insert (x,(L as ref l)) = L := (S.insert (x,l))

(* Removes x from the set if it is there *)

fun remove (x,(L as ref l)) = L := (S.remove (x,l))

(* Extends one set with the elements from another one *)

fun extend ((L as ref l),(ref t)) = L := (S.union (l,t))

(* Tests to see if x is a member of the set *)

fun member (x,(ref l)) = S.member (x,l)
    
(* Takes the elements of the second set out of the first one *)

fun reduce ((L as ref l),(ref t)) = L := (S.diff (l,t))

(* Makes L the intersection of it and the second set *)

fun restrict ((L as ref l),(ref t)) = L := (S.intersect (l,t))

(* Tests to see if the first set is a subset of the second *)

fun subset ((ref s),(ref t)) = S.subset (s,t)

(* Tests to see if two sets are subsets of one another *)

fun equal ((ref s),(ref t)) = S.equal (s,t)

(* Speeds up the set somehow *)

fun study (L as ref s) = L := (S.study s)

(* Adds the list of elements (t) to the set L *)

fun addList ((L as ref l),t) = L := (S.addList (l,t))

(* Turns the set into a list of the elements *)

fun toList (ref l) = S.toList l

(* Copies the set T into the set L (Makes L identical to T) *)

fun copy ((T as ref t),(L as ref l)) = L := t

(* Returns a duplicate of the Set *)

fun dup (T as ref t) = ref t

end (* SetF2NF *)
