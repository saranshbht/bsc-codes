#include<iostream>
using namespace std;

void changeVal(int board[][8], int row, int col, int val){
	for(int j = 0; j < 8; j++)
		board[row][j] = val;
	for(int j = 0; j < 8; j++)
		board[j][col] = val;
	for(int i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--)
		board[i][j] = val;
	for(int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++)
		board[i][j] = val;
}

bool putQueen(int board[][8], int row){
	for(int i = 0; i < 8; i++){
		if(board[row][i]){
			changeVal(board, row, i, 0);
			if(row < 8)
				putQueen(board, row + 1);
			else
				return true;
		}
		changeVal(board, row, i, 1);	
	}
	return false;
}


int main(){
	int board[8][8];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j] = 1;
	
	if(putQueen(board, 0)){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
