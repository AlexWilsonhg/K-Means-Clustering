#include "stdafx.h"
#include "KMeans.h"
#include <random>

KMeans::KMeans(std::vector<Vec2::Point> _dataset, int numCentroids)
{
	for (int i = 0; i < numCentroids && i < _dataset.size(); i++)
	{
		Cluster a{_dataset[rand() % _dataset.size()]};
		clusters.push_back(a);
	}
	dataset = _dataset;
}

void KMeans::Update()
{
	ResetClusterAssignments();
	AssignDataToClusters();
	PruneUnusedClusters();
	UpdateClusterCentroids();
}

void KMeans::AssignDataToClusters()
{
	for (auto & p : dataset)
	{
		float minDistance = 99999999.0f;
		Cluster * closestCluster = nullptr;
		for(auto & c : clusters)
		{
			float dist = Vec2::SquaredDistance(p, c.centroid);
			if (dist < minDistance)
			{
				minDistance = dist;
				closestCluster = &c;
			}
		}
		closestCluster->datapoints.push_back(p); // TODO: This is a bottleneck, maybe try turning this into an array, 
												  //       and just change numerical values instead of creating/deleting.										 
	}	
}

void KMeans::ResetClusterAssignments()
{
	for (auto & c : clusters)
	{
		c.datapoints.clear();
	}
}

void KMeans::UpdateClusterCentroids()
{
	for (auto & c : clusters)
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
		c.centroid.x = x;
		c.centroid.y = y;
	}
}

void KMeans::PruneUnusedClusters()
{
	// Delete centroids with 0 datapoints.
}
