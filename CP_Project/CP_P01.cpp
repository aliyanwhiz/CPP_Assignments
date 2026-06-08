#include <iostream>
#include <iomanip>

using namespace std;

// 1. Structure Definition [cite: 15]
struct Node
{
    int data;   // Stores the value of the node [cite: 17]
    Node *next; // Pointer to the next node [cite: 18]
};

// --- Function Prototypes ---
void insert_begin(Node *&head, int d);
void insert_end(Node *&head, int d);
void insert_at(Node *&head, int d, int p);
void delete_begin(Node *&head);
void delete_end(Node *&head);
void delete_at(Node *&head, int p);
void delete_data(Node *&head, int d);
void display_list(Node *head); // Updated for custom boxed printing
Node *search_data(Node *head, int d);
void reverse_list(Node *&head);
void sort_list(Node *head);
int get_size(Node *head);
void clear_list(Node *&head); // Clears complete list on exit

int main()
{
    Node *head = NULL; // Local head pointer [cite: 49]
    int choice, data, position;

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "      LINKED LIST MANAGEMENT MENU        \n";
        cout << "=========================================\n";
        cout << "1. Insert at Beginning (insert_begin)\n";
        cout << "2. Insert at End (insert_end)\n";
        cout << "3. Insert at Specific Position (insert_at)\n";
        cout << "4. Delete from Beginning (delete_begin)\n";
        cout << "5. Delete from End (delete_end)\n";
        cout << "6. Delete from Specific Position (delete_at)\n";
        cout << "7. Delete First Instance of Value (delete_data)\n";
        cout << "8. Search for an Element (search)\n";
        cout << "9. Display/Traverse List\n";
        cout << "10. Determine List Size\n";
        cout << "11. Sort List (Ascending)\n";
        cout << "12. Reverse List\n";
        cout << "13. Exit Program\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-13): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter integer value to insert: ";
            cin >> data;
            insert_begin(head, data);
            break;
        case 2:
            cout << "Enter integer value to insert: ";
            cin >> data;
            insert_end(head, data);
            break;
        case 3:
            cout << "Enter integer value to insert: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            insert_at(head, data, position);
            break;
        case 4:
            delete_begin(head);
            break;
        case 5:
            delete_end(head);
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            delete_at(head, position);
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> data;
            delete_data(head, data);
            break;
        case 8:
        {
            cout << "Enter value to search: ";
            cin >> data;
            Node *result = search_data(head, data);
            if (result != NULL)
                cout << "Element found at address: " << result << "\n";
            else
                cout << "Element not found.\n";
            break;
        }
        case 9:
            display_list(head);
            break;
        case 10:
            cout << "Current number of nodes: " << get_size(head) << "\n";
            break;
        case 11:
            sort_list(head);
            break;
        case 12:
            reverse_list(head);
            break;
        case 13:
            // CRITICAL REQUIREMENT MET: Safely delete the complete list on exit
            clear_list(head);
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid selection!\n";
        }
    }
}

// --- Dynamic Boxed Printing ---
void display_list(Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *temp = head;

    temp = head;
    while (temp != NULL)
    {
        cout << "(" << temp->data << ")";
        if (temp->next != NULL)
        {
            cout << "-->";
        }
        else
        {
            cout << "-->NULL"; // Ending pointer
        }
        temp = temp->next;
    }
    cout << "\n";
}

// --- Wipes the Complete List from Memory ---
void clear_list(Node *&head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        // Explicitly deletes the node to prevent leaks
        delete current;
        current = nextNode;
    }
    head = NULL; // Reset local head pointer back to safe state
}

// --- Rest of Operations ---
void insert_begin(Node *&head, int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

void insert_end(Node *&head, int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insert_at(Node *&head, int d, int p)
{
    if (p < 1)
        return;
    if (p == 1)
    {
        insert_begin(head, d);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_begin(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void delete_end(Node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void delete_at(Node *&head, int p)
{
    if (head == NULL || p < 1)
        return;
    if (p == 1)
    {
        delete_begin(head);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete; //[cite: 36]
}

void delete_data(Node *&head, int d)
{
    if (head == NULL)
        return;
    if (head->data == d)
    {
        delete_begin(head);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != d)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete; //[cite: 36]
}

Node *search_data(Node *head, int d)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == d)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int get_size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void sort_list(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    bool swapped;
    Node *ptr1;
    Node *lptr = NULL;
    do
    {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int tempVal = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempVal;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void reverse_list(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}