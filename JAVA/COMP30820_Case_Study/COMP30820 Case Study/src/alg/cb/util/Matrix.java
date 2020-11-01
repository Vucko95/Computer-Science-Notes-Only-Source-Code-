/**
 * A class to represent a matrix (2-D array)
 */

package alg.cb.util;

public class Matrix {
	private double[][] matrix; // the data structure used to store matrix elements

	/**
	 * constructor - creates a new Matrix object (with a minimum of one row and one column)
	 * @param nrows - the number of rows in the matrix
	 * @param ncols - the number of columns in the matrix
	 */
	public Matrix(int nrows, int ncols) {
		nrows = (nrows < 1) ? 1 : nrows;
		ncols = (ncols < 1) ? 1 : ncols;
		matrix = new double[nrows][ncols];
	}

	/**
	 * adds a value to the matrix
	 * @param rowId - the row id
	 * @param colId - the column id
	 * @param value - the value to be added
	 * @return true if the value is added; false otherwise
	 */
	public boolean addValue(int rowId, int colId, double value) {
		if (rowId < 0 || rowId >= matrix.length || colId < 0 || colId >= matrix[0].length)
			return false;
		else {
			matrix[rowId][colId] = value;
			return true;
		}
	}

	/**
	 * @param rowId - the row id
	 * @param colId - the column id
	 * @return the value corresponding to (rowId, colId) or -1 if the element is not present in the matrix
	 */
	public double getValue(int rowId, int colId) {
		if (rowId < 0 || rowId >= matrix.length || colId < 0 || colId >= matrix[0].length)
			return -1;
		else
			return matrix[rowId][colId];
	}
}
