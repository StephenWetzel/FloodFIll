
//Test Program for Grid class
//  Autogenerated by Class Wizard, by Stephen Wetzel, on April 19, 2014

#include "GridGui.h" //
#include <iostream> //Basic input output (cout)
#include <string> //strings
#include <fstream> //file output
#include <sstream> //used to convert streams to strings
#include <ostream> //output streams
#include <vector> //vectors
#include <ctime> //time stamps
#include "ccc_x11.h"
#include "ccc_shap.h"
using namespace std;


int ccc_win_main(void)
{	
	Grid fileGrid("sample.txt");
	bool stop = false;
		
	while (!stop)
	{
		int x;
		int y;
		cout << fileGrid;
		
		fileGrid.drawGrid(); //draw grid on gui
		fileGrid.getClick(x, y); //get mouse click
		if (y < 1) stop = true;
		fileGrid.floodFill(x, y, 2);
		fileGrid.drawGrid();
		
	}
		
  cout<<"\n\n"; //clean up output
  return 0;
}
