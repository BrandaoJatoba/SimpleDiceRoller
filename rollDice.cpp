#include <random>
#include <stdio.h>

std::random_device dev; // gerador de numeros aleatórios
std::mt19937 rng{dev()}; // seed de numeros aleatorios. aparece fora da função rolar pq tava dando erro.

void roll( int quantity, int dice) 
{
    int current_roll = 0;    // valor da rolagem atual
    int total = 0;          // valor do total de dados até o momento
    for (int i = 1; i <= quantity; i++) 
    {        
        std::uniform_int_distribution<int> distr{1, dice}; // valor aleatório entre 1 e $'dado'
        current_roll = distr(rng);  
        total += current_roll;
        printf("Roll #%d = %d \n", i, current_roll);
    }
    printf("Rolls Sum: %d \n", total);
}

int main(int argc, char const *argv[])
{

    int dice = 0;
    int quantity = 0;
    int user_choice = 0;
    char quit = 'y';
    int status = 0;
       
    while (status == 0)
    {
        system("CLS");

        printf("Choose dice type:\n");
        printf("1 - d4\n");
        printf("2 - d6\n");
        printf("3 - d8\n");
        printf("4 - d10\n");
        printf("5 - d12\n");
        printf("6 - d20\n");

        printf(">>");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:
            dice = 4;
            break;
        case 2:
            dice = 6;
            break;
        case 3:
            dice = 8;
            break;
        case 4:
            dice = 10;
            break;
        case 5:
            dice = 12;
            break;
        case 6:
            dice = 20;
            break;
        }

        printf("How many rolls ? \n");
        printf(">>");
        scanf("%d", &quantity);
        
        printf("......................\n");
        printf("...  Casting dice  ...\n");
        printf("......................\n");
        
        roll(quantity, dice);

        printf("Roll again? (y/n) :\n");
        scanf("%s", &quit);
        if (quit == 'n') status = 1;
    }

    return 1;
}