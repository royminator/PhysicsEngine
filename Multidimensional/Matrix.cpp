#include <vector>
#include <assert.h>
#include <stdio.h>

#include "Matrix.h"

using namespace std;

// --- Constructors ---
Matrix::Matrix() {

	this->m = 0;
	this->n = 0;
}

Matrix::Matrix(unsigned int _m, unsigned int _n) : m(_m), n(_n) {

	assert(_m >= 0);
	assert(_n >= 0);

	const unsigned int rows = this->m;
	const unsigned int cols = this->n;

	this->entries = new double*[rows];
	for(int i = 0; i < rows; i++) {
		this->entries[i] = new double[cols];
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			this->set(i, j, 0);
		}
	}
}

// --- Operators ---

// --- Utility ---

vector<unsigned int> Matrix::get_dimensions() const {

	vector<unsigned int> dimension(2, 0);
	
	dimension[0] = this->m;
	dimension[1] = this->n;

	return dimension;
}

void Matrix::set(unsigned int m, unsigned int n, double entry) {

	if ((m < this->m) && (n < this->n))
		this->entries[m][n] = entry;
	else
		printf("\x1b[31;1m Error: Dimensions out of bounds \x1b[0m \n");
}

void Matrix::print_console() const {

	printf("Matrix = \n");

	for(int i = 0; i < this->m; i++) {
		for(int j = 0; j < this->n; j++) {

			printf("%f\t", this->entries[i][j]);
		}
		printf("\n");
	}
}