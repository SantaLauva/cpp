#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    int num;
    Node* left;
    Node* right;
    Node (int s)
    {
        num = s;
        left = NULL;
        right = NULL;
    };
};

class Stack
{
    Node *top;
    Node *ptr;
public:
    Stack()
    {
        top = NULL;
        ptr = NULL;
    };

    void re (fstream &fout)
    {
        if ((top->left == NULL) && (top->right == NULL))
            fout << top->num << endl;
        else print(fout, top);
    }
    void ru ()
    {
        pop(top);
    }

    void pushRoot (int s)
    {
        Node *n = new Node(s);
        top = ptr = n;
    };

    void push (int k, int s, Node *&pt)
    {
        int a=0;
        if (pt == NULL) return;
        if (k == pt->num)
        {
            a = 1;
            Node *n = new Node (s);
            pt->left = n;
            ptr = pt;
            return;
        }
        else
        {
            if (pt->right != NULL)
            {
                if (a == 1) return;
                push(k, s, pt->right);
            }
            if (pt->left !=NULL)
            {
                if (a == 1) return;
                push(k, s, pt->left);
            }
        }

    };

    void pushFirstChild (int k, int s)
    {
        if (top->left == NULL)
        {
            Node *n = new Node(s);
            top->left = n;
            return;
        }
        ptr = top;
        push(k, s, ptr);
    };

    void pushChildren (int k, int s)
    {
        Node *n = new Node(s);
        Node *b = ptr->left;
        n->right = b;
        ptr->left = n;
    };

   void pop (Node *&ptr)
    {
        if (ptr->left != NULL)
        {
            pop(ptr->left);
        }
        if (ptr->right != NULL) pop(ptr->right);
        delete ptr;
    };

    bool isEmpty ()
    {
        return (top == NULL);
    };

void print (fstream &fout, Node *&ptr)
    {
        if (isEmpty()) return;
        if (ptr->left != NULL)
        {
            fout << ptr->num << " ";
            Node *ptr2 = ptr->left;
            while(ptr2)
            {
                fout << ptr2->num << " ";
                ptr2 = ptr2->right;
            }
            fout << endl;
            print(fout, ptr->left);
        }
        if (ptr->right != NULL)
        {
            print(fout, ptr->right);
        }
        else return;
    };
};

int main()
{
    fstream fin;
    fstream fout;
    int s, k;
    char c;
    Stack p;

    fin.open("alise.in",ios::in);
    fout.open ("alise.out", ios::out);

    fin >> s;
    if (s == 0)
    {
        fout << 0 << endl;
        fin.close();
        fout.close();
        return 0;
    }
    p.pushRoot(s);
    while ((s != 0) && !fin.eof())
    {
        k=s;
        fin.get(c);
        if (c != '\n')
        {
            fin >> s;
            p.pushFirstChild(k, s);
            while ((s != 0) && !fin.eof())
            {
                fin.get(c);
                if (c == '\n')  break;
                else
                {
                    fin >> s;
                    p.pushChildren(k, s);
                }
            }
        }
        fin >> s;
    }
    fin.close();

    p.re(fout); //print
    fout << 0;
    fout.close();

    p.ru(); // pop
    return 0;
}
