/******************************************************************************
 * UNIVERSIDADE DO VALE DO ITAJAÍ (UNIVALI)
 * CURSO: CIÊNCIA DA COMPUTAÇÃO
 * DISCIPLINA: ALGORITMOS E PROGRAMAÇÃO
 * AUTORES: [Arthur Ferraz de Aquino]
 * [Vicenzo Radin]
 * DATA: 14/04/2026
 * PROJETO: RPG LIVRO-JOGO "ESTAÇÃO VÁCUO"
 ******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

bool temCartao = false;
int oxigenio = 100; // O oxigênio diminui conforme você faz escolhas

void cena2();
void cena3();
void cena4();
void laboratorio();
void final1(); 
void final2(); 
void final3(); 
void final4();
void gameOver();

void mostrarStatus() {
    cout << "\n[ Oxigenio Atual: " << oxigenio << "% ]" << endl;
}

void cena1() {
    mostrarStatus();
    cout << "O alarme ecoa. A Estacao Atlas esta se partindo. \n";
    cout << "Voce esta no setor de comunicacoes. Ha um painel piscando e uma escotilha travada.\n";
    cout << "1 - Investigar o painel de controle\n";
    cout << "2 - Tentar forcar a escotilha (Gasta 20% de oxigenio)\n";

    int escolha;
    cin >> escolha;

    if (escolha == 1) {
        cout << "Voce encontra um Cartao de Acesso esquecido em uma gaveta!\n";
        temCartao = true;
        cena2();
    } else {
        oxigenio -= 20;
        cout << "Voce forca a porta com os ombros. Ela abre, mas voce esta ofegante.\n";
        cena2();
    }
}

void cena2() {
    mostrarStatus();
    cout << "Voce chega ao corredor principal. O caminho para as Capsulas de Fuga esta bloqueado por fogo.\n";
    cout << "1 - Atravessar o fogo correndo (Perigoso)\n";
    cout << "2 - Ir pelo Laboratorio de Criogenia (Caminho longo)\n";

    int escolha;
    cin >> escolha;

    if (escolha == 1) {
        oxigenio -= 40;
        if (oxigenio <= 0) gameOver();
        else {
            cout << "Voce atravessa as chamas! Sua roupa protegeu o corpo, mas o ar ficou escasso.\n";
            cena4();
        }
    } else {
        laboratorio();
    }
}

void laboratorio() {
    mostrarStatus();
    cout << "O laboratorio esta gelado. Ha um cientista ferido preso sob escombros.\n";
    cout << "1 - Ajudar o cientista (Gasta tempo e oxigenio)\n";
    cout << "2 - Ignorar e seguir para as capsulas\n";

    int escolha;
    cin >> escolha;

    if (escolha == 1) {
        oxigenio -= 30;
        if (oxigenio <= 0) gameOver();
        else {
            cout << "Voce liberta o cientista. Ele conhece um atalho para o hangar!\n";
            final1(); // Caminho para o melhor final
        }
    } else {
        cena4();
    }
}

void cena4() {
    mostrarStatus();
    cout << "Voce chega ao Hangar. So resta uma capsula de fuga, mas ela exige o Cartao de Acesso.\n";
    
    if (temCartao) {
        cout << "1 - Entrar na capsula e lancar imediatamente\n";
        cout << "2 - Tentar enviar um sinal de socorro antes de partir (Gasta o resto do oxigenio)\n";
        
        int escolha;
        cin >> escolha;
        if (escolha == 1) final2();
        else final3();
    } else {
        cout << "Voce nao tem o cartao! Voce tenta hackear o sistema manualmente...\n";
        final4();
    }
}

//FINAIS -

void final1() {
    cout << "\n*** FINAL 1: OS HERÓIS ***\n";
    cout << "Com a ajuda do cientista, voces ativam um protocolo de emergencia.\n";
    cout << "Uma nave de resgate detecta voces a tempo. Voce salvou uma vida alem da sua!\n";
}

void final2() {
    cout << "\n*** FINAL 2: SOBREVIVENTE SOLITÁRIO ***\n";
    cout << "A capsula e lancada. Voce olha pela janela e vê a estacao explodir.\n";
    cout << "Voce esta vivo, mas o silencio no espaco e a solidao sao seus unicos companheiros.\n";
}

void final3() {
    cout << "\n*** FINAL 3: O SACRIFÍCIO ***\n";
    cout << "Voce gasta seus ultimos segundos de ar enviando as coordenadas da explosao.\n";
    cout << "O sinal e recebido por uma base próxima, salvando outros tripulantes em setores distantes.\n";
    cout << "Voce morre como um heroi entre as estrelas.\n";
}

void final4() {
    cout << "\n*** FINAL 4: DERIVA ESPACIAL ***\n";
    cout << "Sem o cartao, a capsula ejeta, mas sem vedacao total.\n";
    cout << "Voce flutua pelo vacuo, vendo as estrelas ficarem menores. Voce se torna parte do cosmos.\n";
}

void gameOver() {
    cout << "\n--- GAME OVER ---\n";
    cout << "Seu oxigenio acabou. Tudo ficou escuro antes que voce pudesse alcancar a saida.\n";
}

int main() {
    cout << "--- MISSÃO: ESTAÇÃO VÁCUO ---\n";
    cena1();
    return 0;
}
