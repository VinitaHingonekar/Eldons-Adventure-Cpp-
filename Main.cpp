// Forgotten Treasure of the Evergreen - Eldon's Adventure.

#include <iostream>
#include<ctime>
using namespace std;

class Player {
    
private:

    int health = 100;
    
    int maxDamage = 30;
    int minDamage = 20;
    
    int maxHealing = 15;
    int minHealing = 10;
    
public:

    Player() {
        cout<<"--------------------------------------"<<endl;
        cout<<"Hi, my name is Eldon."<<endl;
        cout<<"We have to defeat the Shadowman."<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Player Stats:"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Eldon's Health : "<<health<<endl;
        cout<<"Eldon's Attack Range : "<<minDamage<<" - "<<maxDamage<<"."<<endl;
        cout<<"Eldon's Healing Range : "<<minHealing<<" - "<<maxHealing<<"."<<endl;
        cout<<"--------------------------------------"<<endl;
    }
    
    int GetHealth()
    {
        return health;
    }
    
    void TakeDamage(int damage)
    {
        
            cout<<"--------------------------------------"<<endl;
            cout<<"Oh no! Shadowman damaged Eldon."<<endl;
            cout<<"Enemy is dealing dmage of "<<damage<<" to Eldon."<<endl;
            health -= damage;
            
        if(health > 0) // player is alive
        {
            cout<<"Eldon's current health after getting damaged is : "<<health<<endl;
            cout<<"--------------------------------------"<<endl;
        }
        else
        {
            cout<<"--------------------------------------"<<endl;
            cout<<"Eldon is dead. \nYOU LOST\nBETTER LUCK NEXT TIME"<<endl;
            cout<<"--------------------------------------"<<endl;
        }
    }
    
    int GiveDamage()
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);
        return randomDamage;
    }
    
    void Heal()
    {
        int randomHeal = (rand() % (maxHealing - minHealing + 1) + minHealing);
        cout<<"--------------------------------------"<<endl;
        cout<<"Eldon will get "<<randomHeal<<" health."<<endl;
        health += randomHeal;
        cout<<"Eldon's current health after getting healed is : "<<health<<endl;
        cout<<"--------------------------------------"<<endl;
    }
};

class Enemy {
  
private:

    int health = 100;
    
    int maxDamage = 40;
    int minDamage = 30;
    
public:

    Enemy()
    {
        cout<<"--------------------------------------"<<endl;
        cout<<"I am the Shadowman!"<<endl;
        cout<<"I am the protector tof the treasure. No one can defeat me."<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Enemy Stats:"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Enemy's Health : "<<health<<endl;
        cout<<"Enemy's Attack Range : "<<minDamage<<" - "<<maxDamage<<"."<<endl;
        cout<<"--------------------------------------"<<endl;
        
    }
    
    int GetHealth()
    {
        return health;
    }
    
    void TakeDamage(int damage)
    {
            cout<<"--------------------------------------"<<endl;
            cout<<"Oh yes! Shadowman was attacked by Eldon."<<endl;
            cout<<"Eldon is dealing dmage of "<<damage<<" to Shadowman."<<endl;
            health -= damage;
            
            if(health > 0) // enemy is alive
            {
                cout<<"Shadowman's current health after getting damaged is : "<<health<<endl;
                cout<<"--------------------------------------"<<endl;
            }
            else
            {
                cout<<"--------------------------------------"<<endl;
                cout<<"Shadowman is dead.\nYOU WON\nCongratulation! You have successfully aquired the treasure map by defeating the Shadowman."<<endl;
                cout<<"--------------------------------------"<<endl;
            }
    }
    
    int GiveDamage()
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);
        return randomDamage;
    }

};

void gameLoop(Player player, Enemy enemy)
{
    char choice;
    
    do{
        cout<<"Press A to attack or H to heal : ";
        cin >> choice;
        
        if(choice == 'a' || choice == 'A')
        {
            system("clear");
            enemy.TakeDamage(player.GiveDamage());
            
            if(enemy.GetHealth() > 0)
            {
                cout<<"Yess! It is my turn now."<<endl;
                player.TakeDamage(enemy.GiveDamage());
            }      
        }
        else if(choice == 'h' || choice == 'H')
        {
            system("clear");
            player.Heal();
            cout<<"Yess! It is my turn now."<<endl;
                player.TakeDamage(enemy.GiveDamage());
        }
        else
        {
            system("clear");
            cout<<"Invalid Input"<<endl;
        }
        
    }while(player.GetHealth() > 0 && enemy.GetHealth() > 0);
}

void gameStory() {
    system("clear");
    cout << "---------------------------------------\nForgotten Treasure of the Evergreen\n---------------------------------------\n" << endl;
    cout << "Eldon, a brave boy, ventured into the Evergreen Forest \nin search of a legendary map that would lead him \nto the Forgotten Treasure." << endl;
    cout << "\n---------------------------------------\n" << endl;
    cout << "As he approached the hidden map, he was confronted \nby the Shadow Man, \nthe dark guardian of the treasure." << endl;
    cout << "\n---------------------------------------\n" << endl;
}

int main() {
    
    gameStory();
    char userInput;
    
    do
    {
        cout<<"Press S to start the game and any other key to exit : ";
        cin>>userInput;
        
        if(userInput == 'S' || userInput == 's')
        {
            system("clear");
            Player player1;
            Enemy enemy1;
            
            gameLoop(player1, enemy1);
        }
        else
        {
            cout<<"Thanks for playing the game!";
        }
    }
    while(userInput == 'S' || userInput == 's');

    return 0;
}
