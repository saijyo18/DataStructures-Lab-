//implement round robin process scheduling algorithm for a CPU using circularly linked list
#include <iostream>
#include "cll.h"
using namespace std;

int main()
{
    int option,time,cpu_time;
    List process;

    cout << "Allocate fixed CPU time for process: ";
    cin >> cpu_time;

    while (option != 3)
    {
        cout << "\nMENU:\n1.Insert Process\n2.Execute\n3.Exit\n";
        cout << "Enter your choice:";
        cin >> option;

        switch (option)
        {
            case 1:
            cout << "Enter process time: ";
            cin >> time;
            process.insertProcess(time);
            cout << "Successfully inserted process in queue.\n";
            process.display();
            break;

            case 2:
            process.Execute(cpu_time);
            process.display();
            break;

            case 3:
            cout << "Exiting.";
            break;
        }

    }

    return 0;
}
