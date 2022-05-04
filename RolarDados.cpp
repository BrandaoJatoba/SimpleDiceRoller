// RolarDados.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <random>

void rolar(int dado, int quant) 
{
    int jogada_atual= 0;
    int total = 0;
    for (int i = 1; i <= quant; i++) 
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, dado); // distribution in range [1, dado]
        jogada_atual = dist(rng);
        total += jogada_atual;
        std::cout << ">>";
        std::cout << i;
        std::cout << "o dado = ";
        std::cout << jogada_atual;
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "Total: ";
    std::cout << total;
    std::cout << "\n";
}

int main()
{

    int dados = 0;
    int quant = 0;
    int escolher = 0;
    char quit = 's';
    int status = 0;
    
    while (status == 0)
    {
        std::cout << "Escolha o dado a ser rolado:\n";
        std::cout << "1 - d4\n";
        std::cout << "2 - d6\n";
        std::cout << "3 - d8\n";
        std::cout << "4 - d10\n";
        std::cout << "5 - d12\n";
        std::cout << "6 - d20\n";

        std::cout << ">>";
        std::cin >> escolher;

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

        std::cout << "Quantos dados rolar ? \n";
        std::cout << ">>";
        std::cin >> quant;
        
        std::cout << "......................\n";
        std::cout << "...Rolando os dados...\n";
        std::cout << "......................\n";
        
        rolar(dados, quant);
        std::cout << "Rolar novamente? (s/n) :\n";
        std::cin >> quit;
        if (quit == 'n')
        {
            status = 1;
        }
        else
        {
            system("CLS");
        }
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
