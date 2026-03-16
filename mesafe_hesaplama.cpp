#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <locale> // Turkce karakter destegi icin

/**
 * @brief Koordinat sistemindeki bir noktayı temsil eden şablon sınıf.
 */
template <typename T>
class Point {
public:
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    // Operatör Aşırı Yükleme: Noktayı doğrudan cout ile yazdırabilmek için
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

/**
 * @brief Matematiksel hesaplamaları yöneten yardımcı sınıf.
 */
class MathUtility {
public:
    template <typename T>
    static double CalculateDistance(const Point<T>& p1, const Point<T>& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

/**
 * @brief Konsol Arayüzü Yönetimi
 */
class UserInterface {
public:
    static void ShowHeader() {
        std::cout << "\n"
                  << "   =========================================\n"
                  << "   |        İKİ NOKTA ARASI MESAFE         |\n"
                  << "   |           HESAPLAYICI v1.0            |\n"
                  << "   =========================================\n\n";
    }

    static double RequestInput(const std::string& label) {
        double value;
        while (true) {
            std::cout << "   > " << label << ": ";
            if (std::cin >> value) {
                // Girişten sonra kalan karakterleri temizle
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "   [!] Hata: Geçersiz giriş. Lütfen bir sayı giriniz.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    template <typename T>
    static void DisplayResult(const Point<T>& p1, const Point<T>& p2, double res) {
        std::cout << "\n   +---------------------------------------+\n"
                  << "   |           HESAPLAMA RAPORU            |\n"
                  << "   +---------------------------------------+\n"
                  << "   | Nokta A : " << std::setw(27) << p1 << " |\n"
                  << "   | Nokta B : " << std::setw(27) << p2 << " |\n"
                  << "   |---------------------------------------|\n"
                  << "   | Mesafe  : " << std::fixed << std::setprecision(4) 
                  << std::setw(15) << res << " birim       |\n"
                  << "   +---------------------------------------+\n";
    }
};

int main() {
    // Windows terminalinde Turkce karakterlerin dogru gorunmesini saglar
    setlocale(LC_ALL, "Turkish");

    UserInterface::ShowHeader();

    bool keepRunning = true;
    while (keepRunning) {
        std::cout << "   --- Koordinat Verilerini Giriniz ---\n";
        
        double x1 = UserInterface::RequestInput("1. Nokta (X)");
        double y1 = UserInterface::RequestInput("1. Nokta (Y)");
        Point<double> p1(x1, y1);

        double x2 = UserInterface::RequestInput("2. Nokta (X)");
        double y2 = UserInterface::RequestInput("2. Nokta (Y)");
        Point<double> p2(x2, y2);

        double dist = MathUtility::CalculateDistance(p1, p2);
        UserInterface::DisplayResult(p1, p2, dist);

        std::cout << "\n   Tekrar hesaplama yapmak istiyor musunuz? (E/H): ";
        char choice;
        std::cin >> choice;
        
        // Sadece 'e' veya 'E' girilirse devam eder
        keepRunning = (choice == 'e' || choice == 'E');
        
        if (!keepRunning) {
            std::cout << "\n   Program kapatılıyor. İyi günler dileriz!\n";
        }
    }

    return 0;
}
