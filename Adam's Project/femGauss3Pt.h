/* 
 femGauss3Pt

 This class stores the gauss point data for three point integration.
*/

#ifndef femGauss3Pt_h
#define femGauss3Pt_h

//#include "femDefine.h"

class femGauss3Pt
{
  private:
	int d_numgp;	//number of Gauss integration points, d_numgp = 3;
	double d_point[3];	//location of Gauss point, i.e. d_point[0] = -0.774596669241483 etc.
	double d_weight[3];	//weight, i e. d_weight[0] = 0.555555555555556 etc.

  public:
    //Constructor
	femGauss3Pt();

    //Destructor
    virtual ~femGauss3Pt();

    // Functions
	int getNumPts() const;	//	return d_numgp;
	double getGaussPt(int gp) const;	//	return d_point[gp];
	double getWeight(int gp) const;		//	return d_weight[gp];
};

#endif
