#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

/**
 * @brief Koordinat sistemindeki bir noktayi temsil eden sablon sinif.
 */
template <typename T>
class Point {
public:
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    // Operator Asiri Yukleme: Noktayi dogrudan cout ile yazdirabilmek icin
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

/**
 * @brief Matematiksel hesaplamalari yoneten sinif
 */
class MathUtility {
public:
    template <typename T>
    static double CalculateDistance(const Point<T>& p1, const Point<T>& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

/**
 * @brief Konsol Arayuz Yonetimi
 */
class UserInterface {
public:
    static void ShowHeader() {
        std::cout << "\n"
                  << "   =========================================\n"
                  << "   |        IKI NOKTA ARASI MESAFE         |\n"
                  << "   |           HESAPLAYICI v1.0            |\n"
                  << "   =========================================\n\n";
    }

    static double RequestInput(const std::string& label) {
        double value;
        while (true) {
            std::cout << "   > " << label << ": ";
            if (std::cin >> value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "   [!] Hata: Gecersiz giris. Lutfen sayi giriniz.\n";
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
    UserInterface::ShowHeader();

    bool keepRunning = true;
    while (keepRunning) {
        std::cout << "   --- Koordinat Verilerini Giriniz ---\n";
        
        double x1 = UserInterface::RequestInput("Nokta 1 (X)");
        double y1 = UserInterface::RequestInput("Nokta 1 (Y)");
        Point<double> p1(x1, y1);

        double x2 = UserInterface::RequestInput("Nokta 2 (X)");
        double y2 = UserInterface::RequestInput("Nokta 2 (Y)");
        Point<double> p2(x2, y2);

        double dist = MathUtility::CalculateDistance(p1, p2);
        UserInterface::DisplayResult(p1, p2, dist);

        std::cout << "\n   Tekrar hesaplama yapmak istiyor musunuz? (E/H): ";
        char choice;
        std::cin >> choice;
        keepRunning = (choice == 'e' || choice == 'E');
        
        if (!keepRunning) {
            std::cout << "\n   Program kapatiliyor. Iyi gunler dileriz!\n";
        }
    }

    return 0;
}
