#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int row, col = 0;
vector<vector<char>> board;
vector<string> words;
int counter = 0;

void readFile(string path);
void displayTest();
void checkWord(int i, int j, string word, int arah);
void generate(vector<vector<char>> &vec);

int main(int argc, const char **argv)
{
    string path;

    /* Penentuan path file konfigurasi */
    // cout << "Type path to config file: ";

    // getline(cin,path);

    readFile(argv[1]);
    displayTest();

    auto start = high_resolution_clock::now();
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            for (string word : words)
            {
                checkWord(i, j, word, 1);
                checkWord(i, j, word, 2);
                checkWord(i, j, word, 3);
                checkWord(i, j, word, 4);
                checkWord(i, j, word, 5);
                checkWord(i, j, word, 6);
                checkWord(i, j, word, 7);
                checkWord(i, j, word, 8);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    cout << endl << "Pengecekan huruf dilakukan sebanyak: " << counter << " kali" << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Puzzle diselesaikan dalam waktu: " << duration.count() << " microseconds"<< endl;
    return 0;
}

void generate(vector<vector<char>> &vec)
{

    for (int i = 0; i < row; i++)
    {
        vector<char> v_row;
        for (int j = 0; j < col; j++)
        {
            v_row.push_back('_');
        }
        vec.push_back(v_row);
    }
}

void checkWord(int i, int j, string word, int arah)
{
    vector<vector<char>> vec;
    bool isRight = false;
    int k = 0;

    generate(vec);

    // cout << word << endl ;
    while (k < word.size() && i >= 0 && j >= 0 && i < row && j < col && counter++ && word[k] == board[i][j])
    {
        vec[i][j] = word[k];
        k += 1;
        switch (arah)
        {
        case 1:
            j = j + 1;
            i = i;
            break;
        case 2:
            j = j + 1;
            i = i + 1;
            break;
        case 3:
            j = j;
            i = i + 1;
            break;
        case 4:
            j = j - 1;
            i = i + 1;
            break;
        case 5:
            j = j - 1;
            i = i;
            break;
        case 6:
            j = j - 1;
            i = i - 1;
            break;
        case 7:
            j = j;
            i = i - 1;
            break;
        case 8:
            j = j + 1;
            i = i - 1;
            break;
        }
    }

    if (k == word.size())
    {
        cout << endl
             << word << endl;
        for (int l = 0; l < row; l++)
        {
            for (int m = 0; m < col; m++)
            {
                cout << vec[l][m] << " ";
            }
            cout << endl;
        }
    }
}

void readFile(string path)
{
    /* Kamus */
    fstream file;
    /* Algoritma */

    /* Membuka file konfigurasi */
    file.open(path, ios::in);
    if (file.is_open())
    {
        string line;
        /* Proses pembacaan board permainan */
        while (getline(file, line))
        {
            vector<char> b_row;
            /* Panjang line 1 memiliki arti baris kosong */
            if (line.length() == 1)
                break;
            else
            {
                col = line.length() / 2;
                for (int i = 0; i < line.length(); i += 2)
                {
                    b_row.push_back(line[i]);
                }
                board.push_back(b_row);
                row += 1;
            }
        }

        /* Pembacaan kata-kata yang ingin dicari */
        while (file >> line)
        {
            words.push_back(line);
        }

        file.close();
    }
}

void displayTest()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        cout << *i << endl;
    }
}
