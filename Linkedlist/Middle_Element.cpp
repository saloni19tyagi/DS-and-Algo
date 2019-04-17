#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link; // Pointer to node
};

int main()
{

    int n, item;
    cin >> n;

    struct node *head = NULL;         // pointer to Head Node
    struct node *t = NULL, *slow = NULL , *fast = NULL; // pointer to traverse the linkedlist

    for (int i = 0; i < n; i++)
    {
        cin >> item;
        node *temp = new node;
        temp->data = item;
        temp->link = NULL;

        if (head == NULL)
        {
            head = temp; // When linkedlist is empty
            t = head;
        }
        else
        {
            t->link = temp; // inserting element at the back
            t = temp;
        }
    }

    slow = head ; // skipping this pointer by 2 nodes
    fast = head ; // skipping this pointer by 1 node

    while (fast != NULL)
    {
        fast = fast->link;
        if (fast == NULL)
            break;
        fast = fast->link;
        slow = slow->link;
    }

    cout << slow->data << "\n"; // at the end , it will point to middle element
}