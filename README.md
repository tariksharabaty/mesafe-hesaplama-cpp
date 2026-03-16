# 📏 İki Nokta Arası Uzaklık Hesaplayıcı

**İstanbul Kent Üniversitesi Bilgisayar Programlama II** dersi için hazırlanmış, nesne yönelimli programlama (OOP) prensiplerine uygun C++ konsol uygulamasıdır.

## 💻 Öğrenci Bilgileri
* **Ad Soyad:** Tarek Sharabaty
* **Öğrenci Numarası:** 2507020015
* **Bölümü:** Bilgisayar Mühendisliği

## 👨‍💻 Programın Çalışma Mantığı
1. **Veri Girişi:** `UserInterface::RequestInput` fonksiyonu ile kullanıcıdan X ve Y koordinatları güvenli bir şekilde alınır.
2. **Nesne Yapısı:** Koordinatlar, template tabanlı `Point` sınıfı kullanılarak nesneleştirilir.
3. **Matematiksel İşlem:** `MathUtility::CalculateDistance` metodu, Öklid mesafesi formülünü ($d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$) kullanarak sonucu hesaplar.
4. **Çıktı:** Sonuçlar, formatlanmış bir rapor tablosu halinde kullanıcıya sunulur.

## ⚙️ Program Özellikleri
* 🛠️ **Girdi Doğrulama:** Sayı harici girişlerde hata vererek programın çökmesini engeller.
* 🚀 **Template Kullanımı:** Esnek veri tiplerini destekleyen sınıf yapısı.
* 📊 **Estetik Arayüz:** `iomanip` kütüphanesi ile düzenlenmiş tablo görünümü.
