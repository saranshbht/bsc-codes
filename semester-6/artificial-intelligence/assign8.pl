origin(pt(X, Y)):- X=0,Y=0.
inside(pt(X, Y), R):- X*X + Y*Y < R*R.