
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

local
    (* order HAS to be "in" *)
    fun toListIn t =
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
end

<some code here>

end (* FsetTree *)


functor NFsetTable(T : TABLE) : BASICNFSET = struct

<some code here>

exception SetIsFull of int (* Set is never full *)

fun filter p = T.filter (p o #1)

fun remove(x,A) = T.remove A x

(* Inefficient *)
fun forall p A = T.fold (fn (k,x,y) => y andalso p k) true A

fun epsilon A = (* Very inefficient *)
    case T.keys A of
        [] => NONE
      | (x::_) => SOME x

<some code here>

end (* NFsetTable *)


functor SetF2NF(S : BASICFSET) : BASICNFSET = struct

exception SetIsFull of int (* never raised *)

<some code here>

end (* SetF2NF *)
