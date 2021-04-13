#pragma once

#include <vector>
using namespace std;

void arank(vector<int>& vecs) {
	for (int i = 0; i < vecs.size(); i++) {
		for (int j = 0; j < vecs.size()-1; j++) {
			
			if (vecs[j] < vecs[j+1]) {
				int temp = vecs[j];
				vecs[j] = vecs[j+1];
				vecs[j+1] = temp;
			}
		}
	}
}


