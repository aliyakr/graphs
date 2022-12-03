#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill_matrix(int size); //функция заполнения матрицы смежности
int number_of_cycles(vector<vector<int>>gr, int size); //функция, которая находит количество простых циклов в графе
void find_path(vector<int>path, int size); //функция поиска циклов и построения дерева
void delete_copies(); //функция удаления повторений
bool check_paths(vector<int> path);//функция проверки корректности цикла


vector<vector<int>>true_tree;
vector<vector<int>>gr;
vector<vector<int>>tree;


void fill_matrix(int size) {
	cout << "\nInput adjacency matrix: " << endl;
	gr.resize(size);
	for (int i = 0; i < size; ++i) {
		gr[i].resize(size);
		for (int j = 0; j < size; ++j) {
			cin >> gr[i][j];
		}
	}
}


int number_of_cycles(vector<vector<int>> gr, int size) {
	for (int i = 0; i < size; i++) {
		vector<int> path;
		path.push_back(i);
		find_path(path, size);
	}
	delete_copies();

	return true_tree.size();
	
}

void find_path(vector<int> path, int size) {
	vector<int> copy_path = path;
	for (int i = 0; i < size; i++) {
		path = copy_path;
		for (int j = 0; j < path.size(); j++) {

			//cout << "i = " << i << " j = " << j << endl;
			
			if ((path[j] == i) & (i != path[0])) {
				break;
			}
			if (j == path.size() - 1) {
				if (gr[path[path.size() - 1]][i] == 0) {
					break;
				}
				path.push_back(i);
				if (i == path[0]) {
					tree.push_back(path);

					//for (int k = 0; k < path.size(); k++)
					//{
						//cout << path[k] << ' ';
					//}
					//cout << endl;
					break;
					
				}
				else {
					find_path(path, size);
				}
			}
		}
	}
}

void delete_copies() {
	if (tree.size() > 0) {
		for (int i = 1; i < tree.size(); i++) {
			if (check_paths(tree[i])) {
				true_tree.push_back(tree[i]);
			}
		}
	}
}

bool check_paths(vector<int> path) {
	for (int i = 0; i < true_tree.size(); i++) {
		//cout << "\ntrue_tree[i].size()= " << true_tree[i].size() << endl;
		if (path.size() == true_tree[i].size()) { //т.о. находим повторяющиеся циклы
			int count = 0;
			for (int j = 0; j < path.size(); j++)
				for (int k = 0; k < path.size(); k++)
					if (path[j] == true_tree[i][k]) {
						count++;
						break;
					}

			if (count == path.size()) { 
				return false;
			}
		}
	}
	if (path.size() < 4) { //например, 0->1->0
		return false;
	}
	return true;
}

	
	


int main()
{
	int size;
	cout << "Input number of heights: ";
	cin >> size;
	fill_matrix(size);
	cout << "Number of cycles: " << number_of_cycles(gr, size);
	
	
	return 0;
}