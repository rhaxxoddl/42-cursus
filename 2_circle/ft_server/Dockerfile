FROM	debian:buster 

RUN		apt-get update && apt-get install -y \
		nginx \
		mariadb-server \
		php-mysql \
		php-mbstring \
		openssl \
		vim \
		wget \
		php7.3-fpm
# 쉘 명령어를 실행하고 결과를 커밋한다. 

COPY	./src/run.sh ./
COPY	./src/default ./tmp
COPY	./src/wp-config.php ./tmp
COPY	./src/config.inc.php ./tmp
# HostOS의 파일 또는 디렉토리를 컨테이너 안의 경로로 복사한다.

EXPOSE	80 443
# 이 컨테이너가 해당 포트를 사용할 예정임을 사용자에게 알려준다.
# 실제로 포트를 열기 위해서는 run 명령어에서 -p 옵션을 사용해야한다.

CMD		bash run.sh
# 생성된 컨테이너를 실행할 명령어를 지정한다.
