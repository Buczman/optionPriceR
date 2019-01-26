#include<vector>

class Option{
public:

	//constructor
	Option(
		int nInt_,
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double expiry_,
		double barrier_
		);

	//destructor
	~Option(){};

	//methods
	void generatePath();
	double getDownAndOutCallPrice(int nReps);


	//members
	std::vector<double> thisPath;
	int nInt;
	double strike;
	double spot;
	double vol;
	double r;
	double expiry;
	double barrier;

};
