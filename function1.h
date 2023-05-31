#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "struct1.h"
#define MAX_PLAYER_RECORDS 10

typedef char NamePlayer[20];
typedef char word[11];
typedef int nBackZero[7];


//function
void nHighestScore(PlayerAndLetters *playerone,
                   PlayerAndLetters *playertwo,
                   PlayerAndLetters *playerthree,
                   PlayerAndLetters *playerfour,
                   int nPlayerWho);
void 
cLongestWord(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour);


int
IsValidWord(PlayerAndLetters *playerone, PlayerAndLetters *playertwo,
            PlayerAndLetters *playerthree, PlayerAndLetters *playerfour,
            int nPlayerCount, int nAsciiAlphbt[], int nLttrQntity[],
            int nTileAlphabetScore[],  int nplayerrnt);

int
PssngLttersPlayers(PlayerAndLetters *playerone,
                   PlayerAndLetters *playertwo,
                   PlayerAndLetters *playerthree,
                   PlayerAndLetters *playerfour,
                   int nAsciiAlphbt[], int nLttrQntity[],
                   int nTileAlphabetScore[], int nPlayerCount,
                   char BOARD[][11], int roundnumber);

int SrtngPntsLttrs(int nAsciiAlphbt[], int nLttrQntity[],
               int nTileAlphabetScore[]);

int RandomizeLetters(int nRdmNm);

void nNameOfPlayer(NamePlayer cNameofplayer);

int ChoosePlayerNumbers();

int StartUpMenu(int nDecision);

void nChangeUserLetter(PlayerAndLetters *playerone,
                  PlayerAndLetters *playertwo,
                  PlayerAndLetters *playerthree,
                  PlayerAndLetters *playerfour,
                  int nAsciiAlphbt[], int nLttrQntity[],
                  int nTileAlphabetScore[], int nNumber, int         
                  nPlayerCount);

void
nAverageScore(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour,
              int nPlayerCount);

int GameEndChecker( int valid_words, int playerscore); 

int getInt();

void printBoard (char BOARD[11][11]);

void getMove (char BOARD[11][11], int roundnumber, String wordofplayer);

int CheckCenter (char BOARD[11][11]);

int LineChecker (char BOARD[11][11], String wordofplayer, char direction,
	     int startx, int starty, int endx, int endy);

int WriteData(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour,
              int nPlayerCount);

int AppendData(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour,
              int nPlayerCount);

int ReadData(int nPlayerCount);

//not important
void cCaptilizingWord(char *cWord);
void DisplayAsterisk();
void DisplayNewLine();
void TitleScreen();
void DisplayEquals();
void DisplayGreater();
void DisplayLesser();
void DisplayHashtag();

void red ();
void yellow();
void blue();
void green();
void cyan();
void reset();




//important

/*
<WriteData will write player data into a txt file>
Precondiiton: <That there is data to be written>
@param <*playerone> <Get players data>
@param <*playertwo> <Get players data>
@param <*playerthree> <Get players data>
@param <*playerfour> <Get players data>
@param <nPlayerCount> <To count how many to write>
@return <printing of txt file>
*/
int 
WriteData(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour,
              int nPlayerCount) 
{
	int     i;
    FILE* playerfile;
	playerfile = fopen("playerfile.txt", "w");
       
    if(playerfile == NULL)
    {
        printf("Error file opening\n");
        return 1;
    }
       
    Player_Data pData[MAX_PLAYER_RECORDS];
    
    strcpy(pData[0].cName, playerone->S_player.cName);
    strcpy(pData[0].cLongestWord, playerone->S_player.cValidWord);
    pData[0].nHighestScore = playerone->S_player.nPoints;
    pData[0].nGamesPlayed = 1;
    pData[0].AveScore = playerone->S_player.nPoints;
    
    strcpy(pData[1].cName, playertwo->S_player.cName);
    strcpy(pData[1].cLongestWord, playertwo->S_player.cValidWord);
    pData[1].nHighestScore = playertwo->S_player.nPoints;
    pData[1].nGamesPlayed = 1;
    pData[1].AveScore = playertwo->S_player.nPoints;
    
    strcpy(pData[2].cName, playerthree->S_player.cName);
    strcpy(pData[2].cLongestWord, playerthree->S_player.cValidWord);
    pData[2].nHighestScore = playerthree->S_player.nPoints;
    pData[2].nGamesPlayed = 1;
    pData[2].AveScore = playerthree->S_player.nPoints;
    
    strcpy(pData[3].cName, playerfour->S_player.cName);
    strcpy(pData[3].cLongestWord, playerfour->S_player.cValidWord);
    pData[3].nHighestScore = playerfour->S_player.nPoints;
    pData[3].nGamesPlayed = 1;
    pData[3].AveScore = playerfour->S_player.nPoints;
    
    for (i = 0; i < nPlayerCount; i++)
    {
        fprintf(playerfile, 
		        "%s, %s, %d, %d, %.2f\n", 
		        pData[i].cName, 
		        pData[i].cLongestWord, 
		        pData[i].nHighestScore, 
		        pData[i].nGamesPlayed, 
		        pData[i].AveScore);
		
        if (ferror(playerfile))
        {
            printf("Error writing to file\n");
            return 1;
        }
    }
    
    fclose(playerfile);
    printf("\n %d records written\n", i); 
    
    for (i = 0; i < nPlayerCount; i++)
    {
        printf("%s, %s, %d, %d, %.2f\n", 
		        pData[i].cName, 
		        pData[i].cLongestWord, 
		        pData[i].nHighestScore, 
		        pData[i].nGamesPlayed, 
		        pData[i].AveScore);
    }
    
    return 0;
}

/*
<ReadData will read player data from a txt file>
Preconditon: <That there is data stored>
@return <priting of txt file>
*/

int 
ReadData(int nPlayerCount) // to read the data at the very start
{
	int i;
    FILE* playerfile;
    playerfile = fopen("playerfile.txt", "r");   

       
    if(playerfile == NULL)
    {
        printf("Error file opening");
        return 1;
    }
       
    Player_Data pData[MAX_PLAYER_RECORDS];
    int read = 0;
    int records = 0;
    
    do
	{
		read = fscanf(playerfile, 
				"%49[^,], %49[^,], %d, %d, %f\n",
				pData[records].cName, 
				pData[records].cLongestWord, 
				&pData[records].nHighestScore, 
				&pData[records].nGamesPlayed, 
				&pData[records].AveScore);					  
				  
		if (read == 5) records++;
				  
		if(read != 5 && !feof(playerfile))
		{
			printf("File format incorrect.\n");
			return 1;
		}			  
					  
		if (ferror(playerfile))	
		{
			printf("Error reading file.\n");
			return 1;
	    }
						 					  
	}while(!feof(playerfile));
	fclose(playerfile);
     
    for (i = 0; i < nPlayerCount; i++)
    {
        printf("\n\n%s, %s, %d, %d, %.2f\n", 
                pData[i].cName, 
                pData[i].cLongestWord, 
                pData[i].nHighestScore, 
                pData[i].nGamesPlayed,
                pData[i].AveScore);
			    
    }
}

/*
<AppendData will append player data to an existing txt file>
Preconditon: <That there is data stored>
@param <*playerone> <Get players data>
@param <*playertwo> <Get players data>
@param <*playerthree> <Get players data>
@param <*playerfour> <Get players data>
@param <nPlayerCount> <To count how many to append>
@return <printing the txt file>
*/

int 
AppendData(PlayerAndLetters *playerone,
            PlayerAndLetters *playertwo,
            PlayerAndLetters *playerthree,
            PlayerAndLetters *playerfour,
            int nPlayerCount)  // to append the data to the file
{
	int     i;
    FILE*   playerfile;
    playerfile = fopen("playerfile.txt", "a");  
    
    if(playerfile == NULL)
    {
        printf("Error file opening");
        return 1;
    }
    Player_Data pData[MAX_PLAYER_RECORDS];
    
    strcpy(pData[0].cName, playerone->S_player.cName);
    strcpy(pData[0].cLongestWord, playerone->S_player.cValidWord);
    pData[0].nHighestScore = playerone->S_player.nHighestScore;
    pData[0].nGamesPlayed = 1;
    pData[0].AveScore = playerone->S_player.AveScore;
    
    strcpy(pData[1].cName, playertwo->S_player.cName);
    strcpy(pData[1].cLongestWord, playertwo->S_player.cValidWord);
    pData[1].nHighestScore = playertwo->S_player.nHighestScore;
    pData[1].nGamesPlayed = 1;
    pData[1].AveScore = playertwo->S_player.AveScore;
    
    strcpy(pData[2].cName, playerthree->S_player.cName);
    strcpy(pData[2].cLongestWord, playerthree->S_player.cValidWord);
    pData[2].nHighestScore = playerthree->S_player.nHighestScore;
    pData[2].nGamesPlayed = 1;
    pData[2].AveScore = playerthree->S_player.AveScore;
    
    strcpy(pData[3].cName, playerfour->S_player.cName);
    strcpy(pData[3].cLongestWord, playerfour->S_player.cValidWord);
    pData[3].nHighestScore = playerfour->S_player.nHighestScore;
    pData[3].nGamesPlayed = 1;
    pData[3].AveScore = playerfour->S_player.AveScore;
    
    for (i = 0; i < nPlayerCount; i++)
    {
        fprintf(playerfile, 
		        "%s, %s, %d, %d, %.2f\n", 
		        pData[i].cName, 
		        pData[i].cLongestWord, 
		        pData[i].nHighestScore, 
		        pData[i].nGamesPlayed, 
		        pData[i].AveScore);
		
        if (ferror(playerfile))
        {
            printf("Error writing to file\n");
            return 1;
        }
    }

    fclose(playerfile);
    printf("\n %d records written\n", i); 
    
    for (i = 0; i < nPlayerCount; i++)
    {
        printf("%s, %s, %d, %d, %.2f\n", 
                pData[i].cName, 
                pData[i].cLongestWord, 
                pData[i].nHighestScore, 
                pData[i].nGamesPlayed, 
                pData[i].AveScore);
    }    
}
//The above code is calculating the average score of the player.
void
nAverageScore(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour,
              int nPlayerCount)
{
    if(nPlayerCount == 1)
    {
        playerone->S_player.AveScore = (playerone->S_player.AveScore + playerone->S_player.nPoints) / 2.0;
        playerone->S_player.nGamesPlayed = playerone->S_player.nGamesPlayed + 1;
    }
    
    else if(nPlayerCount == 2)
    {
        playertwo->S_player.AveScore = (playertwo->S_player.AveScore + playertwo->S_player.nPoints) / 2.0;
        playertwo->S_player.nGamesPlayed = playertwo->S_player.nGamesPlayed + 1;
    }
    
    else if(nPlayerCount == 3)
    {
        playerthree->S_player.AveScore = (playerthree->S_player.AveScore + playerthree->S_player.nPoints) / 2.0;
        playerthree->S_player.nGamesPlayed = playerthree->S_player.nGamesPlayed + 1;
    }
    
    else if(nPlayerCount == 4)
    {
        playerfour->S_player.AveScore = (playerfour->S_player.AveScore + playerfour->S_player.nPoints) / 2.0;
        playerfour->S_player.nGamesPlayed = playerfour->S_player.nGamesPlayed + 1;
    }
}


/*
<Linechecker will check if the player is placing the word properly>
Preconditon: <There is a word given>
@param <char BOARD[11][11]> <to just get the board>
@param <String wordofplayer> <get playerword>
@param <char direction> <horizontal or vertical>
@param <int startx> <start of coordinates>
@param <int starty> <start of coordinates>
@param <int endx> <end of coordinates>
@param <int endy> <end of coordinates>
@return <description of returned result>
*/
int
LineChecker (char BOARD[11][11], String wordofplayer, char direction,
	     int startx, int starty, int endx, int endy)
{
    int     i,
            j, 
            len;
    len = strlen (wordofplayer);
    int     lol1 = true,
            lol2 = false;
  
    if (direction == 'h' || direction == 'H')	// to check if horizontal
    {
      for (i = 0; i < len; i++)	// for checking if its blank or has same letters
	    {
	        if (BOARD[starty][startx + i] == ' '
	            || wordofplayer[i] == BOARD[starty][startx + i])
	        {
	        }
	        else
	        {
	            lol1 = false;
	            printf ("something is blocking\n");
	            return 1;
	        }
	    }
    }
    else if (direction == 'v' || direction == 'V')	// to check if vertical
    {
      for (i = 0; i < len; i++)	// for checking if its blank or has same letters
	    {
	        if (BOARD[starty + i][startx] == ' '
	        || wordofplayer[i] == BOARD[starty + i][startx])
	        {
	        }
	        else
	        {
	            lol1 = false;
	            printf ("something is blocking\n");
	            return 1;
	        }
	    }
    }


    if (direction == 'h' || direction == 'H')	// to check if horizontal
    {
        for (i = 0; i < len; i++)	// for looping startx -> endx
	    {
	        if (BOARD[starty + 1][startx + i] != ' ' || BOARD[starty - 1][startx + i] != ' ')	// to check if above and below has letter
	        {
	            lol2 = true;
	            printf ("there are words in the surroundings\n");
	        }
	        else if (BOARD[starty + i][startx - 1] != ' ' || BOARD[starty + i][startx + 1] != ' ')	// to check if above and below has letter
	        {
	            lol2 = true;
	            printf ("there are words in the surroundings\n");
	        }
	        else
	        {
	            printf ("there are no words\n");
	        }
	    }
    }

    else if (direction == 'v' || direction == 'V')	// to check if vertical
    {
        for (i = 0; i < len; i++)	// for looping starty -> endy
	    {
	        if (BOARD[starty + i][startx - 1] != ' ' || BOARD[starty + i][startx + 1] != ' ')	// to check if above and below has letter
	        {
	            lol2 = true;
	            printf ("there are words in the surroundings\n");
	        }
	        else if (BOARD[starty + 1][startx + i] != ' ' || BOARD[starty - 1][startx + i] != ' ')	// to check if above and below has letter
	        {
	            lol2 = true;
	            printf ("there are words in the surroundings\n");
	        }
	        else
	        {
	            printf ("There are no words\n");
	        }
	    }
    }



    if (lol1 == true && lol2 == true)
    {
        int x = startx;
        int y = starty;
        for (j = 0; j < len; j++)
	    {
	        BOARD[y][x] = wordofplayer[j];
	        if (startx != endx)
	        x++;
	        // move x
	        if (starty != endy)
	        y++;
	        // move y
	    }

    return 2;

    }
    return 1;
}


//Checking if the center of the board is empty or not.
int
CheckCenter (char BOARD[11][11])	// just to check if it is center and print it after
{
    if (BOARD[5][5] == ' ')
    {
        int     i, 
                j;
        printf ("It is not center\n");
        printf ("Start on the center (6,6)!\n\n");
        for (i = 0; i < 11; i++)
	    {
	        for (j = 0; j < 11; j++)
	        {
	          BOARD[i][j] = ' ';
	        }
	    }
        printBoard (BOARD);
        return 1;
    }
    else
    {
        printf ("There is center value\n");
        printBoard (BOARD);
        return 2;
    }
}

/*
<getMove will get the direction, the coords, then check if it is inputted at the right place>
Precondiiton: <That the word is valid / the user asks for it>
@param <BOARD[11][11]> <get the board>
@param <roundnumber> <to know which round to use what>
@param <wordofplayer> <get the word of player>
@return <>
*/
void
getMove (char BOARD[11][11], int roundnumber, String wordofplayer)
{
    bool a;
    while (true)
    {
        a =     true;
        int     len,
                startx, 
                starty, 
                endx, 
                endy, 
                x, 
                y, 
                count = 0;
        char    letter,
                direction;

        len = strlen (wordofplayer);
      
    do
    {
        printf ("\n[h] if Horizontal [v] if Vertical\n");
        printf ("Direction: ");
        if(scanf (" %c", &direction));

    }while(!(direction == 'h' || direction == 'H' || direction == 'v' || direction == 'V'));
      
        if (direction == 'h' || direction == 'H')
	    {
            printBoard(BOARD);
            printf ("\n\nEnter coordinate of your move\n");
            printf ("x: ");
            startx = getInt ();
            printf ("y: ");
            starty = getInt ();
            endx = startx + len - 1;
            endy = starty;
            
            if(endx > 11)
            {
                printf("Out of Boundary\n");
                return getMove(BOARD, roundnumber, wordofplayer);
            }
	    }
        else if (direction == 'v' || direction == 'V')
	    {
            printBoard(BOARD);
            printf ("\n\nEnter coordinate of your move\n");
            printf ("x: ");
            startx = getInt ();
            printf ("y: ");
            starty = getInt ();
            endx = startx;
            endy = starty + len - 1;
            if(endy > 11)
            {
                printf("Out of Boundary\n");
                return getMove(BOARD, roundnumber, wordofplayer);                       
            }
	    }
	    else
	    {
	    }

        if (roundnumber == 1)	// round 1 to check if it is in middle
	    {
	        if (startx == 5 && starty == 5)	// middle
	        {
	            // start from middle
	        }
	        else if (startx == 5)	// middle vertical
	        {
	         // horizontal is middle row 

	        // so only vertical will work
	        if (direction == 'v')
		    {
		        if (endy >= 6)
		        {
		            // this is middle
		            a = false;
		        }
		      }
	        }
	        else if (starty == 5)	// middle horizontal
	        {
	      // vertical is middle column
	        if (direction == 'h')
		        {
		        if (endx >= 6)
		          {
		            // this is middle
		            a = false;
		          }
		        }
	        }  
	        else
	        {
	        }
            x = startx;
            y = starty;
            int i;
            for (i = 0; i < len; i++)
	        {
	            BOARD[y][x] = wordofplayer[i];
	            if (startx != endx)
	            x++;
	            // move x
	            if (starty != endy)
	            y++;
	            // move y
	        }
                int center;
                center = CheckCenter (BOARD);
                if (center == 2)
                    return;
                else
                    a = false;
            }
            else if (roundnumber >= 2)
            {
                int line;
                line = LineChecker (BOARD, wordofplayer, direction, startx, starty, endx, endy);
            if(line == 2)
            {
                printBoard(BOARD);
                return;
            }
            else
            {
            }
        }
        else
	    {
            a = false;
	    }
    }
}

/*
<getInt will get the coordinate numbers>
Precondiiton: <That it gets asked>
@return <the number - 1 due to start 0>
*/
int
getInt ()			// to get the number for the coordinates
{
    int b = 0;
    bool isNum;
    while (true)
    {
        isNum = true;
        b = 0;
        char a[10] = "";
        if(scanf ("%s", a));
        int c = strlen (a);
        int i;
        for (i = 0; i < c; i++)
        {
            if (isdigit (a[i]) && c <= 2)
            {
                b += (a[i] - 48) * pow (10, c - (i + 1));
            }
            else
            isNum = false;
        }
        if (b > 11)
            isNum = false;
            else if (b == 0)
            isNum = false;
        if (isNum)
            return b - 1;
    }
}


/*
<printBoard will print the board>
Precondiiton: <That it gets called>
@return <board>
*/
void
printBoard (char BOARD[11][11])	// to print the 11x11 board
{
    int   i,
            j;
    printf ("  ");
    for (i = 0; i < 11; i++)
    {
        if (i == 10)
            printf ("  %d ", i + 1);
        else
            printf ("  %d  ", i + 1);
    }
    printf ("\n\n");

    for (i = 0; i < 11; i++)
    {
        if (i < 9)
            printf ("%d  ", i + 1);
        else
            printf ("%d ", i + 1);

        for (j = 0; j < 11; j++)
            {
            printf ("[ %c ]", BOARD[i][j]);
            }
        if (i != 10)
            printf
            ("\n   --------------------------------------------------------");
            printf ("\n");
    }
}

//The above code is generating a random number between 1 and 26.

int
RandomizeLetters(int nRdmNm)
{
    nRdmNm = rand() % 26;

    if (nRdmNm == 0)
    {
        nRdmNm = 1;
    }
    return nRdmNm = nRdmNm + 'A' - 1;
}



/*

The above code is checking if the letter the user has entered is in the array of letters. If it
is, it will store the value of the array in a variable.
*/
int
SrtngPntsLttrs(int nAsciiAlphbt[], int nLttrQntity[],
               int nTileAlphabetScore[])
{
    int nCounter,
        nRdmNm,
        nDump,
        nBreaker = 0,
        nMin = 0,
        nMax = 26,
        nWorking = 1;

    nRdmNm = RandomizeLetters(nRdmNm);

    for (nCounter = 0; nCounter < 26 && nWorking != 0; nCounter++)
    {

        if (nAsciiAlphbt[nCounter] == nRdmNm && nLttrQntity[nCounter] > 0) //change
        {
            nTileAlphabetScore[nCounter];
            nLttrQntity[nCounter]--;
            nWorking = 0;
            return nCounter;
        }
        else if (nCounter == 25)
        {
            nRdmNm = RandomizeLetters(nRdmNm);
            nCounter = 0;
        }
    }
}



void
nChangeUserLetter(PlayerAndLetters *playerone,
                  PlayerAndLetters *playertwo,
                  PlayerAndLetters *playerthree,
                  PlayerAndLetters *playerfour,
                  int nAsciiAlphbt[], int nLttrQntity[],
                  int nTileAlphabetScore[], int nNumber, int nPlayerCount)
{
    int     i,
            nExit = 0,
            nStop = 0,
            nCounter,
            sTopper = 0,
            sTopper2 = 0,
            cQuestion = 0, //changed from -1
            nPlaceHolder = -1,
            nReturnChanger = 0,
            ValidWordBa = 0,
            nWholeCounter = 0,
		    nCheckerAlphaCnt = -1;

    int nArrayCount[7] = {0, 1, 2, 3, 4, 5, 6};

    char    cLetterChoice,
            a,
            b;

    // player 1--------------------------------------------------------------------------
    if(nNumber == 1)
    {
		printf("\n\n");
        do
        {	
            int nAnswer = 1;
            /* Displaying the remaining letters in the alphabet. */
            printf("   ");
            DisplayGreater();
            DisplayLesser();
			printf("\n");
			printf("\tRemaining Alphabet Letters\n");
            for(i = 0; i < 26; i++)
            {	
                if(nLttrQntity[i] > 0)
                {
                    printf("\n\t  ALPHABET: %c ", nAsciiAlphbt[i]);
                    printf("\tQUANTITY: %d ", nLttrQntity[i]);
                }

            }
			printf("\n");
            printf("   ");
			DisplayGreater();
            DisplayLesser();
			printf("\n");

            /* Printing the name of the player and asking them what letter they want to change. */
            DisplayNewLine();//
            printf("   ");
            DisplayHashtag();//
            printf("\nWhat letter does ");
			red();
            printf("[%s]",playerone->S_player.cName);
			reset();
            printf(" want to change?\n");

            printf("\n\t\t   Tiles"); //
			printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {	
				cyan();
                printf("%c ", playerone->S_tileletters.cLetterSymbol[i]);

            }
			    reset();
			    printf("\n\t   -----------------------\n");
            
			/* The above code is checking if the letter the user has entered is in the array of letters. If it
            is, it will store the value of the array in a variable. */
            while(nAnswer != 0)
            {
                printf("\t\t==> ");
				if(scanf(" %c", &cLetterChoice));
            	a = toupper(cLetterChoice);
				//printf("\nnCheckerAlphaCnt :%d\n",nCheckerAlphaCnt);

                for(i = 0; i < 7; i++)
                {
                    if(playerone->S_tileletters.cLetterSymbol[i] == a)
                    {
                        nPlaceHolder = nArrayCount[i];
                        nAnswer = 0;
                    }
                }      

            }
			

            for(i = 0; i < 26 && sTopper != 1; i++)
            {
                if(nAsciiAlphbt[i] == a)
                {
                    nLttrQntity[i] += 1;
                    sTopper = 1;
                }

            }

            /* Changing the letter of the player's tile. */
            for(i = 0; i < 26; i++)
            {
                if(playerone->S_tileletters.cLetterSymbol[i] == a && nLttrQntity[i] != 0)//new nLttrQntity[i] != 0
                {

                    do
                    {	
                        cyan();
                        printf("\n\n   ");
                        DisplayGreater();
                        DisplayLesser();
                        printf("\n\t Picking a Letter from the bag!\n\t\tPicked");

                        //randomizer
                        nReturnChanger = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity,
                                            nTileAlphabetScore);
                        red ();								
                        printf(" [%c]\n", nAsciiAlphbt[nReturnChanger]);
                        reset();
                        cyan();
                        printf("   ");
                        DisplayGreater();
                        DisplayLesser();
                        reset();

                        printf("\n\n\n\t     Alphabet Changed!\n");
                        playerone->S_tileletters.cLetterSymbol[nPlaceHolder] = nAsciiAlphbt[nReturnChanger];

                        playerone->S_tileletters.nLetterScore[nPlaceHolder]  = nTileAlphabetScore[nReturnChanger];

                        for(i = 0; i < 26 && sTopper2 != 1; i++)
                        {
                        if(nAsciiAlphbt[i] == playerone->S_tileletters.cLetterSymbol[nPlaceHolder])
                        {
                            playerone->S_tileletters.cLetterSymbol[nPlaceHolder];
                            sTopper2 = 1;

                        }

                    }
                        nStop = 1;
                    }while(nAsciiAlphbt[i] == playerone->S_tileletters.cLetterSymbol[nPlaceHolder] && nStop != 1); //change i

					            printf("\n\t   -----------------------\n\t\t");
                    for (i = 0; i < 7; i++)
                    {
						            cyan();
                        printf("%c ", playerone->S_tileletters.cLetterSymbol[i]);
                    }
					            reset();
					            printf("\n\t   -----------------------");
                }

            }
            printf("\n\n");
            printf("  "); 
            DisplayHashtag();
            printf("\n\n");
			printf("\t\t <MENU>\n");
    	    printf("\t   [1]............CONTINUE\n\n\t   [2]............END TURN\n");
            
            do
			{
			    printf("\n\t\t ==> ");
                if(scanf("%d", &cQuestion));

                if(cQuestion == 1)
                {
                    nWholeCounter++;
                    nExit = 0;
            
                }
                else if(cQuestion == 2)
                {
                    nExit = 1;
                }

            }while(!(cQuestion <= 2) && (cQuestion >= 1));   

        }while(nExit == 0 && nWholeCounter < 7 );

    }
    else if(nNumber == 2) // player 2===============================================================================================
    {
        printf("\n\n");
        do
        {	
            int nAnswer = 1;
            printf("   ");
            DisplayGreater();
            DisplayLesser();
            printf("\n");
            printf("\tRemaining Alphabet Letters\n");
            for(i = 0; i < 26; i++)
            {	
                if(nLttrQntity[i] > 0)
                {
                    printf("\n\t  ALPHABET: %c ", nAsciiAlphbt[i]);
                    printf("\tQUANTITY: %d ", nLttrQntity[i]);
                }

            }
            printf("\n");
            printf("   ");
            DisplayGreater();
            DisplayLesser();
            printf("\n");

            /* Printing the name of the player and asking them what letter they want to change. */
            DisplayNewLine();
            printf("   ");
            DisplayHashtag();
            printf("\n\tWhat letter ");
			yellow();
            printf("[%s]",playertwo->S_player.cName);
			reset();
            printf(" want to change?\n");

            printf("\n\t\t   Tiles"); 
			printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {	
				cyan();
                printf("%c ", playertwo->S_tileletters.cLetterSymbol[i]);

            }
			      reset();
			      printf("\n\t   -----------------------\n");
            
			/* The above code is checking if the letter the user has entered is in the array of letters. If it
            is, it will store the value of the array in a variable. */
            while(nAnswer != 0)
            {
                printf("\t\t==> ");
				if(scanf(" %c", &cLetterChoice));
            	a = toupper(cLetterChoice);

                for(i = 0; i < 7; i++)
                {
                    if(playertwo->S_tileletters.cLetterSymbol[i] == a)
                    {
                        nPlaceHolder = nArrayCount[i];
                        nAnswer = 0;
                    }
                }      

            }
           /* The above code is checking if the letter is in the alphabet. If it is, it will add one to
           the letter count. */
            for(i = 0; i < 26 && sTopper != 1; i++)
            {
                if(nAsciiAlphbt[i] == a)
                {
                    nLttrQntity[i] += 1;
                    sTopper = 1;
                }

            }

            /* Changing the letter of the player's tile. */
            for(i = 0; i < 26; i++)
            {
                if(playertwo->S_tileletters.cLetterSymbol[i] == a)
                {

                    do
                    {	
                        cyan();
                        printf("\n\n   ");
                        DisplayGreater();
                        DisplayLesser();
                        printf("\n\t Picking a Letter from the bag!\n\t\tPicked");

                        //randomizer
                        nReturnChanger = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity,
                                                        nTileAlphabetScore);
                        yellow();								
                        printf(" [%c]\n", nAsciiAlphbt[nReturnChanger]);
                        reset();
                        cyan();
                        printf("   ");
                        DisplayGreater();
                        DisplayLesser();
                        reset();
                        printf("\n\n\n\t     Alphabet Changed!\n");

                        playertwo->S_tileletters.cLetterSymbol[nPlaceHolder] = nAsciiAlphbt[nReturnChanger];
                        playertwo->S_tileletters.nLetterScore[nPlaceHolder]  = nTileAlphabetScore[nReturnChanger];

                        for(i = 0; i < 26 && sTopper2 != 1; i++)
                        {
                            if(nAsciiAlphbt[i] == playertwo->S_tileletters.cLetterSymbol[nPlaceHolder])
                            {
                                playertwo->S_tileletters.cLetterSymbol[nPlaceHolder];
                                sTopper2 = 1;

                            }

                        }
                        nStop = 1;
                    } while(nAsciiAlphbt[i] == playertwo->S_tileletters.cLetterSymbol[nPlaceHolder] && nStop != 1); //change i

					    printf("\n\t   -----------------------\n\t\t");
                    for (i = 0; i < 7; i++)       
                    {
                        cyan();
                        printf("%c ", playertwo->S_tileletters.cLetterSymbol[i]);
                    }
                        reset();
                        printf("\n\t   -----------------------");
                }
            }
                printf("\n\n");
                printf("  ");
                DisplayHashtag();
                printf("\n\n");
                printf("\t\t <MENU>\n");
                printf("\t   [1]............CONTINUE\n\n\t   [2]............END TURN\n");
            
            do
            {
			    printf("\n\t\t ==> ");
                if(scanf("%d", &cQuestion));

                if(cQuestion == 1)
                {
                    nWholeCounter++;
                    nExit = 0;
                }
                else if(cQuestion == 2)
                {
                    nExit = 1;
                }

            }while(!(cQuestion <= 2) && (cQuestion >= 1));          

        }while(nExit == 0 && nWholeCounter < 7 );

    } 
    else if(nNumber == 3) // player 3===============================================================================================
    {
        printf("\n\n");
        do
        {	
            int nAnswer = 1;
            /* Displaying the remaining letters in the alphabet. */
            printf("   ");
            DisplayGreater();
            DisplayLesser();
			      printf("\n");
			      printf("\tRemaining Alphabet Letters\n");
            for(i = 0; i < 26; i++)
            {	
                if(nLttrQntity[i] > 0) //change
                {
                    printf("\n\t  ALPHABET: %c ", nAsciiAlphbt[i]);
                    printf("\tQUANTITY: %d ", nLttrQntity[i]);
                }

            }
			printf("\n");
            printf("   ");
			      DisplayGreater();
            DisplayLesser();
			printf("\n");

            /* Printing the name of the player and asking them what letter they want to change. */
            DisplayNewLine();
            printf("   ");
            DisplayHashtag();
            printf("\n\tWhat letter ");
			blue();
            printf("[%s]",playerthree->S_player.cName);
			reset();
            printf(" want to change?\n");

            printf("\n\t\t   Tiles"); 
			printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {	
				cyan();
                printf("%c ", playerthree->S_tileletters.cLetterSymbol[i]);

            }
			    reset();
			    printf("\n\t   -----------------------\n");
            
			/* The above code is checking if the letter the user has entered is in the array of letters. If it
            is, it will store the value of the array in a variable. */
            while(nAnswer != 0)
            {
                printf("\t\t==> ");
				if(scanf(" %c", &cLetterChoice));
            	a = toupper(cLetterChoice);

                for(i = 0; i < 7; i++)
                {
                    if(playerthree->S_tileletters.cLetterSymbol[i] == a)
                    {
                    nPlaceHolder = nArrayCount[i];
                    nAnswer = 0;
                    }
                }      

            }
			

           /* The above code is checking if the letter is in the alphabet. If it is, it will add one to
           the letter count. */
            for(i = 0; i < 26 && sTopper != 1; i++)
            {
                if(nAsciiAlphbt[i] == a)
                {
                    nLttrQntity[i] += 1;
                    sTopper = 1;
                }

            }

            /* Changing the letter of the player's tile. */
            for(i = 0; i < 26; i++)
            {
                if(playerthree->S_tileletters.cLetterSymbol[i] == a)
                {
                    do
                    {	
                        cyan();
                        printf("\n\n   ");
                        DisplayGreater();
                        DisplayLesser();
            			printf("\n\t Picking a Letter from the bag!\n\t\tPicked");

                        //randomizer
                        nReturnChanger = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity,
                                                        nTileAlphabetScore);
                            blue();								
                            printf(" [%c]\n", nAsciiAlphbt[nReturnChanger]);
                            reset();
                            cyan();
                            printf("   ");
                            DisplayGreater();
                            DisplayLesser();
                            reset();

                            printf("\n\n\n\t     Alphabet Changed!\n");

                        playerthree->S_tileletters.cLetterSymbol[nPlaceHolder] = nAsciiAlphbt[nReturnChanger];
                        playerthree->S_tileletters.nLetterScore[nPlaceHolder]  = nTileAlphabetScore[nReturnChanger];

                        for(i = 0; i < 26 && sTopper2 != 1; i++)
                        {
                            if(nAsciiAlphbt[i] == playerthree->S_tileletters.cLetterSymbol[nPlaceHolder])
                            {
                                playerthree->S_tileletters.cLetterSymbol[nPlaceHolder];
                                sTopper2 = 1;

                            }

                        }
                        nStop = 1;
                    }while(nAsciiAlphbt[i] == playerthree->S_tileletters.cLetterSymbol[nPlaceHolder] && nStop != 1); //change i

					printf("\n\t   -----------------------\n\t\t");
                    for (i = 0; i < 7; i++)
                    {
						            cyan();
                        printf("%c ", playerthree->S_tileletters.cLetterSymbol[i]);
                    }
                    reset();
                    printf("\n\t   -----------------------");
                }

            }
            printf("\n\n");
            printf("   ");
            DisplayHashtag();
            printf("\n\n");
			printf("\t\t <MENU>\n");
    	    printf("\t   [1]............CONTINUE\n\n\t   [2]............END TURN\n");
            
            do
			{
                printf("\n\t\t ==> ");
                if(scanf("%d", &cQuestion));

                if(cQuestion == 1)
                {
                    nWholeCounter++;
                    nExit = 0;
                }
                else if(cQuestion == 2)
                {
                    nExit = 1;
                }

            }while(!(cQuestion <= 2) && (cQuestion >= 1));                 

        }while(nExit == 0 && nWholeCounter < 7 );

    } 
    else if (nNumber == 4) // player 4===============================================================================================
    {
        printf("\n\n");
        do
        {	
            int nAnswer = 1;
            /* Displaying the remaining letters in the alphabet. */
            printf("   ");
            DisplayGreater();
            DisplayLesser();
            printf("\n");
            printf("\tRemaining Alphabet Letters\n");
            for(i = 0; i < 26; i++)
            {	
                if(nLttrQntity[i] > 0)
                {
                    printf("\n\t  ALPHABET: %c ", nAsciiAlphbt[i]);
                    printf("\tQUANTITY: %d ", nLttrQntity[i]);
                }

            }

			printf("\n");
            printf("   ");
			DisplayGreater();
            DisplayLesser();
			printf("\n");;

            /* Printing the name of the player and asking them what letter they want to change. */
            DisplayNewLine();
            printf("   ");
            DisplayHashtag();
            printf("\nWhat letter does ");
			green();
            printf("[%s]",playerfour->S_player.cName);
			reset();
            printf(" want to change?\n");

            printf("\n\t\t   Tiles"); 
			printf("\n\t   -----------------------\n\t\t");

            for (i = 0; i < 7; i++)
            {	
				cyan();
                printf("%c ", playerfour->S_tileletters.cLetterSymbol[i]);

            }
			    reset();
			    printf("\n\t   -----------------------\n");
            
			/* The above code is checking if the letter the user has entered is in the array of letters. If it
            is, it will store the value of the array in a variable. */
            while(nAnswer != 0)
            {
                printf("\t\t==> ");
				if(scanf(" %c", &cLetterChoice));
            	a = toupper(cLetterChoice);

                for(i = 0; i < 7; i++)
                {
                    if(playerfour->S_tileletters.cLetterSymbol[i] == a)
                    {
                        nPlaceHolder = nArrayCount[i];
                        nAnswer = 0;
                    }
                }      

            }
			
           /* The above code is checking if the letter is in the alphabet. If it is, it will add one to
           the letter count. */
            for(i = 0; i < 26 && sTopper != 1; i++)
            {
                if(nAsciiAlphbt[i] == a)
                {
                    nLttrQntity[i] += 1;
                    sTopper = 1;
                }

            }

            /* Changing the letter of the player's tile. */
            for(i = 0; i < 26; i++)
            {
                if(playerfour->S_tileletters.cLetterSymbol[i] == a)
                {

                    do
                    {	
                        cyan();
                        printf("\n\n   ");
                        DisplayGreater();
                        DisplayLesser();
            			printf("\n\t Picking a Letter from the bag!\n\t\tPicked");

                        //randomizer
                        nReturnChanger = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity,
                                                        nTileAlphabetScore);
                        green();								
                        printf(" [%c]\n", nAsciiAlphbt[nReturnChanger]);
                        reset();
                        cyan();
                        printf("   ");
                        DisplayGreater();
                        DisplayLesser();
                        reset();
                        printf("\n\n\n\t     Alphabet Changed!\n");

                        playerfour->S_tileletters.cLetterSymbol[nPlaceHolder] = nAsciiAlphbt[nReturnChanger];
                        playerfour->S_tileletters.nLetterScore[nPlaceHolder]  = nTileAlphabetScore[nReturnChanger];

                        for(i = 0; i < 26 && sTopper2 != 1; i++)
                        {
                            if(nAsciiAlphbt[i] == playerfour->S_tileletters.cLetterSymbol[nPlaceHolder])
                            {
                                playerfour->S_tileletters.cLetterSymbol[nPlaceHolder];
                                sTopper2 = 1;

                            }
                        }
                        nStop = 1;
                    }while(nAsciiAlphbt[i] == playerfour->S_tileletters.cLetterSymbol[nPlaceHolder] && nStop != 1); //change i

					printf("\n\t   -----------------------\n\t\t");
                    for (i = 0; i < 7; i++)
                    {
						            cyan();
                        printf("%c ", playerfour->S_tileletters.cLetterSymbol[i]);
                    }
                    reset();
                    printf("\n\t   -----------------------");
                }

            }
                printf("\n\n");
                printf("   ");
                DisplayHashtag();
                printf("\n\n");
                printf("\t\t <MENU>\n");
                printf("\t   [1]............CONTINUE\n\n\t   [2]............END TURN\n");
                
            do
			{
			    printf("\n\t\t ==> ");
                if(scanf("%d", &cQuestion));

                if(cQuestion == 1)
                {
                    nWholeCounter++;
                    nExit = 0;
            
                }
                else if(cQuestion == 2)
                {
                    nExit = 1;
                }

            }while(!(cQuestion <= 2) && (cQuestion >= 1));
                  
        }while(nExit == 0 && nWholeCounter < 7 );

    } 


}



/*
    this code gets randomized tiles, replaces tiles, and place tiles on the board, checks if word is valid
*/
int
PssngLttersPlayers(PlayerAndLetters *playerone,
                   PlayerAndLetters *playertwo,
                   PlayerAndLetters *playerthree,
                   PlayerAndLetters *playerfour,
                   int nAsciiAlphbt[], int nLttrQntity[],
                   int nTileAlphabetScore[], int nPlayerCount,
                   char BOARD[][11], int roundnumber)
{

    int     i,
            j,  
            nRdmNm,
            nNumber,
            nReturn1 = 0,
            nReturn2 = 0,
            nReturn3 = 0,
            nReturn4 = 0,
            nGameCounter = 0, 
            nplayerrnt = 0;

    int     nChangeTiles1 = 0,
            nChangeTiles2 = 0,
            nChangeTiles3 = 0,
            nChangeTiles4 = 0,
            ValidWordBa = 0,
            TwelveValidWords = 0;

    char wordofplayer[20];

    nBackZero nArryStoreOne,
              nArryStoreOne2,
              nArryStoreTwo,
              nArryStoreTwo2,
              nArryStoreThree,
              nArryStoreThree2,
              nArryStoreFour,
              nArryStoreFour2;

    if (nPlayerCount == 2 || nPlayerCount == 3 || nPlayerCount == 4)
    {    
      while(playerone->S_player.nStopper == 0)
      {    

            DisplayNewLine();
            printf("  ");           
            DisplayHashtag();
            red();
            printf("\n\n<<<<[%s] GETTING TILES>>>>\n\n",playerone->S_player.cName);
            reset();
            for (i = 0; i < 7; i++)
            {
            nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
            nArryStoreOne[i] = nAsciiAlphbt[nRdmNm];
            nArryStoreOne2[i] = nTileAlphabetScore[nRdmNm];
            playerone->S_tileletters.cLetterSymbol[i] = nArryStoreOne[i];
            playerone->S_tileletters.nLetterScore[i] = nArryStoreOne2[i];
            printf("\tALPHALETTER: %c\t\t", playerone->S_tileletters.cLetterSymbol[i]);
            printf("SCORE: %d\n", playerone->S_tileletters.nLetterScore[i]);
            if(i == 6)
            {
                playerone->S_player.nStopper = 1;
            }
            }
            printf("\n");
            printf("  ");
            DisplayHashtag();        
            }; //remove ; ?
       
        while(nReturn1 != 1)
        {
            
            DisplayNewLine();
            printf("  ");
            DisplayHashtag();
            printf("\n\t");
            DisplayEquals();
            
            
    
            red();
            printf("\n[%s's TURN]",playerone->S_player.cName);
            reset();

            //SHOW LETTERS
            printf("\n\t\t   Tiles"); 
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerone->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------");

            printf("\n\n\n\t\t <MENU>");
            printf("\n\n\t[1]............REPLACE TILES\n\n\t[2]............PUT TILES ON BOARD\n");
            printf("\n\t\t==> ");
            scanf("%d",&nChangeTiles1);

            printf("\n\t");
            DisplayEquals();
            printf("   ");
            DisplayHashtag();
            printf("\n");
            

            if(nChangeTiles1 == 1)
            {
                nNumber = 1;
                nChangeUserLetter(playerone, playertwo,
                                    playerthree, playerfour,
                                    nAsciiAlphbt, nLttrQntity,
                                    nTileAlphabetScore, nNumber,
                                    nPlayerCount);

            //makita yung nawawala
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerone->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------");

            nReturn1 = 1;
        
            }
            else if(nChangeTiles1 == 2)
            {
                // TODO: make an do while until valid i balik
                nplayerrnt = 1;
                ValidWordBa = IsValidWord(playerone, playertwo, playerthree, playerfour,
                                        nPlayerCount, nAsciiAlphbt, nLttrQntity,
                                        nTileAlphabetScore, nplayerrnt);
                strcpy(wordofplayer, playerone->S_player.cValidWord);
                
                if(ValidWordBa == 1)
                {
                    playerone->S_player.TwelveValidWords++;
                    getMove(BOARD, roundnumber, wordofplayer);                            
                    roundnumber++;
                }
                
                nReturn1 = 1;

            }
            
        }

        while(playertwo->S_player.nStopper == 0)
        {
        //player 2
        
            DisplayNewLine(); 
            printf("  ");           
            DisplayHashtag();
            yellow();
            printf("\n\n<<<<[%s]GETTING TILES>>>>\n\n",playertwo->S_player.cName);
            reset();
            for (i = 0; i < 7; i++)
            {            
                nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                nArryStoreTwo[i] = nAsciiAlphbt[nRdmNm];
                nArryStoreTwo2[i] = nTileAlphabetScore[nRdmNm];
                playertwo->S_tileletters.cLetterSymbol[i] = nArryStoreTwo[i];
                playertwo->S_tileletters.nLetterScore[i] = nArryStoreTwo2[i];
                printf("\tALPHALETTER: %c\t\t", playertwo->S_tileletters.cLetterSymbol[i]);
                printf("SCORE: %d\n", playertwo->S_tileletters.nLetterScore[i]);
                if(i == 6)
                {
                    playertwo->S_player.nStopper = 2;
                }

            }
            printf("\n");
            printf("  ");
            DisplayHashtag(); 
        };

        while(nReturn2 != 1)
        {
            DisplayNewLine();
            printf("  ");
            DisplayHashtag();
            printf("\n\t");
            DisplayEquals();

            yellow();
            printf("\n\n[%s's TURN]",playertwo->S_player.cName);
            reset();
            
            //show letters
            printf("\n\t\t   Tiles"); 
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playertwo->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------");

            printf("\n\n\n\t\t <MENU>");
            printf("\n\n\t[1]............REPLACE TILES\n\n\t[2]............PUT TILES ON BOARD\n");
            printf("\n\t\t==> ");
            scanf("%d",&nChangeTiles2);

            printf("\n\t");
            DisplayEquals();
            printf("   ");
            DisplayHashtag();
            printf("\n");

            if(nChangeTiles2 == 1)
            {
                nNumber = 2;
                nChangeUserLetter(playerone, playertwo,
                                playerthree, playerfour,
                                nAsciiAlphbt, nLttrQntity,
                                nTileAlphabetScore, nNumber,
                                nPlayerCount);
                //lettters               
                printf("\n\t   -----------------------\n\t\t");
                for (i = 0; i < 7; i++)
                {
                    cyan();
                    printf("%c ", playertwo->S_tileletters.cLetterSymbol[i]);
                }
                reset();
                printf("\n\t   -----------------------");
                
                nReturn2 = 1;
            
            }
            else if (nChangeTiles2 == 2)
            {
                nplayerrnt = 2;
                ValidWordBa = IsValidWord(playerone, playertwo, playerthree, playerfour,
                                        nPlayerCount, nAsciiAlphbt, nLttrQntity,
                                        nTileAlphabetScore,  nplayerrnt);

                strcpy(wordofplayer, playertwo->S_player.cValidWord);
                if(ValidWordBa == 1)
                {
                    playertwo->S_player.TwelveValidWords;
                    getMove(BOARD, roundnumber, wordofplayer);
                    roundnumber++;
                }
                nReturn2 = 1;
                j = 0;

            }
        }

        
            
    }
    if (nPlayerCount == 3 || nPlayerCount == 4)
    {
        while(playerthree->S_player.nStopper == 0)
        {
            //player3
            DisplayNewLine();
            printf("  ");           
            DisplayHashtag();
            blue();
            printf("\n\n<<<<[%s] GETTING TILES>>>>\n\n",playerthree->S_player.cName);
            reset();
        for (i = 0; i < 7; i++)
        {
            nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
            nArryStoreThree[i] = nAsciiAlphbt[nRdmNm];
            nArryStoreThree2[i] = nTileAlphabetScore[nRdmNm];
            playerthree->S_tileletters.cLetterSymbol[i] = nArryStoreThree[i];
            playerthree->S_tileletters.nLetterScore[i] = nArryStoreThree2[i];
            printf("\tALPHALETTER: %c\t\t", playerthree->S_tileletters.cLetterSymbol[i]);
            printf("SCORE: %d\n", playerthree->S_tileletters.nLetterScore[i]);
            if(i == 6)
            {
            playerthree->S_player.nStopper = 1;
            }

        }
            printf("\n");
            printf("  ");
            DisplayHashtag();
        };

        while(nReturn3 != 1)
        {
            DisplayNewLine();
            printf("  ");
            DisplayHashtag();
            printf("\n\t");
            DisplayEquals();

            blue();
            printf("\n\n[%s's TURN]",playerthree->S_player.cName);
            reset();

            //SHOW LETTERS
            printf("\n\t\t   Tiles");
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerthree->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------");

            printf("\n\n\n\t\t <MENU>");
            printf("\n\n\t[1]............REPLACE TILES\n\n\t[2]............PUT TILES ON BOARD\n");
            printf("\n\t\t==> ");
            scanf("%d",&nChangeTiles3);

            printf("\n\t");
            DisplayEquals();
            printf("   ");
            DisplayHashtag();
            printf("\n");

            if(nChangeTiles3 == 1)
            {
                nNumber = 3;
                nChangeUserLetter(playerone, playertwo,
                                    playerthree, playerfour,
                                    nAsciiAlphbt, nLttrQntity,
                                    nTileAlphabetScore, nNumber,
                                    nPlayerCount);

                printf("\n\t   -----------------------\n\t\t");
                for (i = 0; i < 7; i++)
                {
                    cyan();
                    printf("%c ", playerthree->S_tileletters.cLetterSymbol[i]);
                }
                reset();
                printf("\n\t   -----------------------");

                nReturn3 = 1;

            }
            else if (nChangeTiles3 == 2)
            {
                nplayerrnt = 3;
                ValidWordBa = IsValidWord(playerone, playertwo, playerthree, playerfour,
                                                nPlayerCount, nAsciiAlphbt, nLttrQntity,
                                                nTileAlphabetScore,  nplayerrnt);

                strcpy(wordofplayer, playerthree->S_player.cValidWord);
                if(ValidWordBa == 1)
                {
                    playerthree->S_player.TwelveValidWords;
                    getMove(BOARD, roundnumber, wordofplayer);                            
                            roundnumber++;
                }
                nReturn3 = 1;
            }
            
        }
    }
    if (nPlayerCount == 4)
    {   
        while(playerfour->S_player.nStopper == 0)
        {
            //playerfour
            DisplayNewLine();
            printf("  ");           
            DisplayHashtag();
            green();
            printf("\n\n<<<<[%s]: GETTING TILES>>>>\n\n",playerfour->S_player.cName);
            reset();
            for (i = 0; i < 7; i++)
            {
                nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                nArryStoreFour[i] = nAsciiAlphbt[nRdmNm];
                nArryStoreFour2[i] = nTileAlphabetScore[nRdmNm];
                playerfour->S_tileletters.cLetterSymbol[i] = nArryStoreFour[i];
                playerfour->S_tileletters.nLetterScore[i] = nArryStoreFour2[i];
                printf("\tALPHALETTER: %c\t\t", playerfour->S_tileletters.cLetterSymbol[i]);
                printf("SCORE: %d\n", playerfour->S_tileletters.nLetterScore[i]);
                if(i == 6)
                {
                playerfour->S_player.nStopper = 1;
                }

            }
            printf("\n");
            printf("  ");
            DisplayHashtag();    
        };

        while(nReturn4 != 1)
        {
            DisplayNewLine();
            printf("  ");
            DisplayHashtag();
            printf("\n\t");
            DisplayEquals();

            green();
            printf("\n\n[%s's TURN]",playerfour->S_player.cName);
            reset();

            //SHOW LETTERS
            printf("\n\t\t   Tiles"); 
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerfour->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------");

            printf("\n\n\n\t\t <MENU>");
            printf("\n\n\t[1]............REPLACE TILES\n\n\t[2]............PUT TILES ON BOARD\n");
            printf("\n\t\t==> ");
            scanf("%d",&nChangeTiles4);

            printf("\n\t");
            DisplayEquals();
            printf("   ");
            DisplayHashtag();
            printf("\n");

            if(nChangeTiles4 == 1)
            {
                nNumber = 4;
                nChangeUserLetter(playerone, playertwo,
                                    playerthree, playerfour,
                                    nAsciiAlphbt, nLttrQntity,
                                    nTileAlphabetScore, nNumber,
                                    nPlayerCount);

                 //makita yung nawawala
                printf("\n\t   -----------------------\n\t\t");
                for (i = 0; i < 7; i++)
                {
                    cyan();
                    printf("%c ", playerfour->S_tileletters.cLetterSymbol[i]);
                }
                reset();
                printf("\n\t   -----------------------"); 

                nReturn4 = 1;
            }
            else if (nChangeTiles4 == 2)
            {
                nplayerrnt = 4;
                ValidWordBa = IsValidWord(playerone, playertwo, playerthree, playerfour,
                                                nPlayerCount, nAsciiAlphbt, nLttrQntity,
                                                nTileAlphabetScore,  nplayerrnt);

                strcpy(wordofplayer, playerfour->S_player.cValidWord);
                if(ValidWordBa == 1)
                {
                    playerfour->S_player.TwelveValidWords;
                    getMove(BOARD, roundnumber, wordofplayer);                            
                    roundnumber++;
                }
                
                nReturn4 = 1;
            }
            
        }
    }


    return 1;

}


//The above code is checking if the word is valid.
int
IsValidWord(PlayerAndLetters *playerone, PlayerAndLetters *playertwo,
            PlayerAndLetters *playerthree, PlayerAndLetters *playerfour,
            int nPlayerCount, int nAsciiAlphbt[], int nLttrQntity[],
            int nTileAlphabetScore[],  int nplayerrnt)
{
    FILE * cDctnry;

    int nValue = 0,
        i,
        j,
        nNotZero = 1,
        nNotZero2 = 1,
        ValidChecker = 1,
        c = 0,//super need
        nRdmNm = 0,
        nCountrLen = 0,
        nusercount = 0;

    char cData[100];
    char inputUser[50];	// global variable to kanina
    char endalpha;
    char nCOMPARER[10];
    char nHello = {'@'};

    cDctnry = fopen("Dictionary1.txt", "r");

    if (cDctnry == NULL)

    {
      printf("ERROR: 404");
    }
    else
    {
        //Allocating memory for the structure.
        ScrabbleDictionary *cFirstWord = malloc(sizeof(ScrabbleDictionary));
        ScrabbleDictionary *cSecondWord =  malloc(sizeof(ScrabbleDictionary));
        cFirstWord->nWordOne;
        cSecondWord->nWordOne;   
       
        // if(nplayerrnt == 1 || if(nplayerrnt == 2)
        if(nplayerrnt == 1)
        {
//............................................................................................................................
            //PLAYER 1
            
            red();
            printf("[%s]",playerone->S_player.cName);
			reset();
            printf("\n\t\tEnter your word: ");
            printf("\n\t\t  ==> ");
            if(scanf("%s", inputUser));
            char *p = inputUser;
            toupper(*p);
            cCaptilizingWord(*&p);
            printf("\n");          

            nusercount = strlen(inputUser);//add
        
            for(i = 0; i < nusercount; i++)
	   	    {
                endalpha = p[i];
	   		
		    }
            /* Checking if the word is valid. */
            while (*p != '\0')
            {

                for (j = 0; j < 7 && nNotZero != 0; j++)	// meron yann NotZero = 0;
                {
                    
                    if(playerone->S_tileletters.cLetterSymbol[j] == p[c])
                    {
						playerone->S_player.nPoints = playerone->S_player.nPoints + playerone->S_tileletters.nLetterScore[j];                	        
					 	nNotZero = 1;
					 	ValidChecker = 1;
                        nLttrQntity[j]--;     	         
                        playerone->S_tileletters.cLetterSymbol[j] = nHello;
                        
					 	if(p[c] == endalpha && j == 6)
					 	{
					 		nNotZero = 0;
                            
						}
						j = -1;
						c++;
                        nCountrLen++; //add
                        						
                    }
                    else if(nCountrLen != nusercount && j == 6)//add
                    {
                        ValidChecker = 0;
                    }
                  
                }
                p++;	
            }
                          
            for(i = 0; i < 7; i++)
            {
                if(playerone->S_tileletters.cLetterSymbol[i] == nHello)
                {
                    nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                    playerone->S_tileletters.cLetterSymbol[i] = nAsciiAlphbt[nRdmNm];
                    playerone->S_tileletters.nLetterScore[i]= nTileAlphabetScore[nRdmNm]; 

                }
                    
            }         
            strcpy(cFirstWord->nWordOne , inputUser);
        
            /* Comparing the first word in the dictionary to the second word in the dictionary. */
            while(fgets(cData , 100 , cDctnry) != NULL && nValue != 1)
            {
                strcpy(cSecondWord->nWordOne, strtok(cData, "\n"));//segmentationn   
                nValue = !strcmp(cFirstWord->nWordOne, cSecondWord->nWordOne);        
            }
           
            
            if (nValue == 1)
            {
                printf("\n\n\t\t ++++WORD FOUND++++\n");
                printf("\n\t\t***********\n");
                printf("\n\t\t>>>>%s's POINTS: %d<<<<\n\n",playerone->S_player.cName,playerone->S_player.nPoints);
                strcpy(playerone->S_player.cValidWord, cFirstWord->nWordOne);
                return 1;
            }
            else if(nValue == 0)
            {
                printf("\n\t   =====INVALID INPUT=====\n");
                printf("\n\t    =====NEXT TURN=====\n");
            }

            fclose(cDctnry);

        }
//............................................................................................................................
            //PLAYER 2
            if(nplayerrnt == 2)
            {
            yellow();
            printf("[%s]",playertwo->S_player.cName);
		    reset();
            printf("\n\t  Enter your word:");
            printf("\n\t\t==> ");
            if(scanf("%s", inputUser));
            char *p2 = inputUser;
            toupper(*p2);
            cCaptilizingWord(*&p2);
            printf("\n");

             for(i = 0; i < strlen(inputUser); i++)
	   	    { 		
	   		    endalpha = p2[i];
	   		
		    }

            while (*p2 != '\0')
            {
                for (j = 0; j < 7 && nNotZero2 != 0;j++)	// meron yann NotZero = 0;
                {
                    if (playertwo->S_tileletters.cLetterSymbol[j] == p2[c])
                    {
                        playertwo->S_player.nPoints = playertwo->S_player.nPoints + playertwo->S_tileletters.nLetterScore[j];                	        
					 	nNotZero = 1;
					 	ValidChecker = 1;
                        nLttrQntity[j]--; 
                        playertwo->S_tileletters.cLetterSymbol[j] = nHello;    	                
                    
					 	if(p2[c] == endalpha && j == 7)
					 	{
					 		nNotZero = 0;
                        }
						j = -1;
						c++;
                        
                    }
                    else
                    {
                        ValidChecker = 0;
                    }
                }
                p2++;	
            }

            for(i = 0; i < 7; i++)
            {
                if(playertwo->S_tileletters.cLetterSymbol[i] == nHello)
                {
                    nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                    playertwo->S_tileletters.cLetterSymbol[i] = nAsciiAlphbt[nRdmNm];
                    playertwo->S_tileletters.nLetterScore[i]= nTileAlphabetScore[nRdmNm]; 

                }
                    
            }

            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playertwo->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------\n");

           
            strcpy(cFirstWord->nWordOne , inputUser);

            while(fgets(cData , 100 , cDctnry) != NULL && nValue != 1)
            {
                strcpy(cSecondWord->nWordOne, strtok(cData, "\n"));
                nValue = !strcmp(cFirstWord->nWordOne, cSecondWord->nWordOne); 
        
            }
            
            if (nValue == 1)
            {
                printf("\n\n\t\t ++++WORD FOUND++++\n");
                printf("\n\t\t***********\n");
                printf("\n\t\t>>>>%s's POINTS: %d<<<<\n\n",playertwo->S_player.cName,playertwo->S_player.nPoints);
                strcpy(playertwo->S_player.cValidWord, cFirstWord->nWordOne);
                return 1;
            }
            else if(nValue == 0)
            {
                printf("\n\t   =====INVALID INPUT=====\n");
                printf("\n\t    =====NEXT TURN=====\n");
            }

            fclose(cDctnry);
        }
//............................................................................................................................
        //PLAYER 3
        if(nplayerrnt == 3)
        {         
            blue();
            printf("[%s]",playerthree->S_player.cName);
            reset();
            printf("\n\t\t  Enter your word: ");
            printf("\n\t\t  ==> ");
            if(scanf("%s", inputUser));
            char *p3 = inputUser;
            toupper(*p3);
            cCaptilizingWord(*&p3);
            printf("\n");
            
            for(i = 0; i < strlen(inputUser); i++)
	   	    { 		
	   		    endalpha = p3[i];
	   		
		    }
        
            while (*p3 != '\0')
            {
                for (j = 0; j < 7 && nNotZero != 0; j++)
                {
                    if (playerthree->S_tileletters.cLetterSymbol[j] == p3[c])
                    {
						playerthree->S_player.nPoints = playerthree->S_player.nPoints + playerthree->S_tileletters.nLetterScore[j];                	        
					 	nNotZero = 1;
					 	ValidChecker = 1;
                        nLttrQntity[j]--;       	                
                        playerthree->S_tileletters.cLetterSymbol[j] = nHello;

					 	if(p3[c] == endalpha && j == 7)
					 	{
					 		nNotZero = 0;
                        }
						j = -1;
						c++;
						
                    }
                    else
                    {
                        ValidChecker = 0;
                    }
                    
                }
                
                p3++;
            }
            
            for(i = 0; i < 7; i++)
            {
                if(playerthree->S_tileletters.cLetterSymbol[i] == nHello)
                {
                    nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                    playerthree->S_tileletters.cLetterSymbol[i] = nAsciiAlphbt[nRdmNm];
                    playerthree->S_tileletters.nLetterScore[i]= nTileAlphabetScore[nRdmNm]; 
                }
                    
            }

            //tiles
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerthree->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------\n");


            strcpy(cFirstWord->nWordOne , inputUser);
            while(fgets(cData , 100 , cDctnry) != NULL && nValue != 1)
            {
                strcpy(cSecondWord->nWordOne, strtok(cData, "\n"));
                nValue = !strcmp(cFirstWord->nWordOne, cSecondWord->nWordOne);
            }
  
            
            if (nValue == 1)
            {
                printf("\n\n\t\t ++++WORD FOUND++++\n");
                printf("\n\t\t***********\n");
                printf("\n\t\t>>>>%s's POINTS: %d<<<<\n\n", playerthree->S_player.cName,playerthree->S_player.nPoints);
                strcpy(playerthree->S_player.cValidWord, cFirstWord->nWordOne);
                return 1;
            }   
            else if(nValue == 0)
            {
                printf("\n\t   =====INVALID INPUT=====\n");
                printf("\n\t    =====NEXT TURN=====\n");
            }
            
            fclose(cDctnry);
        }
        if(nplayerrnt == 4)
        {
//............................................................................................................................
            //PLAYER 4
            green();
            printf("[%s]",playerfour->S_player.cName);
			reset();
            printf("\n\t\t  Enter your word: ");
            printf("\n\t\t  ==> ");
            if(scanf("%s", inputUser));
            char *p4 = inputUser;
            toupper(*p4);
            cCaptilizingWord(*&p4);
            printf("\n");
            
            for(i = 0; i < strlen(inputUser); i++)
	   	    {
	   		    endalpha = p4[i];
	   		
		    }
            
            while (*p4 != '\0')
            {
                for (j = 0; j < 7 && nNotZero != 0; j++)	// meron yann NotZero = 0;
                {
                    if (playerfour->S_tileletters.cLetterSymbol[j] == p4[c])
                    {
						playerfour->S_player.nPoints = playerfour->S_player.nPoints + playerfour->S_tileletters.nLetterScore[j];                	        
					 	nNotZero = 1;
					 	ValidChecker = 1;
                        nLttrQntity[j]--;  
                        playerfour->S_tileletters.cLetterSymbol[j] = nHello;   	           	                
                    
					 	if(p4[c] == endalpha && j == 7)
					 	{
					 		nNotZero = 0;
                        }
						j = -1;
						c++;
						
                    }
                    else
                    {
                        ValidChecker = 0;
                    }
                }
                p4++;	
            }
 
            for(i = 0; i < 7; i++)
            {
                if(playerfour->S_tileletters.cLetterSymbol[i] == nHello)
                {
                    nRdmNm = SrtngPntsLttrs(nAsciiAlphbt, nLttrQntity, nTileAlphabetScore);
                    playerfour->S_tileletters.cLetterSymbol[i] = nAsciiAlphbt[nRdmNm];
                    playerfour->S_tileletters.nLetterScore[i]= nTileAlphabetScore[nRdmNm]; 
                }
                    
            }
            //tiles
            printf("\n\t   -----------------------\n\t\t");
            for (i = 0; i < 7; i++)
            {
                cyan();
                printf("%c ", playerfour->S_tileletters.cLetterSymbol[i]);
            }
            reset();
            printf("\n\t   -----------------------\n");

            strcpy(cFirstWord->nWordOne , inputUser);
        
            while(fgets(cData , 100 , cDctnry) != NULL && nValue != 1)
            {
                strcpy(cSecondWord->nWordOne, strtok(cData, "\n"));
                nValue = !strcmp(cFirstWord->nWordOne, cSecondWord->nWordOne);
            }
            
            
            if (nValue == 1)
            {
                printf("\n\n\t\t ++++WORD FOUND++++\n");
                printf("\n\t\t***********\n");
                printf("\n\t\t>>>>%s's POINTS: %d<<<<\n\n",playerfour->S_player.cName,playerfour->S_player.nPoints);
                strcpy(playerfour->S_player.cValidWord, cFirstWord->nWordOne);
                return 1;
            }
            else if(nValue == 0)
            {
                printf("\n\t   =====INVALID INPUT=====\n");
                printf("\n\t    =====NEXT TURN=====\n");
                return 0; //new
            }
            
            fclose(cDctnry);
            
        }
    }

}

//The above code is checking to see if the longest word is less than the valid word. 
//If it is, then it will copy the valid word into the longest word. 
//If it is equal to the valid word, then it will copy the valid word into the longest word. If it is greater than the valid word, then it will print the longest word.
void 
cLongestWord(PlayerAndLetters *playerone,
              PlayerAndLetters *playertwo,
              PlayerAndLetters *playerthree,
              PlayerAndLetters *playerfour)
{
   
    //player 1
    if(strlen(playerone->S_player.cLongestWord) < strlen(playerone->S_player.cValidWord))
    {
        strcpy(playerone->S_player.cLongestWord, playerone->S_player.cValidWord);
        printf("\n%s\n", playerone->S_player.cLongestWord);
    }
    else if(strlen(playerone->S_player.cLongestWord) == strlen(playerone->S_player.cValidWord))
    {
        strcpy(playerone->S_player.cLongestWord, playerone->S_player.cValidWord);
        printf("\n%s\n", playerone->S_player.cLongestWord);

    }
    else if(strlen(playerone->S_player.cLongestWord) > strlen(playerone->S_player.cValidWord))
    {
        printf("\n%s\n", playerone->S_player.cLongestWord);
    }

    //player 2
    if(strlen(playertwo->S_player.cLongestWord) < strlen(playertwo->S_player.cValidWord))
    {
        strcpy(playertwo->S_player.cLongestWord, playertwo->S_player.cValidWord);
        printf("\n%s\n", playertwo->S_player.cLongestWord);
    }
    else if(strlen(playertwo->S_player.cLongestWord) == strlen(playertwo->S_player.cValidWord))
    {
        strcpy(playertwo->S_player.cLongestWord, playertwo->S_player.cValidWord);
        printf("\n%s\n", playertwo->S_player.cLongestWord);
    }
    else if(strlen(playertwo->S_player.cLongestWord) > strlen(playertwo->S_player.cValidWord))
    {
        printf("\n%s\n", playertwo->S_player.cLongestWord);
    }

    //player 2
     if(strlen(playerthree->S_player.cLongestWord) < strlen(playerthree->S_player.cValidWord))
    {
        strcpy(playerthree->S_player.cLongestWord, playerthree->S_player.cValidWord);
        printf("\n%s\n", playerthree->S_player.cLongestWord);
    }
    else if(strlen(playerthree->S_player.cLongestWord) == strlen(playerthree->S_player.cValidWord))
    {
        strcpy(playerthree->S_player.cLongestWord, playerthree->S_player.cValidWord);
        printf("\n%s\n", playerthree->S_player.cLongestWord);
    }
    else if(strlen(playerthree->S_player.cLongestWord) > strlen(playerthree->S_player.cValidWord))
    {
        
        printf("\n%s\n", playerthree->S_player.cLongestWord);
    }

    //player 4
    if(strlen(playerfour->S_player.cLongestWord) < strlen(playerfour->S_player.cValidWord))
    {
        strcpy(playerfour->S_player.cLongestWord, playerfour->S_player.cValidWord);
        printf("\n%s\n", playerfour->S_player.cLongestWord);
    } 
    else if(strlen(playerfour->S_player.cLongestWord) == strlen(playerfour->S_player.cValidWord))
    {
        strcpy(playerfour->S_player.cLongestWord, playerfour->S_player.cValidWord);
        printf("\n%s\n", playerfour->S_player.cLongestWord);

    }else if (strlen(playerfour->S_player.cLongestWord) > strlen(playerfour->S_player.cValidWord))
    {
        printf("\n%s\n", playerfour->S_player.cLongestWord);
    }
    
}


/*
The above code is comparing the highest score of the player 
and the real time score of the player.
*/

void
nHighestScore(PlayerAndLetters *playerone,
                 PlayerAndLetters *playertwo,
                 PlayerAndLetters *playerthree,
                 PlayerAndLetters *playerfour,
                 int nPlayerWho)
{


    //player 1
    /* Comparing the highest score of the player and the real time score of the player. */
    if(nPlayerWho == 1 && playerone->S_player.nHighestScore < playerone->S_player.nRealTimeScore)
    {
        playerone->S_player.nHighestScore = playerone->S_player.nRealTimeScore;
        printf("New Highscore[%s]: %d", playerone->S_player.cName,playerone->S_player.nHighestScore);
    }
    else if(nPlayerWho == 1 && playerone->S_player.nHighestScore > playerone->S_player.nRealTimeScore)
    {
        
        printf("Previous Highscore[%s]: %d", playerone->S_player.cName, playerone->S_player.nHighestScore);
    }

    //player 2
    if(nPlayerWho == 2 && playertwo->S_player.nHighestScore < playertwo->S_player.nRealTimeScore) 
    {
        playertwo->S_player.nHighestScore = playertwo->S_player.nRealTimeScore;
        printf("New Highscore[%s]: %d", playertwo->S_player.cName, playertwo->S_player.nHighestScore);
    }
    else if (nPlayerWho == 2 && playertwo->S_player.nHighestScore > playertwo->S_player.nRealTimeScore) 
    {
        printf("Previous Highscore[%s]: %d", playertwo->S_player.cName, playertwo->S_player.nHighestScore);
    }

    //player 3
    if(nPlayerWho == 3 && playerthree->S_player.nHighestScore < playerthree->S_player.nRealTimeScore)
    {
        playerthree->S_player.nHighestScore = playerthree->S_player.nRealTimeScore;
        printf("New Highscore[%s]: %d", playerthree->S_player.cName, playerthree->S_player.nHighestScore);
    }
    else if(nPlayerWho == 3 && playerthree->S_player.nHighestScore > playerthree->S_player.nRealTimeScore)
    {
        printf("Previous Highscore[%s]: %d", playerthree->S_player.cName, playerthree->S_player.nHighestScore);
    }

    //player 4
    if(nPlayerWho == 4 && playerfour->S_player.nHighestScore < playerfour->S_player.nRealTimeScore)
    {
        playerfour->S_player.nHighestScore = playerfour->S_player.nRealTimeScore;
        printf("New Highscore[%s]: %d", playerfour->S_player.cName, playerfour->S_player.nHighestScore);
    }
    else if(nPlayerWho == 4 && playerfour->S_player.nHighestScore > playerfour->S_player.nRealTimeScore)
    {
        printf("Previous Highscore[%s]: %d", playerfour->S_player.cName, playerfour->S_player.nHighestScore);
    }

}

//semi important
//The above code is converting the lower case letters to upper case letters.
void cCaptilizingWord(char *cWord)
{
    int i;

    for (i = 0; cWord[i]!='\0'; i++) 
    {
      if(cWord[i] >= 'a' && cWord[i] <= 'z') 
      {
         cWord[i] = cWord[i] -32;
      }
   }
   
}

//The above code is a function that displays a menu for the user to choose from.
int
StartUpMenu(int nDecision)
{
    printf("\t\t <MENU>\n");
    printf("\t   [1]............PLAY\n\n\t   [2]............EXIT\n\n\t   [3]............RECORD \n");

    do
    {
        printf("\n\t\t==> ");
        if(scanf("%d", &nDecision));

    }while(!(nDecision <= 3) && (nDecision >= 1));
    
    if (nDecision == 1)
    {
        //system("cls");
        return 1;
    }
    else if (nDecision == 2)
    {
    printf("\nThank you for playing!\n");
        return 2;
    }
    else if(nDecision == 3)
    {
        return 3;
    }
    
}

/*
The above code is asking the user to choose the 
number of players that will play the game.
*/

int
ChoosePlayerNumbers()
{
    int nPlayerNumbers;

    printf("\n\n\n\n\t<HOW MANY PLAYERS WILL PLAY>\n\n");
    printf("\t   |2|PLAYERS 1 & 2\n\n");
    printf("\t   |3|PLAYERS 1, 2 & 3\n\n");
    printf("\t   |4|PLAYERS 1, 2 ,3 & 4\n");
    do
    {
    printf("\n\t\t==> ");
    if(scanf("%d", &nPlayerNumbers));

    }while(!(nPlayerNumbers >= 2 && nPlayerNumbers <= 4));

    printf("\n\n");
    return nPlayerNumbers;
}

//name player
void
nNameOfPlayer(NamePlayer cNameofplayer)
{
    //make  a for loop asking the name using[i]
    if(scanf("%s", cNameofplayer));
}





//not important

void TitleScreen() 
{
  DisplayNewLine(); /*displays '\n' */
  blue();
  DisplayAsterisk();
  cyan();
  DisplayHashtag();
  printf("\n\n");
  yellow();
  printf("\t   [Let's ");
  printf("Play");
  red ();
  printf(" Scrabble]");
  printf("\n\n");
  green();
  DisplayHashtag();
  blue();
  printf("\n");
  DisplayAsterisk();
  printf("\n\n");
  reset();
}

void DisplayNewLine() 
{
    int counter; /* declares a variable*/
    for (counter = 0; counter <= 3; counter++)
    printf("\n"); /* prints out new lines*/
}

void DisplayAsterisk() 
{
    int counter; /* declares a variable*/
    for (counter = 0; counter <= 42; counter++)
    printf("*"); /* prints out asterisks*/

    printf("\n");
}

void
DisplayEquals()
{
    int	counter;/* declares a variable*/
    for(counter = 0; counter <= 30; counter++)
            printf("=");/* prints out asterisks*/

    printf("\n");
}

void
DisplayGreater()
{
    int counter;/* declares a variable*/
    for(counter = 0; counter <= 20; counter++)
    printf(">");/* prints out new lines*/
	
}
void
DisplayLesser()
{
    int counter;/* declares a variable*/
    for(counter = 0; counter <= 20; counter++)
    printf("<");/* prints out new lines*/
	
}

void
DisplayHashtag()
{
	int counter;/* declares a variable*/
	for(counter = 0; counter <= 42; counter++)
	printf("#");/* prints out new lines*/
	
}

// colors
void red () 
{
  printf("\033[1;31m");
}

void yellow()
{
  printf("\033[1;33m");
}

void blue()
{
  printf("\033[0;34m");
}

void green()
{
  printf("\033[0;32m");
}

void cyan()
{
  printf("\033[0;36m");
}

void reset() 
{
  printf("\033[0m");
}






