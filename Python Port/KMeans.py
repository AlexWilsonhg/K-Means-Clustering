import random
import pygame
import time

random.seed(1000)

Colors = [
    [255,0,0],
    [0, 255, 0],
    [0, 0, 255],
    [125,125,0],
    [41, 128, 185],
    [20, 143, 119],
    [211, 84, 0]]

epsilon = 1e-32

class Cluster:
    
    def __init__(self, centroid):
        self.centroid = centroid
        self.assignedData = []

    def AddData(self, d):
        self.assignedData.append(d)
        
    def UpdateCentroid(self):
        sumX = 0
        sumY = 0
        for i in self.assignedData:
            sumX += i[0]
            sumY += i[1]
        avgX = sumX/ ( len(self.assignedData) + epsilon ) ## epsilon to avoid potential divide by 0
        avgY = sumY/ ( len(self.assignedData) + epsilon )
        self.centroid = [avgX, avgY]
        return

class KMeans:
    
    def __init__(self, dataset, numClusters):
        self.dataset = dataset
        self.clusters = []
        for i in range(numClusters):
            self.clusters.append(Cluster([random.randint(-100, 100), random.randint(-100,100)]))
        return

    def Update(self):
        self.ResetClusterAssignments()
        self.AssignDataToClusters()
        self.UpdateClusterCentroids()
        
    def Reset(self):
        for c in self.clusters:
            c.centroid = [random.randint(0, 1680), random.randint(0,1020)]
        self.ResetClusterAssignments()
        
    def AssignDataToClusters(self):
        for d in(self.dataset):
            distances = []
            for c in(self.clusters):
                distances.append(SquaredDistance(d, c.centroid))
            
            self.clusters[distances.index(min(distances))].AddData(d)

    def ResetClusterAssignments(self):
        for i in(self.clusters):
            i.assignedData.clear()

    def UpdateClusterCentroids(self):
        for i in(self.clusters):
            i.UpdateCentroid()
            
    def PruneUnusedClusters(self):
        return

    def GetClusters(self):
        return self.clusters


class KMeansDrawer:

    def __init__(self,display,KMeans):
        self.display = display
        self.KMeans = KMeans

    def Draw(self):
        clusters = self.KMeans.GetClusters()
        colorIndex = 0;
        for cluster in clusters:
            for data in cluster.assignedData:
                pygame.draw.circle(self.display, Colors[colorIndex], data, 1)
            pygame.draw.rect(self.display, Colors[colorIndex], [cluster.centroid[0],cluster.centroid[1] , 10, 10])
            colorIndex += 1
             
def SquaredDistance(a, b):
    dX = a[0] - b[0]
    dY = a[1] - b[1]
    return ((dX*dX) + (dY * dY))

data = [ ( random.randint(10, 1680), random.randint(10, 1020) ) for k in range(10000) ]
pygame.init
screen = pygame.display.set_mode((1680,1020))
k = KMeans(data, 5)
kDraw = KMeansDrawer(screen, k)

def Go():
    k.Reset()
    for i in range(10):
        DoStep()
        
def DoStep():
    screen.fill((25,25,25))
    k.Update()
    kDraw.Draw()
    pygame.display.update()

    



