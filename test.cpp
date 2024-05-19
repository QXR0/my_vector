#include"Vector.h"
#include<vector>
void test1_my_vector()
{
	my_vector::Vector<int> v(1);
	v.push_back(2);

	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	//v.push_back(3);
	v.Print();
	int i = 0;
	for (i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}
	v.Print();
}

void test2_my_vector()
{
	my_vector::Vector<int> v(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	
	v.Print();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.Print();
}



void test3_my_vector()
{
	my_vector::Vector<int> v(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);

	v.Print();
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 1);
	v.Print();
}

void test4_my_vector()
{
	my_vector::Vector<int> v(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Print();
	my_vector::Vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	v.Print();
}

void test5_my_vector()
{
	//my_vector::Vector<int> v1(11, 10);
	my_vector::Vector<int> v1(10,10);
	

	my_vector::Vector<int> v2(v1.begin(), v1.end());
	v2.Print();
}
int main()
{
	//test1_my_vector();
	//test3_my_vector();
	//int x = int{};
	/*int* arr = new int[1] {1};
	arr[0] = 1;
	int* arr1 = new int [10] {0};
	swap(arr, arr1);
	cout << *(arr++);*/
	//test4_my_vector();
	test5_my_vector();	
	return 0;
}