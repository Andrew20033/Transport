#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

class transport
{
public:
    virtual void getData() = 0;
};
class car : public transport
{
protected:
    int time = 10;
    int cost = 20;
public:
    void getData()
    {
        char c;
        double S;
        cout << "Specify the distance in km: "; cin >> S;
        cout << "Do you have luggage? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "Driving time: " << S * time << " min" << endl;
            cout << "Fare with luggage: " << (cost + 20) * S * time << " grn" << endl;
        }
        else if (c == 'n')
        {
            cout << "Fare without luggage: " << cost * S << " grn" << endl;
            cout << "Driving time: " << time * S << " min" << endl;
        }

    }
};
class moped : public car
{
public:
    void getData()
    {
        char c;
        double S;
        cout << "Specify the distance in km: "; cin >> S;
        cout << "Do you have luggage? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "Driving time: " << S * (time + 10) << endl;
            cout << "Fare with luggage: " << ((cost - 10) + 20) * S * (time + 10) << " grn" << endl;
        }
        else if (c == 'n')
        {
            cout << "Fare without luggage: " << cost * S << " grn" << endl;
            cout << "Driving time: " << time * S << " min" << endl;
        }

    }
};
class velo : public moped
{
    void getData()
    {
        char c;
        double S;
        cout << "Specify the distance in km: "; cin >> S;
        cout << "Do you have luggage? (y/n) ";
        cin >> c;
        if (c == 'y')
        {
            cout << "What's the difference? Pfft, no room. Either you or the luggage? (i/b)";
            cin >> c;
            if (c == 'i')
            {
                cout << "Fare without luggage: " << cost << " grn" << endl;
                cout << "Driving time : " << time << " min" << endl;
            }
            else if (c == 'b')
            {
                cout << "Baggage fare 0 grn" << endl;
                cout << "Thanks for the gift!" << endl;
            }
        }
        else
        {
            cout << "Fare without luggage: " << cost << " grn" << endl;
            cout << "Driving time: " << time << " min" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    transport* autom = new car;
    transport* mop = new moped;
    transport* vel = new velo;
    int choice;
    cout << "What do we want to ride?\n"
        "1. Auto\n"
        "2. Moped\n"
        "3. Cicle\n";
    cout << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        autom->getData();
        break;
    case 2:
        mop->getData();
        break;
    case 3:
        vel->getData();
        break;
    }
    delete autom;
    delete mop;
    delete vel;
}