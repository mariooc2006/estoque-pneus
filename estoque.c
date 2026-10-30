// Controle de Estoque de Pneus
// programa pra controlar o estoque de uma loja de pneus
// da pra cadastrar, ver o estoque, registrar compra e venda

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Pneu {
    char medida[20];  // tipo 175/70R13
    char marca[30];
    int quantidade;
    float preco;
};

struct Pneu estoque[MAX];
int total = 0;  // quantos pneus tem cadastrado

void cadastrar() {
    if (total == MAX) {
        printf("Estoque cheio\n");
        return;
    }
    printf("Medida (ex: 175/70R13): ");
    scanf("%19s", estoque[total].medida);
    printf("Marca: ");
    scanf("%29s", estoque[total].marca);
    printf("Quantidade: ");
    scanf("%d", &estoque[total].quantidade);
    printf("Preco: ");
    scanf("%f", &estoque[total].preco);
    total++;
    printf("Pneu cadastrado!\n");
}

void listar() {
    if (total == 0) {
        printf("Nenhum pneu cadastrado\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("%d - %s %s | %d unidades | R$ %.2f\n", i + 1, estoque[i].medida,
               estoque[i].marca, estoque[i].quantidade, estoque[i].preco);
    }
}

// mostra a lista e retorna a posicao do pneu escolhido
// se o numero for invalido retorna -1
int escolher() {
    int n;
    listar();
    printf("Numero do pneu: ");
    scanf("%d", &n);
    if (n < 1 || n > total) {
        printf("Numero invalido\n");
        return -1;
    }
    return n - 1;
}

void comprar() {
    int i = escolher();
    if (i == -1) return;
    int qtd;
    printf("Quantos chegaram: ");
    scanf("%d", &qtd);
    estoque[i].quantidade = estoque[i].quantidade + qtd;
    printf("Agora tem %d\n", estoque[i].quantidade);
}

void vender() {
    int i = escolher();
    if (i == -1) return;
    int qtd;
    printf("Quantos vendeu: ");
    scanf("%d", &qtd);
    // nao deixa vender mais do que tem
    if (qtd > estoque[i].quantidade) {
        printf("Nao tem tudo isso! So tem %d\n", estoque[i].quantidade);
        return;
    }
    estoque[i].quantidade = estoque[i].quantidade - qtd;
    printf("Venda feita, total R$ %.2f\n", qtd * estoque[i].preco);
}

void valorTotal() {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma = soma + estoque[i].quantidade * estoque[i].preco;
    }
    printf("Valor total do estoque: R$ %.2f\n", soma);
}

int main() {
    int opcao;
    do {
        printf("\n--- ESTOQUE DE PNEUS ---\n");
        printf("1 - Cadastrar pneu\n");
        printf("2 - Ver estoque\n");
        printf("3 - Registrar compra\n");
        printf("4 - Registrar venda\n");
        printf("5 - Valor total\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: comprar(); break;
            case 4: vender(); break;
            case 5: valorTotal(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
