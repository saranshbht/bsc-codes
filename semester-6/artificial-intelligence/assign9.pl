number_of_parents(adam, 0).
number_of_parents(eve, 0).
number_of_parents(X, 2):- X \= adam, X \= eve.
number_of_parents(john, 2).