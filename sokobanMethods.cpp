#include <iostream>
using namespace std;

class SLevel{
	public:
		//variables for level construction
		int row = 0;
		int column = 0;
		string level[20][20];
		

		//variables for player control
		int playerLocX = 0;
		int playerLocY = 0;

		//Box movers
		int tempBY = 0;
		int tempBX = 0;
		
		
		//stores goal locations
		int goalLocY = -1;
		int goalLocX = -1;

	void levelIn(string* lIn, int r, int c) {
		
//store the amount of rows and columns
		row = r;
		
		column = c;
		

// behold the almighty power of google (and geeks for geeks)
//stores the array passed in the constructor into its own array here (i didn't need to make this probably)
	for (int y = 0; y < r; y++){
		for (int x = 0; x < c; x++){
			level[y][x] = *((lIn + y * c) + x);
			

				
				//locates the player character
				if(level[y][x] == "@")
				{
					playerLocX = x;
					playerLocY = y;
					

				}
				else if(level[y][x] == "$")
				{
					goalLocY = y;
					goalLocX = x;
					

				}
			}	
		}
	}
	
	void levelOut(){
		for (int y = 0; y < row; y++){
			for(int x = 0; x < column; x++){
				cout << level[y][x] << " ";
			}
			cout << "\n";
		}

	}
	
	void playerInput(char input){
		switch(input){
			
			case 'w':
				//moves character up
				
				//checks for colision with a wall, end of the array values, or box, in that order
				//probably way too large of if statement logic but it works lol
				if(playerLocY == 0 || level[playerLocY-1][playerLocX] == "#" || level[playerLocY-1][playerLocX] == "o" && level[playerLocY-2][playerLocX] == "#" || level[playerLocY-1][playerLocX] == "o" && playerLocY-2 < 0 || level[playerLocY-1][playerLocX] == "o" && level[playerLocY-2][playerLocX] == "o")
				{
					cout << "\nUnable to move player\n";
					cout <<	"------------------\n";
				}
				//checks for colision with a box, then moves both player and box
				else if(level[playerLocY-1][playerLocX] == "o" || level[playerLocY-1][playerLocX] == "0")
				{
					//moves box and player
					tempBY = playerLocY-2;
					tempBX = playerLocX;
					
						level[tempBY][tempBX] = "o";
						
						level[playerLocY-1][playerLocX] = "@";
						

						level[playerLocY][playerLocX] = "*";
						playerLocY--;
					
				}
				//just moves the character
				else
				{
					//moves the character without moving the box
					level[playerLocY-1][playerLocX] = "@";
					level[playerLocY][playerLocX] = "*";
					playerLocY--;
				}
				break;
				
				
			case 'a':
				//moves character to the left
				
				//check for colision with a wall, or end of the array
				if(playerLocX == 0 || level[playerLocY][playerLocX-1] == "#" || level[playerLocY][playerLocX-1] == "o" && level[playerLocY][playerLocX-2] == "#" || level[playerLocY][playerLocX-1] == "o" && playerLocX-2 < 0 || level[playerLocY][playerLocX-1] == "o" && level[playerLocY][playerLocX-2] == "o")
				{
					cout << "\nUnable to move player\n";
					cout <<	"------------------\n";
				}
				
				else if(level[playerLocY][playerLocX-1] == "o" || level[playerLocY][playerLocX-1] == "0")
				{
					//moves box and player
					tempBY = playerLocY;
					tempBX = playerLocX-2;
					
						level[tempBY][tempBX] = "o";
						
						level[playerLocY][playerLocX-1] = "@";
						

						level[playerLocY][playerLocX] = "*";
						playerLocX--;
					
				}
				else
				{
					level[playerLocY][playerLocX-1] = "@";
					level[playerLocY][playerLocX] = "*";
					playerLocX--;
				}
				
				break;
				
			case 's':
				//moves character down
				
				//checks for colision with a wall, or the end of the array
				if(playerLocY == 0 || level[playerLocY+1][playerLocX] == "#" || level[playerLocY+1][playerLocX] == "o" && level[playerLocY+2][playerLocX] == "#" || level[playerLocY+1][playerLocX] == "o" && playerLocY+2 < 0 || level[playerLocY+1][playerLocX] == "o" && level[playerLocY+2][playerLocX] == "o")
				{
					cout << "\nUnable to move player\n";
					cout <<	"------------------\n";
				}
				
				else if(level[playerLocY+1][playerLocX] == "o" || level[playerLocY+1][playerLocX] == "0")
				{
					//moves box and player
					tempBY = playerLocY+2;
					tempBX = playerLocX;
					
						level[tempBY][tempBX] = "o";
						
						level[playerLocY+1][playerLocX] = "@";
						

						level[playerLocY][playerLocX] = "*";
						playerLocY++;
					
				}
				else
				{
					level[playerLocY+1][playerLocX] = "@";
					level[playerLocY][playerLocX] = "*";
					playerLocY++;
				}
				break;
				
			case 'd':
				//moves character to the right
				
				//check for colision with a wall, or end of the array
				if(playerLocX == 0 || level[playerLocY][playerLocX+1] == "#" || level[playerLocY][playerLocX+1] == "o" && level[playerLocY][playerLocX+2] == "#" || level[playerLocY][playerLocX+1] == "o" && playerLocX+2 < 0 || level[playerLocY][playerLocX+1] == "o" && level[playerLocY][playerLocX+2] == "o")
				{
					cout << "\nUnable to move player\n";
					cout <<	"------------------\n";
				}
				
				else if(level[playerLocY][playerLocX+1] == "o")
				{
					//moves box and player
					tempBY = playerLocY;
					tempBX = playerLocX+2;
					
						level[tempBY][tempBX] = "o";
						
						level[playerLocY][playerLocX+1] = "@";
						

						level[playerLocY][playerLocX] = "*";
						playerLocX++;
					
				}
				else
				{
					level[playerLocY][playerLocX+1] = "@";
					level[playerLocY][playerLocX] = "*";
					playerLocX++;
				}
				break;
				
			//skips the level in case of emergency
			case 'r':
				level[playerLocY][playerLocX] = level[goalLocY][goalLocX];
				break;
				
			default:
				//doesn't move the character, tells player valid inputs
				cout << "\nenter valid input (W A S D R)\n";
				cout <<	"------------------\n";
				break;
			}
		
	}
	
	void clearLvl(){
			for (int y = 0; y <= row; y++){
				for(int x = 0; x <= column; x++){
					level[y][x] = " ";
					}
			}
	}
	
	bool playerVictory(){
		if(level[playerLocY][playerLocX] == level[goalLocY][goalLocX])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


