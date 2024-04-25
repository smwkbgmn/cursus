#!/bin/sh

echo "=== start mariadb ==="
service mariadb start
sleep 3

if [ ! -d "/var/lib/mysql/${MARIADB_NAME}" ]; then
echo "==mariadb creating"

	mysql -e "CREATE DATABASE IF NOT EXISTS ${MARIADB_NAME};"

	mysql -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"

	mysql -e "GRANT ALL PRIVILEGES ON ${MARIADB_NAME}.* TO '${MARIADB_USER}'@'%';"

	mysql -e "FLUSH PRIVILEGES;"
fi

echo "===mariadb end==="
service mariadb stop

exec mysqld_safe