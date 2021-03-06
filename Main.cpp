// KMeans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KMeans.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

class Clock
{
public:
	Clock()
	{
		start = clock();

	}

	~Clock()
	{
		end = clock();
		std::cout << end - start / (double)CLOCKS_PER_SEC << " ms" << std::endl;
	}

private:
	std::clock_t start;
	std::clock_t end;

};
int main()
{
	std::vector<Vec2::Point> data;
	for (int i = 0; i < 1000000; ++i)
	{
		float a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		data.push_back({ a, b });
	}
	KMeans k(data, 3);
	
	{
		Clock c;
		for (int i = 0; i < 10; ++i)
		{
			k.Update();
		}
	}
}
