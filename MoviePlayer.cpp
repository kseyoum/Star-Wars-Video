#include "MoviePlayer.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // TODO: Implement
    mFilmName=filmName;
    mFilm.clear();
    loadTape();
    pos=mFilm.begin();
    
    
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    // TODO: Implement
    mFilm.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    // TODO: Implement
    if(currFrameNum<mFilm.size())
    {
        pos++;
        currFrameNum++;
    }
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    // TODO: Implement
    if(pos!=mFilm.begin())
    {
        pos--;
        currFrameNum--;
        
    }
    
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    // TODO: Implement
    pos=mFilm.begin();
    currFrameNum=1;
    
    
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    // TODO: Implement
    //dereference the position
    return *pos;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    // TODO: Implement
    // Delete current frame
    pos=mFilm.erase(pos);
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
    // TODO: Implement
    // Copy current frame
    // Establish copy variable
    std::string copy = *pos;
    // Set new pos position
    pos=pos--;
    mFilm.insert(pos, copy);
    // Increase current frame number
    currFrameNum++;
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // TODO: Implement
    // Return current frame num
    
    return currFrameNum;
    
    //return INT_MAX; // FIX RETURN VALUE
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    // TODO: Implement
    // Return list size
    
    return mFilm.size();
    //return INT_MAX; // FIX RETURN VALUE
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    // TODO: Implement
    // Return size of frame
    return FRAMESIZE;
    //return INT_MAX; // FIX RETURN VALUE
}

// Function: getCurrFrame
// Purpose: Retrieves the current "frame" from the film list
// Modifies the inputted vector of GLabels to contain the current frame
// Input: A vector of "GLabels" that are the "screen" -- passed by reference
// Returns: Nothing
void MoviePlayer::getCurrFrame(Vector<GLabel*>& screen)
{
    // TODO: Implement
    // Establish current frame variable
    std::string currFrame= getCurrFrame();
    // Establish string stream to load current frame into
    std::stringstream ss;
    ss<<currFrame;
    
    for (int i=0; i<screen.size(); i++)
    {
        // Create a line variable
        // Use get line to set label from string stream at each position
        std::string line;
        std::getline(ss,line);
        screen[i]->setLabel(line);
        
    }
    
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    // TODO: Implement
    // Establish input file stream
    std::ifstream file(mFilmName);
    // If line file is open
    if (file.is_open())
    {
        //loop until the file is over
        while (!file.eof())
        {
            //create string to store the line into
            std::string line;
            // Establish total frame variable
            std::string totalFrame;
            // Use get line to load file into line variable
            std::getline(file,line);
            // Create string stream to differentiate separator from lines
            std::stringstream ss(line);
            int seperator;
            ss>>seperator;
            // Loop through frame lines to create frames
            for (int i=0; i<FRAMESIZE; i++)
            {
                std::string frameLine;
                // Use get line to load file into frame line
                std::getline(file,frameLine);
                // Input frame line into total frame with separations
                totalFrame+=(frameLine+"\n");
            }
            // For loop allows total frame to be a max of 13 lines
            for (int i=0; i<seperator; i++)
            {
                // Push back function loads total frames into list
                mFilm.push_back(totalFrame);
            }
        }
    }
    else
    {
        // Condition if file doesn't load
        std::cout<< "Failed to load file.";
    }
    

}
