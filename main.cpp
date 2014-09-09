#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int main();

void gotoxy (int x, int y)                  //CURSOR COORDINATES
{
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int AR[79],arr[79],ITEM,index,size,choice,r;

void graph(int a)
{
    for(int i=0;i<a;++i)
    {
        gotoxy(r,24-i);
        cout<<'.';
    }
}

void Bubble(int AR[])
{
    int tmp;
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<(size-1)-i;++j)
        {
            if(AR[j]>AR[j+1])
            {
                tmp=AR[j];
                AR[j]=AR[j+1];
                AR[j+1]=tmp;
            }
        }

        for(int k=0;k<size;k++)
        {
            graph(AR[k]);
            r++;
        }
        r=0;
        Sleep(50);
        if(i!=(size-1))system("cls");
    }
}

void Insert(int AR[])
{
    int tmp,j;
    AR[0]=INT_MIN;
    for(int i=1;i<=size;++i)
    {
        tmp=AR[i];
        j=i-1;
        while(tmp<AR[j])
        {
            AR[j+1]=AR[j];
            j--;
        }
        AR[j+1]=tmp;
        for(int k=1;k<=size;++k)
        {
            graph(AR[k]);
            r++;
        }
        r=0;
        Sleep(50);
        if(i!=(size))system("cls");
    }
}

void Selection(int AR[])
{
    int sma,pos,tmp;
    for(int i=0;i<size;++i)
    {
        sma=AR[i];
        pos=i;
        for(int j=i+1;j<size;j++)
        {
            if(AR[j]<sma)
            {
                sma=AR[j];
                pos=j;
            }
        }
        tmp=AR[i];
        AR[i]=AR[pos];
        AR[pos]=tmp;
        for(int k=0;k<size;++k)
        {
            graph(AR[k]);
            r++;
        }
        r=0;
        Sleep(50);
        if(i!=(size-1))system("cls");
    }
}

void Shell(int AR[])
{
        int iter, jter, increment, temp, i,j;
        for(increment = size/2;increment > 0; increment /= 2)
        {
                for(i = increment; i<size; i++)
                {
                        temp = AR[i];
                        for(j = i; j >= increment ;j-=increment)
                        {
                                if(temp < AR[j-increment])
                                {
                                        AR[j] = AR[j-increment];
                                }
                                else
                                {
                                        break;
                                }
                        }
                        AR[j] = temp;
                }

                for(int k=0;k<size;k++)
                {
                    graph(AR[k]);
                    r++;
                }
                r=0;
                Sleep(50);
                if(increment!=0 && increment!=1 && increment!=-1)
                system("cls");
        }
}

void QuickSort(int AR[], int from, int to)
{
        if(from>=to)
            return;
        int pivot = AR[from]; /*Pivot I am chosing is the starting element */
        /*Here i and j are such that in the AR all elemnts a[from+1...i] are less than pivot,
          all elements a[i+1...j] are greater than pivot and the elements a[j+1...to] are which
          we have not seen which is like shown below.
          ________________________i_________________j___________
          |pivot|....<=pivot......|....>=pivot......|.........|
          If the new element we encounter than >=pivot the above variant is still satisfied.
          If it is less than pivot we swap a[j] with a[i+1].
         */
        int i = from, j, temp;
        for(j = from + 1;j <= to;j++)
        {
                if(AR[j] < pivot)
                {
                        i = i + 1;
                        temp = AR[i];
                        AR[i] = AR[j];
                        AR[j] = temp;
                }
        }
        /* Finally The picture is like shown below
          _______________________i____________________
          |pivot|....<=pivot......|....>=pivot......|
        */
        temp = AR[i];
        AR[i] = AR[from];
        AR[from] = temp;
        /* So we the array is now
          ____________________i______________________
          |...<=pivot......|pivot|....>=pivot......|
        */
        /*Recursively sort the two sub arrays */

        for(int k=0;k<size;k++)
        {
            graph(AR[k]);
            r++;
        }
        r=0;
        Sleep(50);
        system("cls");

        QuickSort(AR,from,i-1);
        QuickSort(AR,i+1,to);
}

int main()
{
    cout << "\t\tHello world!\n\n" << endl;
    srand(time(NULL));
    size=79;

    for(int i=0;i<size;++i)
        arr[i]=rand()%24+1;

    cout<<"\t\tWhat kind of Sorting do you want to see?..."<<endl;
    cout<<"\t\t1. Bubble Sort\n";
    cout<<"\t\t2. Insertion Sort\n";
    cout<<"\t\t3. Selection Sort\n";
    cout<<"\t\t4. Shell Sort\n";
    cout<<"\t\t5. Quick Sort\n";
    cout<<"\t\t0. Exit\n";
    cout<<"\n\t\tcin>>...";
    cin>>choice;
    system("cls");

    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            for(int i=0;i<size;++i)
                AR[i]=arr[i];
            r=0;
            Bubble(AR);
            break;

        case 2:
            for(int i=0;i<size;++i)
                AR[i]=arr[i];
            Insert(AR);
            break;

        case 3:
            for(int i=0;i<size;++i)
                AR[i]=arr[i];
            Selection(AR);
            break;

        case 4:
            for(int i=0;i<size;++i)
                AR[i]=arr[i];
            Shell(AR);
            break;

        case 5:
            for(int i=0;i<size;++i)
                AR[i]=arr[i];
            QuickSort(AR, 0, size-1);
            for(int k=0;k<size;k++)
            {
                graph(AR[k]);
                r++;
            }
            r=0;
            Sleep(50);
            break;

        case 0:
            exit(0);
            break;

        default :
            cout<<"\t\tEnter a valid option...";
            cin>>choice;
            break;
        }
        gotoxy(0,0);
        system("Pause");
        system("cls");
        main();

    }

    return 0;
}
