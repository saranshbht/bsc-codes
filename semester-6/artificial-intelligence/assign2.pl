split(L, 0, [], L):-!.
split([X|Y], N, [X|Y1], L2):-   N1 is N - 1,
                                split(Y, N1, Y1, L2).