//-----------------------------------------------------------
//  Purpose:    Read and Write RealEstate objects.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "real_estate_db.h"
using namespace std;

int main()
{
    RealEstateDB database;

    // Testing quick sort by street on txt file
    database.read_txt("houses_small.txt");
    database.QuickSortStreet();
    database.write_txt("sort_street.txt");

    // Testing insertion sort by house num on csv file
    database.read_csv("houses_small.csv");
    database.InsertionSortHouseNum();
    database.write_csv("sort_house_num.csv");

    // Testing merge sort by price on txt file
    database.read_txt("houses_big.txt");
    database.MergeSortPrice();
    database.write_txt("sort_price.txt");

    // Testing selection sort by sq ft on csv file
    database.read_csv("houses_big.csv");
    database.SelectionSortSqFt();
    database.write_csv("sort_sq_ft.csv");

    return 0;
}