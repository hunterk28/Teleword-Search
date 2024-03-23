//Kamil Saeed, 23i-2035, Assignment 1.

#include<iostream>
#include<fstream>
#include<cstring>
#include<chrono>

#define RESET "\033[0m"															                                    //To Add colour.
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

void sfhorizontal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                              //Fuction for forward horizontal word search.
{
    int a = strlen(arr2);
    int y = 0, d = 0, b = 0;
    char arr[15];
    cout<<arr2<<endl;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && j+k<15; k++)
                {
                    if(grids[i][j+k] == arr2[k])                                                            //Comparing character by character
                    {
                        y++;
                    }

                    if(y == a)                                                                             //Condition if number of match char are equal to word length.
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;                               //Word found
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i;
                        d=j;

                        for (int l=0, k=0; l<15; l++)                                                      //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m >= d)
                                {
                                    if(k < a)                                                             //To colour only  that word
                                    {
                                        cout << RED << grids[l][m] << RESET << " ";                       //Colour the word
                                        arr3[l][m] = grids[l][m];                                         //Storing coloured words in another array.
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";                                         //Printing grid without colour
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";                                             //if condition not matched print grid colourless.
                                }
                            }       
                            cout<<endl;
                        }
                        
                        break;
                    }
                }
            }
            y = 0;
        }  
    }

}

void sbhorizontal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                             //Function of reverse horizontal word search.
{
    int a = strlen(arr2);
    int y = 0 , d = 0, b = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && j-k>-1 && j-k<15 ; k++)                                                   //Loop that run in grid 
                {
                    if(grids[i][j-k] == arr2[k])                                                              //Comparing character by character
                    {
                        y++;
                    }

                    if(y == a)                                                                                //Condition if number of match char are equal to word length.
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;                                  //Word found.
                        cout<<arr2<<"\n"<<endl;    
                        cout << "Length of word: " << a <<"\n\n";

                        b=i;
                        d=j-k;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m >= d)
                                {
                                    if(k < a)                                                               //To colour only  that word
                                    {
                                        cout << RED << grids[l][m] << RESET << " ";                         //Printing coloured words
                                        arr3[l][m] = grids[l][m];                                           //Storing coloured words in another array
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void sdvertical(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                              //Function for vertical down word search.
{
    int a = strlen(arr2);
    int y = 0, b = 0, d = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i+k>-1 && i+k<15 ; k++)
                {
                    if(grids[i+k][j] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i;
                        d=j;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l >= b && m == d)
                                {
                                    if(k < a)
                                    {
                                        cout << BLUE << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                    //arr3[l][m] = grids[l][m];
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void suvertical(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                              //Function for vertical up word search. 
{
    int a = strlen(arr2);
    int y = 0, d = 0, b = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i-k>-1 && i-k<15 ; k++)
                {
                    if(grids[i-k][j] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i-k;
                        d=j;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l >= b && m == d)
                                {
                                    if(k < a)
                                    {
                                        cout << BLUE << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void tlbrdiagonal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                              //Function for diagonal word search from top left to bottom right.          
{
    int a = strlen(arr2);
    int y = 0, b = 0, d = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i+k>-1 && i+k<15 && j+k>-1 && j+k<15 ; k++)
                {
                    if(grids[i+k][j+k] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i;
                        d=j;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m == d)
                                {
                                    b++;
                                    d++;

                                    if(k < a)
                                    {
                                        cout << YELLOW << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void brtldiagonal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                             //Function for diagonal word search from bottom right to top left.         
{
    int a = strlen(arr2);
    int y = 0, b = 0, d = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i-k>-1 && i-k<15 && j-k>-1 && j-k<15 ; k++)
                {
                    if(grids[i-k][j-k] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i-k;
                        d=j-k;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m == d)
                                {
                                    b++;
                                    d++;

                                    if(k < a)
                                    {
                                        cout << YELLOW << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void trbldiagonal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                              //Function for diagonal word search from top right to bottom left.
{
    int a = strlen(arr2);
    int y = 0, b = 0, d = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i+k>-1 && i+k<15 && j-k>-1 && j-k<15 ; k++)
                {
                    if(grids[i+k][j-k] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";

                        b=i;
                        d=j;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m == d)
                                {
                                    b++;
                                    d--;

                                    if(k < a)
                                    {
                                        cout << GREEN << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}

void bltrdiagonal(char** grids, int r, int c, char arr2[], char** arr3, int s, int t)                                //Function for diagonal word search from bottom left to top right.
{
    int a = strlen(arr2);
    int y = 0, b = 0, d = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grids[i][j] == arr2[0])
            {
                for(int k=0; k<a && i-k>-1 && i-k<15 && j+k>-1 && j+k<15 ; k++)
                {
                    if(grids[i-k][j+k] == arr2[k])
                    {
                        y++;
                    }

                    if(y == a)
                    {
                        cout<<"\nWord found at "<< i <<"-"<< j <<"\n"<<endl;
                        cout<<arr2<<"\n"<<endl;
                        cout << "Length of word: " << a <<"\n\n";


                        b=i-k;
                        d=j+k;

                        for (int l=0, k=0; l<15; l++)                                                        //Loop for printing grid.
                        {
                            for (int m=0; m<15; m++) 
                            {         
                                if(l == b && m == d)
                                {
                                    b++;
                                    d--;

                                    if(k < a)
                                    {
                                        cout << GREEN << grids[l][m] << RESET << " ";
                                        arr3[l][m] = grids[l][m];
                                        k++;
                                    }

                                    else
                                    {
                                        cout<< grids[l][m] <<" ";
                                    }

                                }
                                else
                                {
                                    cout<< grids[l][m] <<" ";
                                }
                            }       
                            cout<<endl;
                        }
                        break;
                    }
                }
            }
            y = 0;
        }   
    }
}


int main(int argc, char *argv[])
{
    char a, s;
    int i=15, c, d;
    char arr1[20], arr[43];
    int tsum = 0;

    char** grids = new char* [i];                                                   

    for (int k=0; k<i; k++) 
    {
        grids[k] = new char [i];
    }

    fstream fin;
    fin.open(argv[1], ios::in);                                                     //File open.

    if(!fin)
    {
        cout << "\nError reading file" << endl;
        cout << "Check file name" << endl;
    }

    for (int l=0; l<i; l++)                                                        //Loop for reading characters from file.
    {
        for (int m=0; m<i; m++) 
        {
            fin.get(a);                                                            //Read character by character from file.

            if(a=='\n')
            {
                break;
            }
            if(a==',')
            {
                fin.get(a);
                grids[l][m] = a;
            }

            else
            {
                grids[l][m] = a;
            }
        }
        if(a=='\n')
        {
            break;
        }    
    }

    cout<<endl;

    for (int l=0; l<i; l++)                                                        //Loop for printing grid.
    {
        for (int m=0; m<i; m++) 
        {
            cout << grids[l][m] << " ";
        }

        cout<<endl;
    }

    for(int c=0; c<2; c++)                                                         //Loop for blank line in file.
    {
        char r;
        fin.getline(arr1, '\n');    
    }

    cout << arr1 << endl;

    int x = 43;
    int y = 13;
    int o = 0;

    char** arr2 = new char* [x];

    for(int z=0; z<x; z++)                                                         
    {
        arr2[z] = new char [x];
    }

    while(fin.getline(arr2[o], y, ','))                                            //Reading words in file.
    {
        o++;
    }

    for(int i=0; i<x; i++)                                                         //loop for printing words.
    {
        cout << arr2[i] << endl; 
    }

    fin.close();                                                                   //Closing file.

    char** arr3 = new char* [i];                                                   

    for (int k=0; k<i; k++) 
    {
        arr3[k] = new char [i];
    }

    int q = 0;

        do
        {
            cout << "\nPress any key to search word: ";                                             //Loop fot calling functions on successive key press.
            cin >> s;
		
            auto start = chrono::high_resolution_clock::now();
	
            sfhorizontal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for forward horizontal search.
            cout << endl;

            sbhorizontal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for backward horizontal search.      
            cout << endl;

            sdvertical(grids,15, 15, arr2[q], arr3, 15, 15);                                     //Function for vertical down word search.
            cout << endl;

            suvertical(grids,15, 15, arr2[q], arr3, 15, 15);                                     //Function for vertical up word search.
            cout << endl;

            tlbrdiagonal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for diagonal word search from top left to bottom right.
            cout << endl;

            brtldiagonal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for diagonal word search from bottom right to top left.
            cout << endl;

            trbldiagonal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for diagonal word search from top right to bottom left.
            cout << endl;

            bltrdiagonal(grids,15, 15, arr2[q], arr3, 15, 15);                                   //Function for diagonal word search from bottom left to top right.
            cout << endl;
		
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
            cout << "Time to find word: " << duration.count() << " milliseconds" << endl;

            tsum = tsum + duration.count();

            q++;

        }while(q<42);

    char arr4[15][15];
    char arr5[15][15];
    char arr6[15][15];
    char arr7[15][15];

    for (int l=0; l<i; l++)                                                                     //Loop for printing grid.
    {
        for (int m=0; m<i; m++) 
        {
            if(arr3[l][m] == 0)
            {
                arr4[l][m] = arr3[l][m];
                arr4[l][m] = ' ';
                arr5[l][m] = 'A';
            }
            else
            {
                arr6[l][m] = ' ';
            }
            cout << " "<< RED << arr3[l][m] << RESET;
            cout << arr4[l][m];
        }

        cout<<endl;
    }
    cout<<"\nTELEWORD GRID: \n\n";

    for (int l=0; l<i; l++)                                                                     //Loop for printing grid.
    {
        for (int m=0; m<i; m++) 
        { 
            if(arr5[l][m] == 'A')
            {
                cout << grids[l][m] << " ";
            }
            else
            {
                cout << arr6[l][m] << " ";
            }
        }
        cout << endl;
    }

    cout << "\nTELEWORD is: ";

    for (int l=0; l<i; l++)                                                                     //Loop for printing grid.
    {
        for (int m=0; m<i; m++) 
        { 
            if(arr5[l][m] == 'A')
            {
                cout << grids[l][m];
                arr7[l][m] = grids[l][m];
            }
        }
    }
    cout << "\n\n";

    cout << "Total Time: "<< tsum << endl;                                          //Total time.

    int slen = 0, avgw;

    for(int i=0; i<42; i++)                                                         //loop for adding words length.
    {
        int len = strlen(arr2[i]);
        slen= slen + len;
    }

    cout << endl;

    cout << "Average word length: ";                                               //Avg word length
    avgw = slen/42;
    cout << avgw << endl;
    cout << endl;

    for(int i=0; i<x; i++)                                                                 //Loop for deleting array of words.
    {
        delete [] arr2[i];
    }

        delete [] arr2;
        arr2 = NULL;                                                                      //Undangle.

    for(int k=0; k<i; k++)                                                                //Loop for deleting array of grid.
    {
        delete [] grids[k];
    }

        delete [] grids;
        grids = NULL;                                                                     //Undangle.
        
return 0;    
}