
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
#include <fstream> //file output
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

Grid::Grid(string fileName)
{//Build grid from file
	int rows=1;
	int columns=1;
	int ii = 0;
	int jj = 0;
  grid_.resize(rows, vector<int>(columns, 0)); //create grid of 0's  
	char ch; //one char from the input file
	ifstream inFile(fileName);
	if (inFile.is_open())
	{//check to see if file successfully opened
		while (inFile >> noskipws >> ch)
		{//go through file char by char
			if (ch == '1')
			{//a filled cell
				grid_[ii][jj] = 1;
				jj++;
			}
			else if (ch == '0')
			{//an empty cell
				grid_[ii][jj] = 0;
				jj++;
			}
			else if (ch == '\n')
			{//newline
				ii++;
				jj=0;
			}
			
			if (ii >= rows)
			{//resize grid to add a new row
				rows = ii+1;
				grid_.resize(rows);
				grid_[ii].resize(columns);
			}
			if (jj >= columns)
			{//resize grid to add a new column
				columns = jj+1;
				grid_[ii].resize(columns);
			}
		}
		inFile.close();
		rows_    = rows-1;
		columns_ = columns-1;
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
void Grid::floodFill(int x, int y, int fillType)
{	
	//boundaries:
	if (x > columns_ || x < 0) return;
	if (y > rows_ || y < 0) return;
	
	if (grid_[y][x])
	{//already filled in
		return;
	}
	else
	{//fill it in
		grid_[y][x] = fillType;
		this->floodFill(x  , y+1, fillType); //above
		this->floodFill(x+1, y  , fillType); //to the right
		this->floodFill(x  , y-1, fillType); //below
		this->floodFill(x-1, y  , fillType); //to the left
	}
	return;
}

// ------------------------------------------------------
// ----- Facilitators -----------------------------------
// ------------------------------------------------------

string Grid::display() const
{//output the grid with formatting	
	char fillSymbol[4] = {' ', 'X', '.', 'O'}; //symbols for empty, and filled respectively
	
  ostringstream os; 
  
  os << "\n   ";
	
  for (int ii = 0; ii < rows_; ii++)
  {//go through each row
		os <<"\n";
		for (int jj = 0; jj < columns_; jj++)
		{//go through each column in a row and print cell
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


