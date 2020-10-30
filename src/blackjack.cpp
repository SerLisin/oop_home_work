#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum Cardsuit { CLUBS, DIAMONDS, SPADES, HEARTS };
enum Cardtype {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};


class Card{
private:
    Cardsuit suit;
    Cardtype type;
    bool position;
public:
    Card(Cardsuit s, Cardtype t, bool p): suit(s),type(t), position(p){}
    void Flip(){position = !position;}
    int getValue() const {
        switch (type) {
            case ACE   : return 1;
            case TWO   : return 2;
            case THREE : return 3;
            case FOUR  : return 4;
            case FIVE  : return 5;
            case SIX   : return 6;
            case SEVEN : return 7;
            case EIGHT : return 8;
            case NINE  : return 9;
            case TEN   : return 10;
            case JACK  : return 10;
            case QUEEN : return 10;
            case KING  : return 10;
        }
        return -1;
    }

};

int main(int argc,char** args){

    Card card(SPADES,ACE,true);
    cout << card.getValue() << endl;

    return 0;
}
