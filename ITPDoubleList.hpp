// ITP 365 Fall 2018
// HW6 - Doubly Linked List and Movie Player
// Name: Kirubel Seyoum
// Email: kseyoum@usc.edu
// Platform: Mac
//
// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection
//

#pragma once
#include "error.h"
#include <ostream>
#include <sstream>
#include "leaker.h"

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator()
        {
            // TODO: Implement
            //initializes current iterator
            mCurr=nullptr;
        }
        
        Iterator(Node* inCurr)
        {
            // TODO: Implement
            //sets current iterator to inputted value
            mCurr=inCurr;
        }
        
        Iterator(const Iterator& src)
        {
            // TODO: Implement
            //sets current iterator to current object iterator
            mCurr=src.mCurr;
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
            // TODO: Implement
            //sets current iterator to current object iterator
            mCurr=src.mCurr;
            return *this;
        }
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            // TODO: Implement
            //returns the next node to the current iterator
            mCurr=mCurr->mNext;
            return *this; // FIX RETURN VALUE
        }
        
        // i++
        Iterator operator++(int)
        {
            // TODO: Implement
            //returns the value present in the next node
            Iterator valRet(*this);
            mCurr=mCurr->mNext;
            return valRet; // FIX RETURN VALUE
        }
        
        // --i
        Iterator& operator--()
        {
            // TODO: Implement
            //returns the previous node to the current one
            mCurr=mCurr->mPrev;
            return *this; // FIX RETURN VALUE
        }
        
        // i--
        Iterator operator--(int)
        {
            // TODO: Implement
            //returns the value to the previous node to the current one
            Iterator valRet(*this);
            mCurr=mCurr->mPrev;
            return valRet;
        }
        
        // Dereference
        T& operator*() const
        {
            // TODO: Implement
            //returns the data in the current node
            return mCurr->mData; // FIX RETURN VALUE
        }
        
        Node* operator->() const
        {
            // TODO: Implement
            //returns the current iterator
            return mCurr; // FIX RETURN VALUE
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            // TODO: Implement
            //returns the current iterator to the inputted object
            return mCurr==rhs.mCurr;
           
        }
        
        bool operator!=(const Iterator& rhs) const
        {
            // TODO: Implement
            //returns the current object iterator when not equal
            return mCurr!=rhs.mCurr;
            
        }
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        // Initialize member variables
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
        // TODO: Implement
        // Initialize member variables
        mSize = 0;
        mHead=nullptr;
        mTail=nullptr;
        // Create pointer temp
        Node* temp;
        temp=other.mHead;
        // Loop while temp doesnt equal null
        while (temp!=nullptr)
        {
            //create space for nodes
            push_back(temp->mData);
            temp=temp->mNext;
        };
    }
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        // TODO: Implement
        //clears the list
        clear();
    }
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        // TODO: Implement
        //clears the list through pop back loop
        while (mSize>0)
        {
            pop_back();
        }
    }
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
        // TODO: Implement
        //clear the list
        clear();
        //create node and initialize to head pointer of object
        Node* temp = other.mHead;
        //push back loop
        while (temp!=nullptr)
        {
            push_back(temp->mData);
            temp=temp->mNext;
        };
        
        return *this; // FIX RETURN VALUE
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        //make return value the vector size
        return mSize; // FIX RETURN VALUE
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        // TODO: Implement
        //create a newnode
        //dynamically allocate it
        Node* newNode = new Node;
        //set member variable data for new node
        newNode->mData=value;
        newNode->mPrev=nullptr;
        newNode->mNext=mHead;
        //conditial situations for the new node
        if(mSize==0)
        {
            mTail=newNode;
        }
        else
        {
            mHead->mPrev=newNode;
        }
        mHead=newNode;
        //increase the size
         mSize++;
        
    }
    
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        // TODO: Implement
        //return the value in the head node
        return mHead->mData;
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        // TODO: Implement
        //situation for nothing in the list
        if (mSize==0)
        {
            error("There are no values.");
        }
        //situation for only one node in the list
        else if (mSize==1)
        {
            
            delete mHead;
            //set member variables to inital state
            mHead=nullptr;
            mTail=nullptr;
            mSize=0;
        }
        else
        {
            //pointer node named temp
            Node* temp;
            temp= mHead->mNext;
            delete mHead;
            //set the head to temp
            mHead=temp;
            //set the previous to the head to null
            mHead->mPrev=nullptr;
            //decrement the size
            mSize--;
        }
        
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        // TODO: Implement
        //dynamically allocate a new node
        Node* newNode= new Node;
        newNode->mData=value;
        newNode->mNext=nullptr;
        newNode->mPrev=mTail;
        // Conditional situation for 0 size list
        if (mSize==0)
        {
            mHead=newNode;
        }
        // Set new Node equal to next Node of tail
        else
        {
            mTail->mNext=newNode;
        }
        mTail=newNode;
        // Increase list size
        mSize++;
        
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& back()
    {
        // TODO: Implement
        // Return data within tail node
        return mTail->mData;
        //return *(new T()); // FIX RETURN VALUE
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        // TODO: Implement
        //check if size = 0
        if (mSize==0)
        {
            //display error
            error("There are no values.");
        }
        // Check if size equals 1
        else if (mSize==1)
        {
            // Set appropriate values
            delete mTail;
            mHead=nullptr;
            mTail=nullptr;
            mSize=0;
        }
        else
        {
            // Initialize node temp
            Node* temp = mTail->mPrev;
            delete mTail;
            mTail=temp;
            mTail->mNext=nullptr;
            // Decrease size
            mSize--;
        }
        
    }
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
        // TODO: Implement
        // Return the iterator at head node
        return Iterator(mHead);
        
        //return *(new Iterator); // FIX RETURN VALUE
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        // TODO: Implement
        // Return iterator at the next node of tail
        return Iterator(mTail->mNext);
        
        //return *(new Iterator); // FIX RETURN VALUE
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
        // TODO: Implement
        // If iterator is invalid
        if (!i.mCurr)
        {
            error("iterator is invalid");
        }
        // If iterator is at the beginning
        else if (i == begin())
                 
        {
            pop_front();
            // Return beginning iterator
            return begin();
        }
        else if (i.mCurr==mTail)
        {
            pop_back();
            // Return end iterator
            return end();
        }
      
            // Establishes new node positions
            Node* before=i->mPrev;
            Node* after=i->mNext;
            Node* toDel=i.mCurr;
        // Delete node
            delete toDel;
            before->mNext=after;
            after->mPrev=before;
        // Decrement size
            mSize--;
        // Return the iterator for after node
            return Iterator(after);
        

    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        // TODO: Implement
        // If iterator is invalid
        if (!i.mCurr)
        {
            error("iterator is invalid");
        }
        // If iterator is at beginning
        else if (i == begin())
        {
            push_front(val);
            // Return iterator at mHead
            return Iterator(mHead);
        }
        // If iterator is at end
        else if (i == end())
        {
            
            push_back(val);
            // Return iterator at tail
            return Iterator(mTail);
        }
     
            // Establish node positions
            Node* before=i->mPrev;
            Node* after=i.mCurr;
            Node* newNode=new Node();
        // Insert val into new node data
            newNode->mData=val;
        // Establish before and after positions
            newNode->mPrev=before;
            newNode->mNext=after;
            before->mNext=newNode;
            after->mPrev=newNode;
        // Increment the size
            mSize++;
        // Return iterator at new node
            return Iterator(newNode);
        
    }
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!! DO NOT EDIT BELOW THIS LINE !!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        os << "{";
        
        Node* temp = list.mHead;
        while (temp != nullptr)
        {
            os << temp->mData;
            if (temp != list.mTail)
            {
                os << ",";
            }
            
            temp = temp->mNext;
        }
        
        os << "}";
        return os;
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::stringstream str;
        str << *this;
        return str.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::stringstream str;
        
        str << "{";
        
        Node* temp = mTail;
        while (temp != nullptr)
        {
            str << temp->mData;
            if (temp != mHead)
            {
                str << ",";
            }
            
            temp = temp->mPrev;
        }
        
        str << "}";
        
        return str.str();
    }
};
