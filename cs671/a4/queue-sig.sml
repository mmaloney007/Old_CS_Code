(* Signature for queues *)

signature QUEUE = sig

    exception Empty

    type 'a t
    val empty : 'a t
    val isEmpty : 'a t -> bool
    val deq : 'a t -> 'a t
    val first : 'a t -> 'a
    val enq : 'a * 'a t -> 'a t
    val length : 'a t -> int
end
