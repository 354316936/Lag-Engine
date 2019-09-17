#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <tchar.h>
const DWORDLONG storageNeed = 300;
const DWORDLONG pRAMNeed = 1;
const DWORDLONG vRAMNeed = 1;

using namespace std;

bool CheckStorage(const DWORDLONG diskSpaceNeeded);


int main()
{
	bool storageCheck;
	storageCheck = CheckStorage(storageNeed);
	if (storageCheck == true)
	{
		cout << "You hava enough storage!" << endl;
	}

	return 0;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 neededClusters;
	neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "CheckStorage Failure: Not enough physical storage." << endl;
		return false;

	}
	return true;
}

