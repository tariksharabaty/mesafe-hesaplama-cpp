**İki Nokta Arası Uzaklık Hesaplayıcı**

İstanbul Kent Üniversitesi Bilgisayar Programlama 2 ödevi için hazırlanmış C++ programı.

**💻 Öğrenci Bilgileri**

Ad Soyad: Tarek Sharabaty

Öğrenci Numarası: 2507020015

Bölümü: Bilgisayar Mühendisliği


**👨‍💻 Programın Çalışma Mantığı**

**Program, Sygrad Mühendislik Standartları baz alınarak modüler bir yapıda tasarlanmıştır:**

**Veri Girişi:** ConsoleUI::RequestInput fonksiyonu ile kullanıcıdan X ve Y koordinatları güvenli bir şekilde alınır.

**Nesne Oluşturma:** Alınan değerler, şablon tabanlı (template) Point<T> sınıfından üretilen nesnelerde depolanır.

**Matematiksel Motor:** MathEngine::CalculateEuclidean statik metodu, Öklid mesafesi formülünü <img width="6400" height="20" alt="image" src="https://github.com/user-attachments/assets/72049a60-b6e2-40ca-a1d9-7a5092de4ee1" /> işletir.
 
:std::pow ile eksen farklarının kareleri hesaplanır.
:std::sqrt ile toplamın karekökü alınarak nihai mesafe ($d$) elde edilir.

**Raporlama:** Elde edilen sonuçlar ConsoleUI::DisplayResult ile tablo formatında ve 4 basamak hassasiyetle kullanıcıya sunulur.


**⚙️ Program Özellikleri**

**Generic Programming:** Şablon (Template) yapısı sayesinde sadece double değil, int veya float gibi farklı veri tipleriyle çalışabilir.

**Gelişmiş Girdi Doğrulama (Robust Input):** Kullanıcı sayı yerine harf veya geçersiz bir karakter girerse program çökmez; hata mesajı vererek std::cin.clear() ve std::cin.ignore() ile akışı temizler ve tekrar giriş ister.

**OOP & Namespace:** Kod karmaşasını önlemek için Sygrad isim uzayı (namespace) ve sınıflar (class) kullanılarak endüstriyel standartlarda geliştirilmiştir.

**Süreklilik:** Program her hesaplamadan sonra kullanıcıya devam etmek isteyip istemediğini sorarak döngüsel kullanım imkanı sunar.

**Formatlı Çıktı:** iomanip kütüphanesi (setw, setprecision) kullanılarak sonuçlar estetik bir rapor şablonunda gösterilir.

