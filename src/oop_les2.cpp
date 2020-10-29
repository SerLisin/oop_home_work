#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;


// Task1
class Person{
protected:
    string name;
    int age;
    string sex;
    int weight;
public:
    Person(string n,int a, string s,int w): name(n),age(a),sex(s),weight(w){

    }
    void setName(string new_name){
        name = new_name;
    }
    void setAge(int new_age){
        if(new_age>0) age=new_age;
        else cout << "Enter valid age!" << endl;
    }
    void setWeight(int new_weight){
        if(new_weight>0) weight = new_weight;
        else cout << "Enter valid weight!" << endl;
    }
};

class Student: public Person{
private:
    int begin_year;
    int end_year;
    static int student_counter;
    int number;
public:
    Student(string n, int a, string s, int w, int b_y, int e_y):begin_year(b_y),end_year(e_y),Person(n,a,s,w){
        student_counter++;
        number=student_counter;
    }
    void setYears(int b_y, int e_y){
        if((b_y>1900)&&(e_y>=b_y)){
            begin_year = b_y;
            end_year = e_y;
        }
        else cout << "Enter valid years!" << endl;
    }
    void print()const{
        cout << left << setw(20) << "Student # " << left << number << endl;
        cout << left << setw(20) << "Name: " << left << name << endl;
        cout << left << setw(20) << "Age: " << left << age << endl;
        cout << left << setw(20) << "Sex: " << left << sex << endl;
        cout << left << setw(20) << "Weight: " << left << weight << endl;
        cout << left << setw(20) << "Learning years: " << left << begin_year << " - " << end_year << endl;
    }
    string getName()const{return name;};
    int getCounter()const{return student_counter;}
    int getNumber()const{return number;}
    ~Student(){
        student_counter--;
    }
};
int Student::student_counter = 0;

// Task2
class Fruit{
protected:
    string name;
    string color;
public:
   Fruit(string n, string c):name(n),color(c){}
};

class Apple: public Fruit{
public:
    Apple(string c):Fruit("apple",c){};
    Apple(string n,string c):Fruit(n,c){};
    string getName() const{return name;}
    string getColor() const{return color;}
};

class Banana:public Fruit{
public:
    Banana():Fruit("banana","yellow"){};
    string getName() const{return name;}
    string getColor() const{return color;}
};

class GrannySmith:public Apple{
public:
    GrannySmith():Apple("Granny Smith apple","green"){}
    string getName() const{return name;}
    string getColor() const{return color;}
};


int main(int argc,char** args){
// Task1
    Student st1("Ivan",20,"male",60,2017,2020);
    Student st2("Svetlana",20,"female",50,2017,2020);
    Student st3("Petr",22,"male",65,2015,2019);
    Student *p_st=&st1;

    cout << "// Task1" << endl;
    cout << "Which student data do you want (Inter name): ";
    string st_name;
    cin >> st_name;
    bool suc_search = false;
    for(int i=0;i<st1.getCounter();i++){
        if(((p_st-i)->getName())==st_name){
            (p_st-i)->print();
            suc_search = true;
        }
    }
    if(!suc_search) cout << "Student not found!" << endl;
    cout << endl;
    st1.setYears(2001,2002);
    st1.setName("Tayler");
    st1.setWeight(80);
    st1.setAge(45);

    int st_num;
    do{
        cout << "Enter student number (1-" << st1.getCounter() << "): ";
        cin >> st_num;
    }while((st_num<=0)||(st_num>st1.getCounter()));

    (p_st-st_num+1)->print();
    cout << endl;


// Task2
    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "// Task2" << endl;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
