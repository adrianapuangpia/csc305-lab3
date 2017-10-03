#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Job
{
public:
	string jobName = "";
	int jobSize = 0;
	string location = "";
	int locationSize = 0;
	bool isRunning = false;
};
