import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 접속 요청
client_socket.connect(('127.0.0.1', 8282))

while True:
    message = input('메시지 입력: ')
    # 접속 되면 바로 메시지 전송
    client_socket.send(message.encode()) # str ->byte로 변환해서 보내야함
    print('수신: ' + client_socket.recv(1024).decode())
    if message == 'exit':
        break

# 연결 종료

client_socket.close()
