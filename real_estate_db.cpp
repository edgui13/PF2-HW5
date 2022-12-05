//-----------------------------------------------------------
//  Purpose:    Implementation of real estate db class.
//  Author:     Edgar Alcocer
//-----------------------------------------------------------
#include "real_estate_db.h"

//-----------------------------------------------------------
RealEstateDB::RealEstateDB()
{
}

//-----------------------------------------------------------
RealEstateDB::RealEstateDB(const RealEstateDB &db)
{
    int size = int(db.houses.size());
    for (int i = 0; i < size; i++)
        houses.push_back(db.houses[i]);
}

//-----------------------------------------------------------
RealEstateDB::~RealEstateDB()
{
}

//------------------------------------------------------------------
// Read a .txt file
//------------------------------------------------------------------
void RealEstateDB::readTxt()
{
    // read a .txt file
    // Open input file
    RealEstate house;
    string fileName;
    ifstream din;
    cout << "Which .txt file would you like to read?" << endl;
    cin >> fileName;
    din.open(fileName);
    if (din.fail())
        cout << "Error!, input not recognized" << endl;
    // Loop reading houses
    while (!din.eof())
    {
        // Read from input file
        house.read_txt(din);
        if (!din.eof())
        {
            // Store in vector
            houses.push_back(house);
            // house.print();
        }
    }
    din.close();
}

//------------------------------------------------------------------
// Read a .csv file
//------------------------------------------------------------------
void RealEstateDB::readCsv()
{

    // Open input file
    RealEstate house;
    string fileName;
    ifstream din;
    cout << "Which .csv file would you like to read?" << endl;
    cin >> fileName;
    din.open(fileName);
    if (din.fail())
        cout << "Error!, input not recognized" << endl;
    // Loop reading houses
    while (!din.eof())
    {
        // Read from input file
        house.read_csv(din);
        if (!din.eof())
        {
            // Store in vector
            houses.push_back(house);
            // house.print();
        }
    }
    din.close();
}

//------------------------------------------------------------------
// Write to .txt file
//------------------------------------------------------------------
void RealEstateDB::writeTxt()
{
    // Open output file
    string fileName;
    ofstream dout;
    cout << "Which .txt file would you like to write to?" << endl;
    cin >> fileName;
    dout.open(fileName);
    if (dout.fail())
        cout << "Error!, input not recognized" << endl;
    // Loop writing houses
    for (int i = 0; i < houses.size(); i++)
        houses[i].write_txt(dout);
    dout.close();
}
//------------------------------------------------------------------
// Write to .csv file
//------------------------------------------------------------------
void RealEstateDB::writeCsv()
{
    // Open output file
    string fileName;
    ofstream dout;
    cout << "Which .csv file would you like to write to?" << endl;
    cin >> fileName;
    dout.open(fileName);
    if (dout.fail())
        cout << "Error!, input not recognized" << endl;
    // Loop writing houses
    for (int i = 0; i < houses.size(); i++)
        houses[i].write_csv(dout);
    dout.close();
}

//------------------------------------------------------------------
// Print the current real estate vector
//------------------------------------------------------------------
void RealEstateDB::Print()
{
    for (int i = 0; i < houses.size(); i++)
    {
        cout << "HouseNum:  " << houses[i].getHouseNum() << endl
             << "Street:    " << houses[i].getStreet() << endl
             << "City:      " << houses[i].getCity() << endl
             << "State:     " << houses[i].getState() << endl
             << "ZipCode:   " << houses[i].getZipCode() << endl
             << "Price:     " << houses[i].getPrice() << endl
             << "Bed:       " << houses[i].getBed() << endl
             << "Bath:      " << houses[i].getBath() << endl
             << "SqFt:      " << houses[i].getSqFt() << endl
             << "LotSize:   " << houses[i].getLotSize() << endl
             << endl;
    }
}
//------------------------------------------------------------------
void RealEstateDB::ResetVector()
{
    houses.clear();
}
//------------------------------------------------------------------
// Selection sort algorithm for house number
//------------------------------------------------------------------
void RealEstateDB::SelectionSortHouseNum()
{
    int low = 0;
    int high = houses.size() - 1;
    // Put largest unsorted value at end of sorted list
    for (int last = high; last > low; last--)
    {
        // Find index of largest value in unsorted array
        int largest = low;
        for (int index = low + 1; index <= last; index++)
            if (houses[index].getHouseNum() > houses[largest].getHouseNum())
                largest = index;

        // Swap with last element in unsorted array
        RealEstate temp = houses[last];
        houses[last] = houses[largest];
        houses[largest] = temp;
    }
}
//------------------------------------------------------------------
// Selection sort algorithm for zip code
//------------------------------------------------------------------
void RealEstateDB::SelectionSortZipCode()
{
    int low = 0;
    int high = houses.size() - 1;
    // Put largest unsorted value at end of sorted list
    for (int last = high; last > low; last--)
    {
        // Find index of largest value in unsorted array
        int largest = low;
        for (int index = low + 1; index <= last; index++)
            if (houses[index].getZipCode() > houses[largest].getZipCode())
                largest = index;

        // Swap with last element in unsorted array
        RealEstate temp = houses[last];
        houses[last] = houses[largest];
        houses[largest] = temp;
    }
}
//------------------------------------------------------------------
// Selection sort algorithm for prices
//------------------------------------------------------------------
void RealEstateDB::SelectionSortPrice()
{
    int low = 0;
    int high = houses.size() - 1;
    // Put largest unsorted value at end of sorted list
    for (int last = high; last > low; last--)
    {
        // Find index of largest value in unsorted array
        int largest = low;
        for (int index = low + 1; index <= last; index++)
            if (houses[index].getPrice() > houses[largest].getPrice())
                largest = index;

        // Swap with last element in unsorted array
        RealEstate temp = houses[last];
        houses[last] = houses[largest];
        houses[largest] = temp;
    }
}
//------------------------------------------------------------------
// Selection sort algorithm for number of bedrooms
//------------------------------------------------------------------
void RealEstateDB::SelectionSortBed()
{
    int low = 0;
    int high = houses.size() - 1;
    // Put largest unsorted value at end of sorted list
    for (int last = high; last > low; last--)
    {
        // Find index of largest value in unsorted array
        int largest = low;
        for (int index = low + 1; index <= last; index++)
            if (houses[index].getBed() > houses[largest].getBed())
                largest = index;

        // Swap with last element in unsorted array
        RealEstate temp = houses[last];
        houses[last] = houses[largest];
        houses[largest] = temp;
    }
}

//------------------------------------------------------------------
// Mergesort implementation with copy array for number of bathrooms
//------------------------------------------------------------------
void RealEstateDB::MergeSortBath2(RealEstate copy[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        MergeSortBath2(copy, low, mid);
        MergeSortBath2(copy, mid + 1, high);

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (houses[index1].getBath() < houses[index2].getBath())
                copy[index++] = houses[index1++];
            else
                copy[index++] = houses[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = houses[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = houses[index2++];

        // Copy houses back from the temporary array
        for (index = 0; index < range; index++)
            houses[low + index] = copy[index];
    }
}

//------------------------------------------------------------------
// Mergesort implementation without copy array for number of bathrooms
// Best case O(NlogN) - random data
// Worst case O(NlogN) - random data
// Average case O(NlogN) - random data
//------------------------------------------------------------------
void RealEstateDB::MergeSortBath()
{
    int low = 0;
    int high = houses.size() - 1;
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Allocate memory and call merge_sort2
        RealEstate *copy = new RealEstate[range];
        MergeSortBath2(copy, low, high);
        // delete copy
    }
}

//------------------------------------------------------------------
// Mergesort implementation with copy array for square footage
//------------------------------------------------------------------
void RealEstateDB::MergeSortSqFt2(RealEstate copy[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        MergeSortSqFt2(copy, low, mid);
        MergeSortSqFt2(copy, mid + 1, high);

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (houses[index1].getSqFt() < houses[index2].getSqFt())
                copy[index++] = houses[index1++];
            else
                copy[index++] = houses[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = houses[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = houses[index2++];

        // Copy houses back from the temporary array
        for (index = 0; index < range; index++)
            houses[low + index] = copy[index];
    }
}

//------------------------------------------------------------------
// Mergesort implementation without copy array for square footage
// Best case O(NlogN) - random data
// Worst case O(NlogN) - random data
// Average case O(NlogN) - random data
//------------------------------------------------------------------
void RealEstateDB::MergeSortSqFt()
{
    int low = 0;
    int high = houses.size() - 1;
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Allocate memory and call merge_sort2
        RealEstate *copy = new RealEstate[range];
        MergeSortSqFt2(copy, low, high);
        // delete copy;
    }
}
//------------------------------------------------------------------
// Mergesort implementation with copy array for lot size
//------------------------------------------------------------------
void RealEstateDB::MergeSortLotSize2(RealEstate copy[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        MergeSortLotSize2(copy, low, mid);
        MergeSortLotSize2(copy, mid + 1, high);

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (houses[index1].getLotSize() < houses[index2].getLotSize())
                copy[index++] = houses[index1++];
            else
                copy[index++] = houses[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = houses[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = houses[index2++];

        // Copy houses back from the temporary array
        for (index = 0; index < range; index++)
            houses[low + index] = copy[index];
    }
}

//------------------------------------------------------------------
// Mergesort implementation without copy array for lot size
// Best case O(NlogN) - random data
// Worst case O(NlogN) - random data
// Average case O(NlogN) - random data
//------------------------------------------------------------------
void RealEstateDB::MergeSortLotSize()
{
    int low = 0;
    int high = houses.size() - 1;
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Allocate memory and call merge_sort2
        RealEstate *copy = new RealEstate[range];
        MergeSortLotSize2(copy, low, high);
        // delete copy;
    }
}