#pragma once
#include "Centroid.h"

class KMeans
{
public:
	KMeans(std::vector<Vec2::Point> dataset, int numCentroids);

	void Update();

	std::vector<Centroid> GetCentroids()
	{
		return centroids;
	}

	std::vector<Vec2::Point> GetDataset()
	{
		return dataset;
	}

private:
	void AssignDataToCentroids();
	void ResetCentroidAssignments();
	void UpdateCentroidLocations();
	void PruneUnusedCentroids();

private:
	std::vector<Centroid> centroids;
	std::vector<Vec2::Point> dataset;
};

