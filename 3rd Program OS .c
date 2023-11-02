#include <iostream>
using namespace std;
void CalculateWaitingTime(int at[],
                          int bt[], int N)
{  
    int wt[N]; 
    wt[0] = 0;
    cout << "PN\t\tAT\t\t"
         << "BT\t\tWT\n\n";
    cout << "1"
         << "\t\t" << at[0] << "\t\t"
         << bt[0] << "\t\t" << wt[0] << endl;
    for (int i = 1; i < 5; i++) {
        wt[i] = (at[i - 1] + bt[i - 1]
                 + wt[i - 1]) - at[i];
        cout << i + 1 << "\t\t" << at[i]
             << "\t\t" << bt[i] << "\t\t"
             << wt[i] << endl;
    }
    float average;
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + wt[i];
    }

    average = sum / 5;
    cout << "\nAverage waiting time = "
         << average;
}
int main()
{
    int N = 5;
    int at[] = { 0, 1, 2, 3, 4 };
    int bt[] = { 4, 3, 1, 2, 5 };
    CalculateWaitingTime(at, bt, N);
    return 0;
}
