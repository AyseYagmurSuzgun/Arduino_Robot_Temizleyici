# DİK BİR PLATFORM ÜZERİNDE GEZEBİLEN ROBOT TEMİZLEYİCİ TASARIMI
## Projenin Amacı
Bu proje ile dik bir platform üzerinde gezebilen ve temizlik işlemi yapabilen bir robot tasarlanılması amaçlanmaktadır. Buna göre; robotun 100 cm x 50 cm’lik belirlenmiş bir levha üzerinde gezerek, sağa-sola ve aşağı-yukarı hareket edebilmesi hedeflenmektedir.

---

## Projenin Yöntemi

Bu projede, 100 cm x 50 cm boyutlarındaki dikey bir platform üzerinde hareket edebilen bir robot temizleyici tasarlanmıştır. Robot, platformun üst köşelerine sabitlenmiş iki ip ve bu ipleri hareket ettiren iki step motor yardımıyla platform yüzeyinde yukarı-aşağı ve sağa-sola hareket etmektedir.

Projede kullanılan temel yöntem aşağıda adım adım açıklanmıştır:
1. Mekanik Tasarım
-Robot, iki step motor tarafından çekilen iplerle hareket edecek şekilde tasarlandı.
-Temizlik işlemi için bir DC motor ucuna temizlik bezi yerleştirildi.
-Röle modülü aracılığıyla temizlik motorunun kontrolü sağlandı.
2. Elektronik Devre Tasarımı
-Arduino Uno, sistemin kontrol birimi olarak kullanıldı.
-2 adet 28BYJ-48 step motor, ULN2003 sürücü kartlarıyla sürüldü.
-IR alıcı modül ile uzaktan kumanda komutları alındı.
-I2C LCD ekran kullanılarak sistem durumu kullanıcıya gösterildi.
-Röle modülü ile temizlik motorunun çalışması kontrol edildi.
3. Yazılım ve Kontrol Algoritması
-Arduino IDE üzerinde robotun hareket ve temizlik kontrolüne yönelik programlama gerçekleştirildi.
-IR uzaktan kumanda ile robotun belirli yönlere hareketi sağlandı (örneğin: asagiIn(); yukariCik(); caprazSagaYukari(); gibi fonksiyonlarla).
-Robotun koordinatlara uygun şekilde adım adım hareket etmesi sağlandı.
-Temizlik işlemi sırasında DC motorun aktif/pasif olması için röle kontrolü kullanıldı.

---

## Sonuç

Bu projede, dik bir platform üzerinde hareket edebilen, step motorlarla kontrollü bir robot temizleyici sistemi geliştirilmiştir. Arduino Uno, IR kumanda, LCD ekran ve röle modülü kullanılarak robotun yönlendirilmesi, temizlik işlemi ve kullanıcı geri bildirimi başarıyla gerçekleştirilmiştir.
Robot; sağa, sola, yukarı, aşağı ve çapraz hareket kabiliyetine sahiptir. Tanımlanan adım algoritması sayesinde rota takibi sağlanmış, temizlik sonrası başlangıç (orta) noktasına dönüş başarıyla uygulanmıştır. Sistem, temel mekatronik prensiplerine dayalı olarak modüler ve geliştirilebilir bir yapıda tasarlanmıştır.

---
