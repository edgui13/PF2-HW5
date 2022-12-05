//-----------------------------------------------------------
//  Purpose:    Implementation of RealEstateDB class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include "real_estate_db.h"

RealEstateDB::RealEstateDB()
{
    // Empty
}

RealEstateDB::RealEstateDB(const RealEstateDB &real_estate_db)
{
    houses = real_estate_db.houses;
}

RealEstateDB::~RealEstateDB()
{
    // Empty
}

void RealEstateDB::print()
{
    // Loop printing houses
    for (unsigned int i = 0; i < houses.size(); i++)
        houses[i].print();
}

void RealEstateDB::read_txt(string filename)
{
    // Open input file
    ifstream din;
    din.open(filename);
    if (din.fail())
        return;

    // Loop reading houses
    RealEstate house;
    houses.clear();
    while (!din.eof())
    {
        // Read from input file
        house.read_txt(din);

        // Store in vector
        if (!din.eof())
            houses.push_back(house);
    }

    // Close files
    din.close();
}

void RealEstateDB::read_csv(string filename)
{
    // Open input file
    ifstream din;
    din.open(filename);
    if (din.fail())
        return;

    // Loop reading houses
    RealEstate house;
    houses.clear();
    while (!din.eof())
    {
        // Read from input file
        house.read_csv(din);

        // Store in vector
        if (!din.eof())
            houses.push_back(house);
    }

    // Close files
    din.close();
}

void RealEstateDB::write_txt(string filename)
{
    // Open output file
    ofstream dout;
    dout.open(filename);
    if (dout.fail())
        return;

    // Loop writing houses
    for (unsigned int i = 0; i < houses.size(); i++)
        houses[i].write_txt(dout);

    // Close files
    dout.close();
}

void RealEstateDB::write_csv(string filename)
{
    // Open output file
    ofstream dout;
    dout.open(filename);
    if (dout.fail())
        return;

    // Loop writing houses
    for (unsigned int i = 0; i < houses.size(); i++)
        houses[i].write_csv(dout);

    // Close files
    dout.close();
}

void RealEstateDB::PartitionStreet(int low, int high, int &mid)
{
    // Use houses[high] for pivot value
    RealEstate pivot = houses[high];

    // Partition array into two parts
    int left = low;
    int right = high;
    while (left < right)
    {
        // Scan left to right
        while ((left < right) && (houses[left].getStreet() < pivot.getStreet()))
            left++;

        // Scan right to left
        while ((left < right) && (houses[right].getStreet() >= pivot.getStreet()))
            right--;

        // Swap data values
        RealEstate temp = houses[left];
        houses[left] = houses[right];
        houses[right] = temp;
    }

    // Swap pivot to mid
    mid = left;
    houses[high] = houses[mid];
    houses[mid] = pivot;
}

void RealEstateDB::QuickSortStreet(int low, int high)
{
    // Check terminating condition
    if (low < high)
    {
        // Partition data into two parts
        int mid = 0;
        PartitionStreet(low, high, mid);

        // Recursive calls to sort array
        QuickSortStreet(low, mid - 1);
        QuickSortStreet(mid + 1, high);
    }
}

void RealEstateDB::QuickSortStreet()
{
    QuickSortStreet(0, houses.size() - 1);
}

void RealEstateDB::MergeSortPrice(vector<RealEstate> &copy, int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        MergeSortPrice(copy, low, mid);
        MergeSortPrice(copy, mid + 1, high);

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (houses[index1].getPrice() < houses[index2].getPrice())
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

        // Copy data back from the temporary array
        for (index = 0; index < range; index++)
            houses[low + index] = copy[index];
    }
}

void RealEstateDB::MergeSortPrice()
{
    // Allocate memory and call recursive function
    vector<RealEstate> copy(houses);
    MergeSortPrice(copy, 0, houses.size() - 1);
}

void RealEstateDB::SelectionSortSqFt()
{
    // Put largest unsorted value at end of sorted list
    int low = 0;
    int high = houses.size() - 1;
    for (int last = high; last > low; last--)
    {
        // Find index of largest value in unsorted array
        int largest = low;
        for (int index = low + 1; index <= last; index++)
            if (houses[index].getSqFt() > houses[largest].getSqFt())
                largest = index;

        // Swap with last element in unsorted array
        RealEstate temp = houses[last];
        houses[last] = houses[largest];
        houses[largest] = temp;
    }
}

void RealEstateDB::InsertionSortHouseNum()
{
    // Insert each element of unsorted list into sorted list
    int low = 0;
    int high = houses.size() - 1;
    for (int unsorted = low + 1; unsorted <= high; unsorted++)
    {
        // Select unsorted value to be inserted
        RealEstate value = houses[unsorted];
        int posn = unsorted;

        // Make room for new data value
        while ((posn > 0) && (houses[posn - 1].getHouseNum() > value.getHouseNum()))
        {
            houses[posn] = houses[posn - 1];
            posn--;
        }

        // Put new value into array
        houses[posn] = value;
    }
}

// Demonstrate bubble sort on vector of RealEstate objects
void RealEstateDB::BubbleSortZipCode()
{
    // Loop over houses vector "size" times
    int low = 0;
    int high = houses.size() - 1;
    for (int count = low; count < high; count++)
    {
        // Loop over "size" elements in houses vector
        for (int index = low; index < high; index++)
        {
            // Swap two RealEstate objects if zip codes are out of order
            if (houses[index].getZipCode() > houses[index + 1].getZipCode())
            {
                RealEstate temp = houses[index];
                houses[index] = houses[index + 1];
                houses[index + 1] = temp;
            }
        }
    }
}
