length_of([], 0).
length_of([X|Y], N):- length_of(Y, N1),
                      N is N1 + 1.

is_even([]):- !.
is_even(L):- length_of(L, N),
             0 is mod(N, 2).