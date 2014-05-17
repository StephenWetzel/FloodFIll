
// ----------------------------------------------------------------------------
//
//  Grid class
//    Implementation
//
//  Autogenerated by Class Wizard, by Stephen Wetzel, on April 19, 2014
//
//
// ----------------------------------------------------------------------------
//  Author:        Stephen Wetzel
//  Date:          
//
// ----------------------------------------------------------------------------

#include "Grid.h" //
#include <iostream> //Basic input output (cout)
#include <string> //strings
#include <sstream> //used to convert streams to strings
#include <ostream> //output streams
#include <vector> //vectors
using namespace std;

//--- global constants used for the Grid class

// ------------------------------------------------------
// ----- Constructors -----------------------------------
// ------------------------------------------------------

Grid::Grid()
{//Default constructor
  rows_    = 5; //default to size 5 grid
  columns_ = 5;
	grid_.resize(columns_, vector<int>(rows_, 0)); //create grid of 0's
}

Grid::Grid(
    int  rows,
    int  columns,
    vector< vector<int> > &matrix)
{//Alternate Constructor:
  rows_    = rows;
  columns_ = columns;
  grid_.resize(columns_, vector<int>(rows_, 0)); //create grid of 0's
  
  for (int ii = 0; ii < rows_; ii++)
  {//go through each row
		for (int jj = 0; jj < columns_; jj++)
		{//go through each column in a row and print peg
			grid_[ii][jj] = matrix[ii][jj];
			
			
			
		}
	}
}

Grid::Grid(const Grid &obj)
{//copy constructor
  //grid_    = obj.grid_;
  rows_    = obj.rows_;
  columns_ = obj.columns_;
}

Grid::~Grid()
{//destructor
  grid_.clear();
}

// ------------------------------------------------------
// ----- Inspectors -------------------------------------
// ------------------------------------------------------

int Grid::getRows() const
{
  return rows_;
}
int Grid::getColumns() const
{
  return columns_;
}

// ------------------------------------------------------
// ----- Mutators ---------------------------------------
// ------------------------------------------------------

void Grid::setRows(const int &rows)
{
  rows_ = rows;
}
void Grid::setColumns(const int &columns)
{
  columns_ = columns;
}


// ------------------------------------------------------
// ----- Facilitators -----------------------------------
// ------------------------------------------------------

string Grid::display() const
{//output the grid with formatting	
	char fillSymbol[2] = {'.', 'X'}; //symbols for empty, and filled respectively
	
  ostringstream os; 
  
  os << "\n   ";
	
  for (int ii = 0; ii < rows_; ii++)
  {//go through each row
		os <<"\n";
		for (int jj = 0; jj < columns_; jj++)
		{//go through each column in a row and print peg
			os << "" << fillSymbol[grid_[ii][jj]];
		}
	}
	
	os << "\n";
  return os.str();
}



// ------------------------------------------------------
// ----- Overloaded Operators----------------------------
// ------------------------------------------------------

ostream &operator<< (ostream &out, const Grid &obj)
{
  out<<obj.display(); 
  return out;
}

vector<int> & Grid::operator[] (int ii)
{
	//returns a 1d vector, which then has a regular [] operator that can be used on it
  return grid_[ii];
}


