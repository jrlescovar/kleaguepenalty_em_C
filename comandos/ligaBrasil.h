#ifndef LIGABRASIL_H
#define LIGABRASIL_H
#include "listaEncadeada.h"

#define NUM_TIMES 10
#define NUM_RODADAS 9 


// Estruturas

typedef struct Confronto {
    char timeCasa[20];
    int codigo1;
    int cor1;
    int placarCasa; 
    char timeFora[20];
    int codigo2;
    int cor2;
    int placarFora;
    struct Confronto* prox;
    struct Confronto* ant;
} Confronto;

typedef struct SemanaBrasil {
    int numeroRodada;
    Confronto* primeiroConfronto;
    struct SemanaBrasil* prox;
    struct SemanaBrasil* ant;
} SemanaBrasil;

typedef struct playOffsConfrontos {
    Confronto* primeiroConfronto;//ligabrasil
    Confronto* segundoConfronto;//liga brasil
    Confronto* terceiroConfronto;//liga brasil
    Confronto* playin1Confronto;
    Confronto* playin2Confronto;
    Confronto* playin3Confronto;
    Confronto* q1Confronto;
    Confronto* q2Confronto;
    Confronto* q3Confronto;
    Confronto* s1Confronto;
    Confronto* s2Confronto;
    Confronto* finalConfronto;
}playoffsConfrontos;
// Funções de criação
void MolduraBrasil(void){
	int i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 14 : 2); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "#" : "$");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "#" : "$");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,2,2,14,14);
}
void MolduraEspanha(void){
	int i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 14 : 4); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "$" : "@");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "$" : "@");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,4,4,14,14);
}
void MolduraItalia(void){
	int i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 4 : 10); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "=" : "*");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "=" : "*");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,15,15,10,4);
}
void MolduraAmericas(void){
	int	i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 8 : 9); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "<" : "?");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? ">" : "?");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,15,15,9,9);
}

Confronto* criarConfronto(char* casa, char* fora,int pais) {
	int cod1 , cod2;
    Confronto* novo = (Confronto*)malloc(sizeof(Confronto));
    if(pais == 1){
    	if(strcmp(casa,"Capim FC") == 0 ){
    	novo->cor1 = 11;
    	novo->codigo1 = 1;
		}		
	    if(strcmp(casa,"Dendele FC") == 0 ){
	    	novo->cor1 = 1;
	    	novo->codigo1 = 2;
		}
	    if(strcmp(casa,"DesimpedidosGoti") == 0 ){
	    	novo->cor1 = 2;
	    	novo->codigo1 = 3;
		}
	    if(strcmp(casa,"FC Real Elite") == 0 ){
	    	novo->cor1 = 13;
	    	novo->codigo1 = 4;
		}
	    if(strcmp(casa,"Fluxo FC") == 0 ){
	    	novo->cor1 = 4;
	    	novo->codigo1 = 5;
		}
	    if(strcmp(casa,"Funkbol Clube") == 0 ){
	    	novo->cor1 = 5;
	    	novo->codigo1 = 6;
		}
	    if(strcmp(casa,"Furia FC") == 0 ){
	    	novo->cor1 = 7;
	    	novo->codigo1 = 7;
		}
	    if(strcmp(casa,"G3X FC") == 0 ){
	    	novo->cor1 = 15;
	    	novo->codigo1 = 8;
		}
	    if(strcmp(casa,"LOUD SC") == 0 ){
	    	novo->cor1 = 2;
	    	novo->codigo1 = 9;
		}
	    if(strcmp(casa,"Nyvelados FC") == 0 ){
	    	novo->cor1 = 8;
	    	novo->codigo1 = 10;
		}
	    
	    
	    if(strcmp(fora,"Capim FC") == 0 ){
	    	novo->cor2 = 11;
	    	novo->codigo2 = 1 ;
		}
	    if(strcmp(fora,"Dendele FC") == 0 ){
	    	novo->cor2 = 1;
	    	novo->codigo2 = 2;
	    }
	    if(strcmp(fora,"DesimpedidosGoti") == 0 ){
	    	novo->cor2 = 2;
	    	novo->codigo2 = 3;
	    }
	    if(strcmp(fora,"FC Real Elite") == 0 ){
	    	novo->cor2 = 13;
	    	novo->codigo2 = 4;
	    }
	    if(strcmp(fora,"Fluxo FC") == 0 ){
	    	novo->cor2 = 4;
	    	novo->codigo2 = 5;
		}
	    if(strcmp(fora,"Funkbol Clube") == 0 ){
	    	novo->cor2 = 5;
	    	novo->codigo2 = 6;
		}
	    if(strcmp(fora,"Furia FC") == 0 ){
	    	novo->cor2 = 7;
	    	novo->codigo2 = 7;
		}
	    if(strcmp(fora,"G3X FC") == 0 ){
	    	novo->cor2 = 15;
	    	novo->codigo2 = 8;
		}
	    if(strcmp(fora,"LOUD SC") == 0 ){
	    	novo->cor2 = 2;
	    	novo->codigo2 = 9; 	
		}
	    if(strcmp(fora,"Nyvelados FC") == 0 ){
	    	novo->cor2 = 8;
	    	novo->codigo2 = 10;
		}
    }
    if(pais == 2){
    	if(strcmp(casa,"1K FC") == 0 ){
	    	novo->cor1 = 5;
	    	novo->codigo1 = 1;
		}		
	    if(strcmp(casa,"Aniquiladores FC") == 0 ){
	    	novo->cor1 = 4;
	    	novo->codigo1 = 2;
		}
	    if(strcmp(casa,"El Barrio") == 0 ){
	    	novo->cor1 = 11;
	    	novo->codigo1 = 3;
		}
	    if(strcmp(casa,"Jijantes FC") == 0 ){
	    	novo->cor1 = 1;
	    	novo->codigo1 = 4;
		}
	    if(strcmp(casa,"Kunisports") == 0 ){
	    	novo->cor1 = 8;
	    	novo->codigo1 = 5;
		}
	    if(strcmp(casa,"Los Troncos FC") == 0 ){
	    	novo->cor1 = 2;
	    	novo->codigo1 = 6;
		}
	    if(strcmp(casa,"PIO FC") == 0 ){
	    	novo->cor1 = 8;
	    	novo->codigo1 = 7;
		}
	    if(strcmp(casa,"Porcinos FC") == 0 ){
	    	novo->cor1 = 13;
	    	novo->codigo1 = 8;
		}
	    if(strcmp(casa,"Rayo Barcelona") == 0 ){
	    	novo->cor1 = 14;
	    	novo->codigo1 = 9;
		}
	    if(strcmp(casa,"Saiyans FC") == 0 ){
	    	novo->cor1 = 6;
	    	novo->codigo1 = 10;
		}
		if(strcmp(casa,"Ult. Mostoles") == 0 ){
	    	novo->cor1 = 8;
	    	novo->codigo1 = 11;
		}
		if(strcmp(casa,"xBuryer Team") == 0 ){
	    	novo->cor1 = 15;
	    	novo->codigo1 = 12;
		}
	    
	    
	    if(strcmp(fora,"1K FC") == 0 ){
	    	novo->cor2 = 5;
	    	novo->codigo2 = 1 ;
		}
	    if(strcmp(fora,"Aniquiladores FC") == 0 ){
	    	novo->cor2 = 4;
	    	novo->codigo2 = 2;
	    }
	    if(strcmp(fora,"El Barrio") == 0 ){
	    	novo->cor2 = 11;
	    	novo->codigo2 = 3;
		}
	    if(strcmp(fora,"Jijantes FC") == 0 ){
	    	novo->cor2 = 1;
	    	novo->codigo2 = 4;
		}
	    if(strcmp(fora,"Kunisports") == 0 ){
	    	novo->cor2 = 8;
	    	novo->codigo2 = 5;
		}
	    if(strcmp(fora,"Los Troncos FC") == 0 ){
	    	novo->cor2 = 2;
	    	novo->codigo2 = 6;
		}
	    if(strcmp(fora,"PIO FC") == 0 ){
	    	novo->cor2 = 8;
	    	novo->codigo2 = 7;
		}
	    if(strcmp(fora,"Porcinos FC") == 0 ){
	    	novo->cor2 = 13;
	    	novo->codigo2 = 8;
		}
	    if(strcmp(fora,"Rayo Barcelona") == 0 ){
	    	novo->cor2 = 14;
	    	novo->codigo2 = 9; 	
		}
	    if(strcmp(fora,"Saiyans FC") == 0 ){
	    	novo->cor2 = 6;
	    	novo->codigo2 = 10;
		}
		if(strcmp(fora,"Ult. Mostoles") == 0 ){
	    	novo->cor2 = 8;
	    	novo->codigo2 = 11;
		}
		if(strcmp(fora,"xBuryer Team") == 0 ){
	    	novo->cor2 = 15;
	    	novo->codigo2 = 12;
		}
    }
    if(pais == 3){
    	if(strcmp(casa,"Alpak FC") == 0 ){
	    	novo->cor1 = 13;
	    	novo->codigo1 = 1;
		}		
	    if(strcmp(casa,"Black Lotus FC") == 0 ){
	    	novo->cor1 = 1;
	    	novo->codigo1 = 2;
		}
	    if(strcmp(casa,"Boomers") == 0 ){
	    	novo->cor1 = 14;
	    	novo->codigo1 = 3;
		}
	    if(strcmp(casa,"Circus FC") == 0 ){
	    	novo->cor1 = 7;
	    	novo->codigo1 = 4;
		}
	    if(strcmp(casa,"FC Caesar") == 0 ){
	    	novo->cor1 = 4;
	    	novo->codigo1 = 5;
		}
	    if(strcmp(casa,"FC Zeta") == 0 ){
	    	novo->cor1 = 4;
	    	novo->codigo1 = 6;
		}
	    if(strcmp(casa,"Gear 7 FC") == 0 ){
	    	novo->cor1 = 1;
	    	novo->codigo1 = 7;
		}
	    if(strcmp(casa,"Punchers FC") == 0 ){
	    	novo->cor1 = 6;
	    	novo->codigo1 = 8;
		}
	    if(strcmp(casa,"Stalions") == 0 ){
	    	novo->cor1 = 9;
	    	novo->codigo1 = 9;
		}
	    if(strcmp(casa,"TRM FC") == 0 ){
	    	novo->cor1 = 14;
	    	novo->codigo1 = 10;
		}
		if(strcmp(casa,"Underdogs FC") == 0 ){
	    	novo->cor1 = 10;
	    	novo->codigo1 = 11;
		}
		if(strcmp(casa,"Zebras FC") == 0 ){
	    	novo->cor1 = 15;
	    	novo->codigo1 = 12;
		}
		
		if(strcmp(fora,"Alpak FC") == 0 ){
	    	novo->cor2 = 13;
	    	novo->codigo2 = 1;
		}		
	    if(strcmp(fora,"Black Lotus FC") == 0 ){
	    	novo->cor2 =1;
	    	novo->codigo2 = 2;
		}
	    if(strcmp(fora,"Boomers") == 0 ){
	    	novo->cor2 = 14;
	    	novo->codigo2 = 3;
		}
	    if(strcmp(fora,"Circus FC") == 0 ){
	    	novo->cor2 = 7;
	    	novo->codigo2 = 4;
		}
	    if(strcmp(fora,"FC Caesar") == 0 ){
	    	novo->cor2 = 4;
	    	novo->codigo2 = 5;
		}
	    if(strcmp(fora,"FC Zeta") == 0 ){
	    	novo->cor2 = 4;
	    	novo->codigo2 = 6;
		}
	    if(strcmp(fora,"Gear 7 FC") == 0 ){
	    	novo->cor2 = 1;
	    	novo->codigo2 = 7;
		}
	    if(strcmp(fora,"Punchers FC") == 0 ){
	    	novo->cor2 = 6;
	    	novo->codigo2 = 8;
		}
	    if(strcmp(fora,"Stalions") == 0 ){
	    	novo->cor2 = 9;
	    	novo->codigo2 = 9;
		}
	    if(strcmp(fora,"TRM FC") == 0 ){
	    	novo->cor2 = 14;
	    	novo->codigo2 = 10;
		}
		if(strcmp(fora,"Underdogs FC") == 0 ){
	    	novo->cor2 = 10;
	    	novo->codigo2 = 11;
		}
		if(strcmp(fora,"Zebras FC") == 0 ){
	    	novo->cor2 = 15;
	    	novo->codigo2 = 12;
		}
    }
    if(pais == 4){
    	if(strcmp(casa,"ATL. Parceros FC") == 0 ){
	    	novo->cor1 = 12;
	    	novo->codigo1 = 1;
		}		
	    if(strcmp(casa,"Clube Cuervos") == 0 ){
	    	novo->cor1 = 8;
	    	novo->codigo1 = 2;
		}
	    if(strcmp(casa,"Galatic Caribe") == 0 ){
	    	novo->cor1 = 1;
	    	novo->codigo1 = 3;
		}
	    if(strcmp(casa,"Los Aliens FC") == 0 ){
	    	novo->cor1 = 9;
	    	novo->codigo1 = 4;
		}
	    if(strcmp(casa,"Los Chamos FC") == 0 ){
	    	novo->cor1 = 6;
	    	novo->codigo1 = 5;
		}
	    if(strcmp(casa,"Muchachos FC") == 0 ){
	    	novo->cor1 = 9;
	    	novo->codigo1 = 6;
		}
	    if(strcmp(casa,"Olimpo United") == 0 ){
	    	novo->cor1 = 7;
	    	novo->codigo1 = 7;
		}
	    if(strcmp(casa,"Peluche Caligari") == 0 ){
	    	novo->cor1 = 14;
	    	novo->codigo1 = 8;
		}
	    if(strcmp(casa,"Persas FC") == 0 ){
	    	novo->cor1 = 15;
	    	novo->codigo1 = 9;
		}
	    if(strcmp(casa,"Raniza FC") == 0 ){
	    	novo->cor1 = 2;
	    	novo->codigo1 = 10;
		}
		if(strcmp(casa,"Real Titan FC") == 0 ){
	    	novo->cor1 = 13;
	    	novo->codigo1 = 11;
		}
		if(strcmp(casa,"West Santos FC") == 0 ){
	    	novo->cor1 = 15;
	    	novo->codigo1 = 12;
		}
		
		if(strcmp(fora,"ATL. Parceros FC") == 0 ){
	    	novo->cor2 = 12;
	    	novo->codigo2 = 1;
		}		
	    if(strcmp(fora,"Clube Cuervos") == 0 ){
	    	novo->cor2 = 8;
	    	novo->codigo2 = 2;
		}
	    if(strcmp(fora,"Galatic Caribe") == 0 ){
	    	novo->cor2 = 1;
	    	novo->codigo2 = 3;
		}
	    if(strcmp(fora,"Los Aliens FC") == 0 ){
	    	novo->cor2 = 9;
	    	novo->codigo2 = 4;
		}
	    if(strcmp(fora,"Los Chamos FC") == 0 ){
	    	novo->cor2 = 6;
	    	novo->codigo2 = 5;
		}
	    if(strcmp(fora,"Muchachos FC") == 0 ){
	    	novo->cor2 = 9;
	    	novo->codigo2 = 6;
		}
	    if(strcmp(fora,"Olimpo United") == 0 ){
	    	novo->cor2 = 7;
	    	novo->codigo2 = 7;
		}
	    if(strcmp(fora,"Peluche Caligari") == 0 ){
	    	novo->cor2 = 14;
	    	novo->codigo2 = 8;
		}
	    if(strcmp(fora,"Persas FC") == 0 ){
	    	novo->cor2 = 15;
	    	novo->codigo2 = 9;
		}
	    if(strcmp(fora,"Raniza FC") == 0 ){
	    	novo->cor2 = 2;
	    	novo->codigo2 = 10;
		}
		if(strcmp(fora,"Real Titan FC") == 0 ){
	    	novo->cor2 = 13;
	    	novo->codigo2 = 11;
		}
		if(strcmp(fora,"West Santos FC") == 0 ){
	    	novo->cor2 = 15;
	    	novo->codigo2 = 12;
		}
		
		
    }
    
    strcpy(novo->timeCasa, casa);
    novo->placarCasa = 0; // Espaço em branco nos dois caracteres
    strcpy(novo->timeFora, fora);
    novo->placarFora =  0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

SemanaBrasil* criarSemana(int numero) {
    SemanaBrasil* nova = (SemanaBrasil*)malloc(sizeof(SemanaBrasil));
    nova->numeroRodada = numero;
    nova->primeiroConfronto = NULL;
    nova->prox = NULL;
    nova->ant = NULL;
    return nova;
}

// Função para gerar todas as partidas (9 semanas)

SemanaBrasil* gerarPartidas() {
	 srand(time(NULL));
    char* allTimes1[NUM_TIMES] = {
        "Capim FC", "Dendele FC", "DesimpedidosGoti", "FC Real Elite", "Fluxo FC",
        "Funkbol Clube", "Furia FC", "G3X FC", "LOUD SC", "Nyvelados FC"
    };
    char* allTimes2[NUM_TIMES] = {
        "Dendele FC", "Nyvelados FC", "Fluxo FC", "LOUD SC", "Funkbol Clube",
        "FC Real Elite", "Furia FC", "DesimpedidosGoti", "Capim FC", "G3X FC"
    };
    char* allTimes3[NUM_TIMES] = {
        "Funkbol Clube", "FC Real Elite", "Furia FC", "Nyvelados FC", "LOUD SC",
        "Capim FC", "Dendele FC", "DesimpedidosGoti", "G3X FC", "Fluxo FC"
    };
    char* allTimes4[NUM_TIMES] = {
        "Nyvelados FC", "Funkbol Clube", "Dendele FC", "G3X FC", "FC Real Elite",
        "Fluxo FC", "LOUD SC", "Capim FC", "DesimpedidosGoti", "Furia FC"
    };
    char* allTimes5[NUM_TIMES] = {
        "Fluxo FC", "Capim FC", "Furia FC", "DesimpedidosGoti", "Funkbol Clube",
        "G3X FC", "Nyvelados FC", "FC Real Elite", "Dendele FC", "LOUD SC"
    };
    char* allTimes6[NUM_TIMES] = {
        "G3X FC", "LOUD SC", "Nyvelados FC", "Capim FC", "Dendele FC",
        "FC Real Elite", "Fluxo FC", "Furia FC", "DesimpedidosGoti", "Funkbol Clube"
    };
    char* allTimes7[NUM_TIMES] = {
        "FC Real Elite", "DesimpedidosGoti", "LOUD SC", "Furia FC", "Nyvelados FC",
        "Capim FC", "Fluxo FC", "Funkbol Clube", "Dendele FC", "G3X FC"
    };
    char* allTimes8[NUM_TIMES] = {
        "DesimpedidosGoti", "Fluxo FC", "G3X FC", "Nyvelados FC", "Furia FC",
        "LOUD SC", "Capim FC", "Funkbol Clube", "FC Real Elite", "Dendele FC"
    };
    char* allTimes9[NUM_TIMES] = {
        "LOUD SC", "Capim FC", "FC Real Elite", "DesimpedidosGoti", "Fluxo FC",
        "Nyvelados FC", "G3X FC", "Furia FC", "Funkbol Clube", "Dendele FC"
    };
    char* allTimes10[NUM_TIMES] = {
    "Furia FC", "DesimpedidosGoti", "Fluxo FC", "LOUD SC", "G3X FC",
    "Capim FC", "FC Real Elite", "Dendele FC", "Nyvelados FC", "Funkbol Clube"
	};

    // Lista de todas as tabelas
    char** allTimesList[10] = {allTimes1, allTimes2, allTimes3, allTimes4, allTimes5, allTimes6, allTimes7, allTimes8, allTimes9, allTimes10};


    int escolha = rand() % 10;
    char** allTimes = allTimesList[escolha];

    int tabela[NUM_TIMES];
    for (int i = 0; i < NUM_TIMES; i++) {
        tabela[i] = i;
    }

    SemanaBrasil* primeiraSemana = NULL;
    SemanaBrasil* semanaAtual = NULL;

    for (int rodada = 0; rodada < NUM_RODADAS; rodada++) {
        SemanaBrasil* novaSemana = criarSemana(rodada + 1);

        for (int i = 0; i < NUM_TIMES / 2; i++) {
            int casa = tabela[i];
            int fora = tabela[NUM_TIMES - 1 - i];

            Confronto* novoConfronto = criarConfronto(allTimes[casa], allTimes[fora],1);
            
            if (novaSemana->primeiroConfronto == NULL) {
                novaSemana->primeiroConfronto = novoConfronto;
            } else {
                Confronto* atual = novaSemana->primeiroConfronto;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoConfronto;
                novoConfronto->ant = atual;
            }
        }

        if (primeiraSemana == NULL) {
            primeiraSemana = novaSemana;
        } else {
            semanaAtual->prox = novaSemana;
            novaSemana->ant = semanaAtual;
        }
        semanaAtual = novaSemana;

        // Rotacionar os times
        int ultimo = tabela[NUM_TIMES - 1];
        for (int i = NUM_TIMES - 1; i > 1; i--) {
            tabela[i] = tabela[i - 1];
        }
        tabela[1] = ultimo;
    }

    return primeiraSemana;
}


SemanaBrasil* gerarPartidasEspanha() {
	 srand(time(NULL));
    char* allTimes1[12] = {
	    "1K FC", "Aniquiladores FC", "El Barrio", "Jijantes FC",
	    "Kunisports", "Los Troncos FC", "PIO FC", "Porcinos FC",
	    "Rayo Barcelona", "Saiyans FC", "Ult. Mostoles", "xBuryer Team"
	};
	
	char* allTimes2[12] = {
	    "Aniquiladores FC", "1K FC", "Jijantes FC", "El Barrio",
	    "Los Troncos FC", "Kunisports", "Porcinos FC", "PIO FC",
	    "Saiyans FC", "Rayo Barcelona", "xBuryer Team", "Ult. Mostoles"
	};
	
	char* allTimes3[12] = {
	    "El Barrio", "Jijantes FC", "1K FC", "Aniquiladores FC",
	    "PIO FC", "Porcinos FC", "Kunisports", "Los Troncos FC",
	    "Ult. Mostoles", "xBuryer Team", "Rayo Barcelona", "Saiyans FC"
	};
	
	char* allTimes4[12] = {
	    "Jijantes FC", "El Barrio", "Aniquiladores FC", "1K FC",
	    "Porcinos FC", "PIO FC", "Los Troncos FC", "Kunisports",
	    "xBuryer Team", "Ult. Mostoles", "Saiyans FC", "Rayo Barcelona"
	};
	
	char* allTimes5[12] = {
	    "Kunisports", "Los Troncos FC", "PIO FC", "Porcinos FC",
	    "1K FC", "Aniquiladores FC", "El Barrio", "Jijantes FC",
	    "xBuryer Team", "Ult. Mostoles", "Saiyans FC", "Rayo Barcelona"
	};
	
	char* allTimes6[12] = {
	    "Los Troncos FC", "Kunisports", "Porcinos FC", "PIO FC",
	    "Aniquiladores FC", "1K FC", "Jijantes FC", "El Barrio",
	    "Ult. Mostoles", "xBuryer Team", "Rayo Barcelona", "Saiyans FC"
	};
	
	char* allTimes7[12] = {
	    "PIO FC", "Porcinos FC", "Kunisports", "Los Troncos FC",
	    "El Barrio", "Jijantes FC", "1K FC", "Aniquiladores FC",
	    "Saiyans FC", "Rayo Barcelona", "xBuryer Team", "Ult. Mostoles"
	};
	
	char* allTimes8[12] = {
	    "Porcinos FC", "PIO FC", "Los Troncos FC", "Kunisports",
	    "Jijantes FC", "El Barrio", "Aniquiladores FC", "1K FC",
	    "Rayo Barcelona", "Saiyans FC", "Ult. Mostoles", "xBuryer Team"
	};
	
	char* allTimes9[12] = {
	    "Rayo Barcelona", "Saiyans FC", "Ult. Mostoles", "xBuryer Team",
	    "1K FC", "Aniquiladores FC", "El Barrio", "Jijantes FC",
	    "Kunisports", "Los Troncos FC", "PIO FC", "Porcinos FC"
	};
	
	char* allTimes10[12] = {
	    "Saiyans FC", "Rayo Barcelona", "xBuryer Team", "Ult. Mostoles",
	    "Aniquiladores FC", "1K FC", "Jijantes FC", "El Barrio",
	    "Los Troncos FC", "Kunisports", "Porcinos FC", "PIO FC"
	};
	
	char* allTimes11[12] = {
	    "Ult. Mostoles", "xBuryer Team", "Rayo Barcelona", "Saiyans FC",
	    "El Barrio", "Jijantes FC", "1K FC", "Aniquiladores FC",
	    "PIO FC", "Porcinos FC", "Kunisports", "Los Troncos FC"
	};
	
	char* allTimes12[12] = {
	    "xBuryer Team", "Ult. Mostoles", "Saiyans FC", "Rayo Barcelona",
	    "Jijantes FC", "El Barrio", "Aniquiladores FC", "1K FC",
	    "Porcinos FC", "PIO FC", "Los Troncos FC", "Kunisports"
	};

    // Lista de todas as tabelas
    char** allTimesList[12] = {allTimes1, allTimes2, allTimes3, allTimes4, allTimes5, allTimes6, allTimes7, allTimes8, allTimes9, allTimes10,allTimes11,allTimes12};


    int escolha = rand() % 12;
    char** allTimes = allTimesList[escolha];

    int tabela[12];
    for (int i = 0; i < 12; i++) {
        tabela[i] = i;
    }

    SemanaBrasil* primeiraSemana = NULL;
    SemanaBrasil* semanaAtual = NULL;

    for (int rodada = 0; rodada < 11; rodada++) {
        SemanaBrasil* novaSemana = criarSemana(rodada + 1);

        for (int i = 0; i < 12 / 2; i++) {
            int casa = tabela[i];
            int fora = tabela[12 - 1 - i];

            Confronto* novoConfronto = criarConfronto(allTimes[casa], allTimes[fora],2);
            
            if (novaSemana->primeiroConfronto == NULL) {
                novaSemana->primeiroConfronto = novoConfronto;
            } else {
                Confronto* atual = novaSemana->primeiroConfronto;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoConfronto;
                novoConfronto->ant = atual;
            }
        }

        if (primeiraSemana == NULL) {
            primeiraSemana = novaSemana;
        } else {
            semanaAtual->prox = novaSemana;
            novaSemana->ant = semanaAtual;
        }
        semanaAtual = novaSemana;

        // Rotacionar os times
        int ultimo = tabela[12 - 1];
        for (int i = 12 - 1; i > 1; i--) {
            tabela[i] = tabela[i - 1];
        }
        tabela[1] = ultimo;
    }

    return primeiraSemana;
}


// Função para buscar uma semana específica
SemanaBrasil* buscarSemana(SemanaBrasil* inicio, int numeroRodada) {
    SemanaBrasil* atual = inicio;
    while (atual != NULL) {
        if (atual->numeroRodada == numeroRodada) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // Não encontrou
}
void exibirSemana(SemanaBrasil* inicio, int numeroRodada) {
    SemanaBrasil* semana = buscarSemana(inicio, numeroRodada);

    /*if (semana == NULL) {
        printf("Rodada %d não encontrada.\n", numeroRodada);
        return;
    }*/

    gotoxy(87, 6); // Centralizado para título
    printf("RODADA %d", semana->numeroRodada);

    Confronto* confronto = semana->primeiroConfronto;
    
    int y = 8;
    while (confronto != NULL) {
		
		textcolor(confronto->cor1);
		if(strlen(confronto->timeCasa) > 13){
			gotoxy(71, y);
        	printf("%s",confronto->timeCasa);
		}else if(strlen(confronto->timeCasa) <= 14){
			gotoxy(74,y);
			printf("%s",confronto->timeCasa);
		}
		gotoxy(88,y);
		textcolor(15);
        printf("%d",confronto->placarCasa);
        gotoxy(90,y);
        printf("X");
        gotoxy(92,y);
        printf("%d",confronto->placarFora);
        textcolor(confronto->cor2);
        if(strlen(confronto->timeFora) > 14){
			gotoxy(94, y);
        	printf("%s",confronto->timeFora);
		}else{
			gotoxy(95,y);
			printf("%s",confronto->timeFora);
		}
        y += 2;
        confronto = confronto->prox;
    }
    textcolor(15);
}





char telaBrasil(void){
	clrscr();
	MolduraColorida(1, 1, 120, 30,2,2,14,14);
	gotoxy(95,2);
	printf("[??]: Overall Equipe");
	
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
	printCentralizado("KL PENALTY - BRASIL",3,14);
	gotoxy(42, 4);
	printf("SELECIONE A EQUIPE QUE DESEJA JOGAR");
	gotoxy(35, 28);
	printf("[APERTE] O NUMERO DA EQUIPE QUE DESEJA SELECIONAR");

	
	gotoxy(8,11);
    printf("[ APERTE  1 ]");
    gotoxy(10,8);
    textcolor(11);
    printf("CAPIM FC");
    gotoxy(20,7);
    printf("[84]");
	MolduraColorida(4, 6, 24, 10, 11, 2, 8, 8);
	
	gotoxy(31,11);
    printf("[ APERTE  2 ]");
    gotoxy(33,8);
    textcolor(1);
    printf("DENDELE FC");
    gotoxy(43,7);
    printf("[85]");
	MolduraColorida(27, 6, 47, 10, 1, 1, 14, 14);
	
	gotoxy(54,11);
    printf("[ APERTE  3 ]");
    gotoxy(52,8);
    textcolor(1);
    printf("DESIMPEDIDOS GOTI");
	gotoxy(66,7);
    printf("[82]");
	MolduraColorida(50, 6, 70, 10, 2, 2, 1, 1);
	
	gotoxy(77,11);
    printf("[ APERTE  4 ]");
    gotoxy(77,8);
    textcolor(9);
    printf("FC REAL ELITE");
    gotoxy(89,7);
    printf("[80]");
	MolduraColorida(73, 6, 93, 10, 13, 13, 9, 9);
	
	gotoxy(101,11);
    printf("[ APERTE 5 ]");
    gotoxy(103,8);
    textcolor(15);
    printf("FLUXO FC");
    gotoxy(113,7);
    printf("[82]");
	MolduraColorida(96, 6, 117, 10, 4, 8, 15, 15);
		
	gotoxy(8,19);
    printf("[ APERTE  6 ]");
    gotoxy(8,16);
    textcolor(5);
    printf("FUNKBOL CLUBE");
    gotoxy(20,15);
    printf("[83]");
	MolduraColorida(4, 14, 24, 18, 5, 5, 14, 14);	
	
	gotoxy(31,19);
    printf("[ APERTE  7 ]");
    gotoxy(33,16);
    textcolor(15);
    printf("FURIA FC");
    gotoxy(43,15);
    printf("[86]");
	MolduraColorida(27, 14, 47, 18, 15, 8, 15, 8);
	
	gotoxy(54,19);
    printf("[ APERTE  8 ]");
    gotoxy(57,16);
    textcolor(15);
    printf("G3X FC");
    gotoxy(66,15);
    printf("[87]");
	MolduraColorida(50, 14, 70, 18, 15, 15, 1, 14);
	
	gotoxy(77,19);
    printf("[ APERTE  9 ]");
    gotoxy(80,16);
    textcolor(2);
    printf("LOUD SC");
    gotoxy(89,15);
    printf("[82]");
	MolduraColorida(73, 14, 93, 18, 2, 2,10,10);
	
	gotoxy(101,19);
    printf("[ APERTE 0 ]");
    gotoxy(101,16);
    textcolor(15);
    printf("Nyvelados FC");
    gotoxy(113,15);
    printf("[83]");
	MolduraColorida(96, 14, 117, 18, 8, 8, 15,15);

	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}

char ligaBrasil(listaDupla *lista, listaDupla *lista2,int buscar,SemanaBrasil* campeonato,int rodada,int rodadaOficial){
	int jogador1, jogador2;
	clrscr();
	listaDupla *aux = buscarTimeNaLista(lista, buscar);
	int y,x,i;
	
	MolduraBrasil();
	
	Moldura(10, 5, 68, 18);
	
	gotoxy(12,4);
	printf("TABELA GERAL");
	textcolor(14);
	gotoxy(25,4);
	printf("KL - PENALTY BRASIL");
	textcolor(15);
	gotoxy(11,6);
	printf("POS");
	y = 6;
	while(y <= 17){
		gotoxy(14, y); 
    	printf("%c", 186);
    	gotoxy(35, y); 
    	printf("%c", 186);
    	gotoxy(41, y); 
    	printf("%c", 186);
		gotoxy(45, y);
    	printf("%c", 186);
    	gotoxy(49, y); 
    	printf("%c", 186);
    	gotoxy(53, y);
    	printf("%c", 186);
    	gotoxy(58, y); 
    	printf("%c", 186);
    	gotoxy(63,y);
    	printf("%c", 186);
    	y++;
	}
	
	
	gotoxy(22,6);
	printf("EQUIPE");
	
	gotoxy(37,6);
	printf("PTS");
	
	gotoxy(43,6);
	printf("V");
	
	gotoxy(47,6);
	printf("E");

	gotoxy(51,6);
	printf("D");

	gotoxy(55,6);
	printf("GF");
	
	gotoxy(60,6);
	printf("GS");
	
	gotoxy(65,6);
	printf("GA");
	
	x = 11;
	while(x < 68){
		gotoxy(x, 7);
		if (x != 14 || x != 35 || x != 41 || x != 45 || x != 49 || x != 53 || x != 58 || x != 63)
			printf("%c", 205);
		x++;
	}
	
	

	Moldura(69, 5, 111, 18);
	
	if(rodada == 1)
	{	
		gotoxy(84,4);
		printf("PROXIMOS JOGOS --> [M]");
		
	}else if(rodada == 9){
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS");
	}else{
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS --> [M]");
	}
	
	
	Moldura(10, 20, 27, 23);
	gotoxy(16,21);
	printf("ELENCO");
	gotoxy(24,22);
	printf("[E]");

	Moldura(30, 20, 48, 23);
	gotoxy(34,21);
	printf("ESTATISTICAS");
	gotoxy(37,22);
	printf("TOP 10  [W]");
	
	Moldura(51, 20, 69, 23);
	gotoxy(55,21);
	printf("? EM BREVE ?");
	
	Moldura(72, 20, 90, 23);
	gotoxy(76,21);
	printf("PLAY - OFFS");
	gotoxy(87,22);
	printf("[P]");

	
	MolduraColorida(93, 20, 111, 23,14,14,14,14);
	textcolor(14);
	gotoxy(99,21);
	printf("SIMULAR");
	gotoxy(99,22);
	printf(" AGORA   [S]");
	textcolor(15);
	
	
	
	Moldura(10, 24, 27, 27);
	gotoxy(14,25);
	printf("MARKETPLACE");
	gotoxy(24,26);
	printf("[T]");

	
	Moldura(30, 24, 48, 27);
	gotoxy(34,25);
	printf("ESTATISTICAS");
	gotoxy(36,26);
	printf("POR TIME [G]");

	
	Moldura(51, 24, 69, 27);/*
	gotoxy(57,25);
	printf("CARTAS");
	gotoxy(66,26);
	printf("[C]");*/
	gotoxy(55,25);
	printf("? EM BREVE ?");
	
	Moldura(72, 24, 90, 27);
	gotoxy(78,25);
	printf("OUTRAS");
	gotoxy(75,26);
	printf("KL - LIGAS");
	gotoxy(87,26);
	printf("[L]");
	
	MolduraColorida(93, 24, 111, 27,14,14,14,14);
	textcolor(14);
	gotoxy(97,25);
	printf("JOGAR AGORA");
	gotoxy(108,26);
	printf("[J]");
	textcolor(15);

	
	printCentralizado("APERTA [H] PARA ACESSAR MENU 'AJUDA' ",29,15);
	gotoxy(10,2);
	textcolor(aux->info.elenco.cor1);
	printf("%s  PRESIDENTE: %s",aux->info.elenco.nomeEquipe, aux->info.elenco.presida.nome);
	textcolor(15);
	gotoxy(69,2);
	if(aux->info.saldo < 1000){
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.0f", aux->info.elenco.valorMercado/1000, aux->info.saldo);
	}else if(aux->info.saldo <= 9999)
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	else if(aux->info.saldo > 9999 && aux->info.saldo < 99999)
	{
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	}else
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	
	if(rodadaOficial >= 10){
		exibirTabela(lista2,8);
		
	}else{
		exibirTabela(lista, 8);
	}
	exibirSemana(campeonato,rodada);
	
	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}


void gerenciarElenco(listaDupla **lista, tree *resultado,int localidade) {
    clrscr();
    fflush(stdin);
    textcolor(12);
    gotoxy(7,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
    int i = 0;
    
    if(localidade == 1){
    	MolduraBrasil();
    }
    if(localidade == 2){
	    MolduraEspanha();
    }
	 if(localidade == 3){
	   MolduraItalia();
    }
    if(localidade == 4){
	    MolduraAmericas();
    }
	if(localidade == 1){
	    if (resultado->time.codigo == 1) {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, 2, resultado->time.cor2, resultado->time.cor2);
	    } else if (resultado->time.codigo == 5) {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor2, 15, 15);
	    } else if (resultado->time.codigo == 7) {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor2, resultado->time.cor1, resultado->time.cor2, resultado->time.cor1);
	    } else if (resultado->time.codigo == 8) {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, 1, resultado->time.cor2);
	    } else {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
	    }
	}
	
	if(localidade == 2){
		 if (resultado->time.codigo == 7) {
	        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, 14, resultado->time.cor2, resultado->time.cor2);
		}else if (resultado->time.codigo == 11) {
	        MolduraColorida(6, 6, 82, 24, 14, 4, 8,8);
		}else if (resultado->time.codigo == 8) {
	        MolduraColorida(6, 6, 82, 24, 13, 13, 13,13);
		}else if (resultado->time.codigo == 10) {
	        MolduraColorida(6, 6, 82, 24, 14, resultado->time.cor2, resultado->time.cor1,resultado->time.cor1);
		}else
			MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
		
	}
	if(localidade == 3){
		MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
	}
	if(localidade == 4){
		MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
	}
    gotoxy(42, 5);
    printf("$: Valor de Mercado");
    gotoxy(65, 5);
    printf("[??]: Overall ");

    char tecla;
    int toggle = 0;
    listaDupla *temp = buscarTimeNaLista(*lista, resultado->time.codigo); // Usa temp, não muda *lista!
    listaDupla *aux;
	
	do{
		
		do{
	        if (toggle == 0)
	            textcolor(resultado->time.cor1);
	        else
	            textcolor(resultado->time.cor2);
	
	        gotoxy(9, 7);
	        printf("Time: %s  [%d]", resultado->time.nomeEquipe,((resultado->time.jogador1.overall + resultado->time.jogador2.overall) + (resultado->time.jogador3.overall + resultado->time.jogador4.overall) + (resultado->time.jogador5.overall + resultado->time.goleiro1.overall))/6); 
	
	        gotoxy(51, 7);
	        printf("Presidente: %s [%d]", resultado->time.presida.nome, resultado->time.presida.overall);
	
	        // Cor dos jogadores e goleiro (invertida da do time)
	        if (toggle == 0)
	            textcolor(resultado->time.cor2);
	        else
	            textcolor(resultado->time.cor1);
	
	        gotoxy(13, 10);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador1.posicao, resultado->time.jogador1.nome, resultado->time.jogador1.overall, resultado->time.jogador1.valor/1000);
	
	        gotoxy(41, 12);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador2.posicao, resultado->time.jogador2.nome, resultado->time.jogador2.overall, resultado->time.jogador2.valor/1000);
	
	        gotoxy(13, 14);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador3.posicao, resultado->time.jogador3.nome, resultado->time.jogador3.overall, resultado->time.jogador3.valor/1000);
	
	        gotoxy(41, 16);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador4.posicao, resultado->time.jogador4.nome, resultado->time.jogador4.overall, resultado->time.jogador4.valor/1000);
	
	        gotoxy(13, 18);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador5.posicao, resultado->time.jogador5.nome, resultado->time.jogador5.overall, resultado->time.jogador5.valor/1000);
	
	        gotoxy(41, 20);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.goleiro1.posicao, resultado->time.goleiro1.nome, resultado->time.goleiro1.overall, resultado->time.goleiro1.valor/1000);
	
	        gotoxy(71, 23);
	        printf("$: %.3f", temp->info.elenco.valorMercado / 1000.0);
			
			gotoxy(93,9);
			printf("ORDEM PENALIDADES");
			gotoxy(94,12);
			printf("                  ");
			gotoxy(94,12);
			printf("[1] %s",temp->info.elenco.jogador1.nome);
			gotoxy(94,14);
			printf("                  ");
			gotoxy(94,14);
			printf("[2] %s",temp->info.elenco.jogador2.nome);
			gotoxy(94,16);
			printf("                  ");
			gotoxy(94,16);
			printf("[3] %s",temp->info.elenco.jogador3.nome);
			gotoxy(94,18);
			printf("                  ");
			gotoxy(94,18);
			printf("[4] %s",temp->info.elenco.jogador4.nome);
			gotoxy(94,20);
			printf("                  ");
			gotoxy(94,20);
			printf("[5] %s",temp->info.elenco.jogador5.nome);
			
			printCentralizado("ALTERAR ORDEM DAS PENALIDADE APERTE [Y]",29,15);
			
	        gotoxy(119, 29);
	        toggle = !toggle;
	
	        int tempoEspera = 1500; // em milissegundos
	        int tempoPassado = 0;
	        int passo = 10; // 10ms de cada vez
	
	        while (tempoPassado < tempoEspera) {
	            if (kbhit()) break; // Se alguma tecla for pressionada, sai na hora
	            Sleep(passo);
	            tempoPassado += passo;
	        }
	        
	    
	    } while(!kbhit());
	
	    // Aqui a parte de ler a tecla corretamente
	    tecla = getch();
	    tecla = toupper(tecla);
	
	    textcolor(15); // volta cor padrão
	    
	    if(tecla == 'Y')
	    {
	    	
			printCentralizado("                                                                                            ",29,15);
			printCentralizado("DIGITE OS NUMEROS DOS JOGADORES QUE DESEJAM TROCAR NA ORDEM DA PENALIDADE",26,15);
			printCentralizado("JOGADOR 1:     TROCAR COM JOGADOR 2:    ",27,15);
	    	gotoxy(53,27);
	    	int pronto = 0; 
			char jogador1, jogador2;
	    	do{
	    		gotoxy(53,27);
	    		jogador1 = getche();
	    		if( jogador1 >=49 && jogador1 <= 53)
	    			pronto++;
	    		else{
	    			gotoxy(53,27);
	    			printf("   ");
	    			printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [4] [5]",29,15);
	    			gotoxy(119,29);
	    			Sleep(1000);
	    			gotoxy(30,29);
	    			printf("                                                    ");
	    		}
	    		
	    	}while(pronto != 1);
	    	gotoxy(53,27);
	    	printf("%c",jogador1);
	    	
	    	do{
	    		pronto = 0;
	    		gotoxy(79,27);
	    		jogador2 = getche();
	    		if( jogador2 >=49 && jogador2 <= 53 && jogador2 != jogador1)
	    			pronto++;
	    		else{
	    			gotoxy(79,27);
	    			printf("   ");
	    			if(jogador1 == 49)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [2] [3] [4] [5]",29,15);
	    			if(jogador1 == 50)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [3] [4] [5]",29,15);
	    			if(jogador1 == 51)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [4] [5]",29,15);
	    			if(jogador1 == 52)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [5]",29,15);
	    			if(jogador1 == 53)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [4]",29,15);
	    			gotoxy(119,29);
	    			Sleep(1000);
	    			gotoxy(30,29);
	    			printf("                                                    ");
	    		}
	    		
	    	}while(pronto != 1);
	    	
	    	gotoxy(79,27);
	    	printf("%c",jogador2);
	    	
	    	if(pronto == 1){
	    		int jg1 = jogador1 - '0';
				int jg2 = jogador2 - '0';
				jogador *jogadores[5] = {
				    &temp->info.elenco.jogador1,
				    &temp->info.elenco.jogador2,
				    &temp->info.elenco.jogador3,
				    &temp->info.elenco.jogador4,
				    &temp->info.elenco.jogador5
				};
				jogador aux = *jogadores[jg1 - 1];
				*jogadores[jg1 - 1] = *jogadores[jg2 - 1];
				*jogadores[jg2 - 1] = aux;		
	    	}
	    
	    }
	    gotoxy(20,26);
		printf("                                                                                  ");
		gotoxy(20,27);
		printf("                                                                 ");
		gotoxy(119,29);
		
	}while(tecla != 27);
    
}

void exibirConfronto4(Confronto* confronto,int linhaX,int linhaY) {
    textcolor(confronto->cor1);

    if (strlen(confronto->timeCasa) >=14) {
    	linhaX - 4;
        gotoxy(linhaX, linhaY);
        printf("%s", confronto->timeCasa); linhaX + 4;
    } else if(strlen(confronto->timeCasa) > 10 && strlen(confronto->timeCasa) < 14){
        gotoxy(linhaX+2, linhaY);
        printf("%s", confronto->timeCasa);
    }else{
    	gotoxy(linhaX+5, linhaY);
        printf("%s", confronto->timeCasa);
    }

    gotoxy(linhaX+17, linhaY); textcolor(15);
    printf("%d", confronto->placarCasa);

    gotoxy(linhaX+19, linhaY);
    printf("X");

    gotoxy(linhaX+21, linhaY);
    printf("%d", confronto->placarFora);

    textcolor(confronto->cor2);
    gotoxy(linhaX+25, linhaY);
    printf("%s", confronto->timeFora);

    textcolor(15);
}
void exibirPlayoffsBrasil(int rodadaOficial, listaDupla *listaBrasil, playoffsConfrontos *qbr, int num) {
    if (num == 1) {
        listaDupla *time1 = buscarTimeNaListaPOSI(listaBrasil, 1);

        MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
        textcolor(14);

        gotoxy(19, 5); textcolor(15); textcolor(14);printf("QUARTAS DE FINAIS");textcolor(15);
        gotoxy(6, 8); printf("Q1");
        gotoxy(6, 11); printf("Q2");
        gotoxy(6, 14); printf("Q3");

        exibirConfronto4(qbr->q1Confronto, 9, 8);
        exibirConfronto4(qbr->q2Confronto, 9, 11);
        exibirConfronto4(qbr->q3Confronto, 9, 14);
        gotoxy(26,8);
        printf(" ");
        gotoxy(30,8);
        printf(" ");
        gotoxy(26,11);
        printf(" ");
        gotoxy(30,11);
        printf(" ");
        gotoxy(26,14);
        printf(" ");
        gotoxy(30,14);
        printf(" ");
		textcolor(14);
        gotoxy(68, 7); printf("SEMI FINAIS");textcolor(15);



        int nomeLen = strlen(time1->info.elenco.nomeEquipe);
        if (nomeLen > 14) 
		    gotoxy(55, 10); 
		else if (nomeLen > 10) 
		    gotoxy(57, 10);
		else 
		    gotoxy(62, 10); 
		
		textcolor(time1->info.elenco.cor1);
		printf("%s", time1->info.elenco.nomeEquipe);
		
		textcolor(15);
		gotoxy(73, 10); printf("X");            
		gotoxy(77, 10); printf("VENCEDOR Q1");   
		gotoxy(60, 13); printf("VENCEDOR Q2");   
		gotoxy(73, 13); printf("X");           
		gotoxy(77, 13); printf("VENCEDOR Q3");  
		
		textcolor(14);
		gotoxy(87, 18); printf("FINAL KL - BRASIL"); 
		textcolor(15);
		gotoxy(83, 20); printf("VENC. SEMI1  X  VENC.SEMI2"); 

    }
	if (num == 2) {

        MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
        textcolor(14);

        gotoxy(19, 5); textcolor(15); textcolor(14);printf("QUARTAS DE FINAIS");textcolor(15);
        gotoxy(6, 8); printf("Q1");
        gotoxy(6, 11); printf("Q2");
        gotoxy(6, 14); printf("Q3");

        exibirConfronto4(qbr->q1Confronto, 9, 8);
        exibirConfronto4(qbr->q2Confronto, 9, 11);
        exibirConfronto4(qbr->q3Confronto, 9, 14);
		textcolor(14);
        gotoxy(69, 7); printf("SEMI FINAIS");
		textcolor(15);
		exibirConfronto4(qbr->s1Confronto, 55, 10);
        exibirConfronto4(qbr->s2Confronto, 55, 13);
        gotoxy(72,13);
        printf(" ");
        gotoxy(76,13);
        printf(" ");
        gotoxy(72,10);
        printf(" ");
        gotoxy(76,10);
        printf(" ");
       
        textcolor(14);
        gotoxy(87, 18); printf("FINAL KL - BRASIL");textcolor(15);
        gotoxy(83, 20); printf("VENC. SEMI1  X  VENC.SEMI2");

    }
    if(num == 3){
    	MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
        textcolor(14);

        gotoxy(19, 5); textcolor(15); textcolor(14);printf("QUARTAS DE FINAIS");textcolor(15);
        gotoxy(6, 8); printf("Q1");
        gotoxy(6, 11); printf("Q2");
        gotoxy(6, 14); printf("Q3");

        exibirConfronto4(qbr->q1Confronto, 9, 8);
        exibirConfronto4(qbr->q2Confronto, 9, 11);
        exibirConfronto4(qbr->q3Confronto, 9, 14);
		textcolor(14);
        gotoxy(69, 7); printf("SEMI FINAIS");
		textcolor(15);
		exibirConfronto4(qbr->s1Confronto, 55, 10);
        exibirConfronto4(qbr->s2Confronto, 55, 13);
        
        textcolor(14);
		gotoxy(86, 16); printf("FINAL KL - BRASIL"); 
		if (qbr->finalConfronto) {
		    exibirConfronto4(qbr->finalConfronto, 75, 18);
		} else {
		    gotoxy(70, 18);
		    printf("FINAL NAO CRIADA");
		}
		gotoxy(92,18);printf(" ");
	    gotoxy(96,18);printf(" ");
		
		textcolor(15);
		 
		
    }
    if(num == 4){
			MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
        	textcolor(14);
	
	        gotoxy(19, 5); textcolor(15); textcolor(14);printf("QUARTAS DE FINAIS");textcolor(15);
	        gotoxy(6, 8); printf("Q1");
	        gotoxy(6, 11); printf("Q2");
	        gotoxy(6, 14); printf("Q3");
	
	        exibirConfronto4(qbr->q1Confronto, 9, 8);
	        exibirConfronto4(qbr->q2Confronto, 9, 11);
	        exibirConfronto4(qbr->q3Confronto, 9, 14);
			textcolor(14);
	        gotoxy(69, 7); printf("SEMI FINAIS");
			textcolor(15);
			exibirConfronto4(qbr->s1Confronto, 55, 10);
	        exibirConfronto4(qbr->s2Confronto, 55, 13);
	        exibirConfronto4(qbr->finalConfronto, 75, 18);
	        textcolor(14);
	        gotoxy(86, 16); printf("FINAL KL - BRASIL");
	        textcolor(15);	
	}
    printCentralizado("PRESSIONE QUALQUER TECLA PARA CONTINUAR", 29, 15);
    gotoxy(119, 29);
    getch();
}





void criarPlayoffBrasil(playoffsConfrontos **qbr, listaDupla *listaEspanha, int play) {
    if (*qbr == NULL) {
        *qbr = malloc(sizeof(playoffsConfrontos));
        if (!(*qbr)) {
            printf("Erro: Falha ao alocar memória para playoffsConfrontos.\n");
            return;  // único return justificado aqui (memória não alocada)
        }
        memset(*qbr, 0, sizeof(playoffsConfrontos));
    }

    // PLAY 1 - criar play-ins e confrontos iniciais
    if (play == 1) {
        listaDupla *time2 = buscarTimeNaListaPOSI(listaEspanha, 2);
        listaDupla *time3 = buscarTimeNaListaPOSI(listaEspanha, 3);
        listaDupla *time4 = buscarTimeNaListaPOSI(listaEspanha, 4);
        listaDupla *time5 = buscarTimeNaListaPOSI(listaEspanha, 5);
        listaDupla *time6 = buscarTimeNaListaPOSI(listaEspanha, 6);
        listaDupla *time7 = buscarTimeNaListaPOSI(listaEspanha, 7);


        if (time4 && time5)
            (*qbr)->q1Confronto = criarConfronto(time4->info.elenco.nomeEquipe, time5->info.elenco.nomeEquipe, 1);
        else
            printf("Erro ao criar playin1Confronto.\n");

        if (time3 && time6)
            (*qbr)->q2Confronto = criarConfronto(time3->info.elenco.nomeEquipe, time6->info.elenco.nomeEquipe, 1);
        else
            printf("Erro ao criar playin2Confronto.\n");

        if (time2 && time7)
            (*qbr)->q3Confronto = criarConfronto(time2->info.elenco.nomeEquipe, time7->info.elenco.nomeEquipe, 1);
        else
            printf("Erro ao criar q1Confronto.\n");
    }

    // PLAY 2 - criar play-in final
    if (play == 2) {
        if (!(*qbr)->q1Confronto || !(*qbr)->q2Confronto) {
            printf("Erro: playins 1 ou 2 não definidos.\n");
        } else {
            listaDupla *vencedorQ1 = NULL;
            listaDupla *vencedorQ2 = NULL;
            listaDupla *vencedorQ3 = NULL;
			listaDupla *time1 = buscarTimeNaListaPOSI(listaEspanha, 1);
            for (int i = 1; i <= 10; i++) {
                listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
                if (!t) continue;

                if (!vencedorQ1) {
                    if (((*qbr)->q1Confronto->placarCasa > (*qbr)->q1Confronto->placarFora &&
                         (*qbr)->q1Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q1Confronto->placarFora > (*qbr)->q1Confronto->placarCasa &&
                         (*qbr)->q1Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ1 = t;
                    }
                }

                if (!vencedorQ2) {
                    if (((*qbr)->q2Confronto->placarCasa > (*qbr)->q2Confronto->placarFora &&
                         (*qbr)->q2Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q2Confronto->placarFora > (*qbr)->q2Confronto->placarCasa &&
                         (*qbr)->q2Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ2 = t;
                    }
                }
                
                if (!vencedorQ3) {
                    if (((*qbr)->q3Confronto->placarCasa > (*qbr)->q3Confronto->placarFora &&
                         (*qbr)->q3Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q3Confronto->placarFora > (*qbr)->q3Confronto->placarCasa &&
                         (*qbr)->q3Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ3 = t;
                    }
                }

                if (vencedorQ1 && vencedorQ2 && vencedorQ3) break;
            }

            if (vencedorQ1 && vencedorQ2 && vencedorQ3){
                (*qbr)->s1Confronto = criarConfronto(time1->info.elenco.nomeEquipe, vencedorQ1->info.elenco.nomeEquipe, 1);
                (*qbr)->s2Confronto = criarConfronto(vencedorQ2->info.elenco.nomeEquipe, vencedorQ3->info.elenco.nomeEquipe, 1);
        	}
            else
                printf("Erro: Não foi possível determinar os vencedores dos play-ins.\n");
        }
    }

    // PLAY 3 - criar confronto q3 com time2 vs vencedor do play-in final
    if (play == 3) {
    	if (!(*qbr)->s1Confronto || !(*qbr)->s2Confronto) {
    		printf("Erro: semifinais não foram definidas.\n");
		} else {
		    listaDupla *vencedorQ1 = NULL;
		    listaDupla *vencedorQ2 = NULL;
		
		    for (int i = 1; i <= 10; i++) {
		        listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
		        if (!t) continue;
		
		        if (!vencedorQ1) {
		            if (((*qbr)->s1Confronto->placarCasa > (*qbr)->s1Confronto->placarFora &&
		                 (*qbr)->s1Confronto->codigo1 == t->info.elenco.codigo) ||
		                ((*qbr)->s1Confronto->placarFora > (*qbr)->s1Confronto->placarCasa &&
		                 (*qbr)->s1Confronto->codigo2 == t->info.elenco.codigo)) {
		                vencedorQ1 = t;
		            }
		        }
		
		        if (!vencedorQ2) {
		            if (((*qbr)->s2Confronto->placarCasa > (*qbr)->s2Confronto->placarFora &&
		                 (*qbr)->s2Confronto->codigo1 == t->info.elenco.codigo) ||
		                ((*qbr)->s2Confronto->placarFora > (*qbr)->s2Confronto->placarCasa &&
		                 (*qbr)->s2Confronto->codigo2 == t->info.elenco.codigo)) {
		                vencedorQ2 = t;
		            }
		        }
		
		        if (vencedorQ1 && vencedorQ2) break;
		    }
		
		    if (vencedorQ1 && vencedorQ2)
		        (*qbr)->finalConfronto = criarConfronto(vencedorQ1->info.elenco.nomeEquipe, vencedorQ2->info.elenco.nomeEquipe, 1);
		    else
		        printf("Erro ao determinar finalistas.\n");
		}

	}
    
}

int exibeLigaBrasil(listaDupla *lista, listaDupla *lista2,SemanaBrasil* campeonato,int rodada,int rodadaOficial,int outrasliga,playoffsConfrontos *jogo,int liga){
	clrscr(); char passarPagina1;
	int y,x,i;
	char op;
	if(rodadaOficial >= 10)
		rodada = 9;
	do{	
		MolduraBrasil();
		
		Moldura(10, 5, 68, 18);
		
		gotoxy(12,4);
		printf("TABELA GERAL");
		textcolor(14);
		gotoxy(25,4);
		printf("KL - PENALTY BRASIL");
		textcolor(15);
		gotoxy(11,6);
		printf("POS");
		y = 6;
		while(y <= 17){
			gotoxy(14, y); 
	    	printf("%c", 186);
	    	gotoxy(35, y); 
	    	printf("%c", 186);
	    	gotoxy(41, y); 
	    	printf("%c", 186);
			gotoxy(45, y);
	    	printf("%c", 186);
	    	gotoxy(49, y); 
	    	printf("%c", 186);
	    	gotoxy(53, y);
	    	printf("%c", 186);
	    	gotoxy(58, y); 
	    	printf("%c", 186);
	    	gotoxy(63,y);
	    	printf("%c", 186);
	    	y++;
		}
		
		
		gotoxy(22,6);
		printf("EQUIPE");
		
		gotoxy(37,6);
		printf("PTS");
		
		gotoxy(43,6);
		printf("V");
		
		gotoxy(47,6);
		printf("E");
	
		gotoxy(51,6);
		printf("D");
	
		gotoxy(55,6);
		printf("GF");
		
		gotoxy(60,6);
		printf("GS");
		
		gotoxy(65,6);
		printf("GA");
		
		x = 11;
		while(x < 68){
			gotoxy(x, 7);
			if (x != 14 || x != 35 || x != 41 || x != 45 || x != 49 || x != 53 || x != 58 || x != 63)
				printf("%c", 205);
			x++;
		}
		
		
	
		Moldura(69, 5, 111, 18);
		if(rodada == 1)
		{	
			gotoxy(84,4);
			printf("PROXIMOS JOGOS --> [M]");
			
		}else if(rodada == 9){
			gotoxy(76,4);
			printf("[N] <-- PROXIMOS JOGOS");
		}else{
			gotoxy(76,4);
			printf("[N] <-- PROXIMOS JOGOS --> [M]");
		}
		printCentralizado("APERTE [ESC] PARA SAIR DO MENU OUTRAS LIGAS",2,12);
	
		Moldura(30, 21, 48, 24);
		gotoxy(34,22);
		printf("ESTATISTICAS");
		gotoxy(36,23);
		printf("POR TIME [G]");

	
		Moldura(51, 21, 69, 24);
		gotoxy(55,22);
		printf("ESTATISTICAS");
		gotoxy(65,23);
		printf("[W]");
		
		Moldura(72, 21, 90, 24);
		gotoxy(76,22);
		printf("PLAY - OFFS");
		gotoxy(87,23);
		printf("[P]");
		
		if(outrasliga == 1){
			printCentralizado("        PROXIMA LIGA --> [D]",26,15);
		}
		if(outrasliga == 3){
			printCentralizado("[A] <-- PROXIMA LIGA        ",26,15);
		}
		if(outrasliga == 2)
			printCentralizado("[A] <-- PROXIMA LIGA --> [D]",26,15);
		
		if(liga == 1){
			if(rodadaOficial >= 10){
				exibirTabela(lista2,8);
			}else{
				exibirTabela(lista, 8);
			}	
		}
		else{
			if(rodadaOficial >= 12){
				exibirTabela(lista2,8);
			}else{
				exibirTabela(lista, 8);
			}
		}
		exibirSemana(campeonato,rodada);
		
		gotoxy(119,29);
		fflush(stdin);
		op = toupper(getch());
		limparBufferTeclado();
		switch(op){
			case 'W':
				passarPagina1 = 'A';
    			do{
    				if(passarPagina1 == 'A'){
    					passarPagina1 = exibirEstatisticas(lista,1);
    				}
    				if(passarPagina1 == 'G')
    				{
    					passarPagina1 = exibirTopGoleiros(lista,1);
    				}
    				if(passarPagina1 == 'P'){
    					passarPagina1 = exibirTopPresidentes(lista,1);
    				}
    			}while(passarPagina1 != 27);
			break;
			case 'N':
    			if(rodada != 1){
    				rodada--;
    			}
    		break;
    		case 'M':
    			if(rodada < 10){
    				rodada++;
    			}
    		break;	
			case 'D':
				if(outrasliga<3){
					op = 27;
					return outrasliga+1;
				} 
			break;
			case 'A':
				if(outrasliga>1)
				{
					op = 27;
					return outrasliga-1;
				}
			break;
			case 'P':
				if(rodadaOficial>9){
					clrscr();
					if(rodadaOficial >= 9 && rodadaOficial <= 14)
						exibirPlayoffsBrasil(rodadaOficial, lista,jogo,1);
					if(rodadaOficial == 15)
						exibirPlayoffsBrasil(rodadaOficial, lista,jogo,2);
					if(rodadaOficial == 16)
						exibirPlayoffsBrasil(rodadaOficial, lista,jogo,3);
					if(rodadaOficial == 17)
						exibirPlayoffsBrasil(rodadaOficial, lista,jogo,4);
				}
				if(rodadaOficial < 9){
			        printCentralizado("LOGO MAIS OS PLAYOFFS ESTARAO EM ANDAMENTO",28,15);
			        gotoxy(119, 29);
			        Sleep(1200);
			        limparBufferTeclado();
			    }
			break;
			case 'G':
				exibirEstatisticaTime(lista,10,1);
			break;
			case 27:
				Sleep(1);break;
			default:
    			printCentralizado("TECLA INVALIDA! TECLAS DISPONIVEIS [A] [D] [P] [M] [N] [W]",28,15);
    			gotoxy(119, 29);
	        	Sleep(1000);
	        	limparBufferTeclado();
		}
		
		clrscr();
	}while(op != 27);
	return 5;
}

void exibirEstatisticaTime(listaDupla *lista,int num,int localidade){
	int time = 1;
	char op; int y , x ;
	listaDupla *listaAtual = NULL;
	do{
		clrscr();
		listaAtual = buscarTimeNaLista(lista,time);
		if(localidade == 1)
			MolduraBrasil();
		if(localidade == 2)
			MolduraEspanha();
		if(localidade == 3)
			MolduraItalia();
		if(localidade == 4)
			MolduraAmericas();
		
		int toggle = 0;
		do{
			if(localidade == 1){
			    if (listaAtual->info.elenco.codigo == 1) {
			        MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, 2, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			        MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, 2, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			    } else if (listaAtual->info.elenco.codigo == 5) {
			        MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, 15, 15);
			      	MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, 15, 15);
			    } else if (listaAtual->info.elenco.codigo == 7) {
			        MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1);
			        MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1);
			    } else if (listaAtual->info.elenco.codigo == 8) {
			        MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, 1, listaAtual->info.elenco.cor2);
			        MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1,1, listaAtual->info.elenco.cor2);
			    } else {
			    	MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			        MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			    }
			}else if(localidade == 2){
				 if (listaAtual->info.elenco.codigo == 7) {
				 	MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, 14, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			        MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, 14, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
				 }else if(listaAtual->info.elenco.codigo == 11) {
					MolduraColorida(60, 4, 114, 24, 14, 4, 8,8);
			        MolduraColorida(6, 4, 60, 24, 14, 4, 8,8);
				 }else if(listaAtual->info.elenco.codigo == 8) {
			        MolduraColorida(60, 4, 114, 24, 13, 13, 13,13);
			        MolduraColorida(6, 4, 60, 24,13, 13,13,13);
				 }else if(listaAtual->info.elenco.codigo == 10) {
			        MolduraColorida(60, 4, 114,24, 14, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1,listaAtual->info.elenco.cor1);
			        MolduraColorida(6, 4, 60, 24,listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1);
				 }else{
					MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
					MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
				}		
			}else if(localidade == 3){
				MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
				MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			}else if(localidade == 4){
				MolduraColorida(60, 4, 114, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
				MolduraColorida(6, 4, 60, 24, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			}
			
	        if (toggle == 0)
	            textcolor(listaAtual->info.elenco.cor1);
	        else
	            textcolor(listaAtual->info.elenco.cor2);
	            
	        gotoxy(41,5);
			printf("QUADRO TATICO");    
	
	        gotoxy(9, 5);
	        printf("Time: %s  [%d]", listaAtual->info.elenco.nomeEquipe,((listaAtual->info.elenco.jogador1.overall + listaAtual->info.elenco.jogador2.overall) + (listaAtual->info.elenco.jogador3.overall + listaAtual->info.elenco.jogador4.overall) + (listaAtual->info.elenco.jogador5.overall + listaAtual->info.elenco.goleiro1.overall))/6); 
	
	        gotoxy(19, 7);
	        printf("Presidente: %s [%d]", listaAtual->info.elenco.presida.nome, listaAtual->info.elenco.presida.overall);
	
	        // Cor dos jogadores e goleiro (invertida da do elenco)
	        if (toggle == 0)
	            textcolor(listaAtual->info.elenco.cor2);
	        else
	            textcolor(listaAtual->info.elenco.cor1);
		
	        gotoxy(13, 9);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador1.posicao, listaAtual->info.elenco.jogador1.nome, listaAtual->info.elenco.jogador1.overall, listaAtual->info.elenco.jogador1.valor/1000);
	
	        gotoxy(13, 11);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador2.posicao, listaAtual->info.elenco.jogador2.nome, listaAtual->info.elenco.jogador2.overall, listaAtual->info.elenco.jogador2.valor/1000);
	
	        gotoxy(13, 13);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador3.posicao, listaAtual->info.elenco.jogador3.nome, listaAtual->info.elenco.jogador3.overall, listaAtual->info.elenco.jogador3.valor/1000);
	
	        gotoxy(13, 15);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador4.posicao, listaAtual->info.elenco.jogador4.nome, listaAtual->info.elenco.jogador4.overall, listaAtual->info.elenco.jogador4.valor/1000);
	
	        gotoxy(13, 17);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador5.posicao, listaAtual->info.elenco.jogador5.nome, listaAtual->info.elenco.jogador5.overall, listaAtual->info.elenco.jogador5.valor/1000);
	
	        gotoxy(13, 21);
	        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.goleiro1.posicao, listaAtual->info.elenco.goleiro1.nome, listaAtual->info.elenco.goleiro1.overall, listaAtual->info.elenco.goleiro1.valor/1000);
	
	        gotoxy(49, 23);
	        printf("$: %.3f", listaAtual->info.elenco.valorMercado / 1000.0);
	        
	        y = 5;
			while(y <= 23){
				gotoxy(90, y); 
		    	printf("%c", 186);
		    	gotoxy(98, y); 
		    	printf("%c", 186);
		    	gotoxy(106, y); 
		    	printf("%c", 186);

		    	y++;
			}
			
			
			x = 61;
			while(x < 114){
				gotoxy(x, 6);
				if (x != 80 || x != 87 || x != 93 || x != 100)
					printf("%c", 205);
				gotoxy(x, 18);
				if (x != 80 || x != 87 || x != 93 || x != 100)
					printf("%c", 205);
				gotoxy(x, 20);
				if (x != 80 || x != 87 || x != 93 || x != 100)
					printf("%c", 205);
				x++;
			}
			gotoxy(109,3);
			printf("%d/%d",time,num);

	        gotoxy(74,5);printf("NOME");
	        gotoxy(93,5);printf("G/F");
	        gotoxy(101,5);printf("E/R");
	        gotoxy(109,5);printf("P/J");
	        
	        gotoxy(74,19);printf("NOME");
	        gotoxy(93,19);printf("D/F");
	        gotoxy(101,19);printf("G/S");
	        gotoxy(109,19);printf("P/J");
			
			gotoxy(70,7);
			printf("%s",listaAtual->info.elenco.presida.nome);
			gotoxy(70,9);
			printf("%s",listaAtual->info.elenco.jogador1.nome);
			gotoxy(70,11);
			printf("%s",listaAtual->info.elenco.jogador2.nome);
			gotoxy(70,13);
			printf("%s",listaAtual->info.elenco.jogador3.nome);
			gotoxy(70,15);
			printf("%s",listaAtual->info.elenco.jogador4.nome);
			gotoxy(70,17);
			printf("%s",listaAtual->info.elenco.jogador5.nome);
			gotoxy(70,21);
			printf("%s",listaAtual->info.elenco.goleiro1.nome);
			
			if(listaAtual->info.elenco.presida.gols < 10){
				gotoxy(95,7);
				printf("%d",listaAtual->info.elenco.presida.gols);
			}else{
				gotoxy(94,7);
				printf("%d",listaAtual->info.elenco.presida.gols);
			}
			if(listaAtual->info.elenco.jogador1.gols < 10){
				gotoxy(95,9);
				printf("%d",listaAtual->info.elenco.jogador1.gols);
			}else{
				gotoxy(94,9);
				printf("%d",listaAtual->info.elenco.jogador1.gols);
			}
			if(listaAtual->info.elenco.jogador2.gols < 10){
				gotoxy(95,11);
				printf("%d",listaAtual->info.elenco.jogador2.gols);
			}else{
				gotoxy(94,11);
				printf("%d",listaAtual->info.elenco.jogador2.gols);
			}
			if(listaAtual->info.elenco.jogador3.gols < 10){
				gotoxy(95,13);
				printf("%d",listaAtual->info.elenco.jogador3.gols);
			}else{
				gotoxy(94,13);
				printf("%d",listaAtual->info.elenco.jogador3.gols);
			}
			if(listaAtual->info.elenco.jogador4.gols < 10){
				gotoxy(95,15);
				printf("%d",listaAtual->info.elenco.jogador4.gols);
			}else{
				gotoxy(94,15);
				printf("%d",listaAtual->info.elenco.jogador4.gols);
			}
			if(listaAtual->info.elenco.jogador5.gols < 10){
				gotoxy(95,17);
				printf("%d",listaAtual->info.elenco.jogador5.gols);
			}else{
				gotoxy(94,17);
				printf("%d",listaAtual->info.elenco.jogador5.gols);
			}
			if(listaAtual->info.elenco.goleiro1.defesa < 10){
				gotoxy(95,21);
				printf("%d",listaAtual->info.elenco.goleiro1.defesa);
			}else{
				gotoxy(94,21);
				printf("%d",listaAtual->info.elenco.goleiro1.defesa);
			}
			
			
			
			if(listaAtual->info.elenco.presida.errou < 10){
				gotoxy(103,7);
				printf("%d",listaAtual->info.elenco.presida.errou);
			}else{
				gotoxy(102,7);
				printf("%d",listaAtual->info.elenco.presida.errou);
			}
			if(listaAtual->info.elenco.jogador1.errou < 10){
				gotoxy(103,9);
				printf("%d",listaAtual->info.elenco.jogador1.errou);
			}else{
				gotoxy(102,9);
				printf("%d",listaAtual->info.elenco.jogador1.errou);
			}
			if(listaAtual->info.elenco.jogador2.errou < 10){
				gotoxy(103,11);
				printf("%d",listaAtual->info.elenco.jogador2.errou);
			}else{
				gotoxy(102,11);
				printf("%d",listaAtual->info.elenco.jogador2.errou);
			}
			if(listaAtual->info.elenco.jogador3.errou < 10){
				gotoxy(103,13);
				printf("%d",listaAtual->info.elenco.jogador3.errou);
			}else{
				gotoxy(102,13);
				printf("%d",listaAtual->info.elenco.jogador3.errou);
			}
			if(listaAtual->info.elenco.jogador4.errou < 10){
				gotoxy(103,15);
				printf("%d",listaAtual->info.elenco.jogador4.errou);
			}else{
				gotoxy(102,15);
				printf("%d",listaAtual->info.elenco.jogador4.errou);
			}
			if(listaAtual->info.elenco.jogador5.errou < 10){
				gotoxy(103,17);
				printf("%d",listaAtual->info.elenco.jogador5.errou);
			}else{
				gotoxy(102,17);
				printf("%d",listaAtual->info.elenco.jogador5.errou);
			}
			if(listaAtual->info.elenco.goleiro1.golsSofridos < 10){
				gotoxy(103,21);
				printf("%d",listaAtual->info.elenco.goleiro1.golsSofridos);
			}else{
				gotoxy(102,21);
				printf("%d",listaAtual->info.elenco.goleiro1.golsSofridos);
			}
			
			if(listaAtual->info.partidas < 10){
				gotoxy(111,7);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,9);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,11);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,13);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,15);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,17);
				printf("%d",listaAtual->info.partidas);
				gotoxy(111,21);
				printf("%d",listaAtual->info.partidas);
			}else{
				gotoxy(110,7);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,9);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,11);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,13);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,15);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,17);
				printf("%d",listaAtual->info.partidas);
				gotoxy(110,21);
				printf("%d",listaAtual->info.partidas);
			}			
			
	        int tempoEspera = 1500; // em milissegundos
	        int tempoPassado = 0;
	        int passo = 10; // 10ms de cada vez
			if(time == 1){
    			printCentralizado("        PROXIMA TIME --> [D]",29,15);
    		}
    		if(time>1 && time < num){
    			printCentralizado("[A] <-- PROXIMA TIME --> [D]",29,15);
    		}
    		if(time == num){
    			printCentralizado("[A] <-- PROXIMA TIME        ",29,15);
    		}
    		printCentralizado("APERTE [ESC] PARA SAIR DO MENU ESTATISCAS POR TIME",2,12);
    		printCentralizado("G/F: GOLS FEITOS   E/R: GOLS PERDIDOS   P/J: PARTIDAS JOGADAS   G/S: GOLS SOFRIDOS   D/F DEFESAS FEITAS",25,15);
    		printCentralizado("$: VALOR DE MERCADO   [??]: OVERALL",26,15);
			gotoxy(119, 29); 
	        toggle = !toggle;
	    		
	        while (tempoPassado < tempoEspera) {
	            if (kbhit()) break; // Se alguma tecla for pressionada, sai na hora
	            Sleep(passo);
	            tempoPassado += passo;
	        }
	    	
	    	
	    	
	    } while(!kbhit());
	    op = getch();
		op = toupper(op);
		switch(op){
			case 'A':
    			if(time != 1){
    				time--;
    			}
    		break;
    		case 'D':
    			if(time < num){
    				time++;
    			}
    		break;
    		case 27:
    			Sleep(1);break;
    		default:
    			printCentralizado("TECLA INVALIDA! TECLAS DISPONIVEIS [A] [D] [ESC]",29,15);
    			gotoxy(119, 29);
	        	Sleep(1000);
	        	limparBufferTeclado();
		}
		
	}while(op != 27);
}
void limaparNomesTrocas(void){
	gotoxy(66, 7);
	printf("                                                     ");
    gotoxy(66, 8);
    printf("                                                     ");
	gotoxy(66, 10);
	printf("                                                     ");
    gotoxy(66, 12);
    printf("                                                     ");
    gotoxy(66, 14);
    printf("                                                     ");
    gotoxy(66, 16);
    printf("                                                     ");
    gotoxy(66, 18);
    printf("                                                     ");
    gotoxy(66, 20);
    printf("                                                     ");
}
void marketplace(listaDupla **lista1,tree *resultado,listaDupla **lista2,listaDupla **lista3,listaDupla **lista4,int rodadaOficial,int l1){
	int rodadaMAX = 7;
	char op;int localidade;
	int i, num;
	listaDupla *meuTime = buscarTimeNaLista(*lista1, resultado->time.codigo);
	listaDupla *listaAtual = NULL;
	clrscr();
	int sairdessamerda;
	if(l1 == 1){
	    if (meuTime->info.elenco.codigo == 1) {
	         MolduraColorida(7, 6, 58, 22, meuTime->info.elenco.cor1, 2, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
	    } else if (meuTime->info.elenco.codigo == 5) {
	        MolduraColorida(7, 6, 58, 22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, 15, 15);
	    } else if (meuTime->info.elenco.codigo == 7) {
	        MolduraColorida(7,6,58,22, meuTime->info.elenco.cor2, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, meuTime->info.elenco.cor1);
	    } else if (meuTime->info.elenco.codigo == 8) {
	        MolduraColorida(7,6,58,22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1,1, meuTime->info.elenco.cor2);
	    } else {
	        MolduraColorida(7,6,58,22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
	    }
	}else if(l1 == 2){
		 if (meuTime->info.elenco.codigo == 7) {
	       MolduraColorida(7,6,58,22, meuTime->info.elenco.cor1, 14, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
		 }else if(meuTime->info.elenco.codigo == 11) {
	       MolduraColorida(7,6,58,22, 14, 4, 8,8);
		 }else if(meuTime->info.elenco.codigo == 8) {
	       MolduraColorida(7,6,58,22,13, 13,13,13);
		 }else if(meuTime->info.elenco.codigo == 10) {
	       MolduraColorida(7,6,58,22,meuTime->info.elenco.cor2, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1);
		 }else{
			MolduraColorida(7, 6,58, 22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
		}		
	}else if(l1 == 3){
		MolduraColorida(7, 6, 58, 22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
	}else if(l1 == 4){
		MolduraColorida(7, 6, 58, 22, meuTime->info.elenco.cor1, meuTime->info.elenco.cor1, meuTime->info.elenco.cor2, meuTime->info.elenco.cor2);
	}
	MolduraColorida(1,1,120,30,15,15,15,15);
	MolduraColorida(64,6,114,22,15,15,15,15);
	i = 1;
	localidade = 1;
	do{
		if(localidade == 1){
			if(l1 == 1){
				num = 9;
				listaAtual = buscarVizinhoTimeNaLista(*lista1, i,resultado->time.codigo);
			}	
			else{
				num = 10;
				listaAtual = buscarTimeNaLista(*lista1 , i);
			}
			if (listaAtual != NULL) {
				gotoxy(84,5);
				printf("KL BRASIL --> [M]          1/4");
			    if (listaAtual->info.elenco.codigo == 1) {
			         MolduraColorida(64, 6, 114, 22, listaAtual->info.elenco.cor1, 2, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			    } else if (listaAtual->info.elenco.codigo == 5) {
			      	MolduraColorida(64, 6, 114, 22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, 15, 15);
			    } else if (listaAtual->info.elenco.codigo == 7) {
			       MolduraColorida(64,6,114,22, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1);
			    } else if (listaAtual->info.elenco.codigo == 8) {
			       MolduraColorida(64,6,114,22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1,1, listaAtual->info.elenco.cor2);
			    } else {
			       MolduraColorida(64,6,114,22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			    }	
			}	
		}else if(localidade == 2){
			if(l1 == 2){
				num = 11;
				listaAtual = buscarVizinhoTimeNaLista(*lista2,i,resultado->time.codigo);
			}else{
				num = 12;
				listaAtual = buscarTimeNaLista(*lista2, i);
			}
			gotoxy(76,5);
			printf(" [N] <-- KL ESPANHA --> [M]         2/4");
			 if (listaAtual->info.elenco.codigo == 7) {
		       MolduraColorida(64,6,114,22, listaAtual->info.elenco.cor1, 14, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			 }else if(listaAtual->info.elenco.codigo == 11) {
		       MolduraColorida(64,6,114,22, 14, 4, 8,8);
			 }else if(listaAtual->info.elenco.codigo == 8) {
		       MolduraColorida(64,6,114,22,13, 13,13,13);
			 }else if(listaAtual->info.elenco.codigo == 10) {
		       MolduraColorida(64,6,114,22,listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1);
			 }else{
				MolduraColorida(64, 6, 114, 22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
			}		
		}else if(localidade == 3){
			if(l1 == 3){
				num = 11;
				listaAtual = buscarVizinhoTimeNaLista(*lista3, i,resultado->time.codigo);
			}else{
				num = 12;
				listaAtual = buscarTimeNaLista(*lista3, i);
			}
			gotoxy(77,5);
			printf(" [N] <-- KL ITALIA --> [M]         3/4");
			MolduraColorida(64, 6, 114, 22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
		}else if(localidade == 4){
			if(l1 == 4){
				num = 11;
				listaAtual = buscarVizinhoTimeNaLista(*lista4, i,resultado->time.codigo);
			}else{
				num = 12;
				listaAtual = buscarTimeNaLista(*lista4, i);
			}
			gotoxy(78,5);
			printf("[N] <-- KL AMERICAS              4/4");
			MolduraColorida(64, 6, 114, 22, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor1, listaAtual->info.elenco.cor2, listaAtual->info.elenco.cor2);
		}
		
		gotoxy(80,23);
		if(i == 1){
			printf("        TIME --> [D]");
		}else if(i < num){
			printf("[A] <-- TIME --> [D]");
		}else{
			printf("[A] <-- TIME");
		}
		gotoxy(110,23);
		printf("%d/%d",i,num );
		//parte de exibir os time.  MEU TME ""
		textcolor(resultado->time.cor1);
 		gotoxy(9, 7);
	    printf("Time: %s  [%d]", resultado->time.nomeEquipe,((resultado->time.jogador1.overall + resultado->time.jogador2.overall) + (resultado->time.jogador3.overall + resultado->time.jogador4.overall) + (resultado->time.jogador5.overall + resultado->time.goleiro1.overall))/6); 
	    gotoxy(9, 8);
	    printf("Presidente: %s [%d]", resultado->time.presida.nome, resultado->time.presida.overall);
		gotoxy(13, 10);
	    printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador1.posicao, resultado->time.jogador1.nome, resultado->time.jogador1.overall, resultado->time.jogador1.valor/1000);	
        gotoxy(13, 12);
        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador2.posicao, resultado->time.jogador2.nome, resultado->time.jogador2.overall, resultado->time.jogador2.valor/1000);
        gotoxy(13, 14);
        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador3.posicao, resultado->time.jogador3.nome, resultado->time.jogador3.overall, resultado->time.jogador3.valor/1000);
        gotoxy(13, 16);
        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador4.posicao, resultado->time.jogador4.nome, resultado->time.jogador4.overall, resultado->time.jogador4.valor/1000);
        gotoxy(13, 18);
        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador5.posicao, resultado->time.jogador5.nome, resultado->time.jogador5.overall, resultado->time.jogador5.valor/1000);
        gotoxy(13, 20);
        printf("[%s] - %s [%d][$: %.3f]", resultado->time.goleiro1.posicao, resultado->time.goleiro1.nome, resultado->time.goleiro1.overall, resultado->time.goleiro1.valor/1000);
        textcolor(15);
        // time gerenciar troca.
        textcolor(listaAtual->info.elenco.cor1);
 		gotoxy(66, 7);
	    printf("Time: %s  [%d]", listaAtual->info.elenco.nomeEquipe,((listaAtual->info.elenco.jogador1.overall + listaAtual->info.elenco.jogador2.overall) + (listaAtual->info.elenco.jogador3.overall + listaAtual->info.elenco.jogador4.overall) + (listaAtual->info.elenco.jogador5.overall + listaAtual->info.elenco.goleiro1.overall))/6); 
	    gotoxy(66, 8);
	    printf("Presidente: %s [%d]", listaAtual->info.elenco.presida.nome, listaAtual->info.elenco.presida.overall);
		gotoxy(70, 10);
	    printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador1.posicao, listaAtual->info.elenco.jogador1.nome, listaAtual->info.elenco.jogador1.overall, listaAtual->info.elenco.jogador1.valor/1000);	
        gotoxy(70, 12);
        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador2.posicao, listaAtual->info.elenco.jogador2.nome, listaAtual->info.elenco.jogador2.overall, listaAtual->info.elenco.jogador2.valor/1000);
        gotoxy(70, 14);
        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador3.posicao, listaAtual->info.elenco.jogador3.nome, listaAtual->info.elenco.jogador3.overall, listaAtual->info.elenco.jogador3.valor/1000);
        gotoxy(70, 16);
        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador4.posicao, listaAtual->info.elenco.jogador4.nome, listaAtual->info.elenco.jogador4.overall, listaAtual->info.elenco.jogador4.valor/1000);
        gotoxy(70, 18);
        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.jogador5.posicao, listaAtual->info.elenco.jogador5.nome, listaAtual->info.elenco.jogador5.overall, listaAtual->info.elenco.jogador5.valor/1000);
        gotoxy(70, 20);
        printf("[%s] - %s [%d][$: %.3f]", listaAtual->info.elenco.goleiro1.posicao, listaAtual->info.elenco.goleiro1.nome, listaAtual->info.elenco.goleiro1.overall, listaAtual->info.elenco.goleiro1.valor/1000);
        textcolor(15);
        printCentralizado("APERTE [ESC] PARA SAIR DO MARKETPLACE",2,12);
        sairdessamerda = 0;
        if(rodadaOficial <= 6){
        	printCentralizado("APERTE [T] PARA INICIAR UM TROCA ENTRE ESSES TIMES",25,15);
			if(rodadaOficial <= 6){
				int toggle = 0;
				do{
					if (toggle == 0)
		            	textcolor(12);
		        	else
		            	textcolor(4);
		            toggle = !toggle;
		
			        int tempoEspera = 1000; // em milissegundos
			        int tempoPassado = 0;
			        int passo = 10; // 10ms de cada vez
					gotoxy(37,29);printf("! ! ! FALTAM %d RODADAS PARA O MERCADO FECHAR ! ! !",rodadaMAX - rodadaOficial);textcolor(15);gotoxy(119,29);
			        while (tempoPassado < tempoEspera) {
			            if (kbhit()){
			            	sairdessamerda = 1;
							break;
						} // Se alguma tecla for pressionada, sai na hora
			            Sleep(passo);
			            tempoPassado += passo;
		        	}
		        	
		        }while(sairdessamerda != 1);
		        
			}
		}else{
			printCentralizado("MERCADO FECHADO, NOVO MERCADO ABRE NO INICIO DA PROXIMA TEMPORADA",29,12);
		}
		gotoxy(119,29);
		op = getch();
		op = toupper(op);
		switch(op){
			case 'A':
				if(i > 1){
					i--;
					limaparNomesTrocas();
				}
			break;
			case 'D':
				if(i < num){
					i++;
					limaparNomesTrocas();

				}
			break;	
			case 'M':
				if(localidade < 4){
					localidade++;
					i = 1;
					limaparNomesTrocas();
				}
			break;
			case 'N':
				if(localidade != 1){
					localidade--;
					i = 1;
					limaparNomesTrocas();
				}
			break;
			case 'T':
				if(rodadaOficial <= 6){
					printCentralizado("                                                           ",25,3);
					gotoxy(80,23);
					printf("                                    ");
					gotoxy(77,5);
					printf("                                           ");
					int confirmado = 0,kbind,sair = 0;
					char jogadorTime, jogadorFora;
					do{
						printCentralizado("APERTA A TECLA REFERENTE AO JOGADOR QUE DESEJA TROCAR",25,15);
						printCentralizado("LEMBRETE: GOLEIROS SO PODEM SER TROCADOS POR GOLEIROS",27,15);
						gotoxy(9, 10);printf("[1]");
						gotoxy(9, 12);printf("[2]");
						gotoxy(9, 14);printf("[3]");
						gotoxy(9, 16);printf("[4]");
						gotoxy(9, 18);printf("[5]");
						gotoxy(9, 20);printf("[G]");
						gotoxy(119,29);
						jogadorTime = toupper(getch());
						if(jogadorTime == 27){
							sair = 1;
							confirmado = 1;
						}
						if(sair == 0){
							if (jogadorTime == '1' || jogadorTime == '2' || jogadorTime == '3' || jogadorTime == '4'|| jogadorTime == '5' || jogadorTime == 'G')
								confirmado = 1;
							else{
								printCentralizado("                                                                   ",25,3);
								printCentralizado("                                                                   ",27,3);
						 		printCentralizado("SELECIONE UMA TECLA VALIDA ENTRE [1] [2] [3] [4] [5] [G]",25,15);gotoxy(119,27);
								Sleep(1222);
								printCentralizado("                                                        ",25,15);
							}
						}
						
					}while(confirmado != 1);
					if(sair == 0){
							gotoxy(9, 10);printf("   ");gotoxy(9, 12);printf("   ");gotoxy(9, 14);printf("   ");gotoxy(9, 16);printf("   ");gotoxy(9, 18);printf("   ");gotoxy(9, 20);printf("   ");
						if(jogadorTime == '1')
							kbind = 10;
						if(jogadorTime == '2')
							kbind = 12;
						if(jogadorTime == '3')
							kbind = 14;
						if(jogadorTime == '4')
							kbind = 16;
						if(jogadorTime == '5')
							kbind = 18;
						if(jogadorTime == 'G')
							kbind = 20;
							
						gotoxy(9,kbind);
						printf("-->");
						
						printCentralizado("                                                                   ",25,3);
						confirmado = 0;
						do{
							printCentralizado("APERTA A TECLA REFERENTE AO JOGADOR DO TIME ADVERSARIO QUE DESEJA TROCAR",25,15);
							printCentralizado("LEMBRETE: GOLEIROS SO PODEM SER TROCADOS POR GOLEIROS",27,15);
							gotoxy(66, 10);printf("[1]");gotoxy(66, 12);printf("[2]");gotoxy(66, 14);printf("[3]");gotoxy(66, 16);printf("[4]");gotoxy(66, 18);printf("[5]");gotoxy(66, 20);printf("[G]");gotoxy(119,29);
							jogadorFora = toupper(getch());
							if(jogadorFora == 27){
								sair = 1;
								confirmado = 1;
							}
							if(sair == 0){
								if(jogadorTime == '1' || jogadorTime == '2' || jogadorTime == '3' || jogadorTime == '4' || jogadorTime == '5' ){
									if(jogadorFora == '1' || jogadorFora == '2' || jogadorFora == '3' || jogadorFora == '4'|| jogadorFora == '5'){
										confirmado = 1;
									}else{
										printCentralizado("                                                                           ",25,3);
										printCentralizado("                                                           ",27,3);
									 	printCentralizado("SELECIONE UMA TECLA VALIDA ENTRE [1] [2] [3] [4] [5]",25,15);gotoxy(119,27);
										Sleep(1222);
										printCentralizado("                                                        ",25,15);
									}
								}else{
									//EU ESCOLHER GK
									if(jogadorTime == 'G'){
										if(jogadorFora == 'G'){
											confirmado = 1;
										}else{
											printCentralizado("                                                                           ",25,3);
											printCentralizado("                                                           ",27,3);
										 	printCentralizado("GOLEIROS SO PODEM SER TROCADOS POR GOLEIROS",25,15);gotoxy(119,29);
											Sleep(702);
											printCentralizado("                                                        ",25,15);
											confirmado = 0;
										}
									}
								}
							}	
								
						}while(confirmado != 1);
						if(sair == 0){
							printCentralizado("                                                                           ",25,3);
							gotoxy(66, 10);printf("   ");gotoxy(66, 12);printf("   ");gotoxy(66, 14);printf("   ");gotoxy(66, 16);printf("   ");gotoxy(66, 18);printf("   ");gotoxy(66, 20);printf("   ");
							if(jogadorFora == '1')
								kbind = 10;
							if(jogadorFora == '2')
								kbind = 12;
							if(jogadorFora == '3')
								kbind = 14;
							if(jogadorFora == '4')
								kbind = 16;
							if(jogadorFora == '5')
								kbind = 18;
							if(jogadorFora == 'G')
								kbind = 20;
							gotoxy(66,kbind);
							printf("-->");gotoxy(119,29);
							printCentralizado("                                                           ",27,3);
						}
					}
				}
			break;
		}
		gotoxy(70,5);
		printf("                                              ");
		gotoxy(70,23);
		printf("                                               ");
	}while(op != 27);	 
	
}
#endif
