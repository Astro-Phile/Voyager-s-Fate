#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Stat {
    char name[50];
    int health;
    int attack;
    int defense;
    int mana;
} Stat;

typedef struct {
    int playerX, playerY;
    int banditX[7], banditY[7];
    int itemX[3], itemY[3];
    int powerUpX[2], powerUpY[2];
    int trapX[3], trapY[3];
    int hasPowerUp;
} GameState;

typedef struct {
    char *name;
    char *pattern;
} Constellation;

void printBold(const char *text) {
    printf("\033[1m%s\033[0m", text);
}

char yesno(){
   char yes;
   scanf(" %c",&yes);

 while(getchar() != '\n');// input buffer(needs more reading)
 
if(yes=='y'|| yes=='n'){
     return yes;
}else {
 printf("Wrong Input.");
 printf("Type 'y'to continue and 'n' to go back.\n"); 
 return yesno(); }   // important to write return so that char yes in main has a value assigned and not undifened behavior or garbage .
}

int shareFood() {
    int foodItems = 3;
    int shareChoice;

    printf("After walking avery long day you encountere a house of a family of three.You are tired and they allow you to call the night in their house. After a very heatry talk with the beautiful family you come to know that their situation is not good as the father is ill. They have not been able to hunt any good food and they are practically starving from few days.\n");
    printf("You have three food items in your bag and a long journey ahead.\n");
    printf("Do you want to share your food with them? (1 for Yes, 0 for No): ");
    scanf("%d", &shareChoice);

    if (shareChoice == 0) {
        printf("How cringe! Looks like you are embodiment of selfishness.Do you really think there is place in world for you. Maybe the very tree whose life purpose will be to provide you oxygen will be ashamed of himself.\n");
        return 0;
    }

    printf("How many food items do you want to share? (0-3): ");
    scanf("%d", &shareChoice);

    while(shareChoice < 0 || shareChoice > 3) {
        printf("Invalid choice. You must choose between 0 and 3.\n");
        printf("How many food items do you want to share? (0-3): ");
        scanf("%d", &shareChoice);
    }

    if (shareChoice == 0) {
        printBold("How hypocrite! You can only be good in your thougths and dream.Even the devil is ashamed of how he took you under his wing and it joys him.Cause they is no word of salvation but only suffering in your life dictionary. \n");
        return 0;
    } else if (shareChoice == 1 || shareChoice == 2) {
        printBold("You are a good guy with a considerate heart but you also take care of yourself.Is it a good thing or perhaps it is the way of world.\n");
        return 1;
    } else if (shareChoice == 3) {
        printBold("Even The Great Karna envies you! You gave all your food to the family.Is it not the epitome of selfless to give away every ounce of ourself in service of the humanity.\n");
        return 2;
    }
}
//game 2
int playRockPaperScissorsGame() {
    int playerWins = 0;
    int rounds = 5;

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < rounds; i++) {
        int playerChoice, ginieChoice;
        
        // Get player's choice
        printf("Round %d: Enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): ", i + 1);
        scanf("%d", &playerChoice);
        while (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice. Please enter 0, 1, or 2: ");
            scanf("%d", &playerChoice);
        }

        // Get Ginie's choice
        ginieChoice = rand() % 3;

        // Display choices
        const char *choices[] = {"Rock", "Paper", "Scissors"};
        printf("You chose %s.\n", choices[playerChoice]);
        printf("Ginie chose %s.\n", choices[ginieChoice]);

        // Determine winner
        if (playerChoice == ginieChoice) {
            printf("This round is a tie.\n");
        } else if ((playerChoice == 0 && ginieChoice == 2) ||
                   (playerChoice == 1 && ginieChoice == 0) ||
                   (playerChoice == 2 && ginieChoice == 1)) {
            printf("You win this round!\n");
            playerWins++;
        } else {
            printf("Ginie wins this round.\n");
        }
    }

    // Display final results
    printf("\nFinal Results:\n");
    printf("You won %d out of %d rounds.\n", playerWins, rounds);

    return playerWins;
}
//game 1
void shuffle(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

int guess() {
    srand(time(NULL));

    char *words[] = {"lynx","glyph", "nymph", "crypt", "joust","quark", 
                     "azure", "axiom", "blitz", "cozy", "equip","endeavor",
                     "conundrum","magnificent","endeavor","exquisite","perplexing",
                     "splendid","fascinate","serene","curiosity"};
    int numWords = sizeof(words) / sizeof(words[0]);
    int usedIndices[4]={-1};// To store indices of used words
    int winCount = 0;
    printf("You come across a stone cave with strange words and you try to make sense of it.\n");
    for (int round = 0; round < 5; round++) {
        int index,yes=0;
        do {
            index = rand() % numWords;
            for(int i=0;i<4;i++){
              if(index==usedIndices[i]){yes=1;}
            }
        } while (yes==1); // Mark this word as used
        usedIndices[round]=index;

        char word[15];
        char scrambled[15];
        strcpy(word, words[index]);
        strcpy(scrambled, word);

        shuffle(scrambled);

        printf("\nRound %d - Unscramble the word: %s\n", round + 1, scrambled);

        char guess[15];
        printf("Your guess: ");
        scanf("%s", guess);

        if (strcasecmp(guess, word) == 0) {
            printf("Correct! The word is %s.\n", word);
            winCount++;
        } else {
            printf("Wrong! The correct word was %s.\n", word);
        }
    }

    printf("\nYou guessed correctly %d out of 5 times.\n", winCount);

    if(winCount<1){
      printBold("\nAre you sure this story is written in english?Cause you just do not seem to get it.\nWell even this is a bouncer for you ,just go back to nursery kid.");
      return 0;
    }else if(winCount==5){
      printBold("Aren\'t you a guessing wizard or maybe just a cheater.Well then off you go as the world shall be the judge and your path the punishment.");
      return 2;
    }else{
      printBold("Darkness is vast and ever incompassing and sometimes just guessing the way of light can bring upon enlightenment.");
      return 1;
    }
}
// game 3
int random(int a) {
    int b = rand() % (a + 1);
    if (b < 1) {
        return random(a);
    } else {
        return b;
    }
}

void fight(Stat *p1, Stat *p2, char ch) {
    int damage, x = 0, y = 0;
    if (ch == 'a') {
        y = 5;
    } else if (ch == 'd') {
        x = 5;
    } else if (ch == 'm') {
        if (p2->mana > 0) {
            y = 10;
            p2->mana--; // Reduce mana after use
        } else {
            printf("%s tried to use mana but has none left!\n", p2->name);
            return;
        }
    }
    damage = random(p1->defense + x) - random(p2->attack + y);
    if (damage > 0) {
        p1->health -= damage;
        printf("%s dealt the damage of %d.\n", p2->name, damage);
    } else {
        printf("%s evaded the attack.\n", p1->name);
    }
}

int rpgGame() {
    Stat player = {"You", 15, 10, 8, 2};
    Stat dragon = {"Dragon", 25, 15, 10, 0};
    printf("\nSuddenly you encounter a dragon and have disturbed him. Now you made him furious and can not escape.\nA last option remains either slay or be slayed.\n");
    while (player.health > 0 && dragon.health > 0) {
        printf("\nYou : Health=%d, Attack=%d, Defence=%d, Mana=%d.\n", player.health, player.attack, player.defense, player.mana);
        printf("Dragon : Health=%d, Attack=%d, Defence=%d, Mana=%d.\n", dragon.health, dragon.attack, dragon.defense, dragon.mana);
        printf("Type a for Attacking, d for Defending and m for using Mana to attack: ");
        
        char ch;
        scanf(" %c", &ch); 

        while (ch != 'a' && ch != 'd' && ch != 'm') {
            printf("Invalid input. Try again: ");
            scanf(" %c", &ch); 
        }

        fight(&dragon, &player, ch);
        fight(&player, &dragon, 'n');
    }

    if (player.health < 1) {
        printBold("\nUnfortunate! Pity you could not even win a simple fight.\nLooks like adventure is not the thing for you. If it is, try again and see you soon.\n");
        return 0;
    } else if (player.health < 10) {
        printBold("\nYou survived the dragon. Now you can flaunt your scars proudly as only few are the lucky ones.\n");
        return 1;
    } else {
        printBold("\nYou slayed the dragon. What battle scars? It would take more than a dragon for them to scar you.\n");
        return 2;
    }
}
//game 4

void resetGrid(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = '-';
        }
    }
}

void placeMoles(char grid[3][3]) {
    int count = 0;
    while (count < 4) { // Ensure we place exactly 4 moles
        int row = rand() % 3;
        int col = rand() % 3;
        grid[row][col] = 'R';
        count++;
    }
}

void printGrid(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int whackRabbit() {
    srand(time(NULL)); 
    printf("You come across a big opening where there are a lot of rabbits hidding in holes.\nThey can make a good meal in journey ahead, so get in battle of agility and luck.\n");
    int hits = 0, rounds = 0;
    char grid[3][3];
    int row, col;
    resetGrid(grid);
    printGrid(grid); 

    while (rounds < 5) {
        rounds++;
        placeMoles(grid); 

        printf("Chance %d\n", rounds);
        
        printf("Enter row and column to whack (e.g., '2 1'): ");
        scanf("%d %d", &row, &col);
        row--;col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            printf("Invalid input! Please enter values within the grid range.\n");
            rounds--; // Don't count this round if the input was invalid
            continue;
        }
        printGrid(grid); 

        if (grid[row][col] == 'R') {
            printf("Hit!\t\t");
            hits++;
        } else {
            printf("Missed!\t\t");
        }

        printf("Score: %d\n", hits);
        resetGrid(grid);
    }

    printf("You killed %d moles.\n", hits);
    if(hits<1){
      printBold("Athleticism is the boon you shall never have!\nFor what are you if not a shambles of bones with courage so less that even the fear itself is braver.");
      return 0;
      }else if(hits>3){
        printBold("Fast and Lucky shall be retired from dictionary in this realm to commerate you when you are rubbles if you continue like this");
        return 2;
      }else{
        printBold("Just another lucky day!Being Average is it curse or perhaps a boon, for he shall never know the highest but just enough to feel it all");
        return 1;
      }
    
}
//game 5

char getChoice() {
    char choice;
    printf("\nChoose a direction to move:\n");
    printf("W - Move forward\n");
    printf("A - Move left\n");
    printf("S - Move backward\n");
    printf("D - Move right\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice;
}

void findTreasure(int *health) {
    printf("You find a hidden treasure chest! Inside, you discover:\n");
    int treasure = rand() % 3;
    switch(treasure) {
        case 0:
            printf("- A pile of gold coins! You feel wealthier.\n");
            break;
        case 1:
            printf("- A rare gemstone! Its glow fills you with hope.\n");
            break;
        case 2:
            printf("- A magical amulet! It radiates energy, healing your wounds.\n");
            *health += rand() % 20 + 10; // Health increment between 10 and 29
            if (*health > 75) {
                *health = 75; // Cap health at maximum value
            }
            break;
    }
}

void springTrap(int *health) {
    printf("You step on a trap! It's a...\n");
    int trap = rand() % 3;
    switch(trap) {
        case 0:
            printf("- Pitfall! You fall into a hole and lose some health.\n");
            *health -= rand() % 10 + 10; // Health deduction between 10 and 19
            break;
        case 1:
            printf("- Net trap! You're caught and struggle to free yourself.\n");
            *health -= rand() % 5 + 5; // Health deduction between 5 and 9
            break;
        case 2:
            printf("- Poison darts! You narrowly dodge them but feel weakened.\n");
            *health -= rand() % 15 + 5; // Health deduction between 5 and 19
            break;
    }
}

void riddleChallenge(int *health) {
    printf("A mystical creature appears and gives you a riddle. Solve it to proceed.\n");
    int riddle = rand() % 3;
    char answer[50];
    
    switch(riddle) {
        case 0:
            printf("Riddle: What has keys but can't open locks? ");
            scanf("%s", answer);
            if (strcasecmp(answer, "keyboard") == 0) {
                printf("Correct! The creature lets you pass.\n");
            } else {
                printf("Wrong! The creature blocks your path and you have to go back.\n");
                *health -= rand() % 5 + 5; // Health deduction between 5 and 9
            }
            break;
        case 1:
            printf("Riddle: What gets wetter as it dries? ");
            scanf("%s", answer);
            if (strcasecmp(answer, "towel") == 0) {
                printf("Correct! The creature lets you pass.\n");
            } else {
                printf("Wrong! The creature blocks your path and you have to go back.\n");
                *health -= rand() % 10 + 5; // Health deduction between 5 and 14
            }
            break;
        case 2:
            printf("Riddle: I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I? ");
            scanf("%s", answer);
            if (strcasecmp(answer, "echo") == 0) {
                printf("Correct! The creature lets you pass.\n");
            } else {
                printf("Wrong! The creature blocks your path and you have to go back.\n");
                *health -= rand() % 15 + 5; // Health deduction between 5 and 19
            }
            break;
    }
}

void mysticalEncounter(int *health) {
    printf("A mystical creature appears. It's a...\n");
    int creature = rand() % 3;
    switch(creature) {
        case 0:
            printf("- Friendly elf! They give you a healing potion.\n");
            *health += rand() % 20 + 10; // Health increment between 10 and 29
            if (*health > 75) {
                *health = 75; // Cap health at maximum value
            }
            break;
        case 1:
            printf("- Mischievous fairy! They play a trick on you, causing you to lose your way.\n");
            break;
        case 2:
            printf("- Wise old sage! They offer you wisdom that helps you on your journey.\n");
            break;
    }
}

void encounterEvent(int *health) {
    int event = rand() % 4;
    switch(event) {
        case 0:
            findTreasure(health);
            break;
        case 1:
            springTrap(health);
            break;
        case 2:
            riddleChallenge(health);
            break;
        case 3:
            mysticalEncounter(health);
            break;
    }
}

int navigateMaze() {
    srand(time(NULL));
    printf("You find yourself in a dense forest maze. The path ahead is unclear,\n");
    printf("and you must navigate your way out. You can sense this maze holds traps and mystical creatures,\n");
    printf("but also hidden treasures.\n");
 
    int steps = 0;
    int correctPath = rand() % 5 + 5; // Random correct path length between 5 and 9
    int health = 75; // Initialize health
    while (steps < correctPath && health > 0) {
        printf("\nCurrent Health: %d\n", health);
        char choice = getChoice();
        steps++;
        if (rand() % 2 == 0) { // Randomly encounter events
            encounterEvent(&health);
        } else {
            printf("You move %c without any encounter and delay.\n", choice);
        }
    }

    if (health <=0) {
        printBold("\nFor all lives are not meant of the a single universe as all must chose where they perish.\nBut for you my dear it seems all road lead to crumble.Or can you become the very road they all wish they could walk?\n");
        return 0;
    } else if(health>50){
        printBold("Through is the Only way for you.\nAll the poisons cannot fathom your being for you have already girdeled enough to shake the world around.\n");
        return 2;
    }else{
      printBold("\nJust surving is it a curse or a boon?For the survivor does not just suffer the joy of being alive but also boon of shredded companionship.\n");
      return 1;
      }
}
//game 6

void initializePositions(GameState *game) {
    game->playerX = random(9);
    game->playerY = random(9);
    
    for (int i = 0; i < 7; i++) {
        game->banditX[i] = random(9);
        game->banditY[i] = random(9);
    }
    
    for (int i = 0; i < 3; i++) {
        game->itemX[i] = random(9);
        game->itemY[i] = random(9);
    }
    
    for (int i = 0; i < 2; i++) {
        game->powerUpX[i] = random(9);
        game->powerUpY[i] = random(9);
    }
    
    for (int i = 0; i < 3; i++) {
        game->trapX[i] = random(9);
        game->trapY[i] = random(9);
    }
}

void printField(GameState *game) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (x == game->playerX && y == game->playerY) {
                printBold("P ");
            } else {
                int isPrinted = 0;
                
                for (int i = 0; i < 3; i++) {
                    if (x == game->itemX[i] && y == game->itemY[i]) {
                        printBold("I ");
                        isPrinted = 1;
                        break;
                    }
                }
                
                for (int i = 0; i < 2; i++) {
                    if (x == game->powerUpX[i] && y == game->powerUpY[i]) {
                        printf("U ");
                        isPrinted = 1;
                        break;
                    }
                }
                
                for (int i = 0; i < 3; i++) {
                    if (x == game->trapX[i] && y == game->trapY[i]) {
                        printf("T ");
                        isPrinted = 1;
                        break;
                    }
                }
                
                if (!isPrinted) {
                    int isBandit = 0;
                    for (int i = 0; i < 7; i++) {
                        if (x == game->banditX[i] && y == game->banditY[i]) {
                            printf("B ");
                            isBandit = 1;
                            break;
                        }
                    }
                    if (!isBandit) {
                        printf(". ");
                    }
                }
            }
        }
        printf("\n");
    }
}

void moveBandits(GameState *game) {
    for (int i = 0; i < 7; i++) {
        int direction = random(4);
        switch (direction) {
            case 4: // Move up
                if (game->banditY[i] > 0) game->banditY[i]--;
                break;
            case 1: // Move down
                if (game->banditY[i] < 10 - 1) game->banditY[i]++;
                break;
            case 2: // Move left
                if (game->banditX[i] > 0) game->banditX[i]--;
                break;
            case 3: // Move right
                if (game->banditX[i] < 10 - 1) game->banditX[i]++;
                break;
        }
    }
}

int negotiateRelease(GameState *game) {
    printf("You have been captured by the bandits!\n");
    printf("You can try to negotiate your release.\n");
    printf("Enter your offer percentage of your loot and gold (0-100): ");
    int offer;
    scanf("%d", &offer);
    if (offer >= 70) {
        printf("The bandits accept your offer and release you.\n");
        return 1;
    } else {
        printf("The bandits reject your offer and kill you.\n");
        return 0;
    }
}

int playStealth() {
    srand(time(NULL)); // Seed the random number generator

    GameState game = {0};
    game.hasPowerUp = 0;

    initializePositions(&game);

    printf("The small village you encouter has been robbed.And you can gain so much if you help them.\n");
    printf("Your goal is to retrieve the important items (I) without being caught by the bandits (B).\n");
    printf("Avoid the traps (T) and collect power-ups to avoid detection(U).\n");
    printf("You are represented by 'P'.\n");

    int failures = 0, gameup = 0 , itemsCollected = 0;

    while (gameup==0) {
        printField(&game);
        printf("Enter your move (w/a/s/d) : ");
        char move;
        scanf(" %c", &move);

        // Move the player
        switch (move) {
            case 'w':
                if (game.playerY > 0) game.playerY--;
                break;
            case 's':
                if (game.playerY < 10 - 1) game.playerY++;
                break;
            case 'a':
                if (game.playerX > 0) game.playerX--;
                break;
            case 'd':
                if (game.playerX < 10 - 1) game.playerX++;
                break;
           default:
                printf("Invalid move. Use w/a/s/d to move.\n");
                continue;
        }

        // Check if the player has reached an item
        for (int i = 0; i < 3; i++) {
            if (game.playerX == game.itemX[i] && game.playerY == game.itemY[i]) {
                printf("You have retrieved an item!\n");
                game.itemX[i] = -1; // Remove the item from the field
                game.itemY[i] = -1;
                itemsCollected++;
            }
        }

        // Check if the player has reached a power-up
        for (int i = 0; i < 2; i++) {
            if (game.playerX == game.powerUpX[i] && game.playerY == game.powerUpY[i]) {
                printf("You have found a power-up!\n");
                game.powerUpX[i] = -1; // Remove the power-up from the field
                game.powerUpY[i] = -1;
                game.hasPowerUp++; // Player now has a power-up
            }
        }
         int caught=0;
         // Check if the player steps on a trap
        for (int i = 0; i < 3; i++) {
           if (game.playerX == game.trapX[i] && game.playerY == game.trapY[i]) {
               printf("You step on a trap.AAHH!The bandits might have heard you.\n");
               caught++;
            }
       }

        // Move the bandits
            moveBandits(&game);
        // Check if the player is caught by a bandit
         for (int i = 0; i < 7; i++) {
             if (game.playerX == game.banditX[i] && game.playerY == game.banditY[i]) {
                 caught++;
            }
        }

        if(caught>0 && game.hasPowerUp > 0){
           printf("You are nearly caught but use your power-up to become invisible for one move!\n");
           game.hasPowerUp--;
           caught=0; 
        }else if (caught>0 ) {
            int success = negotiateRelease(&game);
            if (success) {
                // Place player in a random safe location
                do {
                    game.playerX = random(10 - 1);
                    game.playerY = random(10 - 1);
                } while (caught>0); // Ensure the new position is safe
                caught=0;
                failures++;
                continue; // Continue the game from the new position
            } else {
                printBold("\nChild! The world is a fury and you too delicate to tread it.\nHope you are brave enough to lose it all over,as the ones that quit never mattered.\n");
                return 0;
            }
        }

        // Check if all items are collected
        if (itemsCollected == 3) {
            gameup=1;
        }
    }
    if(failures==0){
        printBold("\nThe eminence is shadow!\nBeing sleek to sweep away anyone floor with dready silence is the true power,as loud is the prey but silent is one who prowls\n");
        return 2;
    }else{
        printBold("\nFools try to sway all.But wise ones are busy swaying the ones who matter.\n");
        return 1;
    }
}
//game 7

void negotiate(int *successCount, int *failureCount,int usedIndices[]) {
    int scenario ,yes=0;
        do {
            scenario=random(6);
            for(int i=0;i<4;i++){
              if(scenario==usedIndices[i]){yes=1;}
            }
        } while (yes==1); // Mark this word as used
        for(int i=0;i<4;i++){
            if(usedIndices[i]==(-1)){
               usedIndices[i]=scenario;
               break;
            }
        }
        
    switch (scenario) {
        case 1:
            printf("\nScenario: Water Shortage\n");
            printf("NPC 1: Our village needs more water to irrigate our crops.\n");
            printf("NPC 2: But diverting water will leave our village without enough.\n");
            printf("NPC 3: We cannot let our crops fail due to lack of water!\n");
            break;
        case 2:
            printf("\nScenario: Trade Dispute\n");
            printf("NPC 1: We demand lower prices for your goods.\n");
            printf("NPC 2: Lower prices will bankrupt our businesses!\n");
            printf("NPC 3: We need fair prices to sustain our livelihoods!\n");
            break;
        case 3:
            printf("\nScenario: Territory Dispute\n");
            printf("NPC 1: Our tribe claims ownership of this land.\n");
            printf("NPC 2: But we have been living here for generations!\n");
            printf("NPC 3: We cannot allow our territory to be encroached upon!\n");
            break;
        case 4:
            printf("\nScenario: Resource Allocation\n");
            printf("NPC 1: We need more resources for our research project.\n");
            printf("NPC 2: But allocating more resources will delay our construction project.\n");
            printf("NPC 3: We cannot afford any delays in our construction!\n");
            break;
        case 5:
            printf("\nScenario: Environmental Preservation\n");
            printf("NPC 1: We must protect this forest from logging.\n");
            printf("NPC 2: But logging is essential for our village's economy.\n");
            printf("NPC 3: We cannot sacrifice our economy for the sake of the forest!\n");
            break;
        case 6:
            printf("\nScenario: Total Concession\n");
            printf("NPC 1: We demand complete withdrawal of your proposal.\n");
            printf("NPC 2: Any compromise will result in public unrest.\n");
            printf("NPC 3: We expect you to concede entirely to avoid conflict.\n");
            break;
    }

    int offer = -1;
    while (offer < 0 || offer > 100) {
        printf("\nYour Offer (0-100%%): ");
        scanf("%d", &offer);
        if (offer < 0 || offer > 100) {
            printf("Please enter a value between 0 and 100.\n");
        }
    }

    // Evaluate negotiation outcome
    printf("\nYou propose to offer %d%%.\n", offer);
    if ((scenario == 1 && offer >= 50 && offer<=70) || (scenario == 2 && offer >= 60 && offer<=90) || (scenario == 3 && offer >= 80) || (scenario == 4 && offer >= 40 && offer<=60) || (scenario == 5 && offer <= 50 && offer>=20)) {
        printf("The NPCs agree to your offer and the negotiation is successful.\n");
        (*successCount)++; // Increment success count
    } else if (scenario == 6 && offer == 0) {
        printf("You agree to the NPCs' demand of complete withdrawal, averting potential conflict.\n");
        (*successCount)++; // Increment success count
    } else {
        printf("The NPCs reject your offer, feeling it's insufficient.\n");
        (*failureCount)++; // Increment failure count
    }
}

int theNegotiations() {
    srand(time(NULL)); // Seed the random number generator

    printf("You dose off now that you are tired in this journey.You seem to find yourself in a similar yet different world\nIs this parallel world or are you dreaming.Suddenlyn you find your self on a throne and it seems you are a king.\nNow you have got some dispute to take care of.Not the perfect first day starter job. But you wanna go with flow else maybe this could be trouble.\n");

    int successCount = 0; // Counter to track successful negotiations
    int failureCount = 0; // Counter to track failed negotiations
    int usedIndices[4]={-1};
    // Simulated gameplay loop
    for (int i = 1; i <= 5; i++) { // Let's say the player encounters 5 negotiation scenarios
        printf("\n--- Negotiation Scenario %d ---\n", i);
        negotiate(&successCount, &failureCount,usedIndices);
    }

    printf("\nYou successfully resolved %d out of 5 negotiation scenarios in your dream.\n\n", successCount);
   if(successCount>3){
    printBold("For what are words if not just a different sign to rule the world.\nWhy do you require swords when words are already enough honey serrated and poison honed?\n");
    return 2;
   }else if(successCount>0){
    printBold("Balance, is not the illusion to compromise greatness?\nIs it not midiocrity where neither epitome of one nor zenith of another is promised.\n");
    return 1;
   }else{
    printBold("What is the purpose of life if not be able to transact on better ternms than we were dealth with\n In which you seem to excell at the lowest lengths.\n");
    return 0;
    }
    
}
//game 8

int checkTimeBonus(time_t startTime) {
    time_t endTime = time(NULL);
    double timeTaken = difftime(endTime, startTime);
    printf("You guessed constellations in %.2f seconds!\n", timeTaken);
       
    if (timeTaken <= 60) {
        printf("Are you astrophile!Cause you guessed all within 60 seconds\n");
        return 1; // Bonus achieved
    }
    return 0; // No bonus
}

void initializeConstellations(Constellation constellations[]) {
    constellations[0].name = "Orion";
    constellations[0].pattern = "     *\n    * *\n     * *\n    * * *\n";

    constellations[1].name = "Big Dipper";
    constellations[1].pattern = "      *\n     *\n    *\n    *\n     *\n      *\n       *\n";

    constellations[2].name = "Cassiopeia";
    constellations[2].pattern = "    *   *\n     * *\n      *\n     * *\n    *   *\n";

    constellations[3].name = "Scorpius";
    constellations[3].pattern = "      *\n     *\n      *\n       *\n      * *\n     *   *\n";

    constellations[4].name = "Cygnus";
    constellations[4].pattern = "      *\n      *\n    * * *\n      *\n      *\n";

    constellations[5].name = "Leo";
    constellations[5].pattern = "        *\n       *\n     * *\n    *\n     *\n";

    constellations[6].name = "Lyra";
    constellations[6].pattern = "      *\n     * *\n    *   *\n";

    constellations[7].name = "Taurus";
    constellations[7].pattern = "     *   *\n    * * *\n     * *\n      *\n";

    constellations[8].name = "Ursa Major";
    constellations[8].pattern = "       *\n      *\n     * *\n    *   *\n";

    constellations[9].name = "Ursa Minor";
    constellations[9].pattern = "       *\n      *\n     *\n    *\n";
}

void shuffleArray(int array[], int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

int playCelestialObservatory() {
    srand(time(NULL)); // Seed the random number generator

    Constellation constellations[10];
    initializeConstellations(constellations);
    int score = 0;
    char guess[50];
    int indices[10];

    for (int i = 0; i < 10; i++) {
        indices[i] = i;
    }

    shuffleArray(indices, 10);

    printf("One night when you are chilling under moonlight, stars seem brighter.\n");
    printf("You seem to notice constelations one after another.\nYou understand there is greater picture at play and try Guess the name of the constellation as fast as you can.\n\n");

    // Start timing
    time_t startTime = time(NULL);
    
    for (int round = 0; round < 5; round++) {
        int index = indices[round];
        printf("Round %d:\n", round + 1);
        printBold(constellations[index].pattern);
        printf("\nYour guess: ");
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0; // Remove trailing newline

        if (strcasecmp(guess, constellations[index].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", constellations[index].name);
        }
        printf("\n");
    }

    // Check for bonus
    int x=checkTimeBonus(startTime);
    if (x==1 && score>3) {
        printBold("\nStars are the lightsource of revolving planets and yet they burn themselves in the process.\nBetter decide if you wanna be a star and also for whom you are ready to be ashes.\n");
        return 2;
    }else if(score>0){
        printBold("\nFor all humankind stars have been the pointers to a hope of fabulous dreams fulfilled.\nBut if once shall know all gifts then pleasure of attaining will lose.\n");
        return 1;
    }else{
        printBold("\nHe shall never know simple pleasures of life ,for he has lost himself the attaining.\nAre you sure your shadow is proud to be yours??\n");
        return 0;
    }

}
//game 9


void backstory(){
  printf("\nAs a baby, you were found abandoned in the woods by your savior. He wad out gathering herbs when he stumbled upon you, nestled in a basket under a tree. Your savior, with their heart full of compassion, took you in and brought you to the village. he didn't know who your parents were or why you were left in the woods, but he knew that you deserved a loving home.\n\nYour savior never revealed your origins to anyone in the village. He raised you as their own, teaching you about magic and the wonders of the forest. Your parents, who were skilled in their respective crafts, never had a chance to meet you. They had passed away before you were found, leaving behind a legacy of knowledge and kindness.\n\nGrowing up, you never felt the absence of your biological parents. Your savior filled that void with love and guidance, always reminding you that you were meant for great things. He often said that it didn't matter where you came from; what mattered was where you were going.\n\nYour savior was a spell caster. He had a special connection with the natural world and had a knack for weaving magic into everyday life. They were the one who found you as a baby, abandoned you in the woods, and brought you to your parents. They often said that you were meant for great things, that your destiny was bound to be extraordinary.\n\nOne day, when you were young, you and your savior were exploring the woods together. You stumbled upon a group of mischievous fairies who were causing trouble for the villagers. Your savior, with a twinkle in their eye, cast a spell that made the fairies laugh uncontrollably, and they promised never to bother the village again.\n\nAnother time, you and your savior were trying to catch a rare, magical butterfly for your mother's birthday. The butterfly was elusive, flitting from flower to flower faster than you could follow. But your savior whispered a spell, and suddenly the butterfly flew right into your hands.\n\nYour savior was your mentor, your guide, and your friend. They taught you about the wonders of magic, the importance of kindness, and the beauty of the natural world. You looked up to them with admiration and affection, and you knew that you could always count on them.\n\nBut then, tragedy struck. Your savior passed away unexpectedly, leaving you feeling lost and alone. You also recently lost your best friend in an accident. With no purpose and a heavy heart, you decided to set out on an adventure. You gathered a few technology and magic equipment that your savior had left behind, determined to fulfill their words and honor the memory of your friend.\n\nNow you stand on the crossroads in the woods , every step that you take will lead to a future that you manifest. What you choose will  matter , you will matter.\n\nAs you venture deeper into the wilderness, you come across a fork in the path. To the left lies a dense forest, filled with ancient trees and the whispers of forgotten magic. To the right is a winding mountain path, leading towards a distant peak where the gleam of future technologies can be seen.\n\nFeeling a mix of trepidation and excitement, you stand at the crossroads, uncertain of which path to take. The forest calls to you, its mysterious allure pulling at your heartstrings. You remember the stories your savior used to tell you about the wonders hidden within those ancient trees.\n\nBut then, you glance to the right, and the sight of the gleaming technologies on the distant peak fills you with a sense of longing. Your savior often spoke of the advancements that awaited beyond the mountains, the wonders of a world you had never seen.");
}

void mountainpath(){
  printf("\nWas that a dream or did a ginie was really here to test your luck ?\nYou do not quite remember the details but the best course of action would be to move on now.\n\nAfter a moment of deliberation, you make your decision. You choose the mountain path, feeling a sense of determination wash over you. You take a deep breath and begin your ascent, the rugged terrain challenging your every step.\n\nAs you climb higher and higher, the air grows thinner, and the landscape changes. You leave the lush forest behind and enter a rocky, barren landscape. But you press on, fueled by the promise of what lies ahead.As you continue along the mountain path, you encounter a variety of creatures and experiences that both challenge and inspire you. The rugged terrain is home to a diverse array of wildlife, each species adapted to its unique environment.\n\nYou come across a family of mountain goats, their sure-footedness and agility a testament to their mastery of the rocky landscape. You watch in awe as they navigate the steep cliffs with ease, their powerful hooves gripping the narrow ledges.\n\nFurther along the path, you encounter a group of wild boars foraging for food in the underbrush. You observe them from a distance, marveling at their strength and resilience. Their powerful tusks and thick hides are a reminder of the harsh realities of survival in the wilderness.\n\nAs you climb higher, you come across a flock of mountain birds, their vibrant plumage a stark contrast to the barren landscape. You watch as they soar through the sky, their graceful movements a testament to their mastery of the air.\n\nThe higher you climb, the more the landscape changes. You leave the rocky terrain behind and enter a lush alpine meadow. Here, you encounter a herd of deer grazing peacefully in the grass. You watch as they move gracefully through the meadow, their delicate features and graceful movements a stark contrast to the ruggedness of the mountain.\n\nAs you continue along the path, you come across a mountain lake, its crystal-clear waters reflecting the surrounding peaks. You take a moment to rest and drink from the cool, refreshing water, savoring the beauty and tranquility of the moment.\n\nAs you continue your journey, you encounter various challenges and obstacles along the way. The terrain becomes increasingly rugged, and you have to navigate treacherous cliffs and narrow ledges. But with each challenge, you grow stronger and more determined.\n\nFinally, after what feels like an eternity, you reach the summit. You stand at the peak, gazing out at the breathtaking view before you. The future technologies are even more impressive up close, their sleek designs and advanced functionalities leaving you in awe.\n\nBut as you look around, you realize that something is missing. You had embarked on this journey to fulfill your savior's words, to honor your friend's memory, but you still feel lost and alone.\n\nSuddenly, a gust of wind sweeps through the mountaintop, and you hear a familiar voice. It's your savior's voice, carried on the wind, speaking words of encouragement and wisdom.\n\nWith renewed determination, you set out to explore the future technologies, eager to learn and grow. And as you immerse yourself in this new world, you carry your savior's memory with you, knowing that they will always be a part of your journey.");
}

void forestpath(){
printf("\nWas that a dream or did a ginie was really here to test your luck ?\nYou do not quite remember the details but the best course of action would be to move on now.\n\nAfter a moment of deliberation, you make your decision. You choose the forest path, feeling a sense of determination wash over you. You take a deep breath and begin your journey. \n\nAs you step into the forest, you are immediately enveloped by the lush greenery and the sense of mystery that hangs in the air. The trees seem to whisper secrets, their rustling leaves a gentle chorus of ancient magic. You can almost feel the presence of your savior beside you, their comforting aura guiding you through the dense foliage. \n\nAs you venture deeper into the forest, you come across signs of the magical creatures that call this place home. You catch glimpses of colorful birds flitting through the branches, their songs echoing through the trees. You spot a family of foxes playing in a sun-dappled clearing, their playful antics a testament to the joy of life in the wild. \n\nBut it's not just the animals that exude magic in this forest. As you continue your exploration, you stumble upon hidden glens and enchanted groves, each one pulsing with mystical energy. You come across patches of glowing mushrooms that illuminate the forest floor, casting an ethereal glow that dances across the leaves. \n\nAs you reach a particularly dense thicket, you sense a presence watching you from the shadows. You freeze, your senses on high alert as you try to discern the source of the feeling. Suddenly, a pair of glowing eyes emerge from the darkness, belonging to a majestic stag with antlers that seem to shimmer with magic. It regards you with a wise gaze before disappearing into the depths of the forest, leaving you with a sense of wonder and awe. \n\nAs you continue your journey, you encounter more signs of the ancient magic that permeates the forest. You stumble upon a hidden waterfall, its waters sparkling with an otherworldly light. You reach out to touch the cascading water, and you feel a tingling sensation course through your veins, as if the magic of the forest is flowing through you. \n\nAs you emerge from the depths of the forest, you feel a sense of gratitude for the experience. The secrets and wonders you've encountered have left an indelible mark on your soul, reminding you of the beauty and magic that still exists in the world. And as you continue on your journey, you carry the presence of your savior with you, knowing that they are guiding you every step of the way. \n\nAs you venture deeper into the forest, the dense foliage and towering trees seem to envelop you, creating an atmosphere of mystery and wonder. The rustling leaves and the distant calls of animals add to the sense of adventure. \n\nSuddenly, a group of deer appears, gracefully bounding through the underbrush. You watch in awe as the animals leap effortlessly over fallen logs and streams, their movements almost ethereal in the dappled sunlight. \n\nContinuing on your journey, you come upon a clearing where you see something truly magical. A small, shimmering pool of water lies in the center, surrounded by a ring of mushrooms that glow softly in the twilight. Mesmerized, you approach the pool, feeling a sense of calm wash over you. \n\nBut as you reach out to touch the water, you hear a rustling behind you. Whirling around, you see a pair of glowing eyes staring at you from the shadows. Without thinking, you turn and run, your heart pounding in your chest. ");
}

void ShipFight(){
  printf("\n\nYou stumble upon a clearing where you see something you had never expected to find . A sleek, silver spaceship stands before you, its hatch open invitingly. Without hesitating, you climb inside, feeling the hum of advanced technology beneath your fingertips.\n\nAs you explore the interior of the spaceship, you can't shake off the feeling of unease that gnaws at the back of your mind. The walls are lined with strange devices and monitors, and the air is heavy with the scent of metal and ozone.You know about airships but this one seems too advanced.\n\nSuddenly the engines roar to life, propelling the sleek craft upwards into the sky with incredible speed. You're tossed around inside the cabin, your stomach lurching as the ship climbs higher and higher.\n\nAfter what feels like an eternity, the ship levels off, and you find yourself floating weightlessly in the zero-gravity environment. You cling to the nearest handhold, trying to steady yourself as the ship hurtles through space.\n\nBut just as suddenly as it began, the sensation of weightlessness fades, and you feel the familiar pull of gravity as the ship begins its descent. You brace yourself as the spacecraft plunges back towards the earth, the air rushing past you with dizzying speed.\n\nAs the ship touches down, you're thrown forward with the force of the impact, but you manage to steady yourself before you fall. With cautious steps, you start to make your way to the hatch .\n\nYou hear footsteps approaching from the opposite direction, and before you can react, a group of armed figures burst into the room. They're dressed in dark uniforms, and their faces are hidden behind intimidating masks. Without a word, they raise their weapons, and you realize with a sinking feeling that you're in danger.\n\nInstinct takes over as you summon your magical abilities, ready to defend yourself against the threat. Arcane energy crackles around you as you unleash a barrage of spells, each one striking true against your assailants. The air fills with the sound of gunfire and magical explosions as the battle rages on.\n\nYou duck and weave, dodging bullets and spells with lightning-fast reflexes. Your heart pounds in your chest as you fight with all your strength, refusing to back down in the face of adversity. The walls of the spaceship reverberate with the force of the battle, and you can feel the sweat trickling down your brow as you push yourself to the limit.\n\nWith each passing moment, you can feel yourself growing stronger and more determined. You tap into the depths of your magical abilities, drawing on reserves of power you never knew you had. Your movements become more fluid and precise, and you find yourself anticipating your opponents' attacks with uncanny accuracy.\n\nFinally, after what feels like an eternity, you emerge victorious. The last of your assailants lie defeated at your feet, their weapons scattered across the floor. You take a moment to catch your breath, the adrenaline still coursing through your veins.\n\nBut there's no time to rest. You quickly gather your wits and set about freeing the captives held within the spaceship. With a few deft spells, you disable the locks on their restraints, and they emerge from their cells with gratitude shining in their eyes.\n\nTogether, you make your way through the labyrinthine corridors of the spaceship, fighting off any remaining guards that stand in your way. At last, you reach the exit, and with a final burst of magical energy, you blast open the hatch and step out into the cool night air.\n\nAs you look out over the landscape, you realize that you're in a high valley, far from the bustling tech city you had heard so much about. But despite the distance, you know that your journey is far from over. With your newfound allies by your side, you set out once more, ready to face whatever challenges lie ahead.");
}

void ForestFight(){
printf("\n\nAs you venture deeper into the enchanted forest, the sense of mystery intensifies, and the whispers of the trees seem to grow uncomfortably louder. Shafts of golden sunlight pierce through the thick canopy above, casting small dappled patterns of light and shadow on the forest floor. The air is thick with the scent of pine and earth, and you can feel a bit of dark magic of the forest swirling around you like a tangible presence.\n\nSuddenly, without warning, you feel a strange pull at your senses, and before you can react, you're engulfed in a blinding flash of light. As your vision clears, you find yourself standing in a place unlike any you've ever seen. The surroundings are surreal, with towering crystalline structures that seem to pulse with an otherworldly energy. Each facet of the crystals refracts the light in a dazzling display of colors, casting rainbow hues across the landscape.\n\nThe air crackles with magic, and you can feel it tingling against your skin like a thousand tiny needles. Strange, ethereal creatures flit through the air, their forms shimmering and shifting as if they're made of pure energy. You watch in awe as they dance and play among the crystalline structures, their movements graceful and mesmerizing.\n\nBefore you can fully comprehend your surroundings, you're surrounded by a group of figures cloaked in shadows. They move with an eerie grace, their eyes glowing with malice as they advance towards you. Panic surges through you as you realize that you've been abducted by unknown forces.\n\nWith a surge of adrenaline, you summon your magical abilities, determined to fight back against your captors. Arcane energy crackles around you as you unleash a barrage of spells, each one striking true against your assailants. The air fills with the sound of magical explosions as the battle rages on, and you fight with all your strength, refusing to back down in the face of adversity.\n\nBut despite your best efforts, you find yourself outnumbered and overwhelmed. Just when all seems lost, you spot a glimmer of hope on the horizon. Through the chaos of battle, you catch sight of a shimmering portal, its edges pulsing with a faint light.\n\nWith a burst of speed, you make a break for it, dodging spells and obstacles as you race towards freedom. The ground shakes beneath your feet as you run, and the air crackles with energy, but you push forward with single-minded determination.\n\nAs you reach the portal, you leap through with reckless abandon, feeling the rush of air as you hurtle through space and time. Moments later, you find yourself back in the familiar surroundings of the forest, your heart pounding in your chest.\n\nYou take a moment to catch your breath, grateful to have escaped the clutches of your captors. But as you look around, you realize that your adventure is far from over. With newfound determination, you set out once more, ready to face whatever challenges lie ahead.");
}

void MountainFight(){
printf("\n\nAs you ascend the steep, rocky path towards your next destination, you hear the unmistakable sounds of a fierce battle echoing through the valley. The roars of a dragon and the shouts of desperate heroes reach your ears. Your heart races as you realize the gravity of the situation. Determined to help, you divert your path and rush toward the source of the commotion. As you break through the treeline, the scene unfolds before you: a mighty dragon, its scales gleaming, and a group of brave heroes struggling to fend off its relentless attacks. Without hesitation, you join the fray, ready to make a difference.\n\nThe air around you crackles with tension as you and a group of brave heroes stand at the edge of a vast, ancient forest, staring up at the formidable silhouette of a dragon. Its scales glint menacingly in the dying light, and its eyes burn with an otherworldly fire. The ground trembles as it roars, a sound that echoes through the mountains and chills you to the bone.\n\nThe battle begins with a thunderous clash. The dragon swoops down with terrifying speed, its massive wings generating gusts of wind that nearly knock you off your feet. The heroes spring into action, wielding a combination of advanced technology and powerful magic to confront the beast. Arrows tipped with enchanted steel and bolts of pure energy streak through the air, aimed at the dragon's vulnerable spots.\n\nYou join the fray, casting protective shields and hurling powerful spells to support your comrades. The dragon responds with a torrent of flame, forcing you to conjure a barrier of shimmering energy to deflect the inferno. The heat is intense, and you can feel the strain of maintaining the shield, but you hold firm, knowing that the lives of your companions depend on you.\n\nThe heroes fight valiantly, their courage and determination shining brightly against the encroaching darkness. One warrior, clad in high-tech armor, leaps onto the dragon's back, driving a spear into its scales. The dragon thrashes wildly, trying to shake off its assailant, and the ground beneath you quakes with the force of its fury.\n\nAs the battle rages on, it becomes clear that the dragon is a formidable foe, its strength and resilience seemingly inexhaustible. Despite their best efforts, the heroes begin to falter, their attacks growing weaker as exhaustion takes its toll. The dragon senses their desperation and redoubles its efforts, unleashing a devastating blast of energy that sends several heroes sprawling to the ground.\n\nIn that moment, you feel a surge of resolve. With your heart pounding and your mind focused, you channel every ounce of your magical power into a single, decisive strike. You weave a complex spell, drawing upon the ancient magic of the forest and the advanced knowledge you've acquired. Your hands glow with a brilliant, blinding light as you complete the incantation.\n\nJust as the dragon prepares to deliver the final blow to the fallen heroes, you unleash your spell. A beam of pure, radiant energy shoots forth, striking the dragon squarely in the chest. The force of the impact staggers the beast, and it lets out a roar of pain and fury. Seizing the opportunity, the remaining heroes rally and press their attack, their weapons and spells finding their mark with renewed vigor.\n\nThe dragon, now weakened and struggling to stay aloft, turns its fiery gaze upon you. With a final, defiant roar, it lunges, determined to crush you beneath its massive claws. Time seems to slow as you brace yourself for the onslaught, your mind racing for a solution.\n\nAt the last possible moment, you tap into a hidden reserve of strength and conjure a colossal spear of pure magic. With a mighty throw, you hurl the spear towards the dragon's heart. The weapon pierces its scaled hide, sinking deep into its flesh. The dragon's roar of rage turns into a howl of agony as the magical energy courses through its body.\n\nWith a final, shuddering breath, the dragon collapses to the ground, its once fearsome form now lifeless and still. The battle is over. The heroes, battered and weary, look to you with expressions of gratitude and awe. You have landed the final blow, turning the tide when all hope seemed lost.\n\nAs the adrenaline fades, you find yourself surrounded by the grateful faces of your comrades. The victory is bittersweet, for you know that while the dragon is defeated, the journey to reach your true potential and find the fulfillment you seek is far from over. But for now, you savor the triumph and the knowledge that, in this moment, you have proven yourself a hero.");
}

void Techcity(){
printf("\n\nAs you encounter the travellers along your way. They are going to the techcity. You decide to join them. When you reach, you're introduced to a world beyond your wildest imagination. The city they guide you to is a marvel of futuristic design, with towering skyscrapers that seem to reach up to touch the heavens themselves. Each building is a masterpiece of architecture, gleaming with sleek lines and shimmering surfaces that catch the light in mesmerising patterns.\n\nAs you explore the city, you're amazed by the advanced technologies that surround you at every turn. Homes float effortlessly above the ground, held aloft by anti-gravity generators that defy the laws of physics. The interiors are spacious and luxurious, filled with state-of-the-art appliances and holographic displays that respond to your every command.\n\nThe people you meet are equally impressive, with minds as sharp as the cutting-edge technology they wield. They welcome you warmly, eager to share their knowledge and experiences with someone from a simpler world. You marvel at their ingenuity and creativity, inspired by the boundless possibilities that lie ahead.\n\nEntertainment in this advanced world is unlike anything you've ever experienced. Virtual reality simulations allow you to explore distant planets and galaxies, while holodecks create immersive environments where you can live out your wildest fantasies. Music and art are everywhere, with holographic displays that transform the city into a living canvas of color and sound.\n\nBut perhaps most impressive of all are the robots and AI that populate the city, seamlessly integrated into every aspect of daily life. From self-driving vehicles that whisk you away to your destination in comfort and style, to robotic assistants that anticipate your every need, automation has revolutionized the way people live and work.\n\nAs you spend days exploring the wonders of this advanced world, you're filled with awe at the possibilities that lie ahead. The future is bright, and with the guidance of your newfound friends, you know that you're ready to embrace it with open arms.");
}

void AcientRuinsMagic(){
printf("\n\nAs you continue your journey, you encounter various struggles and challenges along the way. Your path leads you through rugged terrain and treacherous obstacles, but you persevere, fueled by a determination to uncover the mysteries of this world.\n\nAmidst the dense foliage, you stumble upon ancient ruins, their weathered stones whispering tales of a bygone era. You explore the crumbling structures, marveling at the intricate carvings and faded murals that adorn the walls.\n\nBut your exploration is interrupted by the appearance of weird creatures, unlike anything you've ever seen. They skitter and scuttle through the shadows, their bizarre forms sending shivers down your spine. With quick thinking and a few well-placed spells, you manage to fend them off and continue on your way.\n\nAs you press deeper into the forest, you come across a clearing where you encounter a group of small, ethereal beings - forest fairies. They flit and dart through the air, their delicate wings shimmering in the sunlight. Intrigued by their presence, you follow them as they lead you deeper into the heart of the forest.\n\nThe fairies guide you to an ancient hidden village, nestled among the trees. The village is a quaint and charming sight, with quaint cottages and winding cobblestone streets. But despite its rustic appearance, there's an air of magic and mystery that hangs over the village like a veil.\n\nAs you explore the village, you learn of its connection to the modern world - a portal hidden deep within the forest that links the village to the bustling city beyond. Through the portal, the villagers have access to advanced technologies and modern conveniences, while still preserving the ancient traditions and practices of their ancestors.\n\nAs you arrive at the ancient hidden village, you're met with cautious stares from the villagers. They regard you with suspicion, wary of outsiders intruding upon their secluded way of life. But despite their initial skepticism, you sense a glimmer of curiosity in their eyes, a spark of interest in the stranger who has stumbled upon their village.\n\nDetermined to earn their trust, you set out to prove yourself to the villagers. You offer to help with various tasks around the village, from tending to the crops to repairing the thatched roofs of the cottages. With each passing day, you work tirelessly to show your commitment to the community and its well-being.\n\nOne day, when a sudden storm threatens to flood the village, you spring into action, rallying the villagers to reinforce the riverbanks and protect their homes. Together, you work tirelessly through the night, using your knowledge of magic to channel the elements and divert the floodwaters away from the village.\n\nImpressed by your bravery and resourcefulness, the villagers begin to warm to you, gradually accepting you as one of their own. They invite you to join in their traditions and celebrations, welcoming you into their homes with open arms.\n\nAs time passes, you become an integral part of the village, forging deep bonds with the villagers and earning their respect and admiration. You share stories around the hearth, laugh and sing with them during festivals, and lend a helping hand whenever needed.\n\nEventually, you come to be regarded as family by the villagers, your presence a source of comfort and strength in their lives. Together, you weather the challenges and triumphs of village life, united by a shared sense of community and belonging.\n\nAnd as you gaze out over the village and the forest beyond, you know that you have found a home among these kind-hearted people, and that your journey has led you to where you truly belong.You immerse yourself in the nuances of magic and the modern world, learning from the villagers and exploring the hidden wonders of the forest. With each passing day, you feel yourself growing stronger and more attuned to the ancient forces that shape this world. And as you gaze out over the village and the forest beyond, you know that your journey is far from over.");
}

void MountainHermit(){
  printf("\n\nAs you climb higher and higher, the air grows thin and crisp, and the landscape unfolds before you in a breathtaking panorama. Each step fills you with a sense of exhilaration and determination as you ascend towards the summit.\n\nAs you continue your ascent, you come across a solitary figure standing at the edge of a precipice - a hermit who seems to have been expecting your arrival. His weathered face bears the marks of a life lived in solitude, yet his eyes sparkle with a wisdom that belies his years.\n\nThe hermit greets you warmly, welcoming you to his humble abode nestled high among the peaks. He explains that he has been awaiting your arrival, knowing that you would come seeking guidance and wisdom.\n\nTo test your mettle, the hermit challenges you to a series of trials designed to push your limits and unlock your hidden potential. First, he tests your physical stamina, As the hermit leads you on a gruelling hike through rugged terrain and steep inclines, the physical strain begins to take its toll on your body. Each step feels like a monumental effort, and sweat beads on your brow as you push yourself to keep pace with the hermit's steady stride. The path ahead seems endless, winding its way up the side of the mountain with no respite in sight.\n\nDespite the exhaustion weighing heavily on your limbs, you draw upon your inner reserves of strength and determination, refusing to let fatigue hold you back. With each step, you dig deep within yourself, channelling your energy into propelling yourself forward and conquering the challenges that lie ahead.\n\nThe hermit watches with keen interest as you navigate the treacherous terrain, silently assessing your resolve and determination. He pushes you to your limits, urging you to dig deeper and find the strength to persevere in the face of adversity.\n\nAs you reach the summit, gasping for breath and drenched in sweat, a sense of accomplishment washes over you. You've proven your physical stamina, pushing yourself beyond your limits to reach the pinnacle of the mountain. The hermit nods in approval, a knowing smile playing at the corners of his lips as he acknowledges your feat.\n\nNext comes the test of your magical abilities, as the hermit presents you with tasks that require both skill and intuition. You summon your powers with focused concentration, tapping into the depths of your magical abilities to weave intricate spells and manipulate the elements to overcome each challenge with grace and precision.\n\nWith each task you complete, you feel a sense of satisfaction and empowerment, knowing that you possess the skills and knowledge to harness the forces of magic to achieve your goals. The hermit observes your progress with a discerning eye, offering guidance and encouragement as you navigate the complexities of the magical world.\n\nBut perhaps the most challenging test of all is the test of character, where the hermit observes your actions and choices in moments of adversity. He places you in situations where your integrity and compassion are put to the test, watching closely to see how you respond.\n\nThrough acts of kindness and selflessness, you demonstrate your unwavering commitment to doing what is right, even in the face of temptation or hardship. Your actions speak volumes about your true character, earning the hermit's respect and admiration as he sees the depth of your compassion and the strength of your moral fiber.\n\nAs the trials come to an end, you stand before the hermit with a newfound sense of purpose and determination. You've proven yourself worthy of his teachings, ready to embark on the next phase of your journey with confidence and conviction. And as you look back on the trials you've overcome, you know that you've unlocked your hidden potential and embraced the path of destiny that lies before you.\n\nAs the days pass, you find yourself drawn to the hermit's wisdom and guidance, seeking solace in his teachings and companionship. He becomes a father figure to you, imparting valuable lessons and offering unwavering support as you navigate the trials and tribulations of life.\n\nTogether, you share moments of quiet contemplation and profound insight, forging a bond that transcends words and spans the depths of the human spirit. And as you look out over the majestic peaks and valleys below, you know that you have found not only a mentor, but a lifelong friend who will walk beside you on your journey through life.");
}

void Ending1(){
printf("\n\nAs you delve deeper into the world of technology and entertainment, you find yourself consumed by a whirlwind of success and excess. Your innovations and creations earn you fame and fortune, while your charismatic persona draws admirers from all corners of society.\n\nAmidst the glitz and glamour, you find love in the arms of a kindred spirit, someone who understands and complements your ambitions and desires. You marry amidst grand celebrations, surrounded by friends and well-wishers who toast to your happiness and prosperity.\n\nBut despite outward appearances, a gnawing sense of emptiness begins to creep into your life. The pursuit of wealth and fame leaves you feeling hollow, yearning for something more meaningful and fulfilling.\n\nIn an attempt to fill the void, you indulge in reckless spending and high-stakes gambling, seeking thrills and excitement in the adrenaline-fueled world of risk and chance. As your debts mount and losses pile up, you find yourself spiraling out of control, grasping at fleeting moments of excitement to distract from the growing sense of despair within.\n\nAmidst the chaos, tragedy strikes when your beloved is senselessly killed before your eyes, a victim of the dark underbelly of the world you've become entangled in. Devastated and broken, you are unable to muster the strength or magic to save her, stripped of all that once defined you - your power, your wealth, and your love.\n\nWith nothing left to live for and consumed by grief and guilt, you spiral into a deep pit of despair. The weight of your failures and losses crushes your spirit, leaving you with no hope or reason to go on.\n\nIn a moment of profound despair, you make a fateful decision. Stripped of all magic, strength, and love, you take your own life, a tragic ending to a life once filled with promise and potential. As darkness envelops you, it's a grim reminder of the consequences of chasing fleeting pleasures and losing sight of what truly matters in life.");
}

void Ending2(){
printf("\n\nNow you have found both the tech city and the magical village,you know life on both sides of the coin. You know difficulties,people and how meaning and purpose differ from person to person and place to place.\n\nAs you roam the city streets, you marvel at the advancements and innovations that surround you. The holographic displays, self-driving vehicles, and AI-powered services remind you of the wonders of the modern world. Yet, amidst the marvels, a sense of longing tugs at your heart.\n\nDespite earning respect and making a name for yourself in the village and city alike, you can't shake the feeling that you haven't reached your true potential. Deep down, you yearn for a connection that goes beyond mere recognition and achievements.\n\nAs the years pass, you help everyone in need, using your skills and knowledge to aid those facing challenges. Your acts of heroism earn you a reputation as a guardian and protector, hailed by many as a beacon of hope and inspiration.\n\nYet, in the quiet moments of reflection, you still feel a void within you. The search for your true love remains elusive, and you wonder if you'll ever find the person who can understand and appreciate the depths of your soul.\n\nDespite the uncertainties and the feeling that you may never reach your true potential, you continue to strive for greatness, knowing that even if you never find what you seek, your journey has been one of growth, learning, and self-discovery. And as you look towards the horizon, you remain hopeful, knowing that every step forward brings you closer to unlocking the mysteries of your own heart and finding fulfillment in ways you never imagined possible.");
}

void Ending3(){
printf("\n\nAs you continue to go deeper into the darkness of revenge, fueled by the loss of the person you loved at the hands of power-hungry Hermits, you become consumed by a desire for retribution. You stop at nothing, trying everything at the expense of your own morality and sanity.\n\nDespite warnings against delving into dark magic, you embrace its corrupting influence, tapping into forbidden forces to augment your power and ruthlessness. The lines between right and wrong blur as you unleash devastating spells and curses upon your enemies, leaving a trail of destruction in your wake.\n\nWith each victory, your thirst for conquest grows stronger, and you set your sights on a grander goal - the domination of the entire world. You amass an army of loyal followers, using your dark magic to bend them to your will and crush any resistance that dares to oppose you.\n\nAs you sweep across continents and kingdoms, your reputation as a fearsome conqueror spreads far and wide. You subjugate nations and bend rulers to your whim, leaving no corner of the world untouched by your insatiable hunger for power.\n\nBut with each victory, a darkness creeps into your soul, gnawing at your conscience and leaving you haunted by the choices you've made. The cost of your conquests weighs heavily on your shoulders, but you push aside any doubts or remorse, driven by an insatiable thirst for control.\n\nIn the end, you stand as the undisputed conqueror of the world, your name whispered in fear and awe by all who know of your reign. But as you sit upon your throne of power, surrounded by the spoils of your conquests, you can't shake the feeling of emptiness that gnaws at your heart.\n\nFor all your might and dominion, you realize that true happiness and fulfillment elude you, forever lost in the pursuit of power and revenge. And as you look out over the world you've conquered, you wonder if it was all worth it, or if you've become nothing more than a puppet of the dark forces you once sought to control.");
}

void Ending4(){
printf("\n\nAs the hermit falls to the relentless onslaught of the power-hungry conqueror, you feel a deep sense of loss and despair. Despite your best efforts to fight back, you and your allies are crushed under the overwhelming might of the conqueror's forces. It seems that all hope is lost as the conqueror slowly tightens their grip on the world.\n\nBut just when you think all is lost, a ray of hope appears in the form of a beautiful warrior girl. She swoops in to rescue you from the clutches of defeat, her strength and determination shining brightly as she tends to your wounds and nurses you back to health. As you spend time together, you find yourself falling deeply in love with her, grateful for her courage and kindness.\n\nDespite the efforts of many brave souls to stop the conqueror, they are unable to match the conqueror's might and cunning. The world falls under the shadow of the conqueror's rule, and you realize that drastic measures must be taken to turn the tide of war.\n\nAs you recover from your injuries, you devote yourself to mastering every aspect of magic and gathering every possible resource to aid in your quest for justice. You rally those who still believe in freedom and righteousness, uniting them in a last-ditch effort to challenge the conqueror's reign.\n\nThe final battle is fierce and grueling, with armies clashing and magic lighting up the sky. You lead the charge against the conqueror, using every spell and strategy at your disposal to outwit and outmaneuver your formidable foe.\n\nIn the climactic showdown, you face the conqueror alone, their dark magic proving to be a formidable challenge. But with quick thinking and clever tactics, you manage to turn the tide of battle in your favor, tricking and overpowering the conqueror with a well-placed spell.\n\nWith the conqueror defeated and the world liberated from tyranny, you are hailed as a hero and a savior. The people you fought alongside and protected now look to you as their one true emperor, a beacon of hope and inspiration.\n\nYou marry the beautiful warrior girl, your love for each other blossoming amidst the ruins of war. Together, you build a magnificent palace in the air, a symbol of peace and prosperity for all. As you sit together on the balcony, sipping chai and watching the sunset, you reflect on the journey that brought you here.\n\nYou remember the people who believed in you and supported you, and you feel a deep sense of pride and accomplishment. You have reached your true potential, not as a conqueror of lands, but as a leader who inspires and uplifts those around you. And as you gaze into the eyes of your love, you know that you have found true happiness and fulfillment in a world that once seemed so dark and uncertain.");
}



int main(){
  printBold("Welcome to \"Voyager’s Fate\"\n");
    printf("Introduction\n");
    printf("Embark on \"Voyager’s Fate,\" an adventure which determines do you really have the luck the world so furiously wants.\nThe best ending is calculated to be approximately 0.00582% where you also win a total luck game with 100% probability and the getting the best win by 50% probability\n");
    printBold("About the Game\n");
    printf("In \"Voyager’s Fate,\" you are not just a player; you are the hero of an epic journey. Navigate through enchanted forests, climb treacherous mountains, and unravel the secrets of ancient ruins. Each decision you make carves a unique path, leading to one of many intriguing endings.Hope you find the best potential.\n");
    printBold("Your Journey\n");
    printf("As you delve into this immersive world, ponder the choices you make and the paths you take. How did your journey unfold? Reflect on the challenges and triumphs, and consider how you would have crafted this adventure. Share your thoughts and ideas for how you would have done this game to my email [aditya77551@gmail.com] , for every explorer's tale is a new story waiting to be told.\n");
   
printBold("Hello Dreamer!!\nLet's start Your Journey.");
char name[100];
char yes='n';                    //initialising char yes as n(denoting no).
while(yes!='y'){                //back or continue button.
  printf("What's your good name??\n");
  fgets(name,100,stdin);
  printf("Type 'y'to continue and 'n' to go back.\n"); 
  yes=yesno();
}

printf("\nLet's continue the exciting adventure.\nAnd let yourself be signed in the world history as '%s the stunning explorer'.\n",name);
printBold("Every character big and small has a backstory.And this is your own...\n");
backstory();

int wins;
printf("\n\nSuddenly a Ginie appears in front of you.\nHe seems so chivalrous and you are comepled to play a small game with him.\nIt is the infamous game of luck.");
wins=playRockPaperScissorsGame();

if(wins>3){
 
  mountainpath();
  int a=shareFood();

  if(a==2){
       MountainFight();
       int b=navigateMaze();

        if(b==2){
           MountainHermit();
           int c=playCelestialObservatory();
           if(c==2){
               Ending4();
               return 0;
            } 
            if(c==1){
                Ending3();
                return 0;

            } 
            else{
                return 0;
            }
        }
      if(b==1){
           Techcity();
           int d=theNegotiations();
           if(d==2){
               Ending2();
               return 0;
            } 
            if(d==1){
                Ending1();
                return 0;

            } 
            else{
                return 0;
            }

        }
        else{
            return 0;
        }

    }
    if(a==1){
        ShipFight();
       int e=rpgGame();

        if(e==2){
           AcientRuinsMagic();
           int f=playCelestialObservatory();
           if(f==2){
               Ending3();
               return 0;
            } 
            if(f==1){
                Ending2();
                return 0;

            } 
            else{
                return 0;
            }
        }
      if(e==1){
           Techcity();
           int g=playStealth();
           if(g==2){
               Ending2();
               return 0;
            } 
            if(g==1){
                Ending1();
                return 0;

            } 
            else{
                return 0;
            }

        }
        else{
            return 0;
        }

    }
  else{
    return 0;
  }
}
else if(wins<2){
  printBold("Looks like you were not quite lucky.\n Better luck in next life adventurer, it seems your dream to become the stunning explorer was a false and unattainable dream.");
  return 0;
}
else{
  forestpath();
  int h=guess();

  if(h==2){
       ShipFight();
       int i=rpgGame();

        if(i==2){
           AcientRuinsMagic();
           int j=playCelestialObservatory();
           if(j==2){
               Ending3();
               return 0;
            } 
            if(j==1){
                Ending2();
                return 0;

            } 
            else{
                return 0;
            }
        }
      if(i==1){
           Techcity();
           int k=playStealth();
           if(k==2){
               Ending2();
               return 0;
            } 
            if(k==1){
                Ending1();
                return 0;

            } 
            else{
                return 0;
            }

        }
        else{
            return 0;
        }

    }
    if(h==1){
        ForestFight();
       int l=whackRabbit();

        if(l==2){
           AcientRuinsMagic();
           int m=theNegotiations();
           if(m==2){
               Ending3();
               return 0;
            } 
            if(m==1){
                Ending2();
                return 0;

            } 
            else{
                return 0;
            }
        }
      if(l==1){
           Techcity();
           int n=playStealth();
           if(n==2){
               Ending2();
               return 0;
            } 
            if(n==1){
                Ending1();
                return 0;

            } 
            else{
                return 0;
            }

        }
        else{
            return 0;
        }

    }
  else{
    return 0;
  }
}

}
