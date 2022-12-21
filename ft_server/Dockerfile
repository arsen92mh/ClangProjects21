FROM debian:buster
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y	vim
RUN apt-get install -y	wget
RUN apt-get install -y	nginx
RUN apt-get install -y	mariadb-server 
RUN apt-get install -y  php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN apt-get install -y	openssl

RUN mkdir /var/www/localhost/
RUN mv /var/www/html/ /var/www/localhost/
WORKDIR /var/www/localhost/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
RUN rm phpmyadmin/config.sample.inc.php

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
RUN rm wordpress/wp-config-sample.php

WORKDIR /tmp
COPY ./srcs ./
COPY srcs/config.sample.inc.php /var/www/localhost/phpmyadmin/
COPY srcs/wp-config-sample.php /var/www/localhost/wordpress/
RUN rm /etc/nginx/sites-enabled/default
COPY srcs/nginx.conf /etc/nginx/sites-enabled/
RUN ln -s /etc/nginx/sites-enabled/nginx.conf /etc/nginx/sites-available/
RUN openssl req -x509 -nodes -days 365 -subj "/C=ru/ST=Russia/L=Kazan/O=21school/OU=21school/CN=kulrike" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

RUN chmod -R 755 /var/www/localhost
RUN chown -R www-data:www-data /var/www/localhost
EXPOSE 80 443
CMD bash init.sh