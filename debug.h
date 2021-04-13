#pragma once


#include <iostream>

using namespace std;
#include <vector>
#include<stdarg.h>

#include<stdio.h>
#include<string.h>
void log(string head, vector<int > vec, initializer_list<string> detail,initializer_list<int> args) {
	

	cout << head<<": ";

	for (int i = 0; i < vec.size(); i++) {
		
		cout << vec[i]<<" ";
	}
	int argno = 0;
	int para;
	cout << "#";
	vector<int> v1;
	for (auto k: args)
	{
		v1.push_back(k);
	}

	vector<string> v2;
	for (auto k : detail)
	{
		v2.push_back(k);
	}
	for (int i = 0; i < args.size();i++) {
		
		cout << v2[i]<<"="<<v1[i] << " ";
	}

	cout << endl;

}