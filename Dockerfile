FROM ubuntu:20.04

RUN apt update && apt upgrade
RUN apt install -y build-essential
RUN apt install -y git
RUN apt install -y make

COPY . /app

WORKDIR /app

RUN make clean
RUN make

CMD ["./escapeGame"]