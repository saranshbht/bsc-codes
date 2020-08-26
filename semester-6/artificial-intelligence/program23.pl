go:- write('Enter Ordered List 1(-1 to specify end)'),
    nl,
    createList(L1),
    write('List 1: '),
    printList(L1),
    nl,
    write('Enter Ordered List 2(-1 to specify end)'),
    nl,
    createList(L2),
    write('List 2: '),
    printList(L2),
    nl,
    merge(L1, L2, L3),
    write('Merged List: '),
    printList(L3).

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
merge([], L2, L2).
merge(L1, [], L1).
merge([X1|Y1], [X2|Y2], [X1|Z]):- X1 =< X2, merge(Y1, [X2|Y2], Z), !.
merge([X1|Y1], [X2|Y2], [X2|Z]):- X2 < X1, merge([X1|Y1], Y2, Z).

:- initialization(go).