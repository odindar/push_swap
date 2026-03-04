#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Argüman kontrolü: Program adı, sayı adedi ve dosya adı
    if (argc != 3) {
        printf("Kullanım: %s <sayı_adedi> <dosya_adı>\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);
    if (count <= 0) {
        printf("Lütfen geçerli pozitif bir sayı girin.\n");
        return 1;
    }

    // Dosyayı yazma modunda aç
    FILE *file = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Dosya açılamadı: %s\n", argv[2]);
        return 1;
    }

    // Her çalıştırmada farklı sayılar üretmek için rastgelelik tohumunu ayarla
    srand(time(NULL));

    // İstenilen adet kadar rastgele sayı üret ve dosyaya yaz
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", rand());
    }

    fclose(file);
    printf("%d adet rastgele sayı başarıyla '%s' dosyasına yazıldı.\n", count, argv[2]);

    return 0;
}
