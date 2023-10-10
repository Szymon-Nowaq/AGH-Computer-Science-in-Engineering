#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Punkt{
public:
    int x;
    int y;
    Punkt(){
        x = 0;
        y = 0;
    }
    Punkt(int a, int b){
        x = a;
        y = b;
    }
    Punkt(const Punkt &p){
        x = p.x;
        y = p.y;
    }
    void pisz(){
        cout<<x<<", "<<y;
    }
};

double get_distance(int x1, int y1, int x2, int y2);
Punkt zad1(int n, int m, int x, int y);
double zad2(int n, int m, int color_count);


int main() {
    Punkt x = zad1(10,10,7,8);
    //x.pisz();
    zad2(5,5, 10);
    return 0;
}


double get_distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}


Punkt zad1(int n, int m, int x, int y){
    int ** plansza = new int * [n];
    for(int i = 0; i < m; i++)
        plansza[i] = new int [m];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            plansza[i][j] = 0;
    }
    plansza[x][y] = 1;
    double dist_corner[4];
    dist_corner[0] = get_distance(x,y,0,0);
    dist_corner[1] = get_distance(x,y,n,0);
    dist_corner[2] = get_distance(x,y,0,m);
    dist_corner[3] = get_distance(x,y,n,m);
    Punkt corners[4];
    corners[0] = Punkt(0,0);
    corners[1] = Punkt(n,0);
    corners[2] = Punkt(0,m);
    corners[3] = Punkt(n,m);
    int max = 0;
    for(int i = 1; i < 4; i++){
        if(dist_corner[i] > dist_corner[max])
            max = i;
    }
    for(int i = 0; i < m; i++)
        delete [] plansza[i];
    delete [] plansza;
    return corners[max];
}

double zad2(int n, int m, int color_count){
    srand( time( NULL ) );
    int ** plansza = new int * [n];
    for(int i = 0; i < m; i++)
        plansza[i] = new int [m];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            plansza[i][j] = rand() % color_count;
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout<<plansza[i][j]<<" ";
        cout<<endl;
    }
    int * sas_count = new int [color_count]();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if(j > 0 && j < m - 1){
                if(plansza[i][j - 1] == plansza[i][j + 1])
                    sas_count[plansza[i][j]]++;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < color_count; i++) {
        if(max < sas_count[i])
            max = sas_count[i];
        if (sas_count[i] != 0)
            cout << i << " ma " << sas_count[i] << " takich samych sąsiadów" << endl;
    }
    for(int i = 0; i < m; i++)
        delete [] plansza[i];
    delete [] plansza;
    delete [] sas_count;
    return max;
}