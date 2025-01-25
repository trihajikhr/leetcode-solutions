```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "Compile C++",
			"type": "shell",
			"command": "g++",
			"args": [
			  "-std=c++14",
			  "${file}",  
			  "-o",
			  "${fileDirname}/bin/${fileBasenameNoExtension}.exe" 
			]
		},
		{
			"label": "Compile + Run",
			"type": "shell",
			"command": "& ${fileDirname}/bin/${fileBasenameNoExtension}.exe",
			"dependsOn": ["Compile C++"],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		},
		{
			"label":"Only Run Program",
			"type": "shell",
			"command":"& ${fileDirname}/bin/${fileBasenameNoExtension}.exe",
		}
	]
}
```

```c
Perhatiakan penggunaan task json diatas.

terdapat 3 task yang bisa dipilih, yaitu:

1. "Compile C++" >> Untuk hanya melakukan proses compile. Jadi bagian "command" dipecah menjadi beberapa 
argumen dengan "args". Bagian ini akan menampung command atau perintah yang akan dituliskan d terminal
 ketika dijalankan atau dipanggil.

2. "Compile + Run" >> Bagian untuk melakukan proses compile dan run. Program ini akan berjalan, dengan mula-mula menjalankan
bagian compile dari "Compile C++", karena sudah dituliskan di "dependsOn". Baru setelah itu akan menjalankan bagian "command", yang 
berisi perintah untuk melakukan eksekusi program, dan ditampilkan outputnya di terminal.

3. "Only Run Program" >> Bagian yang akan mengeksekusi program saja, tanpa perlu proses compile terlebih dahulu. 

Penjelasan lain:

Seperti yang kita tahu, bahwa terdapat shortcut pada VSCode berupa Ctrl+Shift+B. Shortcut ini akan menjalankan
"task" pada file "task.json", yang memiliki variabel tertentu.

Ketika kamu menekan Ctrl+Shift+B, VS Code akan mencari dan menjalankan task "build" yang telah didefinisikan di dalam file tasks.json. Secara khusus:

---
-> Jika task diatur dengan "group": { "kind": "build", "isDefault": true }, 
maka task tersebut adalah task default yang akan dijalankan saat kamu menggunakan Ctrl+Shift+B.

-> Task yang dijalankan akan melakukan proses tertentu yang sudah didefinisikan, seperti kompilasi kode.
---
```

Jika ingin belajar tentang penggunaan argumen, mungkin OS yang berbeda akan membutuhkan perintah yang berbeda.
Jadi, berikut untuk pengguna OS Windows tentang argumen di task.json:
-> https://learn.microsoft.com/id-id/visualstudio/ide/customize-build-and-debug-tasks-in-visual-studio?view=vs-2022

Info selengkapnya tentang VS Code:
-> https://code.visualstudio.com/docs
