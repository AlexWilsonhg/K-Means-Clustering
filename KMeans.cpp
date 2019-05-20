#include "stdafx.h"
#include "KMeans.h"
#include <random>

KMeans::KMeans(std::vector<Vec2::Point> _dataset, int numCentroids)
{
	for (int i = 0; i < numCentroids && i < _dataset.size(); i++)
	{
		Centroid a{_dataset[rand() % _dataset.size()]};
		centroids.push_back(a);
	}
	dataset = _dataset;
}

void KMeans::Update()
{
	ResetCentroidAssignments();
	AssignDataToCentroids();
	PruneUnusedCentroids();
	UpdateCentroidLocations();
}

void KMeans::AssignDataToCentroids()
{
	for (auto & p : dataset)
	{
		float minDistance = 99999999.0f;
		Centroid * closestCentroid = nullptr;
		for(auto & c : centroids)
		{
			float dist = Vec2::SquaredDistance(p, c.point);
			if (dist < minDistance)
			{
				minDistance = dist;
				closestCentroid = &c;
			}
		}
		closestCentroid->datapoints.push_back(p);
	}	
}

void KMeans::ResetCentroidAssignments()
{
	for (auto & c : centroids)
	{
		c.datapoints.clear();
	}
}

void KMeans::UpdateCentroidLocations()
{
	for (auto & c : centroids)
	{
		float x = 0.0f;
		float y = 0.0f;
		for (const auto p : c.datapoints)
		{
			x += p.x;
			y += p.y;
		}
		x /= c.datapoints.size();
		y /= c.datapoints.size();
		c.point.x = x;
		c.point.y = y;
	}
}

void KMeans::PruneUnusedCentroids()
{
	// Delete centroids with 0 datapoints.
}
