#include <iostream>
using namespace std;

class Node
{
public:
    string key;
    int data;
    Node *next;

    Node(string key, int data)
    {
        this->data = data;
        this->key = key;
        next = nullptr;
    }
};

class HashTable
{
    static const int size = 7;
    Node *dataMap[size];

    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % 7;
        }
        return hash;
    }

public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            dataMap[i] = nullptr;
        }
    }

    void PrintHashTable()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";
            Node *temp = dataMap[i];
            while (temp)
            {
                cout << "[" << temp->key << ", " << temp->data << "] ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void set(string key, int data)
    {
        int index = hash(key);
        Node *newNode = new Node(key, data);
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key)
    {
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp)
        {
            if (temp->key == key)
                return temp->data;
            temp = temp->next;
        }
        return 0; // Return 0 if key not found
    }

    void deleteHash(string key)
    {
        int index = hash(key);
        Node *temp = dataMap[index];
        Node *prev = nullptr;

        while (temp)
        {
            if (temp->key == key)
            {
                if (prev == nullptr)
                {
                    dataMap[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Key '" << key << "' deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key '" << key << "' not found." << endl;
    }
};

int main()
{
    HashTable *hashTable = new HashTable();
    hashTable->set("apple", 5);
    hashTable->set("mango", 10);
    hashTable->set("onion", 70);
    hashTable->set("tomato", 90);

    cout << "Before deletion:" << endl;
    hashTable->PrintHashTable();

    hashTable->deleteHash("mango");
    hashTable->deleteHash("onion");

    cout << "\nAfter deletion:" << endl;
    hashTable->PrintHashTable();

    delete hashTable;
    return 0;
}
