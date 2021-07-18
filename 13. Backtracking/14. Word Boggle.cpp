/*Given a dictionary of distinct words and an M x N board where every cell has one character. 
Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board.
We can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.

Input:  N = 4   dictionary = {"GEEKS","FOR","QUIZ","GO"}
	R = 3, C = 3 board = { {G,I,Z},
						   {U,E,K},
						   {Q,S,E} }
Output:
{"GEEKS" , "QUIZ"} */

class Solution {
public:
    void wordSearching( int row, int col, int &rowSize, int &colSize,
                        string &wordSearch, int wordIdx, 
                        vector<vector<char>> &board, vector<vector<bool>> &visited,
                        bool &wordFound )
    {
        if(wordIdx == wordSearch.size())
        {
            wordFound = true;
            return;
        }
        if(row<0 || row>=rowSize ||
            col<0 || col>=colSize ||
            board[row][col] != wordSearch[wordIdx] ||
            visited[row][col] == true)
        {
            return;
        }
        
        visited[row][col] = true;
        wordSearching(row-1, col-1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row-1, col, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row-1, col+1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row, col-1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row, col+1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row+1, col-1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row+1, col, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        wordSearching(row+1, col+1, rowSize, colSize, wordSearch, wordIdx+1, board, visited, wordFound);
        visited[row][col] = false;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
	{
	    int M = board.size();
	    int N = board[0].size();
        
	    vector<vector<bool>> isVisited(M+1 , vector<bool>(N+1, false));
	    vector<string> wordsFormed;
	    
	    for(string currWord: dictionary)
	    {
	        bool wordFound = false;
	        for(int i=0; i<M; i++)
	        {
	            if(wordFound == true)
	               break; //go to next Word in the dictionary loop
	            for(int j=0; j<N; j++)
	            {
	                if(wordFound == true)
	                    break;
	                    
	                if(board[i][j] == currWord[0])//got the first char of currWord in board[i][j]
	                { //continue searching for the next characters of the word in adjacent to board[i][j]
	                    wordSearching(i, j, M, N, currWord, 0, board, isVisited, wordFound);

	                    if(wordFound == true)
	                        wordsFormed.push_back(currWord);
	                }
	            }

	        }
	    }
	    return wordsFormed;
	}
};



//gfg solution 

//Back-end complete function Template for C++
class Solution {
  public:
    bool search(vector<vector<char> >& board, const string& word, int index, int x,int y) 
    {

    // If position of the cell is out of boundary of board or
    // letter in current cell does not match letter of word
    if (x < 0 || x == board[0].size() || y < 0 || y == board.size() || word[index] != board[y][x])
        return false;

    // Base case : each character of the word has been matched
    if (index == word.length() - 1) 
    	return true;

    // mark the current cell as visited
    char cur = board[y][x];
    board[y][x] = '#';
    bool found = search(board, word, index + 1, x + 1, y)        // bottom
                 || search(board, word, index + 1, x - 1, y)     // top
                 || search(board, word, index + 1, x, y + 1)     // right
                 || search(board, word, index + 1, x, y - 1)     // left
                 || search(board, word, index + 1, x + 1, y + 1) // bottom right
                 || search(board, word, index + 1, x - 1, y + 1) // top right
                 || search(board, word, index + 1, x + 1, y - 1) // bottom left
                 || search(board, word, index + 1, x - 1, y - 1); // top left

    // revert the current cell back to its original state
    board[y][x] = cur;
    return found;
	}

	bool exist(vector<vector<char> >& board, string word) 
	{
	    if (board.size() == 0) return false;

	    // Consider every character cell and look for all words
	    // starting with this character
	    for (int i = 0; i < board[0].size(); i++)
	        for (int j = 0; j < board.size(); j++)
	            if (search(board, word, 0, i, j)) 
	            	return true;

	    return false;
	}

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
	{
	    vector<string> result;

	    // Iterate through every word in the dictionary
	    for (int i = 0; i < dictionary.size(); ++i) 
	    {
	        string word = dictionary[i];

	        if (exist(board, word)) 
	        	result.push_back(word);
	    }
	    return result;
	}
};