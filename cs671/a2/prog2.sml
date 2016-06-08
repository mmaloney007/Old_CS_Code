(* Victor Maloney 9 25 2001 *)
(* GCD function *)
fun gcd (x, 0) = x
| gcd (x,y) = gcd (y, x mod y);
(* sum function on a list of ints *)
fun sum [] = 0
 | sum (x::t) = x + sum t;
(* sum tail recursive *)
local 
   fun sumh [] x = x
   | sumh (y::t) x = sumh t (y+x)
in 
   fun sum [] = 0
   | sum (y::t) = sumh t y
end;
(* natural list *)
local
   fun natListh 0 (x::t) = (x::t)
   | natListh y (x::t) = natListh (y-1) (y::(x::t))
in     
   fun natList 0 = []
   | natList n = natListh (n-1) [n]
end;
(* tail recursive last *)
local
  fun revh (x::nil) l = (x::l)
  | revh (x::y) l = revh y (x::l)
in
  fun rev [] = []
  | rev (x::nil) = (x::nil)
  | rev (x::y) = revh y [x]
end;
(* last function *)
local
   exception Impossible
in 
   fun last [] = raise Impossible
   | last (x::nil) = x
   | last (x::y) = last y 
end;
(* hanoi without list *)
fun hanoi (n,l,c,r) =
   if (n=0) then print("")
   else ((hanoi((n-1),l,r,c);print(" Move "^l^" to "^r^",");(hanoi((n-1),c,l,r))));
(* curry function *)
fun curry f x y = f(x,y);
(* uncurry function *)
fun uncurry g (x,y) = g x y;
(* set functions *)
fun isEmpty [] = true
| isEmpty _ = false;
(* set to a list *)
fun toList [] = []
| toList (l as (x::t)) = l;
(* set from a list *)
fun fromList [] = []
| fromList (l as (x::t)) = l;
(* length of a set *)
fun size [] = 0
| size (x::t) = length (x::t);
(* Equality of two sets *)
fun equal [] [] = true
| equal _ [] = false
| equal [] _ = false
| equal (x::t) (y::l) = (x=y) andalso equal t l;
(* empty set *)
fun emptySet() = [];
(* insert *)
fun insert n [] = [n]
 | insert n (x::t) = (n::(x::t));
(* unoin of two set *)
local
   fun unoinh [] (x::t) l = unoinh [] t (l@[x])
   | unoinh (y::p) (x::t) l = 
     if (y<x) then unoinh p (x::t) (l@[y])
     else if (y=x) then unoinh p t (l@[y])
     else unoinh (y::p) t (l@[x])
    | unoinh (y::p) [] l = unoinh p [] (l@[y])
    | unoinh [] [] l = l
in
   fun unoin g h = unoinh g h []
end;
(* epsilon *)
local
   exception Impossible
in
   fun epsilon [] = raise Impossible
   | epsilon (x::t) = x
end;
(* member of two set *)
fun member x [] = false
 | member x (y::t) =
   if (x=y) then true
  else member x t;
fun subset [] [] = true
| subset [] _ = true
| subset _ [] = false
| subset (x::t) (y::l) =
if (member x (y::l)) then subset t (y::l)
else false;
(* Intersect of two Sets *)
local
   fun intersecth [] (x::t) l = l
   | intersecth (y::p) (x::t) l = 
     if (y=x) then intersecth p t (l@[y])
     else (intersecth p (x::t) (l@[y]); intersecth (x::t) p l)
   | intersecth (y::p) [] l = l
   | intersecth [] [] l = l
in
   fun intersect g h = intersecth g h []
end;
(* Remove a element *)
local 
  exception Impossible;
  fun removeh x [] l = l
  | removeh x (y::t) l = if (x=y) then removeh x t l else removeh x t l@[y]
in
  fun remove x [] = raise Impossible
  | remove x t = removeh x t []
end;
(* Diff of two Sets *)
local
  fun diffh [] t = t
  | diffh (x::l) t = diffh l (remove x t)
in
  fun diff [] t = t
  | diff t [] = t
  | diff t l = diffh (intersect t l) (unoin t l)
end;
(* End Set Functions *)
(* Regular Int Collatz *)
local
   fun collatzh(1,y) = y
   | collatzh(x,y) =                 
   if ((x mod 2) = 0) then collatzh(x div 2,y+1)
   else collatzh ((3*x)+1,y+1)
in
   fun collatz 0 = 0
   | collatz x = collatzh(x,0)
end;
(* Sums function written on it's own *)
fun sums [] = (0,0)
| sums (x::nil) = (x,0)
| sums (x::t::nil) = (x,t)
| sums (x::t::p::nil) = (x+p,t)
| sums (x::t::p::q::nil) = (x+p,t+q)
| sums (x::t::p::l::y) = sums ((x+p)::(t+l)::y);
(* Sums fuction written with sm *)
local
  fun sm [] x y = (x,y)
  | sm [t] x y = (x+t,y)
  | sm (t::i::p) x y = sm p (x+t) (y+i)
in
  fun sums [] = (0,0)
  | sums t = sm t 0 0
end;
(* Roman Function *)
local 
  fun romanh x l =
  if (x >= 1000) then romanh (x - 1000) (l@[#"M"])
  else if (x >= 900) then romanh (x - 900) ((l@[#"C"])@[#"M"])
  else if (x >= 500) then romanh (x - 500) (l@[#"D"])
  else if (x >= 400) then romanh (x - 400) ((l@[#"C"])@[#"D"])
  else if (x >= 100) then romanh (x - 100) (l@[#"C"])
  else if (x >= 90) then romanh (x - 90) ((l@[#"X"])@[#"C"])
  else if (x >= 50) then romanh (x - 50) (l@[#"L"])
  else if (x >= 10) then romanh (x - 10) (l@[#"X"])
  else if (x = 9) then implode ((l@[#"I"])@[#"X"])
  else if (x >= 5) then romanh (x - 5) (l@[#"V"])
  else if (x = 4) then implode ((l@[#"I"])@[#"V"])
  else if (x >= 1) then romanh (x - 1) (l@[#"I"])
  else implode l
in 
  fun roman 0 = ""
  | roman x = romanh x []
end;
(* UnRoman Function *)
local 
  fun unRomanh [] x = x
  | unRomanh (y::t) x =
  if (y = (#"M")) then unRomanh t (x + 1000)
  else if (not(null t) andalso y=(#"C") andalso hd(t)=(#"M")) then unRomanh (tl(t)) (x + 900) 
  else if (y = (#"D")) then unRomanh t (x + 500)
  else if (not(null t) andalso y=(#"C") andalso hd(t)=(#"D")) then unRomanh (tl(t)) (x + 400)
  else if (y = (#"C")) then unRomanh t (x + 100)
  else if (not(null t) andalso y=(#"X") andalso hd(t)=(#"C")) then unRomanh (tl(t)) (x + 90)
  else if (y = (#"L")) then unRomanh t (x + 50)
  else if (y = (#"X")) then unRomanh t (x + 10)
  else if (not(null t) andalso y=(#"I") andalso hd(t)=(#"X")) then (x + 9)
  else if (y = (#"V")) then unRomanh t (x + 5)
  else if (not(null t) andalso y=(#"I") andalso hd(t)=(#"V")) then (x + 4)
  else if (y = (#"I")) then unRomanh t (x + 1)
  else x
in 
  fun unRoman "" = 0
  | unRoman t = unRomanh (explode(t)) 0
end;
(* try Roman *)
local
  fun f x = unRoman(roman x);
  fun g x = x;
  fun diffh [] = []
  | diffh (x::t) = 
  if (f x) = (g x) then diffh t else x::diffh t
in
  fun tryRoman n = diffh (natList n) 
end;
(* subSeqStr Function *)
fun memberh x []  q f= false
 | memberh x (y::t) q f=
   if (x=y) then f (q, t)
   else memberh x t q f;
local
   fun subStrh ([], []) = true
   | subStrh ([], _) = true
   | subStrh (_, []) = false
   | subStrh ((x::t),(y::l)) =
   if (memberh x (y::l) t subStrh) then true
   else false;
in
   fun subSeqStr (t, q) = subStrh ((explode t),(explode q))
end;
