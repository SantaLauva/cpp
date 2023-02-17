#include <iostream>
#include <fstream>
using namespace std;


class Node
{
public:
	int day;
	int year;
	char name[30];
	char surname[30];
	Node* next;

	Node(int d, int y, char *n, char *s)
	{
		day = d;
		year = y;

		int i=0;
        while (n[i] != '\0')
        {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';

        i = 0;
        while (s[i] != '\0')
        {
            surname[i] = s[i];
            i++;
        }
        surname[i] = '\0';

		next = NULL;
	}
};


class List
{
public:
	Node* first;
	Node* ptr;
	Node* months[12];

	List()
	{
		first = NULL;
		ptr = NULL;
		for (int i = 0; i < 12; i++)
			months[i] = NULL;
	}

	void insertPerson(char *name, char *surname, int day, int month, int year)
	{
		Node* n = new Node(day, year, name, surname);
		if (months[month-1] == NULL) months[month - 1] = n;
		else
		{
			ptr = first = months[month - 1];
			if (day < months[month - 1]->day)
			{
				months[month-1] = n;
				months[month - 1]->next = first;
				return;
			}
			if (day == months[month - 1]->day) // Dienas sakrît
			{
				if (year < months[month - 1]->year)
				{
					months[month - 1] = n;
					months[month - 1]->next = first;
					return;
				}
				if (year == months[month - 1]->year) // Gadi sakrît
				{
					if (alphabeticalOrder(surname, months[month - 1]->surname) == 1)
					{
						months[month - 1] = n;
						months[month - 1]->next = first;
						return;
					}
					if (alphabeticalOrder(surname, months[month - 1]->surname) == 2) // Uzvârdi sakrît
					{
						if (alphabeticalOrder(name, months[month - 1]->name) == 1)
						{
							months[month - 1] = n;

							months[month - 1]->next = first;
							return;
						}
						if (alphabeticalOrder(name, months[month - 1]->name) == 0) // Nav situâcijas, kad vârdi sakrît.
						{
							if (months[month - 1]->next == NULL)
							{
								months[month - 1]->next = n;
								return;
							}
							ptr = months[month - 1];
							while (!(ptr->next->day > day) && (ptr->next != NULL))
							{
								if (alphabeticalOrder(name, ptr->next->name) == 1)
								{
									n->next = ptr->next;
									ptr->next = n;
									return;
								}
								ptr = ptr->next;
							}
							n->next = ptr->next;
							ptr->next = n;
							return;   // Vai sis izpildas ari ja sasniedz pedejo node??
						}
						if (alphabeticalOrder(name, months[month - 1]->name) == 2) return;
					}
					else // Uzvârdi alfabçtiskâ secîbâ
					{
						if (months[month - 1]->next == NULL)
						{
							months[month - 1]->next = n;
							return;
						}
						ptr = months[month - 1];
						while (!(ptr->next->day > day) && (ptr->next != NULL))
						{
							if (alphabeticalOrder(surname, ptr->next->surname) == 1)
							{
								n->next = ptr->next;
								ptr->next = n;
								return;
							}
							if (alphabeticalOrder(surname, ptr->next->surname) == 2) // Uzvârdi ir vienâdi
							{
								if (alphabeticalOrder(name, ptr->next->name) == 1)
								{
									n->next = ptr->next;
									ptr->next = n;
									return;
								}
								if (alphabeticalOrder(name, ptr->next->name) == 2) return;
							}
							ptr = ptr->next;
						}
						n->next = ptr->next;
						ptr->next = n;
						return;   // Vai sis izpildas ari ja sasniedz pedejo node??
					}
				}
				else // Gads lielâks
				{
					if (months[month - 1]->next == NULL)
					{
						months[month - 1]->next = n;
						return;
					}
					ptr = months[month - 1];
					while (!(ptr->next->day > day) && (ptr->next != NULL))
					{
						if (year < ptr->next->year)
						{
							n->next = ptr->next;
							ptr->next = n;
							return;
						}
						if (year == ptr->next->year) // gadi ir vienâdi
						{
							if (alphabeticalOrder(surname, ptr->next->surname) == 1)
							{
								n->next = ptr->next;
								ptr->next = n;
								return;
							}
							if (alphabeticalOrder(surname, ptr->next->surname) == 2)
							{
								if (alphabeticalOrder(name, ptr->next->name) == 1)
								{
									n->next = ptr->next;
									ptr->next = n;
									return;
								}
								if (alphabeticalOrder(name, ptr->next->name) == 2) return;
							}
						}
						ptr = ptr->next;
					}
					n->next = ptr->next;
					ptr->next = n;
					return;   // Vai sis izpildas ari ja sasniedz pedejo node??
				}
			}
			else // Diena lielâka
			{
				if (months[month - 1]->next == NULL)
				{
					months[month - 1]->next = n;
					return;
				}
				ptr = months[month - 1];
				while (!(ptr->next->day > day) && (ptr->next != NULL))
				{
					if (day < ptr->next->day)
					{
						n->next = ptr->next;
						ptr->next = n;
						return;
					}
					if (day == ptr->next->day) // dienas ir vienâdas
					{
						if (year < ptr->next->year)
						{
							n->next = ptr->next;
							ptr->next = n;
							return;
						}
						if (year == ptr->next->year) // gadi ir vienâdi
						{
							if (alphabeticalOrder(surname, ptr->next->surname) == 1)
							{
								n->next = ptr->next;
								ptr->next = n;
								return;
							}
							if (alphabeticalOrder(surname, ptr->next->surname) == 2)
							{
								if (alphabeticalOrder(name, ptr->next->name) == 1)
								{
									n->next = ptr->next;
									ptr->next = n;
									return;
								}
								if (alphabeticalOrder(name, ptr->next->name) == 2) return;
							}
						}
					}
					ptr = ptr->next;
				}
				n->next = ptr->next;
				ptr->next = n;
				return;   // Vai sis izpildas ari ja sasniedz pedejo node??
			}
		}
	}

	int alphabeticalOrder(char *name1, char *name2)
	{
		int i=0;
		while ((name1[i] != '\0') && (name2[i] != '\0'))
        {
            if (name1[i] < name2[i]) return 1;
            if (name1[i] > name2[i]) return 0;
            i++;
        }
        if ((name1[i] == '\0') && (name2[i] != '\0')) return 1;

        if ((name1[i] != '\0') && (name2[i] == '\0')) return 0;
		return 2;
	}
};


int main()
{
	ifstream fin;
	fstream fout;

	char name[30];
	char surname[30];
	int day;
	int month;
	int year;
	char c;
	int m = 0;

	List personList;

	fout.open("anniversary.out", ios::out);
	fin.open("anniversary.in", ios::in);

	fin.read((char*)&c, sizeof(char));
	while (fin)
	{
		day = month = year = 0;
		m = 0;
		if (c == 'P')
		{
			fin.read(&c, sizeof(char)); // Nolasa atstarpi starp P un name
			fin.read(&c, sizeof(char));
			while (fin)
			{
				if (c == ' ')
                {
                    name[m] = '\0';
                    break;
                }
				name[m] = c;
				m++;
				fin.read(&c, sizeof(char));
			}
			fin.read(&c, sizeof(char));
			m = 0;
			while (fin)
			{
				if (c == ' ')
                {
                    surname[m] = '\0';
                    break;
                }
				surname[m] = c;
				m++;
				fin.read(&c, sizeof(char));
			}

			fin.read(&c, sizeof(char));
			day = (c - 48) * 10;
			fin.read(&c, sizeof(char));
			day = day + (c - 48);

			fin.read(&c, sizeof(char)); // Nolasa .
			fin.read(&c, sizeof(char));
			month = (c - 48) * 10;
			fin.read(&c, sizeof(char));
			month = month + (c - 48);

			fin.read(&c, sizeof(char)); // Nolasa .
			fin.read(&c, sizeof(char));
			year = (c - 48) * 1000;
			fin.read(&c, sizeof(char));
			year = year + ((c - 48)*100);
			fin.read(&c, sizeof(char));
			year = year + ((c - 48) * 10);
			fin.read(&c, sizeof(char));
			year = year + (c - 48);

			personList.insertPerson(name, surname, day, month, year);
		}

		if (c == 'D')
		{
			fin.read(&c, sizeof(char)); // Nolasa atstarpi starp D un datumu

			fin.read(&c, sizeof(char));
			day = (c - 48) * 10;
			fin.read(&c, sizeof(char));
			day = day + (c - 48);

			fin.read(&c, sizeof(char)); // Nolasa .
			fin.read(&c, sizeof(char));
			month = (c - 48) * 10;
			fin.read(&c, sizeof(char));
			month = month + (c - 48);

			fin.read(&c, sizeof(char)); // Nolasa .
			fin.read(&c, sizeof(char));
			year = (c - 48) * 1000;
			fin.read(&c, sizeof(char));
			year = year + ((c - 48) * 100);
			fin.read(&c, sizeof(char));
			year = year + ((c - 48) * 10);
			fin.read(&c, sizeof(char));
			year = year + (c - 48);

            int bDay = 0;
			personList.ptr = personList.months[month - 1];
			while (personList.ptr)
			{
				if (personList.ptr->day > day)
				{
					bDay = personList.ptr->day;
					if (bDay < 10)
                    {
                        fout << "0" << bDay << ".";
                        if (month < 10) fout << "0" << month << "." << year << endl;
                        else fout << month << "." << year << endl;
                    }
					else
                    {
                        fout << bDay << ".";
                        if (month < 10) fout << "0" << month << "." << year << endl;
                        else fout << month << "." << year << endl;
                    }
					while(personList.ptr->day == bDay)
                    {
                        fout << year - personList.ptr->year << " " << personList.ptr->name << " " << personList.ptr->surname << endl;
                        if (personList.ptr->next == NULL) break;
                        personList.ptr = personList.ptr->next;
                    }
                    break;
				}
				if (personList.ptr->day == day)
				{
					bDay = personList.ptr->day;
					if (bDay < 10)
                    {
                        fout << "0" << bDay << ".";
                        if (month < 10) fout << "0" << month << "." << year << endl;
                        else fout << month << "." << year << endl;
                    }
					else
                    {
                        fout << bDay << ".";
                        if (month < 10) fout << "0" << month << "." << year << endl;
                        else fout << month << "." << year << endl;
                    }
					while(personList.ptr->day == bDay)
                    {
                        fout << year - personList.ptr->year << " " << personList.ptr->name << " " << personList.ptr->surname << endl;
                        if (personList.ptr->next == NULL) break;
                        personList.ptr = personList.ptr->next;
                    }
                    break;
				}
				personList.ptr = personList.ptr->next;
			}

			if (bDay == 0)
            {
                int i = month;
                int y = 0; // Pârbaudei
                while (i < 12)
                {
                    if (personList.months[i] != NULL)
                    {
                        personList.ptr = personList.months[i];
                        bDay = personList.months[i]->day;

                        if (bDay < 10)
                        {
                            fout << "0" << bDay << ".";
                            if (i < 9) fout << "0" << i+1 << "." << year << endl;
                            else fout << i+1 << "." << year << endl;
                        }
                        else
                        {
                            fout << bDay << ".";
                            if (i < 9) fout << "0" << i+1 << "." << year << endl;
                            else fout << i+1 << "." << year << endl;
                        }

                        while(personList.ptr->day == bDay)
                        {
                            fout << year - personList.ptr->year << " " << personList.ptr->name << " " << personList.ptr->surname << endl;
                            if (personList.ptr->next == NULL) break;
                            personList.ptr = personList.ptr->next;
                        }
                        y=1;
                        break;
                    }
                    i++;
                }
                if (y == 0)
                {
                    i = 0;
                    while (i < month)
                    {

                        if (personList.months[i] != NULL)
                        {
                            personList.ptr = personList.months[i];
                            bDay = personList.months[i]->day;

                            if (bDay < 10)
                            {
                                fout << "0" << bDay << ".";
                                if (i < 9) fout << "0" << i+1 << "." << year+1 << endl;
                                else fout << i+1 << "." << year+1 << endl;
                            }
                            else
                            {
                                fout << bDay << ".";
                                if (i < 9) fout << "0" << i+1 << "." << year+1 << endl;
                                else fout << i+1 << "." << year+1 << endl;
                            }

                            while(personList.ptr->day == bDay)
                            {
                                fout << year - personList.ptr->year + 1 << " " << personList.ptr->name << " " << personList.ptr->surname << endl;
                                if (personList.ptr->next == NULL) break;
                                personList.ptr = personList.ptr->next;
                            }
                            y=1;
                            break;
                        }
                        i++;
                    }

                }
            }
		}
		fin.read(&c, sizeof(char));
	}

	fin.close();
	fout.close();
}

