/*#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>*/

#include <bits/stdc++.h>
using namespace std;
//#define count 4
int ranking[100][100];
int manPreferences[100][100];
int womanPreferences[100][100];
int next[100];
int pairs[100];
struct Queue
{
    int front, rear, capacity;
    int *queue;
    // constructor function
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
    // destructor function
    ~Queue()
    {
        delete[] queue;
    }
    // inserts an element at the end of the queue
    void enqueue(int data)
    {
        // check queue is full or not
        if (capacity == rear)
        {
            printf("\nQueue is full\n");
            return;
        }
        // insert element at the rear
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }
    // deletes an element from the front of the queue
    void dequeue()
    {
        if (front == rear)
        {
            printf("\nQueue is empty\n");
            return;
        }
        // shift all the elements from index 2 till rear
        // to the left by one
        else
        {
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            // decrement rear
            rear--;
        }
        return;
    }
    // Returns boolean value if the queue is full or not
}