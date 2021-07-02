#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Program a linked list and then sort that linked list
    //APPLICATION: Multiplayer Games use a circular linked list to swap between players in a loopp

//const int MAX_NAME_LENGTH = 25;

typedef struct Node
{
    char playerName[25];        //Looks like you cannot use a const int to define string size in this case
    int scoreVal;                //Data value
    int userPing;
    struct Node* nextNodePtr;      //Pointer to next node location
}Node;

void CreateNode(Node* myNode, int initValue, char* namePlayer, int pingGet)
{
    myNode->scoreVal = initValue;
    myNode->userPing = pingGet;
    myNode->nextNodePtr = NULL;
    strcpy(myNode->playerName, namePlayer);
}


void PlaceNode(Node* firstNode, Node* secondNode)
{
    Node* temp = NULL;
        temp = firstNode->nextNodePtr;              //Get nextNode of firstNode so we can can assign it to the second node's next node ptr

    firstNode->nextNodePtr = secondNode;            //Assign the firstnode's next node to the second Node
    secondNode->nextNodePtr = temp;                 //Assign secondNode's nextnode to be the original nextNode of the firstNode
}

// void CreateNodeTest(Node* myNode, int initValue)
// {

// }

void PrintNode(Node* myNode)
{
    fprintf(stdout, "Player:\t%s\nScore:\t%d\nPing\t%d\n\n", myNode->playerName, myNode->scoreVal, myNode->userPing);
}

int main (void)
{
    srand(time(NULL));

    Node* playerOne;
        playerOne = (Node*)malloc(sizeof(Node));           //Its best to allocate memory for node in main, maybe try a pass by pointer reference? Nvm not possible in C, but possible in C++
        CreateNode(playerOne, 25, "armyman123", rand() % 101);
        PrintNode(playerOne);

    Node* playerTwo;
        playerTwo = (Node*)malloc(sizeof(Node));
        CreateNode(playerTwo, rand() % 101, "catgaming123", rand() % 101);
        PrintNode(playerTwo);
        PlaceNode(playerOne, playerTwo);                //playerOne -> playerTwo

    Node* currObj = playerOne;          //Creates a counterObj and assigns it to the pointer of player one so we can search thru and print all of the node's info
        Node* MVP;
            MVP = (Node*)malloc(sizeof(Node));
            CreateNode(MVP, 0, "NULL", 0);

        Node* Lowest = NULL;
            Lowest = (Node*)malloc(sizeof(Node));
            CreateNode(Lowest, 0, "NULL", 0);

        int min = 101, max = 0;

        while (currObj != NULL)
        {
            if (currObj->scoreVal > max)
            {
                max = currObj->scoreVal;
                CreateNode(MVP, currObj->scoreVal, currObj->playerName, currObj->userPing);
                    //currObj = currObj->nextNodePtr;
                    
            }
            if (currObj->scoreVal < min)
            {
                min = currObj->scoreVal;
                CreateNode(Lowest, currObj->scoreVal, currObj->playerName, currObj->userPing);
                    //currObj = currObj->nextNodePtr;         
            }
            currObj = currObj->nextNodePtr;
        }
    fprintf(stdout, "The player with the highest score was...\n"); 
        PrintNode(MVP);

    fprintf(stdout, "The player with the lowest score was...\n");
        PrintNode(Lowest);

    return 0;
}