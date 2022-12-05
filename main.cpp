//-----------------------------------------------------------
//  Purpose:    Read, Write, and Sort RealEstate objects.
//  Author:     Edgar Alcocer
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "real_estate.h"
#include "real_estate_db.h"
using namespace std;

int main()
{
    int selection;
    RealEstateDB choice;
    // menu interface
    do
    {
        cout << "Welcome to Projet 5" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><>" << endl;
        cout << "1. Read a .txt file" << endl;
        cout << "2. Read a .csv file" << endl;
        cout << "3. Write to a .txt file" << endl;
        cout << "4. Write to a .csv file" << endl;
        cout << "5. Print out vector db of houses" << endl;
        cout << "6. Sort the vector list" << endl;
        cout << "7. Exit the Program" << endl;
        cout << "Selection: ";
        cin >> selection;

        if (cin.fail())
        {
            cout << "Error!, input not recognized" << endl;
            cout << endl;
            return 0;
        }

        if (selection <= 0 || selection >= 8)
        {
            cout << "Error!, please select an option between 1-7" << endl;
            cout << endl;
        }

        switch (selection)
        {
        case 1:
        {
            // read txt file into the db vector
            choice.readTxt();
            cout << "Successfully read .txt data and transferred to vector!" << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            // read csv file into the db vector
            choice.readCsv();
            cout << "Successfully read .csv data and transferred to vector!" << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            // write from the db vector to txt file
            choice.writeTxt();
            cout << "Successfully written vector data to .txt file!" << endl;
            choice.ResetVector();
            cout << endl;
            break;
        }
        case 4:
        {
            // write from the db vector to csv file
            choice.writeCsv();
            cout << "Successfully written vector data to .csv file!" << endl;
            choice.ResetVector();
            cout << endl;
            break;
        }
        case 5:
        {
            // print the current vector
            cout << "Printing out the current vector" << endl;
            choice.Print();
            cout << endl;
            break;
        }
        case 6:
        {
            int sortSelection;
            do
            {
                // sorting menu interface
                cout << "1. Sort by house number" << endl;
                cout << "2. Sort by zipcode" << endl;
                cout << "3. Sort by price" << endl;
                cout << "4. Sort by number of beds" << endl;
                cout << "5. Sort by number of bathrooms" << endl;
                cout << "6. Sort by square footage" << endl;
                cout << "7. Sort by lot size" << endl;
                cout << "8. Go back to MAIN MENU" << endl;

                cout << "Selection: ";
                cin >> sortSelection;

                if (sortSelection <= 0 || sortSelection >= 9)
                {
                    cout << "Error!, please select an option between 1-8" << endl;
                    cout << endl;
                }
                switch (sortSelection)
                {
                case 1:
                {
                    // use selection sort by house number
                    cout << "Selection Sort by House Number" << endl;
                    choice.SelectionSortHouseNum();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 2:
                {
                    // use selection sort by zip code
                    cout << "Selection Sort by ZipCode" << endl;
                    choice.SelectionSortZipCode();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 3:
                {
                    // use selection sort by price
                    cout << "Selection Sort by Price" << endl;
                    choice.SelectionSortPrice();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 4:
                {
                    // use selection sort by number of beds
                    cout << "Selection Sort by Number of Beds" << endl;
                    choice.SelectionSortBed();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 5:
                {
                    // use merge sort by number of baths
                    cout << "Merge Sort by Number of Baths" << endl;
                    choice.MergeSortBath();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 6:
                {
                    // use merge sort by square footage
                    cout << "Merge Sort by Square Footage" << endl;
                    choice.MergeSortSqFt();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 7:
                {
                    // use merge sort by lot size
                    cout << "Merge Sort by Lot Size" << endl;
                    choice.MergeSortLotSize();
                    cout << "Successfully Sorted the Data!" << endl;
                    cout << endl;
                    break;
                }
                case 8:
                {
                    // go back to main menu
                    cout << "Going back to main menu" << endl;
                    break;
                }
                }
            } while (sortSelection != 8);
        }
        case 7:
        {
            // exit program
            cout << endl;
            break;
        }
        }
    } while (selection != 7);
    cout << "Thank you for using Project 5!" << endl;
    return 0;
}