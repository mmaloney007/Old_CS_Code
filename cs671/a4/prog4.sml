(* Victor Maloney October 10, 2001 *)
(* CS 671 Assignment 4 *)
(* simple queue *)
structure SimpleQueue : QUEUE = struct

type 'a t = 'a list

(* exception for an empty queue *)
exception Empty

(* give an empty queue *)
val empty = []

(* get the first item *)
fun first [] = raise Empty
| first (x::t) = x

(* dequeue "remove item" *)
fun deq [] = raise Empty
| deq (x::t) = t

(* enqueue "add item" *)
fun enq (x,[]) = [x]
| enq (x,t) = t@[x]

(* length of queue function *)
fun length t = List.length t

(* isEmpty function *)
fun isEmpty [] = true
| isEmpty _ = false
end

(* second queue implementation *)
structure Queue : QUEUE = struct

(* types and exceptions *)
type 'a t = 'a list * 'a list
exception Empty

(* empty queue *)
val empty = ([], [])

(* test if queue is empty *)
fun isEmpty ([],[]) = true
| isEmpty q = false

(* find the length of the queue *)
fun length (front,rear) = List.length front + List.length rear

(* put item x on the queue *)
fun enq (x,(front,rear)) = (front,x::rear)

(* remove the first item from the queue *)
fun deq (x::front,rear) = (front,rear)
| deq ([],rear) = case List.rev rear of
[] => raise Empty
| x::front' => (front',[])

(* get the first item in the queue line *)
fun first ([],[]) = raise Empty
| first (x::front,q) = x
| first ([],x::rear) =
if (null rear) then x
else first([],rear)

end

(* basic btree code *)
structure Btree : BASICBTREE = struct

datatype 'a t = EmptyTree | Node of 'a * 'a t * 'a t

(* an empty exception for the trees *)
exception Empty

(* Accessors *)
(* gives the left side of a tree *)
fun left EmptyTree = raise Empty
| left (Node(x,l,r)) = l

(* gives the right branch of the tree *)
fun right EmptyTree = raise Empty
| right (Node(x,l,r)) = r

(* gives the root element *)
fun root EmptyTree = raise Empty
| root (Node(x,l,r)) = x

(*Characteristics *)
(* tells if a tree is empty or not *)
fun isEmpty EmptyTree = true
| isEmpty (Node(x,l,r)) = false

(* gives the size of a tree "number of nodes" *)
fun size EmptyTree = 0
| size (Node(x,l,r)) = size l + size r + 1

(* gives the depth of a tree *)
fun depth EmptyTree = 0
| depth (Node(x,l,r)) = Int.max(depth l, depth r) + 1

(* gives all the nodes at a certain depth *)
local
  fun truedepth EmptyTree n p = []
  | truedepth (Node(x,l,r)) n p =
  if (n = p) then (x::(truedepth l (n+1) p))@(truedepth r (n+1) p)
  else (truedepth l (n+1) p)@(truedepth r (n+1) p)
in
  fun atDepth tree p = truedepth tree 1 p
end

(* finds if a tree is balanced or not *)
fun isBalanced EmptyTree = true
| isBalanced (Node(x,l,r)) =
abs (size l - size r) <= 1 andalso isBalanced l andalso isBalanced r

(* tells is a tree is an AVL tree *)
fun isAVL EmptyTree = true
| isAVL (Node(x,l,r)) =
abs (depth l - depth r) <= 1 andalso isAVL l andalso isAVL r

(* gives a list of leaves for a binary tree *)
fun leaves EmptyTree = []
| leaves (Node(x,EmptyTree,EmptyTree)) = [x]
| leaves (Node(x,l,r)) = leaves(l)@leaves(r)

(* gives the string form of a binary tree *)
fun toString (rts,ls,rs,lfs) (g : 'a -> string) indent EmptyTree = " "
| toString (rts,ls,rs,lfs) (g : 'a -> string) indent (Node(x,l,r)) =
    indent^(g x)^(rts^"\n")^
    (case (l,r) of
    (EmptyTree,r) => toString (rs,ls,rs,lfs) g (indent^".") r
    | (l,EmptyTree) => toString (ls,ls,rs,lfs) g (indent^".") l
    | (l,r) => (toString (" ",ls,rs,lfs) g (indent^".") l)^(toString (" ",ls,rs,lfs) g (indent^".") r)
    )

(* iterators *)
(* maps a funtion to a binary tree *)
fun map f EmptyTree = EmptyTree
| map f (Node(x,l,r)) = (Node(f(x),map f l,map f r))

(* sees if the function is true for all nodes on a binary tree *)
fun all f EmptyTree = true
| all f (Node(x,l,r)) = f(x) andalso all f l andalso all f r

(* implements the function exists on a binary tree *)
fun exists f EmptyTree = false
| exists f (Node(x,l,r)) = f(x) orelse exists f l orelse exists f r

(* misc. *)
(* reverses a binary tree *)
fun rev EmptyTree = EmptyTree
| rev (Node(x,l,r)) = (Node(x,rev r,rev l))
end

(* simple general tree *)
structure Tree = struct
datatype 'a t = Node of 'a * 'a t list

(* accessors *)
fun children (Node(x,l)) = l

fun root (Node(x,_)) = x

(* characteristics *)
(* gives size of a general tree *)
fun size (Node(x,l)) = 1 + (foldl (op +) 0 (List.map size l))

(* gives depth of a general tree *)
fun depth (Node(_,l)) = 1 + (foldl Int.max 0 (List.map depth l))

(* gives the arity of a general tree *)
fun arity (Node(x,l)) = List.length l

(* gives the tree in a string *)
fun toString (rt,lv) g indent (Node(x,l)) = "hello"

(* misc *)

(* reverses a general tree *)
fun rev (Node(x,l)) = (Node(x,List.rev l))

end

(* to List in *)
local
  open Btree
in
  fun toListIn EmptyTree = []
  | toListIn (Node(x,l,r)) = (toListIn l)@[x]@(toListIn r)
end

(* from List In *)
local
    open Btree
  in
    fun fromListIn [] = EmptyTree
    | fromListIn l =
    let val m = ((List.length l) div 2)
    val a = (List.take (l,m))
    val b = (List.drop (l,m))
  in
    (Node(hd(b),fromListIn a,fromListIn (tl(b))))
  end
end
