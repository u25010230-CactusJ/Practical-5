FROM gcc:latest

WORKDIR /app

RUN apt-get update && \
    apt-get install -y \
    make \
    gdb \
    valgrind

COPY . .

RUN make

CMD ["./campusguard"]
