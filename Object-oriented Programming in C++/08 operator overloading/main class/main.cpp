#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Wektor{
    double x, y;

public:
    Wektor(double x1, double y1){
        x = x1;
        y = y1;

    }

    double getX() const {
        return x;
    }

    void setX(double x) {
        Wektor::x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        Wektor::y = y;
    }

    Wektor(){
        x = 0;
        y = 0;
    }

    double getLen(){
        return sqrt(pow(x,2)+pow(y,2));
    }

    Wektor findClosest(Wektor *tab, int n){
        Wektor answer = tab[0];
        for(int i = 1; i < n; i++){
            if(std::abs(getLen() - tab[i].getLen()) < std::abs(getLen() - answer.getLen()))
                answer = tab[i];
        }
        return answer;
    }

    Wektor operator+(const Wektor& w){
        return Wektor(x + w.x, y+w.y);
    }

    double operator*(const Wektor& w){
        return (x * w.x + y * w.y);
    }
};

ostream& operator<<(ostream& out, const Wektor& w){
    out << '['<< w.getX() <<','<<w.getY()<<']';
    return out;
}

void bubbleSort(Wektor *arr, int n);


int main() {
    Wektor w1(3,5);
    Wektor w2(-2,7);
    cout<<w1<<endl<<w2<<endl;
    cout<<"w1 + w2 = "<<w1 + w2<<endl;
    cout<<"w1 * w2 = "<<w1 * w2<<endl;
    Wektor tab[20];
    srand( time( NULL ) );
    for(int i = 0; i < 20; i++)
        tab[i] = Wektor((rand() % 31) - 16, (rand() % 31) - 16);
    bubbleSort(tab, 20);
    for(int i = 0; i < 20; i++)
        cout<<tab[i]<<" dlugosc: "<<tab[i].getLen()<<endl;
    Wektor w3 = w1.findClosest(tab, 20);
    cout<<endl<<w3<<" dlugosc: "<<w3.getLen()<<endl;
}

void bubbleSort(Wektor* arr, int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].getLen() > arr[j + 1].getLen())
                swap(arr[j], arr[j + 1]);
}