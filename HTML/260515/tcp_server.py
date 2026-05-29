import socket

# ip주소 port번호

# 소켓 생성 (갤럭시 구입)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 포트 바인딩 (전화번호 개통)
server_socket.bind(('127.0.0.1', 8282))

# 연결 대기 (전화 기다림)
server_socket.listen()
print('서버 소켓 대기')

# 실제로는 연결될때까지 여기서 멈춰있음ㅋ
# 전화가 옴!! 연결 요청이 오면 연걸 수락

client_socket, client_ip = server_socket.accept()   
print(f'연결되었습니다. {client_ip}')

## 데이터 수신 (전화 청취)
while True:
    message = client_socket.recv(1024).decode() # byte -> str
    print('수신: ' + message)
    client_socket.send('OK!'.encode())
    if message == 'exit':
        break

# 전화 끊기
client_socket.close()
# 전화기 가입 해지
server_socket.close()