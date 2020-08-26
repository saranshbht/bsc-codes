go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    evenlength(L),
    write('The list is of even length');
    write('The list is of odd length').

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
evenlength([]).
evenlength([_|Y]):- oddlength(Y).
oddlength([X|[]]).
oddlength([_|Y]):- evenlength(Y).
:- initialization(go).