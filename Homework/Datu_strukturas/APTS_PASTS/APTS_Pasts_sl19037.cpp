// Autors: Santa Lauva
// Studentu apliecîbas nr.: sl19037
// Izstrâdes datums: 06.05.2020

#include <iostream>
#include <fstream>
using namespace std;
const int garums=255;

class Node
{
public:
    int g;
    char burts;
    char adrese[garums];
    Node* next;
    Node (char b, string a)
    {
        burts = b;
        int i=0;
        while (isalpha(a[i]))
        {
            adrese[i] = a[i];
            i++;
        }
        adrese[i] = '\0';
        g=i;
        next = NULL;
    };
};

class Stack
{
    Node *top;
public:
    Stack()
    {
        top = NULL;
    };
    void push (char b, string vards)
    {

        Node *n = new Node (b, vards);

        if (isEmpty())
        {
            top = n;
            return;
        }

        Node *ptr = top;

        while (ptr != NULL && ptr->next != NULL)
        {
            if (int(n->burts) <= int(ptr->burts))
            {
                n->next = ptr;
                top=n;
                return;
            }
            else if  (((int(n->burts)) > int(ptr->burts)) && ((int(n->burts)) <= int(ptr->next->burts)))
            {
                n->next = ptr->next;
                ptr->next=n;
                return;
            }
            ptr = ptr->next;
        }

        if (ptr->next == NULL)
        {
            if (n->burts <= ptr->burts)
            {
                n->next = ptr;
                top=n;
                return;
            }
            else
            {
                ptr->next=n;
                return;
            }
        }
    };
    void pop ()
    {
        if (!isEmpty())
        {
            Node *n = top;
            top = top->next;
            delete n;
        }
    };
    bool isEmpty ()
    {
        return (top == NULL);
    };
    void print (fstream &fout)
    {
        string m = " ";
        if (!isEmpty())
        {
            Node *n = top;
            while (n != NULL)
            {
                fout.write((char*)&n->adrese, n->g);
                if (n->next != NULL) fout << " ";
                n=n->next;
            }
        }
    };
};

int main()
{
    fstream fin;
    fstream fout;
    string vards; // Atrastais kârtçjais vârds
    Stack p;
    char c;
    char k;
    char nt[8]="nothing";

    fout.open ("post.out", ios::out|ios::binary);
    fin.open("post.in", ios::in|ios::binary);
    if (!fin){fout.write((char*)&nt, 7);}

    vards="";
    fin.read((char*)&c, sizeof(char));
    while(fin)
    {
        if (isalpha(c) && (vards == ""))
        {
            vards+=c;
            k=c;
            if (int(k) >= 65 && int(k) <= 90) k=char(int(k) + 32);
        }
        else if (isalpha(c))
        {
            vards+=c;
        }
        else
        {
            if (vards != "")
            {
                p.push (k, vards);
                vards="";
            }
        }
        fin.read(&c, sizeof(char));
    }

    if (p.isEmpty()) fout.write((char*)&nt, 7);

    fin.close();

    p.print(fout);

    fout.close();

    while (!p.isEmpty())
    {
        p.pop();
    }

}
