#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Partition
{
public:
	string partitionName = "";
	int partitionSize = 0;
	bool isOccupied = false;
	int difference;
};
