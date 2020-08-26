import java.util.Scanner;
class Matrix {
	int row, col;
	int arr[][];
	Matrix(int r, int c) {
		row = r;
		col = c;
		arr = new int[row][col];
		/*for(int i=0;i<row;i++)
			arr[i]=new int[col];*/
	}

	void getElements() {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = sc.nextInt();
			}
			System.out.println();
		}
	}

	Matrix add(Matrix mat) {
		if (row == mat.row && col == mat.col) {
			System.out.println("Matrices are compatible for addition");
			Matrix newMat = new Matrix(row, col);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					newMat.arr[i][j] = arr[i][j] + mat.arr[i][j];
				}
			}
			return newMat;
		} else {
			System.out.println("Matrices are not compatible for addition");
			return null;
		}
	}

	Matrix sub(Matrix mat) {
		if (row == mat.row && col == mat.col) {
			System.out.println("Matrices are compatible for subtraction");
			Matrix newMat = new Matrix(row, col);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					newMat.arr[i][j] = arr[i][j] - mat.arr[i][j];
				}
			}
			return newMat;
		} else {
			System.out.println("Matrices are not compatible for subtraction");
			return null;
		}
	}

	Matrix mul(Matrix mat) {
		if (col == mat.row) {
			System.out.println("Matrices are compatible for multiplication");
			Matrix newMat = new Matrix(row, mat.col);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < mat.col; j++) {
					for (int k = 0; k < col; k++) {
						newMat.arr[i][j] = newMat.arr[i][j] + arr[i][k] * mat.arr[k][j];
					}
				}
			}
			return newMat;
		} else {
			System.out.println("Matrices are not compatible for multiplication");
			return null;
		}
	}

	void trace() {
		if (row != col) {
			System.out.println("For the given matrix, trace cannot be calculated");
		} else {
			int trace = 0;
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					if (i == j) {
						trace += arr[i][j];
					}

			System.out.println("Trace: " + trace);
		}
	}

	boolean checkSymmetric() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] != arr[j][i]) {
					return false;
				}
			}
		}
		return true;
	}

	void showElements() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}

class MatrixDemo {
	public static void main(String args[]) {
		Matrix m1 = new Matrix(3, 3);
		Matrix m2 = new Matrix(3, 3);

		m1.getElements();
		m1.showElements();
		m2.getElements();
		Matrix m3 = new Matrix(3, 3);
		m3 = m1.add(m2);
		m3.showElements();
		Matrix m4 = new Matrix(3, 3);
		m4 = m1.sub(m2);
		m4.showElements();
		Matrix m5 = new Matrix(3, 3);
		m5 = m1.mul(m2);
		m5.showElements();
		m1.trace();
		if (m1.checkSymmetric()) {
			System.out.println("The given matrix is symmetric");
		} else {
			System.out.println("The given matrix is non-symmetric");
		}
	}
}