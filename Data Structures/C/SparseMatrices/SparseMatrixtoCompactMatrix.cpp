#include <iostream> 
using namespace std; 

/* SPARSE MATRIX CLASS
* This Class Converts the Matrix into Compact Matrix Form .
* Also used add() to add two Compact Matrices together.
* 
* @Author: Ausaaf Nabi
*
* 
* @STDIN: row , col
* use insert() to add compact matrix
* or sparsify() it to convert it into the compact from regular matrix 
*/
class Sparse_Matrix { 

	// Double-pointer initialization
	int **CompactMatrix; 
	int **SparseMatrix;

	// dimensions of matrix 
	unsigned int row, col; 
	unsigned int sparseCount; // For optimization
	// total number of elements in matrix 
	int len; 
	
   public: 
	Sparse_Matrix(int r, int c) 
	{ 

	// initialize Variables
	row = r; 
	col = c; 
	len = 0; 
	sparseCount=0;
	
	// Allocating Memory (initializing array dynamically
	CompactMatrix = new int *[(r*c)]; 
	for (int i = 0; i < (r*c); i++) 
		CompactMatrix[i] = new int[3];
	
    // Array of Sparse Matrix
	SparseMatrix = new int *[row];
	for(int i=0;i<row;i++)
		SparseMatrix[i] = new int[col];
	} 
	/* Creates a regular matrix
	* it also calculates the size of sparse matrix 
	*
	*/ 
	void createMatrix(){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>SparseMatrix[i][j];
				if(SparseMatrix[i][j] != 0)
					sparseCount++;
			}
		}
	}
	/* Converts Regular to sparse matrix
 	 * 
	 */
	void Sparsify(){
		for (auto i = 0; i < row; i++) 
			for (auto j = 0; j < col; j++) 
				if (SparseMatrix[i][j] != 0) 
					insert(i, j, SparseMatrix[i][j]); 
	}
	/* insert elements into sparse matrix 
	 *
	 */
	void insert(int r, int c, int val) { 
		// invalid entry 
		if (r > row || c > col) { 
			cout << "Wrong entry"; 
		} 
		else
		{ 
			CompactMatrix[len][0] = r; 
			CompactMatrix[len][1] = c; 
			CompactMatrix[len][2] = val; 
			len++; 
		} 
	} 
	/* Adds two Sparse Matrix in compact form
 	 *
	 */
	void add(Sparse_Matrix b) { 
		int apos = 0, bpos = 0; 
		Sparse_Matrix result(row, col); 
		while (apos < len && bpos < b.len) 
		{ 
			if (CompactMatrix[apos][0] > b.CompactMatrix[bpos][0] || 
			(CompactMatrix[apos][0] == b.CompactMatrix[bpos][0] && 
			CompactMatrix[apos][1] > b.CompactMatrix[bpos][1])) 
			{ 
				result.insert(b.CompactMatrix[bpos][0], b.CompactMatrix[bpos][1],b.CompactMatrix[bpos][2]); 
				bpos++; 
			} 
		    else if (CompactMatrix[apos][0] < b.CompactMatrix[bpos][0] || 
			        (CompactMatrix[apos][0] == b.CompactMatrix[bpos][0] && 
			          CompactMatrix[apos][1] < b.CompactMatrix[bpos][1])) 
    		{ 
	    		result.insert(CompactMatrix[apos][0], CompactMatrix[apos][1], CompactMatrix[apos][2]); 
		    	apos++; 
		    } 
	    	else
		    { 
			    int addedval = CompactMatrix[apos][2] + b.CompactMatrix[bpos][2]; 
	    		if (addedval != 0) 
		    		result.insert(CompactMatrix[apos][0],CompactMatrix[apos][1],addedval); 
                // then insert 
			    apos++; 
			    bpos++; 
	    	} 
	    } 
	    // insert remaining elements 
	    while (apos < len) 
		    result.insert(CompactMatrix[apos][0],CompactMatrix[apos][1], CompactMatrix[apos++][2]); 
    	while (bpos < b.len) 
	    	result.insert(b.CompactMatrix[bpos][0], b.CompactMatrix[bpos][1], b.CompactMatrix[bpos++][2]); 
		// print result 
		result.print(); 
	} 

	// printing matrix 
	void print() { 
		cout<<"\nDimension: " << row << "x" << col; 
		cout<<"\nSparse Matrix: ";
		cout<<"\nRow\tColumn\tValue\n"; 
	
		for (int i = 0; i < len; i++) 
		{ 
			cout<<CompactMatrix[i][0]<<"\t "<<CompactMatrix[i][1]<<"t"<<CompactMatrix[i][2]<<endl; 
		} 
	} 
}; 

// Driver Code 
int main() 
{ 

	int row, col;
	cin>>row>>col;
	Sparse_Matrix a(row, col); 
	Sparse_Matrix b(row, col); 
	a.createMatrix();
	b.createMatrix();
	a.Sparsify();
	b.Sparsify();
	a.print();
	b.print();
	/*
	Can Also be initialized in this way
	a.insert(1, 2, 10); 
	b.insert(1, 3, 8); 
	*/
	cout << "\n\nAddition: "; 
	a.add(b); 
	return 0;
} 
