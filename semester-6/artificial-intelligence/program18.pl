go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    maxlist(L, M),
    write('Maximum element of the list: '),
    write(M), nl.

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

own_max(X, Y, M):- X > Y, M is X;
                    M is Y.
maxlistHelper([], CurMax, CurMax).
maxlistHelper([H|T], PrevMax, M):- own_max(H, PrevMax, CurMax), maxlistHelper(T, CurMax, M).
maxlist([H|T], M):- maxlistHelper(T, H, M).
:- initialization(go).