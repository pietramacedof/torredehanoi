#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define CONST 30
#define CONF 60
#define INST 80
#define TAM 8

typedef struct p
{
    int v[TAM], topo
} Pilha;

typedef struct o{
    char nome[50];
    double seconds;
}Ordena;

int i, coluna, linha, opcao, discos=3;
double tempo;
FILE *file;

void gotoxy (int x, int y)
{
    COORD coord;
    coord.X= x;
    coord.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void linhaSuperior(int tam)
{
    printf("\033[35m");
    printf("%c", 201);
    for(i=0; i<tam; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);
    printf("\033[0m");
}

void rodape(int tam)
{
    printf("\033[35m");
    printf("%c", 200);
    for(i=0; i<tam; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 188);
    printf("\033[0m");
}

void item(int tam, char str[])
{
    int contaLetras = 0;
    printf("\033[35m");
    printf("%c", 186);
    printf("\033[0m");
    for(i=0; i<tam; i++)
    {
        if(str[i] == '\0')
        {
            break;
        }
        else
        {
            contaLetras++;
        }
    }
    printf("%s", str);
    while(contaLetras<tam)
    {
        printf("%c", 32);
        contaLetras++;
    }
    printf("\033[35m");
    printf("%c\n", 186);
    printf("\033[0m");
}

void push(Pilha *p,int x)
{
        p->topo++;
        p->v[p->topo]= x;
}

void pop(Pilha *p)
{
        p->topo--;
}

void imprimir(Pilha p)
{
    while(p.topo!=-1)
    {
        printf("      %i\n", p.v[p.topo]);
        pop(&p);
    }
}

void menu ()
{
    char escolha;
    system("cls");
    coluna = 70, linha = 11;
    gotoxy(coluna,linha);
    printf("\033[38;2;255;140;0m");
    printf("  __  __                     \n");
    linha++;
    gotoxy(coluna,linha);
    printf(" |  \\/  |  ___   _ _    _  _ \n");
    linha++;
    gotoxy(coluna,linha);
    printf(" | |\\/| | / -_) | ' \\  | || |\n");
    linha++;
    gotoxy(coluna,linha);
    printf(" |_|  |_| \\___| |_||_|  \\_,_|\n");
    printf("\033[0m");
    linha++;
    gotoxy(coluna,linha);
    linhaSuperior(CONST);
    linha++;
    gotoxy(coluna,linha);
    item(CONST, "1 - Jogar");
    linha++;
    gotoxy(coluna,linha);
    item(CONST, "2 - Configurar");
    linha++;
    gotoxy(coluna,linha);
    item(CONST, "3 - Como jogar");
    linha++;
    gotoxy(coluna,linha);
    item(CONST, "4 - Ranking");
    linha++;
    gotoxy(coluna,linha);
    item(CONST, "5 - Sair");
    linha++;
    gotoxy(coluna,linha);
    rodape(CONST);
    escolha = getch();
    if(escolha == 49)
    {
        play();
    }
    else if(escolha == 50)
    {
        configura();
    }
    else if(escolha == 51)
    {
        instruir();
    }
    else if(escolha == 52)
    {
        ranking();
    }
    else if(escolha == 53)
    {
        exit(0);
    }
    else {
        linha++;
        gotoxy(coluna,linha);
        printf("Escolha uma opcao valida!\n");
        sleep(2);
        menu();
    }
}

void play ()
{
    char nome [50];
    system("cls");
    Pilha a, b, c;
    char origem, destino;
    a.topo = -1;
    b.topo = -1;
    c.topo = -1;
    int i, aux, jogadas=0;
    i=discos;
    while(a.topo<discos-1)
    {
        push(&a, i);
        i--;
    }
    printf("Por favor, informe seu nome: ");
    gets(nome);
    clock_t start_time = clock();
    while(c.topo != discos-1)
    {
        system("cls");
        imprimir(a);
        printf("\033[38;2;255;140;0m======|======\033[0m\n");
        printf("\033[32m  ______ \n");
        printf(" /\\  __ \\\n");
        printf(" \\ \\  __ \\\n");
        printf("  \\ \\_\\ \\_\\\n");
        printf("   \\/_/\\/_/\033[0m\n\n\n\n\n");
        imprimir(b);
        printf("\033[38;2;255;140;0m======|======\033[0m\n");
        printf("\033[35m ______\n");
        printf("/\\  == \\\n");
        printf("\\ \\  __<\n");
        printf(" \\ \\_____\\ \n");
        printf("  \\/_____/  \033[0m\n\n\n");
        imprimir(c);
        printf("\033[38;2;255;140;0m======|======\033[0m\n");
        printf("\033[34m ______ \n");
        printf("/\\  ___\\\n");
        printf("\\ \\ \\____\n");
        printf(" \\ \\_____\\\n");
        printf("  \\/_____/\033[0m\n\n\n");
        fflush(stdin);
        printf("Quantidade de jogadas: %d\n\n\n", jogadas);
        printf("Origem: ");
        scanf(" %c", &origem);
        printf("Destino: ");
        scanf(" %c", &destino);
        if(origem == 'a' || origem == 'A')
        {
            if(a.topo == -1){
                printf("A pilha origem se encontra vazia");
            }
            else{
            aux = a.v[a.topo];
            if(destino == 'b' || destino == 'B')
            {
                if(b.v[b.topo]>a.v[a.topo] || b.topo == -1)
                {
                    push(&b, aux);
                    pop(&a);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else if (destino == 'c' || destino == 'C')
            {
                if(c.v[c.topo]>a.v[a.topo] || c.topo == -1)
                {
                    push(&c, aux);
                    pop(&a);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else
            {
                printf("Movimento inapropriado");
            }
        }
        }
        else if(origem == 'B' || origem == 'b')
        {
            if(b.topo == -1){
                printf("Pilha vazia.\n");
            }
            else{
            aux = b.v[b.topo];
            if(destino == 'a' || destino == 'A')
            {
                if(a.v[a.topo]>b.v[b.topo] || a.topo == -1)
                {
                    push(&a, aux);
                    pop(&b);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else if (destino == 'c' || destino == 'C')
            {
                if(c.v[c.topo]>b.v[b.topo] ||  c.topo == -1)
                {
                    push(&c, aux);
                    pop(&b);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else
            {
                printf("Movimento inapropriado");
            }
        }
        }
        else  if(origem == 'C' || origem == 'c')
        {
            if(c.topo == -1){
                printf("Pilha vazia");
            }
            else{
            aux = c.v[c.topo];
            if(destino == 'a' || destino == 'A')
            {
                if(a.v[a.topo]>c.v[c.topo] || a.topo == -1)
                {
                    push(&a, aux);
                    pop(&c);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else if (destino == 'b' || destino == 'B')
            {
                if(b.v[b.topo]>c.v[c.topo] || b.topo == -1)
                {
                    push(&b, aux);
                    pop(&c);
                    jogadas++;
                }
                else
                {
                    printf("Movimento inapropriado.\n");
                }
            }
            else
            {
                printf("Movimento inapropriado");
            }
        }
        }
        else
        {
            printf("Movimento inapropriado");
        }
        sleep(2);
        }
    if(c.topo == discos - 1)
    {
        system("cls");
        imprimir(c);
        printf("\033[38;2;255;140;0m======|======\033[0m\n");
        printf("\033[34m ______ \n");
        printf("/\\  ___\\\n");
        printf("\\ \\ \\____\n");
        printf(" \\ \\_____\\\n");
        printf("  \\/_____/\033[0m\n\n\n");
        printf("Demais, vc eh espertinho!\n");
        printf("Quantidade de jogadas: %d\n", jogadas);
    }
    clock_t end_time = clock();
    tempo = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    file = fopen("ranking.txt", "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
    }
    fprintf(file, "%s %.2lf\n", nome, tempo);
    fclose(file);
    printf("Seu tempo de execucao, %s: %.2lf segundos\n", nome, tempo);
    system("pause");
    menu();
}
void configura()
{
    coluna = 60, linha = 11;
    system("cls");
    gotoxy(coluna,linha);
    printf("\033[33m");
    printf("  ___                 __   _                                  \n");
    linha++;
    gotoxy(coluna,linha);
    printf(" / __|  ___   _ _    / _| (_)  __ _   _  _   _ _   __ _   _ _ \n");
    linha++;
    gotoxy(coluna,linha);
    printf("| (__  / _ \\ | ' \\  |  _| | | / _` | | || | | '_| / _` | | '_|\n");
    linha++;
    gotoxy(coluna,linha);
    printf(" \\___| \\___/ |_||_| |_|   |_| \\__, |  \\_,_| |_|   \\__,_| |_|  \n");
    linha++;
    gotoxy(coluna,linha);
    printf("                               |___/                           \n");
    printf("\033[0m");
    linha++;
    gotoxy(coluna,linha);
    linhaSuperior(CONF);
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "Informe com quantos pinos deseja jogar:");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "1 - Tres pinos - Padrao");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "2 - Quatro pinos");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "3 - Cinco pinos");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "4 - Seis pinos");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "5 - Sete pinos");
    linha++;
    gotoxy(coluna,linha);
    item(CONF, "6 - Oito pinos");
    linha++;
    gotoxy(coluna,linha);
    rodape(CONF);
    coluna++;
    linha++;
    gotoxy(coluna,linha);
    scanf("%d", &opcao);
    if(opcao==1)
    {
        discos = 3;
    }
    else if(opcao==2)
    {
        discos = 4;
    }
    else if(opcao==3)
    {
        discos = 5;
    }
    else if(opcao==4)
    {
        discos = 6;
    }
    else if(opcao==5)
    {
        discos = 7;
    }
    else if(opcao==6)
    {
        discos = 8;
    }
    linha++;
    gotoxy(coluna,linha);
    printf("Quantidade de discos alterada com sucesso!\n");
    linha++;
    gotoxy(coluna,linha);
    system("pause");
    linha++;
    gotoxy(coluna,linha);
    menu();
}

void instruir ()
{
    system("cls");
    linha= 10;
    coluna = 52;
    gotoxy(coluna,linha);
    printf("\t\033[034m      ___                            _                           \n");
    linha++;
    gotoxy(coluna,linha);
    printf("\t     / __|  ___   _ __    ___     _ | |  ___   __ _   __ _   _ _ \n");
    linha++;
    gotoxy(coluna,linha);
    printf("\t    | (__  / _ \\ | '  \\  / _ \\   | || | / _ \\ / _` | / _` | | '_|\n");
    linha++;
    gotoxy(coluna,linha);
    printf("\t     \\___| \\___/ |_|_|_| \\___/    \\__/  \\___/ \\__, | \\__,_| |_|  \n");
    linha++;
    gotoxy(coluna,linha);
    printf("\t                                              |___/              \033[0m\n");
    linha++;
    gotoxy(coluna,linha);
    linhaSuperior(INST);
    linha++;
    gotoxy(coluna,linha);
    item(INST, " O objetivo deste jogo consiste em deslocar todos os discos da haste onde se");
    linha++;
    gotoxy(coluna,linha);
    item(INST, "encontram para a haste C, respeitando as seguintes regras:");
    linha++;
    gotoxy(coluna,linha);
    item(INST, "1. deslocar um disco de cada vez, o qual devera ser o do topo de uma das tres");
    linha++;
    gotoxy(coluna,linha);
    item(INST, "hastes;");
    linha++;
    gotoxy(coluna,linha);
    item(INST, "2. cada disco nunca podera ser colocado sobre outro de diametro menor.");
    linha++;
    gotoxy(coluna,linha);
    rodape(INST);
    linha++;
    coluna++;
    gotoxy(coluna,linha);
    system("pause");
    linha++;
    gotoxy(coluna,linha);
    menu();
}

void ranking()
{
    char nome[50];
    int j, n, aux;
    char aux2[50];
    Ordena ranking[100];
    system("cls");
    printf("\x1b[38;5;205m ___                 _     _               \n");
    printf("| _ \\  __ _   _ _   | |__ (_)  _ _    __ _ \n");
    printf("|   / / _` | | ' \\  | / / | | | ' \\  / _` |\n");
    printf("|_|_\\ \\__,_| |_||_| |_\\_\\ |_| |_||_| \\__, |\n");
    printf("                                      |___/\n\x1b[0m");
    file = fopen("ranking.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }
    i=0;
    while (fscanf(file, "%s %lf\n", &nome, &tempo) != EOF)
    {
        strcpy(ranking[i].nome, nome);
        ranking[i].seconds = tempo;
        i++;
    }
    fclose(file);
    for(n=0; n<i; n++){
        for(j=n+1; j<i; j++){
            if(ranking[n].seconds > ranking[j].seconds){
                aux = ranking[n].seconds;
                ranking[n].seconds = ranking[j].seconds;
                ranking[j].seconds = aux;
                strcpy(aux2, ranking[n].nome);
                strcpy(ranking[n].nome, ranking[j].nome);
                strcpy(ranking[j].nome, aux2);
            }
        }
    }
    for(n=0; n<i; n++){
        printf("Nome: %s\n", ranking[n].nome);
        printf("Segundos: %.2lf\n", ranking[n].seconds);
        printf("\033[35m____________________________________________\033[0m\n");
    }
    system("pause");
    menu();
}

int main ()
{
    int i;
    system("MODE CON: COLS=190 LINES=140");
    char caule[] = "____________________________________________________________________________________________________________________________________________________________________________";
    printf("\033[31m");
    printf("\n\n\n%s", caule);
    printf("\033[0m");
    printf("\n\n\n\t\t\t\t\t\t\t\033[38;2;255;140;0m _________   ______       ______        ______        ______      \n");
    printf("\t\t\t\t\t\t\t/________/\\ /_____/\\     /_____/\\      /_____/\\      /_____/\\     \n");
    printf("\t\t\t\t\t\t\t\\__.::.__\\/ \\:::_ \\ \\    \\:::_ \\ \\     \\:::_ \\ \\     \\::::_\\/_    \n");
    printf("\t\t\t\t\t\t\t   \\::\\ \\    \\:\\ \\ \\ \\    \\:(_) ) )_    \\:(_) ) )_    \\:\\/___/\\   \n");
    printf("\t\t\t\t\t\t\t    \\::\\ \\    \\:\\ \\ \\ \\    \\: __ `\\ \\    \\: __ `\\ \\    \\::___\\/_  \n");
    printf("\t\t\t\t\t\t\t     \\::\\ \\    \\:\\_\\ \\ \\    \\ \\ `\\ \\ \\    \\ \\ `\\ \\ \\    \\:\\____/\\ \n");
    printf("\t\t\t\t\t\t\t      \\__\\/     \\_____\\/     \\_\\/ \\_\\/     \\_\\/ \\_\\/     \\_____\\/\033[0m \n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\033[33m ______       ______      \n");
    printf("\t\t\t\t\t\t\t\t\t\t/_____/\\     /_____/\\     \n");
    printf("\t\t\t\t\t\t\t\t\t\t\\:::_ \\ \\    \\::::_\\/_    \n");
    printf("\t\t\t\t\t\t\t\t\t\t \\:\\ \\ \\ \\    \\:\\/___/\\   \n");
    printf("\t\t\t\t\t\t\t\t\t\t  \\:\\ \\ \\ \\    \\::___\\/_  \n");
    printf("\t\t\t\t\t\t\t\t\t\t   \\:\\/.:| |    \\:\\____/\\ \n");
    printf("\t\t\t\t\t\t\t\t\t\t    \\____/_/     \\_____\\/ \033[0m\n");
    printf("\t\t\t\t\t\t\t\t\t\t                          \n\n\n");
    printf("\t\t\t\t\t\t\t\033[32m ___   ___      ________       ___   __       ______       ________     \n");
    printf("\t\t\t\t\t\t\t/__/\\ /__/\\    /_______/\\     /__/\\ /__/\\    /_____/\\     /_______/\\    \n");
    printf("\t\t\t\t\t\t\t\\::\\ \\\\  \\ \\   \\::: _  \\ \\    \\::\\_\\\\  \\ \\   \\:::_ \\ \\    \\__.::._\\/    \n");
    printf("\t\t\t\t\t\t\t \\::\\/_\\ .\\ \\   \\::(_)  \\ \\    \\:. `-\\  \\ \\   \\:\\ \\ \\ \\      \\::\\ \\     \n");
    printf("\t\t\t\t\t\t\t  \\:: ___::\\ \\   \\:: __  \\ \\    \\:. _    \\ \\   \\:\\ \\ \\ \\     _\\::\\ \\__  \n");
    printf("\t\t\t\t\t\t\t   \\: \\ \\\\::\\ \\   \\:.\\ \\  \\ \\    \\. \\`-\\  \\ \\   \\:\\_\\ \\ \\   /__\\::\\__/\\ \n");
    printf("\t\t\t\t\t\t\t    \\__\\/ \\::\\/    \\__\\/\\__\\/     \\__\\/ \\__\\/    \\_____\\/   \\________\\/ \033[0m\n\n\n\n");
    printf("\033[34m");
    for(i=0; i<=sizeof(caule); i++)
    {
        printf("%c", caule[i]);
        fflush (stdin);
        usleep(1000);
    }
    printf("\033[0m");
    menu();
}