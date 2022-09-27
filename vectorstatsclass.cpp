


#include<iostream>
#include <cmath>
#include<string>
#include<vector>
#include <iomanip>
#include <math.h>
#include<algorithm>
using namespace std;

class Stat{
private:
    vector<double>x;
    friend double sum(vector<double>);
    friend double largerSpread(Stat*,Stat*);

public:
    Stat(vector<double>);
    double mean();
    double sd();
    double var();
    vector<double> zscores();


};
Stat::Stat(vector<double>vect){
    x = vect;

}


double Stat::mean() {
    double total = 0;
    for(int i=0; i < x.size();i++)
        total += x[i];
    return total / x.size();

};

double Stat::sd(){
    double ttl = 0;
    for(int i=0; i < x.size();i++)
        ttl += x[i];
    double m = ttl / x.size();
    double summ =0;
    for(int i=0; i < x.size();i++)
        summ += pow((x[i]-m),2);
    double standard = sqrt(summ/ x.size());
    return standard;


};

double Stat::var(){
    double j = this->sd();
    double o = pow(j,2);
    return o;

};


vector <double> Stat::zscores() {
    vector <double> C;
    double m = this->mean();
    double s = this->sd();
    for(int i=0; i<x.size();i++)
        C.push_back((x[i]-m)/s);
    return C;



};

std::ostream& operator<<(ostream& os, const vector<double>& vect)
{
    os << "<";
    for (int i = 0; i < vect.size(); ++i) {
        os << vect[i];
        if (i != vect.size() - 1)
            os << ", ";
    }
    os << ">"<<endl;
    return os;
}
double largerSpread(Stat *C, Stat *W){
    double c = C->var();
    double w = W->var();
    if(c>w)
        return c;
    else
        return w;

};
double sum(vector<double>x){
    double ttla =0;
    for(int i=0; i<x.size();i++)
        ttla += x[i];
    return ttla;

};

int main(){


    vector <double>X1 ={6,3,4,5,1,2,9,8,3,5};
    vector <double>X2 ={1,8,0,2,5,6,9,0,4,9};
    Stat A (X1);
    Stat B (X2);
    cout << A.mean()<< endl;
    cout << A.sd() << endl;
    cout << sum(A.zscores()) << endl;
    cout << largerSpread(&A, &B) << endl; 

}
