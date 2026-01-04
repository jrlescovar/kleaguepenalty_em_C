#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/dadosAutomaticosEspanha.h"
#include "./comandos/dadosAutomaticosItalia.h"
#include "./comandos/dadosAutomaticosAmericas.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"
#include "./comandos/ligaBrasil.h"
#include "./comandos/ligaEspanha.h"
#include "./comandos/ligaItalia.h"
#include "./comandos/ligaAmericas.h"
#include "./comandos/listaEncadeada.h"
#include "./comandos/jogoRodando.h"
#include "./comandos/cartas.h"
#include "./comandos/limpar_mensagem.h"

 
int main(void){
	srand(time(NULL));//inicializar sistema de sorteio.
	int rodada,rodadaOficial,rodadaPlayoffBrasil = 0,buscar,outrasligas = 1;
	char confirmaLocal,confirmaTime,timeConfirmado,menuSelecionado,passarPagina;
	system("mode con: cols=120 lines=30");//padronizar tela "creio eu que ta mudando nada rs"
	//LIGA BRASIL TUDO AQUI ABAIXO.
	tree *raiz = NULL; //Times Brasilerios
	tree *resultado = NULL; // times Brasilerios
	tree *moverTimesParaLista = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	// INSERIR DADOS LIGA BRASIL
	dadosAutomaticos(&raiz);
	SemanaBrasil* campeonatoBrasil = gerarPartidas();// gerar partidas  Ligas BRasil;
	listaDupla *listaBrasil = NULL; //CRIAR A LISTA PARA OS TIME BR
	listaDupla *listaTabela = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semana = malloc(sizeof(SemanaBrasil)); //buscar o jogos dessa rodada
	Confronto *confronto = malloc(sizeof(Confronto));
	//playoffsBrasil
	playoffsConfrontos *jogosQuartasBrasil;jogosQuartasBrasil= malloc(sizeof(playoffsConfrontos));//usa 1-2-3 confrontos
	playoffsConfrontos *jogosSemiBrasil;jogosSemiBrasil = malloc(sizeof(playoffsConfrontos));//usa 1-2 confrontos
	
	playoffsConfrontos *jogosBrasil; jogosBrasil= malloc(sizeof(playoffsConfrontos));
	
	
	//LIGA ESPANHA ABAIXO.
	tree *raizEspanha = NULL; //Times 
	tree *resultadoEspanha = NULL; // times 
	tree *moverTimesParaListaEspanha = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosEspanha(&raizEspanha);
	SemanaBrasil* campeonatoEspanha = gerarPartidasEspanha();// gerar partidas  Ligas 
	listaDupla *listaEspanha = NULL; //CRIAR A LISTA PARA OS TIME 
	listaDupla *listaTabelaEspanha = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaEspanha  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoEspanha = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosEspanha; jogosEspanha= malloc(sizeof(playoffsConfrontos));
	//liga Italia.
	tree *raizItalia = NULL; //Times 
	tree *resultadoItalia = NULL; // times 
	tree *moverTimesParaListaItalia = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosItalia(&raizItalia);
	SemanaBrasil* campeonatoItalia = gerarPartidasItalia();// gerar partidas  Ligas 
	listaDupla *listaItalia = NULL; //CRIAR A LISTA PARA OS TIME 
	listaDupla *listaTabelaItalia = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaItalia  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoItalia = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosItalia; jogosItalia= malloc(sizeof(playoffsConfrontos));
	
	//liga americas ABAIXO
	tree *raizAmericas = NULL; //Times
	tree *resultadoAmericas = NULL; // times 
	tree *moverTimesParaListaAmericas = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosAmericas(&raizAmericas);
	SemanaBrasil* campeonatoAmericas = gerarPartidasAmericas();// gerar partidas  Ligas BRasil;
	listaDupla *listaAmericas = NULL; //CRIAR A LISTA PARA OS
	listaDupla *listaTabelaAmericas = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaAmericas  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoAmericas = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosAmericas; jogosAmericas= malloc(sizeof(playoffsConfrontos));

	
	int desbugarplayoff = 1;
	tela1(); //tela de abertura apenas.
	system("cls");
	
	while (kbhit()) { //caso seleciona 1 e ao mesmo tempo aperte outras teclas
        getch();  // Descarta as teclas pendentes na fila de entrada
    }
    
    //jogo começa aqui " "
	do {
	    fflush(stdin);
	    confirmaLocal = tela2(); // TELA DE CONFIRMAR NACIONALIDADE "selecionar se vai jogar na liga do brasil, espanha etc...
	    limparBufferTeclado();
	    if (confirmaLocal == 27) { 
	        break; // Sai do loop sem mostrar mensagem
	    }
	    switch (confirmaLocal) { 
	        case '1'://escolheu liga brasil
	           do {
				    confirmaTime = telaBrasil();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
				
				
				    if (confirmaTime >= '0' && confirmaTime <= '9') {  //TECLA DE 0 a 10 for apertada
				        buscar = confirmaTime - '0';
				
				        // Se o código for 0, muda para 10
				        if (buscar == 0) {
				            buscar = 10;  // Muda o ID para 10 quando escolher '0'
				        }
				        resultado = buscaPorCodigo(raiz, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultado,"KL PENALTY - BRASIL",14,2,2,14,14,1);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
				            	int x = 1; //dados brasil
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
								x = 1; //dados espanha para simulação
								while( x <= 12){
									moverTimesParaListaEspanha = buscaPorCodigo(raizEspanha, x);
									inserirLista(&listaEspanha, moverTimesParaListaEspanha);
									moverTimesParaListaItalia = buscaPorCodigo(raizItalia, x);
									inserirLista(&listaItalia, moverTimesParaListaItalia);
									moverTimesParaListaAmericas = buscaPorCodigo(raizAmericas, x);
									inserirLista(&listaAmericas, moverTimesParaListaAmericas);
									x++;
									
								}
				            	rodada = 1;
				                do{
				                	//criarQuartas
				                	if(rodadaOficial == 10){
				                		listaTabela = copiarLista(listaBrasil);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffBrasil(&jogosBrasil,listaBrasil,1);
				                	}
				                	//criarSemiFinal
				                	if(rodadaOficial == 11){
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,2);
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,4);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,4);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,4);
				                	}
				                	//criarFinak
									if(rodadaOficial == 12){
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,3);
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,5);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,5);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,5);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOsSeteMelhores(listaBrasil,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaBrasil(listaBrasil,listaTabela,buscar,campeonatoBrasil,rodada,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
				                			if(rodadaOficial <= 9){
				                				semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
				                				
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
				                				
												semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												rodadaOficial++;
				                				
				                				if(rodadaOficial == 10){
				                					semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
													confrontoEspanha = semanaEspanha->primeiroConfronto;
													do{
														jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
														confrontoEspanha = confrontoEspanha->prox;
													}while(confrontoEspanha != NULL);
													
													semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoEspanha = semanaEspanha->primeiroConfronto;
													do{
														jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
														confrontoEspanha = confrontoEspanha->prox;
													}while(confrontoEspanha != NULL);
													
													
													semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
													confrontoItalia = semanaItalia->primeiroConfronto;
													do{
														jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
														confrontoItalia = confrontoItalia->prox;
													}while(confrontoItalia != NULL);
													
													
													semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoItalia = semanaItalia->primeiroConfronto;
													do{
														jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
														confrontoItalia = confrontoItalia->prox;
													}while(confrontoItalia != NULL);
													
													semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
													confrontoAmericas = semanaAmericas->primeiroConfronto;
													do{
														jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
														confrontoAmericas = confrontoAmericas->prox;
													}while(confrontoAmericas != NULL);
													
													semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoAmericas = semanaAmericas->primeiroConfronto;
													do{
														jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
														confrontoAmericas = confrontoAmericas->prox;
													}while(confrontoAmericas != NULL);
													
													listaTabelaEspanha = copiarLista(listaEspanha);
													criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
													
													listaTabelaItalia = copiarLista(listaItalia);
													criarPlayoffItalia(&jogosItalia,listaItalia,1);
													
													listaTabelaAmericas = copiarLista(listaAmericas);
													criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
													
													if(desbugarplayoff == 1){
														jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin2Confronto,1);
														criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
														jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin3Confronto,1);
														criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
														
														jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin2Confronto,1);
														criarPlayoffItalia(&jogosItalia,listaItalia,2);
														jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin3Confronto,1);
														criarPlayoffItalia(&jogosItalia,listaItalia,3);
														
														jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin2Confronto,1);
														criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
														jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin3Confronto,1);
														criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
														
														
														desbugarplayoff = 0;
													}
													
				                				}
				                				
												if(rodadaOficial != 10)//chegar em 10 para para nao exibir vento...
				                					rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                				break;	
				                			}
				                			
				                			if(rodadaOficial >= 10 && rodadaOficial < 13){
				                				if(rodadaOficial == 10){
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q3Confronto,1);
					                				//simula outras ligas;
				                					
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q3Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q3Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q3Confronto,1);
				                					
					                			}
					                			
					                			if(rodadaOficial == 11){
					                				
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->s2Confronto,1);
				                					
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->s2Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->s2Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->s2Confronto,1);
					             					
					                			}
					                			
					                			if(rodadaOficial == 12){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->finalConfronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->finalConfronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->finalConfronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->finalConfronto,1);
					                			}
					                			rodadaOficial++;
				                			}
				                			
 				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 9){
				                				semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,0,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
												
												
												semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
												
												semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaItalia = semanaItalia->prox;
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												semanaAmericas = semanaAmericas->prox;
												rodadaOficial++;
																                				
				                				if(rodadaOficial == 10){
				                					semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
													confrontoEspanha = semanaEspanha->primeiroConfronto;
													do{
														jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
														confrontoEspanha = confrontoEspanha->prox;
													}while(confrontoEspanha != NULL);
													
													semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoEspanha = semanaEspanha->primeiroConfronto;
													do{
														jogarConfronto(&listaEspanha,resultado,&confrontoEspanha,1,2);
														confrontoEspanha = confrontoEspanha->prox;
													}while(confrontoEspanha != NULL);
													
													semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
													confrontoItalia = semanaItalia->primeiroConfronto;
													do{
														jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
														confrontoItalia = confrontoItalia->prox;
													}while(confrontoItalia != NULL);
													
													
													semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoItalia = semanaItalia->primeiroConfronto;
													do{
														jogarConfronto(&listaItalia,resultado,&confrontoItalia,1,2);
														confrontoItalia = confrontoItalia->prox;
													}while(confrontoItalia != NULL);
													
													semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
													confrontoAmericas = semanaAmericas->primeiroConfronto;
													do{
														jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
														confrontoAmericas = confrontoAmericas->prox;
													}while(confrontoAmericas != NULL);
													
													semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial+1); //buscar o jogos dessa rodada
													confrontoAmericas = semanaAmericas->primeiroConfronto;
													do{
														jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,2);
														confrontoAmericas = confrontoAmericas->prox;
													}while(confrontoAmericas != NULL);
													
													
													listaTabelaEspanha = copiarLista(listaEspanha);
													criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
													
													listaTabelaItalia = copiarLista(listaItalia);
													criarPlayoffItalia(&jogosItalia,listaItalia,1);
													
													listaTabelaAmericas = copiarLista(listaAmericas);
													criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
													
													if(desbugarplayoff == 1){
														jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin2Confronto,1);
														criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
														jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->playin3Confronto,1);
														criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
														
														jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin2Confronto,1);
														criarPlayoffItalia(&jogosItalia,listaItalia,2);
														jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->playin3Confronto,1);
														criarPlayoffItalia(&jogosItalia,listaItalia,3);
														
														jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin1Confronto,1);
								                		jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin2Confronto,1);
														criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
														jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->playin3Confronto,1);
														criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
														
														
														desbugarplayoff = 0;
													}
													
				                				}
				                				if(rodadaOficial != 10)//chegar em 10 para para nao exibir vento...
				                					rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                				break;	
				                			}//mudar a pagina da rodada para a proxima;
				                			//PlayOffs
				                			if(rodadaOficial >= 10 && rodadaOficial < 13){
				                				if(rodadaOficial == 10){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q1Confronto,0);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q2Confronto,0);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->q3Confronto,0);
					                				//simula outros dados de outras liga.
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->q3Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->q3Confronto,1);
				                					
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q1Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q2Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->q3Confronto,1);
					                			}
					                			
					                			if(rodadaOficial == 11){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->s1Confronto,0);
				                					jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->s2Confronto,0);
					                				//simula outros dados de outras liga.
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->s2Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->s2Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->s1Confronto,1);
				                					jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->s2Confronto,1);
					             
					                			}
					                			
					                			if(rodadaOficial == 12){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosBrasil->finalConfronto,0);
					                				jogarConfrontoPlayoff(&listaEspanha,resultado,&jogosEspanha->finalConfronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultado,&jogosItalia->finalConfronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultado,&jogosAmericas->finalConfronto,1);
					                			}
					                			rodadaOficial++;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=10){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsBrasil(rodadaOficial, listaBrasil, jogosBrasil,rodadaOficial - 9);
				                				}
												if(rodadaOficial <10){
											        gotoxy(39, 19);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 10 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaBrasil,resultado,1);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaBrasil,1);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaBrasil,1);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaBrasil,1);
				                				}
				                			}while(passarPagina != 27);
				                		break;
				                		case 'N':
				                			if(rodada != 1){
				                				
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 9){
				                				rodada++;
				                			}
				                		break;
				                		case 'L':
				                				outrasligas = 1;
				                				do{
				                					if(outrasligas == 1){
				                						outrasligas = exibeLigaEspanha(listaEspanha,listaTabelaEspanha,campeonatoEspanha,rodada,rodadaOficial,outrasligas,jogosEspanha,1);
				                					}
				                					if(outrasligas == 2){
				                						outrasligas = exibeLigaItalia(listaItalia,listaTabelaItalia,campeonatoItalia,rodada,rodadaOficial,outrasligas,jogosItalia,1);
				                					}
				                					if(outrasligas == 3){
				                						outrasligas = exibeLigaAmericas(listaAmericas,listaTabelaAmericas,campeonatoAmericas,rodada,rodadaOficial,outrasligas,jogosAmericas,1);
				                					}
				                					if(outrasligas == 5)
				                						break;
				                				}while(1);
				                		break;
				                		case 'G':
				                			exibirEstatisticaTime(listaBrasil,10,1);
				                		break;
				                		case 'T':
				                			marketplace(&listaBrasil,resultado,&listaEspanha,&listaItalia,&listaAmericas,rodadaOficial,1);
				                		break;
				                		default:
				                				if(menuSelecionado == 27)
				                					menuSelecionado = 'o';
				                			break;
				                			
				                	}
				                }while(menuSelecionado != 27);
				                
				            }
				            else if (timeConfirmado != 27){//Se aperta tecla errada exibe msg, aperta ESC fecha o JOGO
				                teclaInvalida();
				        	}
				        } while (timeConfirmado != 27);
				    }
				
				} while (confirmaTime != 27);
	        break;
	            
			case '2':
				do {
				    confirmaTime = telaEspanha();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
					
				    if ((confirmaTime >= '0' && confirmaTime <= '9') || confirmaTime == 'W' || confirmaTime == 'E') {  // TECLA DE 0 a 9 ou W/E
					    buscar = confirmaTime - '0';
					
					    // Se o código for 0, muda para 10
					    if (buscar == 0) {
					        buscar = 10;  // Muda o ID para 10 quando escolher '0'
					    }
					    if (confirmaTime == 'W') {
					        buscar = 11;  // Muda o ID para 11 quando escolher 'W'
					    }
					    if (confirmaTime == 'E') {
					        buscar = 12;  // Muda o ID para 12 quando escolher 'E'
					    }
				        resultadoEspanha = buscaPorCodigo(raizEspanha, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoEspanha,"KL PENALTY - ESPANHA",4,4,4,14,14,2);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
								int x = 1; //dados brasil
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
								x = 1; //dados espanha para simulação e outros.
								while( x <= 12){
									moverTimesParaListaEspanha = buscaPorCodigo(raizEspanha, x);
									inserirLista(&listaEspanha, moverTimesParaListaEspanha);
									moverTimesParaListaItalia = buscaPorCodigo(raizItalia, x);
									inserirLista(&listaItalia, moverTimesParaListaItalia);
									moverTimesParaListaAmericas = buscaPorCodigo(raizAmericas, x);
									inserirLista(&listaAmericas, moverTimesParaListaAmericas);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	if(rodadaOficial == 10){
				                		listaTabela = copiarLista(listaBrasil);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffBrasil(&jogosBrasil,listaBrasil,1);
				                	}
				                	if(rodadaOficial == 12){
				                		listaTabelaEspanha = copiarLista(listaEspanha);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
										listaTabelaItalia = copiarLista(listaItalia);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffItalia(&jogosItalia,listaItalia,1);
										listaTabelaAmericas = copiarLista(listaAmericas);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,2);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,3);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,4);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,4);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,4);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,2);
				                
									}
				                	if(rodadaOficial == 16){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,5);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,5);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,5);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,3);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaEspanha,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaEspanha(listaEspanha,listaTabelaEspanha,buscar,campeonatoEspanha,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);
											if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultadoEspanha,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
											}                			
				                			if(rodadaOficial < 12){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoEspanha,&confrontoItalia,1,2);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoEspanha,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												rodadaOficial++;
												
				                				
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosEspanha->playin1Confronto && jogosEspanha->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin2Confronto,1);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 11){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,0,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												
												semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial);
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoEspanha,&confrontoItalia,1,2);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoEspanha,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												
				                			}
				                			if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultadoEspanha,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
											}  
				                			if(rodadaOficial < 12)
				                				rodadaOficial++;
				                			
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;//mudar a pagina da rodada para a proxima;
												break; 
											}
											
				                			if(rodadaOficial == 12){
			                					if (jogosEspanha->playin1Confronto && jogosEspanha->playin2Confronto){
			                						
			                						jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin2Confronto,0);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin2Confronto,1);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin3Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q3Confronto,0);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->q3Confronto,1);
				                					
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s2Confronto,0);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->finalConfronto,0);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoEspanha,&jogosBrasil->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoEspanha,&jogosItalia->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoEspanha,&jogosAmericas->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsEspanha(rodadaOficial, listaEspanha, jogosEspanha,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaEspanha,resultadoEspanha,2);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaEspanha,2);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaEspanha,2);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaEspanha,2);
				                				}
				                			}while(passarPagina != 27);
				                		break;
				                		case 'N':
				                			if(rodada != 1){
				                				
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 11){
				                				rodada++;
				                			}
				                		break;
				                		case 'L':
				                				outrasligas = 1;
				                				do{
				                					if(outrasligas == 1){
				                						outrasligas = exibeLigaBrasil(listaBrasil,listaTabela,campeonatoBrasil,rodada,rodadaOficial,outrasligas,jogosBrasil,1);
				                					}
				                					if(outrasligas == 2){
				                						outrasligas = exibeLigaItalia(listaItalia,listaTabelaItalia,campeonatoItalia,rodada,rodadaOficial,outrasligas,jogosItalia,2);
				                					}
				                					if(outrasligas == 3){
				                						outrasligas = exibeLigaAmericas(listaAmericas,listaTabelaAmericas,campeonatoAmericas,rodada,rodadaOficial,outrasligas,jogosAmericas,2);
				                					}
				                					if(outrasligas == 5)
				                						break;
				                				}while(1);
				                		break;
				                		case 'G':
				                			exibirEstatisticaTime(listaEspanha,12,2);
				                		break;
				                		default:
				                			if(menuSelecionado == 27)
				                				menuSelecionado = 'o';
				                		break;
				                			
				                	}
				                }while(menuSelecionado != 27);
				                
				            }
				            else if (timeConfirmado != 27){//Se aperta tecla errada exibe msg, aperta ESC fecha o JOGO
				                teclaInvalida();
				        	}
				        } while (timeConfirmado != 27);
				    }
					
				} while (confirmaTime != 27); 
			break;
			case '4':
				do {
				    confirmaTime = telaItalia();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
					
				    if ((confirmaTime >= '0' && confirmaTime <= '9') || confirmaTime == 'W' || confirmaTime == 'E') {  // TECLA DE 0 a 9 ou W/E
					    buscar = confirmaTime - '0';
					
					    // Se o código for 0, muda para 10
					    if (buscar == 0) {
					        buscar = 10;  // Muda o ID para 10 quando escolher '0'
					    }
					    if (confirmaTime == 'W') {
					        buscar = 11;  // Muda o ID para 11 quando escolher 'W'
					    }
					    if (confirmaTime == 'E') {
					        buscar = 12;  // Muda o ID para 12 quando escolher 'E'
					    }
				        resultadoItalia = buscaPorCodigo(raizItalia, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoItalia,"KL PENALTY - ITALIA",10,15,15,10,4,3);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
				            	int x = 1; //dados brasil
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
								x = 1; //dados espanha para simulação e outros.
								while( x <= 12){
									moverTimesParaListaEspanha = buscaPorCodigo(raizEspanha, x);
									inserirLista(&listaEspanha, moverTimesParaListaEspanha);
									moverTimesParaListaItalia = buscaPorCodigo(raizItalia, x);
									inserirLista(&listaItalia, moverTimesParaListaItalia);
									moverTimesParaListaAmericas = buscaPorCodigo(raizAmericas, x);
									inserirLista(&listaAmericas, moverTimesParaListaAmericas);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	if(rodadaOficial == 10){
				                		listaTabela = copiarLista(listaBrasil);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffBrasil(&jogosBrasil,listaBrasil,1);
				                	}
				                	//criarPlayin
				                	if(rodadaOficial == 12){
				                		listaTabelaEspanha = copiarLista(listaEspanha);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
										listaTabelaItalia = copiarLista(listaItalia);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffItalia(&jogosItalia,listaItalia,1);
										listaTabelaAmericas = copiarLista(listaAmericas);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,2);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,3);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,4);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,4);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,4);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,2);
				                
									}
				                	if(rodadaOficial == 16){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,5);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,5);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,5);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,3);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaItalia,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaItalia(listaItalia,listaTabelaItalia,buscar,campeonatoItalia,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);
											if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultadoItalia,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
												semana = semana->prox;
											}  	                			
				                			if(rodadaOficial < 12){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoItalia,&confrontoItalia,1,3);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaItalia = semanaItalia->prox;
												semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoItalia,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoItalia,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												semanaAmericas = semanaAmericas->prox;
				                				
												rodadaOficial++;	
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosItalia->playin1Confronto && jogosItalia->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin2Confronto,1);
													jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin2Confronto,1);
													rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J': 
				                			if(rodadaOficial <= 11){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoItalia,&confrontoItalia,0,3);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoItalia,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoItalia,&confrontoAmericas,1,2);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
				                			}
				                			if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultadoItalia,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
											} 
				                			if(rodadaOficial < 12)
				                				rodadaOficial++;
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;
												break; //mudar a pagina da rodada para a proxima;
											}
				                			if(rodadaOficial == 12){
			                					if (jogosItalia->playin1Confronto && jogosItalia->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin2Confronto,0);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin2Confronto,1);
													jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin2Confronto,1);
													rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin3Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q3Confronto,0);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s2Confronto,0);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->finalConfronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoItalia,&jogosEspanha->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoItalia,&jogosAmericas->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoItalia,&jogosBrasil->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsItalia(rodadaOficial, listaItalia, jogosItalia,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaItalia,resultadoItalia,3);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaItalia,3);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaItalia,3);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaItalia,3);
				                				}
				                			}while(passarPagina != 27);
				                		break;
				                		case 'N':
				                			if(rodada != 1){
				                				
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 11){
				                				rodada++;
				                			}
				                		break;
				                		case 'L':
				                				outrasligas = 1;
				                				do{
				                					if(outrasligas == 1){
				                						outrasligas = exibeLigaEspanha(listaEspanha,listaTabelaEspanha,campeonatoEspanha,rodada,rodadaOficial,outrasligas,jogosEspanha,2);
				                					}
				                					if(outrasligas == 2){
				                						outrasligas = exibeLigaBrasil(listaBrasil,listaTabela,campeonatoBrasil,rodada,rodadaOficial,outrasligas,jogosBrasil,1);
				                					}
				                					if(outrasligas == 3){
				                						outrasligas = exibeLigaAmericas(listaAmericas,listaTabelaAmericas,campeonatoAmericas,rodada,rodadaOficial,outrasligas,jogosAmericas,2);
				                					}
				                					if(outrasligas == 5)
				                						break;
				                				}while(1);
				                		break;
				                		case 'G':
				                			exibirEstatisticaTime(listaItalia,12,3);
				                		break;
				                		default:
				                			if(menuSelecionado == 27)
				                				menuSelecionado = 'o';
				                			break;
				                			
				                	}
				                }while(menuSelecionado != 27);
				                
				            }
				            else if (timeConfirmado != 27){//Se aperta tecla errada exibe msg, aperta ESC fecha o JOGO
				                teclaInvalida();
				        	}
				        } while (timeConfirmado != 27);
				    }
					
				} while (confirmaTime != 27); 
			break;
			case '3':
				do {
				    confirmaTime = telaAmericas();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
					
				    if ((confirmaTime >= '0' && confirmaTime <= '9') || confirmaTime == 'W' || confirmaTime == 'E') {  // TECLA DE 0 a 9 ou W/E
					    buscar = confirmaTime - '0';
					
					    // Se o código for 0, muda para 10
					    if (buscar == 0) {
					        buscar = 10;  // Muda o ID para 10 quando escolher '0'
					    }
					    if (confirmaTime == 'W') {
					        buscar = 11;  // Muda o ID para 11 quando escolher 'W'
					    }
					    if (confirmaTime == 'E') {
					        buscar = 12;  // Muda o ID para 12 quando escolher 'E'
					    }
				        resultadoAmericas = buscaPorCodigo(raizAmericas, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoAmericas,"KL PENALTY - AMERICAS",9,15,15,9,9,4);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
				            	int x = 1; //dados brasil
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
								x = 1; //dados espanha para simulação e outros.
								while( x <= 12){
									moverTimesParaListaEspanha = buscaPorCodigo(raizEspanha, x);
									inserirLista(&listaEspanha, moverTimesParaListaEspanha);
									moverTimesParaListaItalia = buscaPorCodigo(raizItalia, x);
									inserirLista(&listaItalia, moverTimesParaListaItalia);
									moverTimesParaListaAmericas = buscaPorCodigo(raizAmericas, x);
									inserirLista(&listaAmericas, moverTimesParaListaAmericas);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	if(rodadaOficial == 10){
				                		listaTabela = copiarLista(listaBrasil);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffBrasil(&jogosBrasil,listaBrasil,1);
				                	}
				                	//criarPlayin
				                	if(rodadaOficial == 12){
				                		listaTabelaEspanha = copiarLista(listaEspanha);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
										listaTabelaItalia = copiarLista(listaItalia);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffItalia(&jogosItalia,listaItalia,1);
										listaTabelaAmericas = copiarLista(listaAmericas);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,2);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,3);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,4);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,4);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,4);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,2);
				                
									}
				                	if(rodadaOficial == 16){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,5);
				                		criarPlayoffItalia(&jogosItalia,listaItalia,5);
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,5);
				                		criarPlayoffBrasil(&jogosBrasil,listaBrasil,3);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaAmericas,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaAmericas(listaAmericas,listaTabelaAmericas,buscar,campeonatoAmericas,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);
											if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,1,4);
													confronto = confronto->prox;
												}while(confronto != NULL);
											}  	                			
				                			if(rodadaOficial < 12){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoItalia,&confrontoItalia,1,4);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												
												semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,1,4);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultado,&confrontoAmericas,1,4);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
				                				
												rodadaOficial++;	
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosAmericas->playin1Confronto && jogosAmericas->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin2Confronto,1);
													jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin2Confronto,1);
													rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J':  
				                			if(rodadaOficial <= 11){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoAmericas,&confrontoItalia,1,3);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoAmericas,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoAmericas,&confrontoAmericas,0,4);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
				                			}
				                			if(rodadaOficial < 10){
												semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultadoAmericas,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
											}
				                			if(rodadaOficial < 12)
				                				rodadaOficial++;
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;
												break; //mudar a pagina da rodada para a proxima;
											}
				                			if(rodadaOficial == 12){
			                					if (jogosAmericas->playin1Confronto && jogosAmericas->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin2Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin2Confronto,1);
													jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin2Confronto,0);
													rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->playin3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin3Confronto,0);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->q3Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q3Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->s2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s2Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
	          	                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->finalConfronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoAmericas,&jogosItalia->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoAmericas,&jogosEspanha->finalConfronto,1);
				                				jogarConfrontoPlayoff(&listaBrasil,resultadoAmericas,&jogosBrasil->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsAmericas(rodadaOficial, listaAmericas, jogosAmericas,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaAmericas,resultadoAmericas,4);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaAmericas,4);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaAmericas,4);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaAmericas,4);
				                				}
				                			}while(passarPagina != 27);
				                		break;
				                		case 'N':
				                			if(rodada != 1){
				                				
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 11){
				                				rodada++;
				                			}
				                		break;
				                		case 'L':
				                				outrasligas = 1;
				                				do{
				                					if(outrasligas == 1){
				                						outrasligas = exibeLigaEspanha(listaEspanha,listaTabelaEspanha,campeonatoEspanha,rodada,rodadaOficial,outrasligas,jogosEspanha,2);
				                					}
				                					if(outrasligas == 2){
				                						outrasligas = exibeLigaBrasil(listaBrasil,listaTabela,campeonatoBrasil,rodada,rodadaOficial,outrasligas,jogosBrasil,1);
				                					}
				                					if(outrasligas == 3){
				                						outrasligas = exibeLigaItalia(listaItalia,listaTabelaItalia,campeonatoItalia,rodada,rodadaOficial,outrasligas,jogosItalia,2);
				                					}
				                					if(outrasligas == 5)
				                						break;
				                				}while(1);
				                		break;
				                		case 'G':
				                			exibirEstatisticaTime(listaAmericas,12,4);
				                		break;
				                		default:
				                			if(menuSelecionado == 27)
				                				menuSelecionado = 'o';
				                			break;
				                			
				                	}
				                }while(menuSelecionado != 27);       
				            }else if (timeConfirmado != 27){//Se aperta tecla errada exibe msg, aperta ESC fecha o JOGO
				                teclaInvalida();
				        	}
				        } while (timeConfirmado != 27);
				    }
					
				}while (confirmaTime != 27); 
			break;
	        default:
	            if (confirmaLocal != '\n' && confirmaLocal != 0) {
	                teclaInvalida();//mensagem de tecla invalida...
	            }
	            break;
	    }
	} while(confirmaLocal != 27); //nao escolheu nada e apertou esc fecha o jogo.

	clrscr();
    printf("\nEntrar Tela de Encerramento aqui.");
	return 0; // FIM
}
