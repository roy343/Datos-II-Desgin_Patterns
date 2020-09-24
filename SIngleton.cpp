#include <iostream>

using namespace std;

class Singleton {
    static Singleton *instancia;
    int data;

    Singleton() {
        data = 0;
    }

public:
    static Singleton *getInstance() {
        if (!instancia)
            instancia = new Singleton;
        return instancia;
    }

    int getData() {
        return this -> data;
    }

    void setData(int data) {
        this -> data = data;
    }
};


Singleton *Singleton::instancia = 0;

int main(){
    Singleton *s = s->getInstance();
    cout << s->getData() << endl;
    s->setData(343);
    cout << s->getData() << endl;
    return 0;
}