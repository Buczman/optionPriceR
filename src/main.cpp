#include<Rcpp.h>
#include<vector>
#include"Option.h"
#include<ctime>
#include<cstdlib>

using std::vector;
using namespace Rcpp;

// [[Rcpp::export]]
double getDownAndOutCallPrice(int nInt = 0,
							  double Strike = 100,
                              double Spot = 95,
                              double Vol = 0.2,
                              double Rfr = 0.06,
                              double Expiry = 0.5,
							  double Barrier = 90,
                              int nReps = 1000){

	// set the seed
	srand( time(NULL) );
	
	// set nInt to 252 stock days multiplied by Expiry (only if not provided/hacky way to have it as an optiona arg)
	if (nInt == 0)
		nInt = 252 * Expiry;
	
	// create a new instance of class
	Option Option1(nInt, Strike, Spot, Vol, Rfr, Expiry, Barrier);

	// call the method to get price
	double price =	Option1.getDownAndOutCallPrice(nReps);

	// return the price
	return price;
}
