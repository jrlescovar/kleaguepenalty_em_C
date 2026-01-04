#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

void inserirLista(listaDupla **lista, tree *raiz) {
    // Alocação de memória para um novo nó
    listaDupla *novaLista = (listaDupla*)malloc(sizeof(listaDupla));
    if (novaLista == NULL) { //NUNCA ENTRAR AQUI AMEM!
        printf("Erro na alocação de memória.\n");
        return; // Se falhar na alocação, sai da função
    }
    // Inicializa o novo nó
    novaLista->prox = NULL;  // O próximo ainda não existe
    novaLista->ant = NULL;   // O anterior ainda não existe
    // Preenche os dados do time na nova lista
    novaLista->info.elenco.codigo = raiz->time.codigo;
    strcpy(novaLista->info.elenco.nomeEquipe, raiz->time.nomeEquipe);
    // Atribuindo os dados dos jogadores
    novaLista->info.elenco.jogador1 = raiz->time.jogador1;
    novaLista->info.elenco.jogador2 = raiz->time.jogador2;
    novaLista->info.elenco.jogador3 = raiz->time.jogador3;
    novaLista->info.elenco.jogador4 = raiz->time.jogador4;
    novaLista->info.elenco.jogador5 = raiz->time.jogador5;
    // Atribuindo o goleiro
    novaLista->info.elenco.goleiro1 = raiz->time.goleiro1;
    // Atribuindo o presidente
    novaLista->info.elenco.presida = raiz->time.presida;
    // Atribuindo outras informações
    novaLista->info.elenco.cor1 = raiz->time.cor1;
    novaLista->info.elenco.cor2 = raiz->time.cor2;
    novaLista->info.elenco.valorMercado = raiz->time.valorMercado;
    
    novaLista->info.partidas = 0;
    novaLista->info.pontos = 0;
    novaLista->info.saldo = 0;
    novaLista->info.vitoria = 0;
    novaLista->info.derrota = 0;
    novaLista->info.empate = 0;
    novaLista->info.golsFeitos = 0;
    novaLista->info.golsSofridos= 0;
    //novaLista->info.saldoDegols = 0;
    // Verifica se a lista está vazia
    if (*lista == NULL) {
        *lista = novaLista; // Se estiver vazia, o novo nó é o primeiro
    } else {
        listaDupla *temp = *lista;
        // Percorre até o final da lista
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        // Adiciona o novo nó ao final
        temp->prox = novaLista;
        novaLista->ant = temp;
    }
}

listaDupla* buscarTimeNaLista(listaDupla *lista, int codigo) {
    listaDupla* temp = lista;  // Inicia com o primeiro nó da lista
    
    // Percorre a lista até encontrar o código ou chegar ao final da lista
    while (temp != NULL) {
        if (temp->info.elenco.codigo == codigo) {
            return temp;  // Se encontrar o time, retorna o nó
        }
        temp = temp->prox;  // Avança para o próximo nó
    }
    
    // Se não encontrar o time com o código informado
    return NULL;
}
listaDupla* buscarVizinhoTimeNaLista(listaDupla *lista, int posicao, int codigoIgnorado) {
    int cont = 0;

    while (lista != NULL) {
        if (lista->info.elenco.codigo != codigoIgnorado) {
            cont++;
            if (cont == posicao) {
                return lista;
            }
        }
        lista = lista->prox;
    }

    return NULL;  // Não encontrou o vizinho desejado
}
listaDupla* buscarTimeNaListaPOSI(listaDupla *lista, int codigo) {
    listaDupla* temp = lista;  // Inicia com o primeiro nó da lista
    
    // Percorre a lista até encontrar o código ou chegar ao final da lista
    int i=1;
    while (temp != NULL) {
        if (i == codigo) {
            return temp;  // Se encontrar o time, retorna o nó
        }
        temp = temp->prox;  // Avança para o próximo nó
        i++;
    }
    
    // Se não encontrar o time com o código informado
    return NULL;
} 

void centralizaTextoBrasil(int y, const char* texto, int cor) {
    int comprimentoTexto = strlen(texto);
    int espacos = (34 - 15 - comprimentoTexto) / 2; // Calcula os espaços necessários para centralizar
    
    // O valor de x deve ser entre 15 e 34
    int x = 15 + espacos; // Adiciona a quantidade de espaços à posição mínima (15)
    
    // Move o cursor para a posição calculada
    gotoxy(x, y);
    textcolor(cor);
    // Exibe o texto
    printf("%s", texto);
    textcolor(15);
}

void exibirTabela(listaDupla *lista, int y) {
    listaDupla *temp = lista; // Começa no início da lista
    /*if (temp == NULL) {
        printf("A lista está vazia.\n");
        
    }*/
	
    while (temp != NULL) {
    	if(y-7 < 10)
    	{
    	
    		if(y-7 > 1 && y-7 <= 7)
    			textcolor(14);
    		else{
    			textcolor(4);
    		}
    		if(y-7 == 1)
    			textcolor(10);
    		gotoxy(13,y);
    		printf("%d", y-7);
    	}else{
    		textcolor(4);
    		gotoxy(12,y);
    		printf("%d", y-7);
    	
    	}
    	textcolor(15);

    	
        centralizaTextoBrasil(y, temp->info.elenco.nomeEquipe,temp->info.elenco.cor1);
        
		if(temp->info.pontos < 10){
			gotoxy(39,y);
			printf("%d",temp->info.pontos);
		}else{
			gotoxy(38,y);
			printf("%d",temp->info.pontos);
		}
		
		gotoxy(43,y);
		printf("%d",temp->info.vitoria);
		gotoxy(47,y);
		printf("%d",temp->info.empate);
		gotoxy(51,y);
		printf("%d",temp->info.derrota);
		if(temp->info.golsFeitos > 9){
			gotoxy(55,y);
			printf("%d",temp->info.golsFeitos);
		}else{
			gotoxy(56,y);
			printf("%d",temp->info.golsFeitos);
		}
		if(temp->info.golsSofridos > 9){
			gotoxy(60,y);
			printf("%d",temp->info.golsSofridos);
		}else{
			gotoxy(61,y);
			printf("%d",temp->info.golsSofridos);
		}
		if(temp->info.golsFeitos - temp->info.golsSofridos > 9 || temp->info.golsFeitos - temp->info.golsSofridos < 0){
			gotoxy(65,y);
			printf("%d",temp->info.golsFeitos - temp->info.golsSofridos);
		}else{ 
			gotoxy(66,y);
			printf("%d",temp->info.golsFeitos - temp->info.golsSofridos);
		}
	

        temp = temp->prox; // Move para o próximo nó
        y++;
    }
}
void ordenarPorPontos(listaDupla **inicio) {
    if (*inicio == NULL) return;

    int trocou;
    listaDupla *atual;
    listaDupla *ultimo = NULL;

    do {
        trocou = 0;
        atual = *inicio;

        while (atual->prox != ultimo) {
            int pontosAtual = atual->info.pontos;
            int pontosProx  = atual->prox->info.pontos;

            int saldoAtual = atual->info.golsFeitos - atual->info.golsSofridos;
            int saldoProx  = atual->prox->info.golsFeitos - atual->prox->info.golsSofridos;

            if (
                pontosAtual < pontosProx || 
                (pontosAtual == pontosProx && saldoAtual < saldoProx)
            ) {
                // Troca os dados
                jogar temp = atual->info;
                atual->info = atual->prox->info;
                atual->prox->info = temp;
                trocou = 1;
            }

            atual = atual->prox;
        }

        ultimo = atual;
    } while (trocou);
}
typedef struct {
    jogador jog;
    char time[20];
    int cor;
    int partidas;
} Artilheiro;
typedef struct {
    goleiro g;
    char time[20];
    int golsSofridos;
    int cor;
    int partida;
} TopGoleiro;

TopGoleiro topGoleiros[100];

char exibirTopGoleiros(listaDupla *inicio, int l) {
    int total = 0,i,y,x;
	clrscr();
	if(l == 1){
		MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
	    printCentralizado("--- TOP 10 GOLEIROS KL-PENALTY BRASIL---",4,14);
    }
    if(l == 2){
    	MolduraColorida(1, 1, 120, 30, 4, 4, 14, 14);
	    printCentralizado("--- TOP 10 GOLEIROS KL-PENALTY ESPANHA---",4,4);
    }
    if(l == 3){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 10, 4);
	    printCentralizado("--- TOP 10 GOLEIROS KL-PENALTY ITALIA---",4,10);;
	}
	if(l == 4){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 9, 9);
	    printCentralizado("--- TOP 10 GOLEIROS KL-PENALTY AMERICAS---",4,9);;
	}
	textcolor(15);
	Moldura(27,7,96,20);
	for(i = 1; i<11 ; i++){
		if(i < 10){
			gotoxy(30,i+9);
			printf("%d",i);
		}else{
			gotoxy(29,i+9);
			printf("%d",i);
		}
	}
	y = 8;
	while(y <= 19){
		gotoxy(31, y); 
    	printf("%c", 186);
    	gotoxy(52, y); 
    	printf("%c", 186);
    	gotoxy(58, y); 
    	printf("%c", 186);
		gotoxy(64, y);
    	printf("%c", 186);
    	gotoxy(69, y); 
    	printf("%c", 186);
    	//gotoxy(80, y);
    	//printf("%c", 186);
    	y++;
	}
	x = 28;
	while(x < 96){
		gotoxy(x, 9);
		if (x != 31 || x != 51 || x != 56 || x != 61 || x != 75)
			printf("%c", 205);
		x++;
	}
	gotoxy(28,8);
	printf("POS");
	gotoxy(40,8);
	printf("NOME");
	gotoxy(54,8);
	printf("D/F");
	gotoxy(60,8);
	printf("G/S");
	gotoxy(66,8);
	printf("PJ");
	gotoxy(80,8);
	printf("EQUIPE");
    for (listaDupla *p = inicio; p != NULL; p = p->prox) {
        topGoleiros[total].g = p->info.elenco.goleiro1;
        strcpy(topGoleiros[total].time, p->info.elenco.nomeEquipe);
        topGoleiros[total].golsSofridos = p->info.elenco.goleiro1.golsSofridos;
        topGoleiros[total].partida = p->info.partidas;
        topGoleiros[total].cor = p->info.elenco.cor1;
        total++;
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (topGoleiros[j].g.defesa < topGoleiros[j + 1].g.defesa) {
                TopGoleiro temp = topGoleiros[j];
                topGoleiros[j] = topGoleiros[j + 1];
                topGoleiros[j + 1] = temp;
            }
        }
    }
	
    textcolor(15);
    for (int i = 0; i < total && i < 10; i++) {
    	textcolor(topGoleiros[i].cor);;
    	if(strlen(topGoleiros[i].g.nome) < 8){
    		gotoxy(38,i+10);
	    	printf("%s[%d]",topGoleiros[i].g.nome,topGoleiros[i].g.overall);
    	}else if(strlen(topGoleiros[i].g.nome) < 12){ 
	    	gotoxy(36,i+10);
	    	printf("%s[%d]",topGoleiros[i].g.nome,topGoleiros[i].g.overall);
		}else if(strlen(topGoleiros[i].g.nome) == 14){
			gotoxy(33,i+10);
	    	printf("%s[%d]",topGoleiros[i].g.nome,topGoleiros[i].g.overall);
		}else{
			gotoxy(34,i+10);
	    	printf("%s[%d]",topGoleiros[i].g.nome,topGoleiros[i].g.overall);
		}
    	textcolor(15);
    	if(topGoleiros[i].g.defesa <= 9){
    		gotoxy(56,i+10);
    		printf("%d",topGoleiros[i].g.defesa);
    	}else{
    		gotoxy(55,i+10);
    		printf("%d",topGoleiros[i].g.defesa);
    	}
    	if(topGoleiros[i].golsSofridos <= 9){
    		gotoxy(62,i+10);
    		printf("%d",topGoleiros[i].golsSofridos);
    	}else{
    		gotoxy(61,i+10);
    		printf("%d",topGoleiros[i].golsSofridos);
    	}
    	if(topGoleiros[i].partida <= 9)
    		gotoxy(67,i+10);
    	else
    		gotoxy(66,i+10);
    	printf("%d",topGoleiros[i].partida);
    	textcolor(topGoleiros[i].cor);
    	if(strlen(topGoleiros[i].time) == 5 ){
    		gotoxy(81,i+10);
    		printf("%s", topGoleiros[i].time);
    	}else if(strlen( topGoleiros[i].time) == 6){
	    	gotoxy(80,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 7){
	    	gotoxy(80,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 8){
	    	gotoxy(79,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 9){
	    	gotoxy(79,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 10){
	    	gotoxy(78,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 11){
	    	gotoxy(78,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 12){
	    	gotoxy(77,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 13){
	    	gotoxy(77,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 14){
	    	gotoxy(76,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 15){
	    	gotoxy(76,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	else if(strlen( topGoleiros[i].time) == 16){
	    	gotoxy(75,i+10);
    		printf("%s", topGoleiros[i].time);
    	}
    	textcolor(15);
	}
	printCentralizado(" D/F: DEFESAS FEITAS   G/S: GOLS SOFRIDOS   PJ: PARTIDAS JOGADAS",21,15);
	printCentralizado("APERTE [A] <---- ESTATISTICAS DA ARTILHARIA      ESTATISTICAS PRESIDENTE ----> APERTE [P]",28,15);
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
	gotoxy(119,29);
	char plv;
    do{
    	plv = toupper(getch());
    	if(plv == 27 || plv == 'A' || plv == 'P'){
    		break;
    	}else{
    		printCentralizado("APERTE UMA TECLA VALIDA !",29,15);
    		Sleep(850);
    		limparBufferTeclado();
    		printCentralizado("                            ",29,15);
    		gotoxy(119,29);
    	}
    	
    }while (plv != 27 && plv != 'A'&& plv != 'P');
    
    return plv;
}
char exibirEstatisticas(listaDupla *inicio,int l) {	
	clrscr();
	int i,x,y;
	if(l == 1){
		MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
	    printCentralizado("--- TOP 10 ARTILHEIROS KL-PENALTY BRASIL---",4,14);
    }
    if(l == 2){
		MolduraColorida(1, 1, 120, 30, 4, 4, 14, 14);
	    printCentralizado("--- TOP 10 ARTILHEIROS KL-PENALTY ESPANHA---",4,4);
    }
    if(l == 3){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 10, 4);
	    printCentralizado("--- TOP 10 ARTILHEIROS KL-PENALTY ITALIA---",4,10);
	}
	if(l == 4){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 9, 9);
	    printCentralizado("--- TOP 10 ARTILHEIROS KL-PENALTY AMERICAS---",4,9);
	}
	textcolor(15);
	Moldura(27,7,96,20);
	for(i = 1; i<11 ; i++){
		if(i < 10){
			gotoxy(30,i+9);
			printf("%d",i);
		}else{
			gotoxy(29,i+9);
			printf("%d",i);
		}
	}
	y = 8;
	while(y <= 19){
		gotoxy(31, y); 
    	printf("%c", 186);
    	gotoxy(52, y); 
    	printf("%c", 186);
    	gotoxy(58, y); 
    	printf("%c", 186);
		gotoxy(64, y);
    	printf("%c", 186);
    	gotoxy(69, y); 
    	printf("%c", 186);
    	//gotoxy(80, y);
    	//printf("%c", 186);
    	y++;
	}
	x = 28;
	while(x < 96){
		gotoxy(x, 9);
		if (x != 31 || x != 51 || x != 56 || x != 61 || x != 75)
			printf("%c", 205);
		x++;
	}
	gotoxy(28,8);
	printf("POS");
	gotoxy(40,8);
	printf("NOME");
	gotoxy(54,8);
	printf("G/F");
	gotoxy(60,8);
	printf("F/M");
	gotoxy(66,8);
	printf("PJ");
	gotoxy(80,8);
	printf("EQUIPE");
    Artilheiro artilheiros[100];
    int total = 0;

    for (listaDupla *p = inicio; p != NULL; p = p->prox) {
        times t = p->info.elenco;
        int partidas = p->info.partidas;

        jogador jogadores[5] = { t.jogador1, t.jogador2, t.jogador3, t.jogador4, t.jogador5 };

        for (int i = 0; i < 5; i++) {
            artilheiros[total].jog = jogadores[i];
            strcpy(artilheiros[total].time, p->info.elenco.nomeEquipe);
            artilheiros[total].partidas = partidas;
            artilheiros[total].cor = p->info.elenco.cor1;
            total++;
        }
    }

    // Ordenar por gols decrescentesww
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (artilheiros[j].jog.gols < artilheiros[j + 1].jog.gols) {
                Artilheiro temp = artilheiros[j];
                artilheiros[j] = artilheiros[j + 1];
                artilheiros[j + 1] = temp;
            }
        }
    }

    // Exibir os 10 primeiros
    
    textcolor(15);
    for (int i = 0; i < total && i < 10; i++){
    	textcolor(artilheiros[i].cor);
    	if(strlen(artilheiros[i].jog.nome) < 8){
    		gotoxy(38,i+10);
	    	printf("%s[%d]",artilheiros[i].jog.nome, artilheiros[i].jog.overall);
    	}else if(strlen(artilheiros[i].jog.nome) < 11){
	    	gotoxy(36,i+10);
	    	printf("%s[%d]",artilheiros[i].jog.nome, artilheiros[i].jog.overall);
		}else{
			gotoxy(34,i+10);
	    	printf("%s[%d]",artilheiros[i].jog.nome, artilheiros[i].jog.overall);
		}
    	textcolor(15);
		gotoxy(60,i+10);
		printf("%s",artilheiros[i].jog.posicao);
    	if(artilheiros[i].jog.gols <= 9){
    		gotoxy(56,i+10);
    		printf("%d",artilheiros[i].jog.gols);
    	}else{
    		gotoxy(55,i+10);
    		printf("%d",artilheiros[i].jog.gols);
    	}
    	
    	if(artilheiros[i].partidas <= 9)
    		gotoxy(67,i+10);
    	else
    		gotoxy(66,i+10);
    	printf("%d",artilheiros[i].partidas);
    	
    	textcolor(artilheiros[i].cor);
    	
    	if(strlen(artilheiros[i].time) == 5 ){//ok2
    		gotoxy(81,i+10);
    		printf("%s", artilheiros[i].time);
    	}else if(strlen( artilheiros[i].time) == 6){//ok
	    	gotoxy(80,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 7){//ok
	    	gotoxy(80,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 8){//ok
	    	gotoxy(79,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 9){//ok
	    	gotoxy(79,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 10){//ok
	    	gotoxy(78,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 11){//ok
	    	gotoxy(78,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 12){//ok
	    	gotoxy(77,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 13){//ok
	    	gotoxy(77,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 14){//ok
	    	gotoxy(76,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 15){
	    	gotoxy(76,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	else if(strlen( artilheiros[i].time) == 16){//ok
	    	gotoxy(75,i+10);
    		printf("%s", artilheiros[i].time);
    	}
    	
    	
    	textcolor(15);
	} 
	printCentralizado(" G/F: GOLS FEITOS   F/M: POSICAO DO JOGADOR   PJ: PARTIDAS JOGADAS",21,15);
	printCentralizado("APERTE [G] <---- ESTATISTICAS DOS GOLEIRO      ESTATISTICAS PRESIDENTE ----> APERTE [P]",28,15);
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
	gotoxy(119,29);
    char plv;
     do{
    	 plv = toupper(getch());
    	if(plv == 27 || plv == 'G'|| plv == 'P'){
    		break;
    	}else{
    		printCentralizado("APERTE UMA TECLA VALIDA !",29,15);
    		Sleep(850);
    		limparBufferTeclado();
    		printCentralizado("                            ",29,15);
    		gotoxy(119,29);
    	}
    	
    }while(plv != 27 && plv != 'G' && plv != 'P');
    return plv;
}
typedef struct {
    presidente p;
    char time[20];
    int gols;
    int errou;
    int cor;
    int partida;
} TopPresidente;
TopPresidente topPresidente[100];
char exibirTopPresidentes(listaDupla *inicio,int l) {
    int total = 0;
    clrscr();
    if(l == 1){
		MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);
    	printCentralizado("--- TOP 10 PRESIDENTES KL-PENALTY BRASIL---",4,14);
    }
    if(l == 2){
		MolduraColorida(1, 1, 120, 30, 4, 4, 14, 14);
    	printCentralizado("--- TOP 10 PRESIDENTES KL-PENALTY ESPANHA---",4,4);
    }
    if(l == 3){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 10, 4);
    	printCentralizado("--- TOP 10 PRESIDENTES KL-PENALTY ITALIA---",4,10);
	}
	if(l == 4){
    	MolduraColorida(1, 1, 120, 30, 15, 15, 9, 9);
    	printCentralizado("--- TOP 10 PRESIDENTES KL-PENALTY AMERICAS---",4,9);
	}
	textcolor(15);
    Moldura(27, 7, 96, 20);
	
    for (int i = 1; i <= 10; i++) {
        gotoxy(i < 10 ? 30 : 29, i + 9);
        printf("%d", i);
    }

    for (int y = 8; y <= 19; y++) {
        gotoxy(31, y); printf("%c", 186);
        gotoxy(52, y); printf("%c", 186);
        gotoxy(58, y); printf("%c", 186);
        gotoxy(64, y); printf("%c", 186);
        gotoxy(69, y); printf("%c", 186);
    }

    int x = 28;
	while(x < 96){
		gotoxy(x, 9);
		if (x != 31 || x != 51 || x != 56 || x != 61 || x != 75)
			printf("%c", 205);
		x++;
	}

    gotoxy(28, 8); printf("POS");
    gotoxy(40, 8); printf("NOME");
    gotoxy(54, 8); printf("G/F");
    gotoxy(60, 8); printf("G/P");
    gotoxy(66, 8); printf("PJ");
    gotoxy(80, 8); printf("EQUIPE");

    for (listaDupla *p = inicio; p != NULL; p = p->prox) {
        topPresidente[total].p = p->info.elenco.presida;
        strcpy(topPresidente[total].time, p->info.elenco.nomeEquipe);
        topPresidente[total].gols = p->info.elenco.presida.gols;
        topPresidente[total].errou = p->info.elenco.presida.errou;
        topPresidente[total].partida = p->info.partidas;
        topPresidente[total].cor = p->info.elenco.cor1;
        total++;
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (topPresidente[j].gols < topPresidente[j + 1].gols) {
                TopPresidente temp = topPresidente[j];
                topPresidente[j] = topPresidente[j + 1];
                topPresidente[j + 1] = temp;
            }
        }
    }

    textcolor(15);

    for (int i = 0; i < total && i < 10; i++) {
        textcolor(topPresidente[i].cor);

        int nomeX;
        int nomeLen = strlen(topPresidente[i].p.nome);
        if (nomeLen < 8) nomeX = 38;
        else if (nomeLen < 12) nomeX = 36;
        else if (nomeLen == 14) nomeX = 33;
        else nomeX = 34;

        gotoxy(nomeX, i + 10);
        printf("%s[%d]", topPresidente[i].p.nome, topPresidente[i].p.overall);

        textcolor(15);
        gotoxy(topPresidente[i].gols < 10 ? 56 : 55, i + 10);
        printf("%d", topPresidente[i].gols);

        gotoxy(topPresidente[i].errou < 10 ? 62 : 61, i + 10);
        printf("%d", topPresidente[i].errou);

        gotoxy(topPresidente[i].partida < 10 ? 67 : 66, i + 10);
        printf("%d", topPresidente[i].partida);

        textcolor(topPresidente[i].cor);

        if(strlen(topPresidente[i].time) == 5 ){
    		gotoxy(83,i+10);
    		printf("%s", topPresidente[i].time);
    	}else if(strlen( topPresidente[i].time) == 6){
	    	gotoxy(80,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 7){
	    	gotoxy(80,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 8){
	    	gotoxy(79,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 9){
	    	gotoxy(79,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 10){
	    	gotoxy(78,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 11){
	    	gotoxy(78,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 12){
	    	gotoxy(77,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 13){
	    	gotoxy(77,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 14){
	    	gotoxy(76,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 15){
	    	gotoxy(76,i+10);
    		printf("%s", topPresidente[i].time);
    	}
    	else if(strlen( topPresidente[i].time) == 16){
	    	gotoxy(75,i+10);
    		printf("%s", topPresidente[i].time);
    	}
        

        
    }

    printCentralizado("  G/F: GOLS FEITOS   G/P: GOLS PERDIDOS   PJ: PARTIDAS JOGADAS", 21, 15);
    printCentralizado("APERTE [A] <---- ESTATISTICAS DA ARTILHARIA      ESTATISTICAS GOLEIRO ----> APERTE [G]", 28, 15);

    textcolor(12);
    gotoxy(4, 3);
    printf("[ESC] VOLTAR");
    textcolor(15);
    gotoxy(119, 29);

    char plv;
    do {
        plv = toupper(getch());
        if (plv == 27 || plv == 'A' || plv == 'G') break;
        printCentralizado("APERTE UMA TECLA VALIDA !", 29, 15);
        Sleep(850);
        limparBufferTeclado();
        printCentralizado("                            ", 29, 15);
        gotoxy(119, 29);
    } while (plv != 27 && plv != 'A' && plv != 'G');

    return plv;
}

int estaEntreOsSeteMelhores(listaDupla *inicio, int codigo) {
    int contador = 0;
	if(inicio->info.partidas == 9){
	    for (listaDupla *p = inicio; p != NULL && contador < 7; p = p->prox) {
	        // Comparar pelo código (mais confiável que nome)
	        if (p->info.elenco.codigo == codigo) {
	            return 1; // Está entre os 7 melhores
	        }
	
	        contador++;
	    }
	}else{
		return 3;
	}
    return 0; // Não está entre os 7 melhores
}
int estaEntreOs10Melhores(listaDupla *inicio, int codigo) {
    int contador = 0;
	if(inicio->info.partidas == 11){
	    for (listaDupla *p = inicio; p != NULL && contador < 10; p = p->prox) {
	        // Comparar pelo código (mais confiável que nome)
	        if (p->info.elenco.codigo == codigo) {
	            return 1; // Está entre os 10 melhores
	        }
	
	        contador++;
	    }
	}else{
		return 3;
	}
    return 0; // Não está entre os 7 melhores
}
listaDupla* copiarLista(listaDupla *original) {
    if (!original) return NULL;

    listaDupla *novaLista = NULL;
    listaDupla *ultimo = NULL;

    while (original) {
        // Cria um novo nó
        listaDupla *novo = malloc(sizeof(listaDupla));
        if (!novo) return NULL;

        // Copia os dados da struct 'jogar'
        novo->info = original->info;

        // Inicializa os ponteiros
        novo->prox = NULL;
        novo->ant = ultimo;

        // Encadeia os nós
        if (!novaLista)
            novaLista = novo;
        else
            ultimo->prox = novo;

        // Avança os ponteiros
        ultimo = novo;
        original = original->prox;
    }

    return novaLista;
}
listaDupla* copiarLista2(listaDupla *original, int cod) {
    if (!original) return NULL;

    listaDupla *novaLista = NULL;
    listaDupla *ultimo = NULL;

    while (original) {
        // Ignora o time com o código igual ao informado
        if (original->info.elenco.codigo != cod) {
            // Cria um novo nó
            listaDupla *novo = malloc(sizeof(listaDupla));
            if (!novo) return NULL;

            // Copia os dados
            novo->info = original->info;

            // Inicializa os ponteiros
            novo->prox = NULL;
            novo->ant = ultimo;

            // Encadeia os nós
            if (!novaLista)
                novaLista = novo;
            else
                ultimo->prox = novo;

            // Avança o último
            ultimo = novo;
        }

        // Avança no original
        original = original->prox;
    }

    return novaLista;
}

#endif
