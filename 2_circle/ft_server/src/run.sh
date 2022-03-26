!/bin/bash

echo `service nginx start`
echo `openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=sanjeon/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt`
echo `mv localhost.dev.crt etc/ssl/certs/`
echo `mv localhost.dev.key etc/ssl/private/`
echo `chmod 400 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key`

echo `wget https://wordpress.org/latest.tar.gz`
echo `tar -xvf latest.tar.gz`
echo `mv wordpress/ var/www/html/`

echo `cp -b ./tmp/default etc/nginx/sites-available/`
echo `cp ./tmp/wp-config.php var/www/html/wordpress`

echo `wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz`
echo `tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz`
echo `mv phpMyAdmin-5.0.2-all-languages phpmyadmin`
echo `mv phpmyadmin /var/www/html/`
echo `cp tmp/config.inc.php /var/www/html/phpmyadmin/`

echo `service mysql start`
echo `mysql < var/www/html/phpmyadmin/sql/create_tables.sql`
echo "CREATE DATABASE IF NOT EXISTS wordpress;"| mysql -u root
echo "grant all privileges on wordpress.* to 'sanjeon'@'localhost' identified by '1234';"| mysql -u root

echo `service php7.3-fpm start`
echo `service nginx reload`

bash
