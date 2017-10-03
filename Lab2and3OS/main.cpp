#include <iostream>
#include "Job.h"
#include "Partition.h"
using namespace std;

int main()
{
	int numOfPartitions;
	int numOfJobs;
	int memWasted = 0;
	int memSize;
	int userMemSize = 0;
	void bestfit(int jobnum, int partnum, Job *jobList, Partition *partitionList);


	cout << "Please enter total memory size. " << endl;
	cin >> memSize;

	cout << "Please input num of partitions up to 5." << endl;
	cin >> numOfPartitions;
	//validate input
	while (numOfPartitions > 5 || numOfPartitions < 0)
	{
		cout << "Please enter a number between 0 and 5" << endl;
		cin >> numOfPartitions;
	}

	cout << "Please input num of jobs up to 5." << endl;
	cin >> numOfJobs;

	while (numOfJobs > 5 || numOfJobs < 0)
	{
		cout << "Please enter a number between 0 and 5" << endl;
		cin >> numOfJobs;
	}

	//make the array of partitions
	Partition* partitionList = NULL;
	partitionList = new Partition[numOfPartitions];
	for (int i = 0; i < numOfPartitions; i++)
	{
		int size;
		string name;
		cout << "Please enter partition name" << endl;
		cin >> name;
		partitionList[i].partitionName = name;
		cout << "Please enter partition size" << endl;
		cin >> size;

		userMemSize += size;
		while (userMemSize > memSize)
		{
			userMemSize -= size;
			cout << "There is not enough memory. Try again. " << endl;
			cin >> size;
			userMemSize += size;

		}
		partitionList[i].partitionSize = size;
	}

	if (userMemSize > memSize)
	{
		cout << "Error. Try entering the memory sizes again. " << endl;
	}
	//Make the array of jobs
	Job* jobList = NULL;
	jobList = new Job[numOfJobs];
	for (int i = 0; i<numOfJobs; i++)
	{
		int size;
		string name;
		cout << "Please enter job name" << endl;
		cin >> name;
		jobList[i].jobName = name;
		cout << "Please enter job size" << endl;
		cin >> size;
		jobList[i].jobSize = size;

	}
	/*
	//////////assign jobs to partitions
	for (int i = 0; i < numOfJobs; i++)
	{
		for (int j = 0; j < numOfPartitions; j++)
		{
		//check for memory
		if (jobList[i].jobSize <= partitionList[j].partitionSize && jobList[i].isRunning == false)
		{
		//partition is free
			if (partitionList[j].isOccupied == false)
			{
			//assign this job to a partition
			jobList[i].location = partitionList[j].partitionName;
			//change job status and partition status
			jobList[i].isRunning = true;
			partitionList[j].isOccupied = true;
			//add the leftover memory to mem wasted.
			memWasted += (partitionList[j].partitionSize - jobList[i].jobSize);
			cout << jobList[i].jobName << " with size of " << jobList[i].jobSize << " was allocated to " << partitionList[j].partitionName;
			cout << " with size of " << partitionList[j].partitionSize << endl;
			}
		//job doesn't fit in the current partition
	}

	}
	//job was not able to be assigned to anything
	if (jobList[i].isRunning == false)
	{
	cout << jobList[i].jobName << " is waiting." << endl;
	}
	}
	*/
	

	bestfit(numOfJobs, numOfPartitions, jobList, partitionList);

	//print out job status
	for (int n = 0; n < numOfJobs; n++)
	{
		cout << jobList[n].jobName << " with size of " << jobList[n].jobSize << " was allocated to " << jobList[n].location << " with size of " << jobList[n].locationSize << endl;
	}
	//add the unassigned partitions to wasted memory.
	for (int k = 0; k < numOfPartitions; k++)
	{
		if (partitionList[k].isOccupied == false)
		{
			memWasted += partitionList[k].partitionSize;
		}
	}
	cout << "Total memory wasted is: " << memWasted << endl;


	system("pause");
	return 0;
}

void bestfit(int jobnum, int partnum, Job *jobList, Partition *partitionList)
{
	Partition* potentialBest = NULL;
	potentialBest = new Partition[partnum];
	int index = 0;

	for (int i = 0; i < jobnum; i++)
	{
		for (int j = 0; j < partnum; j++)
		{
			if ((jobList[i].jobSize <= partitionList[j].partitionSize) && partitionList[j].isOccupied == false)
			{
				potentialBest[j].difference = partitionList[j].partitionSize - jobList[i].jobSize;
				potentialBest[j].partitionName = partitionList[j].partitionName;
				potentialBest[j].partitionSize = partitionList[j].partitionSize;
				for (int n = 0; n < partnum; n++)
				{
					int min = potentialBest[n].difference;
					if (potentialBest[n].difference <= min)
					{
						min = potentialBest[n].difference;
						index = n;
					}
				}
				jobList[i].location = potentialBest[index].partitionName;
				jobList[i].locationSize = potentialBest[index].partitionSize;
				partitionList[index].isOccupied = true;
			}
			
		}
			

	}



}



