go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Permutations of the List: '), nl,
    own_permutation(L, K),
    printList(K), nl,
    fail;
    write('').

enterElement(X):- write('Enter element: '),
                read(X).

createList(L):- enterElement(X),
                createListHelper(X, L).
createListHelper(-1, []):- !.
createListHelper(X, [X|Y]):- enterElement(X1),
                            createListHelper(X1, Y).

printList([]):- !.
printList([X|Y]):-  write(X),
                    write(' '),
                    printList(Y).

conc([], L2, L2).
conc([X|Y], L2, [X|Z]):- conc(Y, L2, Z).
own_permutation([], []).
own_permutation(L, [H|T]):- conc(V, [H|U], L),
                            conc(V, U, W),
                            own_permutation(W, T).

:- initialization(go).
