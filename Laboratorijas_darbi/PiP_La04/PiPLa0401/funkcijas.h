struct Node
{
    int num;
    Node *next;
};
void pievienot(Node* &first, Node* &last, int elem);
bool atrast(Node* first, int sk);
