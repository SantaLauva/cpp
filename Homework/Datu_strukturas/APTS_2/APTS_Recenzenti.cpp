#include <iostream>
#include <fstream>
using namespace std;


class Node
{
public:
	string name;
	int pseudonymCount;
	Node* next;

	Node(string s)
	{
		name = s;
		pseudonymCount = 0;
		next = NULL;
	}
};

class BinaryNode
{
public:
	int pseudonym;
	//Node* reviewer;
	string reviewer;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int ps, string rev)//Node* rev)
	{
		pseudonym = ps;
		reviewer = rev;
		left = NULL;
		right = NULL;
	}
};

class ReviewersList
{
public:
	Node* first;
	Node* last;
	Node* ptrReviewer;

	ReviewersList()
	{
		first = last = NULL;
		ptrReviewer = NULL;
	}

	void insertName(string s)
	{
		Node* ptr = first; // Iterators
		ptrReviewer = NULL;
		while (ptr != NULL)
		{
			if (ptr->name == s)
			{
				ptrReviewer = ptr;
				return;
			}
			else ptr = ptr->next;
		}

		if (isEmpty())
		{
			Node* n = new Node(s);
			first = n;
			last = n;
			ptrReviewer = n;
		}

		if (ptrReviewer == NULL) // Ja neatrada sarakstâ recenzentu, tad pievieno
		{
			Node* n = new Node(s);
			last->next = n;
			last = n;
			ptrReviewer = n;
		}
	}

	bool isEmpty()
	{
		return (first == NULL);
	};
};


class PseudonymsBinaryTree
{
	BinaryNode* root;

public:
	BinaryNode* ptrPseudonym;
	bool pseudonymAlreadyExists; // Mainigais, kas saglaba vai pseidonims eksiste jau citam recenzentam

	PseudonymsBinaryTree()
	{
		root = ptrPseudonym = NULL;
	}

	void insertPseudonym(int ps, string reviewer)
	{
			pseudonymAlreadyExists = false;
			BinaryNode* ptr = root; // Iterators
			while (ptr != NULL)
			{
				if (ps < ptr->pseudonym)
				{
					if (ptr->left == NULL)
					{
						BinaryNode* n = new BinaryNode(ps, reviewer);
						ptr->left = n;
						return;
					}
					ptr = ptr->left;
				}
				if (ps > ptr->pseudonym)
				{
					if (ptr->right == NULL)
					{
						BinaryNode* n = new BinaryNode(ps, reviewer);
						ptr->right = n;
						return;
					}
					ptr = ptr->right;
				}
				if (ptr->pseudonym == ps)
				{
					if (ptr->reviewer == reviewer) return;
					else if (ptr->reviewer == "")
                    {
                        ptr->reviewer = reviewer;
                    }
                    else // Pseidonims jau eksiste, bet citam recenzentam
					{
						pseudonymAlreadyExists = true;
						return;
					}
				}
			}

			if (root == NULL) // Ja binârais koks ir tukðs
			{
				BinaryNode* n = new BinaryNode(ps, reviewer);
				root = n;
			}
	}

	void searchPseudonym(int ps)
	{
		BinaryNode* ptr = root; // Iterators
		ptrPseudonym = NULL;  // Atjauno vçrtîbu uz null
		while (ptr != NULL)
		{
			if (ptr->pseudonym == ps)
			{
				if (ptr->reviewer == "") return;
				else
				{
					ptrPseudonym = ptr;
					return;
				}
			}
			if (ps < ptr->pseudonym)
            {
                if (ptr->left == NULL) return;
                ptr = ptr->left;
            }
			if (ps > ptr->pseudonym)
            {
                if (ptr->right == NULL) return;
                ptr = ptr->right;
            }


		}
	}

	void deleteReviewer(string reviewer)
	{
		BinaryNode* ptr = root; //Iterators
		deletePseudonyms(ptr, reviewer);
	}

	void deletePseudonyms(BinaryNode* ptr, string reviewer)
	{
		if (ptr == NULL) return;

		if (ptr->reviewer == reviewer) ptr->reviewer = "";

		deletePseudonyms(ptr->left, reviewer);

		deletePseudonyms(ptr->right, reviewer);
	}

	bool isEmpty()
	{
		return (root == NULL);
	}
};


int main()
{
	ifstream fin;
	fstream fout;

	char c;
	string name = "";
	int pseudonymCount;
	int readedInt;

	ReviewersList reviewers;
	PseudonymsBinaryTree pseudonyms;

	fout.open("reviewers.out", ios::out);
	fin.open("reviewers.in", ios::in);

	fin.read((char*)&c, sizeof(char));
	while (fin)
	{
		name="";
		if (c == 'I')
		{
			fin.read(&c, sizeof(char)); // Nolasa atstarpi starp I un name
			fin.read(&c, sizeof(char));
			while (fin)
			{
				if (c == ' ') break;
				name += c;  // Nav jçgas pârbaudît simbolus, par cik dotie dati ir atbilstoði
				fin.read(&c, sizeof(char));
			}

			fin >> pseudonymCount;
			if (pseudonymCount < 51)
			{
				fin >> readedInt;
				while (fin)
				{
					pseudonyms.insertPseudonym(readedInt, name);

					fin.read((char*)&c, sizeof(char));
					if (c == '\n') break;

					fin >> readedInt;
				}

				if (pseudonyms.pseudonymAlreadyExists == true)
                {
                    pseudonyms.deleteReviewer(name);
                    fout << "no";
                    continue;
                }
			}
			else fout << "no";

			reviewers.insertName(name);
			fout << "ok";
			fin.read(&c, sizeof(char)); // Lai lasîtu tâlâk nâkoðo rindu
		}
		else
		{
			if (c == 'D')
			{
				fin.read(&c, sizeof(char)); // Nolasa atstarpi starp D un key

				fin >> readedInt;

				pseudonyms.searchPseudonym(readedInt);
				if (pseudonyms.ptrPseudonym == NULL) fout << "no";
				else
				{
					pseudonyms.deleteReviewer(pseudonyms.ptrPseudonym->reviewer);

					// recenzenta dzçðana no saraksta
					if (reviewers.first == reviewers.last)
					{
						Node* ptr = reviewers.first;
						reviewers.first = reviewers.last = NULL;
						delete ptr;
					}

					if (reviewers.first != NULL)
					{
						Node* ptr = reviewers.first; //Iterators
						if (ptr->name == pseudonyms.ptrPseudonym->reviewer) // pirmais node sarakstâ ir vçlamais recenzents
						{
							reviewers.first = ptr->next;
							delete ptr;
						}

						while (ptr->next != NULL)
						{
							if (ptr->next->name != pseudonyms.ptrPseudonym->reviewer) ptr = ptr->next;
							else
							{
								Node* ptr2 = ptr->next;
								ptr->next = ptr2->next; // ptr->next->next
								if (ptr->next == NULL) reviewers.last = ptr;
								delete ptr2;
								break;
							}
						}
					}
					fout << "ok";
				}
			}
			if (c == 'L')
			{
				fin.read(&c, sizeof(char)); // Nolasa atstarpi starp L un key

				fin >> readedInt;
				pseudonyms.searchPseudonym(readedInt);

				if (pseudonyms.ptrPseudonym == NULL) fout << "no";
				else fout << pseudonyms.ptrPseudonym->reviewer;
			}
			fin.read(&c, sizeof(char)); // Lai lasîtu tâlâk nâkoðo rindu
		}
		if (c != '\n') fout << endl;
	}


	fin.close();
	fout.close();
}
