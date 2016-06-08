(* Victor Maloney Assignment 6 *)
(* CS 671 Fall 2001 *)
(* October 19, 2001 *)

(* Objects that can be compared with a linear order *)
signature ORDER = sig
    type t
    val eq : t * t -> bool
    val less : t * t -> bool
end

(* Functional sets over binary search trees *)
signature BASICFSETTREE = sig
    include BASICFSET

    val depth : set -> int
    val isBalanced : set -> bool
    val isAVL : set -> bool
end


functor FsetTree(O : ORDER) : BASICFSETTREE = struct

type elem = O.t
type set = elem Btree.t
val eq = O.eq

infix << val op << = O.less

open Btree

local (* remove *)
    fun deleteMax (Node(x,l,EmptyTree)) = (x,l) (* tree cannot be empty *)
      | deleteMax (Node(x,l,r)) = 
        let val (x',r') = deleteMax r
        in (x', Node(x,l,r'))
        end
in
fun remove(_,EmptyTree) = EmptyTree
  | remove(x,Node(y,l,r)) =
    if x<<y then Node(y, remove(x,l), r)
    else if y<<x then Node(y, l, remove(x,r))
    else case (l,r) of
             (EmptyTree,r) => r
           | (l,EmptyTree) => l
           | (l,r) => 
             let val (x',l') = deleteMax l
             in Node(x',l',r)
             end
end 
local (* order HAS to be "in" *) fun toListIn t =
        let fun f EmptyTree acc = acc
              | f (Node(y,l,r)) acc = f l (y :: f r acc)
        in f t []
        end
            
    fun fromListIn [] = EmptyTree
      | fromListIn l = 
        let val n = List.length l div 2
            val x::t = List.drop(l,n) (* non exhaustive but ok *)
        in Node(x, fromListIn (List.take(l,n)), fromListIn t)
        end
in
val toList = toListIn
fun study t = fromListIn (toListIn t) (* rebalances the tree *)
fun filter p t = fromListIn (List.filter p (toListIn t))
(* MY STUFF *)

(* Equality on elements *)
val eq = O.eq

(* Tests to see if x is a member of s *)

fun member (x,s) = List.exists (fn y => eq(x,y)) (toListIn s)

(* tests to see if s is a subset of t *)

fun subset (s,t) = List.all (fn x => member (x,t)) (toListIn s)

(* tests to see if s and t are equal *)

fun equal (s,t) = subset (s,t) andalso subset (t,s)

(* Returns the insterection of s and t *)

fun intersect (s,t) = fromListIn(List.filter (fn x => member(x,t)) (toListIn s))

(* Returns the difference of s and t *)

fun diff (s,t) = fromListIn(List.filter (fn x => not(member(x,t))) (toListIn s))
end


fun emptySet n = EmptyTree 

(* return an element of the set *)

fun epsilon EmptyTree = NONE
| epsilon (Node(x,_,_)) = SOME x 

(* inserts a element into the tree *)

fun insert (x,EmptyTree) = (Node(x,EmptyTree,EmptyTree))
|   insert (x,(T as (Node(y,left,right)))) = 
    if (x<<y) then (Node(y,(insert (x,left)),right))
    else if (y<<x) then (Node(y,left,(insert (x, right)))) 
    else T (* x = y do nothing *)

(* gives the union of set S and set T *)
(* adds list of elements l to set T *)

local
  fun unh [] T = T
  | unh (x::t) T = unh t (insert (x,T))
in
  fun union (S,T) = unh (toList S) T
  fun addList (T,l) = unh l T
end


end (* FsetTree *)

functor NFsetTable (T : TABLE) : BASICNFSET = struct

exception SetIsFull of int (* Set is never full *)

(* My stuff *)

type elem = T.key 
type set = elem T.table 

(* Equality on elements *)

val eq = T.eq

(* Gives you an emptySet *)

val emptySet = T.create

(* Tests to see if the structure is empty *)

val isEmpty = T.isEmpty

(* Lists all the elements *)

val toList = T.keys

(* Returns a duplicate of the structure *)

val dup = T.dup

(* Returns the number of elements in the set *)

val size = T.nbKeys

(* Returns a copy of *)

val copy = T.copy

(* Inserts x into T *)

fun insert (x,T) = T.insert T (x,x) 

(* Tests to see if x is a member of T *)

fun member (x,T) = 
  case T.find T x of
  NONE => false
  | _ => true  

(* Removes anything that does not hold true for p *)

fun filter p = T.filter (p o #1)

(* Removes x and is value from A *)

fun remove(x,A) = T.remove A x

(* My stuff ends for a while *)

(* Inefficient *)
(* PART 3 & 4 *)
(* Tests to see if p is true for all of A *)
  
local
  exception Not
  fun forh p x =
  if (p x) then ()
  else raise Not
in
  fun forall p A = ((T.app (forh p) A); true)  handle Not => false
end

(* Returns a element option from the structure *)

fun epsilon A =
   if (isEmpty A) then NONE
   else SOME (hd(T.keys A))

(* END PART 3 & 4 *)
(* My stuff again *)

(* Puts all the elements of S into T *)

fun extend (T,S) =
   let val l = T.keys S
     fun ins [] T = () 
     | ins (y::t) T = (insert (y,T);ins t T)
   in
    ins l T
   end

(* Takes all the elements of S out of T *)

fun reduce (T,S) = 
   let val l = T.keys S
    fun rem [] T = () 
    | rem (y::t) T = (remove (y,T);rem t T)
   in
    rem l T
   end

(* Adds a list of elements to the S *)

fun addList (S,[]) = ()
| addList (S,y::t) = (insert(y,S);addList(S,t))

(* Replaces S with S / T *)

fun restrict (S,T) = (List.filter (fn x => member(x,S)) (toList T);())

(* Tests if S is a subset of T *)

fun subset (S,T) = List.all (fn x => member(x,T)) (toList S)

(* Tests to see if to sets are equal *)

fun equal (S,T) = subset(S,T) andalso subset(T,S)

(* Makes the structure more organized in some way *)

val study = T.study

end (* NFsetTable *)

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
