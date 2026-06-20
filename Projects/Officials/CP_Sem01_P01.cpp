#include <iostream>

using namespace std;

// node for the list
struct Node
{
    int data;
    Node *next; // pointer to next block
};

// --- MY FUNCTIONS ---
void display_list(Node *head);
void insert_begin(Node *&head, int d);
void insert_end(Node *&head, int d);
void insert_at(Node *&head, int d, int p);
void delete_begin(Node *&head);
void delete_end(Node *&head);
void delete_at(Node *&head, int p);
void delete_data(Node *&head, int d);
void search_data(Node *head, int d);
int get_size(Node *head);
void sort_list(Node *head);
void reverse_list(Node *&head);
void clear_list(Node *&head);
void show_memory_usage(Node *head);       // NEW FEATURE
void count_duplicates(Node *head, int x); // NEW + 1 FEATURE

int main()
{
    Node *head = NULL; // empty a the start
    int choice, data, position;

    while (true)
    {
        cout << "\nLinked List System\n\n";
        cout << "1. insert at start\n";
        cout << "2. insert at end\n";
        cout << "3. insert at n position\n";
        cout << "4. delete from start\n";
        cout << "5. delete from end\n";
        cout << "6. delete from n position\n";
        cout << "7. delete by data\n";
        cout << "8. Search by data\n";
        cout << "9. Print list!\n";
        cout << "10. Node Count\n";
        cout << "11. Sort (ASC)\n";
        cout << "12. Flip list\n";
        cout << "13. delete all\n";              // clear option
        cout << "14. Check RAM usage (bytes)\n"; // memory usage option
        cout << "15. Check Duplicate\n";         // memory usage option
        cout << "16. quit program\n";
        cin >> choice;

        if (choice == 16)
        {
            clear_list(head); // clean up memory
            cout << "prog end\n";
            return 0;
        }

        switch (choice)
        {
        case 1:
            cout << "enter data : ";
            cin >> data;
            insert_begin(head, data);
            break;
        case 2:
            cout << "enter data : ";
            cin >> data;
            insert_end(head, data);
            break;
        case 3:
            cout << "enter data : ";
            cin >> data;
            cout << "What slot? ";
            cin >> position;
            if (position <= (get_size(head) + 1))
            {
                insert_at(head, data, position);
            }
            else
            {
                cout << "Invalid slot" << endl;
            }
            break;
        case 4:
            delete_begin(head);
            break;
        case 5:
            delete_end(head);
            break;
        case 6:
            cout << "node to delete : ";
            cin >> position;
            if (position <= (get_size(head) + 1))
            {
                delete_at(head, position);
            }
            else
            {
                cout << "Invalid node" << endl;
            }
            break;
        case 7:
            cout << "data to delete :";
            cin >> data;
            delete_data(head, data);
            break;
        case 8:
        {
            cout << "Enter value to search: ";
            cin >> data;
            search_data(head, data);
            break;
        }
        case 9:
            display_list(head);
            break;
        case 10:
            cout << "Total nodes : " << get_size(head) << "\n";
            break;
        case 11:
            sort_list(head);
            break;
        case 12:
            reverse_list(head);
            cout << "Flipped\n";
            break;
        case 13:
            clear_list(head);
            break;
        case 14:
            show_memory_usage(head);
            break;
        case 15:
            cout << "Duplicate check for: ";
            cin >> data;
            count_duplicates(head, data);
            break;
        default:
            cout << "Invalid..\n";
        }
    }
}

// prints everything with cool arrows
void display_list(Node *head)
{
    if (head == NULL)
    {
        cout << "list is empty.\n";
        return;
    }
    Node *temp2 = head; // named it temp2 because why not
    while (temp2 != NULL)
    {
        cout << "(" << temp2->data << ")";
        if (temp2->next != NULL)
        {
            cout << "-->";
        }
        else
        {
            cout << "-->NULL";
        }
        temp2 = temp2->next;
    }
    cout << "\n";
}

// wipes the whole thing out
void clear_list(Node *&head)
{
    if (head == NULL)
    {
        cout << "list is already empty.\n";
        return;
    }
    Node *current = head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        delete current; // Begone!
        current = nextNode;
    }
    head = NULL; // reset it or everything goes boom
    cout << "list deleted.\n";
}

void insert_begin(Node *&head, int d)
{
    Node *n = new Node(); // made a new one
    n->data = d;
    n->next = head;
    head = n;
}

void insert_end(Node *&head, int d)
{
    Node *n = new Node();
    n->data = d;
    n->next = NULL;
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = n;
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
    Node *t = head;
    for (int i = 1; i < p - 1 && t != NULL; i++)
    {
        t = t->next;
    }
    if (t == NULL)
        return; // position out of bounds, generic exit
    Node *n = new Node();
    n->data = d;
    n->next = t->next;
    t->next = n;
}

void delete_begin(Node *&head)
{
    if (head == NULL)
        return;
    Node *t = head;
    head = head->next;
    delete t;
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
    Node *t = head;
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    delete t->next;
    t->next = NULL;
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
    Node *t = head;
    for (int i = 1; i < p - 1 && t != NULL; i++)
    {
        t = t->next;
    }
    if (t == NULL || t->next == NULL)
        return;
    Node *killMe = t->next;
    t->next = t->next->next;
    delete killMe;
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
    Node *t = head;
    while (t->next != NULL && t->next->data != d)
    {
        t = t->next;
    }
    if (t->next == NULL)
        cout << d << ": Not found.";
        return;
    Node *killMe = t->next;
    t->next = t->next->next;
    delete killMe;
}

void search_data(Node *head, int d)
{
    Node *temp = head;
    int index = 1;
    int totalMatches = 0;

    while (temp != NULL)
    {
        if (temp->data == d)
        {
            cout << "Found at " << temp << " | " << index << " index\n";
            totalMatches++;
        }
        temp = temp->next;
        index++;
    }

    if (totalMatches == 0)
    {
        cout << "Element not found.\n";
    }
    else
    {
        cout << "Total instances discovered: " << totalMatches << "\n";
    }
}

int get_size(Node *head)
{
    int count = 0;
    Node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

// sort bubble
void sort_list(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    bool swapped;
    Node *p1;
    Node *last = NULL;
    do
    {
        swapped = false;
        p1 = head;
        while (p1->next != last)
        {
            if (p1->data > p1->next->data)
            {
                int fallback = p1->data;
                p1->data = p1->next->data;
                p1->next->data = fallback;
                swapped = true;
            }
            p1 = p1->next;
        }
        last = p1;
    } while (swapped);
    cout << "List sorted.\n";
}

// flipping
void reverse_list(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *logicPrev = NULL;
    Node *logicCurrent = head;
    Node *logicNext = NULL;
    while (logicCurrent != NULL)
    {
        logicNext = logicCurrent->next;
        logicCurrent->next = logicPrev;
        logicPrev = logicCurrent;
        logicCurrent = logicNext;
    }
    head = logicPrev;
}

// --- NEW FEATURES ---
void show_memory_usage(Node *head)
{
    int total_nodes = get_size(head);
    // scale up calculations for sizes
    size_t node_size = sizeof(Node);
    size_t total_bytes = total_nodes * node_size;
    size_t total_bits = total_bytes * 8;

    // cout << "Size of single Node: " << node_size << " bytes\n";
    // cout << " -> (int data takes " << sizeof(int) << " bytes + Node* next pointer takes " << sizeof(Node*) << " bytes)\n";
    // cout << "Total Nodes inside list: " << total_nodes << "\n";
    cout << "Total space in RAM: " << total_bytes << " bytes (" << total_bits << " bits!)\n";
}

void count_duplicates(Node *head, int x)
{
    Node *temp = head;
    int occurrenceCount = 0;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            occurrenceCount++;
        }
        temp = temp->next;
    }

    cout << "Value " << x << " found " << occurrenceCount << " times in the list.\n";
}