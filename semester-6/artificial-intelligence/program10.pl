go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Enter element to be searched: '),
    read(X),
    write(X),
    own_memb(X, L),
    write(' is a member of the list.');
    write(' is not a member of the list.').

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
own_memb(X, [X|_]).
own_memb(X, [_|Y]):- own_memb(X, Y).

:- initialization(go).