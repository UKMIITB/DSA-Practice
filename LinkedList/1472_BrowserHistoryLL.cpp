// https://leetcode.com/problems/design-browser-history/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string webpage;
    Node *next;

    Node()
    {
        this->webpage = "";
        this->next = NULL;
    }

    Node(string url)
    {
        this->webpage = url;
        this->next = NULL;
    }

    Node(string url, Node *next)
    {
        this->webpage = url;
        this->next = next;
    }
};

class BrowserHistory
{
public:
    Node *head;
    Node *current;
    int size;
    int currentSize;

public:
    BrowserHistory(string homepage)
    {
        head = new Node(homepage);
        current = head;
        size = 1;
        currentSize = 1;
    }

    void visit(string url)
    {
        // cleanup forward nodes
        Node *itr = current->next;
        while (itr != NULL)
        {
            Node *temp = itr;
            itr = itr->next;
            delete temp;
        }

        current->next = new Node(url);
        current = current->next;

        updateSize();
        updateCurrentSize();
    }

    string back(int steps)
    {
        if (steps >= (currentSize - 1)) // current will go to head
        {
            current = head;
            currentSize = 1;
        }
        else
        {
            currentSize = currentSize - steps;
            int count = 1;
            current = head;

            while (count != currentSize)
            {
                count++;
                current = current->next;
            }
        }

        return current->webpage;
    }

    string forward(int steps)
    {
        while (steps != 0)
        {
            if (current->next == NULL)
                return current->webpage;

            current = current->next;
            this->currentSize++;
            steps--;
        }

        return current->webpage;
    }

private:
    void updateSize()
    {
        Node *itr = head;
        this->size = 0;
        while (itr != NULL)
        {
            this->size++;
            itr = itr->next;
        }
    }

    void updateCurrentSize()
    {
        Node *itr = head;
        this->currentSize = 0;
        while (itr != current->next)
        {
            this->currentSize++;
            itr = itr->next;
        }
    }
};

int main()
{
    BrowserHistory *browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    browserHistory->back(1);
    browserHistory->back(1);
    browserHistory->forward(1);
    browserHistory->visit("linkedin.com");
    browserHistory->forward(2);
    browserHistory->back(2);
    browserHistory->back(7);
    return 0;
}
