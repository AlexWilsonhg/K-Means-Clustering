#pragma once
#include "Point.h"
#include <vector>

struct Centroid
{
	Centroid(Vec2::Point _p) : point(_p) {}

	Vec2::Point point;
	std::vector<Vec2::Point> datapoints;
};

