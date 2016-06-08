
(* Time-stamp: <28 Sep 2001 at 16:44:03 by charpov on berlioz.cs.unh.edu> *)
(* Functional and nonfunctional set signatures *)

signature BASICFSET = sig (* Functional sets *)

    type elem (* Elements in the set *)
    type set  (* The set itself *)
         
    (* Equality on elements *)
    val eq : elem * elem -> bool
                            
    (* Takes a hint at size as parameter *)
    val emptySet : int option -> set

    (* True iff set is empty.  Equiv "not o isSome o epsilon" or "=0 o size" *)
    val isEmpty : set -> bool

    (* Number of elements in the set *)
    val size : set -> int

    (* Hilbert epsilon operator.  Returns NONE only for empty set
     * Satisfies member(valOf(epsilon s), s) for nonempty s *)
    val epsilon : set -> elem option 

    (* insert(x,s) returns s U {x} *)
    val insert : elem * set -> set
                               
    (* Set union U (symmetric) *)
    val union : set * set -> set

    (* Membership *)
    val member : elem * set -> bool

    (* Set difference \ (nonsymmetric) *)
    val diff : set * set -> set

    (* remove(x,s) returns S \ {x} *)
    val remove : elem * set -> set
                               
    (* Set intersection (symmetric) *)
    val intersect : set * set -> set

    (* Subset relation: subset(s,s') iff all members of s are members of s' *)
    val subset : set * set -> bool

    (* equal(s,s') = subset(s,s') /\ subset(s',s) *)
    val equal : set * set -> bool

    (* Returns the union of the set and all elements of the list *)
    val addList : (set * elem list) -> set

    (* Returns the list of all elements in the set (any order) *)
    val toList : set -> elem list

    (* Returns a set semantically equivalent to param, optimized in some way *)
    val study : set -> set
end

signature FSET = sig

    include BASICFSET

(* True iff predicate is true for all elements in set *)
val forall : (elem -> bool) -> set -> bool
                                      
(* True iff predicate is true for at least one element is set *)
val exists : (elem -> bool) -> set -> bool
                                      
(* Returns the set all elements in param that satisfy predicate *)
val filter : (elem -> bool) -> set -> set
                                      
(* app f s executes f(x) once and once only for all x in s *)
val app : (elem -> unit) -> set -> unit
                                   
(* map f {x, y, z, ...} = {f(x), f(y), f(z), ...} *)
val map : (elem -> elem) -> set -> set
                                   
(* fold f e {x, y, z, ...} = f(..., f(z, f(y, f(x,e)))...) (any order) *)
val fold : ((elem * 'a) -> 'a) -> 'a -> set -> 'a 
end                                               

    
signature BASICNFSET = sig (* Nonfunctional sets (side effect) *)

    type elem
    type set

    (* Raised if set becomes too big by insert, extend, addList or copy
     * Should not be raised before size reaches at least hint
     * Returns size of full set *)
    exception SetIsFull of int

    (* Equality on elements *)
    val eq : elem * elem -> bool

    (* Only creator, hint at size is mandatory *)
    val emptySet : int -> set

    (* Same as above *)
    val isEmpty : set -> bool

    (* Same as above *)
    val size : set -> int

    (* Same as above *)
    val epsilon : set -> elem option

    (* insert(x,s) replaces s with s U {x} *)
    val insert : elem * set -> unit

    (* extend(s,s') replaces s with s U s' *)
    val extend : set * set -> unit

    (* Same as above *)
    val member : elem * set -> bool

    (* reduce(s,s') replaces s with s \ s' *)
    val reduce : set * set -> unit

    (* remove(x,s) = reduce(s,{x}) *)
    val remove : elem * set -> unit

    (* restrict(s,s') replaces s with intersection of s and s' *) 
    val restrict : set * set -> unit

    (* Same as above *)
    val subset : set * set -> bool

    (* Same as above *)
    val equal : set * set -> bool

    (* Leaves set semantically unchanged but optimized in some way *)
    val study : set -> unit

    (* addList s [x, y, z, ...] = extend s {x, y, z, ...} *)
    val addList : (set * elem list) -> unit

    (* Same as above *)
    val toList : set -> elem list

    (* copy(s,s') replaces s' with s and leaves s unchanged *)
    val copy : set * set -> unit

    (* Returns a copy of set (only functional operation)
     * dup s is equivalent to (but more efficient than):
     * let val s' = emptySet(...) in copy(s,s'); s' end *)
    val dup : set -> set
end

signature NFSET = sig

include BASICNFSET

(* filter p s removes from s all elements that do not satisfy p *)
val filter : (elem -> bool) -> set -> unit
                                      
(* Same as above *)
val app : (elem -> unit) -> set -> unit
                                   
(* modify f s replaces s with map f s *) 
val modify : (elem -> elem) -> set -> unit
                                      
(* Same as above *)
val fold : ((elem * 'a) -> 'a) -> 'a -> set -> 'a 
                                               
(* Same as above *)
val forall : (elem -> bool) -> set -> bool
                                      
(* Same as above *)
val exists : (elem -> bool) -> set -> bool
end
