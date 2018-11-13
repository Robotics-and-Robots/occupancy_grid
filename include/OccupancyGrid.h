#ifndef OCCUPATION_GRID_H
#define OCCUPATION_GRID_H

#include <cmath>
#include "geometry_msgs/Pose2D.h"

#include "Vector2D.hpp"
#include "Constants.h"

using namespace geometry_msgs;

//Cell elements are float-typed values
typedef double OGCellType;

//Defines a class to hold values for an
//occupation grid. 
class OccupancyGrid{

private:
	OGCellType _m_pospos[OG_SEC_W][OG_SEC_H]; //X is positive, Y is positive.
	OGCellType _m_posneg[OG_SEC_W][OG_SEC_H]; //X is positive, Y is negative.
	OGCellType _m_negpos[OG_SEC_W][OG_SEC_H]; //X is negative, Y is positive.
	OGCellType _m_negneg[OG_SEC_W][OG_SEC_H]; //X is negative, Y is negetive.

public:

	//ctor. and dtor.
	OccupancyGrid();
	~OccupancyGrid();
	
	//overload [] to access as an array
	OGCellType Get(int x, int y);
	
	//set some value to a cell
	OGCellType Set(int x, int y, OGCellType value);
	OGCellType SetLoc(Pose2D pose, OGCellType dist, OGCellType theta);

	void Reset();

	std::string ToString();
	void ToFile(std::string filename);
	std::string ToMap();
	void LoadMap(std::string);
	void UpdatePotentialFields();
	void ToStringPF();
};

#endif /* OCCUPATION_GRID_H */
