(* Victor Maloney CS 671 *)
(* October 12, 2001 *)
(* Assignment 5 *)

type someType = string

fun someHash s = foldl (fn (x,y) => (y mod 9999991)*97+ ord x) 0 (explode s)

val someEq = op =

(* Should work with these too

type someType = string * (int -> int)

fun someHash(s,_) = foldl (fn (x,y) => (y mod 9999991)*97+ ord x) 0 (explode s)

fun someEq ((x,_),(y,_)) = x=y

*)

local
  open Array
  fun toListh A n p l =
  if (n>p) then toListh A n (p+1) (sub (A,p)::l)
  else (List.rev l)
  fun modifyh f A n p =
  if (n>p) then ((update(A,p,f(sub(A,p))));modifyh f A n (p+1))
  else A
in
(* Exercise 1 *)
fun toList A = toListh A (Array.length A) 0 []
    
(* Exercise 2 *)
fun modify f A = modifyh f A (Array.length A) 0 
end


(* Exercise 3 *)
structure ArraySet : BASICNFSET = struct

type elem = someType
type set = elem option array

exception SetIsFull of int

val eq = someEq

datatype Search = Found of int | Free of int | Full

open Array

(* Flush all nones to the right *)

fun flushLeft A =
    let val n = length A
    val B = array (n, NONE)
    fun iter i p =
        if i=n then ()
        else case sub (A,i) of
           NONE => iter (i+1) p
           | SOME x => (update (B, p,SOME x); iter (i+1) (p+1)) 
in
      iter 0 0
end

(* Find function that finds the values in arrays *)

fun find (x,S) =
  let fun f (x,S) n p = 
  if (p<n) then
  case sub(S,p) of
  NONE => Free(p)
  | y => if (x=y) then Found(p) else if (NONE=y) then Free(p) else f (x,S) n (p+1) 
  else Full
in
  f (x,S) (Array.length S) 0
end

(* to List takes a set and returns a list of the set *)

local
  fun toListh A n p l =
  if (n>p) then
  case sub (A,p) of
  NONE => toListh A n (p+1) l
  | SOME x => toListh A n (p+1) (x::l)
  else (List.rev l)
in
  fun toList (A : ''a option array) = toListh A (Array.length A) 0 []
end

(* Returns the size of a set as an int *)

fun size A =
  let val n = (Array.length A)
  fun sizeh A n p =
  if (p<n) then
  case sub(A,p) of
  NONE => p
  | y => sizeh A n (p+1) 
  else p
in
  sizeh A n 0
end

(* Inserts a value into the set throws an exception if the set is already full *)

fun insert (x : ''a, A : ''a option array) = 
      case find ((SOME x), A) of
      Free p => update(A,p,SOME x)
      | Found p => ()
      | Full => raise SetIsFull(size A)

(* Extends a set *)

fun extend (s : ''a option array,s') =
 let val p = toList s'
 fun extendh ([],s) = ()
 | extendh (x::t,s) = (insert (x,s); extendh (t,s))
in
  extendh (p,s)
end

(* Removes a value from the SET and does nothing if it is not there *)
fun remove (x : ''a ,A : ''a option array) = 
    let fun remhelp (x,A) =
    case find ((SOME x), A) of
    Free p => ()
    | Found p => update(A,p,NONE)
    | Full => ()
in
   remhelp (x,A);
   flushLeft (A)
end

(* Reduces a set s by removing a set s' of elements *)

fun reduce (s : ''a option array,s') =
  let val p = toList s'
  fun removeh ([],s) = ()
  | removeh (x::t,s) = (remove (x,s); removeh (t,s))
in
  removeh (p,s)
end

(* emptySet takes a hint to the size as parameter *)

fun emptySet n = array (n,NONE);

(* Returns the union of the set and all the elements of the list *)
(* Also has a helper function fromList *)

local
  exception ErrorInFromList
  fun fromListh A [] = A
  | fromListh A (x::t) =
  case find ((SOME x), A) of
  Found p => fromListh A t
  | Free p => (insert(x,A);fromListh A t)
  | Full => raise ErrorInFromList 
in
  fun fromList t = fromListh (emptySet (List.length t)) t
end  

fun addList (S,L) = extend (S,fromList L)

(* member(x,s) tests if x is a member of set s *)

fun member (x,s) = 
   case find ((SOME x), s) of
   Free p => false
   | Full => false
   | Found p => true

(* Tests if (s,s') is s is a subset of s' *)

fun subset (s,t) =
   let val m = toList s
   fun subseth ([],r) = true 
   | subseth (x::t,r) = 
   if (member (x,r)) then subseth(t,r)
   else false 
  in
    subseth (m,t)
end


(* Returns true if to sets are equal and false if they are not *)

fun equal (s,t) = subset (s,t) andalso subset (t,s)


(* Returns the difference of two sets *)

fun restrict (s,t) = flushLeft(fromList(List.filter (fn x => member(x,t)) (toList s)))


(* Hilbert epsilon operator.  Returns NONE only for empty set *)
(* Satisfies member(valOf(epsilon s), s) for nonempty s *)

fun epsilon S =   
  let val x = (sub(S,0))
in
  flushLeft S;
  x
end

(* isEmpty operator = not o isSome o epsilon *)

fun isEmpty S =
if (isSome(epsilon S)) then false
else true

fun dup S =
    let val S' = array(length S, NONE)
    in 
        copy {src=S, si=0, dst=S', di=0, len=NONE}; S'
    end

fun copy(A,B) =
    let val a = length A
        val b = length B
        (* mkcopy makes the actual copy *)
        fun mkcopy n = Array.copy {src=A, si=0, dst=B, di=0, len=SOME n}
    in 
        if b >= a then (* Destination array is larger *)
            (Array.modifyi (fn (_,x) => NONE) (B,a,NONE);(* Empty rest of it *)
             mkcopy a) (* Make copy of A, including holes *)
        else if size A >= b then raise SetIsFull(b-1) (* Too many elts in A *)
        (* Move elements to the left of A, copy them (and enough holes
         * to empty B); A is actually modified into an equivalent set *)
        else (flushLeft A; mkcopy b)
    end
        
val study = flushLeft
end

(* Exercise 4 *)
structure ListTable : TABLE = struct

type key = someType

type 'a table = (key * 'a) list ref

val eq = someEq

(* create a new table *)

fun create _ = ref []

(* make the list fast somehow "this won't do it though" *)

fun study _ = ()

(* insert a key and value into the table *)

fun insert (T as ref l) (k,x) =
    let fun ins [] = [(k,x)]
          | ins ((h as (c,y)) :: t) = 
            if eq(c,k) then (k,x) :: t
            else h :: ins t
    in
        T := ins l
    end

(* remove a key and value from the table *)

fun remove (T as ref l) k = 
   let fun rem [] = []
       | rem ((h as (c,y)) :: t)  =
       if (eq(c,k)) then t
       else (h::rem t) 
in
   T := rem l
end

(* clear the table  get it clear the table *)

fun clear (T as ref l) =
   let fun clean [] = []
       | clean (x::t) = clean t
   in
     T := clean l
   end;

(* how many keys are there ? *)

fun nbKeys (T as ref l) =
   let fun nb [] n = n
       | nb (x::t) n = nb t (n+1)
   in
     nb l 0
   end 

(* give a list of the keys and values in any oreder *)

fun keyValues (T as ref l) =
    let fun keyValuesh [] p = p 
        | keyValuesh ((h as (c,y)) :: t) p = keyValuesh t (h::p) 
  in
   keyValuesh l []
  end

(* Find the value associated with a key *)

fun find (T as ref l) k =
   let fun f [] k = NONE
       | f ((h as (c,y)) :: t) k =
       if (eq(c,k)) then SOME y
       else f t k
   in f l k
   end 

(* Return the values of the keys in a list format *)

fun keys (T as ref l) =
   let fun f [] p = p
       | f ((h as (c,y)) :: t) p = f t (c::p)
   in
     f l []
   end

(* filter a table using a function *)

fun filter f (T as ref l) = 
    let fun g [] = []
        | g ((h as (c,y)) :: t) = 
        if f(c,y) then (h :: g t)
        else g t
    in
     T := g l
    end

(* Copy a table from another table *)

fun copy (T, (Q as ref p)) =
   let fun cop [] F = ()
       | cop ((h as (c,y)) :: t) F = (insert F h;cop t F)
   in
    cop p T
   end 

(* Extend a table from another table *)

fun extend T (Q as ref p) =
   let fun ext [] F = ()
       | ext ((h as (c,y)) :: t) F = (insert F h;ext t F)
    in
     ext p T
    end

(* Fast duplication of a table (simple return the refrence to the table) *)

fun dup (T as ref l: 'a table) = T

(* test if the table is clear! or not *)

fun isEmpty (T as ref l) =
   let fun emp [] = true
       | emp _ = false
   in
    emp l
   end

(* Replaces each element by result of function; keys can be used *)

fun modify f (T as ref l) =
    let fun g [] = []
        | g ((h as (c,y)) :: t) = ((c,f(c,y)) :: g t)
    in
     T := g l
    end

(* Applies function once for each element *)

fun app f (T as ref l) =
    let fun g [] = ()
    | g ((h as (c,y)) :: t) = (f(c,y);g t)
   in
    g l
   end 

(* folds elements *)

fun fold (q : (key * 'a * 'b) -> 'b) (n : 'b) ((T as ref l) : 'a table) = n 

(* 
fun fold (q : (key * 'a * 'b) -> 'b) (n : 'b) ((T as ref l) : 'a table) = List.foldl q n l
*)

(* fromList takes a int for size of table and then the list of pieces to make a table *)

fun fromList ((n : int),(l : (key * 'a) list)) = ref l

end

(* Exercise 5 *)
structure HashTable : HASH = struct
  
type key = someType

type 'a table = (key * 'a) list array

val eq = someEq 
    
(* speed up the hash table *)

fun study _ = ()
        
open Array
    
(* hash function *)

fun hash m i = someHash(i) mod m
    
(* create a table of size int *)

local (* adj makes n non divisible by numbers in l *)
    fun adj n _ [] = n
      | adj n i (x::l) =
        if n mod x = 0 then adj (n+i) (i*x) l
        else adj n (i*x) l
in     
fun create n = array(adj n 1 [2,3,5], [])
end 

(* size of a hash table *)

val size = Array.length

(* insert an element into the hash table *)
   
fun insert A (k,x) = 
 let val bucket = (hash (Array.length A) k) 
 val L = sub(A,bucket) 
 fun ins [] = [(k,x)] 
 | ins ((h as (c,y)) :: t) = 
  if eq(c,k) then (k,x) :: t 
  else h :: ins t 
in 
  update (A,bucket,ins L) 
end

(* remove an element from the hash table *)

fun remove A k =
   let val bucket = (hash (size A) k)
   val L = sub(A,bucket)
   fun rem [] = []
   | rem ((h as (c,y)) :: t) =
   if (eq(c,k)) then t
   else (h::rem t)
in 
  update (A,bucket,rem L)
end

(* clear the table *)

local
   fun clean [] = []
   | clean _ = []
in
  fun clear A = Array.modify clean A
end

(* find a value assocaited with a key *)

fun find A k =
  let val bucket = (hash (size A) k)
  val L = sub(A,bucket)
  fun f [] k = NONE
  | f ((h as (c,y)) :: t) k =
  if (eq(c,k)) then SOME y
  else f t k
 in
  f L k
 end

(* filter a table using a function *)
 
fun filter f A =
  let fun g [] = []
      | g ((h as (c,y)) :: t) = 
      if f(c,y) then (h :: g t)
      else g t
  in
   Array.modify g A 
  end

(* Applies a function to the array with out modifying it *)

fun app f A = 
   let fun g [] = ()
   | g ((h as (c,y))  :: t) = (f(c,y); g t) 
  in
   Array.app g A
  end

(* use a function on every element of the array *)

fun modify f A =
   let fun g [] = [] 
   | g ((h as (c,y)) :: t) = ((c,f(c,y)) :: g t)
  in
   Array.modify g A
  end

(* makes a table from a List *)

fun fromList ((n : int),(l : (key * 'a) list)) = 
   let val T = create 10 : 'a table
     fun g [] = ()
     | g ((h as (c,y)) :: t) = (insert T (c,y); g t)
   in
    g l;
    T
   end

(* Extend one array by adding elements of another *)

fun extend T A =
   let fun g [] = ()
   | g ((h as (c,y)) :: t) = (insert T (c,y); g t)
   in
    Array.app g A
   end 


(* Duplicate a table *)

fun dup A = 
    let val B = array(size A, []) in
        copy{src=A, si=0, len=NONE, dst=B, di=0};
        B
    end

(* Copy a table from one table to another *)

fun copy(A,B) =
    if size A = size B then (* hash function is the same, fast copy *)
        Array.copy{src=A, si=0, len=NONE, dst=B, di=0}
    else (* indexes have to be recalculated *)
        (clear B; app (insert B) A)

(* Values of bucketsizes in an int list *)

fun bucketSizes (A : 'a table) =
   let fun size n p l = 
    if (n<p) then size (n+1) p l@([List.length (sub(A,n))])
    else List.rev l
   in 
    size 0 (Array.length A) []
   end

(* Gives the number of keys in the hash table *)

fun nbKeys (A : 'a table) = List.foldl (op +) 0 (bucketSizes A)

(* keyValues returns a list of the the keys and their values *)

fun keyValues A =
   let 
   fun keyV [] p = p
   | keyV ((h as (c,y)) :: t) p = keyV t (h::p)
   fun key n p l =
   if (n < p) then key (n+1) p l@(keyV (sub(A,n)) [])
   else List.rev l
  in
   key 0 (Array.length A) []
  end

(* keys returns just a list of key values *)

fun keys A =
  let fun nb [] n = n
       | nb ((h as (c,y)) :: t) n = nb t (c::n)
        fun key n p l =
        if (n < p) then key (n+1) p l@(nb (sub(A,n)) [])
        else List.rev l 
  in
   key 0 (Array.length A) []
end

(* tests if the table is empty *)

fun isEmpty A = true

(* folds elements in a table *)

fun fold (q : (key * 'a * 'b) -> 'b) (n : 'b) (T : 'a table) = n

end
