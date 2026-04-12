- 3 ve 5 sayı için optimizasyon.
- bench eklenecek
- printf içni stdio.h'dan kurtulcaz.
- radix için "Generally, --complex should use fewer instructions than --simple" şartı sağlanacak. (radixteki bit mantığındansa normal sayıların basamağına göre bakılabilir)
İleri Seviye Optimizasyon: Çift Yönlü B Yığını (Top & Bottom)

3 kez A'yı taramak yerine, B yığınının hem üstünü hem altını kullanarak işlemleri inanılmaz derecede hızlandırabilirsin.

A'yı tararken:

    Eğer 00 ise → pb (B'nin üstüne at).

    Eğer 01 ise → pb ve ardından rb (B'nin altına gizle).

    Eğer 10 ve 11 ise → A'da kalsın (ra).

Böylece A'yı 3 kez değil, sadece 1 kez taramış olursun. Sonra A'da kalan 10 ve 11'leri ayrıştırırsın. Bu yöntemle işlem sayısı klasik Radix'e göre %25 - %30 oranında düşer. 1000 hamle yapan Base-2 algoritman, 700-750 hamle bandına iner.
