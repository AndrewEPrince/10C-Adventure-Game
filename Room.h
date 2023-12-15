// Room.h: interface for the Room class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ROOM_H
#define ROOM_H

#include<string>
//    removed - not needed   #include<ciso646>
#include<vector>
#include<iostream>
using namespace std;

enum Direction {NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3};

class Room  
{
public:
	
	// constructors
	/**
		@brief Represents a room in the adventure game.

		This class provides the necessary functionality to create and manage a room in the game.
		Each room has a name and a description.

		@param name The name of the room.
		@param desc The description of the room.
	 */
	Room(string name, string desc);
	
	/**
		@brief Represents a room in the adventure game.
		
		This class provides the functionality to create and manage a room in the game.
		Each room can have a unique set of attributes and can be connected to other rooms.

		@param name The name of the room. (Optional)
		@param desc The description of the room. (Optional)
	 */
	Room();

	// exit pointers
	/**
		@brief Get the room to the west of this room.
		@return A pointer to the west room.
	 */
	Room * west() const; 
	
	/**
		@brief Get the room to the east of this room.
		@return A pointer to the east room.
	 */
	Room * east() const;
	
	/**
		@brief Get the room to the south of this room.
		@return A pointer to the south room.
	 */
	Room * south() const;
	
	/**
		@brief Get the room to the north of this room.
		@return A pointer to the north room.
	 */
	Room * north() const;

	// inspectors for other attributes
	/**
		@brief Returns the description of the room.

		@return std::string The description of the room.
	 */
	string description() const;

	/**
		@brief Gets the name of the room.

		@return The name of the room as a string.
	 */
	string name() const;

    // mutators
	/**
		@brief Sets the description of the room.

		@param d The description of the room.
	 */
	void set_description(string d);
	
	/**
		@brief Sets the name of the room.

		@param n The name of the room.
	 */
	void set_name(string n);

	// connect this room to room r
	// exit is the direction you exit this 
	// room from. to is the direction you enter
	// the other room from.
	// Theres no law that says the exits have to make sense
	// The method returns true if the connection is successful
	// To prevent memory leaks, you cannot disconnect an exiting
	// attached exit.
	// Examples:
	//    r1.connect(NORTH, &r2, SOUTH);
	//       -- exiting r1 to the north takes you to r2
	//       -- exiting r2 to the south takes you to r1
	//       -- returns true
	//    r1.connect(WEST, &r3, WEST); (extra credit only)
	//       -- exiting r1 to the west takes you to r2
	//       -- exiting r3 to the west takes you to r1
	//       -- odd but permissible
	//       -- returns true
	//    r1.connect(WEST, &r4, EAST);
	//       -- returns false
	//       -- no connections are made because there is 
	//       -- already an exit WEST
	//    r1.connect(EAST, &r2, SOUTH);
	//       -- returns false
	//       -- no connections are made because there is 
	//       -- already an exit SOUTH from r2.
	
	/**
		Connects the current room to another room in the specified direction.
		
		@param exit The direction of the exit in the current room.
		@param r The pointer to the room to be connected.
		@param otherExit The direction in which the other room is connected.
		@return True if the connection is successful, false otherwise.
	 */
	bool connect(Direction exit, Room * r, Direction otherExit);

	// destructor
	// the destructor disconnects itself from
	// other rooms before the room itself is 
	// destroyed.  This prevents dangling pointer
	// in other rooms
	/**
		@brief Destructor for the Room class.
	 */
	virtual ~Room();

private:
	// helper method for destructor
	// CAUTION: dangerous
	//   --- may cause memroy errors!
	
	/**
		@brief Disconnects the room in the specified direction.

		@param d The direction to disconnect.
	 */
	void disconnect(Direction d);

	//  attributes
	/**
		@brief The description of the room.
	 */
	
	string description_;
	/**
		@brief The name of the room.
	 */
	string name_;
	
	/**
		@brief A vector of pointers to Room objects representing the exits from the current room.
	 */
	vector<Room *> exits_;
};

ostream & operator<<(ostream & out, const Room & r);

#endif // !defined(AFX_ROOM_H__7C105847_EA72_4F3E_8758_2D94DD05D583__INCLUDED_)


