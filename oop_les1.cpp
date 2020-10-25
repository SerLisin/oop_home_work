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

// Task2
class RGBA{
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha):m_red(red),m_green(green),m_blue(blue),m_alpha(alpha){
    }
    void print(){
        printf("m_red = %d\n",m_red);
        printf("m_green = %d\n",m_green);
        printf("m_blue = %d\n",m_blue);
        printf("m_alpha = %d\n",m_alpha);
    }
};

int main(int argc,char** args){
    Power obj1;
    obj1.set(3,4);
    cout << obj1.calculate() << endl;
    
    RGBA obj2(110,111,112,113);
    obj2.print();

    
	return 0;
}
