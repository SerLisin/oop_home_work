#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;


// Task1
class Figure{
public: 
		Figure(){}
		virtual double area() = 0;
};

class Parallelogram: public Figure{
protected:
		double side_a,side_b; // стороны параллелограмма
		double alpha; // величина угла между сторонами в градусах
public:
		Parallelogram(double n1,double n2,double a):side_a(n1),side_b(n2),alpha(a){}
		virtual double area(){
			cout << "S par = " << side_a*side_b*sin(alpha*M_PI/180) << endl;
			return side_a*side_b*sin(alpha*M_PI/180);
		}
};

class Circle: public Figure{
private:
		double radius;
public:
		Circle(double r):radius(r){}
		double area(){
			cout << "S cir = " << M_PI*pow(radius,2) << endl;
			return M_PI*pow(radius,2);
		}
};

class Rectangle: public Parallelogram{
public:
		Rectangle(double a, double b): Parallelogram(a,b,90){}
		double area(){
		    cout << "S rec = " << side_a*side_b << endl;
			return side_a*side_b;
		}
};

class Square: public Parallelogram{
public:
		Square(double a): Parallelogram(a,a,90){}
		double area(){
		    cout << "S sq = " << side_a*side_b << endl;
			return side_a*side_b;
		}
};

class Rhombus: public Parallelogram{
public:
		Rhombus(double a,double alpha): Parallelogram(a,a,alpha){}
		double area(){
		    cout << "S rhom = " <<  side_a*side_b*sin(alpha*M_PI/180) << endl;
			return side_a*side_b*sin(alpha*M_PI/180);
		}
};

// Task2
class Car{
protected:
		string company;
		string model;
public:
		Car(){cout << "class Car" << endl;}
};

class PassengerCar: /*virtual*/ public Car{
public:
		PassengerCar(){cout << "class PassengerCar" << endl;}
};

class Bus: /*virtual*/ public Car{
public:
		Bus(){cout << "class Bus" << endl;}
};

class Minivan: public PassengerCar, public Bus{
public: 
		Minivan(){cout << "class Minivan" << endl;}
};

// Task3
int divider(int a,int b){ // вычисление общего делителя числителя и знаменателя
		int tmp=2;
		int div=1;
		while((tmp<=a)&&(tmp<=b)){
			if((!(a%tmp))&&(!(b%tmp)))div=tmp;
			++tmp;
		}
		return div;
}

class Fraction{
private:
		int numerator;   // числитель
		int denominator; // знаменатель
public:
		Fraction(int n,int d): numerator(n), denominator(d){
			int tmp = d;
			while(!tmp){
				cout << "Denominator cannot be equal zero - enter another: ";
				cin >> tmp;
			};
			denominator=tmp;
			int div=divider(numerator,denominator);
			numerator/=div;
			denominator/=div;
		}
		void setFraction(int n,int d){
		    numerator = n;
			int tmp = d;
			while(!tmp){
				cout << "Denominator cannot be equal zero - enter another: ";
				cin >> tmp;
			};
			denominator=tmp;
		}
		double getFraction() const {return numerator/denominator;}
		int getNum() const {return numerator;}
		int getDenum() const {return denominator;}
        void printFraction() const {cout << numerator << "/" << denominator;}
		
		friend Fraction operator+ (const Fraction &fr1,const Fraction &fr2); // сложение
		friend Fraction operator- (const Fraction &fr1,const Fraction &fr2); // вычитание
		friend Fraction operator* (const Fraction &fr1,const Fraction &fr2); // умножение
		
		Fraction operator-(){return Fraction(-numerator,denominator);} // унарный оператор "-"
		
		friend bool operator==(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения "=="
		friend bool operator!=(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения "!="
		friend bool operator<(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения "<"
		friend bool operator>=(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения ">="
        friend bool operator>(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения ">"
        friend bool operator<=(const Fraction &fr1,const Fraction &fr2); // логический оператор сравнения "<="
};
Fraction operator+ (const Fraction &fr1,const Fraction &fr2){ // сложение (дружественная функция)
		int n,d;
		n = fr1.numerator*fr2.denominator+fr2.numerator*fr1.denominator;
		d = fr1.denominator*fr2.denominator;
		int tmp=2;
		int div=divider(n,d);
		n/=div;
		d/=div;
		return Fraction(n,d);
}

Fraction operator- (const Fraction &fr1,const Fraction &fr2){ // вычитание (дружественная функция)
		int n,d;
		n = fr1.numerator*fr2.denominator-fr2.numerator*fr1.denominator;
		d = fr1.denominator*fr2.denominator;
		int div = divider(n,d);
		n/=div;
		d/=div;
		return Fraction(n,d);
}

Fraction operator* (const Fraction &fr1,const Fraction &fr2){ // умножение (дружественная функция)
		int n,d;
		n = fr1.numerator*fr2.numerator;
		d = fr1.denominator*fr2.denominator;
		int div = divider(n,d);
		n/=div;
		d/=div;
		return Fraction(n,d);
}

Fraction operator/ (const Fraction &fr1,const Fraction &fr2){ // деление (простая функция)
		int n,d;
		n = fr1.getNum()*fr2.getDenum();
		d = fr1.getDenum()*fr2.getNum();
		int div = divider(n,d);
		n/=div;
		d/=div;
		return Fraction(n,d);
}

bool operator==(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения "==" (дружественная функция)
		if((fr1.numerator==fr2.numerator)&&(fr1.denominator==fr2.denominator)) return true;
		else return false;
}

bool operator!=(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения "!=" (дружественная функция)
        if((fr1.numerator!=fr2.numerator)||(fr1.denominator!=fr2.denominator)) return true;
		else return false;
}

bool operator<(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения "<" (дружественная функция)

        if(fr1.numerator*fr2.denominator<fr2.numerator*fr1.denominator) return true;
		else return false;
}

bool operator>=(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения ">=" (дружественная функция)
		if(!(fr1<fr2)) return true;
		else return false;
}

bool operator>(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения ">" (дружественная функция)

        if(fr1.numerator*fr2.denominator>fr2.numerator*fr1.denominator) return true;
        else return false;
}

bool operator<=(const Fraction &fr1,const Fraction &fr2){ // оператор сравнения "<=" (дружественная функция)
        if(!(fr1>fr2)) return true;
        else return false;
}


int main(int argc,char** args){
// Task1
	cout << "Task 1" << endl;
    Square sq1(5);
	Parallelogram *par1 = &sq1;
	par1->area();
	
	Figure *pCircle = new Circle(3);
	pCircle->area();
	
	Rectangle rect1(4,6);
	Parallelogram &lrect = rect1;
	lrect.area();
	
	Rhombus rhom1(7,45);
	Figure *prhom = &rhom1;
	prhom->area();
		
	Parallelogram par2(3,6,60);
	Figure *ppar=&par2;
	ppar->area();
	cout << endl;
	
// Task2
   cout << "Task 2" << endl;
   Car car;
   PassengerCar pcar;
   Bus bus;
   Minivan mvan;
   cout << endl;
   
// Task3
	cout << "Task 3" << endl;
	Fraction frac1(1,2);
	Fraction frac2(3,6);
	
	Fraction frac_res = frac1+frac2;
	frac_res.printFraction();
    cout << endl;
	
	frac_res = frac1-frac2;
	frac_res.printFraction();
    cout << endl;
	
	frac_res = frac1*frac2;
	frac_res.printFraction();
    cout << endl;

    frac_res = frac1/frac2;
	frac_res.printFraction();
    cout << endl;

	frac_res = -frac1;
	frac_res.printFraction();
    cout << endl;
	
    frac1.setFraction(3,10);
    frac2.setFraction(334,23);
    if(frac1==frac2){frac1.printFraction(); cout << " equal "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " not equal "; frac2.printFraction(); cout << endl;}
	

    frac1.setFraction(24,45);
    frac2.setFraction(34,23);
    if(frac1!=frac2){frac1.printFraction(); cout << " not equal "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " equal "; frac2.printFraction(); cout << endl;}
	
    frac1.setFraction(4,5);
    frac2.setFraction(3,2);
    if(frac1<frac2){frac1.printFraction();cout << " less "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " not less "; frac2.printFraction(); cout << endl;}
	
    frac1.setFraction(3235,4532);
    frac2.setFraction(3234,2323);
    if(frac1>=frac2){frac1.printFraction(); cout << " larger or equal "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " less "; frac2.printFraction(); cout << endl;}

    frac1.setFraction(89,25);
    frac2.setFraction(90,23);
    if(frac1>frac2){frac1.printFraction(); cout << " larger "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " not larger "; frac2.printFraction(); cout << endl;}

    frac1.setFraction(67,43);
    frac2.setFraction(34,23);
    if(frac1<=frac2){frac1.printFraction(); cout << " less or equal "; frac2.printFraction(); cout << endl;}
    else {frac1.printFraction(); cout << " larger "; frac2.printFraction(); cout << endl;}

    return 0;
}
