edge(p, q).
edge(q, r).
edge(q, s).
edge(s, t).
route(A, B):- edge(A, B), !.
route(A, B):- edge(A, C),
              route(C, B).