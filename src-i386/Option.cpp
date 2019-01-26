#include<cmath>
#include<iostream>
#include <algorithm>
#include"Option.h"
#include"Random1.h"

//definition of constructor
Option::Option(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_,
	double barrier_){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		barrier = barrier_;
		generatePath();
}

//method definition
void Option::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear(); 

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * GetOneGaussianByBoxMuller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//method definition
double Option::getDownAndOutCallPrice(int nReps){
	double minPrice = 0.0;
	double rollingSum = 0.0;

	for(int i = 0; i < nReps; i++){
		generatePath();
		
		minPrice = *std::min_element(thisPath.begin(), thisPath.end());
		if (minPrice >= barrier)
			rollingSum += (thisPath.back() > strike) ? (thisPath.back() - strike) : 0;
	}

	return exp(-r * expiry) * rollingSum / double(nReps);

}