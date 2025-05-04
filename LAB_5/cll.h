#ifndef CLL_H
#define CLL_H

#include <iostream>
using namespace std;

class List
{
    private:

    struct node {
        int data;
        struct node *next;
    }*head = NULL,*tail = head;

    public:

    void insertBeginning(int element)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = element;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            tail = newnode;
        }

        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = newnode;
        }
    }
    //
    void insertProcess(int element)
    {
        if (head == NULL)
        {
            insertBeginning(element);
        }
        else
        {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = element;
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
    }

   
    //
    void Execute(int fixed_time)
    {
        if (head == NULL)
        {
            cout << "No processes in queue";
        }
        
        if (head->next == head)
        {
            int time;
            struct node* temp = head;
            time = temp->data;

            head = NULL;
            tail = NULL;
            free(temp);

            time = time - fixed_time;

            if (time <= 0)
            {
                cout << "Process completed.\n";
                return;
            }
            else

            {
                insertProcess(time);
            }
        }

        else
        {
            int time;
            struct node* temp = head;

            head = head->next;
            tail->next = head;
            time = temp->data;
            free(temp);

            time = time - fixed_time;

            if (time <= 0)
            {
                cout << "Process completed.";
                return;
            }
            else
            {
                insertProcess(time);
            }
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No pending processes.";
        }
        else
        {
            cout << "Process Queue: ";
            struct node* temp = head;
            while (true)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
            }
            cout << "\n";
        }
    }

};

#endif
