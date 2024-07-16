#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
private:
    bool vip;
    string type;
    int start, dest;
    int amount;
    int id;

public:
    Vehicle(int i, bool v, string t, int s, int d, int amt)
    {
        id = i;
        vip = v;
        start = s;
        dest = d;
        type = t;
        amount = amt;
    }
    void setamount(int amt)
    {
        amount += amt;
    }
    int getamount()
    {
        return amount;
    }
    void setvip()
    {
        vip = true;
    }
    bool getvip()
    {
        return vip;
    }
    void settype(string s)
    {
        type = s;
    }
    string gettype()
    {
        return type;
    }
    void setstart(int n)
    {
        start = n;
    }
    int getstart()
    {
        return start;
    }
    void setdest(int n)
    {
        dest = n;
    }
    int getdest()
    {
        return dest;
    }
    int getid()
    {
        return id;
    }
};

class Toll
{
private:
    int id;
    int carprice, lorryprice;
    vector<Vehicle> vehicles;
    int amount;

public:
    Toll()
    {
    }
    Toll(int i, int cp, int lp)
    {
        id = i;
        carprice = cp;
        lorryprice = lp;
        amount = 0;
    }

    void setid(int n)
    {
        id = n;
    }
    int getid()
    {
        return id;
    }
    void setcarprice(int p)
    {
        carprice = p;
    }
    int getcarprice()
    {
        return carprice;
    }
    void setlorryprice(int p)
    {
        lorryprice = p;
    }
    int getlorryprice()
    {
        return lorryprice;
    }
    void addVehicle(Vehicle v)
    {
        vehicles.push_back(v);
    }
    vector<Vehicle> getvehicles()
    {
        return vehicles;
    }
    void setamount(int amt)
    {
        amount += amt;
    }
    int getamount()
    {
        return amount;
    }
};

vector<Vehicle> vehicles;
map<int, Toll> um;
int id = 1;

void addVehicle()
{
    string t;
    int s, d;
    char c;
    bool v = false;
    cout << "Enter type (car/lorry): ";
    cin >> t;
    cout << "Enter start (1-4): ";
    cin >> s;
    cout << "Enter destination (1-4): ";
    cin >> d;
    cout << "Enter vip (y/n): ";
    cin >> c;
    if (c == 'y')
        v = true;
    int x = min(s, d), y = max(s, d);
    int amt = 0;
    for (int i = x; i <= y; i++)
    {
        int q = 0;
        if (t == "car")
        {
            if (v)
            {
                q = (um[i].getcarprice() * 0.8);
            }
            else
            {
                q = um[i].getcarprice();
            }
        }
        else
        {
            if (v)
            {
                q = (um[i].getlorryprice() * 0.8);
            }
            else
            {
                q = um[i].getlorryprice();
            }
        }
        um[i].setamount(q);
        amt += q;
    }
    Vehicle vh(id++, v, t, s, d, amt);
    vehicles.push_back(vh);
    for (int i = x; i <= y; i++)
    {
        um[i].addVehicle(vh);
    }
    cout << "Added\n";
}

void dispTolls()
{
    for (auto i : um)
    {
        cout << "Toll " << i.first << endl;
        for (auto j : i.second.getvehicles())
        {
            cout << j.getid() << " " << j.gettype() << endl;
        }
        cout << "total " << i.second.getamount() << endl;
        cout << endl;
    }
}

void dispVehicles()
{
    for (auto i : vehicles)
    {
        cout << i.getid() << " " << i.gettype() << " " << i.getstart() << " " << i.getdest() << " " << i.getamount() << endl;
    }
    cout << endl;
}

int main()
{

    Toll t1(1, 10, 20);
    um[1] = t1;
    Toll t2(2, 5, 10);
    um[2] = t2;
    Toll t3(3, 15, 30);
    um[3] = t3;
    Toll t4(4, 4, 8);
    um[4] = t4;

    while (1)
    {
        cout << "1.Add vehicle\n2.Display tolls\n3.Display vehicles\n4.Exit\nEnter choice: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            addVehicle();
        }
        else if (ch == 2)
        {
            dispTolls();
        }
        else if (ch == 3)
        {
            dispVehicles();
        }
        else
        {
            break;
        }
    }
}
