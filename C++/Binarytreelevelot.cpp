#include<iostream>
using namespace std;

struct Btnode
{
    int data;
    struct Btnode* left;
    struct Btnode* right;

    Btnode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

};

typedef struct Btnode Btnode;

class Bintree{
    private:
        Btnode *root;
    public:
        void root_initialize(int val);
        
};

void Bintree::root_initialize(int val)
{
    Btnode 
}

int main()
{
    Bintree b1;

}