#pragma once
#include "Centroid.h"

class KMeans
{
public:
	KMeans(std::vector<Vec2::Point> dataset, int numCentroids);

	void Update();

	std::vector<Cluster> GetClusters()
	{
		return clusters;
	}

	std::vector<Vec2::Point> GetDataset()
	{
		return dataset;
	}

private:
	void AssignDataToClusters();
	void ResetClusterAssignments();
	void UpdateClusterCentroids();
	void PruneUnusedClusters();

private:
	std::vector<Cluster> clusters;
	std::vector<Vec2::Point> dataset;
};

