//Gui flood fill test program

#include "GridGui.h" //
#include <iostream> //Basic input output (cout)
#include <string> //strings
#include <fstream> //file output
#include <sstream> //used to convert streams to strings
#include <ostream> //output streams
#include <vector> //vectors
#include <ctime> //time stamps
#include "ccc_x11.h" // Horstmann's Graphics
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
		
		if (y < 1) 
		{//check to see if user clicked the top, which ends the program
			stop = true;
		}
		else 
		{//fill in point if it wasn't the top row
			fileGrid.floodFill(x, y, 2);
		}
		fileGrid.drawGrid();
		cout << fileGrid;
	}
		
  cout<<"\n\n"; //clean up output
  return 0;
}
