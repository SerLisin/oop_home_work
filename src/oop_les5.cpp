#include <iostream>



using namespace std;

// Task1
template <typename T>
class Pair1{
private:
	T m_first;
	T m_second;
public:
	Pair1(T num1, T num2): m_first(num1), m_second(num2){}
	T first() const {return m_first;}
	T second() const {return m_second;}
};

// Task2
template <typename T1, typename T2>
class Pair{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(T1 num1, T2 num2): m_first(num1),m_second(num2){}
	T1 first() const {return m_first;}
	T2 second() const {return m_second;}
};

// Task3
template <typename T>
class Pair <string, T>{
protected:
	string m_first;
	T m_second;
public:
	Pair(string par1, T par2): m_first(par1),m_second(par2){}
	string first() const {return m_first;}
	T second() const {return m_second;}
};

template <typename T>
class StringValuePair: public Pair<string, T>{
public:
	StringValuePair(string par1, T par2): Pair <string,T> :: Pair(par1,par2){}
};


int main(int argc, char** args){

// Task1
	cout << endl << "******************* Task 1 **********************" << endl << endl;
	Pair1<int> p1(6,9);
	cout << "Pair: " << p1.first() << " " << p1.second() << "\n";
	
	const Pair1<double> p2(3.4,7.8);
	cout << "Pair: " << p2.first() << " " << p2.second() << "\n";
 
// Task2
	cout << endl << "******************* Task 2 **********************" << endl << endl;
	Pair<int, double> p3(6,7.8);
	cout << "Pair: " << p3.first() << " " << p3.second() << "\n";
	
	const Pair<double,int> p4(3.4,5);
	cout << "Pair: " << p4.first() << " " << p4.second() << "\n";

// Task3
	cout << endl << "******************* Task 3 **********************" << endl << endl;
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << " " << svp.second() << "\n";
    cout << "\n";
	

	return 0;
}
