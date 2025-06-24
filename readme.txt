1. 學號：b11130024 b11107046
2. 姓名：羅曜安 彭弼暉
3. 使用之程式語言：C++
4. 使用之編譯平台：Linux GNU g++
5. 檔案壓縮方式: tar -zcvf C-5final.tgz iccad_c
6. 各檔案說明：
	iccad_c/src		: 主程式source code
	iccad_c/bin  		: 執行檔目錄
	iccad_c/obj 		: .o檔案目錄
	iccad_c/ICCAD25_ProbC 	: testcase
	iccad_c/report 		: report
	iccad_c/aes_chiper_top.pl	: 輸出.pl file
	iccad_c/ASAP7解釋 		: ASAP7解釋
	iccad_c/其他解釋 		: 其他解釋	
  	iccad_c/Makefile		: Makefile
	iccad_c/readme.txt		: 本檔案
7. 編譯方式說明：        	
   主程式：
	   在 iccad_c/ 這個資料夾下指令 : make
	   即可在 iccad_c 產生 parser 的執行檔
	
8. 執行、使用方式說明：
   主程式：
   	   compile 完成後，在 bin/ 目錄下會產生一個 parser 的執行檔
   	   執行檔的命令格式為 :
   	   ./bin/parser ./ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.nodes ./ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.pl ./ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.nets ./ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.scl ./ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.v 

	  會輸出aes_chiper_top.pl在./iccad_c目錄底下，為輸出的PL檔案
      會輸出ECO_changelist.changelist在./iccad_c目錄底下，為輸出的changelist檔案

arg 1 : .nodes
arg 2 : .pl
arg 3 : .scl
arg 4 : .v
arg 5 : .nets
