person(X):- man(X), !, fail.
person(X):- woman(X).
man(john).
man(mike).
woman(mary).
woman(jenny).