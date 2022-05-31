#include <random>
#include <stdio.h>

std::random_device dev; // gerador de numeros aleatórios
std::mt19937 rng{dev()}; // seed de numeros aleatorios. Está fora da função rolar pq tava dando erro.

void roll(int dado, int quant) 
{
    int jogada_atual = 0;    // valor da rolagem atual
    int total = 0;          // valor do total de dados até o momento
    for (int i = 1; i <= quant; i++) 
    {        
        std::uniform_int_distribution<int> distr{1, dado}; // valor aleatório entre 1 e numero recebido 'dado'
        jogada_atual = distr(rng);  
        total += jogada_atual;
        printf("Dado #%d = %d \n", i, jogada_atual);
    }
    printf("Total: %d \n", total);
}

int main(int argc, char const *argv[])
{

    int dados = 0;
    int quants = 0;
    int escolher = 0;
    char quit = 's';
    int status = 0;
       
    while (status == 0)
    {
        system("CLS");

        printf("Escolha o dado a ser rolado:\n");
        printf("1 - d4\n");
        printf("2 - d6\n");
        printf("3 - d8\n");
        printf("4 - d10\n");
        printf("5 - d12\n");
        printf("6 - d20\n");

        printf(">>");
        scanf("%d", &escolher);

        switch (escolher)
        {
        case 1:
            dados = 4;
            break;
        case 2:
            dados = 6;
            break;
        case 3:
            dados = 8;
            break;
        case 4:
            dados = 10;
            break;
        case 5:
            dados = 12;
            break;
        case 6:
            dados = 20;
            break;
        }

        printf("Quantos dados rolar ? \n");
        printf(">>");
        scanf("%d", &quants);
        
        printf("......................\n");
        printf("...Rolando os dados...\n");
        printf("......................\n");
        
        roll(dados, quants);

        printf("Rolar novamente? (s/n) :\n");
        scanf("%s", &quit);
        if (quit == 'n') status = 1;
    }

    return 1;
}