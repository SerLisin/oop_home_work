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

// Task3
class Stack{
private:
    int num[10];
    int depth;
public:
    void reset(){
        for(int i=0;i<10;i++)num[i]=0;
        depth=0;
    }
    bool push(int a){
        int i= depth;
        if(depth<10){
            while(i>0){
                num[i]=num[i-1];
                i--;
            }
            num[0]=a;
            depth++;
            return true;
        }
        else return false;
    }
    int pop(){
        int a;
        a = num[0];
        if(depth>=1){
            for(int i=0;i<depth-1;i++)num[i]=num[i+1];
            depth--;
            return a;
        }
        else{
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
    void print(){
        cout << "(";
        int i = 0;
        while(i<depth){
            if(i) cout << " ";
            cout << num[depth-i-1]; // Я бы выводил числа в обратном порядке,так как числа, попавшие в стек раньше,
            i++;                    // должны иметь больший индекс и должны располагаться правее
        }
        cout << ")" << endl;
    }

};

int main(int argc,char** args){
    Power obj1;
    obj1.set(3,4);
    cout << obj1.calculate() << endl;

    RGBA obj2(110,111,112,113);
    obj2.print();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    for(int i=0;i<10;i++)stack.push(i);
    stack.print();

    if(stack.push(100)) stack.print(); else cout << "Stack is full!" << endl;

    for(int i=0;i<11;i++)stack.pop();

	return 0;
}
