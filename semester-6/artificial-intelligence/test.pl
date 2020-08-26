isPalindrome(L):- reverse(L, R), L = R.
conc([], L2, L2).
conc([X|Y], L2, [X|Z]):- conc(Y, L2, Z).
test(X, Y):- X > 31, !, fail; X > 20, Y = 50 ; Y = 100.
sumto(1, 1).
sumto(N, R):- N1 is N - 1,
              sumto(N1, R1),
              R is R1 + N.
likes(mary, Fruit):- Fruit \= orange.

conc([], L2, L2).
conc([X|Y], L2, [X|Z]):- conc(Y, L2, Z).
my_reverse([], []).
my_reverse([X|Y], R):- my_reverse(Y, R1),
                       conc(R1, [X], R).




    Notes
    DU Question Papers
    SE Projects
    Java
    JavaScript
    Python
    Java Server Pages
    Programs
    Guidelines

Program 24: Write a PROLOG program that will take grammar rules in the following format:
          NT -> (NT | T)*
Where NT is any nonterminal, T is any terminal and Kleene star (*) signifies any number of repetitions, and generate the corresponding top-down parser, that is:
        sentence -> noun-phrase, verb-phrase
        determiner -> [the]
will generate the following:
        sentence (I, O) :- noun-phrase(I,R), verb-phrase (R,O).
        determiner ([the|X], X) :- !.

Contributor: Abhishek Sharma [KMV (DU)]

    noun([dog|X],X).

    noun([cat|X],X).

    noun([mouse|X],X).

    verb([ate|X],X).

    verb([chases|X],X).

    adjective([big|X],X).

    adjective([brown|X],X).

    adjective([lazy|X],X).

    determiner([the|X],X):-!.

    nounphrase(NP,X):- determiner(NP,R),
					noun(R,X).

    nounphrase(NP,X):- determiner(NP,R),
					adjective(R,S2),
					noun(S2,X).

    verbphrase(VP,X):- verb(VP,R),
					nounphrase(R,X).