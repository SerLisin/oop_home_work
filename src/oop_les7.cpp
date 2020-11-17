#include <iostream>
#include <memory>


using namespace std;

// Task1
class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int d = 0, int m = 0, int y = 0):m_day(d),m_month(m),m_year(y){}
	int getDay() const {return m_day;}
	int getMonth() const {return m_month;}
	int getYear() const {return m_year;}
	void setDay(int day){m_day = day;}
	void setMonth(int month){m_month = month;}
	void setYear(int year){m_year = year;}
	friend ostream& operator<< (ostream& out, const Date& d);
	~Date(){};
};
ostream& operator<< (ostream& out, const Date& d)
{
	out << "Date: " << d.m_day << "." << d.m_month << "." << d.m_year << endl;
	return out;
}

// Task2
unique_ptr<Date>& dateCmp(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
	if (d1->getYear() > d2->getYear()) return d1;
	else if (d1->getYear() < d2->getYear()) return d2;
		else if (d1->getMonth() > d2->getMonth()) return d1;
			else if (d1->getMonth() < d2->getMonth()) return d2;
				else if (d1->getDay() > d2->getDay()) return d1;
					else if (d1->getDay() < d2->getDay()) return d2;
						else return d1;
}

void dateSwap(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
	d1.swap(d2);
}
int main(int argc, char** argv){

// Task1
	cout << endl << "******************* Task 1 **********************" << endl << endl;
	Date d1;
	unique_ptr<Date> today(new Date);
	//auto today = make_unique<Date>(13,11,2020);
	today->setDay(13);
	today->setMonth(11);
	today->setYear(2020);
	cout << *today;
	unique_ptr<Date> date(move(today));	
	if (today) cout << "today is not null" << endl;
	else cout << "today is null" << endl;
	if (date) cout << "date is not null" << endl;
	else cout << "date is null" << endl;
	
// Task2
	cout << endl << "******************* Task 2 **********************" << endl << endl;
    auto date1 = make_unique<Date>(13,11,2020);
	auto date2 = make_unique<Date>(14,9,2019);
	unique_ptr<Date>& last = dateCmp(date1,date2);
	cout << "Later date -> " << *last << endl;
	
	dateSwap(date1,date2);
	cout << "Dates after swapping: " << endl;
	cout << "Date1 -> " << *date1;
	cout << "Date2 -> " << *date2 << endl;
	
	return 0;
}
