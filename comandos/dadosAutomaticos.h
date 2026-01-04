#ifndef DADOS_AUTOMATICOS_H
#define DADOS_AUTOMATICOS_H

#include "times.h"
/* 
	60-75 = 10k $ valor minimo possivel
	76 = 11k && 12k
	77 = 13k && 14k
	78 = 15k && 17k
	79 = 18k && 20k
	80 a 83 = 20k && 29k
	84 a 85 = 30k && 40k
	86 a 87 = 42k && 50k
	88 a 90 = 55k && 78k
	91 a 99 = 80k && 500k
	
	defesa reflexo
	90+ = 6
	89 - 86 = 5
	85 - 82 = 4
	81--   = 3

*/

void dadosAutomaticos(tree **raiz) {
	float valorMercado;
    // Fluxo
    jogador j8_1 = {"Boolt", 0, 0, 38000, 85,"ATA"};
    jogador j8_2 = {"Helber Jr", 0, 0, 35000, 84,"ATA"};
    jogador j8_3 = {"Victor Bueno", 0, 0, 21000, 80,"ATA"};
    jogador j8_4 = {"Chaveirinho", 0, 0, 28000, 82,"MEI"};
    jogador j8_5 = {"Melequinha", 0, 0, 50000, 87,"DEF"};
    goleiro g8 = {"Julio Carvalho", 0,0, 15000, 78,"GOL"};
    presidente p8 = {"Cerol", 0, 0, 85};
    valorMercado = j8_1.valor + j8_2.valor + j8_3.valor + j8_4.valor + j8_5.valor + g8.valor;
    times t8 = {5, "Fluxo FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8,4,8,valorMercado};
    insereABBrecursivo(raiz, t8);
    
    // Goti
    jogador j9_1 = {"Marcelin Jr", 0, 0, 32000, 84,"ATA"};
    jogador j9_2 = {"Luisinho Alves", 0, 0, 25000, 82,"ATA"};
    jogador j9_3 = {"Batman", 0, 0, 28000, 83,"MEI"}; 
    jogador j9_4 = {"Victor Bolt", 0, 0, 20000, 80,"MEI"};
    jogador j9_5 = {"Bernardinello", 0, 0, 15000, 78,"DEF"};
    goleiro g9 = {"Joao Pedro", 0,0, 62000, 87,"GOL"};
    presidente p9 = {"Yuri 22", 0, 0, 50};
    valorMercado = j9_1.valor + j9_2.valor + j9_3.valor + j9_4.valor + j9_5.valor + g9.valor;
    times t9 = {3, "DesimpedidosGoti", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9,2,1,valorMercado};
    insereABBrecursivo(raiz, t9);
    
    
    // Furia
    jogador j2_1 = {"Leleti", 4, 0, 140000, 94,"ATA"};
    jogador j2_2 = {"Lipao", 0, 0, 115000, 92,"ATA"};
    jogador j2_3 = {"Donato", 0, 0, 21000, 80,"ATA"};
    jogador j2_4 = {"Jefinho", 0, 0, 40000, 85,"MEI"};
    jogador j2_5 = {"Dedo", 0, 0, 40000, 84,"DEF"};
    goleiro g2 = {"Victor Hugo", 0, 0,30000, 84,"GOL"};
    presidente p2 = {"Cris Guedes", 0, 0, 76};
    valorMercado = j2_1.valor + j2_2.valor + j2_3.valor + j2_4.valor + j2_5.valor + g2.valor;
    times t2 = {7, "Furia FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2,7,15,valorMercado};
    insereABBrecursivo(raiz, t2);
	
	 // Dendele 
    jogador j6_1 = {"Canhoto", 0, 0, 38000, 85,"MEI"};
    jogador j6_2 = {"Lucas Hector", 0, 0, 78000, 89,"MEI"};
    jogador j6_3 = {"Tuco", 0, 0, 22000, 82,"MEI"};
    jogador j6_4 = {"Romarinho", 0, 0, 20000, 80,"MEI"};
    jogador j6_5 = {"Lyncoln", 0, 0, 68000, 88,"DEF"};
    goleiro g6 = {"Maikon", 0,0, 42000, 86,"GOL"};
    presidente p6 = {"LuquEt4", 0, 0, 73};
    valorMercado = j6_1.valor + j6_2.valor + j6_3.valor + j6_4.valor + j6_5.valor + g6.valor;
    times t6 = {2, "Dendele FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6,1,14,valorMercado};
    insereABBrecursivo(raiz, t6);
    
    // Real Elite
    jogador j4_1 = {"Marlon Ribas", 0, 0, 14000, 77,"ATA"};
    jogador j4_2 = {"Davi Ilario", 0, 0, 90000, 91,"MEI"};
    jogador j4_3 = {"Well", 0, 0, 26000, 82,"MEI"};
    jogador j4_4 = {"Matheus Bueno", 0, 0, 10000, 75,"MEI"};
    jogador j4_5 = {"Junin Antunes", 0, 0, 25000, 81,"MEI"};
    goleiro g4 = {"Gustavo Rocha", 0, 0,20000, 79,"GOL"};
    presidente p4 = {"Allan Stag", 0, 0, 81};
    valorMercado = j4_1.valor + j4_2.valor + j4_3.valor + j4_4.valor + j4_5.valor + g4.valor;
    times t4 = {4, "FC Real Elite", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4,13,9,valorMercado};
    insereABBrecursivo(raiz, t4);
    
    // Funk
    jogador j7_1 = {"Douglinhas", 0, 0, 78000, 90,"ATA"};
    jogador j7_2 = {"Pepinho", 0, 0, 30000, 82,"ATA"};
    jogador j7_3 = {"Betao Ribeiro", 0, 0, 33000, 84,"MEI"};
    jogador j7_4 =  {"Vitinho Ruas", 0, 0, 18000, 79,"MEI"};
    jogador j7_5 = {"MlkJhoow", 0, 0, 29000, 83,"DEF"};
    goleiro g7 = {"Gui Patrick", 0, 0,40000, 81,"GOL"};
    presidente p7 = {"MC Hariel", 0, 0, 79};
    valorMercado = j7_1.valor + j7_2.valor + j7_3.valor + j7_4.valor + j7_5.valor + g7.valor;
    times t7 = {6, "Funkbol Clube", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7,5,14,valorMercado};
    insereABBrecursivo(raiz, t7);
    
    // LOUD
    jogador j5_1 = {"Drope", 0, 0, 29000, 83,"ATA"};
    jogador j5_2 = {"Igor Rock", 0, 0, 20000, 80,"ATA"};
    jogador j5_3 = {"Lukinhas", 0, 0, 64000, 87,"MEI"};
    jogador j5_4 = {"Luca Japa", 0, 0, 22000, 81,"MEI"};
    jogador j5_5 = {"Lucas Caroco", 0, 0, 20000, 80,"MEI"};
    goleiro g5 = {"Esau", 0, 0,50000, 86,"GOL"};
    presidente p5 = {"Loud Coringa", 0, 0, 79};
	valorMercado = j5_1.valor + j5_2.valor + j5_3.valor + j5_4.valor + j5_5.valor + g5.valor;
    times t5 = {9, "LOUD SC", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5,2,10,valorMercado};
    insereABBrecursivo(raiz, t5);
    
    // Capim
    jogador j3_1 = {"Igo Caninde", 0, 0, 25000, 82,"ATA"};
    jogador j3_2 = {"Briquinho", 0, 0, 50000, 87,"ATA"};
    jogador j3_3 = {"Henry Japa", 0, 0, 22000, 80,"MEI"};
    jogador j3_4 = {"Neto Show", 0, 0, 38000, 84,"MEI"};
    jogador j3_5 = {"GB Medeiros", 0, 0, 40000, 84,"DEF"};
    goleiro g3 = {"Barata", 0,0, 78000, 88,"GOL"};
    presidente p3 = {"Jon Vlogs", 0, 0, 72};
    valorMercado = j3_1.valor + j3_2.valor + j3_3.valor + j3_4.valor + j3_5.valor + g3.valor;
    times t3 = {1, "Capim FC", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3,11,8,valorMercado};
    insereABBrecursivo(raiz, t3);
	
    // G3X
    jogador j1_1 = {"Kelvin 'K9'", 3, 0, 115000, 93,"ATA"};
    jogador j1_2 = {"Rufino", 0, 0, 54000, 86,"MEI"};
    jogador j1_3 = {"Andreas Vaz", 0, 0, 100000, 91,"MEI"};
    jogador j1_4 = {"Kenu", 0, 0, 33000, 84,"MEI"};
    jogador j1_5 = {"Wembley", 0, 0, 29000, 82,"DEF"};
    goleiro g1 = {"Igor Rezende", 0, 0,45000, 86,"GOL"};
    presidente p1 = {"Gaules", 0, 0, 74};
    valorMercado = j1_1.valor + j1_2.valor + j1_3.valor + j1_4.valor + j1_5.valor + g1.valor;
    times t1 = {8, "G3X FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1,15,14,valorMercado};
    insereABBrecursivo(raiz, t1);

    // Nyvelado{"Bruninho", 0, 0, 23200, 84,"MEI"};
    jogador j10_1 = {"Leo Gol", 0, 0, 61000, 88,"ATA"};
    jogador j10_2 = {"Bruninho", 0, 0, 40000, 84,"MEI"};
    jogador j10_3 = {"Breno Arantes", 0, 0, 29000, 83,"MEI"};
    jogador j10_4 = {"Klynsmann", 0, 0, 13000, 77,"MEI"};
    jogador j10_5 = {"Willin Jesus", 0, 0, 29000, 82,"DEF"};
    goleiro g10 = {"Ivo Alves", 0,0, 45000, 86,"GOL"};
    presidente p10 = {"Nyvi Estephan", 0, 0, 62};
    valorMercado = j10_1.valor + j10_2.valor + j10_3.valor + j10_4.valor + j10_5.valor + g10.valor;
    times t10 = {10, "Nyvelados FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10,8,15,valorMercado};
    insereABBrecursivo(raiz, t10);
}
#endif
