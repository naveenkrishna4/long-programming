#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    char gender;
    Person *father, *mother;
    vector<Person *> brothers, daughters, sons, sisters;

public:
    Person() : father(nullptr), mother(nullptr) {}
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
    void addbrother(Person *a)
    {
        brothers.push_back(a);
    }
    vector<Person *> getbrothers()
    {
        return brothers;
    }
    void adddaughter(Person *a)
    {
        daughters.push_back(a);
    }
    vector<Person *> getdaughters()
    {
        return daughters;
    }
    void addson(Person *a)
    {
        sons.push_back(a);
    }
    vector<Person *> getsons()
    {
        return sons;
    }
    void addsister(Person *a)
    {
        sisters.push_back(a);
    }
    vector<Person *> getsisters()
    {
        return sisters;
    }
    void setgender(char c)
    {
        gender = c;
    }
    char getgender()
    {
        return gender;
    }
};

int main()
{
    unordered_map<string, Person *> um;
    while (1)
    {
        cout << "\nMenu\n1.Add\n2.View\n3.Exit\n";
        cout << "enter your choice: ";
        int c;
        cin >> c;
        if (c == 3)
            break;
        else if (c == 1)
        {
            string f, m, n;
            char g;
            cout << "Enter name :";
            cin >> n;
            cout << "Enter gender (M/F): ";
            cin >> g;
            Person *p = new Person();
            p->setgender(g);
            p->setname(n);
            cout << "Enter father name :";
            cin >> f;
            cout << "Enter mother name :";
            cin >> m;
            Person *mother, *father;
            if (um.find(m) == um.end())
            {
                um[m] = new Person();
            }
            if (um.find(f) == um.end())
            {
                um[f] = new Person();
            }
            mother = um[m];
            father = um[f];
            mother->setname(m);
            mother->setgender('F');
            father->setname(f);
            father->setgender('M');
            p->setfather(father);
            p->setmother(mother);

            if (g == 'M')
            {
                mother->addson(p);
                father->addson(p);
            }
            else
            {
                mother->adddaughter(p);
                father->adddaughter(p);
            }
            for (auto i : um)
            {
                Person *per = i.second;
                if (per->getfather() && per->getfather()->getname() == f)
                {
                    if (per->getgender() == 'M')
                    {
                        p->addbrother(per);
                    }
                    else
                    {
                        p->addsister(per);
                    }
                    if (p->getgender() == 'M')
                    {
                        per->addbrother(p);
                    }
                    else
                    {
                        per->addsister(p);
                    }
                }
            }
            um[n] = p;
            cout << "Added\n";
        }
        else if (c == 2)
        {
            string n;
            cout << "Enter name :";
            cin >> n;
            if (um.find(n) == um.end())
            {
                cout << "Inavlid";
                continue;
            }
            Person *p = um[n];
            cout << "Mother: " << p->getmother()->getname() << endl;
            cout << "Father: " << p->getfather()->getname() << endl;
            cout << "Brothers: ";
            for (auto j : p->getbrothers())
            {
                cout << j->getname() << " ";
            }
            cout << "\nSisters: ";
            for (auto j : p->getsisters())
            {
                cout << j->getname() << " ";
            }
            cout << endl;

            if (p->getgender() == 'M')
            {
                Person *f = p->getfather();
                {
                    for (auto k : f->getsisters())
                    {
                        for (auto j : k->getdaughters())
                        {
                            cout << j->getname() << " ";
                        }
                    }
                }
                Person *m = p->getmother();
                {
                    for (auto k : f->getbrothers())
                    {
                        for (auto j : k->getdaughters())
                        {
                            cout << j->getname() << " ";
                        }
                    }
                }
            }
            else
            {
                Person *f = p->getfather();
                {
                    for (auto k : f->getsisters())
                    {
                        for (auto j : k->getsons())
                        {
                            cout << j->getname() << " ";
                        }
                    }
                }
                Person *m = p->getmother();
                {
                    for (auto k : f->getbrothers())
                    {
                        for (auto j : k->getsons())
                        {
                            cout << j->getname() << " ";
                        }
                    }
                }
            }
        }
    }
}