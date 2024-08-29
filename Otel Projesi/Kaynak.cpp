#include <iostream>
#include <cstring>
#include <string>
#include <clocale>
#include <iomanip>
using namespace std;


class hotel {

    string* customer_name[100], * customer_lastname[100];
    int* days_of_stay[100]; 
    int sum = 0, counter1, counter2,pay1,pay2;
    enum status {
        empty_room,
        full_room
    } rooms[20];

public:

    hotel();
    void room_management(); 
    void room_reservation(); 
    void room_evacuation();
    void number_of_rooms(); 
    void room_report(); 
    void income(); 
};

int main()
{
    setlocale(LC_ALL, "Turkish");
    hotel h;
}
hotel::hotel()
{
    hotel::counter1 = 0;
    hotel::counter2 = 0;
    room_management();
}

void hotel::room_management()
{
    int number;
    for (int i = 0; i < 20; i++)
        rooms[i] = empty_room;
    do {
        cout << "\n\t ----------------- HOTEL GOKCEN -----------------" << endl;
        cout << "\t1. Room Reservation " << endl;
        cout << "\t2. Room Evacuation " << endl;
        cout << "\t3. Number of Occupied Rooms " << endl;
        cout << "\t4. Room Report " << endl;
        cout << "\t5. Total Income " << endl;
        cout << "\t6. Exit " << endl<<endl;
        cout << "Your choice - ";
        cin >> number;

        switch (number)
        {
        case 1: room_reservation();
            break;
        case 2: room_evacuation();
            break;
        case 3: number_of_rooms();
            break;
        case 4: room_report();
            break;
        case 5: income();
            break;
        case 6: exit(1);
            delete[] customer_name;
            delete[] customer_lastname;
            delete[] days_of_stay; 
            break;
        default: cout << "You made a wrong choice. Please choose between 1-6 " << endl<<endl;
        }
    } while (number != 6);
}

void hotel::room_reservation()
{
    int number, numberOfDays, i = 1, j = 13,pay1,pay2;
    string name, lastname;
    cout << "\n\t ------Please select a room type------" << endl;
    cout << "\t1. Single Room (750 TL)" << endl;
    cout << "\t2. Double Room (1250 TL)" << endl<<endl;
    cout << "Make your room selection-";
    cin >> number;
    cout << endl;

    switch (number)
    {
    case 1:
        for (; i <= 12; i++)
        {
            if (rooms[i] != full_room) {
                rooms[i] = full_room;
                cout << "Your Name:";
                cin >> name;
                cout << "Your Last Name:";
                cin >> lastname;
                cout << "Number of Days of Stay:" ;
                cin >> numberOfDays; cout << endl ;
                sum += numberOfDays * 750;
                counter1++;
                pay1 = numberOfDays * 750;
                customer_name[i] = new string;
                *customer_name[i] = name;
                customer_lastname[i] = new string;
                *customer_lastname[i] = lastname;
                days_of_stay[i] = new int; 
                *days_of_stay[i] = numberOfDays;
                cout << "************* Information ***************" << endl;
                cout << "Room number where you will stay - " << i << endl;
                cout << "The amount you need to pay - " << pay1 << endl;
                cout << "************* Information ***************" << endl<<endl<<endl;


           break;
            }            
        }
        if (i == 12) {
            cout << "All single rooms are full." << endl;
        }
        break;

    case 2:
        for (; j <= 20; j++)
        {
            if (rooms[j] != full_room) {
                rooms[j] = full_room;
                cout << "Your Name:";
                cin >> name;
                cout << "Your Last Name:";
                cin >> lastname;
                cout << "Number of Days of Stay:";
                cin >> numberOfDays; cout << endl;
                sum += numberOfDays * 1250;
                counter2++;
                pay2 = numberOfDays * 1250;
                customer_name[j] = new string;
                *customer_name[j] = name;
                customer_lastname[j] = new string;
                *customer_lastname[j] = lastname;
                days_of_stay[j] = new int;
                *days_of_stay[j] = numberOfDays;   
                cout << "************* Information ***************" << endl;
                cout << "Room number where you will stay - " << j << endl;
                cout << "The amount you need to pay - " << pay2 << endl;
                cout << "************* Information ***************" << endl<<endl<<endl;
                break;
            }     
        }

        if (j == 20) {
            cout << "All double rooms are full." << endl;
        }

        break;

    default: cout << "You entered the wrong room type." << endl;
    }
}

void hotel::room_evacuation()
{
    int number;
    cout << "Enter the room number you want to evacuate:";
    cin >> number;
    if (rooms[number] == full_room) {
        rooms[number] = empty_room;
        delete customer_name[number];
        delete customer_lastname[number];
        delete days_of_stay[number]; 
        if (number > 0 && number <= 12)
            counter1--;
        else if (number > 12 && number <= 20)
            counter2--;
        cout << "The room has been evacuated. We are waiting for you again, goodbye" << endl;
    }
    else {
        cout << "This room is already empty, please enter a different room number." << endl;
    }
}

void hotel::number_of_rooms()
{
    cout << "Number of occupied single rooms:" << counter1 << endl;
    cout << "Number of occupied double rooms:" << counter2 << endl;
}

void hotel::room_report()
{
    system("cls");
    if (counter1 == 0 && counter2 == 0) {
        cout << "All rooms are empty." << endl;
    }
    else {
        cout << "Room number   "<<setw(20)<<"  Customer Name - Last Name  "<<setw(20)<<"  Number of Days of Stay  " << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 1; i <= 20; i++) {
            if (rooms[i] == full_room) {
                cout << i << setw(25) << *customer_name[i] << setw(13)<< *customer_lastname[i] << setw(20) << *days_of_stay[i] << endl<<endl<<endl;
            }
        }
    }
}

void hotel::income()
{
    system("cls");
    cout << "Total Income:" << sum << endl;
}


