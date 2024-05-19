#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace my_vector
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef T value_type;

	private:
		iterator _start=nullptr;//ͷָ��
		iterator _finish=nullptr;//���һ��Ԫ�ص���һλ
		iterator _endofstorage=nullptr;//βָ�����һ��

	public:
		//������
		iterator begin()
		{
			return _start;
		}
		const_iterator begin()const
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator end()const
		{
			return _finish;
		}

		//����
		Vector()
		{}

		//����sizeΪn��vector��������ʼ����data
		Vector(int n, value_type data=value_type())
		{
			reserve(n);
			while (n--)
			{
				push_back(data);
			}
		}

		//�õ�������ʼ��  (��ģ��������ʵ��һ��ģ�庯��������ʲô���͵ĵ����������Ե�����)
		template<class Inputiterator >
		Vector(Inputiterator first, Inputiterator last)
		{
			
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//��������
		Vector(const Vector &v)
		{

			_start = new T[v.size()];
			int i = 0;
			for (i = 0; i < size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity;
		}



		//����
		~Vector()
		{
			if (_start != nullptr)
			{
				delete[]_start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		value_type*& operator=(const Vector& v)
		{
			delete[]_start;
			_start = new value_type [v.capacity];
			int i = 0;
			for (i = 0; i < v.capacity(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
			return *this;
		}

		//����
		void reserve(const int& capacity)
		{
			int s = size();
			value_type* ret = new value_type[capacity]{0};

			 //swap(ret, _start);
			int i = 0;
			for (i = 0; i < size();i++)
			{
				ret[i]=_start[i];
			}
			 delete[] _start;
			
			 _start = ret;
			 _endofstorage = _start + capacity;
			 _finish = _start + s;
			 
		}

		//����Ԫ������
		size_t size()
		{
			return _finish - _start ;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		//��������
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		//����
		void swap(const Vector&v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);

		}

		//[]����
		value_type& operator[](const int index)
		{
			assert(index < size());
			return	_start[index];
		}


		//β��
		void push_back(const value_type &data)
		{
			if(size()>=capacity())
			{
				int capacity_ = capacity() == 0 ? 4 : 2 * capacity();
				reserve(capacity_);
			}
			*_finish = data;
			_finish++;
		}

		//βɾ
		void pop_back()
		{
			assert(size()>0);
			_finish--;
		}


		//�ض�λ�ò���
		void insert(iterator pos, value_type data)
		{
			int len = pos - _start;
			if (size() == capacity())
			{
				reserve(2 * capacity());
				pos = _start + len;
			}
			int end = size()-1;
			while (end >= len)
			{
				_start[end + 1] = _start[end];
				end--;
			}
			*pos = data;
			_finish++;
		}

		//�ض�λ��ɾ��
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;
			return pos;
		}
		



		void Print()
		{
			/*int i = 0;
			for (i = 0; i < size(); i++)
			{
				cout << _start[i]<<" ";
			}*/
			;
			iterator it = begin();
			while (it != _finish)
			{
				cout << *it << "  ";
				it++;
			}
			cout << endl;
		}

	};


}


