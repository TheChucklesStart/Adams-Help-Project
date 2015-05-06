/* 
 femMaterial

 This class stores the gauss point data for three point integration.
*/

#ifndef femMaterial_h
#define femMaterial_h

//#include "utlMatrix.h"
#include <iostream>

using namespace std;

class femMaterial
{
  protected:
	int d_id;
    //Never used constructors.
	femMaterial();
	femMaterial(const femMaterial &mat);

  public:
	//Constructors
	femMaterial(int id);

    //Destructor
    virtual ~femMaterial();

    //Functions
	int getID() const;	//	return d_id;
//	virtual void getDMatrixStress(utlMatrix &d) = 0;	//pure virtual function
//	virtual void getDMatrixHeat(utlMatrix &d) = 0;
	virtual void printData(ostream &out) const = 0;
};
#endif
