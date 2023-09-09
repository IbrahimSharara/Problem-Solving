#include <iostream>

using namespace std;
int t, m, n ;
int main()
{
    cin >> t ;
    char vika[]= {'v', 'i', 'k', 'a'};
    while(t--)
    {
        cin >> n >> m ;

        int counter = 0 ;
        char arr[n][m];
        for(int  i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> arr[i][j];
            }
        }
        if( m < 4)
        {
            cout << "No\n";
            continue ;
        }
        else
        {

            for (int x = 0 ; x < m ; ++x)
            {
                for(int i = 0 ; i < n ; ++i)
                {
                    if(arr[i][x] == vika[counter])
                    {
                        ++counter ;
                        break;
                    }
                }
            }
        }
        if(counter == 4 )
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
