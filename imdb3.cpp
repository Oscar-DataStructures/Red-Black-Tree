/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/


using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "dict.h"

// ================================= Load File ================================
Dictionary<string, string> loadDataFile()
// PreConditions:   data.tsv is downloaded into current directory
// PostConditions:  Return a dict with the movie titles keyed to genres
{
  Dictionary<string, string> movieData;

  ifstream movieFile;
  movieFile.open("data.tsv");
  if (movieFile.is_open())
	{
    string input;
    while ( getline(movieFile, input) )	//gets lines
		{
      istringstream ss(input);
      string junk;
      string movieTitle;
      string movieGenres;

      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, movieTitle, '\t');	//movie title line
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, movieGenres, '\t');	//genre line

      Pair moviePair;
      moviePair.key = movieTitle;
      moviePair.value = movieGenres;
      try
			{
        movieData.insert(movieTitle, movieGenres);
      }
			catch (InsertError e)
			{
				cout << "here" << endl;
        // If a KeyError has occurred, the data is already in the Dictionary.
        // We won't do anything here.
        // The first occurence of a key that is added will always prevail.
      }
    }

    movieFile.close();
  }

	else
	{
    cout << "ERROR Reading file " << "data.tsv" << endl;
    exit(1);
  }

  return movieData;
}


// ============================= findGenre Method ==============================
void findGenre(Dictionary<string, string> *movieData, string searchTerm)
// PreConditions:   movieData cannot be null
// PostConditions:  Prints genres to terminal or not found message
{
  Pair testPair;
	testPair.key = searchTerm;
  Pair *foundPair = movieData->get(searchTerm);
	if (foundPair != NULL)		//found genres
	{
  	string genre = foundPair->value;
  	cout << "Genres: " << genre << endl << endl;
	}

	else											//couldnt find movie
	 {
  	cout << "Title not found." << endl << endl;
	}
}


// ==================================== Main ===================================
// =============================================================================
int main()
// PreConditions:   N/A
// PostConditions:  N/A
{
  Dictionary<string, string> movieData = loadDataFile();
  while (true)	//Allow for searching without needing to rerun program
	{
    string searchName;
    cout << "Enter a movie/show title to search for: ";
    getline(cin, searchName, '\n');
    findGenre(&movieData, searchName);
  }

  return 0;
}
