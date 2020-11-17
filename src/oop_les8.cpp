#include <iostream>
#include<limits>
#include<string>


using namespace std;

// Task1
namespace les8
{
	template <typename T>
	T div(T a, T b)
	{
		if (!b) throw -1;
		return a/b;
	}
}

// Task2
class Ex
{
private:
	double x;
public:
	Ex(double num):x(num){}
	double getX() const {return x;}
};

class Bar
{
private:
	double y;
public:
	Bar(): y(0){}
	void set(double a)
	{
		if (y+a > 100) throw Ex(a*y);
		else y = a;
	}
};

// Task3
enum GridLim
{
	UP_LIM    = 1,
	DOWN_LIM  = 2,
	LEFT_LIM  = 3,
	RIGHT_LIM = 4,
};
class OffTheField
{
private:
	int cur_x,cur_y;
	GridLim dir;
public:
	OffTheField(int a,int b, GridLim c):cur_x(a),cur_y(b),dir(c){};
	void errMessage()
	{
		switch(dir)
		{
		case UP_LIM: 
			cout << "Error!!! The robot is in (" << cur_x << "," << cur_y << "), and you want to move it above the grid!" << endl;
			break;
		case DOWN_LIM: 
			cout << "Error!!! The robot is in  (" << cur_x << "," << cur_y << "), and you want to move it below the grid!" << endl;
			break;
		case LEFT_LIM: 
			cout << "Error!!! The robot is in  (" << cur_x << "," << cur_y << "), and you want to move it to left side out the grid!" << endl;
			break;
		case RIGHT_LIM: 
			cout << "Error!!! The robot is in  (" << cur_x << "," << cur_y << "), and you want to move it to right side out the grid!" << endl;
			break;
		default:
			cout << "Unknown error!" << endl;
			break;
		}
		cout << endl;
	}
};
class Robot
{
private:
	int x,y;
public:
	Robot(int a = 1, int b = 1): x(a),y(b){}
	void move(char command)
	{
		switch(command)
		{
		case 'u':
		case 'U':
			if (y+1 > 10) throw OffTheField(x,y,UP_LIM);
			else 
			{
				y++;
				cout << endl <<  "^^^^^^^^^^^^^^^^^^^^^^^^^ Robot is going UP ^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;
			}
			break;
		case 'd':
		case 'D':
			if (y-1 < 1) throw OffTheField(x,y,DOWN_LIM);
			else
			{
				y--;
				cout << endl << "VVVVVVVVVVVVVVVVVVVVVVVV Robot is going DOWN VVVVVVVVVVVVVVVVVVVVVVVV" << endl << endl;
			}
			break;
		case 'l':
		case 'L':
			if (x-1 < 1) throw OffTheField(x,y,LEFT_LIM);
			else 
			{
				x--;
				cout << endl << "<<<<<<<<<<<<<<<<<<<<< Robot is going TO THE LEFT <<<<<<<<<<<<<<<<<<<<" << endl << endl;
			}
			break;
		case 'r':
		case 'R':
			if (x+1 > 10) throw OffTheField(x,y,RIGHT_LIM);
			else
			{
				x++;
				cout << endl << ">>>>>>>>>>>>>>>>>>>> Robot is going TO THE RIGHT >>>>>>>>>>>>>>>>>>>>" << endl << endl;
			}
			break;
		case 'e':
		case 'E':
			break;
		default:
			throw command;
			break;
		}
	}
	friend ostream& operator<< (ostream& out, const Robot& r);
};
ostream& operator<< (ostream& out, const Robot& r)
{
	out << "Current robot position is (" << r.x << "," << r.y << ")" << endl;
	return out;
}
int main(int argc, char** argv){

// Task1
	cout << endl << "******************* Task 1 **********************" << endl << endl;
	int r,a,b;
		
	cout << "Enter first number: ";
	cin >> a;
	cout << endl << "Enter second number: ";
	cin >> b;
	try
	{
		r = les8::div(a,b);
		cout << endl << "Result: " << r << endl << endl; 
	}
	catch(int x)
	{
		if (x==-1) cerr << endl << "Division by zero!" << endl;
	}
	
// Task2
	cout << endl << "******************* Task 2 **********************" << endl << endl;
	Bar br;
	try
	{
		int n;
		do{
			cout << "Enter integer number: ";
			cin >> n;
			br.set(n);
			cout << endl;
		} while(n);
	}
	catch(Ex ex)
	{
		cout << endl << "Exception was caught! And Ex.x = " << ex.getX() << endl << endl;
	}
	
// Task3
	cout << endl << "******************* Task 3 **********************" << endl << endl;
	Robot r1;
	char com;
	string s;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
	do
	{
		cout << r1;
		cout << "Please enter direction to move: u(U) - move Up, d(D) - move Down, l(L) - move Left, r(R) - move Right, e(E) - for exit." << endl;
		getline(cin,s);
		try
		{
		    if (s.size() > 1) throw s;
			com = s[0];
			r1.move(com);
		}
		catch (OffTheField& err){
			err.errMessage();
		}
		catch (string& str){
			cout << "Error!!! You entered illegal command:\"" << str << "\"" << endl << endl;
		}
		catch (char illegal){
			cout << "Error!!! You entered illegal command:\"" << illegal << "\"" << endl << endl;
		}
	}while((com!='e')&&(com!='E'));
	
	return 0;
}
