#include "util.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cmath>     
#include <fstream>    

using namespace std;

int score = 0;
int level = 1;
int lives = 3;
int progress = 0;
int f = 0;
int moves = 30;
int MenuOption = 0;
int x[4] = { 0, 0, 0, 0 };
int arr[10][10] = { 0 };


void setLevel(int l) {
	level = l;
}

void setProgress(int p) {
	progress = p;
}
void setScore(int s) {
	score = s;
}

void incScore() {
	score++;
}

int getF() {
	return f;
}
void setF(int F) {
	f = F;
}
void setLives(int l) {
	lives = l;
}
int getLives() {
	return lives;
}
void incProgress() {
	progress++;
}
bool incLevel() {
	if (progress >= 31) {
		level++;
		f = 0;
		progress = 0;
		return 1;
	}
	return 0;
}
int getLevel() {
	return level;
}
int getScore() {
	return score;
}
int getProgress() {
	return progress;
}


int getMoves() {
	return moves;
}
void setMoves(int m) {
	moves = m;
}
void decMoves() {
	moves--;
}

int time1 = 100;
void time1Mode() {

	time1--;
}
void settime1(int t) {
	time1 = t;
}
int gettime1() {
	return time1;
}

bool option = 0;

int getOption() {
	return option;
}
void setOption(int o) {
	option = o;
}

void setMenuOption(int o) {
	MenuOption = o;
}
int getMenuOption() {
	return MenuOption;
}

// main menu display
void MenuDisplay() {
	if (MenuOption == 0) {
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); // Update the colors

		DrawString(230, 100, "Press the mentioned number to Enter", colors[RED]);



		DrawLine(100, 705, 135, 705, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(100, 705, 100, 650, 5, colors[THISTLE]);
		DrawLine(100, 650, 135, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(135, 675, 135, 650, 5, colors[THISTLE]);

		DrawLine(160, 705, 160, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(160, 705, 195, 705, 5, colors[THISTLE]);
		DrawLine(160, 675, 195, 675, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(160, 650, 195, 650, 5, colors[THISTLE]);

		DrawLine(220, 705, 220, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(220, 705, 245, 670, 5, colors[THISTLE]);
		DrawLine(270, 705, 245, 670, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(270, 705, 270, 650, 5, colors[THISTLE]);

		DrawLine(295, 705, 345, 705, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(295, 675, 345, 675, 5, colors[THISTLE]);
		DrawLine(295, 705, 295, 675, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(345, 650, 345, 675, 5, colors[THISTLE]);
		DrawLine(295, 650, 345, 650, 5, colors[MEDIUM_VIOLET_RED]);

		DrawLine(380, 705, 420, 705, 5, colors[THISTLE]);
		DrawLine(380, 705, 380, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(380, 650, 420, 650, 5, colors[THISTLE]);

		DrawLine(445, 705, 445, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(445, 705, 485, 705, 5, colors[THISTLE]);
		DrawLine(445, 675, 485, 675, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(485, 705, 485, 675, 5, colors[THISTLE]);
		DrawLine(465, 675, 485, 650, 5, colors[MEDIUM_VIOLET_RED]);

		DrawLine(510, 705, 510, 650, 5, colors[THISTLE]);
		DrawLine(510, 650, 550, 650, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(550, 705, 550, 650, 5, colors[THISTLE]);

		DrawLine(575, 705, 625, 705, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(575, 675, 625, 675, 5, colors[THISTLE]);
		DrawLine(575, 705, 575, 675, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(625, 650, 625, 675, 5, colors[THISTLE]);
		DrawLine(575, 650, 625, 650, 5, colors[MEDIUM_VIOLET_RED]);

		DrawLine(650, 705, 650, 650, 5, colors[THISTLE]);
		DrawLine(650, 675, 690, 675, 5, colors[MEDIUM_VIOLET_RED]);
		DrawLine(690, 705, 690, 650, 5, colors[THISTLE]);

		DrawString(350, 550, "1.Start New Game", colors[THISTLE]);
		DrawString(350, 500, "2.Levels", colors[MEDIUM_VIOLET_RED]);
		DrawString(350, 450, "3.Level Modes", colors[MEDIUM_VIOLET_RED]);
		DrawString(350, 400, "4.Instructions", colors[THISTLE]);
		DrawString(350, 350, "5.HighScores", colors[MEDIUM_VIOLET_RED]);
		DrawString(350, 300, "6.Exit", colors[THISTLE]);

		glutSwapBuffers(); // do not modify this line
	}
}

string playerName;
const int MAX_HIGH_SCORES = 4; // Max number of high scores
string highScoreNames[MAX_HIGH_SCORES];
int highScores[MAX_HIGH_SCORES];

//taking name as input 
void name() {
	if (MenuOption == 1) {
		glClearColor(0, 0, 0, 0); // Black background
		glClear(GL_COLOR_BUFFER_BIT); // Update the colors

		// Border around the screen
		DrawLine(135, 135, 135, 705, 5, colors[THISTLE]);
		DrawLine(135, 135, 705, 135, 5, colors[THISTLE]);
		DrawLine(705, 135, 705, 705, 5, colors[THISTLE]);
		DrawLine(135, 705, 705, 705, 5, colors[THISTLE]);

		// "Enter Your Name" text
		DrawString(310, 450, "Enter Your Name", colors[WHITE]);

		// Input box
		DrawRectangle(250, 400, 300, 40, colors[THISTLE]);
		DrawString(260, 410, playerName, colors[WHITE]); // Player name text

		glutSwapBuffers();
	}
}

/*this function reads the high scores from a file called "highscore.txt" and stores them in two arrays: one for the names of the players (highScoreNames) and another for their scores (highScores). It stops reading when it reaches the max no of high scores (MAX_HIGH_SCORES) or when there are no more scores in the file*/

void readScores() {
    ifstream infile("highscore.txt");
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
    
        if (!(infile >> highScoreNames[i] >> highScores[i])) {
            break; 
        }
    }
    infile.close();
}

/*this function writes the high scores stored in the arrays highScoreNames and highScores to the "highscore.txt" file. It writes each player's name and score on a new line in the file*/

void writeScores() {
    ofstream outfile("highscore.txt");
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        // Write high score name and score to file
        outfile << highScoreNames[i] << " " << highScores[i] << endl;
    }
    outfile.close();
}

/*this function updates the high scores with a new score and name. It first reads the current high scores from the file using readScores() then it checks if the new score is higher than any of the existing scores. If it is, it shifts the existing scores down to make space for the new score. then it saves the updated high scores to the file using writeScores()*/
// simple update (not for time mode)

void updateHighScores(const string& name, int score) {

    readScores();  
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        // Finding the correct position to insert the new score
        if (score > highScores[i]) {
            // Shifting existing scores down to make space for the new score
            for (int j = MAX_HIGH_SCORES - 1; j > i; j--) {
                highScores[j] = highScores[j - 1];
                highScoreNames[j] = highScoreNames[j - 1];
            }
            // Inserting the new score
            highScores[i] = score;
            highScoreNames[i] = name;
            break;
        }
    }
    writeScores();  
}


/*this function displays the high scores on the screen. If the MenuOption is 5, it clears the screen and then iterates over the high scores. For each high score, it creates a string with the player's rank (i+1), name, score, and displays it. out of loop, displays an option to exit the high score display.*/

//it would create a string like "1. PlayerName: 100".

void DisplayHighscore() {
    if (MenuOption == 5) {
        readScores(); 
        glClear(GL_COLOR_BUFFER_BIT);
        int yPos = 550;
        // Display each high score with its rank
        for (int i = 0; i < MAX_HIGH_SCORES; i++) {
            string displayString = to_string(i+1) + ". " + highScoreNames[i] + ": " + to_string(highScores[i]);
            DrawString(350, yPos, displayString, colors[MISTY_ROSE]);
            yPos -= 50;
        }
        DrawString(350, 300, "1.Exit", colors[RED]);
        glutSwapBuffers();
    }
}


void Restart() {
	f = 0;
	level = 1;
	progress = 0;
	lives = 3;
	score = 0;
	time1 = 100;
	moves = 30;
}

// this highscore function is for time mode 
void HighScore(int scor = score)
{
	if (MenuOption == 6) {

int temp1 = 0, temp2 = 0;
ifstream infile("highscore.txt");

// converting the address of the x array (which is an int* pointer) into a char* pointer, which is what read expects.
infile.read(reinterpret_cast<char*>(&x), sizeof(x));

infile.close();
  
for (int i = 0; i < 4; ++i) {

//If scor is greater than any of the existing scores, it inserts scor into the correct position in the array x by shifting 
//the existing scores down to make space for the new score

  if (scor > x[i]) {
  temp1 = x[i];
  x[i] = scor;
  for (int j = i; j < 3; ++j) {
  temp2 = x[j + 1];
  x[j + 1] = temp1;
  temp1 = temp2;
                 }
    break;
	}
	}
		ofstream outfile("highscore.txt");

		outfile.write(reinterpret_cast<char*>(&x), sizeof(x));

		outfile.close();
	}
}

// if button 6 is pressed then displaying game over

void GameOver() {
	if (MenuOption == 6) {

		//HighScore();
		updateHighScores(playerName, score);
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135, 135, 135, 705, 5, colors[WHITE]);
		DrawLine(135, 135, 705, 135, 5, colors[WHITE]);
		DrawLine(705, 135, 705, 705, 5, colors[WHITE]);
		DrawLine(135, 705, 705, 705, 5, colors[WHITE]);

		DrawString(350, 650, "GAME OVER", colors[RED]);

		DrawString(350, 550, "1.Start New Game", colors[MISTY_ROSE]);
		DrawString(350, 500, "2.Levels", colors[MISTY_ROSE]);
		DrawString(350, 450, "3.Level Modes", colors[MISTY_ROSE]);
		DrawString(350, 400, "4.Instructions", colors[MISTY_ROSE]);
		DrawString(350, 350, "5.HighScores", colors[MISTY_ROSE]);
		DrawString(350, 300, "6.Exit", colors[MISTY_ROSE]);
		
		Restart();
		glutSwapBuffers();
	}
}

// if p is pressed game is paused and if p is pressed again game 
// is resumed

void Pause() {
	if (MenuOption == 7) {
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors

		DrawLine(135, 135, 135, 705, 5, colors[WHITE]);
		DrawLine(135, 135, 705, 135, 5, colors[WHITE]);
		DrawLine(705, 135, 705, 705, 5, colors[WHITE]);
		DrawLine(135, 705, 705, 705, 5, colors[WHITE]);

		DrawString(350, 650, "Pause", colors[GREEN]);
		DrawString(350, 550, "1.Continue", colors[MISTY_ROSE]);
		DrawString(350, 500, "2.Start a New Game", colors[MISTY_ROSE]);
		DrawString(350, 450, "3.Instructions", colors[MISTY_ROSE]);
		DrawString(350, 400, "4.HighScores", colors[MISTY_ROSE]);
		DrawString(350, 350, "5.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}
}

void instruction() {
	if (MenuOption == 4) {
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135, 135, 135, 705, 5, colors[WHITE]);
		DrawLine(135, 135, 705, 135, 5, colors[WHITE]);
		DrawLine(705, 135, 705, 705, 5, colors[WHITE]);
		DrawLine(135, 705, 705, 705, 5, colors[WHITE]);

		DrawString(200, 650, "Crush gems by swiping over three matching", colors[MISTY_ROSE]);
		DrawString(200, 600, "pieces of gem in a row or column. You can match ", colors[MISTY_ROSE]);
		DrawString(200, 550, "more than three pieces in a  row or column in a ", colors[MISTY_ROSE]);
		DrawString(200, 500, "connected shape. Once you crush a column or", colors[MISTY_ROSE]);
		DrawString(200, 450, "row of gems, the row or column will disappear and ", colors[MISTY_ROSE]);
		DrawString(200, 400, "the gems above the row will drop down.", colors[MISTY_ROSE]);
		DrawString(350, 350, "1.Exit", colors[RED]);

		glutSwapBuffers(); // do not modify this line..
	}
}


void levels() {
	if (MenuOption == 2) {
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		//		if()
		DrawLine(135, 135, 135, 705, 5, colors[WHITE]);
		DrawLine(135, 135, 705, 135, 5, colors[WHITE]);
		DrawLine(705, 135, 705, 705, 5, colors[WHITE]);
		DrawLine(135, 705, 705, 705, 5, colors[WHITE]);
		int f = level;
		if (f == 1) {
			DrawSquare(330, 555, 10, colors[RED]);
		}
		else if (f == 2) {
			DrawSquare(330, 505, 10, colors[RED]);
		}
		else if (f == 3) {
			DrawSquare(330, 455, 10, colors[RED]);
		}
		else if (f == 4) {
			DrawSquare(330, 405, 10, colors[RED]);
		}
		else if (f == 5) {
			DrawSquare(330, 355, 10, colors[RED]);
		}
		DrawString(350, 550, "1.level 1", colors[MISTY_ROSE]);
		DrawString(350, 500, "2.level 2", colors[MISTY_ROSE]);
		DrawString(350, 450, "3.level 3", colors[MISTY_ROSE]);
		DrawString(350, 400, "4.level 4", colors[MISTY_ROSE]);
		DrawString(350, 350, "5.level 5", colors[MISTY_ROSE]);
		DrawString(350, 300, "6.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}

}

void levelModes() {
	if (MenuOption == 3) {
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135, 135, 135, 705, 5, colors[WHITE]);
		DrawLine(135, 135, 705, 135, 5, colors[WHITE]);
		DrawLine(705, 135, 705, 705, 5, colors[WHITE]);
		DrawLine(135, 705, 705, 705, 5, colors[WHITE]);
		int f = option;
		if (f == 0) {
			DrawSquare(330, 485, 10, colors[RED]);
		}
		else if (f == 1) {
			DrawSquare(330, 435, 10, colors[RED]);
		}
		DrawString(350, 480, "1.Normal Mode", colors[MISTY_ROSE]);
		DrawString(350, 430, "2.time Trail Mode", colors[MISTY_ROSE]);
		DrawString(350, 380, "3.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}
}

// will basically form combination of 9 
bool isMatching()
{
    bool flag = 0;
    // loop for checking 3, 4 and 5 elements matching in a row
    for (int i = 2; i < 10; i++)
    {
     for (int j = 2; j < 8; j++)
     {
     int condition = 0;
     // Checking for 5 elements in a row
     if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4] && j < 6)
     {
         condition = 5;
     }
     // Checking for 4 elements in a row
     else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && j < 7)
     {
         condition = 4;
     }
     // Checking for 3 elements in a row
     else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
     {
         condition = 3;
     }
     switch (condition)
     {
     case 5:
      // Loop for checking 3, 4, and 5 elements matching in a column
      for (int k = 2; k < 8; k++)
      {
      for (int l = 2; l < 10; l++)
      {
          if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6) // Checking for 5 elements in a column
          {
          for (int m = 0; m < 5; ++m)
          {
              arr[k + m][l] = 9;
              flag = 1;
              }
          }
          }
      }
         // for 5 elements matching in a row
     for (int m = 0; m < 5; ++m)
     {
         arr[i][j + m] = 9;
         flag = 1;
     }
     break;
      case 4:
     // Loop for checking 3, 4, and 5 elements matching in a column
     for (int k = 2; k < 8; k++)
     {
         for (int l = 2; l < 10; l++)
         {
         if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7) // Checking for 4 elements in a column
         {
             for (int m = 0; m < 4; ++m)
             {
                 arr[k + m][l] = 9;
                 flag = 1;
             }
         }
        }
        }
        // Processing for 4 elements in a row
        for (int m = 0; m < 4; ++m)
        {
            arr[i][j + m] = 9;
            flag = 1;
        }
        break;

         case 3:
     // Loop for checking 3, 4, and 5 elements matching in a column
     for (int k = 2; k < 8; k++)
     {
         for (int l = 2; l < 10; l++)
         {
         if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && k < 7) // Checking for 3 elements in a column
         {
             for (int m = 0; m < 3; ++m)
             {
                 arr[k + m][l] = 9;
                 flag = 1;
             }
         }
         }
     }
     // Processing for 3 elements in a row
     for (int m = 0; m < 3; ++m)
     {
         arr[i][j + m] = 9;
         flag = 1;
     }
     break;
         default:
                break;
            }
        }
    }

    //-------------------------------------------------------------------------------------------------//
    // loop for checking 3,4,5 elements matching in a column
    for (int k = 2; k < 8; k++)
    {
     for (int l = 2; l < 10; l++)
     {
      int condition = 0;
      
      // Checking for 5 elements match in a column
      if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6)
      {
          condition = 5;
      }
      // Checking for 4 elements match in a column
      else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7)
      {
          condition = 4;
      }
      // Checking for 3 elements match in a column
      else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
      {
          condition = 3;
      }
      switch (condition)
      {
      case 5:
          for (int i = 2; i < 10; i++)
          {
     for (int j = 2; j < 8; j++)
     {
         if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) // Checking for 3 elements in a row
         {
        for (int m = 0; m < 3; ++m)
        {
            arr[i][j + m] = 9;
            flag = 1;
        }
         }
         else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && j < 7) // Checking for 4 elements in a row
         {
        for (int m = 0; m < 4; ++m)
        {
            arr[i][j + m] = 9;
            flag = 1;
        }
         }
         else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4] && j < 6) // Checking for 5 elements in a row
         {
     for (int m = 0; m < 5; ++m)
     {
         arr[i][j + m] = 9;
         flag = 1;
     }
            }
        }
             }
      for (int m = 0; m < 5; ++m)
      {
          arr[k + m][l] = 9;
          flag = 1;
      }
             break;
     case 4:
            for (int i = 2; i < 10; i++)
            {
                for (int j = 0; j < 8; j++)
                {
       if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) // Checking for 3 elements in a row
       {
           for (int m = 0; m < 3; ++m)
           {
               arr[i][j + m] = 9;
               flag = 1;
           }
       }
       else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && j < 7) // Checking for 4 elements in a row
       {
           for (int m = 0; m < 4; ++m)
           {
               arr[i][j + m] = 9;
               flag = 1;
           }
       }
       else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4] && j < 6) // Checking for 5 elements in a row
       {
           for (int m = 0; m < 5; ++m)
           {
               arr[i][j + m] = 9;
               flag = 1;
           }
       }
                }
                }
                for (int m = 0; m < 4; ++m)
                {
                    arr[k + m][l] = 9;
                    flag = 1;
                }
                break;

            case 3:
                for (int i = 2; i < 10; i++)
                {
                    for (int j = 2; j < 8; j++)
                    {
                        if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) // Checking for 3 elements in a row
                        {
                            for (int m = 0; m < 3; ++m)
                            {
                                arr[i][j + m] = 9;
                                flag = 1;
                            }
                        }
                        else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && j < 7) // Checking for 4 elements in a row
                        {
                            for (int m = 0; m < 4; ++m)
                            {
                                arr[i][j + m] = 9;
                                flag = 1;
                            }
                        }
                        else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4] && j < 6) // Checking for 5 elements in a row
                        {
                            for (int m = 0; m < 5; ++m)
                            {
                                arr[i][j + m] = 9;
                                flag = 1;
                            }
                        }
                    }
                }
                for (int m = 0; m < 3; ++m)
                {
                    arr[k + m][l] = 9;
                    flag = 1;
                }
                break;

            default:
                break;
            }
        }
    }

	glutPostRedisplay();//redisplaying the window / updating the window
	return flag;//returning flag. If flag is 1 then there is a match. If flag is 0 then there is no match.
}


void CandiesGenerator() {

// initially 
    if (time1 > 0 && moves > 0) {
    
        int size = 60, sx = 140, sy = 140;
        
        // for grid initialization 
        if (f == 0) {
            for (int i = 2; i < 10; ++i) {
                sx = 140;
                for (int j = 2; j < 10; ++j) {
                    int x = rand() % 6 + 1;

                    if (x == 1) {
                        DrawCircle(sx + size / 2, sy + size / 2, size / 2, colors[DEEP_PINK]);
                        arr[i][j] = 1;
                    }
                    else if (x == 2) {
                        DrawSquare(sx, sy, size, colors[THISTLE]);
                        arr[i][j] = 2;
                    }
                    else if (x == 3) {
                        DrawTriangle(sx, sy, sx + (size / 2), sy + size, sx + size, sy, colors[MEDIUM_VIOLET_RED]);
                        arr[i][j] = 3;
                    }
                    else if (x == 4) {
                        DrawRectangle(sx + 20, sy, size / 3, size, colors[PURPLE]);
                        arr[i][j] = 4;
                    }
                    else if (x == 5) {
                        DrawRoundRect(sx, sy + 15, size, size / 1.5, colors[LIGHT_CORAL]); 
                        arr[i][j] = 5;
                    }
                    else if (x == 6) {
                        DrawTriangle(sx + (size / 2), sy, sx, sy + size, sx + size, sy + size, colors[LIGHT_PINK]);
                        DrawTriangle(sx, sy, sx + size, sy, sx + size / 2, sy + size, colors[LIGHT_PINK]);
                        arr[i][j] = 6;
                    }
                    sx += size + 10;
                }
                sy += size + 10;
            }
        }
        // uses the value stored in the arr (this is random value from newcandies generation and draws shape accordinglyy
        f = 1;
        sx = 140, sy = 140;
        for (int i = 2; i < 10; ++i) {
            sx = 140;
            for (int j = 2; j < 10; ++j) {
                if (arr[i][j] == 1) {
                    DrawCircle(sx + (size / 2), sy + size / 2, size / 2, colors[DEEP_PINK]);
                    arr[i][j] = 1;
                }
                else if (arr[i][j] == 2) {
                    DrawSquare(sx, sy, size, colors[THISTLE]);
                    arr[i][j] = 2;
                }
                else if (arr[i][j] == 3) {
                    DrawTriangle(sx, sy, sx + (size / 2), sy + size, sx + size, sy, colors[MEDIUM_VIOLET_RED]);
                    arr[i][j] = 3;
                }
                else if (arr[i][j] == 4) {
                    DrawRectangle(sx + size / 3, sy, size / 3, size, colors[PURPLE]);
                    arr[i][j] = 4;
                }
                else if (arr[i][j] == 5) {
                    DrawRoundRect(sx, sy + 15, size, size / 1.5, colors[LIGHT_CORAL]); 
                    arr[i][j] = 5;
                }
                else if (arr[i][j] == 6) {
                    DrawTriangle(sx + (size / 2), sy, sx, sy + size, sx + size, sy + size, colors[LIGHT_PINK]);
                    DrawTriangle(sx, sy, sx + size, sy, sx + size / 2, sy + size, colors[LIGHT_PINK]);
                    arr[i][j] = 6;
                }
                sx += size + 10;
            }
            sy += size + 10;
        }
        
        //progress bar drawing 
        int m = 140, n = 100;
        DrawRectangle(135, 95, 570, 30, colors[LIGHT_PINK]);
        for (int i = 0; i < progress; ++i) {
            DrawSquare(m, n, 20, colors[DEEP_PINK]);
            m += 18;
        }
        //score,level,lives
        DrawString(140, 720, "Score " + Num2Str(score), colors[DEEP_PINK]);
        DrawString(620, 720, "Level " + Num2Str(level), colors[DEEP_PINK]);
        DrawString(350, 50, "Lives : " + Num2Str(lives), colors[MEDIUM_VIOLET_RED]);

      // time trial mode
        if (option == 1) {
            DrawString(350, 720, "Timer : " + Num2Str(time1), colors[LIGHT_PINK]);
        }
        // normal mode
        else {
            DrawString(350, 720, "Moves : " + Num2Str(moves), colors[LIGHT_PINK]);
        }
    }
    else 
    // if time1 is 0 or moves is 0 
    {
        lives -= 1;
        // if still lives remaining 
        if (lives > 0) {
            time1 = 100;
            moves = 30;
            f = 0;
            progress = 0;
            if (level == 1) {
                time1 = 100;
                moves = 30;
            }
            else if (level == 2) {
                time1 = 80;
                moves = 25;
            }
            else if (level == 3) {
                time1 = 70;
                moves = 20;
            }
            else if (level == 4) {
                time1 = 65;
                moves = 20;
            }
            else if (level == 5) {
                time1 = 60;
                moves = 18;
            }
            else if (level == 6) {
                time1 = 55;
                moves = 15;
            }
            else if (level == 7) {
                time1 = 50;
                moves = 14;
            }
            else if (level == 8) {
                time1 = 45;
                moves = 12;
            }
            else if (level == 9) {
                time1 = 40;
                moves = 10;
            }
            else if (level >= 10) {
                time1 = 30;
                moves = 8;
            }
        }
        else
        // if there are no lives left it will display game over prompt 
            setMenuOption(6);
    }
}
// using in swap and newcandies generation
void setArr(int x1, int y1, int a) {
	arr[x1][y1] = a;
}

int getArr(int x1, int y1) {
	return arr[x1][y1];
}


void Swap(int sx_1, int sy_1, int sx_2, int sy_2) {
    // Bounds check for array
    if (sx_1 >= 0 && sx_1 < 10 && sy_1 >= 0 && sy_1 < 10 && 
        sx_2 >= 0 && sx_2 < 10 && sy_2 >= 0 && sy_2 < 10) {
        
        // Check for adjacency either horizontally or vertically  (axis should match)
        if ((abs(sx_1 - sx_2) == 1 && sy_1 == sy_2) || 
            (abs(sy_1 - sy_2) == 1 && sx_1 == sx_2)) 
            {
            
            // storing array for first box having sx_1, sy_1
            int temp = getArr(sy_1, sx_1);
            // for replacing the first box with the other box this function is called
            setArr(sy_1, sx_1, getArr(sy_2, sx_2));
            // finally the two boxes are replaced
            setArr(sy_2, sx_2, temp);

            // Check for a match after swapping if isMatching is 1 then boxes will remain at their original positions.
            if (!isMatching()) {
            
		setArr(sy_2, sx_2, getArr(sy_1, sx_1));
                setArr(sy_1, sx_1, temp);
		
            }
            // Decreasing move count if no option is set
            if (option == 0) {
                decMoves();
            }
        }
    }
}

//this function manages the generation of new candies after matches are made updating the game state including score, level, and progress bar

void newCandiesGenerator() {
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == 9)
			{
				for (int k = i; k < 9; k++)  //k<9 because at position 10 new candy will be formed
				{
					int temp = getArr(k, j); //holding the current value 
					setArr(k, j, getArr(k + 1, j)); //setting it to the value below it 
					setArr(k + 1, j, temp);  //setting the one below it to value of temp 
				}
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == 9)
			{
				flag = 1;
				incScore();
				// if progress is greater than 31 sets level++, progress=0, f=0 these are conditions for incLevel function to return 1 
				if (incLevel() == 1) {
					if (level == 1) {
						time1 = 100;
						moves = 30;
					}
					else if (level == 2) {
						time1 = 80;
						moves = 25;
					}
					else if (level == 3) {
						time1 = 70;
						moves = 22;
					}
					else if (level == 4) {
						time1 = 65;
						moves = 20;
					}
					else if (level == 5) {
						time1 = 60;
						moves = 18;
					}
					
				}
				
				arr[i][j] = rand() % 6 + 1;
			}
		}
	}
	// means replacement has done then it eventually increases progress bar
	if (flag == 1) {
		incProgress();
	}
}


/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
//gameScene gam;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	MenuDisplay();
	//DrawHintButton();
	levels();
	levelModes();
	instruction();
	name();
	GameOver();
	Pause();
	DisplayHighscore();
	
	
	if(getMenuOption()==10){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
	// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		CandiesGenerator();
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);
		isMatching();
		newCandiesGenerator();
		glutSwapBuffers(); // do not modify this line..
	}
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	} else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*
bool option = 0;

int getOption() {
	return option;
}
void setOption(int o) {
	option = o;
}

void setMenuOption(int o) {
	MenuOption = o;
}
int getMenuOption() {
	return MenuOption;
}
*/


void PrintableKeys(unsigned char key, int x, int y) {
    static bool enteringName = false;
    static int countPressSix = 0; 
    
	// Toggle pause 'p' and  check if the game is currently active
    if ((key == 'p' || key == 'P') && getMenuOption() == 10) { 
        setMenuOption(7); // Setting  the game state to paused
        glutPostRedisplay(); // Refreshing display to show pause menu
        return; // Exit the function to avoid further processing
    } 
    // again p is pressed and game will be resumed and Check for the game is currently paused (set to 7)
    else if ((key == 'p' || key == 'P') && getMenuOption() == 7) { 
        setMenuOption(10); // Resume the game
        glutPostRedisplay(); 
        return; // Exit the function to avoid further processing
    }
	// Toggle Exit Button
	if ((key == 'e' || key == 'E') && getMenuOption() == 10) { // Checking if the game is currently active
        setMenuOption(6); // Seting  the game state to exit 
        glutPostRedisplay();
        return; // Exiting the function to avoid further processing
    }
    
    if (getMenuOption() == 0 || getMenuOption() == 6) {
        if (key == '1') {
            enteringName = true;
            playerName = "";
            setMenuOption(1);
        } 
        // greater than 1 will be stored in variable 'option'
        else if (key >= '2' && key <= '6') {
            int option = key - '0';
            if (option == 6 && getMenuOption() == 6) {
                countPressSix++;  // Incrementing the counter when '6' is pressed
                if (countPressSix == 2) {  // Checking if '6' has been pressed twice
                    exit(1);  // Exiting the game if '6' is pressed a second time
                }
            }
            setMenuOption(option);
        }
    } 
    
    else if (getMenuOption() == 1 && enteringName) {
    // check if user has entered "entered" k
        if (key == '\r' || key == '\n') {
            enteringName = false;
            // game will start (as called in game display function)
            setMenuOption(10);
            updateHighScores(playerName, getScore());
        } 
        else if (key == 8 || key == 127) 
        {
        // if backspace key is pressed and player's name is not empty then it removes characters 
       if (!playerName.empty()) 
            playerName.pop_back();
        }
        //alphanumeric input and if space is put
        else if (isalnum(key) || key == ' ') {
            playerName += key;
        }
        glutPostRedisplay();
    } 
    
    else if (getMenuOption() == 5 || getMenuOption() == 4) {
        if (key == '1') {
            setMenuOption(0);
        }
    } 
    // if pressed 2 then levels appear 
    else if (getMenuOption() == 2) {
        if (key >= '1' && key < '6') {
        // based on key level is stored
            int levelOrOption = key - '0';
            if (getMenuOption() == 2) {
            // sent to setlevel func
                setLevel(levelOrOption);
            } 
          //exit
        } else if (key == '6') {
            setMenuOption(0);
        }
    } 
    // if modes have to be selected 
    else if (getMenuOption() == 3) {
    // normal mode
        if (key == '1')
        {
            setOption(0);
        } 
        // trial mode 
        else if (key == '2') {
            setOption(1);
        } 
        // exit 
        else if (key == '3') {
            setMenuOption(0);
        }
    } 
    
    if (key == 27) {  // Handle ESC key
        exit(1);
    }

    glutPostRedisplay();
}


/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constan//#include <GL/gl.h>
 * t FPS.
 *
 * */
 
void timer(int m) {
	// implement your functionality here
	if(getOption()==1 && getMenuOption()==10){
		time1Mode();
		HighScore();
		glutPostRedisplay();
	}
	// once again we tell the library to call our timer function after next 1000/FPS
		glutTimerFunc(1000, timer, 0);
}

void MousePressedAndMoved(int x, int y) {

	glutPostRedisplay();

}
void MouseMoved(int x, int y) {

	glutPostRedisplay();

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

// Variables for mouse interaction
int sx_1 = 0, sy_1 = 0; // Start coordinates for swap
int sx_2 = 0, sy_2 = 0; // End coordinates for swap


void MouseClicked(int button, int state, int x, int y) {
   // if (x >= 100 && x <= 200 && y >= 50 && y <= 80 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

      //  findHint();
       // displayHint();
   // }
    int my= glutGet(GLUT_WINDOW_HEIGHT) - y;

    // Check if the click is within the hint button's area
   /* if (x >= 100 && x <= 200 && my >= 50 && my <= 80 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
       findHint();
        displayHint();
    }*/
    // Existing swap logic
    int gridX = x / 70;
    int gridY = (800 - y) / 70;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            sx_1 = gridX;
            sy_1 = gridY;
        } else if (state == GLUT_UP) {
            sx_2 = gridX;
            sy_2 = gridY;
            Swap(sx_1, sy_1, sx_2, sy_2);
        }
    }
}



/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 800, height = 800; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Gemzie"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}

