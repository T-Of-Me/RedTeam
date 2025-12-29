# Port scanning 

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

- 