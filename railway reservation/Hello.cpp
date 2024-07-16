#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string berth;

public:
    void setname(string s)
    {
        name = s;
    }
    string getname()
    {
        return name;
    }
    void setage(int a)
    {
        age = a;
    }
    int getage()
    {
        return age;
    }
    void setberth(string s)
    {
        berth = s;
    }
    string getberth()
    {
        return berth;
    }
};

int lower = 1, middle = 1, upper = 1, waiting = 1, rac = 1;
vector<Person> arr;

void book()
{
    string name, berth;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    Person p;
    p.setname(name);
    p.setage(age);
    cout << "Enter berth: ";
    cin >> berth;
    int f = 0;
    if (berth == "lower")
    {
        if (lower > 0)
        {
            lower--;
            p.setberth("lower");
            f = 1;
        }
        else if (middle > 0)
        {
            middle--;
            p.setberth("middle");
            f = 1;
        }
        else if (upper > 0)
        {
            upper--;
            f = 1;
            p.setberth("upper");
        }
    }
    else if (berth == "middle")
    {
        if (middle > 0)
        {
            middle--;
            p.setberth("middle");
            f = 1;
        }
        else if (lower > 0)
        {
            lower--;
            p.setberth("lower");
            f = 1;
        }
        else if (upper > 0)
        {
            upper--;
            f = 1;
            p.setberth("upper");
        }
    }
    else if (berth == "upper")
    {
        if (upper > 0)
        {
            upper--;
            f = 1;
            p.setberth("upper");
        }
        else if (middle > 0)
        {
            middle--;
            p.setberth("middle");
            f = 1;
        }
        else if (lower > 0)
        {
            lower--;
            p.setberth("lower");
            f = 1;
        }
    }
    else
    {
        cout << "Invalid input" << endl;
        return;
    }
    if (!f)
    {
        if (rac > 0)
        {
            rac--;
            p.setberth("rac");
        }
        else if (waiting > 0)
        {
            waiting--;
            p.setberth("waiting");
        }
        else
        {
            cout << "No seats available";
            return;
        }
    }
    arr.push_back(p);
    cout << "Booked " + p.getberth() << endl;
    return;
}

void cancel()
{
    string name, berth;
    cout << "Enter name: ";
    cin >> name;
    int ind = -1;
    vector<Person *> Rac, Waiting;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].getname() == name)
        {
            berth = arr[i].getberth();
            ind = i;
        }
        if (arr[i].getberth() == "rac")
        {
            Rac.push_back(&arr[i]);
        }
        else if (arr[i].getberth() == "waiting")
        {
            Waiting.push_back(&arr[i]);
        }
    }
    if (ind == -1)
    {
        cout << "Invalid Input" << endl;
        return;
    }
    if (berth == "waiting")
    {
    }
    else if (berth == "rac")
    {
        if (Waiting.size() > 0)
        {
            waiting++;
            Waiting[0]->setberth("rac");
        }
        else
        {
        }
    }
    else
    {
        cout << Rac.size();
        if (Rac.size() > 0)
        {
            Rac[0]->setberth(berth);
            if (Waiting.size() > 0)
            {
                waiting++;
                Waiting[0]->setberth("rac");
            }
            else
            {
                rac++;
            }
        }
        else
        {
            if (berth == "upper")
                upper++;
            else if (berth == "lower")
                lower++;
            else if (berth == "middle")
                middle++;
        }
    }
    arr.erase(arr.begin() + ind);
    cout << "Cancelled" << endl;
    return;
}

void printBooked()
{
    cout << "Name\t\t\t\tAge\t\t\t\tBerth" << endl;
    for (auto i : arr)
    {
        cout << i.getname() << "\t\t\t\t" << i.getage() << "\t\t\t\t" << i.getberth() << endl;
    }
}

void printAvail()
{
    cout << "Berth" << "\t\t\t\t" << "count" << endl;
    cout << "Upper" << "\t\t\t\t" << upper << endl;
    cout << "Lower" << "\t\t\t\t" << lower << endl;
    cout << "Middle" << "\t\t\t\t" << middle << endl;
    cout << "Rac" << "\t\t\t\t" << rac << endl;
    cout << "Waiting" << "\t\t\t\t" << waiting << endl;
}

int main()
{
    while (1)
    {
        cout << "1.Book\n2.Cancel\n3.Print Booked\n4.Print Available\n5.Exit\nEnter choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            book();
        }
        else if (choice == 2)
        {
            cancel();
        }
        else if (choice == 3)
        {
            printBooked();
        }
        else if (choice == 4)
        {
            printAvail();
        }
        else
        {
            break;
        }
    }
}