#include <iostream>
#include <cmath>
#include <cstdint>

using std::cout;
using std::endl;

// Task1
class Power{
private:
    float man = 2;
    float exp = 5;
public:
    void set(float a, float b){
        man = a;
        exp = b;
    }
    double calculate(){
        return pow(man,exp);
    }
};


/
int main(int argc,char** args){
    Power obj1;
    obj1.set(3,4);
    cout << obj1.calculate() << endl;

    
	return 0;
}
