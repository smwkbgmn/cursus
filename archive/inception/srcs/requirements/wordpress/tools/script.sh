#!/bin/sh

echo "==== start wordpress ===="

sleep 3
if [ ! -f "/var/www/html/wp-config.php" ]; then
    echo "Installing WordPress..."
    cd /var/www/html

    wp core download --allow-root --path=/var/www/html
    wp config create --dbname=$MARIADB_NAME --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASSWORD --dbhost=$WORDPRESS_DB_HOST --path=/var/www/html --allow-root
    wp core install --url=localhost --title="Inception" --admin_user=$WORDPRESS_ADMIN_NAME --admin_password=$WORDPRESS_ADMIN_PASS --admin_email=$WORDPRESS_ADMIN_EMAIL --path=/var/www/html --allow-root
    wp user create $WORDPRESS_USER_NAME $WORDPRESS_USER_EMAIL --user_pass=$WORDPRESS_USER_PASS --role="author" --path=/var/www/html --allow-root
else
    echo "WordPress is already installed."
fi

echo "==== WordPress setup completed ===="

exec php-fpm7.4 -F