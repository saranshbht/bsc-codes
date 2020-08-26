go:- write('Enter List 1(-1 to specify end)'),
    nl,
    createList(L1),
    write('List 1: '),
    printList(L1),
    nl,
    write('Enter List 2(-1 to specify end)'),
    nl,
    createList(L2),
    write('List 2: '),
    printList(L2),
    nl,
    sublis(L2, L1),
    write('List 2 is a sublist of List 1.'), nl;
    write('List 2 is not a sublist of List 1.'), nl.

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

sublis([], _).
sublis([H|T], [H|TS]):- sublis(T, TS).
sublis([H|T], [_|TS]):- sublis([H|T], TS).

:- initialization(go).