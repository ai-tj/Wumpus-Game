🎮 Wumpus Adventure — Console Survival Game (C++)
Wumpus Adventure adalah game petualangan berbasis teks yang berjalan di console. Pemain menjelajahi serangkaian ruangan, menghindari jebakan jurang, merasakan petunjuk dari lingkungan, dan berusaha menemukan monster legendaris bernama Wumpus.
Game ini ditulis sepenuhnya menggunakan C++, dengan logika lokasi yang acak setiap permainan, efek animasi menggunakan ASCII, dan sistem navigasi sederhana yang mudah dipelajari.

🕹️ Cara Bermain
Anda memulai permainan di ruangan nomor 1. Setiap ruangan terhubung seperti jalur panjang dari 1 hingga 20.
Tujuan utama Anda:
✔ Temukan dan kalahkan Wumpus!
Namun hati-hati! Selain Wumpus, terdapat dua jurang mematikan yang akan langsung mengakhiri permainan bila Anda memasuki ruangan tersebut.

🧭 Perintah yang Tersedia
Pemain dapat bergerak menggunakan tiga perintah:
kiri → bergerak ke ruangan sebelumnya
kanan → bergerak ke ruangan berikutnya
depan → maju (fungsi sama seperti kanan untuk kesederhanaan)

⚠️ Petunjuk Lingkungan
Game memberikan tanda-tanda saat Anda mendekati bahaya:
“Kamu mencium bau busuk… Wumpus dekat.”
→ Anda berada di ruangan yang bersebelahan dengan Wumpus.
“Angin berhembus kuat… Ada jurang di dekat sini.”
→ Anda dekat dengan salah satu jurang.
Petunjuk ini membantu pemain mengambil keputusan sebelum melangkah.

💀 Kondisi Game Over
Permainan berakhir bila:
Anda memasuki ruangan tempat Wumpus
→ Akan muncul animasi deteksi Wumpus.
Anda jatuh ke jurang
→ Akan muncul animasi jatuh yang dramatis.
Setelah Game Over, Anda dapat memilih untuk mengulang permainan atau keluar.

🎲 Sistem Random
Setiap permainan baru akan menghasilkan:
Lokasi Wumpus (acak)
Lokasi dua jurang (acak)
Selalu dijamin tidak saling bertabrakan
Sehingga setiap sesi permainan terasa unik.
