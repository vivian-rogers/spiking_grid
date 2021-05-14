// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <cstdint>
#include <time.h> 
#include <vector>
//using Eigen::MatrixXd;
//using Eigen::Dynamic;

//typedef spikeNeuron(2000,-500,-50) ourNeuron;
//typedef SparseMatrix<int> SpMatrix;
int synapse = 32;
int size = 1500;
lookupVector matrixLookup(size);
int g = 0;
void delay(int n) {
	for(int i=0; i < 2047483648; i++){g++;}
}
int main( ){
	//int size = 1500;
	cout << "Setting up randomly weighted reservoir: " << size*size << " synapses" << endl;
	srand (time(NULL));
	int intercon = 250; //fixed point, is divided by 100 for average 
	cout << "Average forward neuron connectivity: " << float(float(intercon)/float(100)) << endl;
	//SparseMatrix<int,RowMajor> reservoir(size,size);
	MatrixXd reservoir(size,size);
	for (int i=0; i < size; i++){
		for (int j=0; j < size; j++){
			if(rand() % (size*100) <= intercon){
				reservoir(i,j) = rand() % synapse;
			}
		}
	}
	cout << "Setting up " << size << " unit impulse lookup tables... (might take a while)" << endl;
//	std::cout << reservoir << std::endl << std::endl;
	VectorXd resV(size);
	neuronVector resN(size);
	//cout << "Setting up " << size << " input tables...";
	//SparseVector<uint8_t> vec(size);
	for(int i=0; i<size; i++){
		resV.setZero();
		resV(i)=1;
		matrixLookup(i) = reservoir * resV;
			
	}
	while(true){
		//system("clear");
		resV = randInput(50);
		iterate(resV, resN);
		delay(100000000);
		delay(100000000);
		delay(100000000);
		delay(100000000);
		delay(100000000);
		delay(100000000);
		delay(100000000);
		delay(100000000);
	}
}

