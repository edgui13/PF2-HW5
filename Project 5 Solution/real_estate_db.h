#ifndef REAL_ESTATE_DB_H
#define REAL_ESTATE_DB_H

//-----------------------------------------------------------
//  Purpose:    Declaration of RealEstateDB class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "real_estate.h"
using namespace std;

class RealEstateDB
{
public:
    // Constructors
    RealEstateDB();
    RealEstateDB(const RealEstateDB &real_estate);
    ~RealEstateDB();

    // I/O methods
    void print();
    void read_txt(string filename);
    void read_csv(string filename);
    void write_txt(string filename);
    void write_csv(string filename);

    // Public sorting methods
    void QuickSortStreet();
    void MergeSortPrice();
    void SelectionSortSqFt();
    void InsertionSortHouseNum();
    void BubbleSortZipCode();

private:
    vector<RealEstate> houses;

    // Private sorting methods
    void PartitionStreet(int low, int high, int &mid);
    void QuickSortStreet(int low, int high);
    void MergeSortPrice(vector<RealEstate> &copy, int low, int high);
};

#endif