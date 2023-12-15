/*
MENU
    - create, play, quit, help

    - create
        - create room
            - name, description
        - create item
            - name, description, weight
        - create creature
            - name, description, weight, health, strength
        - create exit
            - name, description, weight, direction
        - visualize room
            - room dimentions
            - item
            - creature
            - exit
        - save
*/
/*
    - play
        - load
            - load room
            - load item
            - load creature
            - load exit
        - save
            - save room
            - save item
            - save creature
            - save exit
        - visualize room
            - room dimentions
            - item
            - creature
            - exit
        - move
            - direction
            - room
            - item
            - creature
            - exit
        - attack
            - creature
            - item
            - room
            - exit
        - quit to main menu
            - save game
    - quit game

    - help
        - create
            - create room
            - create item
            - create creature
            - create exit
            - visualize room
            - save
        - play
            - load
            - save
            - visualize room
            - move
            - attack
            - quit to main menu
        - quit game
        - help
*/
class Menu
{
private:

    void printMainM();

    void CreateMenuMain(); // main create menu 
    void printCreateMenuMain(); // Print the create menu
    
    void CreateMenu(bool newGame); // create menu for if you alrady have a map takes in if new game or not
    void printCreateM(); // print create menu for if you alrady have a map

    void CreateHelp(); // create help menu
    void printCreateHelpM(); // print create help menu
    
public:
    Menu(/* args */);
    ~Menu();

    void load();
    

};
