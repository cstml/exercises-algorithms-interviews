#include <vector>
#include <iostream>
#include <fstream>

struct Node
{
    Node* r;
    Node* l;
    int value;
};

class RandomizedSet {
public:
    Node*firstN;
    Node*lastN;
    int count;
    int value;

/** Initialize your data structure here. */
    RandomizedSet() 
    {
        count = 0;
        firstN = new Node;
        lastN  = new Node;
        firstN  -> value = 0;
        lastN   -> value = 0;
        firstN  ->r = lastN;
        lastN   ->l = firstN;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        Node* current;
        current = firstN;

        while (current != lastN)
        {
            if (current->value > val)
            {
                AddNode (current,val);
                return true;
            }

            else if (current->value==val)
                return false;

            current = current->r;
        }
        AddNode(lastN->l,val);
        return true;
    }

    void AddNode(Node* move, int val)
    {
        Node* addingNode = new Node;    //

        addingNode->r = move->r;        //
        addingNode->l = move;           //

        addingNode->value = val;        //

        addingNode->r->l = addingNode;  //node in front 
        move->r=addingNode;             //

        count++;
        std::cout<<"Added a node \n";
    }

    void NodeRemove(Node* move)
    {
        Node* addingNode = new Node;    //

        addingNode->r = move->r;        //
        addingNode->l = move;           //

        addingNode->r->l = addingNode;  //node in front 
        move->r=addingNode;             //

        count--;
        std::cout<<"Remove a node \n";
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        Node* current=firstN;
        while (current!=lastN)
        {
            if (current->value == val)
            {
                NodeRemove(current);
                return true;
            }
            if (current-> value == val)
                return false;
            current=current->r;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() 
    {
        int order=rand();
        order %= count+1;

        Node* current=firstN;

        if (count == 1)
            return current->r->value;

        while (order)
        {
            current=current->r;
            order--;
        }
        return current->value;
    }

};


int main()
{
    //Your RandomizedSet object will be instantiated and called as such:
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(3);
    param_1 = obj->insert(4);
    std::cout<<param_1<<" "<<obj->count<<"\n";
    bool param_2 = obj->remove(2);
    std::cout<<param_2<<" "<<obj->count<<"\n";
    int param_3 = obj->getRandom();
    std::cout<<param_3<<" "<<obj->count<<"\n";
}
