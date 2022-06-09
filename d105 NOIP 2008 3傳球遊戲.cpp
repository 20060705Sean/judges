#include <iostream>

using namespace std;

int step[31][31][31];

void setTable()
{
    int i, j, k;

    for(i = 3; i<=30; i++)
        step[i][1][0] = 1;

    for(i = 3; i<=30; i++)
        for(k = 1 ; k<=30; k++)
            for(j = 1; j<= i; j++)
                if(j == 1)
                    step[i][j][k] = step[i][i][k-1] + step[i][j+1][k-1];
                else if(j == i)
                    step[i][j][k] = step[i][j-1][k-1] + step[i][1][k-1];
                else
                    step[i][j][k] = step[i][j-1][k-1] + step[i][j+1][k-1];
}

int main()
{
    int people;
    int pass;


    setTable();
    while(cin >> people >> pass)
        cout << step[people][1][pass] << endl;

    return 0;
}
