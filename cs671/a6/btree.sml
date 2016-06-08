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
fun atDepth EmptyTree _  = []
| atDepth _ 0 = []
| atDepth (Node(x,_,_)) 1 = [x]
| atDepth (Node(_,l,r)) n = atDepth l (n-1) @ atDepth r (n-1) 

(* finds if a tree is balanced/AVL or not *)
local
  exception UnBalanced
  fun bal _ EmptyTree = 0
  | bal f (Node(_,l,r)) =
    let val (L,R) = (bal f l, bal f r)
    in if abs(L - R) <= 1 then f(L,R)+1 else raise UnBalanced
    end
in
  fun isBalanced t = (bal (op +) t; true) handle Unbalanced => false
  fun isAVL t = (bal (Int.max) t; true) handle Unbalanced => false
end 

(* gives a list of leaves for a binary tree *)
fun leaves EmptyTree = []
| leaves (Node(x,EmptyTree,EmptyTree)) = [x]
| leaves (Node(x,l,r)) = leaves(l)@leaves(r)

(* gives the string form of a binary tree *)
fun toString(root,left,right,leaf) f sep tree =
    let fun mk _ _ EmptyTree acc = acc
        | mk pad com (Node(x,l,r)) acc =
        let val mk' = mk (pad^sep)
            val acc' = acc^pad^(f x)^com 
         in case (l,r) of
                 (EmptyTree,EmptyTree) => acc'^leaf^"\n"
               | (EmptyTree,_) => mk' right r (acc'^"\n")
               | (_,EmptyTree) => mk' left r (acc'^"\n")
               | _ => mk' " " r (mk' " " l (acc'^"\n"))
        end
        in mk " " root tree " "
        end

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
