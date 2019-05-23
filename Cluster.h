#pragma once
#include "Point.h"
#include <vector>

struct Cluster
{
	Cluster(Vec2::Point _p) : centroid(_p) {}

	Vec2::Point centroid;
	std::vector<Vec2::Point> datapoints;
};

