#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    fstream fin;
    fstream fout;
    char c;
    string s="";
    int k=0, j=0, space=0;

    string morseArray[2][43] = { {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4",
    "5", "6", "7", "8", "9", ".", ",", ":", "?", "-", "/"}, {".-", "-...", "-.-.", "-..",
    ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "---...",
    "..--..", "-....-", "-..-."} };


    fin.open("morse.in",ios::in);
    fout.open ("morse.out", ios::out);

    fin.read((char*)&c, sizeof(char));
    while(fin)
    {
        if (c == '|')
        {
            if (k>6)
            {
                fout << "!";
                s = "";
                k=0;
            }
            else
            {
                if (s == ".----.")
                {
                    space++;
                    if (space == 1)
                    {
                        fout << " ";
                        s = "";
                        k=0;
                    }
                }
                else
                {
                    for (int i=0; i<43; i++)
                    {
                        if (morseArray[1][i] == s)
                        {
                            fout << morseArray[0][i];
                            s = "";
                            k=0;
                            j++;
                            break;
                        }
                    }
                    if (j == 0)
                    {
                        fout << "!";
                        s = "";
                        k=0;
                    }
                    space = 0;
                }
                s = "";
                k=0;
            }
        }
        if (c == '.' || c == '-')
        {
            k++;
            s += c;
        }

        fin.read(&c, sizeof(char));
    }
    if (s != "") fout << "!";


    fin.close();
    fout.close();
}
