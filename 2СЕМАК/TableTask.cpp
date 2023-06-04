#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

const int numberGames = 5;
const int numberMark = 4;
const int lengthIndent = 7;  //    длина абзаца
const int lengthTable = 56;  //    длина таблицы
const int lengthColumn = 10; // длина колонки
/////////////////////////////////////////////////
void dot(ofstream& f, int n, int m)
{
    f.width(n);
    for (int i = 0; i < m; i++)
        f << '.';
    f << endl;
}
///////////////////////////////////////////////
void dot1(ofstream& f, int n)
{
    f.width(n);
    f << ".";
    f.width(lengthColumn + 1);
    f << ".";

    for (int i = 0; i < numberMark; i++)
    {
        f.width(lengthColumn + 1);
        f << '.';
    }
    f << endl;
}
///////////////////////////////////////////////////////////////
int main()
{

    char name_Game[numberGames][15];
    char name_Mark[numberMark][20];
    int number_Review[numberGames][numberMark];
    char name_Head[80];
    double Average[numberMark];

    for (int i = 0; i < numberMark; i++) {
        Average[i] = 0;
    }

    ifstream in("C:/Users/yashn/OneDrive/Documents/info.txt");
    ofstream out("C:/Users/yashn/OneDrive/Documents/result.txt");

    in.getline(name_Head, 80);

    for (int i = 0; i < numberGames; i++)
        in >> name_Game[i];

    for (int i = 0; i < numberMark; i++)
        in >> name_Mark[i];

    for (int i = 0; i < numberGames; i++)
        for (int j = 0; j < numberMark; j++)
            in >> number_Review[i][j];

    in.close();

    out << endl << endl;
    out.width(lengthTable + 4);
    out << name_Head << endl;
    out << endl << endl;

    dot(out, lengthIndent + 1, lengthTable);
    dot1(out, lengthIndent + 1);

    out.width(lengthIndent + 1);
    out << ".";
    out.width(lengthColumn + 1);
    out << ".";

    for (int i = 0; i < numberMark; i++)
    {
        out << " " << name_Mark[i];
        out.width(lengthColumn - strlen(name_Mark[i]));
        out << ".";
    }
    out << endl;

    dot1(out, lengthIndent + 1);
    dot(out, lengthIndent + 1, lengthTable);
    /////////////////////
    for (int i = 0; i < numberGames; i++)
    {
        dot1(out, lengthIndent + 1);
        out.width(lengthIndent + 1);
        out << ".";
        out << " " << name_Game[i];
        out.width(lengthColumn - strlen(name_Game[i]));
        out << ".";

        for (int j = 0; j < numberMark; j++)
        {
            out << setw(6) << number_Review[i][j];
            Average[j] += double(number_Review[i][j]) / 4;
            out << setw(5);
            out << ".";
        }
        out << endl;
        dot1(out, lengthIndent + 1);
        dot(out, lengthIndent + 1, lengthTable);
    }


    dot(out, lengthIndent + 1, lengthTable);
    dot1(out, lengthIndent + 1);

    out.width(lengthIndent + 1);
    out << "." << " Average  .";
    for (int j = 0; j < numberMark; j++)
    {
        out << setw(6) << Average[j];
        out << setw(5);
        out << ".";
    }

    out << endl;
    dot1(out, lengthIndent + 1);
    dot(out, lengthIndent + 1, lengthTable);
    out << endl;

    out.close();
    return 0;
}
