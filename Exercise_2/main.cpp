#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main() {

    // Apriamo il file "data.csv" per la lettura
    std::ifstream dataFile("data.csv");

    // Apriamo il file "result.txt" per la scrittura
    std::ofstream resultFile("result.txt");

    double S;          // La somma totale investita
    int n;             // Il numero di asset
    char semicolon;    // Per ignorare caratteri e ";" nel file

    // Leggiamo S e n dal file
    dataFile >> semicolon >> semicolon >> S;
    dataFile >> semicolon >> semicolon >> n;

    // Creiamo due vettori per memorizzare i pesi (w) e i rendimenti (r) degli asset
    std::vector<double> w(n), r(n);

    // Ignoriamo la linea "w;r"
    dataFile >> semicolon >> semicolon >> semicolon;

    // Leggiamo i pesi e i rendimenti dal file
    for (int i = 0; i < n; ++i) {
        dataFile >> w[i] >> semicolon >> r[i];
    }

    // Calcoliamo il rendimento del portafoglio
    double portfolioReturn = 0.0;
    for (int i = 0; i < n; ++i) {
        portfolioReturn += w[i] * r[i];
    }

    // Calcoliamo il valore finale del portafoglio
    double V = S * (1 + portfolioReturn);

    // Stampiamo i risultati con la precisione richiesta
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "S = " << S << ", n = " << n << "\n";
    std::cout << "w = [ ";
    for (double wi : w) {
        std::cout << wi << " ";
    }
    std::cout << "]\n";
    std::cout << "r = [ ";
    for (double ri : r) {
        std::cout << ri << " ";
    }
    std::cout << "]\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Rate of return of the portfolio: " << portfolioReturn << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "V: " << V << "\n";

    // Stampiamo i risultati sul file con la precisione richiesta
    resultFile << std::fixed << std::setprecision(2);
    resultFile << "S = " << S << ", n = " << n << "\n";

    resultFile << "w = [ ";
    for (double wi : w) {
        resultFile << wi << " ";
    }
    resultFile << "]\n";

    resultFile << "r = [ ";
    for (double ri : r) {
        resultFile << ri << " ";
    }
    resultFile << "]\n";

    resultFile << std::fixed << std::setprecision(4);
    resultFile << "Rate of return of the portfolio: " << portfolioReturn << "\n";
    resultFile << std::fixed << std::setprecision(2);

    resultFile << "V: " << V << "\n";

    return 0;
}
