#include<bits/stdc++.h>
using namespace std;
int Passenger, planes, minCounter = 0, maxCounter = 0, Allseats = 0;
int getMin(int arrAsc[], int planes, int Passenger)
{
    int x = 0 ;
    while(x < planes && Passenger > 0)
    {
        while(arrAsc[x] > 0 && Passenger > 0)
        {
            minCounter += arrAsc[x]--;
            --Passenger;
        }
        ++x;
    }

    return minCounter;
}

int getMax(int arrDsc[], int planes, int Passenger)
{
    int x = planes - 1 ;
    while( x >= 0 && Passenger > 0)
    {
        while(arrDsc[x] > 0 && Passenger > 0)
        {
            maxCounter += arrDsc[x]--;
            --Passenger;
            if(x == 0)
            {
                continue ;
            }
            else
            {
                int y = x - 1 ;
                while(y >=0 && Passenger > 0)
                {
                    if(arrDsc[y] >= arrDsc[x])
                    {
                        maxCounter += arrDsc[y]--;
                        --Passenger ;
                    }
                    else
                        break;
                    y--;
                }
            }
        }
        --x;
    }
    return maxCounter ;
}
int main()
{
    cin >> Passenger >> planes ;
    int planCounter = planes, PassengerConter = Passenger;
    int arrAsc[planes], arrDsc[planes];
    for(int x =0 ; x < planes ; ++x)
    {
        cin >> arrAsc[x] ;
        arrDsc[x] = arrAsc[x];
        Allseats += arrAsc[x];
    }
    sort(arrAsc, arrAsc + planes);
    sort(arrDsc, arrDsc + planes);
    int minCounter = getMin(arrAsc , planes , Passenger);
    if(Allseats == PassengerConter)
    {
        cout << minCounter << " " << minCounter ;
        return 0;
    }

    cout <<getMax(arrDsc , planCounter , PassengerConter) <<" "<< minCounter ;
    return 0 ;
}

