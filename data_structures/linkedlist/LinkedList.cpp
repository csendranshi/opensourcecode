#include <bits/stdc++.h>
#include "node.h"
using namespace std;

// 0-based linkedlist
class LinkedList
{
private:
    void insert_end(int val)
    {
        if (!head)
        {
            head = new Node(val);
            return;
        }

        Node *itr = head;
        while (itr->next)
            itr = itr->next;
        itr->next = new Node(val);
    }

    void insert_front(int val)
    {
        if (!head)
        {
            head = new Node(val);
            return;
        }
        head = new Node(val, head);
    }

public:
    Node *head;
    int nodeCount;

    LinkedList()
    {
        head = nullptr;
        nodeCount = 0;
    }

    // inserts value at specified position
    // positions are zero based
    void insert_at(int position, int val)
    {
        try
        {
            if (position > nodeCount)
                throw "Position out of range";

            if (position == nodeCount)
                insert_end(val);
            else if (position == 0)
                insert_front(val);
            else
            {
                Node *itr = head;
                while (--position)
                    itr = itr->next;
                itr->next = new Node(val, itr->next);
            }
            nodeCount++;
        }
        catch (const char *exp)
        {
            cout << exp << endl;
        }
    }

    // inserts value at end of linked list
    void insert(int val)
    {
        insert_end(val);
        nodeCount++;
    }

    // delete first occurence of val
    void delete_value(int val)
    {
        if (!head)
            return;

        if (head->value == val)
        {
            Node *toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
        }
        else
        {
            Node *itr = head;
            while (itr->next->value != val && itr->next->next)
                itr = itr->next;
            Node *toBeDeleted = itr->next;
            itr->next = itr->next->next;
            delete toBeDeleted;
        }
        nodeCount--;
    }

    // delete duplicates
    void delete_duplicates()
    {
        unordered_set<int> loookupHash{head->value};
        Node *itr = head;

        while (itr->next)
        {
            if (loookupHash.find(itr->next->value) != loookupHash.end())
            {
                Node *toBeDeleted = itr->next;
                itr->next = itr->next->next;
                delete toBeDeleted;
                nodeCount--;
            }
            else
            {
                loookupHash.insert(itr->next->value);
                itr = itr->next;
            }
        }
    }

    // returns kth from last node
    Node *get_kth_to_last(int k)
    {
        Node *left = head;
        int kCopy = k;
        try
        {
            if (k > nodeCount)
                throw "Requested Position k is out of linkedlist range";
            Node *right = head;
            while (k--)
                right = right->next;
            while (right && right->next)
            {
                right = right->next;
                left = left->next;
            }
            cout << kCopy << "th from last is: " << left->value << endl;
        }
        catch (const char *exp)
        {
            cout << exp << endl;
        }
        return left;
    }

    // deletes middle node
    // for odd sized list: n/2+1 element removed
    // for even sized list: n/2 element removed
    void delete_middle_node()
    {
        try
        {
            if (!head || !head->next || !head->next->next)
                throw "No middle element";
            Node *left = head;
            Node *right = head;
            Node *prevLeft = nullptr;
            while (right->next)
                if (right->next->next)
                {
                    right = right->next->next;
                    prevLeft = left;
                    left = left->next;
                }
                else
                {
                    break;
                }
            prevLeft->next = left->next;
            delete left;
            nodeCount--;
        }
        catch (const char *exp)
        {
            cout << exp << endl;
        }
    }

    // partitions linkedlist
    // brings all values less than argument ahead of argument
    void partition_list(int val)
    {
        Node *left = head;

        while (left && left->next->value < val)
            left = left->next;

        Node *prevRight = left;
        Node *right = left->next;

        while (right)
        {
            if (right->value < val)
            {
                prevRight->next = right->next;
                if (left->value < val)
                {
                    right->next = left->next;
                    left->next = right;
                    left = right;
                }
                else
                {
                    right->next = left;
                    if (left == head)
                    {
                        head = right;
                    }
                    left = right;
                }
                right = prevRight->next;
            }
            else
            {
                right = right->next;
                prevRight = prevRight->next;
            }
        }
    }

    static LinkedList add(LinkedList num1, LinkedList num2)
    {
        Node *n1 = num1.head;
        Node *n2 = num2.head;
        int result = 0, level = 0;
        while (n1 && n2)
        {
            result += (n1->value + n2->value) * (int)pow(10.0, level++);
            n1 = n1->next;
            n2 = n2->next;
        }

        while (n1)
        {
            result += (n1->value * (int)pow(10.0, level++));
            n1 = n1->next;
        }

        while (n2)
        {
            result += (n2->value * (int)pow(10.0, level++));
            n2 = n2->next;
        }

        cout << result << endl;

        LinkedList summation;

        while (result)
        {
            summation.insert(result % 10);
            result /= 10;
        }
        return summation;
    }

    static LinkedList addL(LinkedList num1, LinkedList num2)
    {
        Node *n1 = num1.head;
        Node *n2 = num2.head;
        int val, carryforward = 0;
        LinkedList result;

        while (n1 && n2)
        {
            val = (n1->value + n2->value) + carryforward;

            result.insert(val % 10);
            carryforward = val / 10;

            n1 = n1->next;
            n2 = n2->next;
        }

        while (n1)
        {
            val = n1->value + carryforward;
            result.insert(val % 10);
            carryforward = val / 10;
            n1 = n1->next;
        }

        while (n2)
        {
            val = n2->value + carryforward;
            result.insert(val % 10);
            carryforward = val / 10;
            n2 = n2->next;
        }

        while (carryforward)
        {
            result.insert(carryforward % 10);
            carryforward /= 10;
        }

        return result;
    }

    // is palindrome
    bool isPalindromeStack()
    {
        if (!head || !head->next)
            return true;

        stack<int> stack;
        Node *left = head;
        Node *right = head;

        while (right && right->next)
        {
            stack.push(left->value);
            left = left->next;
            right = right->next->next;
        }

        if (right)
            left = left->next;

        while (left)
        {
            int top = stack.top();
            if (top != left->value)
                return false;
            left = left->next;
            stack.pop();
        }

        return true;
    }

    struct Palindrome
    {
        bool result;
        Node *node;
    };

    bool isPalindromeRecursive()
    {
        Palindrome res = isPalindromeRecursiveFunction(head, nodeCount);
        return res.result;
    }

    Palindrome isPalindromeRecursiveFunction(Node *node, int length)
    {
        if (!node || length <= 0)
        {
            Palindrome res;
            res.result = true;
            res.node = node;
            return res;
        }
        else if (length == 1)
        {
            Palindrome res;
            res.result = true;
            res.node = node->next;
            return res;
        }

        Palindrome res = isPalindromeRecursiveFunction(node->next, length - 2);

        if (!res.result || !res.node)
            return res;

        res.result = (res.node->value == node->value);
        res.node = res.node->next;
        return res;
    }

    // find intersection point
    static Node *intersectionNode(LinkedList l1, LinkedList l2)
    {
        Node *h1 = l1.head;
        Node *h2 = l2.head;

        if (l1.nodeCount > l2.nodeCount)
        {
            for (int i = 0; i < l1.nodeCount - l2.nodeCount; i++)
                h1 = h1->next;
        }
        else if (l1.nodeCount < l2.nodeCount)
        {
            for (int i = 0; i < l2.nodeCount - l1.nodeCount; i++)
                h2 = h2->next;
        }

        while (h1 && h2)
        {
            if (h1 == h2)
                return h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        return nullptr;
    }

    Node *isLoop()
    {
        Node *left = head;
        Node *right = head;

        while (right && right->next)
        {
            if (right == left)
                break;
            right = right->next->next;
            left = left->next;
        }
        if (!right || !right->next)
            return nullptr;

        left = head;
        while (left != right)
        {
            left = left->next;
            right = right->next;
        }
        return right;
    }

    // display nodes from head to end
    void display()
    {
        Node *itr = head;
        while (itr)
        {
            cout << itr->value << "->";
            itr = itr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList llist;

    llist.insert(5);
    llist.display();
    llist.insert_at(1, 6);
    llist.display();
    llist.insert_at(2, 8);
    llist.display();
    llist.insert_at(2, 7);
    llist.display();
    llist.insert_at(5, 10);
    llist.display();
    llist.insert_at(4, 5);
    llist.display();
    llist.insert_at(0, 7);
    llist.display();
    llist.insert_at(4, 6);
    llist.display();

    llist.delete_value(6);
    llist.display();
    llist.delete_value(7);
    llist.display();

    llist.insert(7);
    llist.insert_at(3, 7);
    llist.insert(6);
    llist.insert(8);
    llist.display();
    llist.insert(9);
    llist.display();

    llist.delete_duplicates();
    llist.display();

    llist.get_kth_to_last(1);
    llist.get_kth_to_last(3);
    llist.get_kth_to_last(10);
    llist.get_kth_to_last(5);

    llist.delete_middle_node();
    llist.display();
    llist.delete_middle_node();
    llist.display();
    llist.delete_middle_node();
    llist.display();
    llist.delete_middle_node();
    llist.display();
    llist.delete_value(9);
    llist.delete_value(5);

    llist.insert(8);
    llist.insert(5);
    llist.insert(4);
    llist.insert(8);
    llist.insert(5);
    llist.insert(10);
    llist.insert(2);
    llist.insert(1);
    llist.display();

    llist.partition_list(5);
    llist.display();

    LinkedList num1, num2;

    num1.insert(8);
    num1.insert(1);
    num1.insert(6);

    num2.insert(2);
    num2.insert(8);
    num2.insert(9);
    num2.insert(1);

    LinkedList result = LinkedList::addL(num1, num2);
    result.display();

    cout << "llist is Palindrome: " << llist.isPalindromeStack() << endl;

    LinkedList pali;
    pali.insert(1);
    pali.display();
    cout << "Pali is Palindrome: " << pali.isPalindromeRecursive() << endl;
    pali.insert(2);
    pali.display();
    cout << "Pali is Palindrome: " << pali.isPalindromeRecursive() << endl;
    pali.insert(1);
    pali.display();
    cout << "Pali is Palindrome: " << pali.isPalindromeRecursive() << endl;
    pali.insert(2);
    pali.display();
    cout << "Pali is Palindrome: " << pali.isPalindromeRecursive() << endl;
    pali.insert(1);
    pali.display();
    cout << "Pali is Palindrome: " << pali.isPalindromeRecursive() << endl;
}