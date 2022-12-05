#ifndef REAL_ESTATE_DB_H
#define REAL_ESTATE_DB_H

//-----------------------------------------------------------
// Purpose: Header file for the estate db class.
// Author:  Edgar Alcocer
//-----------------------------------------------------------
#include <ctime>
#include <cstdlib>
#include <vector>
#include "real_estate.h"
using namespace std;

//-----------------------------------------------------------
// Define the estate db class interface
//-----------------------------------------------------------
class RealEstateDB
{
public:
    // Constructor and destructor
    RealEstateDB();
    RealEstateDB(const RealEstateDB &db);
    ~RealEstateDB();

    // Public methods
    void readTxt();
    void readCsv();
    void writeTxt();
    void writeCsv();
    void Print();
    void ResetVector();

    void SelectionSortHouseNum();
    void SelectionSortZipCode();
    void SelectionSortPrice();
    void SelectionSortBed();

    void MergeSortBath();
    void MergeSortBath2(RealEstate copy[], int low, int high);
    void MergeSortSqFt();
    void MergeSortSqFt2(RealEstate copy[], int low, int high);
    void MergeSortLotSize();
    void MergeSortLotSize2(RealEstate copy[], int low, int high);

private:
    vector<RealEstate> houses;
};
#endif