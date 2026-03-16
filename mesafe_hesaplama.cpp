#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

// Sygrad Mühendislik Standartları
namespace Sygrad {

    /**
     * @brief Koordinat sistemindeki bir noktayı temsil eden şablon sınıf.
     * @tparam T Sayısal veri tipi (int, float, double vb.)
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
     * @brief Matematiksel motor ve yardımcı araçlar
     */
    class MathEngine {
    public:
        template <typename T>
        static double CalculateEuclidean(const Point<T>& p1, const Point<T>& p2) {
            return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        }
    };

    /**
     * @brief Konsol Arayüz Yönetimi
     */
    class ConsoleUI {
    public:
        static void ShowHeader() {
            std::cout << "\n"
                      << "   =========================================\n"
                      << "   |            Mesafe hesaplama          |\n"
                      << "   |                 v0.2                 |\n"
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
                std::cout << "   [!] Hata: Geçersiz giris. Tekrar deneyin.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        template <typename T>
        static void DisplayResult(const Point<T>& p1, const Point<T>& p2, double res) {
            std::cout << "\n   +---------------------------------------+\n"
                      << "   |                RAPOR                  |\n"
                      << "   +---------------------------------------+\n"
                      << "   | Nokta A : " << std::setw(27) << p1 << " |\n"
                      << "   | Nokta B : " << std::setw(27) << p2 << " |\n"
                      << "   |---------------------------------------|\n"
                      << "   | Mesafe  : " << std::fixed << std::setprecision(4) 
                      << std::setw(15) << res << " birim       |\n"
                      << "   +---------------------------------------+\n";
        }
    };
}

int main() {
    using namespace Sygrad;

    ConsoleUI::ShowHeader();

    bool keepRunning = true;
    while (keepRunning) {
        std::cout << "   --- Veri Griniz ---\n";
        
        double x1 = ConsoleUI::RequestInput("Nokta 1 (X)");
        double y1 = ConsoleUI::RequestInput("Nokta 1 (Y)");
        Point<double> p1(x1, y1);

        double x2 = ConsoleUI::RequestInput("Nokta 2 (X)");
        double y2 = ConsoleUI::RequestInput("Nokta 2 (Y)");
        Point<double> p2(x2, y2);

        double dist = MathEngine::CalculateEuclidean(p1, p2);
        ConsoleUI::DisplayResult(p1, p2, dist);

        std::cout << "\n   Devam etmek istiyor musunuz? (E/H): ";
        char choice;
        std::cin >> choice;
        keepRunning = (choice == 'e' || choice == 'E');
        std::cout << (keepRunning ? "\n" : "\n   Mesafe hesaplama kapatiliyor. Iyi gunler!\n");
    }

    return 0;
}