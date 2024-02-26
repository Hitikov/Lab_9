#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool finding_similars(string row) {
	bool matching = false;
	string* words = new string[100];
	int cur;
	int i = 0;
	int j = 0;
	int n = 0;
	while (i <= size(row)) {
		if ((row[i] == 32) || (row[i] == '\0')) {
			words[n].insert(0, row, j, i - j);
			j = i + 1;
			cur = 1;
			for (int nn = 0; nn < n; ++nn) {
				if (words[n] == words[nn]) {
					++cur;
				}
			}
			++n;
			if (cur >= 2) {
				matching = true;
			}
		}
		++i;
	}
	delete[] words;
	return matching;
}

void finding_A(string row, int* id, int* max, int* n) {
	int i = 0;
	int j = 0;
	int cur;

	while (i <= size(row)) {
		if ((row[i] == 32) || (row[i] == '\0')) {
			cur = 0;
			for (int n = j; n < i; ++n) {
				if (row[n] == 'a') {
					++cur;
				}
			}
			if (cur > *max) {
				*id = *n;
				*max = cur;
			}
			++(*n);
			j = i + 1;
		}
		++i;
	 } 
}

int main() {
	string row;
	int cur_id = -1;
	int cur_max = -1;
	int hm_all = 0;

	ifstream input("F1.txt");
	ofstream output("F2.txt");


	while (!input.eof()) {
		getline(input, row);
		if (finding_similars(row)) output << row << '\n';
		finding_A(row, &cur_id, &cur_max, &hm_all);
	}

	cout << "Index of word with most 'a': " << cur_id + 1 << endl;
	//cout << cur_max << endl;
	
	input.close();
	output.close();
	return 0;
}