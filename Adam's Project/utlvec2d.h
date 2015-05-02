// 2D vector class definition

#ifndef utlVec2D_h
#define utlVec2D_h

//#include "femDefine.h"

class utlVec2D{
  protected:
	// data
	double m_x, m_y;
	// never used constructors
	utlVec2D();
	utlVec2D(utlVec2D&);
  public:
	// constructors
	utlVec2D(double x, double y);
	// destructor
    virtual ~utlVec2D();
	//functions
	void SetX(double x);
	void SetY(double y);
	double GetX() const;
	double GetY() const;
};

#endif
