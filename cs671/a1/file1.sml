fun min2 a b =
  if a<b then a
  else b;
fun min3 a b c =
 if a<c andalso a<b then a
 else if b<a andalso b<c then b
 else c;
fun fact 0 = 1
 | fact l = l * fact (l - 1);
fun len [] = 0
 | len (_::t) = 1 + len t;
fun rev (t) =
     if t = nil then nil
     else rev(tl(t)) @ [hd(t)];
fun sum [] = 0
 | sum (x::t) = x + sum t;
fun prod [0] = 0
| prod [] = 1
| prod (x::t) = x * prod t;
fun last (x::t) =
 if null t then  x
 else last t;
fun gcd (x, y) = 
 if (y = 0) then x
 else gcd(y, x mod y);
fun palindrome t =
 if t = (implode(rev(explode(t)))) then true
 else false;
fun isLetter t =
 if (64 < ord(t)) andalso (122 > ord(t)) then true
else false;
fun toLower t =
 if (64 < ord(t)) andalso (91 > ord(t)) then chr(ord(t)+32)
else t;
fun natList 0 = []
| natList n = natList(n-1) @ [n];
fun isZero (x,y) =
 if (x=0 andalso y>0) then true
 else false;
fun evaluate (x:int, y) = real(x) / real(y);
fun normalize (p, q) =
 if (q > 0 andalso (gcd(p,q) = 1)) then (p, q)
 else if (q < 0) then normalize (~p, ~q)
 else normalize((p div (gcd(p,q))), q div (gcd(p,q)));
fun plus (x,y)(a,b) =
 if (y = b) then (x + a,b)
 else normalize((x*b)+(a*y), y * b);
fun sign (p,q) =
 if (p > 0 andalso q > 0) then 1
 else if (p = 0) then 0
 else if (q = 0) then 0 
 else if (p < 0 andalso q < 0) then 1
 else ~1;
 fun listToLower nil = nil                     
 | listToLower (x::t) = toLower(x) :: listToLower t;
fun stringToLower t = implode(listToLower(explode(t)));
