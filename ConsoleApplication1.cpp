#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
// the above are necessary for reading and writing to a file

int main()
{
    //declaring variables
    double ecount = 0;
    double charsInLongestWordWithE = {};
    std::cout << "Hello World!\n";
    std::string nameOfFile ; //name of the file
    //char text[2000];
    std::string wordWithE;
    std::string wordWithMostE;
    std::string word;
    

    std::cout << "Enter the name of the file you would like to use: "; // we are going to assume that it is in the same location as the location of this program
    std::cin >> nameOfFile; //put string input into the file
    // here we will create the fstream object; the name is already stored in nameOfFile variable
    std::fstream dataFile(nameOfFile, std::ios::in);
    //if loop from class to make sure the file was opened successfully
    if (!dataFile)
    {
        std::cout << "Unable to open file, bye!" << std::endl;
        exit(1);
    }
   
    /* while we are in the dataFile
    for each word  in the file
              check for the char e and add it to a running total
              if the char e is in a word, add it to a running total total Words
      count the number of char e in each word, if it has more es than the previous word,
      make it to variable mostEs. display the highest one's number of characters.
    */

    //the for and if loops below are very similar to our class example
    //on finding the longest word in a user inputted sentence
    while(!dataFile.eof())//while we are not at the end of the file, we can check for each stat all in one while loop
 {      
      getline(dataFile, word); //get the current line of the file
        while (dataFile >> word)//read one word at a time in the file
        {
            for (int i = 0;i < word.length();i++) //for loop that goes through each word in the file
                //then goes through each character in the current word
            {
                if (word[i] == 'e') // if location i of a string is equal to e, add it to a running total ecount
                {
                    ecount++; //running total of words with es
                    wordWithE = word;//assign this word to wordWithE, so that we can compare it in the
                    //next if loop

                    if (wordWithE.length() > wordWithMostE.length())
                    //if loop that compares the length of a word containing e and
                        //the longest word with e in it
                    {
                        wordWithMostE = word;//if it is greater, assign it to wordWithMostE
                    }
                    charsInLongestWordWithE = 0;// initialize to zero (it is not a string like the rest)
                    //this for loop checks the word with the most es (from the above if loop)
                    //and then goes through the whole word, counting each character
                    for (int i = 0;i < wordWithMostE.length();i++)
                    {
                        charsInLongestWordWithE++;
                    }
                }
            }
        }
    }

    dataFile.close(); //close the file we read from

    //here i initialized this variable separately so that I did not get confused 
    //it is an ofstream object to represent the output filestats.txt file
    std::ofstream outputFile;
    outputFile.open("filestats.txt", std::ios::out); //now we open it and list std::ios::out as a parameter since we are outputting to this file

    //add all of these statements to the file
    outputFile << "Number of words where e appears:" << ecount << std::endl;
    outputFile << "Longest word with e: " << wordWithMostE << std::endl;
    outputFile << "Number of letters in longest word with e: " << charsInLongestWordWithE << std::endl;
    outputFile.close(); //close the file after we are done outputting to it
    return 0;

/*
I tried getting each character seperately using the .get method, but it did not work
how i wanted it to. I left the loop here in comments

   dataFile.open(nameOfFile, std::ios::in);
   dataFile.get(text);
   while (dataFile)
   {
      
       if (text == 'e' || 'E')
       {
           ecount++;
       }
   }
   std::cout << "Number of e in the file : " << ecount << std::endl;
   dataFile.close();

   */
}

