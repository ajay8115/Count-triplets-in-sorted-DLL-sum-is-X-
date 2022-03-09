// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

int countTriplets(struct Node *head, int x)
{
    struct Node *n1, *n2, *n3;
    int count = 0;

    // unordered_map 'um' implemented as hash table
    unordered_map<int, Node *> m;

    // insert the <node data, node pointer> tuple in 'um'
    for (n1 = head; n1 != NULL; n1 = n1->next)
        m[n1->data] = n1;

    // generate all possible pairs
    for (n2 = head; n2 != NULL; n2 = n2->next)
        for (n3 = n2->next; n3 != NULL; n3 = n3->next)
        {
            // p_sum - sum of elements in the current pair
            int p_sum = n2->data + n3->data;

            // if 'x-p_sum' is present in 'um' and either of the two nodes
            // are not equal to the 'um[x-p_sum]' node
            if (m.find(x - p_sum) != m.end() && m[x - p_sum] != n2 && m[x - p_sum] != n3)

                count++;
        }

    // division by 3 as each triplet is counted 3 times
    return (count / 3);
}

void insert(struct Node **head, int data)
{
    // allocate node
    struct Node *temp = new Node();

    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program to test above
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 17;

    cout << "Count = " << countTriplets(head, x);

    return 0;
}

