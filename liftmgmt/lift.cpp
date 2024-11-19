#include <bits/stdc++.h>
using namespace std;

// direction => 1:up,2:down,0:stop;
// isMaintenance => 1:lift is under maintenance, 0:lift is working;
// allowedFloors => 0:all floors, 1:0 and 1-5, 2:0 and 6-10;

class Lift
{
public:
    int currentFloor;
    int direction;
    int capacity;
    int id;
    int noOfPeople;
    int allowedFloors;
    bool isMaintenance;
    Lift(int currentFloor, int direction, int capacity, int id, bool isMaintenance, int allowedFloors, int noOfPeople)
    {
        this->currentFloor = currentFloor;
        this->direction = direction;
        this->capacity = capacity;
        this->id = id;
        this->allowedFloors = allowedFloors;
        this->isMaintenance = isMaintenance;
        this->noOfPeople = noOfPeople;
    }
};

void callLift(vector<Lift *> lifts)
{
    int src, dest;
    cout << "Enter the source: ";
    cin >> src;
    cout << "Enter the destination: ";
    cin >> dest;
    vector<Lift *> possibleLifts = {};
    for (int i = 0; i < lifts.size(); i++)
    {
        if (lifts[i]->isMaintenance == false || lifts[i]->capacity < lifts[i]->noOfPeople)
        {
            if (lifts[i]->allowedFloors == 0)
            {
                possibleLifts.push_back(lifts[i]);
            }
            else if (lifts[i]->allowedFloors == 1 && ((src == 0 || (src >= 1 && src <= 5)) && (dest == 0 || (dest >= 1 && dest <= 5))))
            {
                possibleLifts.push_back(lifts[i]);
            }
            else if (lifts[i]->allowedFloors == 2 && ((src == 0 || (src >= 6 && src <= 10)) && (dest == 0 || (dest >= 6 && dest <= 10))))
            {
                possibleLifts.push_back(lifts[i]);
            }
        }
    }
    if (possibleLifts.size() == 0)
    {
        cout << "No lift available\n";
        return;
    }

    int minDist = INT_MAX;
    int dir = src < dest ? 1 : 2;
    int selectedLiftDir, selectedLiftId, selectedLiftallowedFloors;
    for (int i = 0; i < possibleLifts.size(); i++)
    {
        int dist = abs(possibleLifts[i]->currentFloor - src);
        if (dist < minDist)
        {
            minDist = dist;
            selectedLiftId = possibleLifts[i]->id;
            if (src == possibleLifts[i]->currentFloor)
            {
                selectedLiftDir = possibleLifts[i]->direction;
            }
            else if (src > possibleLifts[i]->currentFloor)
            {
                selectedLiftDir = 1;
            }
            else
            {
                selectedLiftDir = 2;
            }
            selectedLiftallowedFloors = possibleLifts[i]->allowedFloors;
        }
        else if (dist == minDist)
        {
            int d = possibleLifts[i]->direction;
            if (possibleLifts[i]->currentFloor > src)
                d = 2;
            else if (possibleLifts[i]->currentFloor < src)
                d = 1;
            if (d == dir)
            {
                if (selectedLiftDir != dir)
                {
                    selectedLiftId = possibleLifts[i]->id;
                    if (src == possibleLifts[i]->currentFloor)
                    {
                        selectedLiftDir = possibleLifts[i]->direction;
                    }
                    else if (src > possibleLifts[i]->currentFloor)
                    {
                        selectedLiftDir = 1;
                    }
                    else
                    {
                        selectedLiftDir = 2;
                    }
                    selectedLiftallowedFloors = possibleLifts[i]->allowedFloors;
                }
                else if (selectedLiftallowedFloors == 0 && possibleLifts[i]->allowedFloors != 0)
                {
                    selectedLiftId = possibleLifts[i]->id;
                    selectedLiftallowedFloors = possibleLifts[i]->allowedFloors;
                }
            }
            else if (dir != d)
            {
                if (selectedLiftallowedFloors == 0 && possibleLifts[i]->allowedFloors != 0)
                {
                    selectedLiftId = possibleLifts[i]->id;
                    selectedLiftallowedFloors = possibleLifts[i]->allowedFloors;
                }
            }
        }
    }
    for (int i = 0; i < lifts.size(); i++)
    {
        if (lifts[i]->id == selectedLiftId)
        {
            lifts[i]->currentFloor = dest;
            lifts[i]->direction = dir;
            lifts[i]->noOfPeople++;
            break;
        }
    }
    cout << "Lift " << selectedLiftId << " is assigned\n";
}

void display(vector<Lift *> lifts)
{
    for (int i = 0; i < lifts.size(); i++)
    {
        cout << "Lift " << lifts[i]->id;
        if (lifts[i]->isMaintenance)
            cout << " is under maintenance\n";
        else
        {
            cout << " is at floor " << lifts[i]->currentFloor << " and is ";
            if (lifts[i]->direction == 1)
            {
                cout << "going up\n";
            }
            else if (lifts[i]->direction == 2)
            {
                cout << "going down\n";
            }
            else
            {
                cout << "stopped\n";
            }
        }
    }
}
void update(vector<Lift *> lifts)
{
    int id;
    cout << "Enter the lift id: ";
    cin >> id;
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;
    int allowedFloors;
    cout << "Enter the allowed floors (0/1/2): ";
    cin >> allowedFloors;
    bool isMaintenance;
    cout << "Enter the maintenance status (0/1): ";
    cin >> isMaintenance;
    for (int i = 0; i < lifts.size(); i++)
    {
        if (lifts[i]->id == id)
        {
            lifts[i]->capacity = capacity;
            lifts[i]->allowedFloors = allowedFloors;
            lifts[i]->isMaintenance = isMaintenance;
            break;
        }
    }
    cout << "Updated \n";
}

int main()
{
    Lift *lift1 = new Lift(0, 0, 10, 1, false, 0, 0);
    Lift *lift2 = new Lift(0, 0, 10, 2, false, 0, 0);
    Lift *lift3 = new Lift(0, 0, 10, 3, false, 0, 0);
    Lift *lift4 = new Lift(0, 0, 10, 4, false, 0, 0);
    Lift *lift5 = new Lift(0, 0, 10, 5, true, 0, 0);
    vector<Lift *> lifts = {lift1, lift2, lift3, lift4, lift5};

    while (1)
    {
        cout << "\nMAIN MENU\n1.User\n2.Admin\n3.Exit\nEnter your choice: ";
        int ch1;
        cin >> ch1;
        if (ch1 == 1)
        {
            int ch = 0;
            while (ch != 3)
            {
                cout << "\nUSER MENU\n1.Call Lift\n2.Display\n3.Exit\nEnter your choice: ";
                ;
                cin >> ch;
                if (ch == 1)
                {
                    callLift(lifts);
                }
                else if (ch == 2)
                {
                    display(lifts);
                }
                else if (ch == 3)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        else if (ch1 == 2)
        {
            int ch = 0;
            while (ch != 4)
            {
                cout << "\nADMIN MENU\n1.Call lift\n2.Display\n3.Update\n4.Exit\nEnter your choice: ";
                int ch;
                cin >> ch;
                if (ch == 1)
                {
                    callLift(lifts);
                }
                else if (ch == 2)
                {
                    display(lifts);
                }
                else if (ch == 3)
                {
                    update(lifts);
                }
                else if (ch == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        else if (ch1 == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}