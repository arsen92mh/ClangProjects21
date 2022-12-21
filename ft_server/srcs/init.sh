service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE USER 'www'@'localhost';" | mysql -u root
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'www'@'localhost' identified by '111';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

while true; do sleep 1000; done
#/bin/bash