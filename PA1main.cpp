/*
 Name: Harrison  McLain
  Class: CptS 122, Spring 2023
 Date: Feb 1, 2023
 Programming Assignment: PA1                                                                      
 Description: This program converts either english to morse or vis versa
 Notes: I utilized this source url: Tutoring
 hello
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

void openFile(ifstream&, string);
void storeVals(ifstream&, vector<char>&);
void englishToMorse(vector<char>&);
void morseToEnglish(vector<char>&);
string charToMorse(char);



int main()
{

    vector<char> vals;
	char mode;


	cout << "please choose a mode: t means english to morse or m for morse to english" << endl;
	
	cin >> mode;
	
	if (mode == 't')
	{
		ifstream inFile;
		openFile(inFile, "morse.txt");
		storeVals(inFile, vals);
		englishToMorse(vals);
		inFile.close();
	
	}
	
	else if (mode == 'm')
	{
	
		ifstream inFileMorse;
		openFile(inFileMorse, "english.txt");
		storeVals(inFileMorse, vals);
		morseToEnglish(vals);
		inFileMorse.close();
		
	
	}
	

	return 0;
	
}


/*************************************************************
 * Function: storeVals ()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function stores values from the inFile	
 *              into a vector                      	
 * Input parameters: a file to read from, a vector    	
 * Returns: void           	     	
 * Post: the vector is modified and now has values by char      
 *************************************************************/

void storeVals(ifstream& inFile, vector<char> &vec)
{
	string line, word;
	char c;
	
	
	while(!inFile.eof())
	{
	// read line by line from file
		getline(inFile, line);
		if(!inFile.bad())
		{
			//cout << line << endl;
			
			for(int o = 0; o < line.size(); o++)
			{
				c = line.at(o);
				vec.push_back(c);		
			}
				
			//print vec items
			for(int k = 0; k < vec.size(); k++)
			{
				//cout << vec.at(k) << endl;
				
			}
				

			}
			
		}
		
	}



/*************************************************************
 * Function: openFile ()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function opens a file                     	
 * Input parameters: file to open and its name   	
 * Returns: void           	     	
 * Post: file is opened or not    
 *************************************************************/


void openFile(ifstream& inFile, string fname)
{
	inFile.open(fname);
	if(inFile.is_open())
	{
		cout << "Success: File opened" << endl;
	} 
	else 
	{
		cout << "Failed: could not open file" << endl;
		exit(-1);
	}
}


/*************************************************************
 * Function: englishToMorse()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function keeps track of number of char	
 *              converted and calls charToMorse to convert                    	
 * Input parameters: vector o chars   	
 * Returns: void           	     	
 * Post: characters are converted and put in string 
 *               and each conversion counted    
 *************************************************************/

void englishToMorse(vector<char> &newVec)
{
	
	string morse = "";
	int cnt = 0;
	
	ofstream outFile;
	outFile.open("morseOut.txt");
	
	
	for(int i = 0; i < newVec.size(); i++)
	{
		morse += charToMorse (newVec[i]) ;
		cnt++;
		
	}
	
		
			outFile << morse << endl;
			cout << morse << endl;
		
	
	cout << cnt << " characters were successfully converted" << endl;

outFile.close();

}

/*************************************************************
 * Function: charToMorse()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function converts each char to morse	
 *              equivalent                  	
 * Input parameters: characters read in one by ones   	
 * Returns: morse string           	     	  
 *************************************************************/

string charToMorse(char c)
{

		if (c == 'a' || c == 'A')
		{
			return ".- ";
		
		} 
		else if (c == 'b' || c == 'B')
		{
			return "-... ";

		} 
		else if (c == 'c' || c == 'C')
		{
			return "-.-. ";

		} 
		 else if (c == 'd' || c == 'D')
		{
			return "-.. ";

		}
		 else if (c == 'e' || c == 'E')
		{
			return ". ";
			
		}
		 else if (c == 'f' || c == 'F')
		{
			return "..-. ";
			
		}
		 else if (c == 'g' || c == 'G')
		{
			return "--. ";
		
		}
		 else if (c == 'h' || c == 'H')
		{
			return ".... ";
			
		}
		 else if (c == 'i' || c == 'I')
		{
			return ".. ";
			
		}
		 else if (c == 'j' || c == 'J')
		{
			return ".--- ";
			
		}
		 else if (c == 'k' || c == 'K')
		{
			return "-.- ";
			
		}
		 else if (c == 'l' || c == 'L')
		{
			return ".-.. ";
			
		}
		 else if (c == 'm' || c == 'M')
		{
			return "-- ";
			
		}
		 else if (c == 'n' || c == 'N')
		{
			return "-. ";
			
		}
		 else if (c == 'o' || c == 'O')
		{
			return "--- ";
			
		}
		 else if (c == 'p' || c == 'P')
		{
			return ".--. ";
			
		}
		 else if (c == 'q' || c == 'Q')
		{
			return "--.- ";
			
		}
		 else if (c == 'r' || c == 'R')
		{
			return ".-. ";
			
		}
		 else if (c == 's' || c == 'S')
		{
			return "... ";
			
		}
		 else if (c == 't' || c == 'T')
		{
			return "- ";
			
		}
		 else if (c == 'u' || c == 'U')
		{
			return "..- ";
			
		}
		 else if (c == 'v' || c == 'V')
		{
			return "...- ";
			
		}
		else if (c == 'w' || c== 'W')
		{
			return ".-- ";
			
		}
		else if (c == 'x' || c== 'X')
		{
			return "-..- ";
			
		}
		else if (c == 'y' || c== 'Y')
		{
			return"-.-- ";
			
		}
		else if (c == 'z' || c== 'Z')
		{
			return "--.. ";
			
		}
		else if (c == '1')
		{
			return ".---- ";
			
		}
		else if (c == '2')
		{
			return "..--- ";
			
		}
		else if (c == '3')
		{
			return "...-- ";
			
		}
		else if (c == '4')
		{
			return "....- ";
			
		}
		else if (c == '5')
		{
			return "..... ";
			
		}
		else if (c == '6')
		{
			return "-.... ";
			
		}
		else if (c == '7')
		{
			return "--... ";
			
		}
		else if (c == '8')
		{
			return "---.. ";
			
		}
		else if (c == '9')
		{
			return "----. ";
			
		}
		else if (c == '0')
		{
			return "----- ";
			
		}
		else if (c == ' ')
		{
			return "  ";
		
		}
		
		exit(-1);

}

/*************************************************************
 * Function: morseToChar()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function converts each morse string to its	
 *              char equivalent                  	
 * Input parameters: a morse string   	
 * Returns: a char           	     	  
 *************************************************************/

char morseToChar(string s)
{
		if(s == ".- "){
		
			return 'A';
			
		
		} 
		else if (s == "-... ")
		{
			return 'B';
			
		} 
		else if (s == "-.-. ")
		{
			return 'C';
			
		} 
		 else if (s == "-.. ")
		{
			return 'D';
			
		}
		 else if (s == ". ")
		{
			return 'E';
			
		}
		 else if (s == "..-. ")
		{
			return 'F';
			
		}
		 else if (s == "--. ")
		{
			return 'G';
			
		}
		 else if (s == ".... ")
		{
			return 'H';
			
		}
		 else if (s == ".. ")
		{
			return 'I';
			
		}
		 else if (s == ".--- ")
		{
			return 'J';
			
		}
		 else if (s == "-.- ")
		{
			return 'K';
			
		}
		 else if (s == ".-.. ")
		{
			return 'L';
			
		}
		 else if (s == "-- ")
		{
			return 'M';
			
		}
		 else if (s == "-. ")
		{
			return 'N';
			
		}
		 else if (s == "--- ")
		{
			return 'O';
			
		}
		 else if (s == ".--. ")
		{
			return 'P';
			
		}
		 else if (s == "--.- ")
		{
			return 'Q';
			
		}
		 else if (s == ".-. ")
		{
			return 'R';
			
		}
		 else if (s == "... ")
		{
			return 'S';
			
		}
		 else if (s == "- ")
		{
			return 'T';
			
		}
		 else if (s == "..- ")
		{
			return 'U';
			
		}
		 else if (s == "...- ")
		{
			return 'V';
			
		}
		else if (s == ".-- ")
		{
			return 'W';
			
		}
		else if (s ==  "-..- ")
		{
			return 'X';
			
		}
		else if (s == "-.-- ")
		{
			return 'Y';
			
		}
		else if (s == "--.. ")
		{
			return 'Z';
			
		}
		else if (s == ".---- ")
		{
			return '1';
			
		}
		else if (s == "..--- ")
		{
			return '2';
			
		}
		else if (s == "...-- ")
		{
			return '3';
			
		}
		else if (s == "....- ")
		{
			return '4';
			
		}
		else if (s == "..... ")
		{
			return '5';
			
		}
		else if (s== "-.... ")
		{
			return '6';
			
		}
		else if (s == "--... ")
		{
			return '7';
			
		}
		else if (s == "---.. ")
		{
			return '8';
			
		}
		else if (s == "----. ")
		{
			return '9';
			
		}
		else if (s == "----- ")
		{
			return '0';
			
		}
		else if (s ==  "  ")
		{
			return ' ';
		}
		
		exit(-1);
		
}

/*************************************************************
 * Function: popMorse()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function solves the solution of double
 *              spaces when reading through the file                 	
 * Input parameters: encoded str 	
 * Returns: decoded str           	     	  
 *************************************************************/

string popMorse (istringstream& sourceStr) {
    //get the next morse code in the stream
    string returnStr;
    getline (sourceStr,returnStr,' ') ;
    
    if (!sourceStr.eof()) {
   	
   	 if (returnStr == "") 
         returnStr = "  ";
    else returnStr = returnStr + ' ';
}
    return returnStr ; //"" means we got to the end
}

/*************************************************************
 * Function: morseToEnglish()                  	
 * Date Created: 1/28/23                 	        
 * Date Last Modified: 1/31/18                        
 * Description: This function appends the sentence 
 *              and keeps count of morse characters converted             	
 * Input parameters: vector of morse code   	
 * Returns: void           	     	  
 *************************************************************/

void morseToEnglish(vector<char> &newVec) {
	string english = "";
	string code,decoded, encodedS ;
	istringstream encoded;
	int cnt = 0;
	
	ofstream outFile;
	outFile.open("englishOut.txt");
    
    encodedS.append (newVec.data (),newVec.size ());
    encoded = istringstream (encodedS);
    
    while (true) {
       code = popMorse (encoded);
       
        if (code == "") break;
        decoded = morseToChar (code);
        english = english + decoded;
        cnt ++;
    }
    
    
    outFile << english << endl;
	cout << english << endl;
	

	
	cout << cnt << " characters were successfully converted" << endl;

    outFile.close();

}
