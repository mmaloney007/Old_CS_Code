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

fun fold q n (T as ref l) =  List.foldl (fn ((k,x),y) => f(k,x,y)) e l
(*
fun fold q n (T as ref l) = List.foldl (fn q((x,y),z) => q(x,y,z)) n l
*)

(* fromList takes a int for size of table and then the list of pieces to make a table *)

fun fromList ((n : int),(l : (key * 'a) list)) = ref l

end
