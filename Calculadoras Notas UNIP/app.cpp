#include <iostream>
#include <iomanip> // Para controlar precis�o na sa�da
#include <limits>  // Para limpar a entrada inv�lida

using namespace std;

// Fun��o para calcular a m�dia semestral
double calcularMediaSemestral(double np1, double np2) {
    return (np1 + np2) / 2;
}

// Fun��o para calcular a m�dia final
double calcularMediaFinal(double mediaSemestral, double exame) {
    return (mediaSemestral + exame) / 2;
}

// Fun��o para obter uma nota v�lida do usu�rio
double obterNota(const string& nomeNota) {
    double nota;
    while (true) {
        cout << "Digite a " << nomeNota << ": ";
        cin >> nota;

        // Verifica se a entrada � v�lida
        if (cin.fail() || nota < 0 || nota > 10) {
            cin.clear(); // Limpa a flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inv�lida
            cout << "Entrada invalida. Por favor, insira uma nota v�lida entre 0 e 10.\n";
        } else {
            return nota; // Retorna a nota v�lida
        }
    }
}

int main() {
    char continuar;

    do {
        cout << "=============================\n";
        cout << "    Calculadora de Notas     \n";
        cout << "=============================\n";

        // Obt�m as notas do usu�rio
        double np1 = obterNota("nota do NP1");
        double np2 = obterNota("nota do NP2");

        // Calcula a m�dia semestral
        double mediaSemestral = calcularMediaSemestral(np1, np2);
        cout << fixed << setprecision(2);
        cout << "\nResultado Media Semestral: " << mediaSemestral << endl;

        // Exibe o status da m�dia semestral
        if (mediaSemestral >= 7) {
            cout << "Status Media Semestral: O aluno est� aprovado!\n";
        } else {
            cout << "Status Media Semestral: O aluno est� de exame.\n";

            // Caso o aluno esteja de exame, solicita a nota do exame
            double exame = obterNota("nota do Exame");

            // Calcula a m�dia final
            double mediaFinal = calcularMediaFinal(mediaSemestral, exame);
            cout << "\nResultado Media Final: " << mediaFinal << endl;

            // Exibe o status da m�dia final
            if (mediaFinal >= 5) {
                cout << "Status Media Final: O aluno est� aprovado!\n";
            } else {
                cout << "Status Media Final: O aluno est� reprovado!\n";
            }
        }

        // Pergunta se o usu�rio deseja calcular novamente
        cout << "\nDeseja calcular novamente? (s/n): ";
        cin >> continuar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer

        cout << endl;
    } while (continuar == 's' || continuar == 'S');

    cout << "Programa encerrado.\n";
    return 0;
}

