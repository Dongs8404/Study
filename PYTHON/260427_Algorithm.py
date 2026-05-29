# def add_data(friend):
#     katok.append(None)
#     kLen = len(katok)
#     katok[kLen-1] = friend

# def insert_data(position, friend):

#     if position < 0 or position > len(katok):
#         print("데이터 삽입할 범위를 벗어났습니다.")
#         return
    
#     katok.append(None)
#     kLen = len(katok)

#     for i in range(kLen-1, position, -1):
#         katok[i] = katok[i-1]
#         katok[i-1] = None

#     katok[position] = friend

# def delete_data(position):
#     if position < 0 or position > len(katok):
#         print("데이터 삭제할 범위를 벗어났습니다.")
#         return
    
#     kLen = len(katok)
#     katok[position] = None

#     for i in range(position+1, kLen):
#         katok[i-1] = katok[i]
#         katok[i] = None
    
#     del(katok[kLen - 1])

# katok = []
# select = -1

# if __name__ == "__main__":
#     while (select != 4):
#         select = int(input("선택하세요(1: 추가, 2: 삽입, 3: 삭제 4: 종료)"))

#         if(select ==1):
#             data = input("추가할 데이터 -->")
#             add_data(data)
#             print(katok)
#         elif (select == 2):
#             pos = int(input("삽입할 위치-->"))
#             data = input("추가할 데이터--> ")
#             insert_data(pos, data)
#             print(katok)
#         elif(select == 3):
#             pos = int(input("삭제할 위치 --> "))
#             delete_data(pos)
#             print(katok)
#         elif (select == 4):
#             print(katok)
#             exit
#         else:
#             print("1~4 중 하나를 입력하세요.")
#             continue


def printPoly(p_x):
    term = len(p_x) - 1
    polyStr = "P(x) = "

    for i in range(len(px)):
        coef = p_x[i]

        if(coef >= 0):
            polyStr += "+"
        polyStr += str(coef) + "x^" + str(term) + " "
        term -= 1

    return polyStr

def calcPoly(xVal, p_x):
    retValue = 0
    term = len(p_x) - 1

    for i in range(len(px)):
        coef = p_x[i]
        retValue += coef * xVal ** term
        term -= 1

    return retValue

px = [7, -4, 0, 5]

if __name__ == "__main__":
    pStr = printPoly(px)
    print(pStr)

    xValue = int(input("X값 -->"))
    
    pxValue = calcPoly(xValue, px)
    print(pxValue)