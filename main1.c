/*
Description: <This is a scrabble game where at first it will ask if you will
want to play the game, num of players, enter your unique names, get randomized 7
tiles for each player, will ask to replace tiles/put tiles on board, ask for a
valid word, ask if horizontal/vertical placement, ask coordinates, first word
will have to touch center, the rest have to touch letters and not blank spaces.
when game ends, it will write playerdata into a file, then next game it will
read it, then end of that it will append more data into a file.>

Programmed by: <RAMOS, Irish Jane> 
               <CHAN, Kendrick Martin>  
  
section         <S14>

Last modified: <05/12/2022>

Version: <5>

[Acknowledgements: <Teacher's Modules>, <tutorialspoint.com-stdio.h, ctype.h, 
                    stdlib.h, stdbool.h, time.h, math.h, sting.h> ]
*/

#include "function1.h"

int main() {
  char BOARD[11][11];
  int i = 0, 
          j, 
          nDecision,
          nPlayerCount,
          gameends = 0, 
          roundnumber = 1,
          nEnder = 1;

  NamePlayer cNmPss;

  PlayerAndLetters playerone;

  nStatsPlayerOne(&playerone);

  PlayerAndLetters playertwo;

  nStatsPlayerOne(&playerone);

  PlayerAndLetters playerthree;

  nStatsPlayerOne(&playerthree);

  PlayerAndLetters playerfour;

  nStatsPlayerOne(&playerfour);

  int nAsciiAlphbt[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z'
                         };

  int nLttrQntity[] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2,
                       6, 8, 2, 1, 6,  4, 6, 4, 2, 2, 1, 2, 1};

  int nTileAlphabetScore[] = { 1, 3, 3, 2, 1, 4, 2,
                               4, 1, 8, 5, 1, 3, 1,
                               1, 3, 10, 1, 1, 1, 1,
                               4, 4, 8, 4, 10
                              };

  srand(time(NULL));
  Letters_Scrabble ArryIntializer;
        
     // board initialization
    for (i = 0; i < 11; i++) 
    {
      for (j = 0; j < 11; j++) 
      {
        BOARD[i][j] = ' ';
      }
    }

  while(nEnder != 0) 
  {
  
    // start
    TitleScreen();
    nDecision = StartUpMenu(nDecision);
    while(i < 9)
    {
      ArryIntializer.nLetterScore[i] = 10;

      ArryIntializer.cLetterSymbol[i] = 10; // working pero maganda kung ayusin
      i++;
    }
    if (nDecision == 1)
    {

        printf("\n");
        DisplayHashtag();
        nPlayerCount = ChoosePlayerNumbers();
        printf("\n");
        DisplayHashtag();
          do
          {
              if(nPlayerCount == 2 || nPlayerCount == 3 ||nPlayerCount == 4  )
		          {
                printf("\n\n[Player 1] enter your IGN: ");
                nNameOfPlayer(cNmPss);
                strcpy(playerone.S_player.cName, cNmPss);
                printf("\n[Player 2] enter your IGN: ");
                nNameOfPlayer(cNmPss);
                strcpy(playertwo.S_player.cName, cNmPss);
                
		          }
              
          }while(strcmp(playerone.S_player.cName,playertwo.S_player.cName) == 0 );

          if(nPlayerCount == 3 ||nPlayerCount == 4 )
          {
            do
            {
            
              if(nPlayerCount == 3 ||nPlayerCount == 4 )
              {
                  printf("\n[Player 3] enter your IGN: ");
                  nNameOfPlayer(cNmPss);
                  strcpy(playerthree.S_player.cName, cNmPss);
              }
              if(nPlayerCount == 4)
              {
                  printf("\n[Player 4] enter your IGN: ");
                  nNameOfPlayer(cNmPss);
                  strcpy(playerfour.S_player.cName, cNmPss);
              }
            }while(strcmp(playerone.S_player.cName, playerthree.S_player.cName) == 0 ||
                  strcmp(playerone.S_player.cName,playerfour.S_player.cName) == 0 ||           
                  strcmp(playertwo.S_player.cName, playerthree.S_player.cName) == 0 ||
                  strcmp(playertwo.S_player.cName, playerfour.S_player.cName) == 0 || 
                  strcmp(playerthree.S_player.cName, playerfour.S_player.cName) == 0
                  );
          }
        printf("\n\n");
        DisplayHashtag();

      // FUNCTION WORKING
      playerone.S_player.nStopper = 0;
      playertwo.S_player.nStopper = 0;
      playerthree.S_player.nStopper = 0;
      playerfour.S_player.nStopper = 0; 

      while (gameends != 1) 
      {

        if(nPlayerCount == 2 || nPlayerCount == 3 ||nPlayerCount == 4)
        {
          printf("\n\n\n%s--->%d\n",playerone.S_player.cName,  playerone.S_player.nPoints);
          printf("%s--->%d\n",playertwo.S_player.cName, playertwo.S_player.nPoints);
        }
        if(nPlayerCount == 3 ||nPlayerCount == 4 )
        {
          printf("%s--->%d\n",playerthree.S_player.cName,  playerthree.S_player.nPoints);

        }
        if(nPlayerCount == 4)
        {
          printf("%s--->%d\n",playerfour.S_player.cName, playerfour.S_player.nPoints);
        }
        
        PssngLttersPlayers(&playerone, &playertwo, &playerthree, &playerfour,
                           nAsciiAlphbt, nLttrQntity, nTileAlphabetScore,
                           nPlayerCount, BOARD, roundnumber);

        if (playerone.S_player.nPoints >= 88 ||
            playertwo.S_player.nPoints >= 88 ||
            playerthree.S_player.nPoints >= 88 ||
            playerfour.S_player.nPoints >= 88 || 
            playerone.S_player.TwelveValidWords == 12 || 
            playertwo.S_player.TwelveValidWords == 12 ||
            playerthree.S_player.TwelveValidWords  == 12 
            || playerthree.S_player.TwelveValidWords  == 12) 
          {
            if (roundnumber == 1) 
            {
              WriteData(&playerone, &playertwo, &playerthree, &playerfour,
                        nPlayerCount);
              roundnumber++;
            } 
            else 
            {
              nAverageScore(&playerone, &playertwo, &playerthree, &playerfour, nPlayerCount);
              printf("\nRECORDS\n");
              AppendData(&playerone, &playertwo, &playerthree, &playerfour, nPlayerCount);
            }
          
          printf("playerone.S_player.TwelveValidWords: %d\n",playerone.S_player.TwelveValidWords );
          gameends = 1;
          }

          playerone.S_player.nStopper++;
          playertwo.S_player.nStopper++;
          playerthree.S_player.nStopper++;
          playerfour.S_player.nStopper++;
      }
      playerone.S_player.TwelveValidWords = 0;
      playertwo.S_player.TwelveValidWords = 0;
      playerthree.S_player.TwelveValidWords = 0;
      playerthree.S_player.TwelveValidWords = 0;
      playerone.S_player.nPoints = 0;
      playertwo.S_player.nPoints = 0;
      playerthree.S_player.nPoints = 0;
      playerfour.S_player.nPoints = 0;

      printf("playerone.S_player.TwelveValidWords: %d\n",playerone.S_player.TwelveValidWords );
      printf("\n\n\n<<<<<ROUND ENDS!>>>>: %d\n\n", playerone.S_player.nStopper);

    }
    else if (nDecision == 2) 
    {
      nEnder = 0;
    }
    else if (nDecision == 3)
    {
      int temp = 0;
      temp = temp + nPlayerCount;
      ReadData(temp);
    }
  }
}