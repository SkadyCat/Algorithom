#pragma once

#include <ostream>
#include <vector>
#include "debug.h"
using namespace std;

void findCombine(int begin, int end,vector<int>& paths,int layer) {
	if (paths.size() == end) {
		log("组合问题: ", paths, { "layer" }, { layer });
		return;
	}
	for (int i = begin; i <= end; i++) {
		paths.push_back(i);
		findCombine(i, end, paths, layer+1);
		paths.erase(paths.begin() + paths.size() - 1);
	}
}