#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <iostream>
#include <vector>
#include <cassert>
#include <vector>

using namespace std;

class ArrayInt{
private:
	int m_length;
	int *m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr){}
	ArrayInt(int length) : m_length(length){
		assert(length >= 0);
		if(length > 0)
			m_data = new int[length]();// "()" - Task1
		else
			m_data = nullptr;
	}
	~ArrayInt(){delete [] m_data;}
	void erase(){
		delete [] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	int getLength() const{
		return m_length;
	}
	int& operator[](int index){
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	void resize(int newLength){
		if(newLength == m_length) return;
		if(newLength <= 0){
			erase();
			return;
		}
		int *data = new int[newLength](); // "()" - Task1
		if(m_length > 0){
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			for(int i = 0;i<elementsToCopy;++i){
				data[i] = m_data[i];
			}
		}
		delete [] m_data;
		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value,int index){
		assert(index >= 0 && index <=m_length);
		int *data = new int[m_length+1];
		for(int before=0;before < index; ++before)
			data[before] = m_data[before];
		data[index] = value;
		for(int after=index; after < m_length; ++after)
			data[after+1] = m_data[after];
		delete [] m_data;
		m_data = data;
		++m_length;
	}
	void push_back(int value){insertBefore(value,m_length);}
	
	// Task1
	void print(){
		if(!m_length) 
			cout << "Array is empty" << endl;
		else
			for(int i = 0; i < m_length; ++i)
				cout << "[" << i << "] : " << m_data[i] << endl;
	}
	void pop_back(){--m_length;} // удаление последнего элемента массива
	void pop_front(){ // удаление первого элемента массива
		if(!m_length)
			cout << "Array is empty!" << endl;
		else {
			for(int i = 0; i < m_length-1; ++i) 
				m_data[i] = m_data[i+1];
			--m_length;
		}
	}
	void sort(int begin,int end, bool direction){ // сортировка перестановками
		if(begin >= end){
			cout << "Invalid parameters for sorting!" << endl;
			return;
		}
		if(end >= m_length) end = m_length-1;
		if(!direction){
			for(int i = begin+1; i <= end; ++i)
				for(int j = begin; j < i; ++j)
					if(m_data[i] < m_data[j]){
                        int tmp = m_data[i];
						m_data[i] = m_data[j];
						m_data[j] = tmp;
					}
		}
		else{
			for(int i = begin+1; i <= end; ++i)
				for(int j = begin; j < i; ++j)
					if(m_data[i] > m_data[j]){
                        int tmp = m_data[i];
						m_data[i] = m_data[j];
						m_data[j] = tmp;
					}
		}
	}
};

#endif
int main(int argc, char** args){

	ArrayInt array;
	
//	array.resize(10);

	
	array.push_back(-5);
    array.push_back(-6);
	array.push_back(-7);
	array.insertBefore(1,0);
	array.insertBefore(2,1);

	
	array.print();
	array.sort(0,array.getLength(),0);
    cout << "sort" << endl;
	array.print();
	
	array.sort(0,array.getLength(),1);
	cout << "sort" << endl;
	array.print();
	
// Task2
	vector<int> v {0,1,2,3,45,76,8,3,6,7,3233,43,5,56,45};
	vector<int> v1;
	v1 = v;
	vector<int>::const_iterator it,it1; 
	
    it = v1.begin(); 
	int amount=0;
    while (it != v1.end())  // подсчёт различных чисел в массиве
    {
	    ++amount;
		it1 = it + 1;
        while(it1 != v1.end()) {
			*it==*it1 ? v1.erase(it1) : ++it1;
		}
		v1.erase(it);	
    }
    cout << "Amount of different numbers = " << amount << ". Vector size = " << v.size() << endl;
	it = v.begin(); 
    while (it != v.end()) 
    {
        cout << *it << " "; 
        ++it; 
    }
    cout << '\n';



	return 0;
}
