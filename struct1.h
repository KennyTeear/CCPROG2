#include <stdio.h>
#include <string.h>
#define MAXLETTERS 7

typedef char StringWord[100];
typedef char String[11];
  
  /*
  for the S_player's name, longest word, highest score , games played and ave score.
  
  */
  typedef struct
  {
    char cName[15]; //need
    StringWord cLongestWord; //need
    StringWord cValidWord;//X
    StringWord cPlayedWord;
    int nHighestScore;//need 
    int nRealTimeScore;//X
    int nGamesPlayed;//need
    float AveScore; //need
    int nPoints;
    int TwelveValidWords;
    int nStopper;
  
   }Player_Data; 

  /*
    this is for the letters/tiles of the players, quantity of the letter/tiles, and scores for the letters/tiles.
  */
  typedef struct 
  {
    char cLetterSymbol[30];
    int nLetterScore [30];

  }Letters_Scrabble;


  typedef struct
  {
    Player_Data S_player;
    Letters_Scrabble S_tileletters;

  }PlayerAndLetters;
  
  typedef struct{
	
    StringWord nWordOne;
    StringWord nWordTwo;
    
  }ScrabbleDictionary;

  
  //player1
  void nStatsPlayerOne(PlayerAndLetters *playerone) 
  {
    //player
    playerone->S_player.cName;
    playerone->S_player.cLongestWord;
    playerone->S_player.cValidWord;//X
    playerone->S_player.cPlayedWord;//X
    playerone->S_player.nHighestScore = 0;
    playerone->S_player.nRealTimeScore = 0;
    playerone->S_player.nGamesPlayed = 0;
    playerone->S_player.AveScore = 0;
    playerone->S_player.nPoints = 0;
    playerone->S_player.TwelveValidWords = 0;
    playerone->S_player.nStopper = 0;
    //tiles
    playerone->S_tileletters.cLetterSymbol;
    playerone->S_tileletters.nLetterScore;
    //conditions
    

  }

  //player2
  void nStatsPlayerTwo(PlayerAndLetters *playertwo)
  {
    //player
    playertwo->S_player.cName;
    playertwo->S_player.cLongestWord;
    playertwo->S_player.cValidWord;
    playertwo->S_player.cPlayedWord;
    playertwo->S_player.nHighestScore = 0;
    playertwo->S_player.nRealTimeScore = 0;
    playertwo->S_player.nGamesPlayed = 0;
    playertwo->S_player.AveScore = 0;
    playertwo->S_player.nStopper = 0;
    //tiles
    playertwo->S_tileletters.cLetterSymbol;
    playertwo->S_tileletters.nLetterScore;
    //conditions
    playertwo->S_player.nPoints = 0;
    playertwo->S_player.TwelveValidWords = 0;
    
  }

  //player3
  void nStatsPlayerThree(PlayerAndLetters *playerthree) 
  {
    //player
    playerthree->S_player.cName;
    playerthree->S_player.cLongestWord;
    playerthree->S_player.cValidWord;
    playerthree->S_player.cPlayedWord;
    playerthree->S_player.nHighestScore = 0;
    playerthree->S_player.nRealTimeScore = 0;
    playerthree->S_player.nGamesPlayed = 0;
    playerthree->S_player.AveScore = 0;
    playerthree->S_player.nStopper = 0;
    //tiles
    playerthree->S_tileletters.cLetterSymbol;
    playerthree->S_tileletters.nLetterScore;
    //conditions
    playerthree->S_player.nPoints = 0;
    playerthree->S_player.TwelveValidWords = 0;
    
  }

  //player4
  void nStatsPlayerFour(PlayerAndLetters *playerfour) // to store S_player 4's info
  {
   //player
    playerfour->S_player.cName;
    playerfour->S_player.cLongestWord;
    playerfour->S_player.cValidWord;
    playerfour->S_player.cPlayedWord;
    playerfour->S_player.nHighestScore = 0;
    playerfour->S_player.nRealTimeScore = 0;
    playerfour->S_player.nGamesPlayed = 0;
    playerfour->S_player.AveScore = 0;
    playerfour->S_player.nStopper = 0;
    //tiles
    playerfour->S_tileletters.cLetterSymbol;
    playerfour->S_tileletters.nLetterScore;
    //conditions
    playerfour->S_player.nPoints = 0;
    playerfour->S_player.TwelveValidWords = 0;
    
  }