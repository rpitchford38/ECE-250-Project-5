/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  rdpitchf @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter) 20663181
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#ifndef nullptr
#define nullptr 0
#endif

#include <iostream>
#include <limits>
#include "Exception.h"
#include "ece250.h"

// include whatever classes you want

//template <typename Type>
class Weighted_graph {
	private:
		// your implementation here
		//  you can add both private member variables and private member functions

		//This is a pointer to the matrix
		double **matrix;
		//This is an array to keep track of what degree each vertex is.
		int * Degree;
		//This is a number which corresponds to an NxN matrix
		int matrix_size;
		//This is how many edges are in the graph
		int edges;

		static const double INF;

	public:
		Weighted_graph( int = 50);
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double distance( int, int );

		void insert( int, int, double );
		void print();
		void printing(double *);

	// Friends

	//friend std::ostream &operator<<( std::ostream &, Weighted_graph const & );
};


//template <typename Type>
Weighted_graph::Weighted_graph(int m) {
	int M = m;
	if (m <= 0){
		M = 1;
	}
	matrix = new double * [M];
	Degree = new int[M];
	//This creates a square matrix
	for (int i = 0; i < M; i++) {
		matrix[i] = new double [M];
		for (int a = 0; a < M; a++) {
			matrix[i][a] = { INF };
		}
		Degree[i] = 0;
	}
	matrix_size = M;
	edges = 0;
}


//template <typename Type>
Weighted_graph::~Weighted_graph() {
	//delete the matrix
	delete [] matrix;
}


//template <typename Type>
void Weighted_graph::print() {

	for (int i = 0; i < matrix_size; i++ ) {
		for(int j = 0; j < matrix_size; j++){
			std::cout << " " << matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) {
		std::cout << " " << Degree[i] << std::endl;
	}
}


//template <typename Type>
int Weighted_graph::degree(int n) const {
	//Make sure the the vertex n is in the graph
	if ((n-1) > matrix_size || n < 0){
		throw illegal_argument();
	}
	//return the degree of the vertex
	else
	{
		return Degree[n];
	}
}



//template <typename Type>
int Weighted_graph::edge_count() const {
	//Return the number of edges in the graph
	return edges;
}


//template <typename Type>
double Weighted_graph::adjacent(int n, int m) const {

	//Make sure the vertices are in the graph
	if (m < 0 || (m - 1) > matrix_size || n < 0 || (n - 1) > matrix_size || n == m) {
		throw illegal_argument();
	}
	//Make sure that the vertices are not the same
	else if (n == m) {
		return 0;
	}
	//make sure that there is a connection or weight between both matrices
	else if (matrix[n][m] != 0) {
		return INF;
	}
	//Otherwise return the weight between both verticies
	else {
		return matrix[n][m];
	}
}



//template <typename Type>
//double Weighted_graph::distance(int n, int m) {
//	//Create 2 new arrays
//	bool * visited = new bool[matrix_size];
//	double * weight = new double[matrix_size];
//
//	for (int i = 0; i < matrix_size; i++)
//	{
//		visited[i] = false;
//		weight[i] = INF;
//	}
//
//
//
//	//int a = 0;
//	int current_node = n;
//	while (visited[current_node] == false || current_node != m) {
//		//std::cout << "a" << a << std::endl;
//		//a++;
//
//		for (int i = 0; i < matrix_size; i++) {
//			//checks to see if there is something in the matrix
//			if (matrix[current_node][i] != INF) {
//				//If there is something in the matrix and nothing in the weight, set the weight
//				//if (weight[i] == INF) {
//				if (weight[i] == INF) {
//					//visited[i] = true;
//					weight[i] = matrix[current_node][i];
//				}
//				//If there is something in the matrix and something in the weight, check for the 'lowest' weight.
//				else {
//					if (weight[i] > matrix[current_node][i] + weight[current_node])
//					{
//						//visited[i] = true;
//						weight[i] = matrix[current_node][i] + weight[current_node];
//					}
//				}
//			}
//		}
//		//This searches through the weighted list to find the next lowest node
//		double min = 9999999;
//		int index;
//		for (int a = 0; a < matrix_size; a++) {
//			if (weight[a] < min && visited[a] == false)
//			{
//				min = weight[a];
//				index = a;
//			}
//		}
//		//set current node to true because we have just visited it
//		visited[current_node] = true;
//		//set current node to the next node
//		current_node = index;
//	}
//
//	return weight[m];
//}

	////Start a vertex n
	//for (int i = 0; i < matrix_size; i++) {
	//	if (matrix[n][i] != INF) {
	//		if (weight[i] == INF) {
	//			visited[i] = true;
	//			weight[i] = matrix[n][i];
	//		}
	//		else if()
	//		visited[i] = true;
	//		weight[i] = matrix[n][i];
	//	}
	//}
	//int index;
	//for (int i = 0; i < matrix_size; i++) {
	//	if (weight[i] != INF) {
	//		if (weight[i] < min)
	//		{
	//			min = weight[i];
	//			index = i;
	//		}
	//	}
	//}



//template <typename Type>
void Weighted_graph::insert(int n, int m, double w) {

	if (w <= 0) {
		throw illegal_argument();
	}
	else if (w == INF) {
		throw illegal_argument();
	}
	else if (w > 0)
	{
		if (n == m) {
			throw illegal_argument();
		}
		if (m < 0 || (m-1) > matrix_size || n < 0 || (n-1) > matrix_size || n == m)
		{
			throw illegal_argument();
		}
		matrix[n][m] = w;
		matrix[m][n] = w;
		Degree[n]++;
		Degree[m]++;
	}
}

void Weighted_graph::printing(double w[]) {
	for (int i = 0; i < matrix_size; i++) {
		std::cout << w[i] << " ";
	}
	std::cout << std::endl;
}

//template <typename Type>
const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

// Your implementation here

// You can modify this function however you want:  it will not be tested
//template <typename Type>
//std::ostream &operator<<( std::ostream &out, Weighted_graph const &graph ) {
//	return out;
//}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?





double Weighted_graph::distance(int n, int m) {
	//Create 2 new arrays
	bool * visited = new bool[matrix_size];
	double * weight = new double[matrix_size];

	for (int i = 0; i < matrix_size; i++)
	{
		visited[i] = false;
		weight[i] = INF;
	}


	//printing(weight);

	int index = m;

	//cycle through each row once at the most.
	for (int i = 0; i < matrix_size; i++) {

		//Assign the proper weights
		//Go through each column in the the row
		for (int a = 0; a < matrix_size; a++)
		{
			//double test = matrix[m][a];
			//If we haven't visited the node and the node is empty, add the weight straight to it.
			if ((visited[a] == false) && (weight[a] == INF) && (matrix[index][a] != INF)) {

				if (weight[a] > weight[index] + matrix[index][a]) {
					weight[a] = (weight[index] + matrix[index][a]);
				}
				else {
					weight[a] = matrix[index][a];
				}
				
			}

			//if the weight already in the spot
			if (visited[a] == false && weight[a] != INF) {

				//if the weight already in the spot is more than
				//the weight of the current node plus the weight between the current node and whichever node
				if (weight[a] > weight[index] + matrix[index][a]) {
					weight[a] = (weight[index] + matrix[index][a]);
				}
			}
			//std::cout << index << " ";
			//printing(weight);
		}
		visited[index] = true;

		int next_index = 0;;
		int used = 0;
		double lowest_value = INF;

		//find the lowest weight that has not been visited, in order to find the next row to search through.
		for (int a = 0; a < matrix_size; a++)
		{
			/*if (a == 0) {
				lowest_value = weight[a];
				next_index = a;
			}*/
			if (visited[a] == false && weight[a] <= lowest_value) {
				lowest_value = weight[a];
				next_index = a;
				used = 1;
			}
			
		}
		if (used == 0) {
			return INF;
		}
		if (next_index == n) {
			return weight[n];
		}
		index = next_index;
	}
	return weight[n];
}

#endif

