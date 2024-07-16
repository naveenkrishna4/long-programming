#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    Person *father, *mother;
    vector<Person *> brothers, daughters, sons, sisters;

public:
    void setname(string s)
    {
        name = s;
    }
    string getname()
    {
        return name;
    }
    void setfather(Person *f)
    {
        father = f;
    }
    void setmother(Person *f)
    {
        mother = f;
    }
    Person *getfather()
    {
        return father;
    }
    Person *getmother()
    {
        return mother;
    }
};

int main()
{
    vector<Person *> arr;
    while (1)
    {
        cout << "1.Add\n2.View\n3.Exit\n";
        cout << "enter your choice: ";
        int c;
        cin >> c;
        if (c == 3)
            break;
        else if (c == 1)
        {
            string f, m, bros, sis, daugs, sons, n;
            cout << "Enter name :";
            cin >> n;
            Person *p = new Person();
            p->setname(n);
            cout << "Enter father name :";
            cin >> f;
            cout << "Enter mother name :";
            cin >> m;
            Person *mother, *father;
            for (Person *i : arr)
            {
                if (i->getname() == m)
                {
                    mother = i;
                }
                if (i->getname() == f)
                {
                    father = i;
                }
                if (mother && father)
                    break;
            }
            p->setfather(father);
            p->setmother(mother);
            arr.push_back(p);
        }
        else if (c == 2)
        {
            string n;
            cout << "Enter name :";
            cin >> n;
        }
    }
}