*This project has been created as part of the 42 curriculum by mucelep.*

# FT_PRINTF

---

## 📋 ENGLISH VERSION

## Description

**ft_printf** is a reimplementation of the standard C `printf()` function. The goal of this project is to understand and implement **variadic functions** in C while reproducing the behavior of the original `printf` from the C standard library (libc).

This implementation supports the mandatory conversions required by the subject and mimics the behavior of the original `printf` for those conversions.

### Supported Conversions:
- `%c` → Character
- `%s` → String
- `%p` → Pointer (hexadecimal format)
- `%d` → Decimal number
- `%i` → Integer (base 10)
- `%u` → Unsigned decimal
- `%x` → Hexadecimal (lowercase)
- `%X` → Hexadecimal (uppercase)
- `%%` → Percent sign

The project does **not** implement buffer management like the original `printf`.

---

## 🚀 Installation
```bash
git clone [your-repository-url]
cd ft_printf
make
```

This will generate: `libftprintf.a`

---

## 🛠️ Compilation

### Makefile Rules

| Command | Description |
|---------|-------------|
| `make` or `make all` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and library |
| `make re` | Recompile everything |

The library is created using the `ar` command as required by the subject.

---

## 💻 Usage

### Basic Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

**Compile with:**
```bash
cc main.c libftprintf.a
./a.out
```

### Detailed Examples
```c
// Character and String
ft_printf("Character: %c\n", 'A');              // Character: A
ft_printf("String: %s\n", "42 Network");        // String: 42 Network
ft_printf("NULL string: %s\n", NULL);           // NULL string: (null)

// Numbers
ft_printf("Decimal: %d\n", -42);                // Decimal: -42
ft_printf("Integer: %i\n", 2147483647);         // Integer: 2147483647
ft_printf("Unsigned: %u\n", 4294967295);        // Unsigned: 4294967295

// Hexadecimal
ft_printf("Hex lower: %x\n", 255);              // Hex lower: ff
ft_printf("Hex upper: %X\n", 255);              // Hex upper: FF

// Pointer
void *ptr = &main;
ft_printf("Pointer: %p\n", ptr);                // Pointer: 0x7fff5fbff710
ft_printf("NULL pointer: %p\n", NULL);          // NULL pointer: (nil)

// Percent
ft_printf("Percentage: 100%%\n");               // Percentage: 100%

// Return value
int len = ft_printf("Total chars: %d\n", 42);   // Returns number of printed chars
```

---

## ⚙️ Implementation Details

### Variadic Arguments
This project uses:
- `va_start` - Initialize argument list
- `va_arg` - Access next argument
- `va_end` - Clean up argument list

to handle a variable number of arguments.

### Structure & Algorithm

The implementation follows a modular and extensible parsing strategy.

> 🔎 **Core workflow:**
> 1. Iterate through the format string character by character.
> 2. When a `%` symbol is encountered, dispatch the next character to a dedicated conversion handler.
> 3. Each conversion function processes its argument and returns the number of printed characters.
> 4. The total output length is accumulated and returned at the end.

This structure ensures clarity, separation of concerns, and easy extensibility for additional conversions.

### Number Printing Strategy

Numbers are printed using a recursive division-based algorithm.

> ⚙ **Strategy:**
> - Decimal numbers are recursively divided by 10.
> - Hexadecimal numbers are recursively divided by 16.
> - Digits are written one by one using `write()`.

This approach avoids dynamic memory allocation and eliminates the need for temporary buffers, ensuring efficient and controlled low-level output.

### Pointer Handling

Pointers are printed in hexadecimal format with the `0x` prefix.

> ⚠ **Special case:**
> If the pointer value is `NULL`, `(nil)` is printed, strictly mimicking the behavior of the original GNU `printf`.

This behavior ensures compatibility with the 42 evaluation testers.

### Return Value

`ft_printf` returns the **total number of characters printed**, just like the original `printf`.
```c
int count = ft_printf("Hello %s!", "World");  // count = 12
```

---

## 🧪 Testing

### Recommended Testers

- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
- [francinette](https://github.com/xicodomingues/francinette)

### Manual Testing
```bash
# Compare with original printf
cc test.c libftprintf.a
./a.out

# Test edge cases
ft_printf("%s", NULL);           # Should print: (null)
ft_printf("%p", NULL);           # Should print: (nil) or 0x0
ft_printf("%d", -2147483648);    # Should handle INT_MIN
ft_printf("%u", -1);             # Should print: 4294967295
```

---

## 🎯 Memory Management

> ⚠ **No dynamic memory allocation** is used for mandatory conversions.

All outputs are written directly using the `write()` system call. No internal buffering or heap allocation is implemented, in accordance with the project subject requirements.

This design choice ensures:
- Predictable behavior
- Minimal memory overhead
- Full compliance with 42 evaluation standards

---

## ⚠️ Known Limitations

- **No buffer management** (unlike the original `printf`)
- **No flags** (`-`, `+`, `0`, `#`, ` `)
- **No width or precision** (e.g., `%10d`, `%.5s`)
- Only **mandatory conversions** are implemented
- Bonus conversions are **not included** in this version

---

## 📚 Resources

- `man 3 printf`
- `man 3 stdarg`
- ISO C documentation
- 42 subject PDF
- [GNU libc documentation](https://www.gnu.org/software/libc/manual/)

---

## 🤖 AI Usage

AI was used as a conceptual guide for:
- Understanding edge cases
- Reviewing algorithm structure
- Verifying behavior differences with the original `printf`
- Assistance in writing this README documentation

**All implementation logic, debugging, and testing were performed manually.**

---

## ✅ Norminette Compliance

This project strictly follows the **42 Norm**:
- Maximum 25 lines per function
- Maximum 5 functions per file
- No forbidden functions (except allowed ones: `write`, `malloc`, `free`, `va_*`)
- Proper error handling
```bash
norminette *.c *.h
# Should return: No errors found
```

---

## 🎓 Learning Outcomes

This project strengthens understanding of:
- ✅ Variadic functions (`stdarg.h`)
- ✅ Recursion techniques
- ✅ Low-level output with `write()`
- ✅ Format string parsing
- ✅ Defensive programming in C
- ✅ Modular code design

**ft_printf** is a fundamental building block for future 42 projects.

---

## 📝 License

This project is part of the 42 curriculum and follows the school's academic policies.

---

## 👤 Author

**mucelep** - 42 Network

---

*Made with ☕ at 42*

---
---

## 📋 TÜRKÇE VERSİYON

## Açıklama

**ft_printf**, standart C `printf()` fonksiyonunun yeniden implementasyonudur. Bu projenin amacı, C'de **değişken sayıda argüman alan fonksiyonları** (variadic functions) anlamak ve uygulamak, aynı zamanda C standart kütüphanesindeki (libc) orijinal `printf` davranışını yeniden üretmektir.

Bu implementasyon, konunun gerektirdiği zorunlu dönüşümleri destekler ve bu dönüşümler için orijinal `printf` davranışını taklit eder.

### Desteklenen Dönüşümler:
- `%c` → Karakter
- `%s` → String (Metin)
- `%p` → İşaretçi (hexadecimal format)
- `%d` → Ondalık sayı
- `%i` → Tamsayı (taban 10)
- `%u` → İşaretsiz ondalık sayı
- `%x` → Hexadecimal (küçük harf)
- `%X` → Hexadecimal (büyük harf)
- `%%` → Yüzde işareti

Proje, orijinal `printf` gibi **buffer yönetimi uygulamaz**.

---

## 🚀 Kurulum
```bash
git clone [repository-url'niz]
cd ft_printf
make
```

Bu komut şunu oluşturacak: `libftprintf.a`

---

## 🛠️ Derleme

### Makefile Kuralları

| Komut | Açıklama |
|-------|----------|
| `make` veya `make all` | Kütüphaneyi derle |
| `make clean` | Object dosyalarını sil |
| `make fclean` | Object dosyalarını ve kütüphaneyi sil |
| `make re` | Her şeyi yeniden derle |

Kütüphane, konunun gerektirdiği şekilde `ar` komutu kullanılarak oluşturulur.

---

## 💻 Kullanım

### Basit Örnek
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Merhaba %s!\n", "Dünya");
    ft_printf("Sayı: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

**Derleme:**
```bash
cc main.c libftprintf.a
./a.out
```

### Detaylı Örnekler
```c
// Karakter ve String
ft_printf("Karakter: %c\n", 'A');              // Karakter: A
ft_printf("String: %s\n", "42 Network");       // String: 42 Network
ft_printf("NULL string: %s\n", NULL);          // NULL string: (null)

// Sayılar
ft_printf("Ondalık: %d\n", -42);               // Ondalık: -42
ft_printf("Tamsayı: %i\n", 2147483647);        // Tamsayı: 2147483647
ft_printf("İşaretsiz: %u\n", 4294967295);      // İşaretsiz: 4294967295

// Hexadecimal
ft_printf("Hex küçük: %x\n", 255);             // Hex küçük: ff
ft_printf("Hex büyük: %X\n", 255);             // Hex büyük: FF

// İşaretçi
void *ptr = &main;
ft_printf("İşaretçi: %p\n", ptr);              // İşaretçi: 0x7fff5fbff710
ft_printf("NULL işaretçi: %p\n", NULL);        // NULL işaretçi: (nil)

// Yüzde
ft_printf("Yüzde: 100%%\n");                   // Yüzde: 100%

// Dönüş değeri
int len = ft_printf("Toplam karakter: %d\n", 42);   // Yazdırılan karakter sayısını döner
```

---

## ⚙️ Implementasyon Detayları

### Değişken Argümanlar (Variadic Arguments)
Bu proje şunları kullanır:
- `va_start` - Argüman listesini başlat
- `va_arg` - Sonraki argümana eriş
- `va_end` - Argüman listesini temizle

Değişken sayıda argümanı işlemek için bu makrolar kullanılır.

### Yapı & Algoritma

Implementasyon, modüler ve genişletilebilir bir parsing stratejisi izler.

> 🔎 **Temel iş akışı:**
> 1. Format string'i karakter karakter dolaş.
> 2. Bir `%` sembolü ile karşılaşıldığında, bir sonraki karakteri ilgili dönüşüm işleyicisine gönder.
> 3. Her dönüşüm fonksiyonu argümanını işler ve yazdırılan karakter sayısını döner.
> 4. Toplam çıktı uzunluğu biriktirilir ve sonunda döndürülür.

Bu yapı, netlik, endişelerin ayrılması ve ek dönüşümler için kolay genişletilebilirlik sağlar.

### Sayı Yazdırma Stratejisi

Sayılar, özyinelemeli (recursive) bölme tabanlı bir algoritma kullanılarak yazdırılır.

> ⚙ **Strateji:**
> - Ondalık sayılar özyinelemeli olarak 10'a bölünür.
> - Hexadecimal sayılar özyinelemeli olarak 16'ya bölünür.
> - Rakamlar `write()` kullanılarak tek tek yazılır.

Bu yaklaşım, dinamik bellek tahsisinden kaçınır ve geçici buffer'lara ihtiyacı ortadan kaldırır, böylece verimli ve kontrollü düşük seviye çıktı sağlar.

### İşaretçi (Pointer) İşleme

İşaretçiler, `0x` öneki ile hexadecimal formatta yazdırılır.

> ⚠ **Özel durum:**
> İşaretçi değeri `NULL` ise, orijinal GNU `printf` davranışını tam olarak taklit ederek `(nil)` yazdırılır.

Bu davranış, 42 değerlendirme test araçlarıyla uyumluluğu sağlar.

### Dönüş Değeri

`ft_printf`, orijinal `printf` gibi **yazdırılan toplam karakter sayısını** döner.
```c
int count = ft_printf("Merhaba %s!", "Dünya");  // count = 14
```

---

## 🧪 Test Etme

### Önerilen Test Araçları

- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
- [francinette](https://github.com/xicodomingues/francinette)

### Manuel Test
```bash
# Orijinal printf ile karşılaştır
cc test.c libftprintf.a
./a.out

# Edge case'leri test et
ft_printf("%s", NULL);           # Şunu yazdırmalı: (null)
ft_printf("%p", NULL);           # Şunu yazdırmalı: (nil) veya 0x0
ft_printf("%d", -2147483648);    # INT_MIN'i handle etmeli
ft_printf("%u", -1);             # Şunu yazdırmalı: 4294967295
```

---

## 🎯 Bellek Yönetimi

> ⚠ **Zorunlu dönüşümler için dinamik bellek tahsisi kullanılmaz.**

Tüm çıktılar doğrudan `write()` sistem çağrısı kullanılarak yazılır. Proje gereksinimlerine uygun olarak hiçbir dahili buffer veya heap tahsisi uygulanmamıştır.

Bu tasarım seçimi şunları sağlar:
- Öngörülebilir davranış
- Minimal bellek yükü
- 42 değerlendirme standartlarına tam uyum

---

## ⚠️ Bilinen Sınırlamalar

- **Buffer yönetimi yok** (orijinal `printf`'in aksine)
- **Flag'ler yok** (`-`, `+`, `0`, `#`, ` `)
- **Genişlik veya hassasiyet yok** (örn: `%10d`, `%.5s`)
- Sadece **zorunlu dönüşümler** implement edilmiştir
- Bonus dönüşümler bu versiyonda **bulunmamaktadır**

---

## 📚 Kaynaklar

- `man 3 printf`
- `man 3 stdarg`
- ISO C dokümantasyonu
- 42 konu PDF'i
- [GNU libc dokümantasyonu](https://www.gnu.org/software/libc/manual/)

---

## 🤖 Yapay Zeka Kullanımı

Yapay zeka aşağıdakiler için kavramsal bir rehber olarak kullanılmıştır:
- Edge case'leri anlama
- Algoritma yapısını gözden geçirme
- Orijinal `printf` ile davranış farklılıklarını doğrulama
- Bu README dokümantasyonunun yazılmasında yardımcı olma

**Tüm implementasyon mantığı, hata ayıklama ve testler manuel olarak gerçekleştirilmiştir.**

---

## ✅ Norminette Uyumluluğu

Bu proje **42 Norm**'una kesinlikle uygundur:
- Fonksiyon başına maksimum 25 satır
- Dosya başına maksimum 5 fonksiyon
- Yasak fonksiyon yok (izin verilenler hariç: `write`, `malloc`, `free`, `va_*`)
- Uygun hata işleme
```bash
norminette *.c *.h
# Şunu dönmeli: No errors found
```

---

## 🎓 Öğrenme Kazanımları

Bu proje şu konularda anlayışı güçlendirir:
- ✅ Değişken argümanlı fonksiyonlar (`stdarg.h`)
- ✅ Özyineleme (Recursion) teknikleri
- ✅ `write()` ile düşük seviye çıktı
- ✅ Format string ayrıştırma (parsing)
- ✅ C'de savunmacı programlama
- ✅ Modüler kod tasarımı

**ft_printf**, gelecekteki 42 projeleri için temel bir yapı taşıdır.

---

## 📝 Lisans

Bu proje 42 müfredatının bir parçasıdır ve okulun akademik politikalarını takip eder.

---

## 👤 Yazar

**mucelep** - 42 Network

---

*42'de ☕ ile yapıldı*
