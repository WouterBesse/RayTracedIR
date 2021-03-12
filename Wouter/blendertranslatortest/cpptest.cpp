#include <iostream>
#include <vector>

// A simple class with a constuctor and some methods...

class DataSorter
{
   public:
       DataSorter(int);
       void insert(int, float, float, float);
       int foobar(int);
   private:
       int val;
       std::vector<std::vector<std::vector<float>>> facelist;
};

// Sets up the vector, gets the amount of face vectors it needs to make and the amount of vertices each face has
DataSorter::DataSorter(int n)
{
   val = n;
   int i = 0;
   while (i < n) {
     std::vector<std::vector<float>> facevex;
     int x = 0;
     facelist.push_back(facevex);
     i++;
   }

}

// Receives data, which face, which vertex and the value of the vertex
void DataSorter::insert(int n, float vexx, float vexy, float vexz)
{
  std::vector<float> blankco {vexx,vexy,vexz};
  facelist[n].push_back(blankco);
  std::cout << facelist[0][0][0];
  std::cout << "\n";
  std::cout << "KAAS \n";
}

int DataSorter::foobar(int n)
{
   return val + n;
}

// Define C functions for the C++ class - as ctypes can only talk to C...
extern "C"
{
   DataSorter* DataSorter_new(int n) {return new DataSorter(n);}
   void DataSorter_insert(DataSorter* DataSorter, int n, float vexx, float vexy, float vexz) {DataSorter->insert(n, vexx, vexy, vexz);}
   int Foo_foobar(DataSorter* DataSorter, int n) {return DataSorter->foobar(n);}
}

// int main(){}
