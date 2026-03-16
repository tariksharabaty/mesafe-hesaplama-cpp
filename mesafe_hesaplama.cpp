#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <fcntl.h>  
#include <io.h>     

/**
 * @brief Koordinat sistemindeki bir noktayı temsil eden şablon sınıf.
 * Wide string (wstring) desteği eklenmiştir.
 */
template <typename T>
class Point {
public:
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    // Geniş karakter çıkış akışı (wostream) için operatör aşırı yükleme
    friend std::wostream& operator<<(std::wostream& os, const Point<T>& p) {
        os << L"(" << p.x << L", " << p.y << L")";
        return os;
    }
};

class MathUtility {
public:
    template <typename T>
    static double CalculateDistance(const Point<T>& p1, const Point<T>& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

class UserInterface {
public:
    static void ShowHeader() {
        std::wcout << L"\n"
                   << L"   =========================================\n"
                   << L"   |        İKİ NOKTA ARASI MESAFE         |\n"
                   << L"   |           HESAPLAYICI v1.0            |\n"
                   << L"   =========================================\n\n";
    }

    static double RequestInput(const std::wstring& label) {
        double value;
        while (true) {
            std::wcout << L"   > " << label << L": ";
            if (std::wcin >> value) {
                std::wcin.ignore((std::numeric_limits<std::streamsize>::max)(), L'\n');
                return value;
            }
            std::wcout << L"   [!] Hata: Geçersiz giriş. Lütfen bir sayı giriniz.\n";
            std::wcin.clear();
            std::wcin.ignore((std::numeric_limits<std::streamsize>::max)(), L'\n');
        }
    }

    template <typename T>
    static void DisplayResult(const Point<T>& p1, const Point<T>& p2, double res) {
        std::wcout << L"\n   +---------------------------------------+\n"
                   << L"   |           HESAPLAMA RAPORU            |\n"
                   << L"   +---------------------------------------+\n"
                   << L"   | Nokta A : " << std::setw(27) << p1 << L" |\n"
                   << L"   | Nokta B : " << std::setw(27) << p2 << L" |\n"
                   << L"   |---------------------------------------|\n"
                   << L"   | Mesafe  : " << std::fixed << std::setprecision(4) 
                   << std::setw(15) << res << L" birim       |\n"
                   << L"   +---------------------------------------+\n";
    }
};

int main() {
    // ÇOK KRİTİK ADIM: Terminali UTF-16 (Unicode) moduna geçiriyoruz.
    // Bu satır Windows'ta Türkçe karakterlerin bozulmasını engelleyen en kesin yöntemdir.
    _setmode(_fileno(stdout), 0x00020000); // _O_U16TEXT
    _setmode(_fileno(stdin), 0x00020000);  // _O_U16TEXT

    UserInterface::ShowHeader();

    bool keepRunning = true;
    while (keepRunning) {
        std::wcout << L"   --- Koordinat Verilerini Giriniz ---\n";
        
        double x1 = UserInterface::RequestInput(L"1. Nokta (X)");
        double y1 = UserInterface::RequestInput(L"1. Nokta (Y)");
        Point<double> p1(x1, y1);

        double x2 = UserInterface::RequestInput(L"2. Nokta (X)");
        double y2 = UserInterface::RequestInput(L"2. Nokta (Y)");
        Point<double> p2(x2, y2);

        double dist = MathUtility::CalculateDistance(p1, p2);
        UserInterface::DisplayResult(p1, p2, dist);

        std::wcout << L"\n   Tekrar hesaplama yapmak istiyor musunuz? (E/H): ";
        wchar_t choice;
        std::wcin >> choice;
        
        keepRunning = (choice == L'e' || choice == L'E' || choice == L'evet' || choice == L'EVET');
        
        if (!keepRunning) {
            std::wcout << L"\n   Program kapatılıyor. İyi günler dileriz!\n";
        }
    }

    return 0;
}
