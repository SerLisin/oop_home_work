#include <iostream>
#include <string>
#include <sstream>



using namespace std;

// Task2
class dbEndl
{
public:
	friend ostream& operator<< (ostream &out,const dbEndl &endll);
};

ostream& operator<< (ostream &out,const dbEndl &endll)
{
	out.flush();
    out << endl << endl; // вставка символов новой строки и очистка буфера
    return out;
}

ostream& endlll(ostream& out)
{
     out.flush();
     out << endl << endl;
     return out;
}


int main(int argc, char** args){

// Task1
	cout << endl << "******************* Task 1 **********************" << endl << endl;
	string inStr;
	bool fl = true;
	do
	{
		fl = true;
		cout << "Enter integer number: ";
		cin >> inStr;
		for(int i = 0; i < inStr.length(); ++i)
		{
			if(!((!i && (isdigit(inStr[i]) || inStr[i] == '-')) || (i && isdigit(inStr[i]))))
			{
				cerr << "Invalid number. Please try again" << endl;
				fl = false;
				break;
			}
		}
	}while(!fl);
	stringstream myStr;
	myStr << inStr;
	int number;
	myStr >> number;
	cout << "The number is " << number << endl << endl;

// Task2
	cout << endl << "******************* Task 2 **********************" << endl << endl;	
	dbEndl endll;
	cout << "endll test start here" << endll;
	cout << "endll test stop here" << endll;
	
        cout << "endll test start here" << endlll;
        cout << "endll test stop here" << endlll;

	return 0;
}
