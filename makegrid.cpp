
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

const maxAdj = 10; //increase this if you want to play with more connected networks than hex/square grids
const maxArr = 1000; // increase this if you want to increase max side length


tile* grid[maxArr][maxArr];

struct tile { 
	int tileType; //if 0, nothing. if 1, neuron, if 2, synapse
	neuron * n;
	synapse * s;
	tile * adj[maxAdj];

struct neuron {
	double integrated;
	double threshold;
	double refractPeriod;
	bool refracting;
}
	
struct synapse {
	//
	tile* adjTiles[maxAdj/2];
	double weight[maxAdj/2];
	double tLastFire1[maxAdj/2];
	double tLastFire2[maxAdj/2];
}


neuron* neuronInit(int refract, int thresh){
	neuron * n = (neuron *) malloc(sizeof(neuron));
	n->threshold = thresh;
	n->refractPeriod = refract;
	n->integrated = 0;
	n->refracting = False;
	return n;
}


tile* tileInit(){
	tile* t = new tile;
	t->n = 0;
	t->s = 0;
	for(int i = 0; i < maxAdj; i++){
		t->adj[i] = 0;
	}
	return t;
}

tile* makegrid(int sideX, int sideY, int option, tile* (*grid)[]){
	for(int i = 0; i < maxArr; i++){
		for(int j = 0; j < maxArr; j++){
			grid[i][j] = 0;
		}
	}
	for(int i = 0; i < sideX; i++){
		for(int j = 0; j < sideY; j++){
			grid[i][j] = tileInit;
		}
	}
	switch(option) {
		case 0:
			break;
		case 1:
			hexgrid();
			break;
	}

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

