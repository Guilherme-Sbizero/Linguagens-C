#include <iostream>
#include <iomanip> // Para controlar precisão na saída
#include <limits>  // Para limpar a entrada inválida

using namespace std;

// Função para calcular a média semestral
double calcularMediaSemestral(double np1, double np2) {
    return (np1 + np2) / 2;
}

// Função para calcular a média final
double calcularMediaFinal(double mediaSemestral, double exame) {
    return (mediaSemestral + exame) / 2;
}

// Função para obter uma nota válida do usuário
double obterNota(const string& nomeNota) {
    double nota;
    while (true) {
        cout << "Digite a " << nomeNota << ": ";
        cin >> nota;

        // Verifica se a entrada é válida
        if (cin.fail() || nota < 0 || nota > 10) {
            cin.clear(); // Limpa a flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada invalida. Por favor, insira uma nota válida entre 0 e 10.\n";
        } else {
            return nota; // Retorna a nota válida
        }
    }
}

int main() {
    char continuar;

    do {
        cout << "=============================\n";
        cout << "    Calculadora de Notas     \n";
        cout << "=============================\n";

        // Obtém as notas do usuário
        double np1 = obterNota("nota do NP1");
        double np2 = obterNota("nota do NP2");

        // Calcula a média semestral
        double mediaSemestral = calcularMediaSemestral(np1, np2);
        cout << fixed << setprecision(2);
        cout << "\nResultado Media Semestral: " << mediaSemestral << endl;

        // Exibe o status da média semestral
        if (mediaSemestral >= 7) {
            cout << "Status Media Semestral: O aluno está aprovado!\n";
        } else {
            cout << "Status Media Semestral: O aluno está de exame.\n";

            // Caso o aluno esteja de exame, solicita a nota do exame
            double exame = obterNota("nota do Exame");

            // Calcula a média final
            double mediaFinal = calcularMediaFinal(mediaSemestral, exame);
            cout << "\nResultado Media Final: " << mediaFinal << endl;

            // Exibe o status da média final
            if (mediaFinal >= 5) {
                cout << "Status Media Final: O aluno está aprovado!\n";
            } else {
                cout << "Status Media Final: O aluno está reprovado!\n";
            }
        }

        // Pergunta se o usuário deseja calcular novamente
        cout << "\nDeseja calcular novamente? (s/n): ";
        cin >> continuar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer

        cout << endl;
    } while (continuar == 's' || continuar == 'S');

    cout << "Programa encerrado.\n";
    return 0;
}

