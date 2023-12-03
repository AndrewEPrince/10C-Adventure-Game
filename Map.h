//TODO: Needs to Hold the rooms starting with the starting room
//TODO: Need to create a map object(dictionary) that holds all the rooms with the key being the name of the room
    // This will be how we will link the room doorways together
    // Will be something like Room: west(name of room) eask(name of room) north(name of room) south(name of room)
    // This will be how we will link the room doorways together from the text save file for the map.

//TODO: could also use JSON Database to store map data.

#include "Room.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Map
{
private:
    map <string, Room *> rooms;
    string description;
    string start_room;

public:
    // leads the rooms to the map
    Map(string name);
    Map();
    ~Map();

    Room* curr_room = rooms[start_room];
    void set_description(string desc);
    string get_description();
    void add_room(string name, string desc);
    void add_exit(string room1, string room2, string direction);
    void print_room(string name);
    void print_map();
    void print_exits(string name);
 


};

Map::Map(string name)
{
}

Map::~Map()
{
}
