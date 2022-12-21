#!bin/bash
sed -i "s/autoindex on;/autoindex off;/g" ../etc/nginx/sites-enabled/nginx.conf

service nginx restart