#pragma once
namespace Vec2
{

	struct Point
	{
		float x;
		float y;
	};

	static float SquaredDistance(Point a, Point b)
	{
		float dX = a.x - b.x;
		float dY = a.y - b.y;
		return ((dX*dX) + (dY*dY));
	}

}