
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
fun toList A = toListh A (Arrary.length A) 0 []
    
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

fun find (x,S) = <some code here>

<some code here>

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

fun create _ = ref []

fun study _ = ()

fun insert (T as ref l) (k,x) =
    let fun ins [] = [(k,x)]
          | ins ((h as (c,y)) :: t) = 
            if eq(c,k) then (k,x) :: t
            else h :: ins t
    in
        T := ins l
    end

<some code here>

end


(* Exercise 5 *)
structure HashTable : HASH = struct

type key = someType

type 'a table = (key * 'a) list array

val eq = someEq

fun study _ = ()

open Array

fun hash m i = someHash(i) mod m

local (* adj makes n non divisible by numbers in l *)
    fun adj n _ [] = n
      | adj n i (x::l) = 
        if n mod x = 0 then adj (n+i) (i*x) l
        else adj n (i*x) l
in
fun create n = array(adj n 1 [2,3,5], [])
end

<some code here>

fun dup A = 
    let val B = array(size A, []) in
        copy{src=A, si=0, len=NONE, dst=B, di=0};
        B
    end

fun copy(A,B) = 
    if size A = size B then (* hash function is the same, fast copy *)
        Array.copy{src=A, si=0, len=NONE, dst=B, di=0}
    else (* indexes have to be recalculated *)
        (clear B; app (insert B) A)

end

