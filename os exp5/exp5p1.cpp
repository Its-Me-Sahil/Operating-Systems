
//1: Program to implement safe sequence and resource request


#include <iostream>
using namespace std;

#define max 10

int n, m, allo[max][max], maxm[max][max], need[max][max], avail[max], work[max], finish[max], count = 0, check1 = 0, check2 = 0, p[max], sequence[max], s = 0,req,request[max];

void safesequence()
{
    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    while (count != n)
    {
        for (int i = 0; i < n; i++)
        {
            check1 = 0;
            for (int j = 0; j < m; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= work[j])) // Fixed need[i][j] <= work[i] to need[i][j] <= work[j]
                {
                    check1++;
                }
            }
            if (check1 == m)
            {
                for (int j = 0; j < m; j++)
                {
                    work[j] = work[j] + allo[i][j];
                    finish[i] = 1;
                }
                sequence[s] = i; // Fixed sequence[s] = 1 to sequence[s] = i
                s++;
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            check2++;
        }
    }
    if (check2 == n)
    {
        cout << "\nSafe sequence exists" << endl; // Moved the safe sequence print outside the loop
        cout << "Safe sequence: ={";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << sequence[i];
            if (i != n - 1)
            {
                cout << " -> ";
            }
        }
        cout <<"}"<<endl;
    }
    else
    {
        cout << "Safe sequence does not exist" << endl;
    }

    //requesting to resources
    cout<<"Enter the process from which request is coming :";
    cin>>req;
    cout<<"\nEnter the request :";
    for(int j=0; j<m; j++)
    {
        cin>>request[j];
    }

    for ( int j = 0; j < m; j++) // Fixed 'j' declaration
    {
        if (request[j] <= need[req][j])
        {
            if (request[j] <= avail[j])
            {
                avail[j] = avail[j] - request[j];
                need[req][j] = need[req][j] - request[j];
                allo[req][j] = allo[req][j] + request[j];
            }
            else
            {
                printf("\nResource cannot be granted\n");
                return;
            }
        }
        else
        {
            printf("\nResource cannot be granted\n");
            return;
        }
    }
    printf("\nResource can be granted\n");
}

void display()
{
    cout << "\n Displaying the User Input:\n";
    cout << "\nDisplays ALLOCATION matrix \n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << allo[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays NEED matrix\n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays max  matrix\n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << maxm[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays available matrix :\n";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << avail[i] << "  ";
    }
}

void input()
{
    cout<<"Enter the number of Process :";
    cin>>n;
    cout<<"\nEnter the number of Resource :";
    cin>>m;
    cout<<"\nEnter the values in allocation table :\n";     //taking input for allocation :
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>allo[i][j];
        }
    }

    cout<<"Enter the values in max table :\n";     //taking input for max :
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>maxm[i][j];
        }
    }

    cout<<"Enter the values for Availablity :"<<endl; //taking input for available
    for(int i=0; i<m; i++)
    {
        cout<<"For R"<<i+1<<":";
        cin>>avail[i];
    }



    //calculating need

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {

            need[i][j]=(maxm[i][j])-(allo[i][j]);
        }
    }


}

int main()
{
    cout<<"\nProgram to implement safe sequence and resource request \n";

    input();
    display();
    safesequence();
    return 0;
}







