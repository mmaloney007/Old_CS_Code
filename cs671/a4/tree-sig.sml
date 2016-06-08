signature BASICBTREE = sig

    datatype 'a t = EmptyTree | Node of 'a * 'a t * 'a t
    exception Empty

    (* Accessors *)
    val left : 'a t -> 'a t
    val right : 'a t -> 'a t
    val root : 'a t -> 'a

    (* Characteritics *)
    val isEmpty : 'a t -> bool
    val isBalanced : 'a t -> bool
    val isAVL : 'a t -> bool
    val size : 'a t -> int
    val depth : 'a t -> int
    val atDepth : 'a t -> int -> 'a list
    val leaves : 'a t -> 'a list
    val toString : string * string * string * string -> 
    (* strings for: root     left     right    leaf            *)
                   ('a -> string) -> string -> 'a t -> string
    (* string for depth:              ^^^                      *)

    (* Iterators *)
    val map : ('a -> 'b) -> 'a t -> 'b t
    val all : ('a -> bool) -> 'a t -> bool
    val exists : ('a -> bool) -> 'a t -> bool

    (* Misc *)
    val rev : 'a t -> 'a t
end
signature BASICTREE = sig

    datatype 'a t = Node of 'a * 'a t list

    (* Accessors *)
    val children : 'a t -> 'a t list
    val root : 'a t -> 'a

    (* Characteritics *)
    val isBalanced : 'a t -> bool
    val isAVL : 'a t -> bool
    val size : 'a t -> int
    val depth : 'a t -> int
    val atDepth : 'a t -> int -> 'a list
    val leaves : 'a t -> 'a list
    val arity : 'a t -> int
    val toString : string * string ->
    (* strings for: root     leaf                             *)
                   ('a -> string) -> string -> 'a t -> string
    (* string for depth:              ^^^                     *)

    (* Iterators *)
    val map : ('a -> 'b) -> 'a t -> 'b t
    val all : ('a -> bool) -> 'a t -> bool
    val exists : ('a -> bool) -> 'a t -> bool

    (* Misc *)
    val rev : 'a t -> 'a t
end
