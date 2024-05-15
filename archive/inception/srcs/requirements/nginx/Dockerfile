FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y nginx openssl gettext vim

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42seoul/CN=donghyu2@student.42seoul.kr" -keyout /etc/ssl/private/nginx.pem -out /etc/ssl/certs/nginx.crt
COPY ./tools/script.sh /tmp/script.sh
COPY ./conf/default /etc/nginx/sites-enabled/default
RUN chmod +x /tmp/script.sh
RUN chmod +x /etc/nginx/sites-enabled/default

CMD ["nginx", "-g", "daemon off;"]


