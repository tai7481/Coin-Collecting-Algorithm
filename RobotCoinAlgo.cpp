/* Modified Robot coin algorithm for
optimum coin retrieval based on plausible
routes in n x m matrix
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int n = 5;
const int m = 6;

//Function Prototypes
void Collect (int Arr[][m]);
void Output (int Arr[][m]);
int Maximum (int x, int y);

int main()
{
    int Array[5][6] = {0,-1,0,1,0,0,
                       1,0,0,-1,1,0,
                       0,1,0,-1,1,0,
                       0,0,0,1,0,1,
                       -1,-1,-1,0,1,0};

    Collect (Array);

    return 0;
}

void Output (int Arr[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << '\t' << Arr[i][j];
        }
        cout << endl;
    }
}

void Collect (int Arr[][m])
{
    int i = 1;      //temp row var
    int j = 1;      //temp col var
    int Brr[n][m];  //temp matrix container

    Brr[0][0] = Arr[0][0];      //set the equate then run algo
    while (i < n && Arr[i][0] != -1)    //boundary restrictions
    {
        Brr[i][0] = Brr[i-1][0] + Arr[i][0];
        i++;
    }
    for (; i < n; i++)
    {
        Brr[i][0] = -6;
    }
    while (j < m && Arr[0][j] != -1)    //boundary restrictions
    {
        Brr[0][j] = Brr[0][j-1] + Arr[0][j];
        j++;
    }
    for (; j < m; j++)
    {
        Brr[0][j] = -6;
    }

    //Output (Brr);     //post init

    cout << endl << endl;

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (Arr[i][j] != -1)
                {
                    Brr[i][j] = Maximum(Brr[i-1][j], Brr[i][j-1]) + Arr[i][j];
                }
            else
                Brr[i][j] = -6;
        }
    }

    Output (Brr);     //post algo result
}

int Maximum (int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
