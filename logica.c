#include <stdio.h>
#include <string.h>

// Função para exibir menu de atributos (dinâmico)
void exibirMenu(int primeiraEscolha) {
    printf("========================================\n");
    printf("🎮 ESCOLHA O ATRIBUTO PARA COMPARAÇÃO\n");
    printf("========================================\n");
    
    if (primeiraEscolha != 1) printf("1. População\n");
    if (primeiraEscolha != 2) printf("2. Área\n");
    if (primeiraEscolha != 3) printf("3. PIB\n");
    if (primeiraEscolha != 4) printf("4. Pontos Turísticos\n");
    if (primeiraEscolha != 5) printf("5. Densidade Populacional\n");
    if (primeiraEscolha != 6) printf("6. PIB per Capita\n");
    
    printf("========================================\n");
    printf("Digite sua opção: ");
}

// Função para obter nome do atributo
char* obterNomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Atributo Inválido";
    }
}

// Função para obter valor do atributo
float obterValorAtributo(int opcao, unsigned long int pop, float area, float pib, int pontos, float densidade, float pibPerCapita) {
    switch(opcao) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        case 6: return pibPerCapita;
        default: return 0.0;
    }
}

// Função para obter unidade do atributo
char* obterUnidadeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "habitantes";
        case 2: return "km²";
        case 3: return "bilhões de reais";
        case 4: return "pontos turísticos";
        case 5: return "hab/km²";
        case 6: return "reais";
        default: return "";
    }
}

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[10];
    char nomeCidade1[100];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    
    // Variáveis para a Carta 2
    char estado2;
    char codigo2[10];
    char nomeCidade2[100];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    
    // Variáveis para o menu e comparação
    int primeiroAtributo, segundoAtributo;
    float valor1_attr1, valor1_attr2, valor2_attr1, valor2_attr2;
    float soma1, soma2;
    int vencedor1, vencedor2;
    
    printf("=== SISTEMA SUPER TRUNFO - BATALHA DUPLA DE PAÍSES ===\n");
    printf("Digite as informações para cadastrar duas cartas:\n\n");
    
    // ========== CADASTRO DA CARTA 1 ==========
    printf("--- CARTA 1 ---\n");
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o nome da cidade/país: ");
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);
    
    printf("\n");
    
    // ========== CADASTRO DA CARTA 2 ==========
    printf("--- CARTA 2 ---\n");
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o nome da cidade/país: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    printf("\n");
    
    // ========== CÁLCULOS DAS PROPRIEDADES ==========
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    
    // ========== EXIBIÇÃO DAS CARTAS ==========
    printf("========================================\n");
    printf("CARTAS CADASTRADAS COM SUCESSO!\n");
    printf("========================================\n\n");
    
    printf("📋 CARTA 1: %s (%c)\n", nomeCidade1, estado1);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões\n", populacao1, area1, pib1);
    printf("Pontos Turísticos: %d | Densidade: %.2f hab/km² | PIB per Capita: %.2f reais\n\n", pontosTuristicos1, densidadePopulacional1, pibPerCapita1);
    
    printf("📋 CARTA 2: %s (%c)\n", nomeCidade2, estado2);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões\n", populacao2, area2, pib2);
    printf("Pontos Turísticos: %d | Densidade: %.2f hab/km² | PIB per Capita: %.2f reais\n\n", pontosTuristicos2, densidadePopulacional2, pibPerCapita2);
    
    // ========== ESCOLHA DO PRIMEIRO ATRIBUTO ==========
    printf("🎯 ESCOLHA O PRIMEIRO ATRIBUTO:\n");
    exibirMenu(0);  // 0 significa que nenhum atributo foi escolhido ainda
    scanf("%d", &primeiroAtributo);
    
    // Validação da primeira escolha
    while(primeiroAtributo < 1 || primeiroAtributo > 6) {
        printf("❌ Opção inválida! Escolha entre 1 e 6: ");
        scanf("%d", &primeiroAtributo);
    }
    
    printf("✅ Primeiro atributo escolhido: %s\n\n", obterNomeAtributo(primeiroAtributo));
    
    // ========== ESCOLHA DO SEGUNDO ATRIBUTO (MENU DINÂMICO) ==========
    printf("🎯 ESCOLHA O SEGUNDO ATRIBUTO:\n");
    exibirMenu(primeiroAtributo);  // Menu dinâmico excluindo a primeira escolha
    scanf("%d", &segundoAtributo);
    
    // Validação da segunda escolha
    while(segundoAtributo < 1 || segundoAtributo > 6 || segundoAtributo == primeiroAtributo) {
        if(segundoAtributo == primeiroAtributo) {
            printf("❌ Você já escolheu esse atributo! Escolha outro: ");
        } else {
            printf("❌ Opção inválida! Escolha uma opção válida: ");
        }
        scanf("%d", &segundoAtributo);
    }
    
    printf("✅ Segundo atributo escolhido: %s\n\n", obterNomeAtributo(segundoAtributo));
    
    // ========== OBTER VALORES DOS ATRIBUTOS ==========
    valor1_attr1 = obterValorAtributo(primeiroAtributo, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1);
    valor1_attr2 = obterValorAtributo(segundoAtributo, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1);
    
    valor2_attr1 = obterValorAtributo(primeiroAtributo, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2);
    valor2_attr2 = obterValorAtributo(segundoAtributo, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2);
    
    // ========== COMPARAÇÃO INDIVIDUAL DOS ATRIBUTOS ==========
    printf("========================================\n");
    printf("⚔️ BATALHA DUPLA - COMPARAÇÃO DETALHADA\n");
    printf("========================================\n\n");
    
    // Comparação do primeiro atributo
    printf("🥊 ROUND 1 - %s:\n", obterNomeAtributo(primeiroAtributo));
    printf("Carta 1 (%s): %.2f %s\n", nomeCidade1, valor1_attr1, obterUnidadeAtributo(primeiroAtributo));
    printf("Carta 2 (%s): %.2f %s\n", nomeCidade2, valor2_attr1, obterUnidadeAtributo(primeiroAtributo));
    
    // Lógica de comparação com operador ternário (considerando densidade populacional)
    if(primeiroAtributo == 5) { // Densidade populacional - menor vence
        vencedor1 = (valor1_attr1 < valor2_attr1) ? 1 : (valor2_attr1 < valor1_attr1) ? 2 : 0;
        printf("⚠️ Regra especial: Menor densidade vence!\n");
    } else { // Outros atributos - maior vence
        vencedor1 = (valor1_attr1 > valor2_attr1) ? 1 : (valor2_attr1 > valor1_attr1) ? 2 : 0;
    }
    
    printf("🏆 Vencedor Round 1: %s\n\n", 
           vencedor1 == 1 ? nomeCidade1 : vencedor1 == 2 ? nomeCidade2 : "Empate");
    
    // Comparação do segundo atributo
    printf("🥊 ROUND 2 - %s:\n", obterNomeAtributo(segundoAtributo));
    printf("Carta 1 (%s): %.2f %s\n", nomeCidade1, valor1_attr2, obterUnidadeAtributo(segundoAtributo));
    printf("Carta 2 (%s): %.2f %s\n", nomeCidade2, valor2_attr2, obterUnidadeAtributo(segundoAtributo));
    
    // Lógica de comparação com operador ternário (considerando densidade populacional)
    if(segundoAtributo == 5) { // Densidade populacional - menor vence
        vencedor2 = (valor1_attr2 < valor2_attr2) ? 1 : (valor2_attr2 < valor1_attr2) ? 2 : 0;
        printf("⚠️ Regra especial: Menor densidade vence!\n");
    } else { // Outros atributos - maior vence
        vencedor2 = (valor1_attr2 > valor2_attr2) ? 1 : (valor2_attr2 > valor1_attr2) ? 2 : 0;
    }
    
    printf("🏆 Vencedor Round 2: %s\n\n", 
           vencedor2 == 1 ? nomeCidade1 : vencedor2 == 2 ? nomeCidade2 : "Empate");
    
    // ========== CÁLCULO DA SOMA E RESULTADO FINAL ==========
    soma1 = valor1_attr1 + valor1_attr2;
    soma2 = valor2_attr1 + valor2_attr2;
    
    printf("========================================\n");
    printf("🏁 RESULTADO FINAL - SOMA DOS ATRIBUTOS\n");
    printf("========================================\n");
    printf("Carta 1 (%s): %.2f + %.2f = %.2f\n", nomeCidade1, valor1_attr1, valor1_attr2, soma1);
    printf("Carta 2 (%s): %.2f + %.2f = %.2f\n", nomeCidade2, valor2_attr1, valor2_attr2, soma2);
    printf("\n");
    
    // Resultado final usando operador ternário
    printf("🏆 CAMPEÃO GERAL: %s\n", 
           soma1 > soma2 ? nomeCidade1 : soma2 > soma1 ? nomeCidade2 : "EMPATE!");
    
    // Informações adicionais sobre a vitória
    if(soma1 > soma2) {
        printf("🎉 %s venceu com uma vantagem de %.2f pontos!\n", nomeCidade1, soma1 - soma2);
    } else if(soma2 > soma1) {
        printf("🎉 %s venceu com uma vantagem de %.2f pontos!\n", nomeCidade2, soma2 - soma1);
    } else {
        printf("🤝 Foi um empate perfeito! Ambas as cartas são igualmente poderosas!\n");
    }
    
    printf("\n========================================\n");
    printf("🎯 Obrigado por jogar Super Trunfo Duplo!\n");
    printf("========================================\n");
    
    return 0;
}