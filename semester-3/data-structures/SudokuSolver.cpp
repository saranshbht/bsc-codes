#include<iostream>
using namespace std;

#define N 9

bool AlreadyInRow(int grid[N][N], int row, int num){
	for(int col = 0; col < N; col++)
		if(grid[row][col] == num)
			return true;
	return false;
}

bool AlreadyInCol(int grid[N][N], int col, int num){
	for(int row = 0; row < N; row++)
		if(grid[row][col] == num)
			return true;
	return false;
}

bool AlreadyInBox(int grid[N][N], int row, int col, int num){
	for(int i = row; i < row + 3; i++)
		for(int j = col; j < col + 3; j++)
			if(grid[i][j] == num)
				return true;
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return !AlreadyInBox(grid, row - row % 3, col - col % 3, num) && !AlreadyInCol(grid, col, num) && !AlreadyInRow(grid, row, num);
}

void printSolution(int grid[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout << grid[i][j] << " ";
		cout << endl << endl;
	}
}

bool findEmpty(int grid[N][N], int &row, int &col){
	for(row = 0; row < N; row++)
		for(col = 0; col < N; col++)
			if(grid[row][col] == 0)
				return true;
	return false;
}

bool sudokuSolver(int grid[N][N]){
	int row, col;
	if(!findEmpty(grid, row, col))
		return true;
	for(int num = 1; num <= 9; num++){
		if(isSafe(grid, row, col, num)){
			grid[row][col] = num;
			if(sudokuSolver(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int sudoku[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> sudoku[i][j];
	cout << endl << endl;
	if(sudokuSolver(sudoku))
		printSolution(sudoku);
	else
		cout << "Solution not possible\n";
	return 0;
}