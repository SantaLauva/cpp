#include <iostream>
#include <fstream>
using namespace std;


class Node
{
public:
	char type;
	int customsOfficer;
	int arrTime;
	int exitTime;
	Node* next;
	Node* previous;

	Node(char c, int m, int a, int e)
	{
		type = c;
		customsOfficer = m;
		arrTime = a;
		exitTime = e;
		next = previous = NULL;
	}
};


class ExitQueue
{
public:
	Node* first;
	Node* last;
	Node* ptr;

	ExitQueue()
	{
		first = last = NULL;
		ptr = NULL;
	}

	// c - tips P vai N, m - muitnieka nr, a - arrival time, e - exit time
	void addToQueue(char c, int m, int a, int e)
	{
		Node* n = new Node(c, m, a, e);

		if (isEmpty()) last = first = n;
		else
		{
			ptr = last;

			if (e > last->exitTime)
			{
				last->next = n;
				n->previous = last;
				last = n;
				return;
			}
			else if (e == last->exitTime)
			{
				if (c == 'P')
				{
					if (last->type == 'P')
					{
						if (m < last->customsOfficer)
						{
							ptr = last->previous;
							ptr->next = n;
							n->previous = ptr;
							n->next = last;
							last->previous = n;
							return;
						}
						else
						{
							last->next = n;
							n->previous = last;
							last = n;
							return;
						}
					}
					else
					{
						ptr = last->previous;
						ptr->next = n;
						n->previous = ptr;
						n->next = last;
						last->previous = n;
						return;
					}
				}
				if (c == 'N')
				{
					if (last->type == 'N')
					{
						if (m < last->customsOfficer)
						{
							ptr = last->previous;
							ptr->next = n;
							n->previous = ptr;
							n->next = last;
							last->previous = n;
							return;
						}
						else
						{
							last->next = n;
							n->previous = last;
							last = n;
							return;
						}
					}
					else
					{
						last->next = n;
						n->previous = last;
						last = n;
						return;
					}
				}
			}
			else
			{
				while (ptr)
				{
					if ((e < ptr->exitTime) && (ptr->previous == NULL))
					{
						ptr->previous = n;
						n->next = ptr;
						first = n;
						return;
					}
					if (e == ptr->exitTime)
					{
						if (c == 'P')
						{
							if (ptr->type == 'P')
							{
								if (m > ptr->customsOfficer)
								{
									Node* ptr2 = ptr->next;
									ptr->next = n;
									n->previous = ptr;
									n->next = ptr2;
									ptr2->previous = n;
									return;
								}
								if ((m < ptr->customsOfficer) && (ptr->previous == NULL))
								{
									ptr->previous = n;
									n->next = ptr;
									first = n;
									return;
								}
							}
							else if ((ptr->type == 'N') && (ptr->previous == NULL))
							{
								ptr->previous = n;
								n->next = ptr;
								first = n;
								return;
							}
						}
						else // c == N
						{
							if (ptr->type == 'P')
							{
								Node* ptr2 = ptr->next;
								ptr->next = n;
								n->previous = ptr;
								n->next = ptr2;
								ptr2->previous = n;
								return;
							}
							else
							{
								if (m > ptr->customsOfficer)
								{
									Node* ptr2 = ptr->next;
									ptr->next = n;
									n->previous = ptr;
									n->next = ptr2;
									ptr2->previous = n;
									return;
								}
								if ((m < ptr->customsOfficer) && (ptr->previous == NULL))
								{
									ptr->previous = n;
									n->next = ptr;
									first = n;
									return;
								}
							}
						}
					}
					if (e > ptr->exitTime)
					{
						Node* ptr2 = ptr->next;
						ptr->next = n;
						n->previous = ptr;
						n->next = ptr2;
						ptr2->previous = n;
						return;
					}
					ptr = ptr->previous;
				}
			}
		}
	}

	bool isEmpty()
	{
		return (last == NULL);
	}

	void deleteQueue()
	{
		while (last)
		{
			ptr = last;
			last = last->previous;
			delete ptr;
		}
	}
};


int main()
{
	ifstream fin;
	fstream fout;

	char c;
	int pMuitnieki = 0;
	int nMuitnieki = 0;
	int pLaiks;
	int nLaiks;

	ExitQueue queue;

	fout.open("customs.out", ios::out);
	fin.open("customs.in", ios::in);

	fin >> pMuitnieki;
	fin >> nMuitnieki;
	fin >> pLaiks;
	fin >> nLaiks;

	int pMuitKontrLaiks[pMuitnieki];
	int nMuitKontrLaiks[nMuitnieki];
	int pMuitBeiguLaiks[pMuitnieki];
	int nMuitBeiguLaiks[nMuitnieki];

	for (int i = 0; i < pMuitnieki; i++)
	{
		pMuitKontrLaiks[i] = pLaiks;
		pMuitBeiguLaiks[i] = 0;
	}

	for (int i = 0; i < nMuitnieki; i++)
	{
		nMuitKontrLaiks[i] = nLaiks;
		nMuitBeiguLaiks[i] = 0;
	}

	fin.read((char*)&c, sizeof(char)); // Nolasa rindas beigas
	fin.read(&c, sizeof(char)); // Nolasa T
	while (fin)
	{
		if (c == 'T')
		{
			int muitnieks;
			int laiks;
			fin.read(&c, sizeof(char)); // Nolasa atstarpi
			fin.read(&c, sizeof(char)); // Nolasa P vai N
			if (c == 'P')
			{
				fin >> muitnieks;
				fin >> laiks;
				pMuitKontrLaiks[muitnieks - 1] = laiks;
			}
			if (c == 'N')
			{
				fin >> muitnieks;
				fin >> laiks;
				nMuitKontrLaiks[muitnieks - 1] = laiks;
			}
		}

		else if (c == 'P')
		{
			int id;
			fin >> id;
			bool min = false;
			int minIndex = 0;

			for (int i = 0; i < pMuitnieki; i++)
			{
				if (id >= pMuitBeiguLaiks[i])
				{
					pMuitBeiguLaiks[i] = id + pMuitKontrLaiks[i];
					// pievieno rindai
					queue.addToQueue('P', i, id, pMuitBeiguLaiks[i]);
					min = false;
					break;
				}
				else if (pMuitBeiguLaiks[i] <= pMuitBeiguLaiks[minIndex])
                {
                    min = true;
                    minIndex = i;
                }
			}

			if (min)
			{
				pMuitBeiguLaiks[minIndex] += pMuitKontrLaiks[minIndex];
				// pievieno rindai
				queue.addToQueue('P', minIndex, id, pMuitBeiguLaiks[minIndex]);
			}

		}

		else if (c == 'N')
		{
			int id;
			fin >> id;
			bool min = false;
			int minIndex = 0;

			for (int i = 0; i < nMuitnieki; i++)
			{
				if (id >= nMuitBeiguLaiks[i])
				{
					nMuitBeiguLaiks[i] = id + nMuitKontrLaiks[i];

					// pievieno rindai
					queue.addToQueue('N', i, id, nMuitBeiguLaiks[i]);
                    min = false;
					break;
				}
				else if (nMuitBeiguLaiks[i] <= nMuitBeiguLaiks[minIndex])
                {
                    min = true;
                    minIndex = i;
                }
			}

			if (min)
			{
				nMuitBeiguLaiks[minIndex] += nMuitKontrLaiks[minIndex];

				// pievieno rindai
				queue.addToQueue('N', minIndex, id, nMuitBeiguLaiks[minIndex]);
			}
		}
		fin.read(&c, sizeof(char));
	}

	if (queue.first == NULL) fout << "nothing" << endl;
	else
	{

		queue.ptr = queue.first;
		while (queue.ptr)
		{
			fout << queue.ptr->arrTime << " " << queue.ptr->exitTime << endl;
			queue.ptr = queue.ptr->next;
		}
	}

	queue.deleteQueue();

	fin.close();
	fout.close();
}
