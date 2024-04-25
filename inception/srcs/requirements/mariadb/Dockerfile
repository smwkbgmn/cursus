FROM debian:bullseye

RUN apt-get update && \
	apt-get install -y vim mariadb-server && \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/*

COPY ./tools/script.sh /tmp/script.sh
RUN chmod +x /tmp/script.sh

COPY ["conf/50-server.cnf", "/etc/mysql/mariadb.conf.d/50-server.cnf"]
RUN chown -R mysql:mysql /etc/mysql/mariadb.conf.d
RUN chmod -R 755 /etc/mysql/mariadb.conf.d


ENTRYPOINT ["/tmp/script.sh" ]