(* Time-stamp: <03 Oct 2001 at 17:23:52 by charpov on berlioz.cs.unh.edu> *)
(* Nonfunctional and hash tables *)

signature TABLE = sig
    type key
    type 'a table

    (* Equality on keys *)
    val eq : key * key -> bool

    (* int is rough size of the table;  might be adjusted by implementation *)
    val create : int -> 'a table

    (* Empties the table *)
    val clear : 'a table -> unit

    (* Fast duplication of a table *)
    val dup : 'a table -> 'a table

    (* Copy of a table into another table, possibly of different size *)
    val copy : 'a table * 'a table -> unit

    (* Adds elements of second table into first table *)
    val extend : 'a table -> 'a table -> unit

    (* Applies function once for each element; keys can be used *)
    val app : (key * 'a -> unit) -> 'a table -> unit

    (* Replaces each element by result of function; keys can be used *)
    val modify : (key * 'a -> 'a) -> 'a table -> unit

    (* Folds elements, keys can be used *)
    val fold : ((key * 'a * 'b) -> 'b) -> 'b -> 'a table -> 'b

    (* No keys in table *)
    val isEmpty : 'a table -> bool

    (* Keeps elements that satisfy predicate; keys can be used *)
    val filter : (key * 'a -> bool) -> 'a table -> unit

    (* Number of keys *)
    val nbKeys : 'a table -> int

    (* Insertion of element and key *)
    val insert : 'a table -> key * 'a -> unit

    (* Removal of element corresponding to key *)
    val remove : 'a table -> key -> unit

    (* Lookup for element corresponding to key *)
    val find : 'a table -> key -> 'a option

    (* Keys in table, any order *)
    val keys : 'a table -> key list

    (* Pair-list representation of table, any order *)
    val keyValues : 'a table -> (key * 'a) list

    (* Builds table of size int from pair list representation *)
    val fromList : int * (key * 'a) list -> 'a table

    (* Leaves table semantically unchanged but optimized in some way *)
    val study : 'a table -> unit

end

(* Hash tables *)
signature HASH = sig

    include TABLE
    
(* Sizes of buckets *)
val bucketSizes : 'a table -> int list
end
