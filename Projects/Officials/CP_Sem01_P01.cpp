#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// --- Node Structure ---
struct Node {
    int data;
    Node* next;
};

// --- Function Prototypes ---
void insert_begin(Node*& head, int d);
void insert_end(Node*& head, int d);
void insert_at(Node*& head, int d, int p);
void delete_begin(Node*& head);
void delete_end(Node*& head);
void delete_at(Node*& head, int p);
void delete_data(Node*& head, int d);
void display_list(Node* head);
void search_data(Node* head, int d); 
void count_duplicates(Node* head, int x);     
void reverse_list(Node*& head);
void sort_list(Node* head);
int get_size(Node* head);
void clear_list(Node*& head); 
void show_memory_usage(Node* head);

// --- Menu Functions ---
void show_grid_menu();
int parse_menu_selection(string input);

int main() {
    Node* head = NULL; 
    string selection;
    int data, position;

    while (true) {
        show_grid_menu();
        cout << "Enter selection code: ";
        cin >> selection;

        int mapped_choice = parse_menu_selection(selection);

        if (mapped_choice == 15) { 
            clear_list(head);
            cout << "\nMemory cleared. Exiting program.\n";
            return 0;
        }

        switch (mapped_choice) {
            // --- GROUP 1: INSERTIONS ---
            case 1: 
                cout << "Enter integer value to insert at beginning: "; cin >> data;
                insert_begin(head, data);
                break;
            case 2: 
                cout << "Enter integer value to insert at end: "; cin >> data;
                insert_end(head, data);
                break;
            case 3: 
                cout << "Enter integer value to insert: "; cin >> data;
                cout << "Enter position (1-based index): "; cin >> position;
                insert_at(head, data, position);
                break;

            // --- GROUP 2: DELETIONS ---
            case 4: 
                delete_begin(head);
                cout << "Deleted from beginning.\n";
                break;
            case 5: 
                delete_end(head);
                cout << "Deleted from end.\n";
                break;
            case 6: 
                cout << "Enter position to delete (1-based index): "; cin >> position;
                delete_at(head, position);
                break;
            case 7: 
                cout << "Enter value to delete: "; cin >> data;
                delete_data(head, data);
                break;

            // --- GROUP 3: SEARCH & UTILITIES ---
            case 8: 
                cout << "Enter value to search: "; cin >> data;
                search_data(head, data);
                break;
            case 9: 
                cout << "Enter value to check for duplicates: "; cin >> data;
                count_duplicates(head, data);
                break;
            case 10: 
                cout << "Current number of nodes: " << get_size(head) << "\n";
                break;

            // --- GROUP 4: TRANSFORMATIONS ---
            case 11: 
                sort_list(head);
                cout << "List sorted in ascending order.\n";
                break;
            case 12: 
                reverse_list(head);
                cout << "List successfully flipped/reversed.\n";
                break;

            // --- GROUP 5: SYSTEM & VIEW ---
            case 13: 
                display_list(head);
                break;
            case 14: 
                show_memory_usage(head);
                break;
            case 16: 
                clear_list(head);
                break;

            default:
                cout << "\n[!] Invalid Selection code. Please try again.\n";
        }
    }
}

// --- Menu UI & Logic Mapping ---
void show_grid_menu() {
    cout << "\n=========================================================================\n";
    cout << "                    LINKED LIST CONTROLLER                                 \n";
    cout << "=========================================================================\n";
    cout << " [1] INSERTIONS         [2] DELETIONS            [3] SEARCH & UTILS      \n";
    cout << " ------------------     ------------------       ------------------      \n";
    cout << "  1A. At Beginning       2A. From Beginning       3A. Enhanced Search     \n";
    cout << "  1B. At End             2B. From End             3B. Check Duplicates    \n";
    cout << "  1C. At Position (n)    2C. From Position (n)    3C. Size Counter        \n";
    cout << "                         2D. By Value Instance                            \n";
    cout << " ------------------------------------------------------------------------\n";
    cout << " [4] Sorting            [5] SYSTEM OPERATIONS                             \n";
    cout << " ------------------     ------------------                               \n";
    cout << "  4A. Sort (Ascending)   5A. Print/Display List                           \n";
    cout << "  4B. Flip/Reverse List  5B. Check RAM Usage                              \n";
    cout << "                         5C. Wipe/Clear List                              \n";
    cout << "                         5D. Quit Program                                 \n";
    cout << "=========================================================================\n";
}

int parse_menu_selection(string input) {
    // Loop through like a normal person and use the character toupper
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = toupper(input[i]);
    }

    if (input == "1A") return 1;
    if (input == "1B") return 2;
    if (input == "1C") return 3;
    if (input == "2A") return 4;
    if (input == "2B") return 5;
    if (input == "2C") return 6;
    if (input == "2D") return 7;
    if (input == "3A") return 8;
    if (input == "3B") return 9;
    if (input == "3C") return 10;
    if (input == "4A") return 11;
    if (input == "4B") return 12;
    if (input == "5A") return 13;
    if (input == "5B") return 14;
    if (input == "5C") return 16;
    if (input == "5D") return 15; 
    
    return -1; 
}

// --- Dynamic Boxed Printing ---
void display_list(Node* head) {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << "(" << temp->data << ")";
        if (temp->next != NULL) {
            cout << "-->";
        } else {
            cout << "-->NULL";
        }
        temp = temp->next;
    }
    cout << "\n";
}

// --- Complete Structural Memory Clear ---
void clear_list(Node*& head) {
    if (head == NULL) {
        cout << "List is already empty.\n";
        return;
    }
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        delete current; 
        current = nextNode;
    }
    head = NULL; 
    cout << "List completely wiped out of RAM.\n";
}

// --- Insertion Mechanics ---
void insert_begin(Node*& head, int d) {
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

void insert_end(Node*& head, int d) {
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insert_at(Node*& head, int d, int p) {
    if (p < 1) return;
    if (p == 1) {
        insert_begin(head, d);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid slot position layout.\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = temp->next;
    temp->next = newNode;
}

// --- Deletion Mechanics ---
void delete_begin(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_end(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void delete_at(Node*& head, int p) {
    if (head == NULL || p < 1) return;
    if (p == 1) {
        delete_begin(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        cout << "Target node position boundaries out of index scope.\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void delete_data(Node*& head, int d) {
    if (head == NULL) return;
    if (head->data == d) {
        delete_begin(head);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != d)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Target item value element not found within structure context.\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// --- Searching Operations ---
void search_data(Node* head, int d) {
    Node* temp = head;
    int index = 0;
    int totalMatches = 0;
    
    while (temp != NULL) {
        if (temp->data == d) {
            cout << "Found at " << temp << " | " << index << " index\n";
            totalMatches++;
        }
        temp = temp->next;
        index++;
    }
    
    if (totalMatches == 0) {
        cout << "Element not found.\n";
    } else {
        cout << "Total instances discovered: " << totalMatches << "\n";
    }
}

// --- Duplicate Counter ---
void count_duplicates(Node* head, int x) {
    Node* temp = head;
    int occurrenceCount = 0;
    
    while (temp != NULL) {
        if (temp->data == x) {
            occurrenceCount++;
        }
        temp = temp->next;
    }
    
    cout << "Value " << x << " matches found inside collection: " << occurrenceCount << " duplicates.\n";
}

// --- Helper Utilities ---
int get_size(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// --- Transforming & Sorting Operations ---
void sort_list(Node* head) {
    if (head == NULL || head->next == NULL) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
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

void reverse_list(Node*& head) {
    if (head == NULL || head->next == NULL) return;
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

// --- RAM Profiler/Estimator ---
void show_memory_usage(Node* head) {
    int total_nodes = get_size(head);
    size_t node_size = sizeof(Node);
    size_t total_bytes = total_nodes * node_size;
    size_t total_bits = total_bytes * 8;
    
    cout << "\n=== RAM MEMORY ALLOCATION ESTIMATOR ===\n";
    cout << "Size of single structural Node : " << node_size << " bytes\n";
    cout << " -> Dynamic components: [int payload: " << sizeof(int) << " bytes] + [Pointer context: " << sizeof(Node*) << " bytes]\n";
    cout << "Total Active Nodes in system   : " << total_nodes << "\n";
    cout << "Aggregated Memory Occupied    : " << total_bytes << " bytes (" << total_bits << " bits)\n";
    cout << "=======================================\n";
}