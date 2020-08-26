utterance(X):- sentence(X, []).

sentence(A, C):- nounPhrase(A, B), verbPhrase(B, C).

nounPhrase(A, C):- article(A, B), noun(B, C).
nounPhrase(A, B):- noun(A, B).

verbPhrase(A, B):- verb(A, B).
verbPhrase(A, C):- verb(A, B), nounPhrase(B, C).
verbPhrase(A, C):- verb(A, B), prepositionPhrase(B, C).

prepositionPhrase(A, C):- preposition(A, B), nounPhrase(B, C).

preposition([at|X], X).

article([a|X], X).
article([the|X], X).

noun([dog|X], X).
noun([cow|X], X).
noun([moon|X], X).

verb([barked|X], X).
verb([winked|X], X).