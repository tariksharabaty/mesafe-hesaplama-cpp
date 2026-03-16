# 📏 İki Nokta Arası Uzaklık Hesaplayıcı (Sygrad Math Engine)

**İstanbul Kent Üniversitesi Bilgisayar Programlama II** dersi kapsamında geliştirilmiş, ileri seviye C++ özelliklerini barındıran profesyonel mesafe hesaplama uygulamasıdır.

## 💻 Öğrenci Bilgileri
* **Ad Soyad:** Tarek Sharabaty
* **Öğrenci Numarası:** 2507020015
* **Bölümü:** Bilgisayar Mühendisliği

## 👨‍💻 Programın Çalışma Mantığı
Program, **Sygrad Mühendislik Standartları** baz alınarak modüler ve nesne yönelimli (OOP) bir yapıda tasarlanmıştır:
1.  **Veri Girişi:** `Sygrad::ConsoleUI::RequestInput` statik fonksiyonu ile kullanıcıdan X ve Y koordinatları güvenli bir şekilde alınır.
2.  **Nesne Oluşturma:** Alınan değerler, şablon tabanlı (template) `Sygrad::Point<T>` sınıfından üretilen nesnelerde depolanır.
3.  **Matematiksel Motor:** `Sygrad::MathEngine::CalculateEuclidean` statik metodu, Öklid mesafesi formülünü ($d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$) işletir:
    * `std::pow` ile eksen farklarının kareleri hesaplanır.
    * `std::sqrt` ile toplamın karekökü alınarak nihai mesafe ($d$) elde edilir.
4.  **Raporlama:** Elde edilen sonuçlar `Sygrad::ConsoleUI::DisplayResult` ile tablo formatında ve 4 basamak hassasiyetle kullanıcıya sunulur. Nokta bilgileri, `operator<<` aşırı yüklemesi sayesinde doğrudan ekrana yazdırılır.

## ⚙️ Program Özellikleri
* 🏗️ **OOP & Namespace:** Kod karmaşasını önlemek ve profesyonel bir yapı sunmak için `Sygrad` isim uzayı (namespace) ve sınıflar (class) kullanılarak endüstriyel standartlarda geliştirilmiştir.
* 🛡️ **Gelişmiş Girdi Doğrulama (Robust Input):** Kullanıcı sayı yerine harf veya geçersiz bir karakter girerse program çökmez; hata mesajı vererek `std::cin.clear()` ve `std::cin.ignore()` ile akışı temizler ve tekrar giriş ister.
* 🚀 **Generic Programming (Şablon Tabanlı):** `Sygrad::Point` sınıfının şablon (template) yapısı, farklı veri tipleriyle (örneğin `int`, `float`) çalışmaya imkan tanır. Ancak, mesafe hesaplama fonksiyonu (`Sygrad::MathEngine::CalculateEuclidean`) ve veri girişi `double` veri tipine göre yapılmıştır.
* 🔄 **Süreklilik:** Program, her hesaplamadan sonra kullanıcıya devam etmek isteyip istemediğini sorar ve `keepRunning` değişkeni ile kontrol edilen döngüsel bir yapı sunar.
* 📊 **Formatlı Çıktı:** `iomanip` kütüphanesi (`setw`, `setprecision`, `fixed`) kullanılarak sonuçlar estetik bir rapor şablonunda gösterilir.
