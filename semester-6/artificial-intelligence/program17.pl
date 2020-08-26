go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    remove_dup(L, R),
    write('List after removing duplicates: '),
    printList(R), nl.

enterElement(X):- write('Enter element: '),
                  read(X).

createList(L):- enterElement(X),
                createListHelper(X, L).
createListHelper(-1, []):- !.
createListHelper(X, [X|Y]):- enterElement(X1),
                       createListHelper(X1, Y).

printList([]).
printList([X|Y]):-  write(X),
                    write(' '),
                    printList(Y).

own_memb(X, [X|_]).
own_memb(X, [_|Y]):- own_memb(X, Y).

remove_dup([], []).
remove_dup([X|Y], R):- own_memb(X, Y),
                       remove_dup(Y, R).
remove_dup([X|Y], [X|R]):- \+own_memb(X, Y),
                            remove_dup(Y, R).
:- initialization(go).